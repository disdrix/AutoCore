# Function record: FUN_005ae4e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae4e0` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (prefer named record) |
| **Ghidra name** | `FUN_005ae4e0` |
| **Address** | `0x005ae4e0` |
| **Body range** | `0x005ae4e0`–`0x005ae6ca` exclusive (**490** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W27-T 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StdTree_InsertAndRebalance_Val12`
- Legacy: `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae4e0` (narrow)

## Purpose

MSVC `_Tree` always-insert + RB rebalance for Val12 nodes. See named function record.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const Val12* value);
// RET 0x10
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md`
- Raw: `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_005ae4e0.cpp`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | FUN_005ae220, FUN_00573170, FUN_00418c10, exception path |
| **Callers** | FUN_005aed20 only |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI ret 0x10 thiscall | **High** |
| Parameter semantic names | **High** (structural) |
| Product demangle | Open |
