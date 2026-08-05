# Function record: GuardedVector_AssignDwordIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d420` |
| **Canonical name** | `GuardedVector_AssignDwordIfNonNull` (**Inferred**) |
| **Ghidra name** | `FUN_0043d420` |
| **Address** | `0x0043d420`–`0x0043d430` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque element store |
| **Status** | Dual A/B sealed W32-F 2026-07-29 — **accept** |

## Purpose

Null-checked single-dword POD assign used by GuardedVector thiscall push_back / push_front after page-slot resolve. Skips the store when `dst` is null.

## Signature

```c
// Retail: cdecl; 2 stack formals; RET 0
void GuardedVector_AssignDwordIfNonNull(uint32_t* dst, const uint32_t* src);
```

## Relationship

- Callee of W31-I `GuardedVector_PushBack_Thiscall` (`0x0043d670`) and `GuardedVector_PushFront_Thiscall` (`0x0043e3d0`).
- Closes the assign-leaf residual named by those duals.

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d420_FUN_0043d420.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d420_FUN_0043d420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignDwordIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d420.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043d420_FUN_0043d420.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043d420_GuardedVector_AssignDwordIfNonNull.md`, `B_…` |
