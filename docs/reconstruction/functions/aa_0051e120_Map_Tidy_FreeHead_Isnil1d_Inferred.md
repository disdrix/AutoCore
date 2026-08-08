# Function record: Map_Tidy_FreeHead_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e120` |
| **Canonical name** | `Map_Tidy_FreeHead_Isnil1d_Inferred` |
| **Ghidra name** | `FUN_0051e120` |
| **Address** | `0x0051e120`–`0x0051e14d` inclusive (**46 bytes** / exclusive end `0x0051e14e`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map tidy (host of dualed `Map_EraseRange_Isnil1d_Inferred`; isnil@+0x1d) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-G OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style **map tidy**: full-range erase via dualed `Map_EraseRange_Isnil1d_Inferred` (`0x0051d700`), free the sentinel head node, null `head` and `size`. Does **not** free the map facade object (outer caller may). Same 46 B template as dualed `Map_Tidy_FreeHead` (`0x0051da30`, isnil@+0x29) and `StdTree_Tidy_FreeHead_Bare_Val12`. Sole static consumer is atexit thunk for global map host `0x00b04240`.

## Signature (byte-sealed)

```c
void __fastcall Map_Tidy_FreeHead_Isnil1d_Inferred(void *map); // ECX = map*; bare RET (C3)
// head @ map+4; size @ map+8
```

## Artifacts

- Raw (+ WQ9F-G re-verify): `docs/reconstruction/raw/aa_0051e120_FUN_0051e120.md`
- Annotated: `docs/reconstruction/raw/aa_0051e120_FUN_0051e120.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_Isnil1d_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051e120.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_0051e120_FUN_0051e120.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_009c3940` | static dtor: `ECX=0xb04240` then JMP |
| Callee | `Map_EraseRange_Isnil1d_Inferred` `0x0051d700` | dualed WQ9E-I |
| Callee | `operator_delete` | free head only |

## Confidence

| Claim | Level |
|---|---|
| Tidy CF + ABI + null epilogue | **Confirmed** |
| Structural twin of `Map_Tidy_FreeHead` | **High** |
| isnil@+0x1d via erase-range callee | **High** |
| Product host English for `0xb04240` | Open |
| Runtime / bit-exact | Open |
