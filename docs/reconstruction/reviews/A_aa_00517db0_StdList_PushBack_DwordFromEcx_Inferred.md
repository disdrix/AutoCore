# Review A (reconstruction fidelity): `aa_00517db0` StdList_PushBack_DwordFromEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517db0` |
| **VA** | `0x00517db0`–`0x00517de9` (**58 B** / `0x3A`) |
| **Canonical name** | `StdList_PushBack_DwordFromEcx_Inferred` |
| **Ghidra name** | `FUN_00517db0` |
| **Review date** | `2026-08-05` (OWN-ONLY dual **R10-032** Path A — fidelity) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| **System** | shared MSVC `std::list` (partition hint: missions-progression / parent BuyNode `0x00418700`) |
| **Live tools** | Ghidra `decompile_function` / `analyze_function_complete` / `get_function_by_address` / `read_memory` / callers / xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Terminal** | **false** (no runtime Confirmed) |

---

## 1. Purpose

MSVC-shaped **`std::list` push_back** of a **dword** whose value is the **incoming ECX** register (typically the caller's adjusted `this` for multi-class virtual register-on-list):

1. `list = stack arg0`; `head = list->_Myhead` (`list+4`).
2. Spill `ECX` to stack; `node = FUN_00418700(head, head->_Prev, &ecx_slot)` — 0xC BuyNode.
3. `FUN_00404840(list, 1)` — `_Incsize(1)`; may throw `"list<T> too long"`.
4. Splice as new tail: `head->_Prev = node`; `old_prev->_Next = node`.

Shared helper (not mission-only): five code parents + many DATA vtable slots.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` @ `0x00517db0` (2026-08-05) ≡ raw 2026-07-23 CF |
| Live complete | `analyze_function_complete` — worker; callees BuyNode+Incsize; 5 callers; 23 xrefs |
| Live bounds | `get_function_by_address` — body `00517db0`–`00517de9` |
| Live bytes | `read_memory` length 64 — hex seal 58 B through `RET 4` + `CC` pad |
| Parent callers | decompile `004c30d0` / `004f46c0` / `00562fa0` / `00587680` / bytes `00569ba0` |
| Callee duals | `aa_00418700` BuyNode SEH; `aa_00404840` Incsize thiscall (R10-006) |
| Sibling dual | `aa_00402d10` PushBack_Dword (ECX=list) |
| Raw / annotated / clean | R10-032 trio |

**Not performed:** `disassemble_bytes` (policy), Launcher, parent ledgers, bit-exact image diff, product PDB.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00517db0`–`0x00517de9` (58 B) | **Confirmed** | `get_function_by_address` + hex through `C2 04 00` + `CC` pad |
| Stack `list*`; **ECX = value dword**; **`RET 4`** | **Confirmed** | `MOV EBX,[ESP+0xC]` after prolog; `PUSH ECX` value spill; epilogue `C2 04 00` |
| Head at `list+4`; size via Incsize at `list+8` | **Confirmed** | body + dualed `FUN_00404840` |
| Node 0xC: Next@0 Prev@4 Myval@8 = ECX | **Confirmed** | BuyNode dual + spill path |
| Insert before sentinel = **push_back** | **Confirmed** | `head->Prev` + `old_prev->Next` rewire |
| Incsize overflow string path | **Confirmed** | dualed callee R10-006 |
| 5 code parents + multi DATA vtable | **Confirmed** | live xrefs |
| Shared (not mission-exclusive) | **Confirmed** | multi-parent + vtable fan-out |
| Product element type English | **Open** | `_Inferred` |
| Null-new safety | **Open** | BuyNode may return 0; body links anyway |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load head `*(list+4)` | **Yes** |
| Spill ECX → BuyNode(head, head->Prev, &slot) | **Yes** (bytes win over "uninit local") |
| Incsize(1) with ECX=list | **Yes** (`MOV ECX,EBX` before CALL) |
| `head->Prev = node` | **Yes** |
| `old_prev->Next = node` | **Yes** |
| `RET 4` | **Yes** |
| No modernization | **Yes** |

### Sealed CF sketch

```
// ECX = value; stack = list*
head = list->_Myhead
value = ECX
node = BuyNode(head, head->_Prev, &value)   // 0x00418700
Incsize(list, 1)                            // 0x00404840
head->_Prev = node
node->_Prev->_Next = node
return; // RET 4
```

---

## 5. Gaps

1. Product C++ `T` / list typedef English (shared across many classes).
2. Full ownership map of DATA vtable slots that point at this body.
3. Null-`operator_new` crash vs guarded (matches BuyNode residual).
4. Runtime / differential verification.

**Verdict:** CF + ABI + layout + push_back role sealed from live decompile + `read_memory` + callees/callers. Product `T` open. **accept-with-gaps.**
