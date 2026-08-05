# Function record: PhysSim_FlushPendingBodyPairs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561320` |
| **Canonical name** | `PhysSim_FlushPendingBodyPairs_Inferred` |
| **Ghidra name** | `FUN_00561320` |
| **Address** | `0x00561320` |
| **Body range** | `0x00561320`–`0x00561360` (exclusive end `0x00561361`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / island pair glue |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + pair drain sealed; merge body / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md`, `reviews/B_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W19-M) |

## Alias

- `FUN_00561320` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_00561320` (auto parent-seed — **misleading as sole role**)

## Purpose

Drain pending `(bodyA, bodyB)` pairs from world pair vector (`+0x20` data, `+0x24` count). When hosts (`body+0x44`) differ, merge via `FUN_00560a30(world, hostA, hostB)`. Clear count to 0.

## Signature

```c
void __thiscall PhysSim_FlushPendingBodyPairs_Inferred(void *world);
// bare ret; ECX = world
```

## Algorithm

1. `i = 0`
2. While `i < world.pairCount` (`+0x24`):
   - Load pair at `data[i]` (stride 8).
   - `hostA/B = body+0x44`
   - If unequal: `FUN_00560a30(world, hostA, hostB)`
   - `i++`
3. `world.pairCount = 0`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00561320_FUN_00561320.md`
- Annotated: `docs/reconstruction/raw/aa_00561320_FUN_00561320.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PhysSim_FlushPendingBodyPairs_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00561320.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-006cad80-00561320-w19m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00560a30` (conditional host merge) |
| **Callers** | `0x00561450`, `0x005614f0`, `0x00561910` (×3), `0x00561b60`, `0x00562680` |

## Confidence

| Claim | Level |
|---|---|
| ABI ECX world + bare ret | **High** |
| Pair layout stride 8 | **High** |
| Host field body+0x44 | **High** |
| Conditional merge + clear count | **High** |
| Merge thiscall includes world | **High** |
| Product/PDB symbol | Open |
| Host English name | Open / inferred |

## Related

- `aa_0055efd0` PhysSim_PushBodyPair_Inferred (producer)
- `aa_00560a30` host merge (callee scaffold)
- `aa_00561910` island step (multi-flush caller)
- `aa_00561450` WorldObj_RemoveOrDefer (conditional flush)
