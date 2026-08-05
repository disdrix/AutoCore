# Function record: GuardedVector_EraseFirstEqual_ThiscallRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e630` |
| **Canonical name** | `GuardedVector_EraseFirstEqual_ThiscallRange` (**Inferred** structural) |
| **Ghidra name** | `FUN_0043e630` |
| **Address** | `0x0043e630`–`0x0043e6c1` |
| **Body** | **146 B** / `0x92` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Completion status** | **Dual-reviewed** W35-A — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Erase the first ring element equal to `*key` under optional CS. Nested erase is **thiscall** `GuardedVector_EraseRange_Thiscall` (W34-L). Outer ABI matches W28-C EraseFirstEqual (**ESI** container, **RET 4**, **AL** found) but is a distinct code unit with different nested EraseRange ABI.

## Signature

```c
// ESI=container; stdcall 1 stack formal; RET 0x4; AL=found
uint8_t GuardedVector_EraseFirstEqual_ThiscallRange(
    const int* key /*stack*/,
    GuardedVectorHeader* container /*ESI*/);
```

| Formal | Source | Conf |
|---|---|---|
| container | **ESI** (caller-established) | **High** |
| key | Stack[+4] | **High** |
| cleanup | `RET 0x4` | **High** |
| return | **AL** found | **High** |

## Layout

| Off | Field |
|---|---|
| +0x04 | pages |
| +0x08 | capacity |
| +0x0c | begin |
| +0x10 | size |
| +0x14 | CRITICAL_SECTION |
| +0x2c | lock-enable |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00971030` (pending ring `this+0x1c`); `NDResourceCache_LookupOrCreate` |
| Callees | CS IAT; `GuardedVector_EraseRange_Thiscall` (`0043df90`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043e630_FUN_0043e630.md`
- Annotated: `docs/reconstruction/raw/aa_0043e630_FUN_0043e630.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GuardedVector_EraseFirstEqual_ThiscallRange.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0043e630.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md`
- Review B: `docs/reconstruction/reviews/B_aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md`
