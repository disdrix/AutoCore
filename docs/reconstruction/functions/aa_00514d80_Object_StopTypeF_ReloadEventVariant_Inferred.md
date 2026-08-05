# Function record: Object_StopTypeF_ReloadEventVariant_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514d80` |
| **Canonical name** | `Object_StopTypeF_ReloadEventVariant_Inferred` |
| **Ghidra name** | `FUN_00514d80` |
| **Address** | `0x00514d80`–`0x00514df3` |
| **Module** | `autoassault.exe` |
| **System** | client-fx / type-0xF stop + event-variant reload |
| **Completion status** | **dual-sealed** 2026-07-29 W28-H |
| **Dual A/B** | `reviews/A_aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md`, `reviews/B_aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md` |

## Purpose

Type-filtered stop (0xF) on the primary owned FX* vector, then reload event-variant 0xF through sealed FxMaster and hand to virtual apply.

```c
void __thiscall Object_StopTypeF_ReloadEventVariant_Inferred(void *self);
```

## Artifacts

- Named: `docs/reconstruction/reconstructed-exact/Object_StopTypeF_ReloadEventVariant_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00514d80.cpp`
- Raw / annotated under `aa_00514d80_FUN_00514d80*`

## Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_00581500` | `0x00581510` | vb-adjust + call; public **ret 4** |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI sealed | **Confirmed** |
| Event 0xF + LoadEvent linkage | **High** (sealed peer) |
| Product English | **Inferred** |
