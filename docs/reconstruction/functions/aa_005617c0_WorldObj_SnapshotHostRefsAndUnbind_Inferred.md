# Function record: WorldObj_SnapshotHostRefsAndUnbind_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005617c0` |
| **Canonical name** | `WorldObj_SnapshotHostRefsAndUnbind_Inferred` |
| **Ghidra name** | `FUN_005617c0` |
| **Address** | `0x005617c0`–`0x005618a0` (**224 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / mode-7 leave snapshot |
| **Completion status** | **Dual-sealed** (W29-T 2026-07-29) — A **accept**, B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

SwitchHBAI **leave mode 7** snapshot producer:

1. Zero snapshot count.
2. For host `*(manager+0x2c)` list `+0x58/+0x5c`, collect entries with `+0xc` or `+0x10` equal to the world object.
3. On match: push to snapshot, entry virtual `+0x28`, host virtual `+0xc`, compact-remove.
4. Tail: `FUN_005614f0` — defer object if reentrancy flag `manager+0x12c==1`, else unbind path.

Snapshot is rehomed later by `WorldObj_RehomeLinksFromSnapshot_Inferred` (`00560f70`) on the same SwitchHBAI path.

## Signature

```c
// RET 8
void __thiscall WorldObj_SnapshotHostRefsAndUnbind_Inferred(
    int manager, int obj, int *snapshot /* {data,count,cap} */);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005617c0_FUN_005617c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005617c0_FUN_005617c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_SnapshotHostRefsAndUnbind_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005617c0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_005617c0_FUN_005617c0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `FUN_005d4440` | 1 site; old mode == 7; before HBAI swap |
| Consumer | `FUN_00560f70` | rehome after swap when old == 7 |
| Callee | `FUN_005b3370` | grow snapshot |
| Callee | `FUN_005614f0` | defer/unbind object |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **Confirmed** |
| Role as mode-7 snapshot producer | **Confirmed** |
| Product names | Open / `_Inferred` |
