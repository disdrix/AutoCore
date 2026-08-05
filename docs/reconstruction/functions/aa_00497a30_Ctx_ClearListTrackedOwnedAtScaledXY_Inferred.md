# Function record: Ctx_ClearListTrackedOwnedAtScaledXY_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497a30` |
| **Canonical name** | `Ctx_ClearListTrackedOwnedAtScaledXY_Inferred` |
| **Ghidra name** | `FUN_00497a30` |
| **Address** | `0x00497a30`–`0x00497ab8` inclusive (**137 B** / `0x89`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Wave** | W31-D OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

## Role

Ctx **single-cell** clearer: maps scaled world/tile units to one host grid cell and frees owned `ListTrackedObj*` @ `elem+0x24`. Sibling of rect clearer `Host_ClearListTrackedOwnedInRect_Inferred` (`0x00494530`).

## Signature

```c
uint32_t __thiscall Ctx_ClearListTrackedOwnedAtScaledXY_Inferred(
    void* ctx, uint32_t xUnits, uint32_t yUnits);
```

## Port notes

- `host = *(*(ctx+0xC4)+0xE898)`; arr `@host+0x28`; dimX `@host+4`.
- `div = trunc(DAT_00aefa50 * DAT_00a14000)`; index = `(y/div)*dimX + (x/div)`.
- Always return **1** and **`ret 8`**.
- Scale global shared with rebuild (`0x004941b0`); do not hardcode 32-only.
- Orphan static graph — wire only when call site recovered.

## Artifacts

See `aa_00497a30_FUN_00497a30.md` for full artifact table.
