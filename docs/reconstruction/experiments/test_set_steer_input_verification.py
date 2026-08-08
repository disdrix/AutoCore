"""Structural verification of shipped SetSteerInput reconstruction.

Drives the real clean source under reconstructed-exact/ (not a reimplementation).
Confirms sealed gate mask and store offset remain present. Does NOT claim
Runtime Confirmed or unit complete — dual accept-with-gaps is not completion.
"""
from __future__ import annotations

import re
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
CLEAN = (
    ROOT
    / "docs"
    / "reconstruction"
    / "reconstructed-exact"
    / "VehicleEntity_SetSteerInput.cpp"
)
REVIEW_A = (
    ROOT
    / "docs"
    / "reconstruction"
    / "reviews"
    / "A_aa_004f5620_VehicleEntity_SetSteerInput.md"
)
REVIEW_B = (
    ROOT
    / "docs"
    / "reconstruction"
    / "reviews"
    / "B_aa_004f5620_VehicleEntity_SetSteerInput.md"
)


class SetSteerInputVerificationTests(unittest.TestCase):
    def test_clean_seals_mask_and_store_offset(self) -> None:
        self.assertTrue(CLEAN.is_file(), f"missing clean {CLEAN}")
        text = CLEAN.read_text(encoding="utf-8")
        # Shipped constants — must match retail-sealed dual (0xC7, +0x618).
        self.assertRegex(text, r"kInputAxisSuppressMask\s*=\s*0xC7u")
        self.assertRegex(text, r"kOffSteerInput\s*=\s*0x618")
        self.assertRegex(text, r"kOffWobjFlags\s*=\s*0xb4")
        # Must not invent clamps in this leaf.
        self.assertNotRegex(text, r"(?i)clamp\s*\(")
        # Gate function body present
        self.assertIn("VehicleEntity_SetSteerInput", text)
        self.assertIn("0xC7", text)

    def test_dual_reviews_exist_and_do_not_claim_runtime_complete(self) -> None:
        self.assertTrue(REVIEW_A.is_file())
        self.assertTrue(REVIEW_B.is_file())
        a = REVIEW_A.read_text(encoding="utf-8")
        b = REVIEW_B.read_text(encoding="utf-8")
        for blob in (a, b):
            self.assertRegex(blob, r"(?i)accept-with-gaps")
            # Must not claim Runtime Confirmed as sealed complete.
            self.assertNotRegex(
                blob,
                r"(?i)Runtime Confirmed\s*[:|]?\s*\*?\*?true",
            )
            self.assertNotRegex(blob, r"(?i)verdict\s*\|\s*\*\*complete\*\*")


if __name__ == "__main__":
    unittest.main()
