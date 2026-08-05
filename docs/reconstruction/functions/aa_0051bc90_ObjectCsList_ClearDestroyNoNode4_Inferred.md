# Function record: ObjectCsList_ClearDestroyNoNode4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bc90` |
| **Canonical name** | `ObjectCsList_ClearDestroyNoNode4_Inferred` |
| **Ghidra** | `FUN_0051bc90` |
| **Address** | `0x0051bc90`–`0x0051bd8b` exclusive (**251 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / CS-owned list teardown |
| **Completion status** | **Dual sealed** W31-S 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

List-method clear used by CS-list complete/scalar dtors: under CS, throw if traversal flag, drain head@`+0x1C` via next@`+8` and scalar-delete, zero head/counts, LeaveCS. Twin of W30-F `ObjectCsList_ClearDestroy_Inferred` without `node+4=0`.

## Signature

```c
void __fastcall ObjectCsList_ClearDestroyNoNode4_Inferred(void *list /*ECX*/);
```

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_0051bc90_FUN_0051bc90.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectCsList_ClearDestroyNoNode4_Inferred.cpp`
- Dual A/B under `docs/reconstruction/reviews/`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Name English | **Inferred** (structural twin of W30-F) |
