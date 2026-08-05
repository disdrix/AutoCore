"""
Coverage gate for docs/reconstruction corpus.

Asserts ledger/progress, high-priority system maps, function raw+clean pairs
(for priority units and a sampled industrial set), SetSteerInput behavioral
gate (via vehicle_entity_set_steer_input model), and minimum review count.

Industrial corpus note: function records may be renamed while raw remains
aa_<addr>_FUN_*.md — resolve by address, not exact stem match.
"""

from __future__ import annotations

import json
import re
import unittest
from pathlib import Path

from vehicle_entity_set_steer_input import (
    INPUT_AXIS_LOCK_MASK,
    DriveAxisLockObject,
    VehicleEntityDriveAxes,
    vehicle_entity_set_longitudinal_input,
    vehicle_entity_set_steer_input,
)

RECON_ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS_DIR = RECON_ROOT / "functions"
RAW_DIR = RECON_ROOT / "raw"
CLEAN_DIR = RECON_ROOT / "reconstructed-exact"
SYSTEMS_DIR = RECON_ROOT / "systems"
REVIEWS_DIR = RECON_ROOT / "reviews"
PROGRESS_PATH = RECON_ROOT / "coverage" / "progress.json"

UNDEFINED4_TYPE_RE = re.compile(r"\bundefined4\b")
SCAFFOLD_RE = re.compile(r"\bscaffold\b", re.IGNORECASE)
# BOM or other invisible chars in filenames
BAD_NAME_RE = re.compile(r"[\ufeff\u200b\u200c\u200d]")

PRIORITY_SYSTEMS = (
    "missions-progression",
    "inventory-transfer",
    "skills-abilities",
    "input-drive-control",
)

# High-priority units that must always have three representations + clean quality.
PRIORITY_UNITS = (
    ("004f5620", "VehicleEntity_SetSteerInput"),
    ("004f5650", "VehicleEntity_SetLongitudinalInput"),
    ("009223b0", "Client_Input_DriveControlTick"),
    ("005327c0", "CVOGReaction_GiveMission"),
    ("005462b0", "CVOGCharacter_CheckMissionRequirements"),
    ("00815710", "Client_PacketDispatch"),
    ("00811170", "Client_RecvSkillStatusEffect"),
    ("00571620", "InventoryGrid_PlaceItemFootprint"),
)

PREFERRED_CLEAN_UNITS = (
    "VehicleEntity_SetSteerInput",
    "VehicleEntity_SetLongitudinalInput",
)


def _function_record_paths() -> list[Path]:
    out: list[Path] = []
    for p in sorted(FUNCTIONS_DIR.glob("aa_*.md")):
        if BAD_NAME_RE.search(p.name):
            continue
        out.append(p)
    return out


def _stem_parts(record_path: Path) -> tuple[str, str, str]:
    """
    functions/aa_004f5620_VehicleEntity_SetSteerInput.md
    -> (stem, addr_hex, canonical_name)
    """
    stem = record_path.stem
    m = re.match(r"^(aa_([0-9a-fA-F]{8}))_(.+)$", stem)
    if not m:
        raise AssertionError(f"unexpected function record name: {record_path.name}")
    return stem, m.group(2).lower(), m.group(3)


def _find_raw(addr: str, stem: str) -> Path | None:
    exact = RAW_DIR / f"{stem}.md"
    if exact.is_file():
        return exact
    candidates = [
        p
        for p in RAW_DIR.glob(f"aa_{addr}_*.md")
        if not p.name.endswith(".annotated.md")
    ]
    return candidates[0] if candidates else None


def _find_clean(addr: str, name: str) -> Path | None:
    preferred = CLEAN_DIR / f"{name}.cpp"
    if preferred.is_file():
        return preferred
    fun = CLEAN_DIR / f"FUN_{addr}.cpp"
    if fun.is_file():
        return fun
    # Address-suffixed domain aliases (e.g. Named_*_00aabbcc.cpp)
    hits = sorted(CLEAN_DIR.glob(f"*{addr}*.cpp"))
    return hits[0] if hits else None


