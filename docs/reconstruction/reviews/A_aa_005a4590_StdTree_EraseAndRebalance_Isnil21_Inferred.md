# Review A (reconstruction fidelity): `aa_005a4590` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4590` |
| **VA** | `0x005a4590` |
| **Body** | `0x005a4590`–`0x005a4862` inclusive (**723 B** / `0x2D3`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005a4590` |
| **Review date** | `2026-08-05` (R12-032 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | MSVC std `_Tree` erase + RB rebalance (isnil@+0x21) |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one isnil@+0x21 red-black tree node: throw on nil iterator, unlink + extremity fix (min/max isnil21), rebalance if erased black (L/R rotate isnil21 dualed), free value heap @+0x14 + node, size--, write `*outIt`.

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell* map, Node** outIt, Node* node); // RET 8
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-032 re-verify) | `docs/reconstruction/raw/aa_005a4590_FUN_005a4590.md` |
| Annotated | `docs/reconstruction/raw/aa_005a4590_FUN_005a4590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005a4590.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF; epilogue from bytes |
| L / R rotates | dualed `0050e9f0` / `005a27f0` (parent) |
| Peer erase | `StdTree_EraseAndRebalance_Isnil29_Inferred` @ `0x004cb740` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | SEH `LAB_009a6342`; `cmp byte [node+0x21], 0` (`80 78 21 00`) |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| ThrowInfo | `DAT_00acc34c` |
| Epilogue | free `[node+0x14]` → zero +0x14/+0x18/+0x1c → `operator_delete(node)` → size-- → `*outIt` → `add esp,0x54; ret 8` |
| Body inclusive end | `0x005a4862` (pad `CC` after) |
| Size | **723** B |
| Color / isnil | +0x20 / +0x21 |
| Node size (sibling) | `0x24` (`FUN_005a4870` `operator_new(0x24)`) |

Epilogue tail hex (`0x005a4820`…):

```
045589751489751889751ce8f24feeff8b4c24148b410883c4045f3bc65e5d760683c0ff8941088b4c24608b44245c89088b4c244c5b64890d0000000083c454c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body inclusive end incl. epilogue | **pass** (`005a4862`) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** |
| isnil throw string | **pass** |
| size-- after delete | **pass** (bytes; decomp miss) |
| RB uses isnil21 L/R rotate | **pass** (`0050e9f0` / `005a27f0`) |
| Min/max isnil21 extremities | **pass** (`004cb2c0` / `00421a60`) |
| Value heap free @+0x14 | **pass** (bytes) |
| Clean meaningful names | **pass** |
| Product demangle of map | **gap** |
| Full both-children successor path | **gap** (unreachable-block warnings) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8 sealed |
| isnil@+0x21 node layout | **High** | match rotates + sibling buynode 0x24 |
| Callers (1) | **High** | xrefs sealed |
| Name `…_Isnil21_Inferred` | **Inferred** | structural; not plate/RTTI |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classical erase + RB rebalance CF | **Yes** |
| isnil@+0x21 byte seal | **Yes** |
| Dualed L/R rotates isnil21 | **Yes** |
| Peer dualed erases (29/31) | **Yes** |
| Parent dual seals R role in fixup | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil21_Inferred`**. Reject insert-merge, range-only alias, isnil29/31 family merge, skill-product exclusive name.

---

## 7. Gaps

1. Product / MSVC demangle for map value_type (key + vector-like @+0x14).
2. Exact English for `FUN_004e12c0` / min / max helpers (structural roles sealed).
3. Unreachable blocks may hide full both-children successor path detail.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
