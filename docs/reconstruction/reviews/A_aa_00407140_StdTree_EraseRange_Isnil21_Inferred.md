# Review A (reconstruction fidelity): `aa_00407140` StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407140` |
| **VA** | `0x00407140`–`0x004071f4` exclusive (**180 B** / `0xB4`) |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_00407140` |
| **Review date** | `2026-08-05` (R13-016 OWN dual; dual start **2686**) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md` |
| **System** | skills-abilities — MSVC `std::_Tree` range erase (isnil@+0x21) |
| **Parent dual** | `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC `_Tree::erase(first, last)` for isnil@+0x21 nodes: full-clear free-subtree + head reset, or partial successor + single erase via dualed `StdTree_EraseAndRebalance_Isnil21_Inferred`. Writes `*outIt`.

```c
void __thiscall StdTree_EraseRange_Isnil21_Inferred(
    MapShell* map, Node** outIt, Node* first, Node* last); // RET 0x0C
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-016 re-verify) | `docs/reconstruction/raw/aa_00407140_FUN_00407140.md` |
| Annotated | `docs/reconstruction/raw/aa_00407140_FUN_00407140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00407140.cpp` |
| Function record | `docs/reconstruction/functions/aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF; ret 0xc both exits from bytes |
| Single erase | R12-009 `StdTree_EraseAndRebalance_Isnil21_Inferred` @ `0x00405650` |
| Peer ranges | isnil29 `0x004cbaa0`; isnil11 `0x00441960`; Map_EraseRange* |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden. **Runtime Confirmed not claimed.**

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `53 8B 5C 24 10 56 8B 74 24 10 57 8B F9` |
| Full-clear free | `CALL 0x00406710` @ `0x0040715c` |
| Single erase | `MOV ECX,EDI; CALL 0x00405650` @ `0x004071dd`–`0x004071df` |
| isnil | `80 7E 21 00` / `80 78 21 00` successor immediates |
| Epilogue full | `5F 5E 89 10 5B C2 0C 00` |
| Epilogue partial | `5F 89 30 5E 5B C2 0C 00` |
| Body exclusive end | `0x004071f4` (pad `CC`) |

---

## 4. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | MapShell* | prolog `MOV EDI,ECX`; call sites `MOV ECX,ESI` / `MOV ECX,EDI` |
| stack0 | outIt** | epilogue `mov eax,[esp+0x10]; mov [eax],…` |
| stack1 | first* | `MOV ESI,[ESP+0x10]` after pushes |
| stack2 | last* | `MOV EBX,[ESP+0x10]` early |
| cleanup | **`ret 0xc`** | `C2 0C 00` both exits |
| Call sites | 3× PUSH + ECX | `004052c3`, `00405632`, `00500162` |

---

## 5. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body 180 B / ret 0x0c both exits | **pass** |
| thiscall ECX=map | **pass** |
| Full clear begin/end gate | **pass** |
| Free `FUN_00406710` | **pass** |
| Partial uses isnil21 erase `00405650` | **pass** |
| Distinct from isnil29 range / Map_EraseRange* | **pass** |
| Clean meaningful names | **pass** |
| Product demangle of map | **gap** |
| Free-subtree full algebra | **gap** |
| Runtime / bit-exact | **gap** (not Runtime Confirmed) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI RET 0x0C | **High** | live ≡ raw; `read_memory` |
| isnil@+0x21 successor | **High** | immediates |
| Callers / 3 xrefs | **High** | bulk xrefs + assembly context |
| Pairs with erase dual `00405650` | **High** | parent R12-009 |
| Name `…_Isnil21_Inferred` | **Inferred** | structural; product English open |
| Runtime / differential | Open | deferred — **never Runtime Confirmed** |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| Full-clear + partial range CF plate | **Yes** |
| isnil@+0x21 match isnil21 family | **Yes** |
| Thiscall RET 0xC (range) pairs erase RET 8 | **Yes** |
| Free/erase callee pair sealed | **Yes** |
| Product/PDB English host type | **No** |
| skills-abilities system assignment | Partition map R13-016 (structural role is generic STL range erase) |

**Decision:** promote **`StdTree_EraseRange_Isnil21_Inferred`**. Reject merge with isnil29/isnil11/Map_EraseRange*; reject single-node-only; reject inventing product map English from tidy/host callers alone.

---

## 8. Gaps

1. Product/PDB demangle for host map type / value payload English.  
2. Dual of free-subtree residual `FUN_00406710` (left-recurse decomp residual).  
3. Runtime / bit-exact / image differential.

**Verdict:** **accept-with-gaps**
