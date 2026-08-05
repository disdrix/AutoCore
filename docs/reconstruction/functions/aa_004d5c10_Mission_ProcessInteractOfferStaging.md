# Function record: Mission_ProcessInteractOfferStaging

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d5c10` |
| **Canonical name** | `Mission_ProcessInteractOfferStaging` (inferred) |
| **Ghidra name** | `FUN_004d5c10` |
| **Address** | `0x004d5c10` |
| **Body** | `0x004d5c10`–~`0x004d64c3` (`ret 0xC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual A/B sealed** (W16-O, 2026-07-29) — CF High; product English / type ids open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004d5c10`
- `Mission_Uses_CVOGCharacter_CheckMissionRequirements` (legacy keyword alias)

## Purpose

Process a **mission interact** against an object/NPC:

1. Resolve interact target from `param_1[1]` COID and character from `param_1` TFID (`vtbl+0x210`).
2. Clear character mission staging map (`FUN_0052d8b0(0, -1)`).
3. **Type `0x3a` path:** stage matching active missions (turn-in ready flags), build offerable mission list from object vectors / region tables, stamp staging payloads, fill **rolled** rewards (`FUN_004d08c0`).
4. **Else:** type-0 reward table path (`FUN_004cf100`) when `char[0x152]` hash hits.

Sibling **eval-only** unit: `CVOGObject_EvalOfferableMissionInteractState` (`0x004d5aa0`) returns UI state 6/7 — this unit **mutates staging + rewards**.

## Signature (image-sealed)

```c
// ret 0xC  (3 stack formals)
void __stdcall Mission_ProcessInteractOfferStaging(
    TFID_16 *pTfidBlock,   // param_1
    int *pOutIdentity,     // param_2 — out resolved identity
    uint32_t rollOrCtx);   // param_3 — to FillRolledRewardSlots
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d5c10_FUN_004d5c10.md`
- Annotated: `docs/reconstruction/raw/aa_004d5c10_FUN_004d5c10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004d5c10.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004d5c10_Mission_ProcessInteractOfferStaging.md`
- Review B: `docs/reconstruction/reviews/B_aa_004d5c10_Mission_ProcessInteractOfferStaging.md`
- Prior scaffold: `functions/aa_004d5c10_FUN_004d5c10.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller (sole) | code @ `0x009245e6` | `push p3; push &out; push tfid+` |
| Callee | `FUN_0052d8b0` | Clear staging full tree |
| Callee | `FUN_0052c700` / `FUN_0052dac0` / `FUN_0052b420` | Stage + turn-in ready |
| Callee | `FUN_004d08c0` | Rolled reward fill |
| Callee | `FUN_004cf100` | Type-0 reward fill |
| Callee | `CheckMissionRequirements` / `HasCompletedMission` | Offer gates |
| Callee | `ResolveObjectTarget` / `Object_ResolveFromTFID` / `CNDHash_LookupByKey` | Resolve / maps |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw | **High** |
| `ret 0xC` / 3 stack args | **Confirmed** |
| Type gate `0x3a` + reward dual path | **High** (numeric) / English **Open** |
| Staging field patches `+0x20/+0x24/+0x2c/+0x28` | **High** |
| Parameter product names | **Probable / Tentative** |
| `unaff_EDI` semantics | **Open** residual |
