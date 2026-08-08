# Function record: StdList_PushBack_DwordFromEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517db0` |
| **Canonical name** | `StdList_PushBack_DwordFromEcx_Inferred` |
| **Ghidra name** | `FUN_00517db0` |
| **Address** | `0x00517db0`–`0x00517de9` (**58 B** / `0x3A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` utility |
| **Partition** | R10-032 / missions-progression residual (parent BuyNode `0x00418700`) |
| **Completion status** | **Dual A/B sealed 2026-08-05** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Purpose

Push a dword-sized element onto the tail of an MSVC `std::list`-shaped container, taking the element value from **ECX** (by value — typically the caller's adjusted `this`):

```
head = list->_Myhead
value = ECX
node = BuyNode(head, head->_Prev, &value)   // FUN_00418700
_Incsize(list, 1)                           // FUN_00404840 (may throw)
head->_Prev = node
old_prev->_Next = node
```

## Signature

```c
void StdList_PushBack_DwordFromEcx_Inferred(
    StdListHeaderDword* list /*stack*/,
    uint32_t value_in_ecx /*ECX*/);
// RET 4  (C2 04 00)
```

## Layout

| Offset | Field |
|---|---|
| list+0x04 | `_Myhead` |
| list+0x08 | `_Mysize` |
| node+0x00 | `_Next` |
| node+0x04 | `_Prev` |
| node+0x08 | `_Myval` (dword = entry ECX) |

## Callees

| VA | Role |
|---|---|
| `0x00418700` | Buy 0xC node; RET 0xC (`StdList_BuyNode_Dword_Seh`) |
| `0x00404840` | `_Incsize`; `"list<T> too long"` (`StdList_Incsize_Thiscall`) |

## Callers

| Parent | Sites |
|---|---|
| `FUN_004c30d0` | `0x004c30e9` |
| `FUN_004f46c0` | `0x004f46d9` |
| `FUN_00562fa0` | `0x00562fb9` |
| `FUN_00587680` | `0x00587699` |
| `FUN_00569ba0` | `0x00569bb0` (this-adjust + tail JMP) |
| DATA vtable slots | 18+ (multi-class virtual register-on-list) |

## Related (not owned)

- `StdList_PushBack_Dword_Inferred` `0x00402d10` — ECX=list, stack=`const T*`
- `StdList_PushFront_DwordFromEax_Inferred` `0x004027f0` — EAX=`const T*`, stack=list; front splice
- `StdList_BuyNode_Dword_Seh` `0x00418700` — parent dual
- `StdList_Incsize_Thiscall` `0x00404840` — R10-006 dual

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00517db0_FUN_00517db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00517db0_FUN_00517db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushBack_DwordFromEcx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00517db0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00517db0_FUN_00517db0.md` |
| Report | `docs/agents/task-dual-ab-00517db0-r10-report.md` |
