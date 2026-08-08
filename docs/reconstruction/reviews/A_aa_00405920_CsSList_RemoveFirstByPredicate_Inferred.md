# Review A (reconstruction fidelity): `aa_00405920` CsSList_RemoveFirstByPredicate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405920` |
| **VA** | `0x00405920`–`0x004059b9` inclusive (**154 B** / `0x9A`) |
| **Canonical name** | `CsSList_RemoveFirstByPredicate_Inferred` |
| **Ghidra name** | `FUN_00405920` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920` |
| **Rejected misname** | inventory-transfer-only / SendInventoryAddItem product helper |
| **Review date** | `2026-08-05` (MEGA-042 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00405920_CsSList_RemoveFirstByPredicate_Inferred.md` |
| **System** | client containers / CS-protected singly-linked list |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `batch_decompile` (callers) + `analyze_control_flow`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Dual-CS **remove-first-by-predicate** on the same singly-linked payload list used by dualed Append (`004024d0`) and Contains (`004e15a0`):

```text
CsSList_RemoveFirstByPredicate(list, pred, cookie)
  EnterCS(+0x28); EnterCS(+0x10)
  for node in head..next:
    if pred(node.payload, cookie):
      unlink; clear payload; node->vtbl[0](1); InterlockedDec(+0xC)
      LeaveCS; return
  LeaveCS; return
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold raw CF (dual Enter → walk → pred → unlink/dtor/dec → Leave) |
| Full body | `disassemble_function` + `read_memory` 160 B (ends `C2 08 00` + `CC`) |
| Size | `analyze_control_flow` → **154 B**, 13 BB, cyclomatic 11 |
| Family | dualed Append `aa_004024d0`, Contains `aa_004e15a0` — identical list/node offs |
| Predicates | `read_memory` @ `0x4cd580` / `0x92d8e0` → ptr-eq `SETE` / `RET 8` |
| Call sites | `get_assembly_context` @ `004d4855`, `00944d8f`, `00944e1e` |

---

## 3. Signature (sealed)

```c
// ECX=list*; stack pred*, cookie; void; RET 8
void __thiscall CsSList_RemoveFirstByPredicate_Inferred(
    void* list,
    char (__cdecl *pred)(void* payload, void* cookie),
    void* cookie);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX → EDI (`MOV EDI,ECX`) | **Confirmed** |
| pred | stack; `CALL [ESP+…]` after pushes | **Confirmed** |
| cookie | stack; loaded EBP, pushed to pred | **Confirmed** |
| cleanup | `RET 8` (`C2 08 00` @ `0x004059b7`) | **Confirmed** |
| return | void | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Enter outer CS `+0x28` then inner `+0x10` | bytes + decompile | **Confirmed** |
| Walk head (`+4`) via next (`node+8`); prev in EBX | loop | **Confirmed** |
| `pred(payload@+4, cookie)`; AL test | CALL + `TEST AL,AL` | **Confirmed** |
| Unlink head/prev; tail=`prev` if next null | stores to `+4`/`+8` | **Confirmed** |
| Clear payload; `PUSH 1; MOV ECX,node; CALL [vtbl]` | dtor | **Confirmed** |
| `InterlockedDecrement(+0xC)` then leave both CS | IAT call | **Confirmed** |
| Exhaust list → leave both CS | shared leave label | **Confirmed** |
| First-match only (no continue after remove) | goto leave | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (container) |
| External callers | **2** functions / **3** UNCONDITIONAL_CALL |
| Site roles | Object_QueueDelete remove-from-list; world/object teardown removes |
| Callees | EnterCS ×2, LeaveCS ×2, InterlockedDecrement, node vtbl[0] |
| Predicates at sites | pointer equality (not inventory string logic) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Same layout as dualed CsSList Append/Contains | **Yes** |
| Predicate-driven remove (not hard-coded inventory) | **Yes** |
| Multi-caller (delete queue + object teardown) | **Yes** |
| Product class English / RTTI for list type | **No** |
| SendInventoryAddItem string/symbol in body | **No** |

**Decision:** promote **`CsSList_RemoveFirstByPredicate_Inferred`**. Retire SendInventoryAddItem scaffold plate. Keep `_Inferred` until product class sealed.

---

## 7. Gaps

- Product C++ class name for list host / node vtbl `009cb340`.
- Mapping which list instance is inventory-transfer vs delete-queue.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/layout/family with product-English residual → **accept-with-gaps**.
