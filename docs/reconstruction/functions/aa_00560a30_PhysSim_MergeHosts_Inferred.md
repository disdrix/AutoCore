# Function record: PhysSim_MergeHosts_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560a30` |
| **Canonical name** | `PhysSim_MergeHosts_Inferred` |
| **Ghidra name** | `FUN_00560a30` |
| **Address** | `0x00560a30` |
| **Body** | `0x00560a30`–`0x00560c8b` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / island host glue |
| **Completion status** | **Dual-sealed 2026-07-29 W20-B** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00560a30`
- Scaffold chain: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set_00560a30` (**misleading sole role** — not spawn-point specific)
- Parent dual role: host/island merge callee of `PhysSim_FlushPendingBodyPairs_Inferred`

## Purpose

`__thiscall` on **world/sim**: merge physics **host** `src` into **host** `dest` (activate both if needed, splice vectors/lists + rebind back-pointers, swap-remove `src` from world host table, scalar-delete `src`, return `dest`). No-op when `dest == src`.

## Signature (byte-sealed)

```c
// __thiscall; RET 0x8
Host *PhysSim_MergeHosts_Inferred(
    World *world, // ECX
    Host *dest,   // survivor
    Host *src);   // absorbed then destroyed
```

## Key offsets

| Object | Off | Field |
|---|---:|---|
| World | +0x08 | Host** table |
| World | +0x0c | host count |
| Host | +0x24 | table index |
| Host | +0x28 | dirty/merged flag (u8) |
| Host | +0x29 | activated flag (u8) |
| Host | +0x3c | body* vector (rebind item+0x44 / +0x58) |
| Host | +0x4c | ptr vector (rebind item+0x10) |
| Host | +0x58 | ptr vector (rebind item+0x14) |
| Host | +0x68 | list merged via `FUN_00560750` |
| Host | +0x74 | 8-byte element vector |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00560a30_FUN_00560a30.md`
- Annotated: `docs/reconstruction/raw/aa_00560a30_FUN_00560a30.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/PhysSim_MergeHosts_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_00560a30.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00560a30_PhysSim_MergeHosts_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00560a30_PhysSim_MergeHosts_Inferred.md`
- Parent dual: `reviews/A|B_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller (sole static) | `0x00561320` | PhysSim_FlushPendingBodyPairs_Inferred |
| Callee | `0x0055eb80` | PhysSim_ActivateHost |
| Callee | `0x00560750` | Merge host+0x68 list |
| Callee | `0x005b3300` | Vector grow |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ body bounds | **High** |
| `RET 0x8` + ECX=world + dest/src hosts | **High** |
| Activate / append vectors / swap-remove / destroy | **High** |
| Body host field `item+0x44` matches flush producer | **High** |
| Product English for host type / +0x68 list | **Open** |
| Runtime / bit-exact | **Open** |
