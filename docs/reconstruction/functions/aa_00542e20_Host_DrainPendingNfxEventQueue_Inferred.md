# Function record: Host_DrainPendingNfxEventQueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00542e20` |
| **Canonical name** | `Host_DrainPendingNfxEventQueue_Inferred` |
| **Ghidra name** | `FUN_00542e20` |
| **Address** | `0x00542e20`–`0x00543050` (**561 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host pending NFX / special-FX event queue |
| **Wave** | W35-F OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md`, `reviews/B_aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md` |

## Purpose

Drain pending NFX/special-FX event queue on host (ECX): readiness, hash lookup, bind/fire or master reload, list unlink.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `FUN_004ed310` | `0x004ed310` | preload ring readiness (W35-A) |
| `FxMaster_LoadMasterFromXML_Inferred` | `0x004a6390` | NFX reload path |
| `GuardedVector_ResizeZeroFill_Thiscall` | `0x0043d650` | clear node vector (W34-M) |
| `Client` frame | `0x0094b520` | sole caller |

## Signature

```c
void Host_DrainPendingNfxEventQueue_Inferred(Host* self /*ECX*/, void* sessionField /*stack; RET 4*/);
```

## Artifacts

See `aa_00542e20_FUN_00542e20.md` for full paths and confidence table.
