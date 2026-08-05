"""Assert cleans + dual reviews exist for skill-fun residual units."""

from __future__ import annotations

import unittest
from pathlib import Path

RECON = Path(__file__).resolve().parents[1]
CLEAN = RECON / "reconstructed-exact"
FUNCS = RECON / "functions"
REVIEWS = RECON / "reviews"

# Stable aa_* ids that must have clean + review artifacts (skill residual set).
SKILL_FUN_RESIDUALS = (
    "aa_004f8b80",  # Vehicle_ResolveFirstHardpointOccupantTfid_Inferred
    "aa_0054ff00",  # Skill_FilterTargetForResolveList_Inferred
    "aa_005788d0",  # CVOGHBSkillBase_ctor
)

# Preferred clean stems (address-based FUN_* is also accepted).
PREFERRED_CLEANS = {
    "aa_004f8b80": (
        "Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.cpp",
        "FUN_004f8b80.cpp",
    ),
    "aa_0054ff00": (
        "Skill_FilterTargetForResolveList_Inferred.cpp",
        "FUN_0054ff00.cpp",
    ),
    "aa_005788d0": (
        "CVOGHBSkillBase_ctor.cpp",
        "FUN_005788d0.cpp",
    ),
}


def _addr_hex(stable: str) -> str:
    # aa_004f8b80 -> 004f8b80
    return stable.removeprefix("aa_")


class TestSkillFunResiduals(unittest.TestCase):
    def test_cleans_exist_for_skill_fun_residuals(self):
        for stable in SKILL_FUN_RESIDUALS:
            with self.subTest(stable=stable):
                preferred = PREFERRED_CLEANS[stable]
                found = any((CLEAN / name).is_file() for name in preferred)
                if not found:
                    addr = _addr_hex(stable)
                    found = bool(list(CLEAN.glob(f"*{addr}*")))
                self.assertTrue(
                    found,
                    f"missing clean for {stable} under reconstructed-exact "
                    f"(tried {preferred})",
                )

    def test_reviews_exist_for_skill_fun_residuals(self):
        for stable in SKILL_FUN_RESIDUALS:
            with self.subTest(stable=stable):
                a_reviews = list(REVIEWS.glob(f"A_{stable}_*"))
                b_reviews = list(REVIEWS.glob(f"B_{stable}_*"))
                any_reviews = list(REVIEWS.glob(f"*{stable}*"))
                self.assertTrue(
                    a_reviews or any_reviews,
                    f"missing review artifacts for {stable} under reviews/",
                )
                # Prefer dual A_/B_ when present; require at least one review.
                self.assertGreaterEqual(
                    len(a_reviews) + len(b_reviews) + len(any_reviews),
                    1,
                    f"expected reviews for {stable}",
                )

    def test_dual_reviews_preferred_for_skill_fun_residuals(self):
        """Soft dual check: A_ and B_ should both exist for residual units."""
        for stable in SKILL_FUN_RESIDUALS:
            with self.subTest(stable=stable):
                a_reviews = list(REVIEWS.glob(f"A_{stable}_*"))
                b_reviews = list(REVIEWS.glob(f"B_{stable}_*"))
                self.assertTrue(
                    a_reviews,
                    f"missing A_ reconstruction review for {stable}",
                )
                self.assertTrue(
                    b_reviews,
                    f"missing B_ skeptical review for {stable}",
                )

    def test_function_records_exist_for_skill_fun_residuals(self):
        for stable in SKILL_FUN_RESIDUALS:
            with self.subTest(stable=stable):
                records = list(FUNCS.glob(f"{stable}_*.md"))
                self.assertTrue(
                    records,
                    f"missing function record for {stable} under functions/",
                )


if __name__ == "__main__":
    unittest.main()
