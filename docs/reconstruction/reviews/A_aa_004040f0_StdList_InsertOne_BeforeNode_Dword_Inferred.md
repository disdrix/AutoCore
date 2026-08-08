# Review A (reconstruction fidelity): `aa_004040f0` StdList_InsertOne_BeforeNode_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004040f0` |
| **VA** | `0x004040f0`–`0x00404122` inclusive (**51 B** / `0x33`) |
| **Canonical name** | `StdList_InsertOne_BeforeNode_Dword_Inferred` |
| **Ghidra name** | `FUN_004040f0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugListMi_004040f0` (**retired**) |
| **Review date** | `2026-08-05` (OWN-ONLY dual **R10-005**) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` |
| **System** | shared MSVC `std::list` (missions-progression partition hint only) |
| **Live tools** | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_function_by_address` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Terminal** | **false** (no runtime Confirmed) |

**Avoided:** `disassemble_bytes`; Launcher; parent ledgers; dualling other VAs.

---

## 1. Purpose

MSVC-shaped **`std::list` insert-one before node** for **dword** payload nodes (size **0xC**):

```text
StdList_InsertOne_BeforeNode_Dword(list, where, val*)
  node = BuyNode(where, where->_Prev, val*)   // FUN_00418700 → operator_new(0xC)
  _Incsize(list, 1)                           // FUN_00404840; may throw "list<T> too long"
  where->_Prev = node
  node->_Prev->_Next = node
```

Shared STL helper. Nested under `Client_DebugListMissionsStatus` only via resize/insert parents — **not** mission product logic. Specialized twin: push_back @ `0x00402d10` hardcodes `where = head`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (buy → inc → rewire); this/Incsize corrected via asm |
| Full body | `disassemble_function` + `read_memory` **51 B** hex sealed |
| BuyNode | dualed `StdList_BuyNode_Dword_Seh` @ `0x00418700` |
| Incsize | `FUN_00404840` max `0x3fffffff`, string `"list<T> too long"` |
| Callers | `FUN_004034c0` (InsertN), `FUN_00404560` (insert-range), orphan `0x004cd020` |
| Clean | `reconstructed-exact/StdList_InsertOne_BeforeNode_Dword_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_004040f0.cpp` |
| Raw (+ re-verify) | `raw/aa_004040f0_FUN_004040f0.md` |
| Annotated | `raw/aa_004040f0_FUN_004040f0.annotated.md` |

---

## 3. Signature (sealed)

```c
// ECX=list*; stack where*, val*; void; RET 0x8
void __thiscall StdList_InsertOne_BeforeNode_Dword_Inferred(
    StdListHeaderDword *list /*ECX*/,
    StdListNodeDword *where,
    const uint32_t *val);
```

| Formal | Source | Conf |
|---|---|---|
| list* | entry **ECX** → EDI; reloaded for Incsize | **Confirmed** |
| where* | stack `[ESP+4]` → EBX | **Confirmed** |
| val* | stack `[ESP+8]` → EAX (pushed to BuyNode) | **Confirmed** |
| cleanup | `RET 0x8` (`C2 08 00`) | **Confirmed** |
| return | void | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| BuyNode(where, where->prev, val) | **Yes** | **Confirmed** |
| Incsize(list, 1) with ECX=list | **Yes** (asm; decompiler elides this) | **Confirmed** |
| where->prev = node | **Yes** | **Confirmed** |
| node->prev->next = node | **Yes** | **Confirmed** |
| RET 0x8 | **Yes** | **Confirmed** |
| Insert **before** where (not after) | **Yes** | **Confirmed** |
| Node 0xC dword payload | **Yes** (BuyNode family) | **Confirmed** |
| No modernization | **Yes** | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** (completeness API) |
| External CALL xrefs | **3** UNCONDITIONAL_CALL |
| Named callers | `FUN_004034c0` (InsertN loop), `FUN_00404560` (insert-range) |
| Orphan | `0x004cd020` (no function) |
| Callees | `FUN_00418700`, `FUN_00404840` |
| Node size | **0xC** dword value |

Caller `004034c0` site (asm):
```text
PUSH val* / PUSH where / MOV ECX,list / CALL 004040f0
```

Caller `00404560` site:
```text
LEA EAX,[ESI+8] / PUSH EAX / PUSH EDI / MOV ECX,EBX / CALL 004040f0
; ESI walks source list nodes; val = &node->_Myval
```

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| BuyNode 0xC + Incsize + before-where splice | **Yes** |
| Match push_back twin CF with free `where` | **Yes** |
| `"list<T> too long"` via Incsize | **Yes** |
| Multi-caller shared helper (not DebugList-only) | **Yes** |
| Product demangle string in body | **No** |

**Decision:** promote **`StdList_InsertOne_BeforeNode_Dword_Inferred`**. Reject `Named_CalleeOf_*DebugList*`. Reject vector/tree insert. `_Inferred` for CRT demangle spelling.

---

## 7. Gaps / open

1. Exact CRT / demangle spelling for list `_Insert` specialization.
2. Product element type English beyond dword-sized payload.
3. Null `operator_new` path: BuyNode may return 0; body still rewires (same residual as push_back dual).
4. Dual seal of Incsize `00404840` (string path High; formal dual residual).
5. Runtime / bit-exact / differential (no Launcher).

**Verdict:** **accept-with-gaps**
