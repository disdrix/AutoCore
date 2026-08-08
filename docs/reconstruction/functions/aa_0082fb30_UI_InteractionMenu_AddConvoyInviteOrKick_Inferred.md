# Function record: UI_InteractionMenu_AddConvoyInviteOrKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fb30` |
| **Canonical name** | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` |
| **Ghidra name** | `FUN_0082fb30` |
| **Address** | `0x0082fb30`–`0x0082fc31` exclusive |
| **Body size** | **257 B** (`0x101`); `ret` (`C3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction menu / convoy UI |
| **Completion status** | **Dual sealed** (WQ9D-I 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred`
- Prior: `UI_int_btn_generic_0082fb30` / `FUN_0082fb30`

## Purpose

Create Invite To Convoy (`0x11171`) or Kick From Convoy (`0x11172`) generic interaction button for a target, store on menu host (`+0x540` / `+0x544`), disable when local player is not convoy leader.

## Signature

```c
// ESI = menu host; EDX = target; ret 0
void UI_InteractionMenu_AddConvoyInviteOrKick_Inferred(void* menuHost, void* targetObject);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082fb30_FUN_0082fb30.md`
- Annotated: `docs/reconstruction/raw/aa_0082fb30_FUN_0082fb30.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082fb30.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082fb30_FUN_0082fb30.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_0082fe20` ×2 (`0x0082fec7`, `0x0082ff1b`) |
| Callees | `VehicleCrew_ContainsMember_Inferred` (`FUN_005749d0`), `FUN_00574880` |
| Indirect | host `vtbl+0x444`, btn `vtbl+0x1D8`, btn `vtbl+0xD4` |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile | **Confirmed** |
| Invite/Kick strings + ids | **Confirmed** |
| Crew branch via +0xCB0 | **Confirmed** |
| Product English name | **Inferred** |
