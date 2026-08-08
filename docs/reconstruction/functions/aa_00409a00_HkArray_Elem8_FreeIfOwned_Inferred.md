# Function record: HkArray_Elem8_FreeIfOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409a00` |
| **Canonical name** | `HkArray_Elem8_FreeIfOwned_Inferred` |
| **Ghidra symbol** | `FUN_00409a00` |
| **Address** | `0x00409a00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | allocator / hkArray-style free (elem size 8) |
| **Completion status** | **Dual sealed** WQ9J-J 2026-08-05 — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Purpose

Free owned elem-size-8 buffer of an hkArray-like triple when capacity is non-negative, via `DAT_00b05060` tagged free (`vtbl+0x14`, tag `0x12`). Used exclusively as SEH unwind JMP target.

## Signature

```c
void __thiscall HkArray_Elem8_FreeIfOwned_Inferred(uint32_t *arr /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409a00_FUN_00409a00.md`
- Annotated: `docs/reconstruction/raw/aa_00409a00_FUN_00409a00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/HkArray_Elem8_FreeIfOwned_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00409a00.cpp`
- FUN record: `docs/reconstruction/functions/aa_00409a00_FUN_00409a00.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md`, `B_aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI | **High** |
| Naming `_Inferred` | Inferred (no product string on this VA) |
| Runtime | Open |
