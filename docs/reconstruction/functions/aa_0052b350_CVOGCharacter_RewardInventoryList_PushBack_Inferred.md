# Function record: CVOGCharacter_RewardInventoryList_PushBack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b350` |
| **Canonical name** | `CVOGCharacter_RewardInventoryList_PushBack_Inferred` |
| **Prior scaffold** | `FUN_0052b350` |
| **Rejected misname** | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_CompleteObjective_0052b350` (parent-seed only) |
| **Address** | `0x0052b350`–`0x0052b388` inclusive (**57 B** / `0x39`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Agent** | MEGA-013 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps** — CF/ABI sealed; product field English residual) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Owner-bound MSVC **`std::list` push_back** for the character list at **this+0xcc4**. Used by the CompleteObjective reward-slot loop (`FUN_004d08c0`) to append each resolved reward item pointer.

```text
CVOGCharacter_RewardInventoryList_PushBack_Inferred(this, value) -> void
  list = this + 0xcc4
  head = *(this + 0xcc8)
  node = StdList_BuyNode_Dword_Seh(head, head->_Prev, &value)  // 0x00418700
  FUN_00404840(list, 1)                                        // Incsize
  head->_Prev = node
  node->_Prev->_Next = node
```

## Signature (decompiler + bytes + call site)

```c
// __thiscall; RET 4
// ECX = CVOGCharacter* (owner; class High from nearby methods)
// stack = dword value (item/object* by value)
void __thiscall CVOGCharacter_RewardInventoryList_PushBack_Inferred(
    void *this_owner,
    uint32_t value);
```

| Item | Value |
|---|---|
| List base | this+**0xcc4** |
| `_Myhead` | this+**0xcc8** (list+4) |
| Node size | **0xC** (Next/Prev/Myval dword) |
| BuyNode | `StdList_BuyNode_Dword_Seh` `0x00418700` (dualed) |
| Incsize | `FUN_00404840` (`"list<T> too long"`) |
| Free twin | `StdList_PushBack_Dword_Inferred` `0x00402d10` (ECX=list*; stack=`const T*`) — **different ABI** |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_0052b350_FUN_0052b350.md`
- Annotated: `docs/reconstruction/raw/aa_0052b350_FUN_0052b350.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_RewardInventoryList_PushBack_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0052b350.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_0052b350_FUN_0052b350.md`
- Report: `docs/agents/task-dual-ab-0052b350-mega-013-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `StdList_BuyNode_Dword_Seh` `0x00418700` | dualed MEGA-081 |
| Callee | `FUN_00404840` | Incsize / length_error path |
| Caller | `FUN_004d08c0` @ `0x004d0980` | sole UNCONDITIONAL_CALL; 4-slot reward loop |
| Parent context | CompleteObjective / `Named_CalleeOf_CVOGReaction_CompleteObjective` scaffold | residual parent dual |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| `__thiscall` + `RET 4` + by-value dword | **Confirmed** |
| MSVC list push_back at +0xcc4 | **Confirmed** |
| CVOGCharacter owner class | **High** |
| "Reward inventory" field English | **Inferred** |
| Full vtable / product strings | **Tentative** |
