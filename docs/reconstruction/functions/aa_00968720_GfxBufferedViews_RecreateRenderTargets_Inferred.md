# Function record: GfxBufferedViews_RecreateRenderTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968720` |
| **Canonical name** | `GfxBufferedViews_RecreateRenderTargets_Inferred` |
| **Ghidra name** | `FUN_00968720` |
| **Address** | `0x00968720`–`0x00968831` exclusive (**273 B** / `0x111`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir/graphics — gfxBufferedView / Device Reset |
| **Naming basis** | Product strings `gfxBufferedView.cpp` + “render target” ReCreate failure; parent factory plate `gfxBufferedViews`; list-level not single-view method |
| **Completion status** | **Dual A/B sealed (W38-AA)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

ReCreate render-target textures for all registered gfxBufferedViews after device reset (or Release special-flag textures).

## Signature

```c
int32_t GfxBufferedViews_RecreateRenderTargets_Inferred(void); // always returns 0
```

## Related

| VA | Role |
|---|---|
| `0x009686e0` | release twin (this agent) |
| `0x00968a50` | gfxBufferedView ctor / list insert (W37-I) |
| `0x0096cad0` | ReCreate (starts with release) |
| `0x0075eff0` | GfxDevice_Reset parent (W37-N) |
