# Function record (named): WaterPhase_RegisterToken_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00576860` |
| **Semantic name** | `WaterPhase_RegisterToken_Inferred` |
| **Ghidra name** | `FUN_00576860` |
| **Address** | `0x00576860`–`0x00576889` exclusive (**41 B** / `0x29`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector water phase |
| **Naming basis** | Sole water-arm post-init after ctor+vcall; fail gated by parent `hr < 0`; body is registry find/append of 4-byte phase token |
| **Status** | Dual sealed W32-S (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_00576860_FUN_00576860.md`.

## Signature

```c
int32_t WaterPhase_RegisterToken_Inferred(void);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W32-S.
