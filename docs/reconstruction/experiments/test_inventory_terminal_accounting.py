"""Inventory terminal accounting checks against reconstruction coverage.

Drives real inventory.jsonl + dual review filesystem (not hard-coded expected dual total).
"""
from __future__ import annotations

import json
import re
import unittest
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
INV = ROOT / "docs" / "reconstruction" / "coverage" / "inventory.jsonl"
REV = ROOT / "docs" / "reconstruction" / "reviews"
PROGRESS = ROOT / "docs" / "reconstruction" / "coverage" / "progress.json"

TERMINAL_STATUSES = frozenset({"full", "reviewed", "trivial-batch", "deferred-low"})
FORBIDDEN_STATUSES = frozenset({"none", "raw", "partial"})


class InventoryTerminalAccountingTests(unittest.TestCase):
    def test_inventory_statuses_are_terminal_only(self) -> None:
        counts: Counter[str] = Counter()
        addrs: set[str] = set()
        with INV.open(encoding="utf-8") as fh:
            for line in fh:
                line = line.strip()
                if not line:
                    continue
                row = json.loads(line)
                status = row["status"]
                counts[status] += 1
                addr = str(row["addr"]).lower().replace("0x", "").zfill(8)
                addrs.add(addr)
                self.assertIn(
                    status,
                    TERMINAL_STATUSES,
                    f"non-terminal status {status!r} at {row.get('addr')}",
                )
                self.assertNotIn(status, FORBIDDEN_STATUSES)
        self.assertGreater(len(addrs), 25000)
        self.assertEqual(len(addrs), sum(counts.values()))
        for bad in FORBIDDEN_STATUSES:
            self.assertEqual(counts.get(bad, 0), 0)

    def test_progress_dual_matches_filesystem_A_and_B(self) -> None:
        a: set[str] = set()
        b: set[str] = set()
        for p in REV.iterdir():
            name = p.name
            m = re.match(r"A_aa_([0-9a-fA-F]{8})", name)
            if m:
                a.add(m.group(1).lower())
            m = re.match(r"B_aa_([0-9a-fA-F]{8})", name)
            if m:
                b.add(m.group(1).lower())
        dual_fs = len(a & b)
        self.assertGreater(dual_fs, 2000)
        prog = json.loads(PROGRESS.read_text(encoding="utf-8"))
        self.assertEqual(int(prog["dual_ab_pairs"]), dual_fs)

    def test_gap_close_vas_present_in_inventory(self) -> None:
        need = {
            "0051b850",
            "00537d10",
            "00573900",
            "008612b0",
            "008c50f4",
        }
        found: set[str] = set()
        with INV.open(encoding="utf-8") as fh:
            for line in fh:
                m = re.search(r'"addr"\s*:\s*"0x([0-9a-fA-F]+)"', line)
                if m:
                    h = m.group(1).lower().zfill(8)
                    if h in need:
                        found.add(h)
        self.assertEqual(need, found)


if __name__ == "__main__":
    unittest.main()
