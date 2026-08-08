# Function record: Object_LoadCloneBaseSkillTrio_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b550` |
| **Canonical name** | `Object_LoadCloneBaseSkillTrio_Inferred` |
| **Ghidra name** | `FUN_0051b550` |
| **Address** | `0x0051b550` |
| **Body range** | `0x0051b550`–`0x0051b5d0` exclusive (**128 B** / `0x80`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md`, `B_aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9R-J OWN-ONLY) |

## Alias

- `FUN_0051b550`
- Scaffold auto name `Named_CalleeOf_Skill_Uses_Skill_EnsureLoadedInTree_0051b550` (**do not promote**)

## Purpose

Shared virtual method used at start of bulk skill loadout (`FUN_004c8a60`): reset skill CNDHash, then materialize three clonebase-default skills into the owner tree with class-specific ranks.

## Signature

```c
void __thiscall Object_LoadCloneBaseSkillTrio_Inferred(void *thisOwner);
```

## Algorithm

1. `Object_CreateOrRecreateSkillHash_Inferred(this, 1)` — wipe or create hash at `this+0x70`.
2. `cloneBase = *(*(this+0xA8)+0x3C)`.
3. For offsets `{0x3BC, 0x3C0, 0x3C4}` paired with vtbl methods `{0x264, 0x268, 0x26C}`:
   - `skillId = *(cloneBase + off)`
   - `rank = (byte) vcall(this)`
   - `Skill_EnsureLoadedInTree(this, skillId, rank)`

## Artifacts

- Raw / annotated / clean / scaffold twin / reviews / report — see `aa_0051b550_FUN_0051b550.md`

## Related

- `aa_00518e30` `Object_CreateOrRecreateSkillHash_Inferred` (owned same wave)
- `aa_0051a980` `Skill_EnsureLoadedInTree`
- `aa_004c8a60` bulk loadout walk (caller)
- `aa_00517400` `Object_RefreshSkillHash_Inferred` (same `+0x70` hash, different role)
