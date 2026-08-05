"""Tests for inventory↔collect bridge models + structural artifacts."""

from __future__ import annotations

import unittest
from pathlib import Path

import inventory_collect_bridge as b

RECON = Path(__file__).resolve().parents[1]
CLEAN = RECON / "reconstructed-exact"
FUNCS = RECON / "functions"
REVIEWS = RECON / "reviews"
SYSTEMS = RECON / "systems"


class TestCountItemsByCbid(unittest.TestCase):
    def test_sums_matching_cbid_stacks(self):
        g = b.InventoryGrid(
            items=[
                b.GridItem(100, 2),
                b.GridItem(100, 3),
                b.GridItem(200, 9),
            ]
        )
        self.assertEqual(b.count_items_by_cbid(g, 100), 5)
        self.assertEqual(b.count_items_by_cbid(g, 200), 9)
        self.assertEqual(b.count_items_by_cbid(g, 999), 0)

    def test_excludes_broken_bit19_when_not_include(self):
        # bit 19 = Broken (sealed dual residual); Collect paths pass includeBroken=0
        g = b.InventoryGrid(items=[b.GridItem(1, 5, flag_bit19=True)])
        self.assertEqual(b.count_items_by_cbid(g, 1, include_broken=False), 0)
        self.assertEqual(b.count_items_by_cbid(g, 1, include_broken=True), 5)
        self.assertTrue(g.items[0].is_broken)


class TestCollectEval(unittest.TestCase):
    def test_fraction_and_clamp(self):
        g = b.InventoryGrid(items=[b.GridItem(42, 3)])
        self.assertAlmostEqual(b.collect_eval_fraction(g, 42, 6), 0.5)
        self.assertAlmostEqual(b.collect_eval_fraction(g, 42, 3), 1.0)
        self.assertAlmostEqual(b.collect_eval_fraction(g, 42, 1), 1.0)

    def test_zero_need_is_complete(self):
        self.assertEqual(b.collect_eval_fraction(b.InventoryGrid(), 1, 0), 1.0)

    def test_missing_grid_is_zero(self):
        self.assertEqual(b.collect_eval_fraction(None, 1, 5), 0.0)

    def test_equality_at_need_completes(self):
        # COMISS + JBE: count == NumToCollect → 1.0 (not strict >)
        g = b.InventoryGrid(items=[b.GridItem(7, 4)])
        self.assertAlmostEqual(b.collect_eval_fraction(g, 7, 4), 1.0)

    def test_broken_stacks_do_not_advance_eval(self):
        # Collect_Eval always passes includeBroken=0 into CountItemsByCbid
        g = b.InventoryGrid(
            items=[
                b.GridItem(9, 10, flag_bit19=True),
                b.GridItem(9, 1, flag_bit19=False),
            ]
        )
        self.assertAlmostEqual(b.collect_eval_fraction(g, 9, 10), 0.1)

    def test_dual_artifacts_present(self):
        self.assertTrue((REVIEWS / "A_aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md").is_file())
        self.assertTrue((REVIEWS / "B_aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md").is_file())
        self.assertTrue((REVIEWS / "a_00611940.md").is_file())
        self.assertTrue((FUNCS / "aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md").is_file())


