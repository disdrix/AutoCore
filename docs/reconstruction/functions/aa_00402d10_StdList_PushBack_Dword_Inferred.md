# Function record: StdList_PushBack_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d10` |
| **Canonical name** | `StdList_PushBack_Dword_Inferred` |
| **Ghidra name** | `FUN_00402d10` |
| **Address** | `0x00402d10`–`0x00402d41` (**50 B** / `0x32`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` utility |
| **Partition** | MEGA-126 / missions-progression residual (DebugListMissionsStatus nested) |
| **Completion status** | **Dual A/B sealed 2026-08-05** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Purpose

Push a dword-sized element onto the tail of an MSVC `std::list`-shaped container:

```
head = list->_Myhead
node = BuyNode(head, head->_Prev, pValue)   // FUN_00418700
_Incsize(list, 1)                           // FUN_00404840 (may throw)
head->_Prev = node
old_prev->_Next = node
```

## Signature

```c
void __thiscall StdList_PushBack_Dword_Inferred(
    StdListHeaderDword* list /*ECX*/,
    const uint32_t* pValue /*stack*/);
// RET 4  (C2 04 00)
```

## Layout

| Offset | Field |
|---|---|
| list+0x04 | `_Myhead` |
| list+0x08 | `_Mysize` |
| node+0x00 | `_Next` |
| node+0x04 | `_Prev` |
| node+0x08 | `_Myval` (dword) |

## Callees

| VA | Role |
|---|---|
| `0x00418700` | Buy 0xC node; RET 0xC |
| `0x00404840` | `_Incsize`; `"list<T> too long"` / ThrowInfo `DAT_00acc388` |

## Callers

| Parent | Sites |
|---|---|
| `FUN_009572e0` Client_DebugListMissionsStatus | `0x00957467` |
| `FUN_00509010` | `0x00509280` |
| `FUN_0057ade0` | `0x0057aeee`, `0x0057af49`, `0x0057af92`, `0x0057b080`, `0x0057b0c0` |

## Related (not owned)

- `StdList_PushPayloadNode_Inferred` `0x00480350` — same splice; payload via **EAX**
- `StdList_BuyNode_Dword` `0x006759b0` — BuyNode twin of `FUN_00418700`
- `StdList_Incsize` `0x0043fe60` — Incsize twin of `FUN_00404840`
- Retired scaffold: `Named_CalleeOf_Client_DebugListMissionsStatus_00402d10`

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402d10_FUN_00402d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00402d10_FUN_00402d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushBack_Dword_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00402d10.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00402d10_StdList_PushBack_Dword_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00402d10_StdList_PushBack_Dword_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00402d10_FUN_00402d10.md` |
| Report | `docs/agents/task-dual-ab-00402d10-mega-126-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET4 / push_back | **High / Sealed** |
| Shared multi-caller | **High / Sealed** |
| Product `T` English | **Tentative** (`_Inferred`) |
| Runtime Confirmed | **Open** |
