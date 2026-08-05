"""
Tests drive SHIPPED reconstructed behavior models in mission_dialog_c2s.py
(mirrors Client_NpcDialog_PrepareResponseOpcode, HandleButton fill/abandon,
FlushPreparedResponse, UiModal abandon confirm, CVOGReaction_FailMission).

Also structurally asserts reconstructed-exact artifacts exist.
"""

from __future__ import annotations

import unittest
from pathlib import Path

import mission_dialog_c2s as m

RECON_ROOT = Path(__file__).resolve().parents[1]
CLEAN_DIR = RECON_ROOT / "reconstructed-exact"
FUNCTIONS_DIR = RECON_ROOT / "functions"
RAW_DIR = RECON_ROOT / "raw"
REVIEWS_DIR = RECON_ROOT / "reviews"


class TestMissionDialogResponse206E(unittest.TestCase):
    """Full 0x206E path: prepare → fill → flush."""

    def test_constants_match_evidence(self):
        self.assertEqual(m.OPCODE_MISSION_DIALOG_RESPONSE, 0x206E)
        self.assertEqual(m.OPCODE_FAIL_MISSION, 0x20B2)
        self.assertEqual(m.RESPONSE_SIZE, 0x20)
        self.assertEqual(m.FAIL_PACKET_SIZE, 0x18)
        self.assertEqual(m.MODAL_ABANDON_PROMPT, 0x4E47)
        self.assertEqual(m.MODAL_ABANDON_CONFIRM, 0x4E46)
        self.assertEqual(m.DIRTY_BIT, 0x10)

    def test_prepare_sets_opcode_206e_and_mission_def(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, mission_def_id=42, mission_def_ptr=0xDEAD)
        self.assertEqual(d.opcode_at_650, m.OPCODE_MISSION_DIALOG_RESPONSE)
        self.assertEqual(d.opcode_at_650, 0x206E)
        self.assertEqual(d.mission_def_id, 42)
        self.assertEqual(d.mission_def_ptr, 0xDEAD)

    def test_full_prepare_fill_flush_emits_0x20_packet(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, mission_def_id=1001)
        m.handle_button_state1_fill_payload(
            d, button_index=1, npc_tfid=(0x1111, 0x2222, 0, 1)
        )
        pkt = m.flush_prepared_response(d)
        self.assertIsNotNone(pkt)
        assert pkt is not None
        self.assertEqual(pkt.opcode, 0x206E)
        self.assertEqual(pkt.size, 0x20)
        self.assertEqual(pkt.size, m.RESPONSE_SIZE)
        self.assertEqual(pkt.payload["mission_id"], 1001)
        self.assertEqual(pkt.payload["accepted"], 1)
        self.assertEqual(pkt.payload["npc_tfid"], (0x1111, 0x2222, 0, 1))

    def test_flush_skips_when_opcode_zero(self):
        d = m.DialogContext(opcode_at_650=0, mission_id_at_654=9)
        self.assertIsNone(m.flush_prepared_response(d))

    def test_state0_sends_206f_not_206e(self):
        d = m.DialogContext()
        pkt = m.handle_button_state0_accept_request(d, 1, 0xAA, 0xBB)
        self.assertEqual(pkt.opcode, 0x206F)
        self.assertEqual(pkt.size, 0x18)
        self.assertNotEqual(pkt.opcode, 0x206E)

    def test_opcode_offset_index_math(self):
        self.assertEqual(m.DIALOG_OPCODE_DWORD_INDEX * 4, m.DIALOG_OPCODE_OFFSET)
        self.assertEqual(m.DIALOG_OPCODE_OFFSET, 0x650)

    def test_packet_body_plus_opcode_is_0x20(self):
        # missionId4 + accepted4 + pad4 + TFID16 = 28; + opcode4 = 32
        body = 4 + 4 + 4 + 16
        self.assertEqual(body + 4, m.RESPONSE_SIZE)
        self.assertEqual(m.RESPONSE_SIZE, 0x20)


