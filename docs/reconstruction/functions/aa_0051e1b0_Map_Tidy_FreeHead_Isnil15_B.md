# Function record: Map_Tidy_FreeHead_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e1b0` |
| **Canonical name** | `Map_Tidy_FreeHead_Isnil15_B` |
| **Ghidra name** | `FUN_0051e1b0` |
| **Address** | `0x0051e1b0`–`0x0051e1dd` inclusive (**46 bytes** / exclusive end `0x0051e1de`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map tidy (host of dualed `Map_EraseRange_Isnil15_B`; isnil@+0x15) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9G-D OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style **map tidy**: full-range erase via dualed `Map_EraseRange_Isnil15_B` (`0x0051d940`), free the sentinel head node, null `head` and `size`. Does **not** free the map facade object. Same 46 B template as dualed `Map_Tidy_FreeHead` / `Map_Tidy_FreeHead_B` / `Map_Tidy_FreeHead_Isnil1d_Inferred`. Static consumer is atexit vector dtor over global map array `DAT_00b04288[3]` (stride `0xc`).

## Signature (byte-sealed)

```c
void __fastcall Map_Tidy_FreeHead_Isnil15_B(void *map); // ECX = map*; bare RET (C3)
// head @ map+4; size @ map+8
```

## Artifacts

- Raw (+ WQ9G-D re-verify): `docs/reconstruction/raw/aa_0051e1b0_FUN_0051e1b0.md`
- Annotated: `docs/reconstruction/raw/aa_0051e1b0_FUN_0051e1b0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_Isnil15_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051e1b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md`
- Alias record: `docs/reconstruction/functions/aa_0051e1b0_FUN_0051e1b0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_009c3980` | `_eh_vector_destructor_iterator_(&DAT_00b04288, 0xc, 3, this)` |
| Callee | `Map_EraseRange_Isnil15_B` `0x0051d940` | dualed; full-range erase |
| Callee | `operator_delete` | free sentinel head only |

## Confidence

| Claim | Level |
|---|---|
| Tidy CF + ABI + null epilogue | **Confirmed** |
| Structural twin of `Map_Tidy_FreeHead` | **High** |
| isnil@+0x15 via erase-range callee | **High** |
| Product host English for `0xb04288` | Open |
| Runtime / bit-exact | Open |
