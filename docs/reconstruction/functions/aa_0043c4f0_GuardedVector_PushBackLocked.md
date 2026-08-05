# Function record: GuardedVector_PushBackLocked

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c4f0` |
| **Canonical name** | `GuardedVector_PushBackLocked` (**Inferred**) |
| **Ghidra name** | `FUN_0043c4f0` |
| **Address** | `0x0043c4f0`–`0x0043c54d` (**94 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Wave** | W30-D OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept** |

## Purpose

Lock-gated push_back: optional Enter CS → `GuardedVector_PushBack` → Leave CS.

## Signature

```c
// EDI=container; stack const uint32_t* value; RET 0x4
void GuardedVector_PushBackLocked(...);
```

## Family

| Unit | VA | Role |
|---|---|---|
| `GuardedVector_PushBack` | `0x0043c830` | unlocked body (W29-B) |
| `GuardedVector_PushBackLocked` | `0x0043c4f0` | this unit — CS wrapper |
| `GuardedVector_AssignTo` | `0x0043c5f0` | CS wrapper around CopyAssign |
| `GuardedVector_EraseFirstEqual` | `0x0043c550` | sibling after pad |

## Artifacts

See `aa_0043c4f0_FUN_0043c4f0.md` for full paths and confidence table.
