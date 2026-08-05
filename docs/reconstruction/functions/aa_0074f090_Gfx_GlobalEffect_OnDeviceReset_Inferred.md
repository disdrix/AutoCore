# Function record: Gfx_GlobalEffect_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074f090` |
| **Canonical name** | `Gfx_GlobalEffect_OnDeviceReset_Inferred` |
| **Ghidra name** | `FUN_0074f090` |
| **Address** | `0x0074f090`–`0x0074f0be` exclusive (**46 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | client / Palantir graphics |
| **Name class** | **Inferred** (structural + parent product plate “Global Effect”) |
| **Completion** | W38-W dual **accept** |

## Signature

```c
int Gfx_GlobalEffect_OnDeviceReset_Inferred(void* holder /*EAX*/);
// returns 0 | -1
```

## Summary

Global Effect device-reset vcall wrapper: `holder[+0xC]` → `vtbl[+0x118]`; status ≥0 → 0 else −1.

## Artifacts

See `aa_0074f090_FUN_0074f090.md` for full table.
