# Function record: StdMap_InsertOrFind_IntKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511b40` |
| **Canonical name** | `StdMap_InsertOrFind_IntKey_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00511b40` |
| **Address** | `0x00511b40`–`0x00511bf8` inclusive (**185 B** / `0xB9`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities partition / generic MSVC map insert-or-find (isnil@+0x21 Node24) |
| **Wave** | R13-031 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x00511950` `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (R12-014) |
| **Partition** | `WAVE_2026-08-05_r13_residual_partition_map.md` → R13-031 |
| **Dual start** | 2686 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00511b40`
- Scaffold: `FUN_00511b40` (2026-07-23 raw)
- Structural: `StdMap_InsertOrFind_IntKey_Isnil21_Inferred` (product demangle open)
- **Not** always-insert parent `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (`0x00511950`)
- **Not** peer `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` (`0x004cbe20`)
- **Not** peer `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (`0x00407060`)

## Purpose

Unique **insert-or-find** for maps with **isnil@+0x21** nodes and a **signed int32** key at node+**0x0C** / value[0]. Writes `{iterator, inserted}`; equal key does not rewrite mapped payload. Insert worker is dualed `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` @ `0x00511950`. Predecessor residual `FUN_005adff0` when goLeft and not begin.

## Signature

```c
void __thiscall StdMap_InsertOrFind_IntKey_Isnil21_Inferred(
    /*ECX*/ MapShell* map,
    InsertPair* out,           // {Node* it @ +0; bool inserted @ +4}
    const Val_IntKey* value);  // signed key at [0]
// RET 8  (C2 08 00 ×3 exits)
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00511950` | `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` | always-insert worker (dualed R12-014 **parent**) |
| `0x005118b0` | buynode Node24 isnil21 | nested residual under parent |
| `0x005adff0` | predecessor isnil21 | residual undualed |
| `0x004cbe20` | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` | peer other isnil family (do not merge) |
| `0x00407060` | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` | peer pair-key isnil21 (do not merge) |
| `0x00511c00` | erase peer isnil21 Node24 family | residual twin after pad |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00511b40_FUN_00511b40.md`
- Annotated: `docs/reconstruction/raw/aa_00511b40_FUN_00511b40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_IntKey_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00511b40.cpp`
- Function (scaffold id): `docs/reconstruction/functions/aa_00511b40_FUN_00511b40.md`
- Dual A: `docs/reconstruction/reviews/A_aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00511b40-r13-report.md`

## Callers / callees

| **Callers (1)** | `FUN_0050ba90` — 1 UNCONDITIONAL_CALL @ `0x0050bbc4` |
| **Callees** | `FUN_00511950` ×2, `FUN_005adff0` ×1 |

## Confidence

| Claim | Level |
|---|---|
| Role insert-or-find (not always-insert) | **High** |
| ABI / RET 8 / thiscall | **High** |
| Layout isnil@+0x21 key@+0x0C signed SETL | **High** |
| Distinct from isnil29 / PairKey peers | **High** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
