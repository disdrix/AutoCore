# Function record: StdTree_Rrotate_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403ee0` |
| **Canonical name** | `StdTree_Rrotate_Isnil31_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00403ee0` |
| **Address** | `0x00403ee0` |
| **Body** | `0x00403ee0`–`0x00403f2f` inclusive (**80 B** / `0x50`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` right-rotate (isnil @ +0x31) |
| **Completion status** | **Dual-reviewed** WQ9L-C — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-C** |

## Purpose

Perform a **right rotate** about node X in the isnil@**+0x31** red-black / std map tree family used by erase-and-rebalance `StdTree_EraseAndRebalance_Isnil31_Inferred` (`0x00408ed0`) and insert peer `FUN_00403250`. Promotes X.left to X's place; fixes parent links for root / left-child / right-child cases. Does **not** recolor (callers write color@+0x30).

## Signature

```c
// ECX = node X; stack map*; RET 4
void __thiscall StdTree_Rrotate_Isnil31_Inferred(void *node_x, void *map);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00408ed0` (3 sites), `FUN_00403250` (2 sites); 5 UNCONDITIONAL_CALL total |
| Callees | none |

## Related

- L-rotate twin: `FUN_00403e90` @ `0x00403e90` (same isnil31 family)
- Max / Min extremities: `StdTree_Max_Isnil31` @ `0x004043e0` (OWN WQ9L-C), `StdTree_Min_Isnil31` @ `0x00409160`
- Erase parent: `StdTree_EraseAndRebalance_Isnil31_Inferred` @ `0x00408ed0`
- Reject isnil2D Rrot `0042a840` / isnil29 Rrot `004192f0` (offset + ABI)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00403ee0_FUN_00403ee0.md`
- Annotated: `docs/reconstruction/raw/aa_00403ee0_FUN_00403ee0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil31_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00403ee0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00403ee0_FUN_00403ee0.md`
- Review A: `reviews/A_aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md`
- Review B: `reviews/B_aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Right-rotate semantics | **High** |
| isnil@+0x31 | **High** |
| ABI ECX=node / stack tree / RET 4 | **High** |
| Product map English | **Open** |
| Runtime | **Open** |
