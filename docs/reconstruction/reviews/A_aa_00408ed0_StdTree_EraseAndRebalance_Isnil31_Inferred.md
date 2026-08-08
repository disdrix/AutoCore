# Review A (reconstruction fidelity): `aa_00408ed0` StdTree_EraseAndRebalance_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408ed0` |
| **VA** | `0x00408ed0` |
| **Body** | `0x00408ed0`–`0x00409160` exclusive (**656** B / `0x290`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil31_Inferred` |
| **Ghidra name** | `FUN_00408ed0` |
| **Review date** | `2026-08-05` (WQ9K-E OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md` |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x31) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node (isnil@+0x31, color@+0x30, node size 0x38): nil-iterator throw, capture successor via iterator++ isnil31, unlink, rebalance if erased black, free node (no value dtor), size--, write out-iterator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9K-E re-verify) | `docs/reconstruction/raw/aa_00408ed0_FUN_00408ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00408ed0_FUN_00408ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil31_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00408ed0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md` |
| Live body | `read_memory` entry/epilogue; string @ `0x00a152f0` |
| Caller | `FUN_00407cb0` + assembly context @ `0x00407d4e` |
| Min peer | dual `StdTree_Min_Isnil31` @ `0x00409160` (WQ9J-E) |
| Iter peer | dual `StdTree_IteratorIncrement_Isnil31` @ `0x00408590` (WQ9H-H) |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack0 | MapShell* | decompile `param_1+4` head / `+8` size; caller PUSH ECX |
| stack1 | outIt** | epilogue `mov [eax], edx` |
| stack2 | node* | early load; isnil check `+0x31` |
| cleanup | **`ret 0x0C`** | `C2 0C 00` @ `0x0040915d` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 0x0C` | **Confirmed** | bytes past false noreturn |
| Single-node erase (not range) | **Confirmed** | range is caller `FUN_00407cb0` loop |
| isnil@+0x31 / color@+0x30 | **Confirmed** | opcodes + recolor path |
| Throw plate | **Confirmed** | `"invalid map/set<T> iterator"` |
| size-- when size>0 | **Confirmed** | epilogue `test eax; jbe; add -1; mov [ebp+8]` |
| Succ via iterator++ isnil31 | **Confirmed** | `CALL FUN_00408590` |
| Min/max extremity fix | **Confirmed** | `00409160` / `004043e0` |
| No string key dtor | **Confirmed** | bare `operator_delete` only |
| Product map English name | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil throw | **Yes** |
| successor prep `FUN_00408590` | **Yes** |
| unlink + extremity fix (min/max) | **Yes** |
| RB rebalance if black | **Yes** (decomp may mark mid blocks unreachable) |
| delete + size-- + *outIt + ret 0xC | **Yes** (bytes seal epilogue) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| color/isnil match isnil31 family (min/iter/head peers) | **Yes** |
| No string dtor (contrast StringKey isnil2d) | **Yes** |
| Product/PDB English host type | **No** |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil31_Inferred`**. Reject freelist; reject isnil29/isnil2d erase merge; reject void/noreturn-on-delete as full body.

---

## 7. Gaps

1. Product/PDB demangle for host map type / value payload English.
2. Dual of erase-range parent `FUN_00407cb0` and rotate/max helpers.
3. Full two-child successor-swap plate fidelity (decomp unreachable warnings).
4. Runtime / bit-exact / image diff.
