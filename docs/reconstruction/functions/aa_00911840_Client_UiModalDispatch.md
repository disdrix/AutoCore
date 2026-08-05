# Function record: Client_UiModalDispatch (abandon slice)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911840` |
| **Canonical name** | `Client_UiModalDispatch` |
| **Prior / Ghidra name** | `FUN_00911840` |
| **Address** | `0x00911840` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Slice focus** | Modal cases **`0x4e46`** (abandon Yes → C2S `0x20B2`) and **`0x4e47`** (No / dismiss close) |
| **Completion status** | **Human-refined abandon slice — residual cases sealed High (2026-07-29)**; full switch remains scaffold |
| **Dual review** | A/B `reviews/A_aa_00911840_*` / `reviews/B_aa_00911840_*` — **accept-with-gaps**; residuals sealed |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Prior scaffold: `FUN_00911840`
- String-derived alias (full function): `Mission_Attempting_to_open_null_dialog_i` (unrelated modal string elsewhere in body)
- Slice clean name: `Client_UiModalDispatch_AbandonConfirm` (**slice only** — not whole-function rename)

## Purpose

Large UI modal-result dispatcher (`switch` on modal type). **Abandon ownership** for this reconstruction unit:

1. **`0x4e46` + `param_2==8`:** if `DAT_00d1b4b4` (pending abandon mission id) valid and local character live, lookup mission def via `FUN_0053fff0` + `CNDHash_LookupByKey` (key snapshotted at entry), build **FailMission** packet opcode **`0x20B2`** size **`0x18`** (COID from char `+0x164/+0x168`, mission id from def node), `Client_SendSectorPacket`, optional mission UI refresh, then close modal.
2. **`0x4e47` + `param_2==8`:** close modal only (`FUN_007fc360`) — shared dismiss family with `0x4e45`, `0x4e4b`, `0x4e4d`, `0x4e4f`, `0x4e52`, `0x4e53`, `0x4e55`, `0x4e57`, `0x4e59`, `0x4e5b`.

Upstream: `Client_MissionDialogHandleButton` state **2** sets `DAT_00d1b4b4` and posts modal via `Client_ShowModalPrompt` with **EAX=`0x4e46` (Yes)** and stack secondary **`0x4e47` (No)** (**High** pairing — UF-009).

Downstream: S2C `0x20B2` → `Client_RecvFailMission` → `CVOGReaction_FailMission`.

**Not on Yes path:** local `CVOGReaction_FailMission` — client waits for server echo.

## Signature (decompiler-derived)

```c
undefined4 __thiscall Client_UiModalDispatch(int* thisUi, int actionCode, undefined4 modalType);
// param_2 = actionCode (8 = primary / confirm for residual cases — Probable enum)
// param_3 = modalType (case key)
```

## Residual cases — sealed facts (2026-07-29 re-verify)

| Case | Gate | Side effects | Close | Confidence |
|---|---|---|---|---|
| `0x4e46` | `param_2==8` | C2S FailMission `0x20B2` size `0x18` if stash≠−1, char live, def hit; optional `FUN_007fef20(0x13,1,0)` | Always `FUN_007fc360` | **High** |
| `0x4e47` | `param_2==8` | **None** (no packet, no mission mutate) | `FUN_007fc360` only | **High** |

Live decompile anchors:

```c
// case 0x4e46 (abbrev):
if (param_2 == 8) {
  if (DAT_00d1b4b4 != 0xffffffff && DAT_00d1b6d8 != 0) {
    puVar7 = FUN_0053fff0();
    if (*puVar7 && (piVar8 = CNDHash_LookupByKey(*puVar7, key)) != 0) {
      packet[0] = 0x20b2;
      // COID lo/hi from DAT_00d1b6d8 dual-base +0x164/+0x168
      // missionId = *piVar8
      Client_SendSectorPacket(&DAT_00d1a840, 0x18, packet);
      // optional DAT_00d1b898 refresh
    }
  }
  FUN_007fc360();
}

// case 0x4e47 (shared dismiss family):
if (param_2 == 8) {
  FUN_007fc360();
}
```

## Packet (case 0x4e46)

| Offset | Field |
|---:|---|
| `+0x00` | `0x20B2` FailMission |
| `+0x04` | pad (stack residual; not explicitly zeroed) |
| `+0x08` | CharacterCoid lo |
| `+0x0C` | CharacterCoid hi |
| `+0x10` | MissionId (`*defNode`) |
| `+0x14` | pad |
| size | `0x18` |

## Entry / xrefs

| Kind | Address | Note |
|---|---|---|
| CALL | `0x009140fe` | `PUSH EDX; PUSH ESI; CALL FUN_00911840; RET 8` |
| CALL | `0x009257e9` | `PUSH EAX; PUSH ESI; CALL FUN_00911840; RET 8` |
| DATA | `0x00a30694` | fn-ptr table slot = `0x00911840` |

`get_function_callers` empty does **not** imply dead code (unnamed containing regions).

## Behavioral summary (abandon only)

See clean extract and dual A/B. Full switch not reconstructed in the exact abandon file.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Abandon confirm case `0x4e46` CF | **High** | Raw literal `0x20b2` + send; live re-decompile |
| Cancel case `0x4e47` close-only | **High** | Shared fall-through + `FUN_007fc360` only |
| `DAT_00d1b4b4` = pending mission id | **High** | HandleButton store + lookup key snapshot |
| Yes/No residual pairing | **High** (UF-009) | EAX Yes `0x4e46` / stack No `0x4e47` → dual-id store |
| No local FailMission on Yes | **High** | Absent from case body |
| Entry liveness | **High** | CALL + DATA xrefs |
| `param_2 == 8` formal meaning | **Probable** | Pattern only |
| Full modal switch semantics | Scaffold | Out of abandon slice scope |
| Overall (abandon chain link) | **High (static)** | Runtime e2e open |

## Open questions

- ~~Full `FUN_007fdfb0` button → modal-code map for abandon~~ sealed (`aa_007fdfb0` / UF-009).
- ~~Residual case bodies `0x4e46` / `0x4e47`~~ sealed this dual.
- Named outer functions at CALL sites `009140fe` / `009257e9`.
- Formal type of `DAT_00d1b6d8` vs game+`0xe98`.
- Whether `*hashValue` always equals key.
- `FUN_007fef20(0x13, …)` refresh meaning.
- Runtime click capture.

## Related artifacts

| Kind | Path |
|---|---|
| Dual A | `reviews/A_aa_00911840_Client_UiModalDispatch_AbandonConfirm.md` |
| Dual B | `reviews/B_aa_00911840_Client_UiModalDispatch_AbandonConfirm.md` |
| Chain | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| Raw (abandon) | `raw/aa_00911840_Client_UiModalDispatch.md` |
| Annotated (abandon) | `raw/aa_00911840_Client_UiModalDispatch.annotated.md` |
| Clean extract | `reconstructed-exact/Client_UiModalDispatch_AbandonConfirm.cpp` |
| Prior full scaffold raw | `raw/aa_00911840_FUN_00911840.md` |
| Prior scaffold record | `functions/aa_00911840_FUN_00911840.md` (superseded for abandon by this file) |
| Modal open helper | `functions/aa_007fdfb0_Client_ShowModalPrompt.md` |
| Upstream | `functions/aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| S2C apply | `functions/aa_0080b100_Client_RecvFailMission.md` |
| Fail kernel | `functions/aa_0052da30_CVOGReaction_FailMission.md` |
