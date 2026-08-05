# Function record: Vehicle_FireAllSecondaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5110` |
| **Canonical name** | `Vehicle_FireAllSecondaryWeapons_Inferred` |
| **Address** | `0x004f5110` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle weapons |
| **Ghidra symbol** | `FUN_004f5110` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Secondary-group fire-all: walk 3 hardpoints at `*(vehicle+0x260)`; for each non-null weapon with vtbl **+0x3C** true, OR-accumulate `FUN_0056d520(weapon)`. Twin of primary `0x004f50d0` (vtbl +0x38).

## Signature

```c
byte __thiscall Vehicle_FireAllSecondaryWeapons_Inferred(Vehicle* vehicle /* ECX */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f5110_FUN_004f5110.md`
- Annotated: `docs/reconstruction/raw/aa_004f5110_FUN_004f5110.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004f5110.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md`
- Legacy scaffold record: `functions/aa_004f5110_FUN_004f5110.md`

## Callers / callees

| Direction | Target | Role |
|---|---|---|
| Caller | `Input_TryFireSecondaryWeapons` `0x0091a550` | Sole static |
| Callee | weapon vtbl +0x3C | Secondary group |
| Callee | `FUN_0056d520` | Start fire |

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| Product English “Secondary” | Probable |
| Types | Probable |
