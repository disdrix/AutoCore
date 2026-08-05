# Function record: EffectHandle_SetSlot_CoW_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970060` |
| **Canonical name** | `EffectHandle_SetSlot_CoW_Inferred` |
| **Address** | `0x00970060`–`0x009700a8` (**73 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / device-effect parameter slot bind |
| **Completion status** | **Dual A/B sealed** (W38-P, 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Ghidra name** | `FUN_00970060` |
| **Rejected alias** | `Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00970060` |

## Purpose

ESI-this effect-handle helper: CoW if binder shared (`0096fdf0`), set parameter slot (`007528f0(index, resource)`), optional parent rebind via `00448fc0` when set returns -1 after CoW. Used to clear/bind named effect params (e.g. `DiffuseTexture` → index, resource 0).

## Signature

```c
// ESI = EffectHandle*; stack (slotIndex, resource*); ret 8; EAX = 0|-1
int32_t EffectHandle_SetSlot_CoW_Inferred(void* handle /*ESI*/, int32_t slotIndex, void* resource);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00970060_FUN_00970060.md`
- Annotated: `docs/reconstruction/raw/aa_00970060_FUN_00970060.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EffectHandle_SetSlot_CoW_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00970060.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md`
- Function twin: `docs/reconstruction/functions/aa_00970060_FUN_00970060.md`

## Callers / callees

- **Callees:** `FUN_0096fdf0`, `FUN_007528f0`, `FUN_00448fc0`.
- **Callers (8):** `FUN_0075bf40` (GfxView clear DiffuseTexture), `FUN_00970140`, `FUN_007a2580`, `FUN_009521c0`, `FUN_00988860`, `FUN_009887a0`, `FUN_0073cb70`, `FUN_0073cd70`.

## Confidence

| Claim | Level |
|---|---|
| Body 73 B / `ret 8` | Confirmed |
| ESI this + 2 stack args | Confirmed |
| CoW → set-slot order | Confirmed |
| Status 0 / -1 | Confirmed |
| Product effect class English | Open |