class TestStructural(unittest.TestCase):
    def test_count_clean_or_fun(self):
        a = CLEAN / "InventoryGrid_CountItemsByCbid.cpp"
        bpath = CLEAN / "FUN_005711c0.cpp"
        self.assertTrue(a.is_file() or bpath.is_file())

    def test_collect_eval_clean(self):
        self.assertTrue(
            (CLEAN / "CVOGObjectiveRequirement_Collect_Eval.cpp").is_file()
            or list(CLEAN.glob("*00611940*"))
        )

    def test_function_records(self):
        self.assertTrue(list(FUNCS.glob("aa_005711c0_*.md")))
        self.assertTrue(list(FUNCS.glob("aa_00611940_*.md")))

    def test_chain_doc(self):
        self.assertTrue((REVIEWS / "CHAIN_2026-07-29_inventory_collect.md").is_file())

    def test_interaction_system_map(self):
        self.assertTrue((SYSTEMS / "interaction-activation.md").is_file())

    def test_useobject_exact(self):
        self.assertTrue((CLEAN / "Client_SendUseObject.cpp").is_file())

    def test_collect_action_artifacts(self):
        self.assertTrue(
            (CLEAN / "CVOGObjectiveRequirement_Collect_Action.cpp").is_file()
        )
        self.assertTrue(list(FUNCS.glob("aa_00611f20_*.md")))
        self.assertTrue(list(REVIEWS.glob("A_aa_00611f20_*")))
        self.assertTrue(list(REVIEWS.glob("B_aa_00611f20_*")))

    def test_deliver_and_interact_finder(self):
        self.assertTrue(
            (CLEAN / "CVOGObjectiveRequirement_Deliver_CargoReady.cpp").is_file()
        )
        self.assertTrue(
            (CLEAN / "CVOGCharacter_FindActiveObjectiveIdForInteract.cpp").is_file()
        )
        self.assertTrue(list(REVIEWS.glob("A_aa_00524520_*")))
        self.assertTrue(list(REVIEWS.glob("B_aa_00524520_*")))


