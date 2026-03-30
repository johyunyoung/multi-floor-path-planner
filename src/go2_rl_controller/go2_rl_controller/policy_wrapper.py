"""
Walk-these-ways policy wrapper for Go2.

Architecture (verified from weight shapes):
  adaptation_module: (30 × 70 = 2100,) → (2,)   latent
  body:              (2100 + 2 = 2102,) → (12,)  action
"""

import numpy as np
import torch


class PolicyWrapper:
    """Loads and runs the walk-these-ways JIT policy for Go2."""

    NUM_OBS = 70
    NUM_HISTORY = 30          # 30 timesteps of full obs
    LATENT_DIM = 2
    NUM_ACTIONS = 12

    # body input = history_flat (2100) + latent (2) = 2102
    HISTORY_FLAT = NUM_OBS * NUM_HISTORY   # 2100

    def __init__(self, body_path: str, adaptation_path: str):
        self.body = torch.jit.load(body_path, map_location='cpu')
        self.adaptation = torch.jit.load(adaptation_path, map_location='cpu')
        self.body.eval()
        self.adaptation.eval()

    def infer(self, obs_history_flat: np.ndarray) -> np.ndarray:
        """
        Args:
            obs_history_flat: (2100,) float32 – 30 stacked 70-dim observations,
                              oldest first (index 0..69 = oldest, 2030..2099 = newest)
        Returns:
            action: (12,) float32 – raw network output (before action scale / offset)
        """
        hist = torch.from_numpy(obs_history_flat).float().unsqueeze(0)  # (1, 2100)
        with torch.no_grad():
            latent = self.adaptation(hist)                               # (1, 2)
            body_in = torch.cat([hist, latent], dim=-1)                  # (1, 2102)
            action = self.body(body_in)                                  # (1, 12)
        return action.squeeze(0).numpy()
