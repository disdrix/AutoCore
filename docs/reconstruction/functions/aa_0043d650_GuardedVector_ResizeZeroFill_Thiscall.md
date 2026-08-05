# Function record: GuardedVector_ResizeZeroFill_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d650` |
| **Canonical name** | `GuardedVector_ResizeZeroFill_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d650` |
| **Address** | `0x0043d650`–`0x0043d66b` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W34-M 2026-07-29 — **accept** |

## Purpose

Thiscall zero-fill resize wrapper over sealed `GuardedVector_Resize_Thiscall`. Closes the W33-L sole-caller residual for fill seeding.

## Signature

```c
// ECX=container; stack new_size; RET 0x4
void GuardedVector_ResizeZeroFill_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                           uint32_t new_size);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d650_FUN_0043d650.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d650_FUN_0043d650.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ResizeZeroFill_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d650.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043d650_FUN_0043d650.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md`, `B_…` |