class TestCoverageLedgerAndProgress(unittest.TestCase):
    def test_coverage_ledger_exists(self):
        path = RECON_ROOT / "COVERAGE_LEDGER.md"
        self.assertTrue(path.is_file(), f"missing {path}")
        text = path.read_text(encoding="utf-8")
        self.assertGreater(len(text.strip()), 40)
        self.assertIn("Coverage", text)

    def test_progress_json_inventory_accounted(self):
        self.assertTrue(PROGRESS_PATH.is_file(), f"missing {PROGRESS_PATH}")
        data = json.loads(PROGRESS_PATH.read_text(encoding="utf-8"))
        self.assertIn("inventory_listed", data)
        listed = data["inventory_listed"]
        self.assertIsInstance(listed, int)
        self.assertGreater(listed, 0)
        # Industrial inventory must remain fully accounted when key present.
        if "inventory_source_total_field" in data:
            self.assertEqual(listed, data["inventory_source_total_field"])
        if "inventory_status" in data:
            status = data["inventory_status"]
            self.assertEqual(status.get("none", 0), 0, f"residual none addrs: {status}")
        if "full_coverage" in data:
            self.assertTrue(data["full_coverage"])
        if "inventory_accounted" in data:
            self.assertTrue(data["inventory_accounted"])


class TestPrioritySystemMaps(unittest.TestCase):
    def test_priority_systems_exist_with_scope(self):
        for system in PRIORITY_SYSTEMS:
            with self.subTest(system=system):
                path = SYSTEMS_DIR / f"{system}.md"
                self.assertTrue(path.is_file(), f"missing system map {path}")
                text = path.read_text(encoding="utf-8")
                self.assertGreater(len(text.strip()), 80, f"too short: {system}")
                self.assertRegex(
                    text,
                    r"(?m)^#{1,3}\s+Scope\b",
                    msg=f"{system}.md must have a Scope section",
                )
                self.assertRegex(
                    text,
                    r"(?m)^#{1,3}\s+(Known entry points|Entry points)\b",
                    msg=f"{system}.md must have entry points",
                )
                self.assertRegex(
                    text,
                    r"(?m)^#{1,3}\s+Behavioral flow\b",
                    msg=f"{system}.md must have Behavioral flow",
                )
                self.assertRegex(
                    text,
                    r"(?m)^#{1,3}\s+(Important functions|Call graph)",
                    msg=f"{system}.md must have Important functions or Call graph",
                )
                self.assertRegex(text, r"(?m)^#{1,3}\s+Evidence\b")
                self.assertRegex(text, r"(?m)^#{1,3}\s+Confidence\b")
                self.assertRegex(text, r"(?m)^#{1,3}\s+Open questions\b")


