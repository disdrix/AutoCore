# Function record: GfxIndexBufferFactory_PreRestoreDevice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985580` |
| **Canonical name** | `GfxIndexBufferFactory_PreRestoreDevice_Inferred` |
| **Ghidra name** | `FUN_00985580` |
| **Address** | `0x00985580`–`0x00985601` exclusive (**129 B** / `0x81`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics |
| **Wave** | W38-AC |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Release device resources for all eligible index-buffer factory slots before `IDirect3DDevice9::Reset` (PreRestore / OnLostDevice family).

## Signature

```c
// EAX = factory*; plain RET
void GfxIndexBufferFactory_PreRestoreDevice_Inferred(void /*EAX*/);
```

## Layout touches

| Offset | Meaning |
|---|---|
| factory `+0x14` | map sentinel* |
| node `+0x0C` | flags byte; gate `& 0x28` |
| node `+0x14` / `+0x18` | slot vector begin/end |
| node `+0x21` | RB `is_nil` |
| slot `+0` | `GfxDeviceIB*` (loaded into ESI) |
| stride | `0x20` |

## Artifacts

- Raw / annotated / clean / twin / Ghidra function record — see `aa_00985580_FUN_00985580.md`
- A/B: `A_aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md`, `B_aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md`
