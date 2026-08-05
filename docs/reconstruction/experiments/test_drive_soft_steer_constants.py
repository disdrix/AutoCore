"""Structural + constant tests for DriveControlTick soft-steer immediates."""

from __future__ import annotations

import unittest
from pathlib import Path

import drive_soft_steer_constants as d

RECON = Path(__file__).resolve().parents[1]


class TestSoftSteerConstants(unittest.TestCase):
    def test_clean_documents_all_four_immediates(self):
        self.assertTrue(d.clean_documents_soft_immediates())

    def test_soft_band_is_pm_half(self):
        soft_l, soft_r = d.soft_band_values()
        self.assertAlmostEqual(soft_l, -0.5)
        self.assertAlmostEqual(soft_r, 0.5)

    def test_hard_band_is_pm_one(self):
        hard_l, hard_r = d.hard_band_values()
        self.assertAlmostEqual(hard_l, 1.0)
        self.assertAlmostEqual(hard_r, -1.0)

    def test_soft_inverts_sign_vs_hard_labels(self):
        # UF-006 observation: soft-L immediate is negative while hard-L is positive
        soft_l, soft_r = d.soft_band_values()
        hard_l, hard_r = d.hard_band_values()
        self.assertLess(soft_l, 0)
        self.assertGreater(hard_l, 0)
        self.assertGreater(soft_r, 0)
        self.assertLess(hard_r, 0)

    def test_dual_refresh_artifacts(self):
        reviews = RECON / "reviews"
        self.assertTrue(list(reviews.glob("A_aa_009223b0_*soft*")) or list(reviews.glob("A_aa_009223b0_*")))
        self.assertTrue((RECON / "functions" / "aa_009223b0_Client_Input_DriveControlTick.md").is_file())


class TestSkillFunArtifacts(unittest.TestCase):
    def test_filter_outflags_unit(self):
        clean = RECON / "reconstructed-exact"
        self.assertTrue(
            (clean / "Skill_FilterTargetForResolveList_Inferred.cpp").is_file()
            or (clean / "FUN_0054ff00.cpp").is_file()
        )
        self.assertTrue(list((RECON / "functions").glob("aa_0054ff00_*.md")))
        self.assertTrue(list((RECON / "reviews").glob("A_aa_0054ff00_*")))

    def test_tfid_helper_unit(self):
        self.assertTrue(
            (
                RECON
                / "reconstructed-exact"
                / "Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.cpp"
            ).is_file()
        )
        self.assertTrue(list((RECON / "reviews").glob("A_aa_004f8b80_*")))


if __name__ == "__main__":
    unittest.main()
