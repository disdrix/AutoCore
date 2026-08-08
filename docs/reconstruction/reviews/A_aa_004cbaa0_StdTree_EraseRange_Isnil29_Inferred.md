# Review A (reconstruction fidelity): `aa_004cbaa0` StdTree_EraseRange_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbaa0` |
| **VA** | `0x004cbaa0`–`0x004cbb54` exclusive (**180 B** / `0xB4`) |
| **Canonical name** | `StdTree_EraseRange_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_004cbaa0` |
| **Prior / alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cbaa0` (**narrow**) |
| **Review date** | `2026-08-04` (WQ9F-C OWN-ONLY dual) |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` |
| **System** | std map/set range erase (isnil@+0x29) |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function`, `read_memory`, `analyze_function_complete`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC `_Tree::erase(first, last)` for isnil@+0x29 nodes: full-clear free-subtree + head reset, or partial successor + single erase via dualed `StdTree_EraseAndRebalance_Isnil29_Inferred`. Writes `*outIt`.

```c
void __thiscall StdTree_EraseRange_Isnil29_Inferred(
    MapShell* map, Node** outIt, Node* first, Node* last); // RET 0x0C
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004cbaa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` |
| Live decompile | ≡ raw CF; ret 0xc both exits from bytes |
| Single erase | WQ9E-E `StdTree_EraseAndRebalance_Isnil29_Inferred` @ `0x004cb740` |
| Peer ranges | `Map_EraseRange` `0x0051c7c0`, `Map_EraseRange_B` `0x0051d880` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `53 8B 5C 24 10 56 8B 74 24 10 57 8B F9` |
| Full-clear free | `CALL 0x004cb550` @ `0x004cbabc` (rel from bytes) |
| Single erase | `MOV ECX,EDI; CALL 0x004cb740` @ `0x004cbb3f` |
| isnil | `80 ?? 29 00` successor immediates |
| Epilogue full | `5F 5E 89 10 5B C2 0C 00` |
| Epilogue partial | `… 5F 89 30 5E 5B C2 0C 00` |
| Body exclusive end | `0x004cbb54` (pad `CC`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body 180 B / ret 0x0c both exits | **pass** |
| thiscall ECX=map | **pass** |
| Full clear begin/end gate | **pass** |
| Free `FUN_004cb550` | **pass** |
| Partial uses isnil29 erase `004cb740` | **pass** |
| Distinct from Map_EraseRange free/erase pair | **pass** |
| Clean meaningful names | **pass** |
| Product demangle of map | **gap** |
| Free-subtree full algebra | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI RET 0x0C | **High** | live ≡ raw; bytes |
| isnil@+0x29 successor | **High** | immediates |
| Callers / 6 xrefs | **High** | bulk xrefs |
| Name `…_Isnil29_Inferred` | **Inferred** | structural; pairs erase dual |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map value_type.  
2. Complete free-subtree of `FUN_004cb550` (left recurse residual).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
