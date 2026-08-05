# Function record: WorldObj_RehomeLinksFromSnapshot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560f70` |
| **Canonical name** | `WorldObj_RehomeLinksFromSnapshot_Inferred` |
| **Ghidra name** | `FUN_00560f70` |
| **Address** | `0x00560f70`–`0x00561312` (**930 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / phys rehome after mode exit |
| **Completion status** | **Dual-sealed** (W27-O 2026-07-29) — A **accept-with-gaps**, B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

After guarded reattach: re-home snapshot children, link-array body pairs, and actions (push + reverse-list remove + neighbor pairs). SwitchHBAI post-path when **leaving** mode code **7**.

## Signature

```c
// RET 8
void __thiscall WorldObj_RehomeLinksFromSnapshot_Inferred(
    Manager *m, WorldObj *obj, Snapshot *snap /* {void** data; int count} */);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560f70_FUN_00560f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00560f70_FUN_00560f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_RehomeLinksFromSnapshot_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560f70.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_00560f70_FUN_00560f70.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `FUN_005d4440` | 1 site; old mode == 7; snapshot from `005617c0` |
| Callee | `FUN_0055e760` / `FUN_0055fa40` | guarded reattach |
| Callee | `FUN_005b3370` | host child list grow |
| Callee | `FUN_005b3300` | pair vector grow (×3 open-coded) |
| Callee | `FUN_006292a0` / `FUN_00628f10` | action rehome |

## Confidence

| Claim | Level |
|---|---|
| CF stages + ABI sealed | **Confirmed** / **High** |
| `unaff_EBX` residual | Gap |
| Product names | Open / `_Inferred` |
