# Function record: BasicStringW_CopyBackward_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a68d0` |
| **Canonical name** | `BasicStringW_CopyBackward_0x1c` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a68d0` |
| **Address** | `0x004a68d0` |
| **Body** | `0x004a68d0`–`0x004a6902` inclusive (**51 B** / `0x33`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `basic_string<wchar_t>` reverse range assign (`copy_backward`) |
| **Completion status** | **Dual-reviewed** W36-T — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Reverse-assign live `basic_string<wchar_t>` elements over half-open range `[first, last)` into a destination ending at `dest_end` (element stride **0x1c**). Implements the mid-insert tail shift of `vector<wstring>::insert(where, count, value)` (`StdVector_InsertN_BasicStringW`).

## Signature

```c
// cdecl; 3 stack args; plain RET; returns final dest*
BasicStringW_0x1c* BasicStringW_CopyBackward_0x1c(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest_end);
```

| Formal | Source | Conf |
|---|---|---|
| first | stack `[esp+4]` → EBX | **High** |
| last | stack `[esp+8]` → ESI | **High** |
| dest_end | stack `[esp+0xC]` → EDI | **High** |
| return | **EAX** = final dest after reverse walk | **High** |
| stride | `SUB ESI/EDI, 0x1C` | **High** |
| cleanup | plain `C3` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicStringW` (`FUN_004a7ad0`) @ `0x004a7dbf` |
| Callees | IAT `basic_string<wchar_t>::operator=` via `[0x009c63bc]` → `0x006ec314` |

## Related

| VA | Role |
|---|---|
| `0x00431790` | char twin `BasicString_CopyBackward_0x1c` (W34-L) |
| `0x004a68a0` | sibling fill `BasicStringW_FillAssignRange_0x1c` (W36-T) |
| `0x004a7ad0` | sole parent insert-n (W34-R) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a68d0_FUN_004a68d0.md` (W36-T append)
- Annotated: `docs/reconstruction/raw/aa_004a68d0_FUN_004a68d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BasicStringW_CopyBackward_0x1c.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a68d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a68d0_BasicStringW_CopyBackward_0x1c.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a68d0_BasicStringW_CopyBackward_0x1c.md`
- Scaffold record: `docs/reconstruction/functions/aa_004a68d0_FUN_004a68d0.md`

## Confidence

| Claim | Level |
|---|---|
| Reverse assign + stride 0x1c | **High** |
| ABI cdecl 3-arg + plain RET | **High** |
| EAX final dest return | **High** |
| Product demangle plate | **Low** |
