"""Verification-first policy: coverage metrics are not completion.

Drives real progress.json + inventory.jsonl + dual filesystem.
Fails if the project claims dual-depth or reconstruction completion
from inventory stamp / dual counts alone.
"""
from __future__ import annotations

import json
import re
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
PROGRESS = ROOT / "docs" / "reconstruction" / "coverage" / "progress.json"
INV = ROOT / "docs" / "reconstruction" / "coverage" / "inventory.jsonl"
REV = ROOT / "docs" / "reconstruction" / "reviews"
RESUME = ROOT / "docs" / "reconstruction" / "RESUME.md"
LEDGER = ROOT / "docs" / "reconstruction" / "COVERAGE_LEDGER.md"


class VerificationFirstPolicyTests(unittest.TestCase):
    def test_progress_does_not_claim_dual_depth_complete(self) -> None:
        prog = json.loads(PROGRESS.read_text(encoding="utf-8"))
        # Dual depth must remain incomplete while dual << live universe.
        dual = int(prog["dual_ab_pairs"])
        live = int(prog["function_count_ghidra"])
        self.assertGreater(live, 0)
        self.assertLess(dual, live)
        # Must not claim dual depth as the terminal bar.
        self.assertNotEqual(dual, live)
        # Honesty fields: terminal inventory stamp is not dual complete.
        if "dual_depth_complete" in prog:
            self.assertFalse(bool(prog["dual_depth_complete"]))
        # full_coverage inventory stamp must not be misread as dual complete.
        if prog.get("full_coverage") is True:
            self.assertLess(dual / live, 0.5, "dual still far from universe")

    def test_dual_filesystem_is_honest_byproduct_not_completion_flag(self) -> None:
        a: set[str] = set()
        b: set[str] = set()
        for p in REV.iterdir():
            m = re.match(r"A_aa_([0-9a-fA-F]{8})", p.name)
            if m:
                a.add(m.group(1).lower())
            m = re.match(r"B_aa_([0-9a-fA-F]{8})", p.name)
            if m:
                b.add(m.group(1).lower())
        dual_fs = len(a & b)
        prog = json.loads(PROGRESS.read_text(encoding="utf-8"))
        self.assertEqual(int(prog["dual_ab_pairs"]), dual_fs)
        live = int(prog["function_count_ghidra"])
        # Dual presence is a byproduct; must not equal live universe (false complete).
        self.assertLess(dual_fs, live)

    def test_inventory_full_is_not_verification_complete(self) -> None:
        """`full` rows are industrial accounting — not verified completion."""
        full = 0
        reviewed = 0
        with INV.open(encoding="utf-8") as fh:
            for line in fh:
                if not line.strip():
                    continue
                st = json.loads(line)["status"]
                if st == "full":
                    full += 1
                elif st == "reviewed":
                    reviewed += 1
        self.assertGreater(full, 0)
        # Full corpus must remain larger than reviewed dual depth under current honesty.
        self.assertGreater(full, reviewed)
        prog = json.loads(PROGRESS.read_text(encoding="utf-8"))
        # Progress must not set a completion flag that equates full inventory to done.
        self.assertFalse(prog.get("reconstruction_complete", False))
        self.assertFalse(prog.get("project_verified_complete", False))

    def test_policy_banners_present_in_resume_and_ledger(self) -> None:
        resume = RESUME.read_text(encoding="utf-8")
        ledger = LEDGER.read_text(encoding="utf-8")
        for blob in (resume, ledger):
            self.assertRegex(
                blob,
                r"(?i)never optimize for coverage|coverage is a byproduct|verification requirements",
            )
            self.assertRegex(
                blob,
                r"(?i)scaffold|partial scaffold|placeholder",
            )


if __name__ == "__main__":
    unittest.main()
