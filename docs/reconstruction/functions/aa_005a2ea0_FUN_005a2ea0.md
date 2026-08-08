# Function record: FUN_005a2ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2ea0` |
| **Canonical name** | `FUN_005a2ea0` (Ghidra) → see named record |
| **Named** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Address** | `0x005a2ea0`–`0x005a3155` inclusive (**694 B** / `0x2B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21) |
| **Wave** | R12-030 OWN-ONLY dual 2026-08-05 (dual start 2646) |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

Single-node MSVC `_Tree::erase(const_iterator)` for **isnil@+0x21** / **color@+0x20** / node **0x28**. See named function record for full contract.

## Artifacts

- Raw (+ R12-030 re-verify): `docs/reconstruction/raw/aa_005a2ea0_FUN_005a2ea0.md`
- Annotated: `docs/reconstruction/raw/aa_005a2ea0_FUN_005a2ea0.annotated.md`
- Clean (VA twin): `docs/reconstruction/reconstructed-exact/FUN_005a2ea0.cpp`
- Named record: `docs/reconstruction/functions/aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` / `B_aa_005a2ea0_…`
- Report: `docs/agents/task-dual-ab-005a2ea0-r12-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF throw/splice/RB from decompiler | **High** |
| ABI ret 8 / size-- / outIt from bytes | **High** |
| Product English | **Open** (`_Inferred`) |
| Runtime | **Open** |
