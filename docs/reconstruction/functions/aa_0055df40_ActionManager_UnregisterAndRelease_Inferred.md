# Function record: ActionManager_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055df40` |
| **Canonical name** | `ActionManager_UnregisterAndRelease_Inferred` |
| **Ghidra name** | `FUN_0055df40` |
| **Address** | `0x0055df40` |
| **Body range** | `0x0055df40`–`0x0055df76` exclusive (**54** / `0x36` B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle / world action lifecycle |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md`, `reviews/B_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W23-P) |

## Alias

- `FUN_0055df40`
- `Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0055df40` (legacy parent-seed scaffold — **misleading**)
- Role: unregister action from manager + reverse list, clear `+0xC`, release short ref `@+6`

## Purpose

Given action manager `this` and action object pointer:

1. Notify manager listener table via `FUN_0062a410` (`manager+0x3c` / count `+0x40`, each `vtbl+0xC(action)`).
2. Remove action from reverse host list via `FUN_00628f10` with `this = *(action+0x10)`.
3. Decrement action short refcount at `+6`; store `0` at action `+0xC`.
4. If refcount hits 0, call `(*action->vtbl[0])(action, 1)`.

## Signature

```c
void __thiscall ActionManager_UnregisterAndRelease_Inferred(
    void *manager,   // ECX — often *(world + 0xe4a4)
    void *action);   // [esp+4]
// RET 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055df40_FUN_0055df40.md` (+ W23-P append)
- Annotated: `docs/reconstruction/raw/aa_0055df40_FUN_0055df40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ActionManager_UnregisterAndRelease_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0055df40.cpp`
- Legacy: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0055df40.cpp`
- Review A/B: as above
- Scaffold record: `docs/reconstruction/functions/aa_0055df40_FUN_0055df40.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0062a410` @ `0x0062a410`, `FUN_00628f10` @ `0x00628f10` |
| **Callers** | `FUN_004f7d60` (Vehicle_DestroyVehicleAction_Inferred), `FUN_00507830`, `FUN_006427e0`, `FUN_00642860`; xref `0x00636280` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body bytes | **High** |
| `__thiscall` + `ret 4` | **High** |
| ECX = manager, stack = action | **High** (call sites + prologue) |
| short ref `@+6`, clear `@+0xC`, vtbl[0](1) | **High** |
| `FUN_00628f10` this = `*(action+0x10)` | **High** (bytes; decomp residual) |
| Manager often `*(world+0xe4a4)` | **High** (createVehicleAction / destroy call sites) |
| Product English name | **Inferred** |
| Runtime / differential | Open |

## Related

- Parent dual: `A/B_aa_004f7d60_Vehicle_DestroyVehicleAction_Inferred`
- createVehicleAction framework slot: `*( *(base+0xa8) + 0xe4a4 )` (`fn_004fb660_createVehicleAction.md`)
