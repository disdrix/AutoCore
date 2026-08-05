# Function record: WorldObj_RebindActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560e90` |
| **Canonical name** | `WorldObj_RebindActivate_Inferred` |
| **Prior / Ghidra name** | `FUN_00560e90` |
| **Address** | `0x00560e90`–`0x00560eb1` (**34 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / phys rebind |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W24-B OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00560e90`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00560e90` (xref-path noise; not product role)

## Purpose

Manager **unbind → rebind → set linked flag** for a world/phys object:

1. `FUN_0055fbf0(manager, obj)` unbind
2. `FUN_0055fa40(manager, obj)` rebind
3. `*(uint8_t*)(*(obj+0x44)+0x28) = 1`

Used after phys wake/recreate and special-event airlift mode restore — not a full enroll (no counters/refcount; see `00560ec0`).

## Signature (sealed)

```c
// __thiscall manager (ECX); stack (Object* obj, int unused); ret 8; void
void WorldObj_RebindActivate_Inferred(void* manager /*ECX*/, void* obj /*stack*/ /*, int unused*/);
```

## Flag

| Path | Value |
|---|---|
| `*(obj + 0x44) + 0x28` | `uint8` set to **1** |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560e90_FUN_00560e90.md` |
| Annotated | `docs/reconstruction/raw/aa_00560e90_FUN_00560e90.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/WorldObj_RebindActivate_Inferred.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00560e90.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00560e90_FUN_00560e90.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `FUN_0055fbf0` | unbind |
| Callee | `FUN_0055fa40` | bind (also used by enroll) |
| Caller | `CVOGHBRecreateObject_RecreateOwner` | `0x005dac00` |
| Caller | `ClientSpecialEvent_Respawn_TeardownAirlift` | `0x00979290` |
| Caller | `ClientSpecialEvent_Respawn_SetupAirlift` | `0x00979310` |
| Caller | `FUN_0053dbb0`, `FUN_004c4880`, `FUN_005f44c0`, … | phys/net family |

## Confidence

| Claim | Level |
|---|---|
| CF: unbind → rebind → flag=1 | **High** |
| ECX=manager, stack obj, ret 8 | **High** |
| Second stack formal unread | **High** residual |
| Product English plate name | **Inferred** |
| Runtime / bit-exact | **Open** |
