# Function record: Input_TryFirePrimaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00922270` |
| **Canonical name** | `Input_TryFirePrimaryWeapons_Inferred` |
| **Ghidra name** | `FUN_00922270` (unrenamed) |
| **Address** | `0x00922270` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / skills-abilities (client input fire) |
| **Completion status** | **Human-refined + dual A/B (2026-07-29)** — CF sealed; product symbol `_Inferred` |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Prior scaffold: `FUN_00922270` / `Named_CalleeOf_Client_QuickBar_ActivateSlot_00922270`
- Dual residual label from `Client_QuickBar_ActivateSlot`: primary / hardpoint fire

## Purpose

Client primary fire entry: walk hardpoint skill vector at `char+0x550` (stride 0xC) and cast first ready category-1 skill; else gate (player, `+0xB8&0xD2`, sector net, vehicle `+0x250`) → tip `0x12` → primary heat probe `FUN_004f5290` → primary fire `FUN_004f50d0` → optional chrome `FUN_0089ff80`. Sibling of `Input_TryFireSecondaryWeapons` (`0x0091A550`).

## Signature (decompiler-derived)

```c
// No formals; uses DAT_00d1b6d8 local player and vehicle at +0x250 as thiscall for heat/fire.
void Input_TryFirePrimaryWeapons_Inferred(void);
```

## Dual seals (2026-07-29)

| Topic | Result |
|---|---|
| Skill list stride / fields | **High** — `+0x550/+0x554`, entry ptr@0 enable@8, skill flags `+0x615`/`+0x628`, id `+0x5FC`, CD obj `+0x5E8` cat **1** |
| Skill-before-gun; skill skips guns | **High** |
| Gates ≡ secondary | **High** |
| Primary heat ∃ vs secondary heat ∀ | **High** CF (`vtbl+0x38` vs `+0x3C`) |
| Tip 0x12 before heat; no heat log | **High** |
| Product name without string | **Probable** → keep `_Inferred` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00922270_FUN_00922270.md`
- Annotated: `docs/reconstruction/raw/aa_00922270_FUN_00922270.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Input_TryFirePrimaryWeapons_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md`
- Scaffold clean (superseded name): `reconstructed-exact/FUN_00922270.cpp`

## Callers / callees

| Direction | Symbol / addr | Role |
|---|---|---|
| Caller | `Client_QuickBar_ActivateSlot` `0x009436C0` | Slot0 off-foot |
| Caller | `Client_Input_DriveControlTick` `0x009223B0` | Held primary fire |
| Callee | `Skill_GetCategoryCooldownRemaining` | Cat 1 remaining |
| Callee | `Client_CastSkillFromQuickBarSlot` `0x009418E0` | Hardpoint skill |
| Callee | `Client_MaybeShowFirstTimeTip` | Tip **0x12** |
| Callee | `FUN_004f5290` | Primary can-fire (vehicle) |
| Callee | `FUN_004f50d0` | Primary fire (vehicle) |
| Callee | `FUN_0089ff80` | Chrome residual |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm | **High** |
| Sibling primary/secondary split | **High** CF / **Probable** product words |
| Parameter semantic names | N/A (void) |
| Runtime | Open |
