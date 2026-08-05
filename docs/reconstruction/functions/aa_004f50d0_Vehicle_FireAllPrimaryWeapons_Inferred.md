# Function record: Vehicle_FireAllPrimaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f50d0` |
| **Canonical name** | `Vehicle_FireAllPrimaryWeapons_Inferred` |
| **Ghidra name** | `FUN_004f50d0` |
| **Address** | `0x004f50d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle weapons |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-07-29; CF High; product name `_Inferred` |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Prior scaffold: `FUN_004f50d0`
- Parent clean sketch: `Vehicle_FireAllPrimaryWeapons` (inside `Input_TryFirePrimaryWeapons_Inferred`)
- Chain alias (auto): `Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot_004f50d0`

## Purpose

Vehicle **thiscall** that walks the **3 hardpoint weapon pointers** at `vehicle+0x260` (byte offsets `0,4,8`). For each non-null weapon whose **vtbl+0x38** predicate is true (primary group), calls **`FUN_0056d520(weapon)`** (start-fire / set firing flag / enqueue weapon HB). OR-accumulates per-weapon start success bytes and returns the aggregate.

**Does not** heat-check (caller `FUN_004f5290` / `Input_TryFirePrimaryWeapons_Inferred` does). **Does not** walk turret `+0x264`. **Does not** cast hardpoint skills.

## Signature (sealed static)

```c
// ECX = vehicle*; returns AL = OR of FUN_0056d520 results (0 if none started)
byte __fastcall Vehicle_FireAllPrimaryWeapons_Inferred(void* pVehicle /*ECX*/);
```

Asm prolog confirms `mov ebp, ecx` then loop; epilog `mov al, bl; ret`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f50d0_FUN_004f50d0.md`
- Annotated: `docs/reconstruction/raw/aa_004f50d0_FUN_004f50d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_FireAllPrimaryWeapons_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md`
- Scaffold residue: `docs/reconstruction/reconstructed-exact/FUN_004f50d0.cpp` (superseded by clean above)

## Callers / callees

| Role | VA | Name / note |
|---|---|---|
| **Caller (sole static)** | `0x00922270` | `Input_TryFirePrimaryWeapons_Inferred` — site `0x0092236c`, after heat probe `FUN_004f5290` |
| **Callee** | `0x0056d520` | Weapon start-fire HB path (`FUN_0056d520`); thiscall on **weapon**, not vehicle |
| **Virtual** | weapon vtbl **+0x38** | Primary-group predicate (bool); twin secondary uses **+0x3C** |

## Sibling map

| VA | Role | Group vtbl | Action |
|---|---|---|---|
| `0x004f50d0` | **this** fire-all primary | +0x38 | `FUN_0056d520` each |
| `0x004f5110` | fire-all secondary | +0x3C | `FUN_0056d520` each |
| `0x004f5290` | can-fire probe primary | +0x38 | `Weapon_CanFireHeatCheck`, **∃** return 1 |
| `0x004f52e0` | can-fire probe secondary | +0x3C | heat, **∀** must OK |

## Confidence

| Claim | Level |
|---|---|
| Control flow (3-slot walk, null skip, vtbl+0x38, OR return) | **High** |
| ECX = vehicle this | **High** (asm + parent ECX from `char+0x250`) |
| `+0x260` = hardpoint weapon table base (ptr to 3× weapon*) | **High** (combat family + `Vehicle_IsAnyWeaponFiring` / equip map) |
| vtbl+0x38 = primary group select (product English) | **Probable** (dual with +0x3C secondary; no RTTI/string) |
| `FUN_0056d520` starts weapon fire (sets `weapon+0xC7`, HB) | **High** CF / body of callee |
| Product symbol without `_Inferred` | **Tentative** (no string) |
| Heat already validated by caller | **High** (parent dual; this body has no heat call) |

## Sealed facts (static)

1. Loop bound **3** hardpoints (`i += 4`, `i < 0xC`).
2. Predicate gate **before** start-fire; non-primary weapons skipped entirely.
3. Return is **OR** of start successes — partial start still returns non-zero if any slot started.
4. Only static xref is primary input fire path (not secondary, not AI fire pack).
