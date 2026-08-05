# Function record: StdMap_FindEq_UintKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d5e0` |
| **Canonical name** | `StdMap_FindEq_UintKey_Val12` |
| **Address** | `0x0043d5e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / MSVC `_Tree` Val12 uint-key map |
| **Completion status** | **Dual-reviewed** — raw/annotated/clean + A/B reviews (2026-08-04 W37-M) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Leaf MSVC-style **ordered-tree exact find** for a **uint32** key. Walks from map head at `this+4`, nil flag **`node+0x19`**, key at **`node+0x0C`** (unsigned). Writes hit node or end into `*out_it` via EAX. Read-only.

## Signature (ABI-corrected)

```c
// Register ABI: ECX=map, EBX=const uint32_t* key, EAX=node** out_it; RET
void StdMap_FindEq_UintKey_Val12(void *map, void **out_it, const uint32_t *key);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043d5e0_FUN_0043d5e0.md`
- Annotated: `docs/reconstruction/raw/aa_0043d5e0_FUN_0043d5e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_FindEq_UintKey_Val12.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md`

## Callers / callees

- **Callees:** none (leaf).
- **Callers (Ghidra, 8):** `FUN_0072a660`, `FUN_00750260`, `FUN_0075d230`, `FUN_0075d330`, `FUN_00970c00`, `FUN_00971640`, `FUN_00971a20`, `FUN_00971ea0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| Register ABI ECX/EBX/EAX + plain RET | **Confirmed** |
| Nil `+0x19`, key uint `+0x0C`, L+0 / R+8 | **Confirmed** |
| Exact-match gate (not pure lower_bound) | **Confirmed** |
| Full node value layout / product STL name | **Open** |
