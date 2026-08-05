# Function record: `Client_InteractWorldClickHub`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925820` |
| **Canonical name** | `Client_InteractWorldClickHub` (structural) |
| **Ghidra name** | `FUN_00925820` |
| **Address** | `0x00925820` |
| **Body** | `00925820`–`00925d59` (1338 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` / client input |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W17-C)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Prior scaffold: `FUN_00925820`
- Related (not this unit): `Client_InteractClickPickTarget` `aa_009247b0`

## Purpose

Virtual world/mouse-click hub: UI mouse vtbls, optional drive Stop, selected-object consume, drop-destroy modal, ray+gather (100f/20f) leading to objective select / IfInteractable **or** ItemPickup `0x2055` with select clear.

## Signature

```c
uint32_t __thiscall Client_InteractWorldClickHub(Client *this, uint32_t param_2, uint32_t packedMouse);
// packedMouse: lo = sx (i16), hi = sy (i16); epilogue ret 8
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00925820_FUN_00925820.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00925820_FUN_00925820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractWorldClickHub.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00925820.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00925820_Client_InteractWorldClickHub.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00925820_Client_InteractWorldClickHub.md` |

## Callers / callees

**Callers:** virtual only — DATA `@ 0x00a2f420` (client vtable).

**Key callees (sealed names where available):**

| Callee | VA / note |
|--------|-----------|
| `CVOGHBBase_Stop` | `0x005081d0` |
| `VehicleEntity_SetLongitudinalInput` | `0x004f5650` |
| `CVOGCharacter_FindActiveObjectiveIdForPick` | `0x005245d0` |
| `CVOGCharacter_FindActiveObjectiveIdForInteract` | `0x00524520` |
| `Client_SendUseObject_IfInteractable` | `0x00930d70` |
| `Client_SendItemPickup` | `0x00925580` |
| `Client_ShowModalPrompt` | `0x007fdfb0` |
| `FUN_0058cd60` (gather) | `0x0058cd60` |
| `FUN_0093e120` (select) | `0x0093e120` |

## Confidence

| Claim | Level |
|---|---|
| Stage map + constants | **High / Confirmed** |
| Product English name | **Probable** structural |
| Vtbl slot English | **Open** |
| Runtime | **Open** |
