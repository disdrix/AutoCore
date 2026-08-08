# Review A (reconstruction fidelity): `aa_0040b3b0` StdTree_ConstructEmpty_Isnil19_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b3b0` |
| **VA** | `0x0040b3b0` |
| **Body** | `0x0040b3b0`–`0x0040b40a` exclusive (**90** B / `0x5A`) |
| **Canonical name** | `StdTree_ConstructEmpty_Isnil19_Inferred` |
| **Ghidra name** | `FUN_0040b3b0` |
| **Review date** | `2026-08-05` (R13-017 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md` |
| **System** | inventory-transfer (partition) — MSVC `std::_Tree` empty construct isnil@+0x19 |
| **Parent dual** | `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred (R12-008) |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Finish **empty tree** construction for the **isnil@+0x19 / 0x1c** family: buy blank head (`FUN_0040bfc0`), install as `_Myhead`, force isnil=1, self-link extremities, zero size. **`__stdcall` + `ret 4`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-017 re-verify) | `docs/reconstruction/raw/aa_0040b3b0_FUN_0040b3b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b3b0_FUN_0040b3b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil19_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0040b3b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ entry/`0x0040b407` → `C2 04 00` |
| Head buy | residual `FUN_0040bfc0` (`operator_new(0x1c)`) — not dualled OWN |
| Caller | parent `FUN_0092b2a0` @ `0x0092b319` (`LEA EAX,[ESP+0x38]; PUSH; CALL`) |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack0 | shell* | `MOV ESI,[ESP+0x14]` after SEH + push esi |
| ECX | unused as this | not thiscall |
| cleanup | **`ret 4`** | `C2 04 00` @ `0x0040b407` |
| return | shell* in EAX | `MOV EAX,ESI` before epilogue |
| Call site | 1× PUSH shell | `0092b319` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 90 B + `ret 4` | **Confirmed** (static) | disasm + epilogue bytes |
| `__stdcall` 1 stack arg; returns shell* | **Confirmed** (static) | ESI from stack; EAX=ESI |
| Calls buyhead `0040bfc0` | **Confirmed** (static) | sole callee; `operator_new(0x1c)` |
| isnil@+0x19 = 1 | **Confirmed** (static) | `C6 40 19 01` |
| Self-link L/P/R | **Confirmed** (static) | three stores of head to L/P/R |
| size@+8 = 0 | **Confirmed** (static) | `C7 46 08 00 00 00 00` |
| Sole caller parent MissionTracker fill | **Confirmed** (static) | 1 xref @ `0092b319` |
| SEH frame present | **Confirmed** (static) | FS:[0] / `LAB_009bda98` |
| Product map English | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; never Runtime Confirmed |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → buyhead | **Yes** |
| install head / isnil1 / self-link / size0 | **Yes** |
| return shell; RET 0x4 | **Yes** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x19 + buyhead 0x1c | **Yes** |
| Classic empty-tree head install CF | **Yes** |
| Peer plate match ConstructEmpty isnil31 `00405f20` (same shape, different isnil) | **Yes** |
| Product/PDB English for map value_type | **No** |
| inventory-transfer system assignment | Partition map R13-017 only (structural role is generic STL construct) |

**Decision:** promote **`StdTree_ConstructEmpty_Isnil19_Inferred`**. Reject MissionTracker product method name; reject thiscall; reject merge with isnil21/29/2d/31 ConstructEmpty; reject claiming full buyhead lives in this body.

---

## 7. Gaps

1. Product key/value type for stack-local shell under MissionTracker secondary fill.
2. Dual of residual buyhead `FUN_0040bfc0` (and sibling helpers `0040b440`/`0040b890`/`0040bc10` — other R13 OWN slots).
3. Shell+0 allocator/comp identity.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
