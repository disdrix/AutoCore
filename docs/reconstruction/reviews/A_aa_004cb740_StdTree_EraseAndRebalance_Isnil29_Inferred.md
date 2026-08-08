# Review A (reconstruction fidelity): `aa_004cb740` StdTree_EraseAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb740` |
| **VA** | `0x004cb740` |
| **Body** | `0x004cb740`–`0x004cb9f5` exclusive (**693 B** / `0x2B5`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_004cb740` |
| **Prior / alias** | `Named_CalleeOf_…_VOG_DEBUG_STOP_004cb740` (**narrow**) |
| **Review date** | `2026-08-04` (WQ9E-E OWN-ONLY dual) |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` |
| **System** | std map/set tree erase + RB rebalance (isnil@+0x29) |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function`, `read_memory`, `analyze_function_complete`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase one isnil@+0x29 red-black tree node: throw on nil iterator, unlink + extremity fix (min/max isnil29), rebalance if erased black (L/R rotate isnil29), delete node, size--, write `*outIt`.

```c
void __thiscall StdTree_EraseAndRebalance_Isnil29_Inferred(
    MapShell* map, Node** outIt, Node* node); // RET 8
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cb740_FUN_004cb740.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb740_FUN_004cb740.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004cb740.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` |
| Live decompile | ≡ raw CF; epilogue from bytes |
| Min / Max / rotates | WQ9D duals `0051b5d0`, `00421b50`, `004192a0`, `004192f0` |
| Peer erase | `StdTree_EraseAndRebalance_Val12` @ `0x004e4130` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | SEH `LAB_009a1e42`; `cmp byte [node+0x29], 0` (`80 78 29 00`) |
| String | `"invalid map/set<T> iterator"` |
| ThrowInfo | `DAT_00acc34c` |
| Epilogue | `operator_delete` → size-- → `*outIt` → `add esp,0x54; ret 8` |
| Body exclusive end | `0x004cb9f5` (pad `CC` after) |
| Color / isnil | +0x28 / +0x29 |

Epilogue tail hex:

```
8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body exclusive end incl. epilogue | **pass** (`004cb9f5`) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** |
| isnil throw string | **pass** |
| size-- after delete | **pass** (bytes; decomp miss) |
| RB uses isnil29 L/R rotate | **pass** |
| Min/max isnil29 extremities | **pass** |
| Clean meaningful names | **pass** |
| Product demangle of map | **gap** |
| `FUN_004cb270` product name | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8 sealed |
| isnil@+0x29 node layout | **High** | match min/max/rotates + buynode twin |
| Callers (3) | **High** | xrefs sealed |
| Name `…_Isnil29_Inferred` | **Inferred** | structural; not plate/RTTI |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map value_type of callers.  
2. Exact English for `FUN_004cb270` (successor).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
