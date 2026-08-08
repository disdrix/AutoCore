# Function record: StdTree_Min_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb2c0` |
| **Canonical name** | `StdTree_Min_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004cb2c0` |
| **Address** | `0x004cb2c0` |
| **Body** | `0x004cb2c0`–`0x004cb2da` inclusive (**27 B** / `0x1b`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` min / leftmost (isnil @ +0x21); partition **skills-abilities** |
| **Completion status** | **Dual-reviewed** R13-002 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-002** |
| **Parent dual** | `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009) |
| **Dual start** | 2686 |
| **Terminal** | **false** (no runtime Confirmed) |

## Purpose

Return the leftmost non-nil node in the subtree rooted at the input node (MSVC `_Tree_min`). Used by isnil@+0x21 erase helpers to recompute `head->left` after unlinking the previous leftmost.

Family twins: `StdTree_Min_Isnil29` @ `0x0051b5d0` (stack ABI); `StdTree_Min_Isnil31` @ `0x00409160` (EAX ABI). Max peer residual `FUN_00421a60` (R13-001).

## Signature

```c
// stack arg node*; returns node* in EAX; bare RET; caller ADD ESP,4
void *StdTree_Min_Isnil21_Inferred(void *node /*[esp+4]*/);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (7) | `FUN_00405650` @ `0x0040571a`; `FUN_004e3e70` @ `0x004e3f5f`; `FUN_00511c00` @ `0x00511cec`; `FUN_0059d300` @ `0x0059d3ec`; `FUN_005a2ea0` @ `0x005a2f8f`; `FUN_005a4590` @ `0x005a467c`; `FUN_005ae6d0` @ `0x005ae7bf` |
| Callees | none (leaf) |

Uniform plate: `PUSH EDI; CALL; ADD ESP,4; MOV [EBX],EAX`.

## Related (not OWN)

- Parent erase `StdTree_EraseAndRebalance_Isnil21_Inferred` @ `0x00405650` (R12 dualed)
- Max residual `FUN_00421a60` (R13-001)
- Iterator++ residual `FUN_004e12c0` (R13-003)
- Family Min peers isnil29/31 (dualed earlier)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.md` (+ R13-002 append)
- Annotated: `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004cb2c0.cpp`
- Review A: `reviews/A_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md`
- Review B: `reviews/B_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004cb2c0_FUN_004cb2c0.md`
- Report: `docs/agents/task-dual-ab-004cb2c0-r13-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| Stack-arg in / EAX out ABI | **High** |
| isnil every guard +0x21 | **High** |
| Role = tree min / leftmost | **High** |
| Product map key/value English | **Open** |
| Runtime | **Open** |
