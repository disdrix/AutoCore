# Function record: Obj_PopulateListAt10_ScaledGridFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3fa0` |
| **Canonical name** | `Obj_PopulateListAt10_ScaledGridFill_Inferred` (Inferred) |
| **Ghidra name** | `FUN_005b3fa0` |
| **Address** | `0x005b3fa0` |
| **Body range** | `0x005b3fa0`–`0x005b4255` exclusive (**693** B / `0x2B5`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host object / list populate worker |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | A/B reviews under `reviews/` (2026-08-04 W37-L) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_005b3fa0`
- Related: empty ctor `Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20` (`0x005b3f60`); convenience ctor `Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate` (`0x005b4260`)

## Purpose

Populate the host's embedded list (`this+0x10`) with a scaled rectangular grid of 0x30 payload nodes after empty construction. Requires a non-null context object for path/lock. Stores three dimension floats (middle stack args swapped into `+0x20/+0x24/+0x28`) and zeros `+0x2c`. Returns status **1** / **0**.

## Signature

```c
uint32_t __thiscall Obj_PopulateListAt10_ScaledGridFill_Inferred(
    void *self,
    float dim_a,   // → +0x20
    float dim_b,   // → +0x28
    float dim_c,   // → +0x24
    float scale,
    void *ctx);    // null → return 0
// ret 0x14
```

## Algorithm

1. If `ctx == 0` → return 0.
2. Store floats (arg0→+0x20, arg2→+0x24, arg1→+0x28, +0x2c=0).
3. `FUN_004f1e20(1,1)` on ctx; stack-construct body; build path; lock asset.
4. On lock fail → teardown; return 0.
5. Compute extents; half-steps via **0.5f**; nested `ROUND(dim*scale)` loops inserting nodes via `FUN_005b4470` + `FUN_005b43d0(1)`.
6. Teardown; return 1.

## Artifacts

- Raw / annotated / clean / scaffold / A/B / report as listed in scaffold record.

## Related

- W30-O default ctor + convenience ctor.
- Node buy `FUN_005b4470`; list size `FUN_005b43d0` (`list<T> too long`).
- Live host store at `+0xe4fc` via `FUN_004cd8f0`.
