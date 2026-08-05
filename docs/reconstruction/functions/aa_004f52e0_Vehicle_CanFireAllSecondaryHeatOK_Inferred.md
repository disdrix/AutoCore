# Function record: Vehicle_CanFireAllSecondaryHeatOK_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f52e0` |
| **Canonical name** | `Vehicle_CanFireAllSecondaryHeatOK_Inferred` |
| **Address** | `0x004f52e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle weapon heat |
| **Ghidra symbol** | `FUN_004f52e0` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Secondary heat **∀** quantifier: for each secondary-group hardpoint (vtbl +0x3C), require `Weapon_CanFireHeatCheck`; first fail → 0; empty secondary set → 1. Differs from primary **∃** at `0x004f5290`.

## Signature

```c
bool __thiscall Vehicle_CanFireAllSecondaryHeatOK_Inferred(Vehicle* vehicle /* ECX */);
```

## Artifacts

- Raw / annotated / clean: `raw/aa_004f52e0_*`, `reconstructed-exact/FUN_004f52e0.cpp`
- Dual A/B: `reviews/A_aa_004f52e0_Vehicle_CanFireAllSecondaryHeatOK_Inferred.md`, `B_aa_004f52e0_*`
- Legacy scaffold: `functions/aa_004f52e0_FUN_004f52e0.md`

## Callers / callees

| Direction | Target | Role |
|---|---|---|
| Caller | `Input_TryFireSecondaryWeapons` `0x0091a550` | Sole static |
| Callee | vtbl +0x3C | Secondary group |
| Callee | `Weapon_CanFireHeatCheck` `0x0056aca0` | Heat |

## Confidence

| Claim | Level |
|---|---|
| ∀ vs primary ∃ | High |
| Product English | Probable |
