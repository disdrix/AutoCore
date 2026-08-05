# Function record: GfxVertexBufferFactory_PostRestoreDevice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00986570` |
| **Canonical name** | `GfxVertexBufferFactory_PostRestoreDevice_Inferred` |
| **Ghidra name** | `FUN_00986570` |
| **Address** | `0x00986570` |
| **Body** | **482 B** (`0x00986570`–`0x00986752` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | graphics / VB factory PostRestoreDevice |
| **Name confidence** | **Inferred** (product `.cpp` path + sealed error string + Reset caller plate) |
| **Dual** | **accept-with-gaps** (W38-AE A+B) |

## Role

After `IDirect3DDevice9::Reset`, walk the factory's VB pool map and recreate DEFAULT-pool vertex buffers via `FUN_00746640`, then fire surface-restore callbacks (log-only on callback fail).

## ABI

| Slot | Value |
|---|---|
| EAX | factory `this*` |
| stack | none |
| cleanup | plain `RET` |
| return | HRESULT (0 / negative) |

## Rejected aliases

- `Named_gfxVertexBufferFactory_00986570` as sole plate
- ECX-thiscall reinterpretation

## Artifacts

See `aa_00986570_FUN_00986570.md`.
