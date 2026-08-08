# Function record: UI_InteractionMenu_AddClanInviteOrKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fa60` |
| **Canonical name** | `UI_InteractionMenu_AddClanInviteOrKick_Inferred` |
| **Ghidra name** | `FUN_0082fa60` |
| **Address** | `0x0082fa60`–`0x0082fb2b` exclusive |
| **Body size** | **203 B** (`0xCB`); `ret` (`C3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / interaction-menu clan UI |
| **Completion status** | **Dual sealed** (MEGA-076 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `UI_InteractionMenu_AddClanInviteOrKick_Inferred`
- Ghidra: `FUN_0082fa60`
- Prior: `UI_int_btn_generic_0082fa60` (**retired** plate-only)

## Purpose

Create **Invite To Clan** (`0x11173`) or **Kick From Clan** (`0x11174`) generic interaction button for a target object after looking up local/target clan entries on `DAT_00d1da30`, and store the button on the menu host (`+0x548` invite / `+0x54C` kick).

## Signature

```c
// EAX = target object*; EBX = menu host*; ret 0 (not thiscall)
void UI_InteractionMenu_AddClanInviteOrKick_Inferred(void* targetObject, void* menuHost);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082fa60_FUN_0082fa60.md`
- Annotated: `docs/reconstruction/raw/aa_0082fa60_FUN_0082fa60.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddClanInviteOrKick_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082fa60.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082fa60_FUN_0082fa60.md`
- Report: `docs/agents/task-dual-ab-0082fa60-mega-076-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`FUN_0082fe20`) ×2 sites |
| Callees | `FUN_004c22a0` (clan-table key lookup), `FUN_0082f7d0` (create+label generic btn) |
| Sibling | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`FUN_0082fb30`) — different ABI |

## Behavioral summary

1. Gate on object `+0x6B4` (shared shape with convoy pack) and non-null `DAT_00d1da30`.
2. Resolve local and target clan entries via secondary key pair `+0x164/+0x168`.
3. If local has clan and target has none and `localClan+0x24 >= 2` → Invite button @ host `+0x548`.
4. Else if both have entries and `targetClan+0x24 < localClan+0x24` → Kick button @ host `+0x54C`.

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile | **Confirmed** |
| Invite/Kick strings + ids + slots | **Confirmed** |
| EAX target / EBX host ABI | **Confirmed** |
| Clan table this = `DAT_00d1da30` | **Confirmed** |
| Product English name | **Inferred** |
| Field English (`+0x6B4`, `+0x24`, keys) | **Open** |
