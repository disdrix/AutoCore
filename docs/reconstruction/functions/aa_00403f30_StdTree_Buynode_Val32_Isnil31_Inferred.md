# Function record: StdTree_Buynode_Val32_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403f30` |
| **Canonical name** | `StdTree_Buynode_Val32_Isnil31_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00403f30` |
| **Address** | `0x00403f30`–`0x00403fb2` exclusive (**130 B** / `0x82`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body epilogue** | `RET 0x14` (`C2 14 00` @ `0x00403faf`) |
| **System** | MSVC `std::_Tree` node allocation |
| **Partition** | MEGA-048 — missions-progression residual under NotifyActiveMissionChanged |
| **Agent** | MEGA-048 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x31** family with **32-byte (8 dword) value** at `+0x10`. Allocates **0x38**, constructs links + value + color + isnil=0 via `FUN_00404360`. Returns null on OOM. Used exclusively by residual insert/rebalance `FUN_00403250` (same isnil31 family as dualed Lrotate `00403e90` / erase `00408ed0` / BuyHead `00409180`).

## Signature

```c
NodeIsnil31_Size0x38* __stdcall StdTree_Buynode_Val32_Isnil31_Inferred(
    NodeIsnil31_Size0x38* left,
    NodeIsnil31_Size0x38* parent,
    NodeIsnil31_Size0x38* right,
    const uint32_t value8[8],
    uint8_t color);
// RET 0x14
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | value (8× int32 / Val32) |
| +0x30 | color (0 red / 1 black) |
| +0x31 | isnil (forced 0) |
| size | **0x38** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00403250` insert/rebalance isnil31 @ `0x004032b6` (MEGA-047 residual) |
| Alloc | `operator_new(0x38)` @ `0x00489892` |
| Construct | `FUN_00404360` @ `0x00404360` (undualed) |
| Family | Lrot `00403e90`, Rrot `00403ee0`, erase `00408ed0`, BuyHead `00409180` |
| Contrast | isnil29 Val24 buynode `00407e30` — **do not merge** |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` / disasm.
- Insert passes `(head, where, head, value, 0)` → red node.
- Ctor seals Val32 + isnil@+0x31 + color@+0x30 (`REP MOVSD` ×8).
- Prior chain-of-caller `Named_CalleeOf_*NotifyActiveMission*` scaffold **retired**.

## Gaps

- Product / PDB demangle for value_type.
- Dual of ctor + insert parent (not OWN).
- Runtime / bit-exact / differential.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val32_Isnil31_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00403f30.cpp`
- Raw: `docs/reconstruction/raw/aa_00403f30_FUN_00403f30.md`
- Annotated: `docs/reconstruction/raw/aa_00403f30_FUN_00403f30.annotated.md`
- FUN record: `docs/reconstruction/functions/aa_00403f30_FUN_00403f30.md`
- Review A: `docs/reconstruction/reviews/A_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md`
- Report: `docs/agents/task-dual-ab-00403f30-mega-048-report.md`
