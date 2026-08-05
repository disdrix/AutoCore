# Function record: ParticleFluidLiquidChild_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1800` |
| **Canonical name** | `ParticleFluidLiquidChild_Ctor_Inferred` |
| **Ghidra name** | `FUN_004c1800` |
| **Address** | `0x004c1800`–`0x004c187d` inclusive (**126 B** / `0x7E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase / liquid child |
| **Completion status** | Dual A/B sealed W37-G 2026-08-04 — **accept-with-gaps** |
| **Dual** | `reviews/A_aa_004c1800_ParticleFluidLiquidChild_Ctor_Inferred.md`, `B_*` |

## Purpose

Construct the 0x40 liquid child that `ParticleFluidPhase_CreateLiquidChild_Inferred` allocates and stores at `phase+0xc4`. Initializes parent link, empty std-list sentinel pair, inactive flag, host-link subobject, zeroed resource slots, and global `DAT_00b03794`.

## Signature

```c
void* __thiscall ParticleFluidLiquidChild_Ctor_Inferred(void *self /*ECX*/, void *phase /*stack*/);
// cleanup: RET 4
```

## Sealed layout

| Off | Field |
|----:|---|
| `+0x00` | phase* |
| `+0x08` | list sentinel* (`StdList_AllocSentinel_0xC_Inferred`) |
| `+0x0C` | list size = 0 |
| `+0x10` | u8 active (0 at ctor; parent sets 1) |
| `+0x14` | dword 0 |
| `+0x18` | host-link subobject (`FUN_004c17b0`, vtbl `009cb7a4`) |
| `+0x20`…`+0x3C` | zeroed (8 dwords) |

## Related (not owned)

| VA | Role |
|---|---|
| `0x004c1960` | CreateLiquidChild parent (W34-O) |
| `0x004933f0` | list sentinel alloc (W32-P) |
| `0x004c17b0` | host-link subobject ctor |
| `0x004c0fe0` | liquid init after ctor (W37-F) |
| `0x00b03794` | published singleton/global child |
| `0x00b03790` | phase host publish (sibling global) |
