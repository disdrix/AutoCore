# Function record: StdMap_InsertOrFind_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a570` |
| **Canonical name** | `StdMap_InsertOrFind_CharKey_Isnil21_Inferred` |
| **Ghidra name** | `FUN_0041a570` |
| **Address** | `0x0041a570`–`0x0041a628` exclusive (**184 B** / `0xB8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 char-key family) |
| **Wave** | R13-021 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (R12-011) |
| **Dual start** | 2686 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_0041a570`
- Scaffold alias: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0041a570`
- Structural: `StdMap_InsertOrFind_CharKey_Isnil21_Inferred` (product demangle open)

## Purpose

Unique insert-or-find for the **char-key isnil@+0x21** node family (node **0x24**, color@**+0x20**, key char @**+0x0C**). Walks the tree from root comparing `*value` (char) against `node[+0x0C]`. On miss, inserts via dualed always-insert/rebalance `0041ba30` (R12-011 parent dual). On equal key, returns existing iterator with `inserted=0` and does **not** rewrite the mapped value. Non-begin left-walk path runs residual predecessor `005adff0` before the strict miss check.

## Signature

```c
void __thiscall StdMap_InsertOrFind_CharKey_Isnil21_Inferred(
    /*ECX*/ MapShell* map,
    InsertPair* out,       // { Node* it; uint8_t inserted @ +4 }
    const void* value);    // char key at value+0
// RET 0x8; out written in place
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0041ba30` | `StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred` | always-insert child (**parent dual** R12-011) |
| `0x005adff0` | tree predecessor isnil21 | pred residual (undualed) |
| `0x0041d860` | buynode node0x24 / isnil21 | via insert child (undualed) |
| `0x00407060` | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` | peer pair-key shell (do **not** merge) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | Val16 always-insert (do **not** merge) |
| `0x004cbe20` | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` | peer int-key isnil29 (do **not** merge) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0041a570_FUN_0041a570.md`
- Annotated: `docs/reconstruction/raw/aa_0041a570_FUN_0041a570.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_CharKey_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0041a570.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-0041a570-r13-report.md`

## Callers / callees

| **Callers (2)** | `FUN_007eaf20` — 2 UNCONDITIONAL_CALL (`007eba53`, `007ec6e4`); `FUN_0059a940` — 1 (`0059ab1c`) |
| **Callees** | `FUN_0041ba30` (insert, dualed R12-011); `FUN_005adff0` (pred, residual) |

## Confidence

| Claim | Level |
|---|---|
| Role unique insert-or-find char-key | **High** |
| ABI / RET 0x8 / thiscall | **High** (bytes sealed; not Runtime Confirmed) |
| Layout isnil@+0x21 / key@+0x0C / color@+0x20 | **High** (walk + parent dual) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
