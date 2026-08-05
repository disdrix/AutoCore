# Function record: GuardedVector_InsertRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e1c0` |
| **Canonical name** | `GuardedVector_InsertRange` (**Inferred**) |
| **Ghidra name** | `FUN_0044e1c0` |
| **Address** | `0x0044e1c0`–`0x0044e4ee` (**815 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Wave** | W32-G OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |

## Purpose

Range insert of external dword span into GuardedVector ring at absolute index; shorter-side policy.

## Signature

```c
// stdcall; RET 0x18; 6 stack formals
void GuardedVector_InsertRange(...);
```

## Family

| Unit | VA | Role |
|---|---|---|
| `GuardedVector_InsertN` | `0x0043cb00` | N×fill insert (W29-A; EAX push family) |
| `GuardedVector_InsertRange` | `0x0044e1c0` | this unit — range insert (thiscall push) |
| `GuardedVector_PushFront_Thiscall` | `0x0043e3d0` | front growth (W31-I) |
| `GuardedVector_PushBack_Thiscall` | `0x0043d670` | back growth (W31-I) |

## Artifacts

See `aa_0044e1c0_FUN_0044e1c0.md` for full paths and confidence table.
