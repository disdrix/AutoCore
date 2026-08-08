# Function record: StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e48b0` |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004e48b0` |
| **Address** | `0x004e48b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004e48b0`–`0x004e4983` exclusive (**211 B** / `0xD3`) |
| **System** | skills-abilities / MSVC `std::map` insert-or-find (pair key, isnil@+0x21) |
| **Wave** | R13-005 OWN-ONLY dual 2026-08-05 (dual start 2686) |
| **Parent dual** | `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Runtime** | **Open** — never Runtime Confirmed |

## Alias history

- Ghidra: `FUN_004e48b0`
- Scaffold: `Named_CalleeOf_CVOGReaction_UpdateRepairStationPosition_004e48b0`
- Structural: `StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred` (product demangle open)

## Purpose

MSVC-style unique insert-or-find for maps whose nodes use **isnil@+0x21** and a **two-dword pair key** (signed hi primary @+0x14, unsigned lo secondary @+0x10). Walks from root, inserts via dualed `FUN_004e37e0` on miss, returns `{it,0}` on equal without rewriting value. Callers include dualed repair-station reaction path and residual `FUN_004da160`.

## Signature

```c
void __thiscall StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred(
    MapShell_Isnil21 *map,     /* ECX */
    InsertPair *out,           /* { Node* it; uint8_t inserted @ +4 } */
    const Val_PairKey *value);
// RET 0x8
```

## Layout (node)

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | key_lo (unsigned secondary) |
| +0x14 | key_hi (signed primary) |
| +0x18..+0x1c | mapped (Val16 remainder) |
| +0x20 | color |
| +0x21 | isnil |

## Call graph

| Role | Target |
|---|---|
| **Caller** | dualed `CVOGReaction_UpdateRepairStationPosition` (`0x004d38b0`) @ `0x004d391f` |
| **Caller** | residual `FUN_004da160` (`0x004da160`) @ `0x004da224` |
| Insert | dualed `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (`0x004e37e0`) ×2 |
| Pred | residual `FUN_005adff0` |
| Peer clone | dualed `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (`0x00407060`) — insert via `00407200`; **do not merge** |
| Family peer | dualed `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (`0x004cbee0`) — isnil@+0x29 |

## Evidence summary

- Live decompile ≡ raw CF; **RET 0x8** ×3 via `read_memory`.
- Hi signed (`JG`/`JL`), lo unsigned (`JAE`/`JNC`); equal path `inserted=0`.
- Body size **211 B** matches peer clone `00407060` (same shell CF; different insert worker).

## Artifacts

- Raw (+ R13-005 re-verify): `docs/reconstruction/raw/aa_004e48b0_FUN_004e48b0.md`
- Annotated: `docs/reconstruction/raw/aa_004e48b0_FUN_004e48b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.cpp`
- Clean twin scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e48b0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md`
- Report: `docs/agents/task-dual-ab-004e48b0-r13-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil21 / pair-key | **High** (byte-sealed) |
| Role insert-or-find shell | **High** |
| Product pair English (TFID / etc.) | **Open** (`_Inferred`) |
| Runtime / bit-exact / differential | **Open** |