class TestFlushInvokerUF010(unittest.TestCase):
    """UF-010: vtable +0x440 invoker chain (static model)."""

    def test_vtable_slot_math(self):
        self.assertEqual(m.FLUSH_VTABLE_BASE + m.FLUSH_VTABLE_METHOD_OFFSET, m.FLUSH_VTABLE_SLOT_ADDR)
        self.assertEqual(m.vtable_slot_address(), 0x00A4A95C)
        self.assertEqual(m.FLUSH_FUNCTION_VA, 0x008AB8F0)
        self.assertEqual(m.FLUSH_VTABLE_METHOD_OFFSET, 0x440)

    def test_host_field_and_table_index(self):
        self.assertEqual(
            (m.CLIENT_NPC_DIALOG_FIELD - m.DIALOG_TABLE_BASE) // 4,
            m.DIALOG_TABLE_INDEX,
        )
        self.assertEqual(m.DIALOG_TABLE_INDEX, 10)
        self.assertNotEqual(m.CLIENT_NPC_DIALOG_FIELD, 0x107C)

    def test_close_invoker_skips_when_not_visible(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, mission_def_id=7)
        self.assertIsNone(m.close_visible_dialog_invokes_flush(d, visible=False))

    def test_close_invoker_flushes_when_visible_and_prepared(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, mission_def_id=7)
        m.handle_button_state1_fill_payload(d, button_index=1)
        pkt = m.close_visible_dialog_invokes_flush(d, visible=True)
        self.assertIsNotNone(pkt)
        assert pkt is not None
        self.assertEqual(pkt.opcode, 0x206E)
        self.assertEqual(pkt.size, 0x20)

    def test_event_dispatch_after_handle_success(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, 99)
        m.handle_button_state1_fill_payload(d, 1)
        pkt = m.event_dispatch_after_handle_button(d, handle_button_success=True)
        self.assertIsNotNone(pkt)
        assert pkt is not None
        self.assertEqual(pkt.size, 0x20)

    def test_event_dispatch_skips_on_handle_fail(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, 99)
        self.assertIsNone(
            m.event_dispatch_after_handle_button(d, handle_button_success=False)
        )

    def test_close_button_flushes_without_fill(self):
        """UF-011 risk: Prepare-on-show + close still flushes 0x206E."""
        d = m.DialogContext()
        m.prepare_response_opcode(d, mission_def_id=0)  # opcode set, body empty
        pkt = m.event_dispatch_after_handle_button(
            d, handle_button_success=False, close_button=True
        )
        self.assertIsNotNone(pkt)
        assert pkt is not None
        self.assertEqual(pkt.opcode, 0x206E)
        self.assertEqual(pkt.size, 0x20)
        self.assertEqual(pkt.payload["mission_id"], 0)

    def test_flush_does_not_clear_opcode(self):
        d = m.DialogContext()
        m.prepare_response_opcode(d, 5)
        m.flush_prepared_response(d)
        self.assertEqual(d.opcode_at_650, 0x206E)  # no clear in Flush body


class TestAbandonFailMission(unittest.TestCase):
    """Abandon prompt → confirm 0x4e46 → C2S 0x20B2; FailMission dirty bit."""

    def test_abandon_prompt_stashes_mission_and_modal_code(self):
        pending, modal = m.handle_button_state2_abandon_prompt(55)
        self.assertEqual(pending, 55)
        self.assertEqual(modal, m.MODAL_ABANDON_PROMPT)
        self.assertEqual(modal, 0x4E47)

    def test_abandon_prompt_null_mission(self):
        pending, modal = m.handle_button_state2_abandon_prompt(None)
        self.assertEqual(pending, 0xFFFFFFFF)
        self.assertEqual(modal, m.MODAL_ABANDON_PROMPT)

    def test_confirm_sends_20b2_size_18(self):
        pending, modal = m.handle_button_state2_abandon_prompt(55)
        self.assertEqual(modal, 0x4E47)
        # Confirm is a separate modal code (0x4e46), not the prompt code.
        self.assertEqual(m.MODAL_ABANDON_CONFIRM, 0x4E46)
        pkt = m.ui_modal_abandon_confirm(
            pending_mission_id=pending,
            character_coid=(0x100, 0x200),
            mission_present=True,
        )
        self.assertIsNotNone(pkt)
        assert pkt is not None
        self.assertEqual(pkt.opcode, 0x20B2)
        self.assertEqual(pkt.opcode, m.OPCODE_FAIL_MISSION)
        self.assertEqual(pkt.size, 0x18)
        self.assertEqual(pkt.size, m.FAIL_PACKET_SIZE)
        self.assertEqual(pkt.payload["mission_id"], 55)
        self.assertEqual(pkt.payload["character_coid_lo"], 0x100)
        self.assertEqual(pkt.payload["character_coid_hi"], 0x200)

    def test_confirm_skips_when_no_pending(self):
        self.assertIsNone(
            m.ui_modal_abandon_confirm(
                pending_mission_id=0xFFFFFFFF,
                character_coid=(1, 2),
                mission_present=True,
            )
        )

    def test_confirm_skips_when_mission_missing(self):
        self.assertIsNone(
            m.ui_modal_abandon_confirm(
                pending_mission_id=55,
                character_coid=(1, 2),
                mission_present=False,
            )
        )

    def test_fail_mission_sets_dirty_bit(self):
        result, dirty = m.fail_mission({55, 99}, 55, dirty_flags=0)
        self.assertEqual(result, 1)
        self.assertEqual(dirty & m.DIRTY_BIT, m.DIRTY_BIT)
        self.assertEqual(dirty & 0x10, 0x10)

    def test_fail_mission_miss_returns_zero(self):
        result, dirty = m.fail_mission({1}, 55, dirty_flags=0)
        self.assertEqual(result, 0)
        self.assertEqual(dirty, 0)

    def test_fail_mission_preserves_other_dirty_bits(self):
        result, dirty = m.fail_mission({7}, 7, dirty_flags=0x01)
        self.assertEqual(result, 1)
        self.assertEqual(dirty, 0x01 | 0x10)


