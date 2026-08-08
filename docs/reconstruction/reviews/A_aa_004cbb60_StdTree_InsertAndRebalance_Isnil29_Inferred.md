# Review A (reconstruction fidelity): `aa_004cbb60` StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbb60` |
| **VA** | `0x004cbb60` |
| **Body** | `0x004cbb60`–`0x004cbd4b` exclusive (**491 B** / `0x1EB`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_004cbb60` |
| **Prior / alias** | `Named_CalleeOf_…_GetTargetFromAggro_004cbb60` (**narrow**) |
| **Review date** | `2026-08-04` (WQ9E-E OWN-ONLY dual) |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| **System** | std map/set tree always-insert + RB rebalance (isnil@+0x29) |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function`, `read_memory`, `analyze_function_complete`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert one node into an isnil@+0x29 red-black tree: length guard, buynode (0x30 / 6-dword value), link left/right of hint, RB rebalance, write `*outIt`.

```c
void __thiscall StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShell* map, Node** outIt, char addLeft, Node* where, const Val24* value);
// RET 0x10
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004cbb60.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| Live decompile | ≡ raw CF |
| Buynode | `FUN_005a2de0` live decompile (0x30, isnil@+0x29) |
| Rotates | WQ9D `004192a0` / `004192f0` |
| Peer insert | `StdTree_InsertAndRebalance_Val12` @ `0x005ae4e0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | SEH `LAB_009a1e42`; size compare vs `0xAAAAAA8` family |
| String | `"map/set<T> too long"` |
| ThrowInfo | `DAT_00acc388` |
| Buynode | `FUN_005a2de0` / `operator_new(0x30)`; value 6 dwords @ +0x10; color@+0x28; isnil=0@+0x29 |
| Epilogue | root black + `*outIt`; **`C2 10 00`** RET 16 |
| Body exclusive end | `0x004cbd4b` (pad `CC` after) |

Exit hex:

```
83c450c21000cccccccccc
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** |
| length throw string | **pass** |
| size++ after buynode | **pass** |
| RB uses isnil29 L/R (+ one inlined L) | **pass** |
| Clean meaningful names | **pass** |
| Product demangle of map | **gap** |
| Parent key-compare walk | **out of scope** (callers) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 sealed |
| Node 0x30 / isnil@+0x29 | **High** | buynode sealed |
| Max size `0xAAAAAA8` | **High** | decompile + entry cmp |
| Callers / 11 xrefs | **High** | xrefs sealed |
| Name `…_Isnil29_Inferred` | **Inferred** | structural |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map value_type of `FUN_004cc220` family.  
2. Full semantic of parent insert-or-find shells.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