class TestFunctionRecordsRawAndClean(unittest.TestCase):
    def test_at_least_twenty_function_records(self):
        records = _function_record_paths()
        self.assertGreaterEqual(
            len(records),
            20,
            f"need >= 20 function records, found {len(records)}",
        )

    def test_priority_units_have_raw_and_clean(self):
        for addr, name in PRIORITY_UNITS:
            with self.subTest(addr=addr, name=name):
                raws = [
                    p
                    for p in RAW_DIR.glob(f"aa_{addr}_*.md")
                    if not p.name.endswith(".annotated.md")
                ]
                self.assertTrue(raws, f"missing raw for 0x{addr}")
                clean = _find_clean(addr, name)
                self.assertIsNotNone(clean, f"missing clean for {name} / 0x{addr}")
                raw_text = raws[0].read_text(encoding="utf-8", errors="replace")
                clean_text = clean.read_text(encoding="utf-8", errors="replace")
                self.assertGreater(len(raw_text.strip()), 40)
                self.assertGreater(len(clean_text.strip()), 40)
                if name in PREFERRED_CLEAN_UNITS:
                    self.assertFalse(
                        bool(UNDEFINED4_TYPE_RE.search(clean_text)),
                        f"{name} clean must not use undefined4 as a type token",
                    )

    def test_sampled_records_resolve_raw_and_clean_by_address(self):
        """Sample industrial records: resolve raw/clean by VA, not exact stem."""
        records = _function_record_paths()
        self.assertGreaterEqual(len(records), 20)

        # Always include priority record stems if present, then first N + stride samples.
        sample: list[Path] = []
        for addr, name in PRIORITY_UNITS:
            hits = list(FUNCTIONS_DIR.glob(f"aa_{addr}_*.md"))
            sample.extend(hits[:1])
        # Stride through corpus for industrial coverage without O(n*glob) explosion.
        stride = max(1, len(records) // 40)
        sample.extend(records[::stride][:40])

        seen: set[str] = set()
        for record in sample:
            if record.name in seen:
                continue
            seen.add(record.name)
            with self.subTest(record=record.name):
                _stem, addr, name = _stem_parts(record)
                raw = _find_raw(addr, _stem)
                clean = _find_clean(addr, name)
                self.assertIsNotNone(raw, f"missing raw for aa_{addr} ({record.name})")
                self.assertIsNotNone(clean, f"missing clean for {name} / aa_{addr}")
                raw_text = raw.read_text(encoding="utf-8", errors="replace")
                clean_text = clean.read_text(encoding="utf-8", errors="replace")
                self.assertGreater(len(raw_text.strip()), 40, f"raw too short: {raw.name}")
                self.assertGreater(
                    len(clean_text.strip()), 40, f"clean too short: {clean.name}"
                )
                has_undefined4 = bool(UNDEFINED4_TYPE_RE.search(clean_text))
                documents_scaffold = bool(SCAFFOLD_RE.search(clean_text))
                # Industrial emit uses "scaffold" or "PURPOSE (auto)" as scaffold markers.
                industrial = "PURPOSE (auto)" in clean_text or "READABILITY (auto CF)" in clean_text
                if name in PREFERRED_CLEAN_UNITS:
                    self.assertFalse(has_undefined4)
                else:
                    self.assertTrue(
                        (not has_undefined4) or documents_scaffold or industrial,
                        f"{name}: undefined4 without scaffold/industrial note",
                    )


class TestSetSteerInputGateFromModel(unittest.TestCase):
    """SetSteerInput gate tests — drive the pure model of reconstructed-exact logic."""

    def test_mask_constant_is_0xc7(self):
        self.assertEqual(INPUT_AXIS_LOCK_MASK, 0xC7)
        self.assertEqual(INPUT_AXIS_LOCK_MASK, 199)

    def test_null_lock_allows_write(self):
        e = VehicleEntityDriveAxes(steer_input=0.25, lock_object=None)
        vehicle_entity_set_steer_input(e, -1.0)
        self.assertEqual(e.steer_input, -1.0)

    def test_zero_flags_allows_write(self):
        e = VehicleEntityDriveAxes(
            steer_input=0.0, lock_object=DriveAxisLockObject(flags_at_0xb4=0)
        )
        vehicle_entity_set_steer_input(e, 1.0)
        self.assertEqual(e.steer_input, 1.0)

    def test_lock_bits_suppress_write(self):
        for bit in (0x01, 0x02, 0x04, 0x40, 0x80, 0xC7, 0x05, 0xC0):
            with self.subTest(bit=bit):
                e = VehicleEntityDriveAxes(
                    steer_input=0.5,
                    lock_object=DriveAxisLockObject(flags_at_0xb4=bit),
                )
                vehicle_entity_set_steer_input(e, -1.0)
                self.assertEqual(
                    e.steer_input,
                    0.5,
                    msg=f"expected suppress for flags={bit:#x}",
                )

    def test_unrelated_bits_outside_mask_do_not_suppress(self):
        e = VehicleEntityDriveAxes(
            steer_input=0.0,
            lock_object=DriveAxisLockObject(flags_at_0xb4=0x08 | 0x10 | 0x20),
        )
        vehicle_entity_set_steer_input(e, 0.5)
        self.assertEqual(e.steer_input, 0.5)

    def test_no_clamp_extreme_values(self):
        e = VehicleEntityDriveAxes(lock_object=None)
        vehicle_entity_set_steer_input(e, 99.0)
        self.assertEqual(e.steer_input, 99.0)
        vehicle_entity_set_steer_input(e, -99.0)
        self.assertEqual(e.steer_input, -99.0)

    def test_longitudinal_sibling_same_gate(self):
        e = VehicleEntityDriveAxes(
            longitudinal_input=0.0,
            lock_object=DriveAxisLockObject(flags_at_0xb4=0x01),
        )
        vehicle_entity_set_longitudinal_input(e, -1.0)
        self.assertEqual(e.longitudinal_input, 0.0)
        e.lock_object.flags_at_0xb4 = 0
        vehicle_entity_set_longitudinal_input(e, -1.0)
        self.assertEqual(e.longitudinal_input, -1.0)

    def test_clean_setters_document_gate_and_offsets(self):
        """Structural: shipped clean sources document 0xC7 and axis offsets."""
        for name, offset in (
            ("VehicleEntity_SetSteerInput", "0x618"),
            ("VehicleEntity_SetLongitudinalInput", "0x614"),
        ):
            with self.subTest(name=name):
                path = CLEAN_DIR / f"{name}.cpp"
                self.assertTrue(path.is_file(), f"missing {path}")
                text = path.read_text(encoding="utf-8", errors="replace")
                self.assertTrue(
                    "0xC7" in text or "199" in text,
                    f"{name} must document gate mask 0xC7/199",
                )
                self.assertIn(offset, text, f"{name} must document store {offset}")


class TestReviewsFloor(unittest.TestCase):
    def test_reviews_has_at_least_four_md_files(self):
        self.assertTrue(REVIEWS_DIR.is_dir(), f"missing reviews dir {REVIEWS_DIR}")
        reviews = sorted(REVIEWS_DIR.glob("*.md"))
        self.assertGreaterEqual(
            len(reviews),
            4,
            f"reviews/ must have >= 4 review md files, found {len(reviews)}",
        )
        for path in reviews[:20]:
            text = path.read_text(encoding="utf-8", errors="replace").strip()
            self.assertGreater(len(text), 40, f"review too short: {path.name}")

    def test_priority_duals_exist(self):
        for addr, name in PRIORITY_UNITS[:6]:
            with self.subTest(addr=addr, name=name):
                a_hits = list(REVIEWS_DIR.glob(f"A_aa_{addr}_*.md"))
                b_hits = list(REVIEWS_DIR.glob(f"B_aa_{addr}_*.md"))
                # Accept older reconstruction/skeptical naming as dual for some units.
                legacy = list(REVIEWS_DIR.glob(f"aa_{addr}_*review*.md"))
                self.assertTrue(
                    (a_hits and b_hits) or len(legacy) >= 2,
                    f"missing dual reviews for {name} @ {addr}",
                )


class TestMissionDialogC2SArtifacts(unittest.TestCase):
    """
    Gate for sealed mission dialog C2S chain (0x206E flush + abandon 0x20B2).

    Requires function record for aa_008ab8f0 (any name). Dual A_/B_ reviews
    for that VA are soft: skip when parent has not written them yet.
    """

    def test_flush_function_record_aa_008ab8f0_exists(self):
        matches = list(FUNCTIONS_DIR.glob("aa_008ab8f0_*.md"))
        self.assertTrue(
            matches,
            "functions/aa_008ab8f0_* must exist (FlushPreparedResponse / FUN_008ab8f0)",
        )
        text = matches[0].read_text(encoding="utf-8", errors="replace")
        self.assertGreater(len(text.strip()), 40)

    def test_flush_clean_exists(self):
        named = CLEAN_DIR / "Client_MissionDialog_FlushPreparedResponse.cpp"
        fun = CLEAN_DIR / "FUN_008ab8f0.cpp"
        self.assertTrue(
            named.is_file() or fun.is_file(),
            "missing FlushPreparedResponse or FUN_008ab8f0 clean",
        )

    def test_mission_dialog_handle_button_and_prepare_clean(self):
        for name in (
            "Client_MissionDialogHandleButton",
            "Client_NpcDialog_PrepareResponseOpcode",
            "CVOGReaction_FailMission",
        ):
            with self.subTest(name=name):
                path = CLEAN_DIR / f"{name}.cpp"
                self.assertTrue(path.is_file(), f"missing {path}")

    def test_flush_dual_reviews_soft(self):
        a_hits = list(REVIEWS_DIR.glob("A_aa_008ab8f0_*.md"))
        b_hits = list(REVIEWS_DIR.glob("B_aa_008ab8f0_*.md"))
        if not a_hits and not b_hits:
            self.skipTest("A_/B_ reviews for aa_008ab8f0 not present yet")
        self.assertTrue(a_hits, "missing A_aa_008ab8f0_*")
        self.assertTrue(b_hits, "missing B_aa_008ab8f0_*")


if __name__ == "__main__":
    unittest.main()
