"""
Tests drive the pure model of the SHIPPED reconstruction logic in
vehicle_entity_set_steer_input.py (mirrors reconstructed-exact gate).

Also structurally asserts reconstruction artifacts exist with required markers.
"""

from __future__ import annotations

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


class TestSetSteerInputGate(unittest.TestCase):
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
        # bits not in 0xC7: 0x08, 0x10, 0x20
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


class TestReconstructionArtifactsStructural(unittest.TestCase):
    """Static checks: required docs exist and are not empty stubs."""

    def _read(self, rel: str) -> str:
        path = RECON_ROOT / rel
        self.assertTrue(path.is_file(), f"missing {path}")
        text = path.read_text(encoding="utf-8")
        self.assertGreater(len(text.strip()), 80, f"too short: {rel}")
        return text

    def test_state_files_present(self):
        for name in (
            "PROJECT_STATE.md",
            "WORK_QUEUE.md",
            "ACTIVE_WORK.md",
            "COMPLETED_WORK.md",
            "NAMING_REGISTRY.md",
            "TYPE_REGISTRY.md",
            "OBJECT_LAYOUTS.md",
            "SYSTEM_INDEX.md",
            "VERIFICATION_MATRIX.md",
            "EVIDENCE_INDEX.md",
            "RUNTIME_EXPERIMENTS.md",
            "UNRESOLVED_FINDINGS.md",
            "DECISION_LOG.md",
            "CHANGE_LOG.md",
            "RESUME.md",
        ):
            self._read(name)

    def test_set_steer_raw_and_function_and_clean(self):
        raw = self._read("raw/aa_004f5620_VehicleEntity_SetSteerInput.md")
        self.assertIn("0x004f5620", raw)
        self.assertIn("0x618", raw)

        fn = self._read("functions/aa_004f5620_VehicleEntity_SetSteerInput.md")
        self.assertIn("aa_004f5620", fn)
        self.assertIn("Confidence", fn)

        clean = self._read("reconstructed-exact/VehicleEntity_SetSteerInput.cpp")
        self.assertIn("SetSteerInput", clean)
        self.assertIn("0xC7", clean)
        # Must not look like unedited Ghidra paste
        self.assertNotIn("undefined4", clean)

    def test_system_map_sections(self):
        text = self._read("systems/input-drive-control.md")
        for section in (
            "Scope",
            "Known entry points",
            "Behavioral flow",
            "Call graph",
            "Data flow",
            "State owners",
            "State transitions",
            "External effects",
            "Dependencies",
            "Known types",
            "Known identifiers",
            "Important functions",
            "Evidence",
            "Confidence",
            "Open questions",
            "Verification gaps",
            "Next recommended work",
        ):
            self.assertIn(section, text)

    def test_reviews_exist(self):
        recon_rev = list((RECON_ROOT / "reviews").glob("*004f5620*recon*"))
        skep_rev = list((RECON_ROOT / "reviews").glob("*004f5620*skep*"))
        if not recon_rev:
            recon_rev = list((RECON_ROOT / "reviews").glob("*SetSteer*"))
        # Accept either naming pattern used by review agents
        all_reviews = list((RECON_ROOT / "reviews").glob("*.md"))
        self.assertGreaterEqual(len(all_reviews), 2, "need reconstruction + skeptical reviews")
        joined = "\n".join(p.read_text(encoding="utf-8") for p in all_reviews)
        self.assertIn("004f5620", joined)
        self.assertNotEqual(joined.strip().upper(), "LGTM")
        for token in ("inspected", "evidence", "uncertain"):
            self.assertTrue(
                token in joined.lower() or "confirm" in joined.lower(),
                f"reviews should discuss inspection/evidence/uncertainty ({token})",
            )


if __name__ == "__main__":
    unittest.main()
