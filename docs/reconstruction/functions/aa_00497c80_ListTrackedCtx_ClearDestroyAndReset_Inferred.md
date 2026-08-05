# Function record: ListTrackedCtx_ClearDestroyAndReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497c80` |
| **Canonical name** | `ListTrackedCtx_ClearDestroyAndReset_Inferred` |
| **Ghidra name** | `FUN_00497c80` |
| **Address** | `0x00497c80`–`0x00497cf0` inclusive (**113 B** / `0x71`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir env child / list-tracked ctx (0xC8) |
| **Completion status** | **Dual A/B sealed (W33-R)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Clear-destroy-and-reset of the **0xC8** list-tracked context:

1. For each non-null bank entry (count @`+0x10`, ptrs @`+0x14`): `FUN_00497900(entry)` + `operator_delete(entry)`.
2. Zero bank 0xA0 bytes via `FUN_00788db0`.
3. Zero `+4`, `+8`, `+0xC`; reset grid @`+0xB8` via `FUN_007874b0(this+0xB8, 0, 0)`.
4. Set flag@`+0 = 1`; return 1.

Inverse of construction-side bank fill; pairs with `ListTrackedCtx_Ctor_Inferred` (`0x00497920`).

## Signature

```c
uint8_t __thiscall ListTrackedCtx_ClearDestroyAndReset_Inferred(uint8_t* self);
// ECX=self; bare ret; AL=1
```

## Classification

worker (reset / clear-destroy)

## Callers / callees

| Dir | Symbol |
|---|---|
| Callers (6) | `FUN_0048f2d0` (ApplyDefaultScalars), `FUN_00498260`, `FUN_004982d0`, `FUN_004982f0`, `FUN_004dfcc0`, `FUN_004deb20` |
| Callees | `FUN_00497900`, `operator_delete`, `FUN_00788db0`, `FUN_007874b0` |

## Related

- Ctor: `ListTrackedCtx_Ctor_Inferred` (`0x00497920`, W32-P)
- Env defaults: `PalantirEnv_ApplyDefaultScalars_Inferred` (`0x0048f2d0`, W32-Q)
- Scaled clear sibling: `Ctx_ClearListTrackedOwnedAtScaledXY` (`0x00497a30`, W31-D)

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00497c80_FUN_00497c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00497c80_FUN_00497c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_ClearDestroyAndReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497c80.cpp` |
| Function FUN_ | `docs/reconstruction/functions/aa_00497c80_FUN_00497c80.md` |
| A | `docs/reconstruction/reviews/A_aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` |

## Confidence

| Claim | Level |
|---|---|
| Thiscall ECX=self; body 113 B; return 1 | **High** |
| Loop destroys all non-null bank entries then resets | **High** (bytes correct decompiler) |
| FUN_007874b0 thiscall on +0xB8 | **High** |
| Product demangle / entry type English | **Low** |
| Runtime / bit-exact | **Open** |
