# Function record: ListTrackedCtx_ClearResetCapacity10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004982d0` |
| **Canonical name** | `ListTrackedCtx_ClearResetCapacity10_Inferred` |
| **Ghidra name** | `FUN_004982d0` |
| **Address** | `0x004982d0`–`0x004982e2` inclusive (**19 B** / `0x13`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir env child / list-tracked ctx |
| **Classification** | wrapper |
| **Name confidence** | **Inferred** — structural from W33-R clear + capacity store; no product string on this VA |
| **Completion status** | **Dual-reviewed (W37-AD)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal coverage claim** | **false** |

## Purpose

Clear-destroy-reset ListTrackedCtx then seed capacity **+0xC = 10**. Used once from PalantirEnv init with `ECX = env+0x100`.

## Signature

```c
uint8_t __thiscall ListTrackedCtx_ClearResetCapacity10_Inferred(uint8_t* self);
```

## Cross-links

- Twin Ghidra record: `functions/aa_004982d0_FUN_004982d0.md`
- Clear body: `ListTrackedCtx_ClearDestroyAndReset_Inferred` (`0x00497c80`, W33-R)
- Report: `docs/agents/task-dual-ab-00970fc0-004982d0-w37ad-report.md`