class TestStructuralArtifacts(unittest.TestCase):
    """Static checks: reconstructed-exact units for sealed C2S chain exist."""

    def test_handle_button_exact_exists(self):
        path = CLEAN_DIR / "Client_MissionDialogHandleButton.cpp"
        self.assertTrue(path.is_file(), f"missing {path}")
        text = path.read_text(encoding="utf-8", errors="replace")
        self.assertIn("0x206", text)  # 0x206E/0x206F notes
        self.assertIn("0x4e47", text.lower())

    def test_prepare_exact_exists(self):
        path = CLEAN_DIR / "Client_NpcDialog_PrepareResponseOpcode.cpp"
        self.assertTrue(path.is_file(), f"missing {path}")
        text = path.read_text(encoding="utf-8", errors="replace")
        self.assertIn("0x206e", text.lower())
        self.assertIn("0x650", text)

    def test_fail_mission_exact_exists(self):
        path = CLEAN_DIR / "CVOGReaction_FailMission.cpp"
        self.assertTrue(path.is_file(), f"missing {path}")
        text = path.read_text(encoding="utf-8", errors="replace")
        self.assertIn("0x10", text)
        self.assertIn("0x540", text)

    def test_flush_or_fun_exact_exists(self):
        a = CLEAN_DIR / "Client_MissionDialog_FlushPreparedResponse.cpp"
        b = CLEAN_DIR / "FUN_008ab8f0.cpp"
        self.assertTrue(
            a.is_file() or b.is_file(),
            "need Client_MissionDialog_FlushPreparedResponse.cpp or FUN_008ab8f0.cpp",
        )
        # Prefer named flush when present: document 0x20 send size.
        if a.is_file():
            text = a.read_text(encoding="utf-8", errors="replace")
            self.assertTrue("0x20" in text or "0x650" in text)

    def test_flush_function_record_exists(self):
        matches = list(FUNCTIONS_DIR.glob("aa_008ab8f0_*.md"))
        self.assertTrue(matches, "functions/aa_008ab8f0_* missing")

    def test_raw_handle_button_exists(self):
        self.assertTrue(
            (RAW_DIR / "aa_008ae7c0_Client_MissionDialogHandleButton.md").is_file()
        )

    def test_ui_modal_abandon_exact_optional(self):
        """Soft: abandon-confirm extract may be present from seal work."""
        path = CLEAN_DIR / "Client_UiModalDispatch_AbandonConfirm.cpp"
        if not path.is_file():
            self.skipTest("Client_UiModalDispatch_AbandonConfirm.cpp not yet present")
        text = path.read_text(encoding="utf-8", errors="replace")
        self.assertIn("0x20b2", text.lower())
        self.assertIn("0x4e46", text.lower())

    def test_flush_dual_reviews_soft(self):
        """Soft-assert A_/B_ reviews for aa_008ab8f0 when parent has written them."""
        a_hits = list(REVIEWS_DIR.glob("A_aa_008ab8f0_*.md"))
        b_hits = list(REVIEWS_DIR.glob("B_aa_008ab8f0_*.md"))
        if not a_hits and not b_hits:
            self.skipTest("dual reviews for aa_008ab8f0 not written yet")
        self.assertTrue(a_hits, "missing A_aa_008ab8f0_*")
        self.assertTrue(b_hits, "missing B_aa_008ab8f0_*")
        a_text = a_hits[0].read_text(encoding="utf-8", errors="replace")
        b_text = b_hits[0].read_text(encoding="utf-8", errors="replace")
        for text in (a_text, b_text):
            self.assertIn("0x440", text)
            self.assertIn("0x20", text)
            self.assertIn("0x650", text)
            self.assertIn("007fca10", text.lower().replace("_", ""))

    def test_flush_plate_documents_invoker(self):
        path = CLEAN_DIR / "Client_MissionDialog_FlushPreparedResponse.cpp"
        if not path.is_file():
            self.skipTest("named flush plate missing")
        text = path.read_text(encoding="utf-8", errors="replace")
        self.assertIn("0x440", text)
        self.assertIn("0x1058", text)
        self.assertIn("0x20", text)
        self.assertIn("0x650", text)


if __name__ == "__main__":
    unittest.main()
