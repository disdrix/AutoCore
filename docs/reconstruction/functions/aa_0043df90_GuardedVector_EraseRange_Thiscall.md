# Function record: GuardedVector_EraseRange_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043df90` |
| **Canonical name** | `GuardedVector_EraseRange_Thiscall` (**Inferred** structural) |
| **Ghidra name** | `FUN_0043df90` |
| **Address** | `0x0043df90`–`0x0043e07d` |
| **Body** | **238 B** / `0xEE` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Completion status** | **Dual-reviewed** W34-L — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Erase absolute index range `[erase_from, erase_to)` in a GuardedVector ring header under **thiscall** ABI. Chooses reverse vs forward element packing by shorter side, then updates `begin`/`size` and publishes out iterator `{container, begin+prefix}`. Closes shrink residual of W33-L `GuardedVector_Resize_Thiscall`.

## Signature

```c
// ECX=container; stack (out, from_c, from_i, to_c, to_i); RET 0x14
void GuardedVector_EraseRange_Thiscall(
    GuardedVectorHeader* container /*ECX*/,
    GuardedVectorIteratorPair* out,
    uint32_t erase_from_c, int32_t erase_from_i,
    uint32_t erase_to_c,   int32_t erase_to_i);
```

| Formal | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,ECX`) | **High** |
| out | Stack[+4] | **High** |
| erase_from_i / erase_to_i | Stack[+0xc]/[+0x14] | **High** |
| cleanup | `RET 0x14` | **High** |

## Layout

| Off | Field |
|---|---|
| +0x08 | capacity (wrap = capacity×4) |
| +0x0c | begin |
| +0x10 | size |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | Resize_Thiscall (`0043d940`); `FUN_0043e630`; `FUN_004ed310`; AssPreloader helpers `00971820` / `00971700` |
| Callees | `GuardedVector_RingAssignBackwardChecked` (`0043ebb0`); `GuardedVector_RingAssignForward` (`0043ec50`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043df90_FUN_0043df90.md`
- Annotated: `docs/reconstruction/raw/aa_0043df90_FUN_0043df90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GuardedVector_EraseRange_Thiscall.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0043df90.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0043df90_GuardedVector_EraseRange_Thiscall.md`
- Review B: `docs/reconstruction/reviews/B_aa_0043df90_GuardedVector_EraseRange_Thiscall.md`
