# Function record: StdVector_FindOrPushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00746400` |
| **Canonical name** | `StdVector_FindOrPushBackDword_Inferred` |
| **Ghidra name** | `FUN_00746400` |
| **Address** | `0x00746400`–`0x00746437` (**56 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / std::vector-like dword registry |
| **Completion status** | **Dual-reviewed (W37-V)** — accept |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Classification** | worker |

## Purpose

Find-or-push one dword into a classic 3-pointer MSVC-ish vector shell (`+4` begin, `+8` end, `+c` capacity via push callee). Returns **1** if the value was already present, **0** if newly appended. Not an error code — OOM wrappers around callers return **−1** separately.

## Signature

```c
uint32_t __thiscall StdVector_FindOrPushBackDword_Inferred(
    VecDword *vec /*ECX*/,
    uint32_t value /*stack*/);
// RET 4
```

## Family

- Push primitive: `StdVector_PushBackDword_Inferred` (`0x004406e0`)
- Callers: water/distort phase token register; gfx bootstrap registrants on `DAT_00d1f620`

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_00746400_FUN_00746400.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_FindOrPushBackDword_Inferred.cpp`
- Dual A/B: `reviews/A_aa_00746400_StdVector_FindOrPushBackDword_Inferred.md`, `reviews/B_aa_00746400_StdVector_FindOrPushBackDword_Inferred.md`
