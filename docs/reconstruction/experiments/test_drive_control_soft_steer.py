"""
Structural + pure-model checks for DriveControlTick soft-steer band.

Body values (High): SoftL → -0.5 (0xbf000000), SoftR → +0.5 (0x3f000000).
Hard: L → +1.0, R → -1.0. UF-006 label polarity remains open — this test does
not claim SoftL physical == HardL physical; it only seals documented constants
in clean source and a pure soft-band table matching clean comments.
"""

from __future__ import annotations

import struct
import unittest
from pathlib import Path

RECON_ROOT = Path(__file__).resolve().parents[1]
CLEAN = RECON_ROOT / "reconstructed-exact" / "Client_Input_DriveControlTick.cpp"
FN_REC = RECON_ROOT / "functions" / "aa_009223b0_Client_Input_DriveControlTick.md"
SYS_MAP = RECON_ROOT / "systems" / "input-drive-control.md"
REVIEW_A = RECON_ROOT / "reviews" / "A_aa_009223b0_Client_Input_DriveControlTick.md"
REVIEW_B = RECON_ROOT / "reviews" / "B_aa_009223b0_Client_Input_DriveControlTick.md"

# IEEE-754 bit patterns as pushed in retail image / clean source
SOFT_L_BITS = 0xBF000000  # -0.5f  DAT_00d1bd2a
SOFT_R_BITS = 0x3F000000  # +0.5f  DAT_00d1bcf6
HARD_L_BITS = 0x3F800000  # +1.0f  DAT_00d1bc8e
HARD_R_BITS = 0xBF800000  # -1.0f  DAT_00d1bcc2


def bits_to_f32(bits: int) -> float:
    return struct.unpack("<f", struct.pack("<I", bits & 0xFFFFFFFF))[0]


# Pure model of soft/hard band values from clean comments / body (caller-owned signs).
# Priority order is exclusive (hard-R > hard-L > soft-L > soft-R > clear).
SOFT_BAND = {
    "hard_r": bits_to_f32(HARD_R_BITS),
    "hard_l": bits_to_f32(HARD_L_BITS),
    "soft_l": bits_to_f32(SOFT_L_BITS),
    "soft_r": bits_to_f32(SOFT_R_BITS),
    "clear": 0.0,
}


def resolve_steer(
    hard_r: bool = False,
    hard_l: bool = False,
    soft_l: bool = False,
    soft_r: bool = False,
    analog_active: bool = False,
) -> float | None:
    """Mirror DriveControlTick SECTION 7 exclusive priority. None = skip write (analog holds)."""
    if hard_r:
        return SOFT_BAND["hard_r"]
    if hard_l:
        return SOFT_BAND["hard_l"]
    if soft_l:
        return SOFT_BAND["soft_l"]
    if soft_r:
        return SOFT_BAND["soft_r"]
    if analog_active:
        return None  # 7e: skip SetSteerInput(0) when analog present
    return SOFT_BAND["clear"]


class TestSoftBandFloatBits(unittest.TestCase):
    def test_soft_half_magnitudes(self):
        self.assertAlmostEqual(SOFT_BAND["soft_l"], -0.5, places=6)
        self.assertAlmostEqual(SOFT_BAND["soft_r"], +0.5, places=6)
        self.assertAlmostEqual(SOFT_BAND["hard_l"], +1.0, places=6)
        self.assertAlmostEqual(SOFT_BAND["hard_r"], -1.0, places=6)

    def test_uf006_residual_signs_oppose_if_labels_share_meaning(self):
        # Document residual honestly: SoftL sign != HardL sign (if both mean physical left).
        self.assertLess(SOFT_BAND["soft_l"] * SOFT_BAND["hard_l"], 0.0)
        self.assertLess(SOFT_BAND["soft_r"] * SOFT_BAND["hard_r"], 0.0)

    def test_priority_hard_beats_soft(self):
        self.assertEqual(resolve_steer(hard_r=True, soft_l=True, soft_r=True), -1.0)
        self.assertEqual(resolve_steer(hard_l=True, soft_l=True), +1.0)

    def test_priority_soft_l_before_soft_r(self):
        self.assertEqual(resolve_steer(soft_l=True, soft_r=True), -0.5)

    def test_clear_and_analog_hold(self):
        self.assertEqual(resolve_steer(), 0.0)
        self.assertIsNone(resolve_steer(analog_active=True))


class TestSoftSteerDocumentedInClean(unittest.TestCase):
    def setUp(self):
        self.assertTrue(CLEAN.is_file(), f"missing {CLEAN}")
        self.clean = CLEAN.read_text(encoding="utf-8")

    def test_soft_hex_immediates_present(self):
        self.assertIn("0xbf000000", self.clean)
        self.assertIn("0x3f000000", self.clean)
        self.assertIn("DAT_00d1bd2a", self.clean)
        self.assertIn("DAT_00d1bcf6", self.clean)

    def test_soft_section_comments_document_band(self):
        self.assertIn("SOFT STEER LEFT", self.clean)
        self.assertIn("SOFT STEER RIGHT", self.clean)
        self.assertIn("UF-006", self.clean)
        # Soft L = -0.5 comment present (do not require invented polarity "fix")
        self.assertIn("-0.5", self.clean)
        self.assertIn("+0.5", self.clean)

    def test_hard_steer_immediates_present(self):
        self.assertIn("0xbf800000", self.clean)
        self.assertIn("0x3f800000", self.clean)
        self.assertIn("DAT_00d1bcc2", self.clean)
        self.assertIn("DAT_00d1bc8e", self.clean)

    def test_analog_section_present(self):
        self.assertIn("SECTION 3: Analog device path", self.clean)
        self.assertIn("DAT_00d1b618", self.clean)
        self.assertIn("DAT_00d1b620", self.clean)


class TestSoftSteerArtifacts(unittest.TestCase):
    def test_function_record_soft_seal(self):
        text = FN_REC.read_text(encoding="utf-8")
        self.assertIn("0xbf000000", text)
        self.assertIn("0x3f000000", text)
        self.assertIn("UF-006", text)
        self.assertIn("0x00922c48", text)
        self.assertIn("0x00922cf8", text)

    def test_system_map_soft_analog(self):
        text = SYS_MAP.read_text(encoding="utf-8")
        self.assertIn("Soft-steer residual", text)
        self.assertIn("Analog device residual", text)
        self.assertIn("0xbf000000", text)
        self.assertIn("UF-006", text)

    def test_dual_reviews_mention_soft_evidence(self):
        a = REVIEW_A.read_text(encoding="utf-8")
        b = REVIEW_B.read_text(encoding="utf-8")
        self.assertIn("0x00922c48", a)
        self.assertIn("0x00922cf8", a)
        self.assertIn("UF-006", a)
        self.assertIn("0x00922c48", b)
        self.assertIn("UF-006", b)


if __name__ == "__main__":
    unittest.main()
