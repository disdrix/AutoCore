# Function record: GuardedVector_InsertRange_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_005441d0` |
| **Canonical name** | `GuardedVector_InsertRange_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_005441d0` |
| **Address** | `0x005441d0`–`0x00544587` exclusive (**951 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Partition** | W32-I |
| **Completion status** | **Dual sealed** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

GuardedVector **insert range**: place `[first,last)` at absolute index with shorter-side room (thiscall push_front/back) and ring assign forward/backward.

## Signature

```c
void GuardedVector_InsertRange_Thiscall(
    GuardedVectorHeader* dest /*ECX*/,
    /* 7 stack formals; RET 0x1C */);
```

## Layout

| Off | Field |
|---|---|
| +0x04 | pages / slots |
| +0x08 | capacity (page count) |
| +0x0c | begin (absolute index) |
| +0x10 | size |

## Related

| VA | Role |
|---|---|
| `0x0043cb00` | `GuardedVector_InsertN` (fill N copies) — W29-A |
| `0x0043e3d0` | `GuardedVector_PushFront_Thiscall` — W31-I |
| `0x0043d670` | `GuardedVector_PushBack_Thiscall` — W31-I |
| `0x00545190` | sole caller (copy-construct insert full range at 0) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005441d0_FUN_005441d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005441d0_FUN_005441d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertRange_Thiscall.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005441d0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_005441d0_FUN_005441d0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_005441d0_GuardedVector_InsertRange_Thiscall.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-005441d0-00556b10-w32i-report.md` |
