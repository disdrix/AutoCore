# Function record: GfxBufferedViews_ReleaseDeviceTextures_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009686e0` |
| **Canonical name** | `GfxBufferedViews_ReleaseDeviceTextures_Inferred` |
| **Ghidra name** | `FUN_009686e0` |
| **Address** | `0x009686e0`–`0x00968715` exclusive (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir/graphics — gfxBufferedView / Device Reset |
| **Naming basis** | List-level release during `GfxDevice_Reset` shutdown; list `DAT_00d1ee30` shared with `GfxBufferedView_Ctor_Inferred`; callee `FUN_0096c8e0` texture release |
| **Completion status** | **Dual A/B sealed (W38-AA)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Release device textures for all registered gfxBufferedViews that need reset (`*(tex+0x30)==0`).

## Signature

```c
void GfxBufferedViews_ReleaseDeviceTextures_Inferred(void);
```

## Related

| VA | Role |
|---|---|
| `0x00968720` | recreate twin (this agent) |
| `0x00968a50` | gfxBufferedView ctor / list insert (W37-I) |
| `0x0096c8e0` | texture release leaf (W38-AB) |
| `0x0075eff0` | GfxDevice_Reset parent (W37-N) |
| `0x00968680` | list flag clear on success path (W38-Z) |
