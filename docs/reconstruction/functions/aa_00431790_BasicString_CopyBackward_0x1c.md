# Function record: BasicString_CopyBackward_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431790` |
| **Canonical name** | `BasicString_CopyBackward_0x1c` (**Inferred** structural) |
| **Ghidra name** | `FUN_00431790` |
| **Address** | `0x00431790`–`0x004317c2` |
| **Body** | **51 B** / `0x33` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `basic_string<char>` copy_backward free helper |
| **Completion status** | **Dual-reviewed** W34-L — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Reverse-assign half-open range `[first, last)` of live `basic_string` elements into a destination ending at `dest_end` (stride **0x1c**). Overlap-safe free algorithm used by vector mid-insert via `BasicString_CopyBackward_Thunk_0x1c`.

## Signature

```c
// cdecl; 3 stack args; plain RET; returns final dest in EAX
BasicString_0x1c* BasicString_CopyBackward_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end);
```

| Formal | Source | Conf |
|---|---|---|
| first | stack → EBX | **High** |
| last | stack → ESI | **High** |
| dest_end | stack → EDI / EAX return | **High** |
| stride | `SUB …, 0x1C` | **High** |
| cleanup | plain `C3` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `BasicString_CopyBackward_Thunk_0x1c` (`FUN_00431480`) @ `0x00431494` |
| Callees | IAT `basic_string::operator=` via `[0x009c63c4]` → `0x006ec244` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431790_FUN_00431790.md`
- Annotated: `docs/reconstruction/raw/aa_00431790_FUN_00431790.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BasicString_CopyBackward_0x1c.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00431790.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00431790_BasicString_CopyBackward_0x1c.md`
- Review B: `docs/reconstruction/reviews/B_aa_00431790_BasicString_CopyBackward_0x1c.md`
