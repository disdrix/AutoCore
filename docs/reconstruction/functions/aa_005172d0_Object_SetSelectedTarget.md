# Function record: Object_SetSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_005172d0` |
| **Canonical name** | `Object_SetSelectedTarget` |
| **Address** | `0x005172d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x005172d0`–`0x005173f9` (`int3` at `0x005173fa`) |
| **System** | object / combat-target / HB |
| **Completion status** | **Human-refined + dual A/B** (accept-with-gaps) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra (prior): `FUN_005172d0`
- Scaffold alias: `Named_CalleeOf_Client_Input_DriveControlTick_005172d0`
- Product method string: **not recovered** (name **inferred**)

## Purpose

Set **`entity+0xA0`** selected target when the pointer changes, gated on world + global HB list. Dirties net mask bit 4, purges **`CVOGHBPlayerTargetingLink`** actions from **`entity+0xB0`**, and for non-null non-self targets installs a dual HB pair (self link + target HB) on **`world+0xE4EC`**.

## Signature

```c
void __thiscall Object_SetSelectedTarget(void *pEntity, void *pNewTarget);
// ECX = pEntity (cloned object base)
// stack = pNewTarget (may be NULL to clear)
// ret 4
```

## Layout touches (this body)

| Offset | Role |
|---|---|
| `entity+0x14` | `NetObject*` (optional dirty) |
| `entity+0xA0` | Selected target pointer (R/W) |
| `entity+0xA4` | World/map pointer |
| `entity+0xB0` | `CNDDoubleList` of HB payloads (purge targeting links) |
| `world+0xE4EC` | `CVOGHBList*` enqueue target |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005172d0_Object_SetSelectedTarget.md`
- Annotated: `docs/reconstruction/raw/aa_005172d0_Object_SetSelectedTarget.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_SetSelectedTarget.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005172d0_Object_SetSelectedTarget.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005172d0_Object_SetSelectedTarget.md`
- Report: `docs/agents/task-dual-ab-005172d0-object-setselectedtarget-report.md`

Legacy scaffold (prefer canonical above):  
`aa_005172d0_FUN_005172d0.*`, `FUN_005172d0.cpp`

## Callers / callees

**Callers (15 named / 30 xrefs):**  
`CVOGHBAIBase_FindTargetToAttack`, `Client_Input_DriveControlTick`, `GhostCreature_UnpackUpdate`, `VehicleNet_UnpackGhostVehicle`, `FUN_004c3c80`, `FUN_004c6360`, `FUN_004f8430`, `FUN_00521650`, `FUN_005ccff0`, `FUN_0060a820`, `FUN_00626890`, `FUN_006389b0`, `FUN_00638ac0`, `FUN_0093e120`, `FUN_00944d50`, plus reaction/site xrefs.

**Callees:**  
`NetObject_SetMaskBits`, `CNDDoubleList_InvokePredicateAndRemove_Inferred` (`0x004e2600`), `operator_new`, `FUN_00512090` (PlayerTargetingLink ctor), `FUN_00604d40` (target HB ctor), `FUN_00604db0` (partner link), `CVOGHBList_Enqueue`.  
Predicate not a direct CALL from this body as a nested call target of the list helper: `FUN_005121d0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets from asm | **High** |
| ABI `__thiscall` + `ret 4` | **High** |
| RTTI class of purged links | **High** |
| Parameter semantic names | **High** (role) / product names **Tentative** |
| Inferred function name | **Probable** |
| Net mask bit 4 semantics | **Tentative** |
