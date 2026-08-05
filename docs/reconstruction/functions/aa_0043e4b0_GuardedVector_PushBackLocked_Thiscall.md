# Function record: GuardedVector_PushBackLocked_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e4b0` |
| **Canonical name** | `GuardedVector_PushBackLocked_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043e4b0` |
| **Address** | `0x0043e4b0`–`0x0043e50d` (**94 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Wave** | W32-G OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept** |

## Purpose

Lock-gated push_back: optional Enter CS → `GuardedVector_PushBack_Thiscall` → Leave CS.

## Signature

```c
// EDI=container; stack const uint32_t* value; RET 0x4
void GuardedVector_PushBackLocked_Thiscall(...);
```

## Family

| Unit | VA | Role |
|---|---|---|
| `GuardedVector_PushBack_Thiscall` | `0x0043d670` | unlocked body (W31-I) |
| `GuardedVector_PushBackLocked_Thiscall` | `0x0043e4b0` | this unit — CS wrapper (thiscall nest) |
| `GuardedVector_PushBackLocked` | `0x0043c4f0` | CS wrapper nesting EAX PushBack (W30-D) |
| `GuardedVector_PushBack` | `0x0043c830` | unlocked EAX body (W29-B) |

## Artifacts

See `aa_0043e4b0_FUN_0043e4b0.md` for full paths and confidence table.
