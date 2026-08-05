# Function record: Vehicle_CanFireAnyPrimaryHeatOK_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5290` |
| **Canonical name** | `Vehicle_CanFireAnyPrimaryHeatOK_Inferred` |
| **Ghidra residual** | `FUN_004f5290` |
| **Address** | `0x004f5290` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle weapon heat gate |
| **Completion status** | **Dual A/B complete** — accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Existential **primary heat quantifier** over the vehicle's 3-slot hardpoint weapon table (`*(vehicle+0x260)`). A slot counts if non-null, weapon vtbl **+0x38** returns true, and `Weapon_CanFireHeatCheck` passes. First success → true; none → false.

## Signature (sealed)

```c
bool __fastcall Vehicle_CanFireAnyPrimaryHeatOK_Inferred(void* pVehicle /* ECX */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f5290_FUN_004f5290.md`
- Annotated: `docs/reconstruction/raw/aa_004f5290_FUN_004f5290.annotated.md`
- Clean (product): `docs/reconstruction/reconstructed-exact/Vehicle_CanFireAnyPrimaryHeatOK_Inferred.cpp`
- Clean (FUN residual): `docs/reconstruction/reconstructed-exact/FUN_004f5290.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md`

## Callers / callees

| Direction | Symbol / VA | Role |
|---|---|---|
| Caller | `Input_TryFirePrimaryWeapons_Inferred` `0x00922270` @ `0x00922361` | sole xref |
| Callee | `Weapon_CanFireHeatCheck` `0x0056aca0` | heat &lt; max |
| Callee | weapon vtbl `+0x38` | primary-group filter |
| Sibling | `FUN_004f52e0` | secondary ∀ heat quantifier |
| Fire twin | `FUN_004f50d0` | primary fire walker |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ∃ quantifier | **High** |
| `*(v+0x260)` 3-slot walk | **High** |
| vtbl+0x38 group filter | **High** CF / **Probable** product word “Primary” |
| Product name (no retail string) | **Probable** (`_Inferred`) |
| Types (weapon*/vehicle*) | **Probable** |

## Dual verdict

**accept-with-gaps** — CF sealed; residual is vtbl method product names + optional Ghidra rename + live empty/partial-overheat checks.
