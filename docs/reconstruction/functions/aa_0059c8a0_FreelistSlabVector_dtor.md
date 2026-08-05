# Function record: FreelistSlabVector_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059c8a0` |
| **Canonical name** | `FreelistSlabVector_dtor` (Ghidra `FUN_0059c8a0`; **Inferred**) |
| **Address** | `0x0059c8a0` |
| **Body** | `0x0059c8a0`–`0x0059c8e1` (**`ret`**, 66 B / `0x42`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash freelist slab vector |
| **Completion status** | **Dual sealed 2026-07-29 W24-M** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

**Freelist slab pointer-vector destructor** (ECX = freelist subobject, typically `CNDHash+0x20`):

1. For each pointer in `[begin(+0x08), end(+0x0c))`: `_aligned_free(*it)` (IAT `0x009c6578`).
2. If `begin != null`: `operator_delete(begin)` — **returns** (decompiler noreturn is false).
3. Always null `begin`, `end`, `capacity_end` (`+0x08/+0x0c/+0x10`).
4. Does **not** touch freelist head at subobject `+0x00`.

Shared by essentially every CNDHash dtor after FreeBuckets reclaims nodes into the freelist.

## Signature (sealed)

```c
// void __thiscall / __fastcall — bare ret
void FreelistSlabVector_dtor(void *thisVec);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0059c8a0_FUN_0059c8a0.md`
- Annotated: `docs/reconstruction/raw/aa_0059c8a0_FUN_0059c8a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FreelistSlabVector_dtor.cpp`
- Clean (FUN alias): `docs/reconstruction/reconstructed-exact/FUN_0059c8a0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0059c8a0_FreelistSlabVector_dtor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0059c8a0_FreelistSlabVector_dtor.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callers | **38+** CNDHash dtors | e.g. `FUN_0053b920` @ `0x0053b976` with `lea ecx,[this+0x20]` |
| Thunk | `thunk_FUN_0059c8a0` | `0x0059cbc0` |
| Callee | `_aligned_free` | IAT `0x009c6578` |
| Callee | `operator_delete` | CRT; returns |

## Confidence

| Claim | Level |
|---|---|
| `_aligned_free` each slab then delete vector | **Confirmed** |
| Always zero three vector fields | **Confirmed** (machine) |
| `operator_delete` returns | **Confirmed** |
| Freelist head untouched | **Confirmed** |
| Product English type name | **Open** |
| Runtime / bit-exact | **Open** |
