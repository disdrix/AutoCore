# Function record: Object_CreateOrRecreateSkillHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518e30` |
| **Canonical name** | `Object_CreateOrRecreateSkillHash_Inferred` |
| **Ghidra name** | `FUN_00518e30` |
| **Address** | `0x00518e30` |
| **Body range** | `0x00518e30`–`0x00518ebe` exclusive (**142 B** / `0x8E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md`, `B_aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9R-J OWN-ONLY) |

## Alias

- `FUN_00518e30`
- Scaffold auto callee-chain name (**do not promote**)

## Purpose

Owner-side helper for skill-tree hash lifecycle at `+0x70`:

- **Present:** thiscall recreate on the hash (`FUN_004cbdc0`) with caller log2 — empties/resizes table (string family *HashError:Recreate…*).
- **Absent:** `new(0x34)` + skill-family ctor `FUN_0051dd60(log2)` → store pointer; OOM stores null.

## Signature

```c
void __thiscall Object_CreateOrRecreateSkillHash_Inferred(void *owner, unsigned char log2);
// stack cleanup: ret 4
```

## Algorithm

1. SEH install.
2. If `*(owner+0x70) != 0`: `FUN_004cbdc0(*(owner+0x70), log2)`; ret 4.
3. Else `block = operator_new(0x34)`:
   - non-null → `*(owner+0x70) = FUN_0051dd60(block, log2)`
   - null → `*(owner+0x70) = 0`
4. ret 4.

## Related

- `aa_0051b550` `Object_LoadCloneBaseSkillTrio_Inferred` (push 1)
- `aa_0051a980` `Skill_EnsureLoadedInTree` (consumes same `+0x70`)
- `aa_00517400` `Object_RefreshSkillHash_Inferred`
- Inventory CNDHash recreate duals (same recreate string; different class/vtbl)
