# Function record: PhysSim_LtBroadPhase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00629d90` |
| **Canonical name** | `PhysSim_LtBroadPhase_Inferred` |
| **Ghidra name** | `FUN_00629d90` |
| **Address** | `0x00629d90` |
| **Body** | `0x00629d90`–`0x0062a160` exclusive (**2000** B / `0x7D0`); epilogue `ret 8` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / sub-island broadphase + narrowphase |
| **Completion status** | **Dual-sealed (W28-S)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Classification** | worker |

## Alias

- Ghidra: `FUN_00629d90`
- Profile string: `"LtBroadPhase"` @ `0x009e335c`

## Purpose

Per-sub-island collide half of island `LtSimulate`: AABB expand (`StCalcAabbs`), 3-axis sweep (`St3AxisSweep`), examine/merge (`StExamine`), `Phys_CommitPairListStorage_Inferred` (`FUN_006297e0`), flag `subIsland+0x30=1`, then narrowphase (`FUN_00629c40` or `FUN_00629990` on parentWorld `+0x23e`).

## Signature (sealed)

```c
void __thiscall PhysSim_LtBroadPhase_Inferred(
    void *subIsland,   // ECX — bodies @ +0x3c/+0x40, parent world @ +0x20
    /* 2 stack args from call site: ctx = *(island+0xc4), stepBlock = island+0x140 */);
// ret 8
```

## Constants

| Addr | Value | Use |
|---|---|---|
| `DAT_00a0f298` | **0.5f** (`00 00 00 3f`) | AABB margin scale |

## Artifacts

- Raw / annotated / clean / twin / A / B — see twin FUN record.

## Callers / callees

| Direction | Symbols |
|---|---|
| Callers | `FUN_00561910` (1 xref) |
| Callees | `FUN_0062d960` x2, `FUN_005b3300`, `FUN_006297e0`, `FUN_00629c40` / `FUN_00629990` |

## Confidence

| Claim | Level |
|---|---|
| Role = broadphase+narrowphase only | **High** |
| ABI ret 8 | **High** |
| Product English | **Tentative** (`_Inferred`) |
