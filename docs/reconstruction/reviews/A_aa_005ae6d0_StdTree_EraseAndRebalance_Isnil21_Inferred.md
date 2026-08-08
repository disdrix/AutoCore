# Review A (reconstruction fidelity): `aa_005ae6d0` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae6d0` |
| **VA** | `0x005ae6d0` |
| **Body** | `0x005ae6d0`–`0x005ae986` exclusive (**694 B** / `0x2B6`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005ae6d0` |
| **Review date** | `2026-08-05` (R12-035 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | MSVC std `_Tree` erase + RB rebalance (isnil@+0x21) |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → R12-035 |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one isnil@+0x21 red-black tree node: throw on nil iterator, unlink + extremity fix (min/max isnil21), rebalance if erased black (L/R rotate isnil21), delete node, size--, write `*outIt`.

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell* map, Node** outIt, Node* node); // RET 8
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-035 re-verify) | `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005ae6d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF; epilogue from bytes |
| Parent Rrotate | `StdTree_Rrotate_Isnil21_Inferred` @ `0x005a27f0` (R11-007) |
| Lrotate twin | `StdTree_Lrotate_Isnil21_Inferred` @ `0x0050e9f0` (R10-030) |
| Peer erase | `StdTree_EraseAndRebalance_Isnil29_Inferred` @ `0x004cb740` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | SEH `LAB_009a65a2`; `cmp byte [node+0x21], 0` (`80 78 21 00`); `MOV EBP,ECX` |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| ThrowInfo | `DAT_00acc34c` |
| Color / isnil | +0x20 / +0x21 |
| Epilogue | `operator_delete` → size-- → `*outIt` → `add esp,0x54; ret 8` |
| RET | `C2 08 00` @ `0x005ae983` |
| Inclusive end | `0x005ae985`; exclusive `0x005ae986`; `CC` pad; next func `0x005ae990` |
| Body size | **694** B |
| Call site | `0x005af37f`: `MOV ECX,EDI` + `CALL 0x005ae6d0` |

Epilogue tail hex (from `0x005ae94d`):

```
8b44241050e8cbaeedff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body exclusive end incl. epilogue | **pass** (`005ae986`) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** (call site + decomp) |
| isnil throw string | **pass** |
| size-- after delete | **pass** (bytes; decomp miss) |
| RB uses isnil21 L/R rotate | **pass** (`0050e9f0` / `005a27f0`) |
| Min/max isnil21 extremities | **pass** (`004cb2c0` / `00421a60`) |
| Sole caller FUN_005af2e0 | **pass** (1 xref) |
| Clean meaningful names | **pass** |
| Product demangle of map | **gap** |
| Two-child splice full plate | **gap** (bytes present; decomp unreachable) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8 sealed |
| isnil@+0x21 node layout | **High** | match min/max/rotates + buynode Val16 |
| Callers (1) | **High** | xrefs sealed |
| Name `…_Isnil21_Inferred` | **Inferred** | structural; not plate/RTTI |
| Runtime / differential | Open | Terminal false |

---

## 6. Gaps

1. Product demangle for map value_type of caller / host shell.  
2. Exact English for residual helpers `FUN_004e12c0` / `FUN_004cb2c0` / `FUN_00421a60`.  
3. Two-child splice plate full fidelity (decomp marks unreachable).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
