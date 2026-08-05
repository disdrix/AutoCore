# Function record: BitVec_EnsureOneAndLocateRef_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004363b0` |
| **Canonical name** | `BitVec_EnsureOneAndLocateRef_Inferred` |
| **Ghidra name** | `FUN_004363b0` |
| **Address** | `0x004363b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | packed bit-vector |
| **Completion status** | **Sealed W38-C** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Ensure one bit then locate bit-reference `{bit, word*}` after possible realloc of dword-packed storage at host`+8`.

## Signature

```c
// EAX=host*, EDI=out*, stack×3; ret 0xC; returns out*
BitRef* BitVec_EnsureOneAndLocateRef_Inferred(...);
```

## Artifacts

See `aa_004363b0_FUN_004363b0.md`.
