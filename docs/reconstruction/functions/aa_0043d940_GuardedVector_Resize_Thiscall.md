# Function record: GuardedVector_Resize_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d940` |
| **Canonical name** | `GuardedVector_Resize_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d940` |
| **Address** | `0x0043d940`–`0x0043d989` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W33-L 2026-07-29 — **accept** |

## Purpose

Thiscall resize of the GuardedVector ring header: grow via `GuardedVector_InsertN_Thiscall` end-insert of fill copies; shrink via thiscall erase-range helper. ABI differs from W28-D `GuardedVector_Resize` (EAX container / ECX new_size / plain RET / internal fill0).

## Signature

```c
// ECX=container; stack (new_size, fill); RET 0x8
void GuardedVector_Resize_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                   uint32_t new_size,
                                   uint32_t fill);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d940_FUN_0043d940.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d940_FUN_0043d940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Resize_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d940.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043d940_FUN_0043d940.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043d940_GuardedVector_Resize_Thiscall.md`, `B_…` |
