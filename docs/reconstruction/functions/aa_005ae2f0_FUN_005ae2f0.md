# Function record: FUN_005ae2f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2f0` |
| **Canonical name** | `FUN_005ae2f0` (scaffold; prefer named record) |
| **Promoted name** | `StdTree_InsertAndRebalance_Val20_Isnil21_Inferred` |
| **Address** | `0x005ae2f0`–`0x005ae4da` inclusive (**491** B / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (Val20 / isnil@+0x21) |
| **Wave** | R12-034 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005ae2f0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae2f0` (**narrow** — reject as product name)
- Named record: `docs/reconstruction/functions/aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md`

## Purpose

MSVC `_Tree` always-insert + red-black rebalance for Val20 nodes (node 0x24). See named record for full seal.

## Signature

```c
void __thiscall FUN_005ae2f0(
    int map,              // ECX; +4 head, +8 size
    undefined4 *outIt,
    char addLeft,
    undefined4 *where,
    undefined4 value);    // Val20*
// RET 0x10
```

## Artifacts

- Raw (+ R12-034 re-verify): `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005ae2f0.cpp`
- Dual A/B: `reviews/A|B_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-005ae2f0-r12-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_005ae1c0`, `FUN_0050e9f0`, `FUN_005a27f0` ×2, `_CxxThrowException`, string/exception |
| **Callers (1)** | `FUN_005aec50` |
| **Xrefs** | 1 UNCONDITIONAL_CALL @ `0x005aecaf` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| ABI / RET 0x10 / size gate | **High** |
| Val20 isnil21 layout | **High** |
| Product English | **Inferred** |
| Runtime / differential | Open |
