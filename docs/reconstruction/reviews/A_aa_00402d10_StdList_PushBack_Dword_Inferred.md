# Review A (reconstruction fidelity): `aa_00402d10` StdList_PushBack_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d10` |
| **VA** | `0x00402d10`–`0x00402d41` (**50 B** / `0x32`) |
| **Canonical name** | `StdList_PushBack_Dword_Inferred` |
| **Ghidra name** | `FUN_00402d10` |
| **Prior alias** | `Named_CalleeOf_Client_DebugListMissionsStatus_00402d10` (**retired** — parent-seed only) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **MEGA-126** Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00402d10_StdList_PushBack_Dword_Inferred.md` |
| **System** | shared MSVC `std::list` (partition hint: missions-progression / DebugListMissionsStatus nested) |
| **Live tools** | GhidraMCP `decompile_function` / `analyze_function_complete` / `disassemble_function` / `read_memory` / callers / xrefs / callees (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Terminal** | **false** (no runtime Confirmed) |

---

## 1. Purpose

MSVC-shaped **`std::list` push_back** of a **dword-sized** element:

1. `head = *(list + 4)` — `_Myhead` sentinel.
2. `node = FUN_00418700(head, head->_Prev, pValue)` — `operator_new(0xC)`:
   - `node->_Next = head`
   - `node->_Prev = head->_Prev`
   - `node->_Myval = *pValue`
3. `FUN_00404840(list, 1)` — `_Incsize(1)`; overflow throws `"list<T> too long"`.
4. Splice as new tail: `head->_Prev = node`; `old_prev->_Next = node`.

Shared helper (not mission-only): Debug mission list, reaction/item give, and `FUN_0057ade0` all call it.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x00402d10` (2026-08-05) ≡ raw 2026-07-23 |
| Live complete | `analyze_function_complete` — 7 xrefs; callees BuyNode+Incsize |
| Live disasm | `disassemble_function` — full body through `RET 4` |
| Live bytes | `read_memory` length 50 — hex seal in raw append |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402d10_FUN_00402d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00402d10_FUN_00402d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushBack_Dword_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00402d10.cpp` |
| Function records | `functions/aa_00402d10_FUN_00402d10.md` + named |
| Callee decompiles | `FUN_00418700` (new 0xC), `FUN_00404840` (`list<T> too long`) |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff, product PDB.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00402d10`–`0x00402d41` (50 B) | **High / Sealed** | `get_function_by_address` + disasm + bytes |
| `__thiscall` ECX=list*, stack=`const T*`, **`RET 4`** | **High / Sealed** | `8B F1`; `8B 44 24 04`; `C2 04 00` |
| Head at `list+4`; size at `list+8` (via Incsize) | **High / Sealed** | body + `FUN_00404840` |
| Node 0xC: Next@0 Prev@4 Myval@8 | **High / Sealed** | BuyNode stores; parent walks `*node` / `node[2]` |
| Insert before sentinel = **push_back** | **High / Sealed** | `head->Prev` + `old_prev->Next` rewire |
| Incsize overflow string path | **High / Sealed** | `"list<T> too long"` @ `0x00a1581c` / ThrowInfo `acc388` |
| 7 call sites / 3 parents | **High / Sealed** | live xrefs |
| Shared (not DebugList-only) | **High / Sealed** | 2 non-mission parents |
| Product element type English | **Tentative** | `_Inferred` |
| Null-new safety | **Open** | BuyNode may return 0; body links anyway |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load head `*(list+4)` | **Yes** |
| BuyNode(head, head->Prev, pValue) | **Yes** |
| Incsize(1) with ECX=list | **Yes** (asm; decompiler elides this) |
| `head->Prev = node` | **Yes** |
| `old_prev->Next = node` | **Yes** |
| `RET 4` | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product C++ `T` / list typedef English (shared across mission*, item*, …).
2. Dual residual of `FUN_00418700` (BuyNode twin of dualed `StdList_BuyNode_Dword` `0x006759b0`).
3. Dual residual of `FUN_00404840` (Incsize twin of dualed `StdList_Incsize` `0x0043fe60`).
4. Null-`operator_new` crash vs guarded.
5. Runtime / differential verification.

**Verdict:** CF + ABI + layout + push_back role sealed from live decompile + disasm + `read_memory` + callees/callers. Product `T` open. **accept-with-gaps.**
