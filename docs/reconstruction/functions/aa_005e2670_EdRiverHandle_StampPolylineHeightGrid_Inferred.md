# Function record: EdRiverHandle_StampPolylineHeightGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e2670` |
| **Canonical name** | `EdRiverHandle_StampPolylineHeightGrid_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_005e2670` |
| **Address** | `0x005e2670`–`0x005e29c8` |
| **Body** | **856 B** / `0x358` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Editor river-handle / map height grid |
| **Completion status** | **Dual-reviewed** W36-D — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Editor river-handle polyline stamp: chain walk → circular segment list → influence stamp (`006442c0`) → u16 requant → tile invalidate (`004a8d40`) → chain release.

## Signature

```c
void EdRiverHandle_StampPolylineHeightGrid_Inferred(
    void* host /*ECX*/,
    void* map /*stack0*/,
    uint32_t argA,
    float argB,
    uint32_t argC);  // RET 0x10
```

## Naming evidence

- Vtable neighborhood string `ed_riverhandle.g*` @ ~`0x009dc9c0`.
- Sibling scaffold `FUN_005e2390` embeds `"ed_riverhandle.geo"`.
- Reject scaffold plate if any `Named_CalleeOf_*` — this unit is vtable-dispatched, not a named-callee chain leaf.

## Artifacts

- Raw / annotated / clean / twin / A / B — see `aa_005e2670_FUN_005e2670.md`.
