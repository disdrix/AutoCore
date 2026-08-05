# Function record: Palantir_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004447e0` |
| **Canonical name** | `Palantir_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004447e0` |
| **Address** | `0x004447e0`–`0x004447FE` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir host scalar deleting destructor |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W35-J 2026-07-29) — fully sealed for port |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `Palantir_ScalarDeletingDtor` (**Inferred** structural + vtbl[0] of dtor-phase Palantir vtbl)
- Ghidra: `FUN_004447e0`
- Vtbl: `PTR_FUN_00a9f76c[0]`
- Complete body: `Palantir_CompleteDtor` (`aa_00754320`, W34-K)

## Purpose

Scalar deleting destructor: run `Palantir_CompleteDtor(this)`, free `this` when `flags&1`, return `this`. Does **not** implement member teardown itself.

## Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this
void* __thiscall Palantir_ScalarDeletingDtor(Palantir* self, unsigned char flags);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004447e0_FUN_004447e0.md` (+ W35-J append)
- Annotated: `docs/reconstruction/raw/aa_004447e0_FUN_004447e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Palantir_ScalarDeletingDtor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004447e0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_004447e0_FUN_004447e0.md`
- Review A/B: `reviews/A_aa_004447e0_Palantir_ScalarDeletingDtor.md`, `reviews/B_aa_004447e0_Palantir_ScalarDeletingDtor.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `PTR_FUN_00a9f76c[0]` | `Palantir_CompleteDtor`, `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| ABI / flags&1 free / return this | **High** |
| Product class Palantir | **High** |
