# Review A (reconstruction fidelity): `aa_0052b350` CVOGCharacter_RewardInventoryList_PushBack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b350` |
| **VA** | `0x0052b350`–`0x0052b388` inclusive (**57 B** / `0x39`) |
| **Canonical name** | `CVOGCharacter_RewardInventoryList_PushBack_Inferred` |
| **Ghidra name** | `FUN_0052b350` |
| **Prior scaffold** | `FUN_0052b350` / `Named_CalleeOf_Named_CalleeOf_CVOGReaction_CompleteObjective_0052b350` |
| **Rejected misname** | bare `Named_CalleeOf_*` parent-seed only; pure `__fastcall` void (decompiler) |
| **Review date** | `2026-08-05` (MEGA-013 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md` |
| **System** | missions-progression |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `analyze_control_flow` + callee/parent decompiles. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Owner-bound **`std::list` push_back** of a dword payload (item/object pointer from CompleteObjective reward path). Resolves embedded list at **this+0xcc4**, buys a 0xC node, increments size, splices as new tail before the sentinel.

```text
CVOGCharacter_RewardInventoryList_PushBack_Inferred(this, value)
  list = this + 0xcc4
  head = *(this + 0xcc8)
  node = BuyNode(head, head->_Prev, &value)   // FUN_00418700
  Incsize(list, 1)                            // FUN_00404840
  head->_Prev = node
  node->_Prev->_Next = node
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (head load → BuyNode → Incsize → relink) |
| Full body | `disassemble_function` + `read_memory` 64 B (57 B body + pad) |
| BuyNode | dualed `StdList_BuyNode_Dword_Seh` `0x00418700` (MEGA-081) |
| Incsize | `FUN_00404840` — `"list<T> too long"` / length_error path |
| Generic twin | dualed `StdList_PushBack_Dword_Inferred` `0x00402d10` (ECX=list*) |
| Sole caller | `FUN_004d08c0` @ `0x004d0980` — reward-slot loop under CompleteObjective |
| Nearby cluster | `CVOGCharacter_IsAreaExplored` / `IsMissionJournalReady` / `IsMissionTurnInReady` |

---

## 3. Signature (sealed)

```c
// ECX = owner*; stack = dword value (by value); void; RET 4
void __thiscall CVOGCharacter_RewardInventoryList_PushBack_Inferred(
    void *this_owner,
    uint32_t value);
```

| Formal | Source | Conf |
|---|---|---|
| this (owner) | ECX → used as base for +0xcc4/+0xcc8 | **Confirmed** |
| value | stack `[ESP+4]` at entry; address taken after 3 PUSHes (`LEA EAX,[ESP+0x10]`) | **Confirmed** |
| cleanup | `RET 4` (`C2 04 00`) | **Confirmed** |
| BuyNode | `CALL 0x00418700` with head / head->_Prev / &value | **Confirmed** |
| Incsize | `PUSH 1; CALL 0x00404840` with ECX=list | **Confirmed** |
| Tail splice | `head->_Prev = node; old_prev->_Next = node` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Save EBX/ESI/EDI | entry | **Confirmed** |
| Load head / list base | `MOV EDI,[ECX+0xcc8]` / `LEA ESI,[ECX+0xcc4]` | **Confirmed** |
| BuyNode 0xC | sole first CALL | **Confirmed** |
| Incsize(1) | second CALL | **Confirmed** |
| Relink tail | two stores | **Confirmed** |
| Restore + RET 4 | epilog | **Confirmed** |
| No loops / single return | `analyze_control_flow` | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (character-bound list insert) |
| External callers | **1** UNCONDITIONAL_CALL (`FUN_004d08c0` @ `0x004d0980`) |
| Site role | CompleteObjective reward-slot loop: push resolved item* into owner list |
| Call-site | `MOV ECX,[ESP+0x20]` … `PUSH ESI` … `CALL 0x0052b350` |
| Callees | `FUN_00418700`, `FUN_00404840` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| MSVC list push_back mechanics (buy + incsize + tail splice) | **Yes** (bytes + dualed family) |
| List embedded at owner+0xcc4 | **Yes** |
| CVOGCharacter method cluster nearby | **Yes** (high) |
| Product string "reward inventory" on field | **No** — inferred from parent reward loop + partition hint |
| Parent-seed Named_CalleeOf only | **Rejected** as final name |

**Decision:** promote **`CVOGCharacter_RewardInventoryList_PushBack_Inferred`** (`_Inferred` required for product field English).

---

## 7. Gaps

- Product English for list member at `+0xcc4`.
- Exact payload type English (item* vs broader object*).
- Full dual of parent `FUN_004d08c0`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals CF/ABI/list mechanics; product field English residual → **accept-with-gaps**.
