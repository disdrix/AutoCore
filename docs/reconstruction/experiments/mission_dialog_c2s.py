"""
Evidence-backed pure models for client mission dialog C2S paths.

Derived from Ghidra decompiles (autoassault.exe) / reconstructed-exact:

  - Client_NpcDialog_PrepareResponseOpcode @ 0x008abd70
      dialog+0x650 = 0x206E; store mission_def ptr (+0x670)
  - Client_MissionDialogHandleButton        @ 0x008ae7c0
      State1: missionId +0x654, accepted +0x658, npc TFID +0x660
      State2: pending abandon DAT_00d1b4b4; modal code 0x4e47
  - Client_MissionDialog_FlushPreparedResponse / FUN_008ab8f0 @ 0x008ab8f0
      if opcode at +0x650 != 0: sector send size 0x20 from +0x650
  - Client_UiModalDispatch case 0x4e46      @ 0x00911840
      if pending != 0xFFFFFFFF → C2S FailMission 0x20B2 size 0x18
  - CVOGReaction_FailMission                @ 0x0052da30
      active hash hit → dirty |= 0x10 + notify; return 1 else 0

Not a full UI reimplementation — only sealed arithmetic / wire fields.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any

# Evidence-backed constants (retail literals / verified plates only)
OPCODE_MISSION_DIALOG_RESPONSE = 0x206E
OPCODE_FAIL_MISSION = 0x20B2
OPCODE_ACCEPT_REQUEST = 0x206F  # state-0 sibling path (not 0x206E)

RESPONSE_SIZE = 0x20
FAIL_PACKET_SIZE = 0x18
ACCEPT_PACKET_SIZE = 0x18

MODAL_ABANDON_PROMPT = 0x4E47
MODAL_ABANDON_CONFIRM = 0x4E46

DIRTY_BIT = 0x10
PENDING_ABANDON_NONE = 0xFFFFFFFF

# FlushPreparedResponse object / invoker (UF-010 static seal)
DIALOG_OPCODE_OFFSET = 0x650
DIALOG_OPCODE_DWORD_INDEX = 0x194  # 0x194 * 4 == 0x650
FLUSH_VTABLE_BASE = 0x00A4A51C
FLUSH_VTABLE_METHOD_OFFSET = 0x440  # base+0x440 == DATA 0x00a4a95c
FLUSH_VTABLE_SLOT_ADDR = 0x00A4A95C
FLUSH_FUNCTION_VA = 0x008AB8F0
CLIENT_NPC_DIALOG_FIELD = 0x1058  # not +0x107c (HideMissionDialogIfOpen)
DIALOG_TABLE_BASE = 0x1030
DIALOG_TABLE_INDEX = 10  # (0x1058 - 0x1030) / 4
CLOSE_INVOKER_VA = 0x007FCA10  # FUN_007fca10 → vtbl+0x440 when visible
EVENT_DISPATCH_VA = 0x008AEC40  # FUN_008aec40
CLOSE_BUTTON_ID = 0x9C40  # case 40000 → close without HandleButton fill
RESPONSE_BUTTON_ID_BASE = 0x9C46  # + index → HandleButton

# Back-compat aliases used by early notes
RESPONSE_PACKET_SIZE = RESPONSE_SIZE
CHAR_DIRTY_MISSION_BIT = DIRTY_BIT


@dataclass
class DialogContext:
    """Subset of mission dialog UI object fields used by sealed paths."""

    opcode_at_650: int = 0  # dialog+0x650 prepared opcode
    mission_id_at_654: int = 0  # dialog+0x654 mission id
    accepted_at_658: int = 0  # dialog+0x658 accepted / reward lo
    accepted_hi_at_65c: int = 0  # dialog+0x65c
    npc_tfid: tuple[int, int, int, int] = (0xFFFFFFFF, 0xFFFFFFFF, 0, 0)  # +0x660
    state_648: int = 0
    turn_in_64c: int = 0
    mission_def_id: int = 0  # *(*(dialog+0x670)) mission id from def ptr
    mission_def_ptr: int = 0  # dialog+0x670 stored mission_def pointer (opaque)


@dataclass
class SectorPacket:
    opcode: int
    size: int
    payload: dict[str, Any] = field(default_factory=dict)


def prepare_response_opcode(
    dialog: DialogContext, mission_def_id: int, mission_def_ptr: int = 0
) -> DialogContext:
    """
    PrepareResponseOpcode (aa_008abd70):
      dialog+0x670 = mission_def ptr
      dialog+0x650 = 0x206E
    """
    dialog.mission_def_id = mission_def_id
    dialog.mission_def_ptr = mission_def_ptr
    dialog.opcode_at_650 = OPCODE_MISSION_DIALOG_RESPONSE
    return dialog


def handle_button_state0_accept_request(
    dialog: DialogContext, button_index: int, field_678: int, field_67c: int
) -> SectorPacket:
    """aa_008ae7c0 state 0: immediate C2S 0x206F size 0x18 (not 0x206E)."""
    return SectorPacket(
        opcode=OPCODE_ACCEPT_REQUEST,
        size=ACCEPT_PACKET_SIZE,
        payload={
            "field_678": field_678,
            "field_67c": field_67c,
            "button": button_index & 0xFF,
        },
    )


def handle_button_state1_fill_payload(
    dialog: DialogContext,
    button_index: int,
    npc_tfid: tuple[int, int, int, int] | None = None,
) -> DialogContext:
    """
    HandleButton_State1_FillPayload (aa_008ae7c0 state 1):
      missionId at +0x654, accepted at +0x658, npc TFID at +0x660.
    Does not send; FlushPreparedResponse does.
    """
    dialog.mission_id_at_654 = dialog.mission_def_id
    dialog.accepted_at_658 = button_index
    dialog.accepted_hi_at_65c = (button_index >> 31) & 0xFFFFFFFF
    if npc_tfid is not None:
        dialog.npc_tfid = npc_tfid
    return dialog


def flush_prepared_response(dialog: DialogContext) -> SectorPacket | None:
    """
    FlushPreparedResponse (aa_008ab8f0):
      if opcode_650 != 0, emit sector packet
        {opcode: fields[0x650], size: 0x20, body from 0x650 for 0x20 bytes}.
    Invoked as dialog.vtbl+0x440 via FUN_007fca10 (does not clear +0x650).
    """
    if dialog.opcode_at_650 == 0:
        return None
    return SectorPacket(
        opcode=dialog.opcode_at_650,
        size=RESPONSE_SIZE,
        payload={
            "mission_id": dialog.mission_id_at_654,
            "accepted": dialog.accepted_at_658 & 0xFF,
            "accepted_hi": dialog.accepted_hi_at_65c,
            "npc_tfid": dialog.npc_tfid,
        },
    )


def close_visible_dialog_invokes_flush(dialog: DialogContext, visible: bool) -> SectorPacket | None:
    """
    FUN_007fca10 slice: if visible (vtbl+0x3d8), call vtbl+0x440 (= Flush).
    Models invoker gate only — not full detach/teardown.
    """
    if not visible:
        return None
    return flush_prepared_response(dialog)


def event_dispatch_after_handle_button(
    dialog: DialogContext, handle_button_success: bool, *, close_button: bool = False
) -> SectorPacket | None:
    """
    FUN_008aec40 success / close path → FUN_007fca10 → Flush.
    close_button: id 0x9c40 closes without requiring HandleButton success.
    """
    if close_button or handle_button_success:
        return close_visible_dialog_invokes_flush(dialog, visible=True)
    return None


def vtable_slot_address(base: int = FLUSH_VTABLE_BASE, offset: int = FLUSH_VTABLE_METHOD_OFFSET) -> int:
    """DATA address of Flush function pointer: base + 0x440 == 0x00a4a95c."""
    return (base + offset) & 0xFFFFFFFF


def handle_button_state2_abandon_prompt(
    mission_def_id: int | None,
) -> tuple[int, int]:
    """
    HandleButton_State2_AbandonPrompt (aa_008ae7c0 state 2 + button 1):
      stash pending_abandon_mission_id (DAT_00d1b4b4); return modal code 0x4e47.
    Returns (pending_abandon_mission_id, modal_code).
    """
    if mission_def_id is None:
        return PENDING_ABANDON_NONE, MODAL_ABANDON_PROMPT
    return mission_def_id & 0xFFFFFFFF, MODAL_ABANDON_PROMPT


def ui_modal_abandon_confirm(
    pending_mission_id: int,
    character_coid: tuple[int, int],
    mission_present: bool = True,
) -> SectorPacket | None:
    """
    UiModal_AbandonConfirm (0x4e46) from FUN_00911840:
      if pending != 0xFFFFFFFF (and character/mission hash live), emit C2S
      0x20B2 size 0x18 with mission id + character coid.
    """
    if pending_mission_id == PENDING_ABANDON_NONE:
        return None
    if not mission_present:
        return None
    return SectorPacket(
        opcode=OPCODE_FAIL_MISSION,
        size=FAIL_PACKET_SIZE,
        payload={
            "character_coid_lo": character_coid[0],
            "character_coid_hi": character_coid[1],
            "mission_id": pending_mission_id,
        },
    )


def fail_mission(
    active_mission_ids: set[int], mission_id: int, dirty_flags: int
) -> tuple[int, int]:
    """
    FailMission (aa_0052da30):
      active hash lookup; on hit set dirty |= 0x10, notify; return 1 else 0.
    Returns (result_0_or_1, new_dirty_flags).
    """
    if mission_id not in active_mission_ids:
        return 0, dirty_flags
    return 1, dirty_flags | DIRTY_BIT
