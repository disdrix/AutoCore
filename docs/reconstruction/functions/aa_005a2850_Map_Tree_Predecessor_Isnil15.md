# Function record: Map_Tree_Predecessor_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2850` |
| **Canonical name** | `Map_Tree_Predecessor_Isnil15` |
| **FUN_* alias** | `FUN_005a2850` |
| **Address** | `0x005a2850` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared map/tree helper (isnil `+0x15` family) |
| **Completion status** | **Dual sealed 2026-07-29 W19-N** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Historical scaffold: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005a2850` — **do not use for semantics**.

## Purpose

MSVC-style ordered-tree **iterator predecessor** (`operator--`): in-place update of a `Node**` for trees whose isnil flag is at **`node+0x15`**. Leaf — no allocation, rebalance, or key compare. Same algorithm as `Map_Tree_Predecessor_Isnil49` (`0x00537770`).

## Signature (sealed)

```c
// __fastcall: ECX = pIt; RET (C3)
void __fastcall Map_Tree_Predecessor_Isnil15(int **pIt /* Node** */);
```

## Node assumptions (sealed partial)

```
+0x00 left*
+0x04 parent*
+0x08 right*
+0x15 isnil (u8)
```

Key / color / payload are **caller-map specific** (not read here).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a2850_FUN_005a2850.md`
- Annotated: `docs/reconstruction/raw/aa_005a2850_FUN_005a2850.annotated.md`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_005a2850.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_Tree_Predecessor_Isnil15.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005a2850_Map_Tree_Predecessor_Isnil15.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005a2850_Map_Tree_Predecessor_Isnil15.md`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | **none** (leaf) |
| Callers | 21 static xrefs — map insert/find family including `Map_InsertOrFind_IntKey` (`0x005d2360` dual already labels this as tree predecessor), `FUN_004e47b0`, `FUN_004e46f0`, `FUN_0041b1e0`, … |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + body bytes | **High** |
| Role = predecessor only | **High** |
| isnil `+0x15`, links 0/4/8 | **High** |
| `__fastcall` ECX = `Node**` | **High** |
| Product STL English name | Tentative / Open |
| Full node schemas of callers | Open (caller duals) |