class TestWave3InventoryGridStructural(unittest.TestCase):
    """
    Structural dual + clean gates for inventory grid wave3 VAs:
      CanPlace  aa_00570840 / 0x00570840
      FindFree  aa_005713a0 / 0x005713a0
      Place     aa_00571620 / 0x00571620

    Does not re-implement grid math; drives artifact presence and sealed plate text.
    """

    # Shared sealed family: index = height * x + y  (height @ grid+0x0c)
    _INDEX_MARKERS = (
        "height * x + y",
        "height * x + y".replace(" ", ""),
        "height*(originX",
        "height * (originX",
        "*(grid+0x0c) *",
        "*(grid+0x0c)*",
        "kOffHeight",
        "0x0c) *",
    )

    def _require_dual(self, addr: str, label: str) -> None:
        a_hits = list(REVIEWS.glob(f"A_aa_{addr}_*.md"))
        b_hits = list(REVIEWS.glob(f"B_aa_{addr}_*.md"))
        legacy = list(REVIEWS.glob(f"aa_{addr}_*review*.md"))
        self.assertTrue(
            (a_hits and b_hits) or len(legacy) >= 2,
            f"missing dual A/B (or legacy dual pair) for {label} aa_{addr}",
        )
        for path in (a_hits + b_hits)[:4]:
            text = path.read_text(encoding="utf-8", errors="replace").strip()
            self.assertGreater(len(text), 80, f"dual too short: {path.name}")

    def _clean_text(self, *candidates: str, addr: str) -> str | None:
        for name in candidates:
            path = CLEAN / name
            if path.is_file():
                return path.read_text(encoding="utf-8", errors="replace")
        hits = sorted(CLEAN.glob(f"*{addr}*.cpp"))
        if hits:
            return hits[0].read_text(encoding="utf-8", errors="replace")
        return None

    def _has_index_formula(self, text: str) -> bool:
        low = text.lower()
        # Direct plate comments / sealed formulas
        if "index =" in low or "idx =" in low:
            if "0x0c" in low or "height" in low:
                return True
        # Decompiler body form seen in CanPlace: *(param_1 + 0xc) * … + …
        if "param_1 + 0xc" in low and "*" in text and "+" in text:
            return True
        for marker in self._INDEX_MARKERS:
            if marker.lower() in low:
                return True
        return False

    def test_findfree_dual_and_clean(self):
        addr = "005713a0"
        self._require_dual(addr, "InventoryGrid_FindFreeSlot")
        self.assertTrue(list(FUNCS.glob(f"aa_{addr}_*.md")))
        text = self._clean_text(
            "InventoryGrid_FindFreeSlot.cpp", f"FUN_{addr}.cpp", addr=addr
        )
        self.assertIsNotNone(text, "missing FindFree clean plate")
        assert text is not None
        self.assertGreater(len(text.strip()), 80)
        self.assertTrue(
            self._has_index_formula(text),
            "FindFree clean must document height*x+y index family",
        )

    def test_place_dual_and_clean(self):
        addr = "00571620"
        self._require_dual(addr, "InventoryGrid_PlaceItemFootprint")
        self.assertTrue(list(FUNCS.glob(f"aa_{addr}_*.md")))
        text = self._clean_text(
            "InventoryGrid_PlaceItemFootprint.cpp", f"FUN_{addr}.cpp", addr=addr
        )
        self.assertIsNotNone(text, "missing Place clean plate")
        assert text is not None
        self.assertGreater(len(text.strip()), 80)
        self.assertTrue(
            self._has_index_formula(text),
            "Place clean must seal stamp index formula",
        )
        # Residual scratch from dual strengthen pass
        self.assertTrue(
            (REVIEWS / "a_00571620.md").is_file()
            or list(REVIEWS.glob("a_00571620*.md")),
            "missing Place dual residual scratch a_00571620",
        )

    def test_canplace_function_record_and_clean(self):
        addr = "00570840"
        self.assertTrue(
            list(FUNCS.glob(f"aa_{addr}_*.md")),
            "missing function record for CanPlace aa_00570840",
        )
        text = self._clean_text(
            "InventoryGrid_CanPlace.cpp",
            "InventoryGrid_CanPlaceFootprint.cpp",
            f"FUN_{addr}.cpp",
            addr=addr,
        )
        self.assertIsNotNone(text, "missing CanPlace clean (FUN_00570840 or named)")
        assert text is not None
        self.assertGreater(len(text.strip()), 40)

    def test_canplace_dual_if_landed(self):
        """Soft: when dual A/B for aa_00570840 lands, require the pair."""
        addr = "00570840"
        a_hits = list(REVIEWS.glob(f"A_aa_{addr}_*.md"))
        b_hits = list(REVIEWS.glob(f"B_aa_{addr}_*.md"))
        legacy = list(REVIEWS.glob(f"aa_{addr}_*review*.md"))
        if not a_hits and not b_hits and len(legacy) < 2:
            self.skipTest("dual A/B for aa_00570840 CanPlace not written yet")
        self.assertTrue(
            (a_hits and b_hits) or len(legacy) >= 2,
            "CanPlace dual landed incomplete (need A+B or legacy pair)",
        )
        for path in (a_hits + b_hits + legacy)[:4]:
            text = path.read_text(encoding="utf-8", errors="replace").strip()
            self.assertGreater(len(text), 80, f"CanPlace dual too short: {path.name}")

    def test_canplace_index_formula_if_sealed_in_clean(self):
        """
        Soft on seal language: if CanPlace clean has sealed index docs, assert formula.
        Scaffold-only FUN_00570840 still carries decompiler height*x+y — accept either.
        """
        addr = "00570840"
        text = self._clean_text(
            "InventoryGrid_CanPlace.cpp",
            "InventoryGrid_CanPlaceFootprint.cpp",
            f"FUN_{addr}.cpp",
            addr=addr,
        )
        if text is None:
            self.skipTest("CanPlace clean not present")
        sealed = (
            "seal" in text.lower()
            or "index =" in text.lower()
            or "idx =" in text.lower()
            or "matches canplace" in text.lower()
            or self._has_index_formula(text)
        )
        if not sealed:
            self.skipTest("CanPlace index formula not yet sealed in clean plate")
        self.assertTrue(
            self._has_index_formula(text),
            "CanPlace clean claims index/seal but missing height*x+y family",
        )

    def test_inventory_transfer_system_map(self):
        path = SYSTEMS / "inventory-transfer.md"
        self.assertTrue(path.is_file())
        text = path.read_text(encoding="utf-8", errors="replace")
        self.assertIn("00571620", text)
        self.assertIn("005713a0", text)


if __name__ == "__main__":
    unittest.main()
