# Function record: Object_CreateCreatureLoadSkills_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8f00` |
| **Canonical name** | `Object_CreateCreatureLoadSkills_Inferred` |
| **Ghidra name** | `FUN_004c8f00` |
| **Address** | `0x004c8f00`–`0x004c9113` (**532 B** / `0x214`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md`, `B_aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9E-H OWN-ONLY) |

## Alias

- `FUN_004c8f00`
- `Named_VOG_DEBUG_STOP_004c8f00` (scaffold; reject as product identity)
- `Mission_CVOGClonedObjectBase_RTTI_Type_Descriptor` (false domain rename; reject)

## Purpose

Create a `CVOGCreature` from the source clone-base embedded CBID factory, copy combat/identity fields, recreate destination skill CNDHash at **log2=2**, traverse-lock the source skill hash and `Skill_EnsureLoadedInTree` each skill. Second CODE site of `SkillCNDHash_Recreate_Inferred`.

## Signature (sealed)

```c
void * __thiscall Object_CreateCreatureLoadSkills_Inferred(void *sourceThis);
// plain RET; returns creature primary* or 0
```

## Algorithm

1. Factory `Object_CreateFromEmbeddedCbid_Inferred` on MI subobject `source-0x4fc`.
2. `__RTDynamicCast` → `CVOGCreature`; fail → VOG_DEBUG_STOP, return 0.
3. Copy vtbl-derived stats and selected fields onto creature.
4. `SkillCNDHash_Recreate_Inferred(destHash@+0x70, 2)`.
5. Lock source hash `+0x1d`; ordered walk; EnsureLoadedInTree; unlock.
6. Return dest MI primary.

## Related

- `aa_0051b230` `Object_CreateFromEmbeddedCbid_Inferred` (factory callee)
- `aa_004cbdc0` `SkillCNDHash_Recreate_Inferred` (recreate; this is second caller)
- `aa_00518e30` `Object_CreateOrRecreateSkillHash_Inferred` (primary recreate path)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
