# Function record: GuardedVector_Resize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c7e0` |
| **Canonical name** | `GuardedVector_Resize` (**Inferred**) |
| **Ghidra name** | `FUN_0043c7e0` |
| **Address** | `0x0043c7e0`–`0x0043c829` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W28-D 2026-07-29 — **accept-with-gaps** |

## Purpose

Resize the GuardedVector ring header to an absolute `new_size`. Grow path default-fills with `0` through unowned `FUN_0043cb00`; shrink path erases `[begin+new_size, begin+size)` via sealed `GuardedVector_EraseRange`.

## Signature

```c
// Retail: EAX=container; ECX=new_size; plain RET; frame SUB/ADD ESP,8
void GuardedVector_Resize(uint32_t new_size /*ECX*/,
                          GuardedVectorHeader* container /*EAX*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c7e0_FUN_0043c7e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c7e0_FUN_0043c7e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Resize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c7e0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043c7e0_FUN_0043c7e0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043c7e0_GuardedVector_Resize.md`, `B_…` |
