# Function record: Object_SetMode278_SelectFromTFID228_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3c80` |
| **Canonical name** | `Object_SetMode278_SelectFromTFID228_Inferred` |
| **Ghidra name** | `FUN_004c3c80` |
| **Address** | `0x004c3c80`–`0x004c3d17` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / AI owner mode / selected-target apply |
| **Wave** | W28-L OWN dual |
| **Verdict** | **accept** |

## Signature

```c
void __thiscall Object_SetMode278_SelectFromTFID228_Inferred(void *self, char mode);
```

## Sealed contract

1. Always write `mode` to `self+0x278`.
2. If `mode != 1`, return (no resolve).
3. If `mode == 1`: resolve TFID at `+0x228`; candidate = `resolved+0xA0`; require vtbl+0x298; `Object_SetSelectedTarget(mi, candidate)`.

## Artifacts

See `aa_004c3c80_FUN_004c3c80.md` for full paths.
