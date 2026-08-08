# Review A (reconstruction fidelity): `aa_004034c0` StdList_InsertN_BeforeNode_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004034c0` |
| **VA** | `0x004034c0`–`0x00403522` inclusive (**99 B** / `0x63`) |
| **Canonical name** | `StdList_InsertN_BeforeNode_Dword_Inferred` |
| **Ghidra name** | `FUN_004034c0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_004034c0` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-134 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` |
| **System** | shared MSVC `std::list` (missions-progression partition hint only) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `analyze_function_completeness` + `get_function_callers` / `get_xrefs_to` / `get_function_callees` + callee chain `004040f0` / `00418700` / `00404840`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **`std::list` insert-N before node** for **dword** payload nodes (size **0xC**):

```text
StdList_InsertN_BeforeNode_Dword(val*, list, where, count)
  SEH install (LAB_009bd210)
  while count != 0:
    FUN_004040f0(list, where, val)   // insert one before where + Incsize(1)
    count--
  SEH unlink; RET 0xC
```

Sole live caller `FUN_00402dd0` uses it as the **grow** path of list resize (`count = target − _Mysize`, `where = head` ⇒ N× push_back of stack `T`).

Not mission/debug product logic — shared STL helper nested under `Client_DebugListMissionsStatus` only via that resize parent.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (loop + SEH); callee this corrected via asm |
| Full body | `disassemble_function` + `read_memory` **99 B** hex sealed |
| Callee insert | `FUN_004040f0` asm: ECX=list, RET 8; BuyNode + Incsize |
| BuyNode | `FUN_00418700` `operator_new(0xC)` Next/Prev/`*val` |
| Incsize | `FUN_00404840` max `0x3fffffff`, string `"list<T> too long"` |
| Caller | `FUN_00402dd0` @ `0x00402de6` — sole UNCONDITIONAL_CALL |
| Clean | `reconstructed-exact/StdList_InsertN_BeforeNode_Dword_Inferred.cpp` |

---

## 3. Signature (sealed)

```c
// ECX=const uint32_t* val; stack list*, where*, count; void; RET 0xC
void StdList_InsertN_BeforeNode_Dword_Inferred(
    const uint32_t *val,
    StdListDword *list,
    ListNodeDword *where,
    uint32_t count);
```

| Formal | Source | Conf |
|---|---|---|
| val* | entry **ECX** → EBX; pushed as insert value* | **Confirmed** |
| list* | stack `[EBP+8]` → ECX for `FUN_004040f0` | **Confirmed** |
| where* | stack `[EBP+0xC]` → EDI; pushed | **Confirmed** |
| count | stack `[EBP+0x10]` → ESI; countdown | **Confirmed** |
| cleanup | `RET 0xC` (`C2 0C 00`) | **Confirmed** |
| early-out | `TEST ESI,ESI` / `JBE` (unsigned) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH install FS:[0] / `LAB_009bd210` | bytes | **Confirmed** |
| Count loop insert-one | sole CALL `004040f0` | **Confirmed** |
| List this passed in ECX (not in decompile print) | asm `MOV ECX,[EBP+8]` | **Confirmed** |
| Unlink SEH; `RET 0xC` | epilog | **Confirmed** |
| No direct string / throw in this body | Incsize may throw in callee | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** (completeness API) |
| External callers | **1** — `FUN_00402dd0` |
| Site role | list resize grow / insert-N before head |
| Callees | `FUN_004040f0` only |
| Node size | **0xC** dword value |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| `"list<T> too long"` on Incsize callee | **Yes** (shared list family) |
| Circular head/prev rewire on insert-one | **Yes** |
| BuyNode 0xC dword payload | **Yes** |
| Product mission English inside this VA | **No** |
| Scaffold `Named_CalleeOf_Client_DebugListMissionsStatus_*` | **Rejected** (parent seed only) |

Name uses **`_Inferred`**: STL role sealed; CRT demangle / exact template spelling open.

---

## 7. Gaps

1. Product demangle of exact `std::list<…>::_Insert` specialization.
2. Dual seal of insert-one `FUN_004040f0` / BuyNode `FUN_00418700` (used as evidence only here).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/RET0xC/sole caller/list insert-N dword sealed; product demangle + callee duals open.
