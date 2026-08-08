# Function record: FreelistSlabVector_Teardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416e80` |
| **Canonical name** | `FreelistSlabVector_Teardown_Inferred` |
| **Ghidra name** | `FUN_00416e80` |
| **Address** | `0x00416e80` |
| **Body range** | `0x00416e80` – `0x00416ef6` (**119 B** / `0x77`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash freelist slab pointer vector |
| **Calling convention** | **stdcall** stack freelist subobject*; **`ret 4`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-A 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` |
| **Dual B** | `reviews/B_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` |
| **Last reviewed** | `2026-08-05` (WQ9I-A) |

## Alias

- Ghidra: `FUN_00416e80`
- Scaffold record: `functions/aa_00416e80_FUN_00416e80.md`
- Twin thiscall: `FreelistSlabVector_dtor` @ `0x0059c8a0`
- Reject: hash dtor merge; freelist-head walk; VOG_DEBUG_STOP naming

## Purpose

MSVC-style freelist **slab pointer-vector dtor** for CNDHash-family objects: free each `_aligned_free` slab in the void* array, delete the array buffer, clear begin/end/capacity triad at freelist+0x08/+0x0c/+0x10. Invoked with freelist base = hash+0x20.

## Signature

```c
void FreelistSlabVector_Teardown_Inferred(FreelistSlabVector_Inferred *fl /*stack*/);
// stdcall ret 4
```

## Behavioral summary

1. SEH install (`LAB_009bc71b`)
2. While it ≠ end: `_aligned_free(*it)`; it++
3. If begin ≠ null: `operator_delete(begin)` (returns)
4. begin = end = capacity_end = null
5. SEH restore; `ret 4`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `_aligned_free`; `operator_delete` |
| **Callers** | `CNDHash_Dtor_00a2c2b0` (`00406420`, WQ9H-D); sibling hash dtors; wrapper `00416c30` |
| **Twin** | `0059c8a0` thiscall FreelistSlabVector_dtor (W24-M) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416e80_FUN_00416e80.md` (+ WQ9I-A append)
- Annotated: `docs/reconstruction/raw/aa_00416e80_FUN_00416e80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FreelistSlabVector_Teardown_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00416e80.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 4 | **Confirmed** |
| Stack freelist* (not thiscall) | **Confirmed** |
| aligned_free + always zero triad | **Confirmed** |
| Role under CNDHash dtor +0x20 | **Confirmed** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
