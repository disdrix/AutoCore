# Review A (reconstruction fidelity): `aa_0040b440` StdTree_EraseAndRebalance_Val12_RetC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b440` |
| **VA** | `0x0040b440` |
| **Body** | `0x0040b440`–`0x0040b6d0` exclusive (**656** B / `0x290`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Val12_RetC_Inferred` |
| **Ghidra name** | `FUN_0040b440` |
| **Review date** | `2026-08-05` (R13-018 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` |
| **System** | inventory-transfer — MSVC `std::_Tree` erase + RB rebalance (Val12 / isnil@+0x19); **stack ret 0xC** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node (isnil@+0x19, color@+0x18, node size 0x1C): nil-iterator throw, capture successor via iterator++ isnil19 (`FUN_00457cc0`), unlink (incl. two-child successor-swap), rebalance if erased black, free node (no value dtor), size--, write out-iterator. **3 stack args + `ret 0xC`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-018 re-verify) | `docs/reconstruction/raw/aa_0040b440_FUN_0040b440.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b440_FUN_0040b440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12_RetC_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0040b440.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` |
| Live body | `read_memory` entry + epilogue through `ret 0xC`; string @ `0x00a152f0` |
| Callers | `FUN_0040bc10` @ `0x0040bcae`; `FUN_0092b2a0` @ `0x0092b741` |
| Parent dual | `MissionTracker_FillTrackedTargetSlots_Inferred` @ `0x0092b2a0` |
| Succ dual | `StdTree_IteratorIncrement_Isnil19` @ `0x00457cc0` (W38-B) |
| Thiscall peer (do not merge) | `StdTree_EraseAndRebalance_Val12` @ `0x004e4130` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack0 | MapShell* | prolog loads EBP from stack; uses `EBP+4` head, `EBP+8` size |
| stack1 | outIt** | epilogue `mov eax,[esp+0x5c]; mov [eax],edx` |
| stack2 | node* | early `MOV EAX,[ESP+0x18]`; isnil check `+0x19` |
| cleanup | **`ret 0xC`** | `C2 0C 00` @ `0x0040b6cd` |
| Call sites | 3× PUSH | `0040bcae`, `0092b741` (`get_assembly_context`) |

**Not** thiscall RET 8 (contrast `0x004e4130` / isnil21 erase `0x00405650`).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 0xC` | **High** | bytes past false noreturn |
| Single-node erase (not range) | **High** | range is caller `FUN_0040bc10` loop |
| isnil@+0x19 / color@+0x18 (Val12) | **High** | opcodes `80 78 19 00`, color `@+0x18` |
| Throw plate | **High** | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| size-- when size>0 | **High** | epilogue `test eax; jbe; add -1; mov [ebp+8]` |
| Succ via iterator++ isnil19 | **High** | `CALL FUN_00457cc0` |
| Min/max extremity fix | **High** | `0043bf90` / `0040b8f0` |
| L/R rotate this clone | **High** | `00446b10` / `0040b910` |
| No value dtor | **High** | bare `operator_delete` only |
| Stack RET 0xC (not thiscall RET 8) | **High** | `C2 0C 00` + 3× PUSH sites |
| Product map English name | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; never Runtime Confirmed |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil throw | **Yes** |
| successor prep `FUN_00457cc0` | **Yes** |
| unlink + extremity fix (min/max) | **Yes** |
| two-child successor-swap @ `0x0040b539` | **Yes** (bytes; decomp "unreachable") |
| RB rebalance if black | **Yes** |
| delete + size-- + *outIt + ret 0xC | **Yes** (bytes seal epilogue) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| color/isnil match Val12 family (+0x18/+0x19) | **Yes** |
| Stack RET 0xC (ABI-distinct from thiscall Val12 erase) | **Yes** |
| No string/value dtor | **Yes** |
| Product/PDB English host type | **No** |
| inventory-transfer system assignment | Partition map R13-018 only (structural role is generic STL erase) |

**Decision:** promote **`StdTree_EraseAndRebalance_Val12_RetC_Inferred`**. Reject freelist; reject merge with thiscall Val12 erase `004e4130`; reject isnil21/29/31 erase; reject void/noreturn-on-delete as full body; reject inventing product map English from MissionTracker parent alone.

---

## 7. Gaps

1. Product/PDB demangle for host map type / value payload English (Val12 fields).
2. Dual of erase-range parent `FUN_0040bc10`, min `0043bf90`, max `0040b8f0`, L/R rotates.
3. Full two-child successor-swap plate fidelity (decomp unreachable warnings).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
