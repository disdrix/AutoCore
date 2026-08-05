# Function record: AssPreloader_PendingRemoveWithSideNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971030` |
| **Canonical name** | `AssPreloader_PendingRemoveWithSideNotify_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00971030` |
| **Address** | `0x00971030`–`0x0097104e` |
| **Body** | **30 B** / `0x1E` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | AssPreloader / client-fx preload |
| **Completion status** | **Dual-reviewed** W36-D — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Two-step pending-side remove: side-host flag0 notify, then first-equal erase on pending ring `preloader+0x1C`.

## Signature

```c
void AssPreloader_PendingRemoveWithSideNotify_Inferred(
    void* preloader /*ECX*/,
    const int* key /*stack*/);  // RET 0x4
```

## Naming evidence

- Nested duals: `SideHost_PushKeyFlag0_Inferred`, `GuardedVector_EraseFirstEqual_ThiscallRange`.
- Sole caller `AssPreloader_ProcessKeyRingStep_Inferred` (W35-A) on tracked+flag path.
- Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971030`.

## Artifacts

- See `aa_00971030_FUN_00971030.md`.
