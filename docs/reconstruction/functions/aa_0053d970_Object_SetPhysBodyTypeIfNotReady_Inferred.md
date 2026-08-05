# Function record: Object_SetPhysBodyTypeIfNotReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053d970` |
| **Canonical name** | `Object_SetPhysBodyTypeIfNotReady_Inferred` |
| **Ghidra symbol** | `FUN_0053d970` |
| **Address** | `0x0053d970` |
| **Body range** | `0x0053d970`–`0x0053d9ac` (`RET 4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / entity shell (type-6 soft path; multi-class) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (2026-07-29); machine CF sealed; product names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | **Present** — `reviews/A_aa_0053d970_*`, `reviews/B_aa_0053d970_*` |

## Alias

- `FUN_0053d970`
- Prior scaffold: `Named_CalleeOf_CVOGSpawnPoint_CreateCreature_0053d970`
- Partition label: “Vehicle type-6 cleanup” (caller pattern; not “always set type 6”)

## Purpose

If the object’s physics shell (`entity+0x08`) is present and **not fully ready** (`phys+0x40==0` **or** `phys+0x08==0`), tail-call `FUN_005d4440(phys, targetType)` where **targetType = 1 if flag==0 else 6**. Fully ready or null phys → no-op.

## Signature (machine-derived)

```c
/* __thiscall: ECX = entity; stack flag cleaned by RET 4 */
void __thiscall Object_SetPhysBodyTypeIfNotReady_Inferred(
    void *entity,
    int   flag);   /* 0 → request type 1; nonzero → request type 6 */
```

## Algorithm

```
phys = *(entity + 0x08)
if (!phys) return
if (phys->byte40 != 0 && phys->ptr08 != 0) return   // fully ready
target = (flag == 0) ? 1 : 6
jmp FUN_005d4440(phys, target)   // tail; ECX=phys
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053d970_FUN_0053d970.md` (re-verify append 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_0053d970_FUN_0053d970.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0053d970.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md`
- Agent report: `docs/agents/task-dual-ab-0053d970-object-setphysbodytypeifnotready-report.md`
- Related soft-ready twin: `docs/reconstruction/physics/verified/fn_0053eec0_networkApply.md`
- Related caller dual: `docs/reconstruction/reviews/A_aa_00504c70_Vehicle_setDrivingInputs.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Callee | `FUN_005d4440` @ `0x005d4440` | Body/AI type switcher; leave-FUN for dual |
| Callers | 20+ / **22** xrefs | Vehicle ghost, activate, creature post-create, spawn, respawn, camera, … |

Representative flags:

| Caller | Flag | Effective type request |
|---|---|---|
| `Vehicle_setDrivingInputs` (after type==6) | 0 | **1** (leave type-6 soft) |
| `FUN_005057c0` (type==6) | 0 | **1** |
| `CVOGCreature_PostCreateFromPacket` | 1 | **6** |
| `CVOGSpawnPoint_CreateTemplateVehicle` | 1 | **6** |

## Confidence

| Claim | Level |
|---|---|
| Control flow from **machine** (`read_memory`) | **High** |
| Flag → {1,6} map | **High** |
| Soft-ready gate (`+0x40` / `+0x08`) | **High** |
| Tail to 5d4440 with phys this | **High** |
| `__thiscall` + `RET 4` | **High** |
| Decompiler completeness | **Falsified** (insufficient alone) |
| Parameter product names / type enum English | **Tentative / open** |
| Runtime | **Open** |
