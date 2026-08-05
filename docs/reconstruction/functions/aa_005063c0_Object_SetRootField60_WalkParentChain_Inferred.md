# Function record: Object_SetRootField60_WalkParentChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005063c0` |
| **Canonical name** | `Object_SetRootField60_WalkParentChain_Inferred` |
| **Address** | `0x005063c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object hierarchy / activate |
| **Ghidra symbol** | `FUN_005063c0` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Follow parent links at `+0xAC` to root; store `root+0x60 = value`. Used by ActivateEnterWorld (value 0) and spawn-point active-state.

## Signature

```c
void __thiscall Object_SetRootField60_WalkParentChain_Inferred(Object* obj, uint32_t value);
```

## Artifacts

- Raw / annotated / clean: `raw/aa_005063c0_*`, `reconstructed-exact/FUN_005063c0.cpp`
- Dual A/B: `reviews/A_aa_005063c0_Object_SetRootField60_WalkParentChain_Inferred.md`, `B_aa_005063c0_*`
- Legacy: `functions/aa_005063c0_FUN_005063c0.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `Vehicle_ActivateEnterWorld`, `CVOGSpawnPoint_SetObjectActiveState` |
| Callee | none |

## Confidence

| Claim | Level |
|---|---|
| Walk + store CF | High |
| Field product names | Tentative |
