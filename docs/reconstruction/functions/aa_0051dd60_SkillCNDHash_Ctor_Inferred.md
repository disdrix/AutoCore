# Function record: SkillCNDHash_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051dd60` |
| **Canonical name** | `SkillCNDHash_Ctor_Inferred` |
| **Ghidra name** | `FUN_0051dd60` |
| **Address** | `0x0051dd60`–`0x0051ddd2` (**115 B** / `0x73`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md`, `B_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9D-A OWN-ONLY) |

## Alias

- `FUN_0051dd60`
- Scaffold `Named_CalleeOf_…_0051dd60` (**do not promote**)

## Purpose

Skill-family CNDHash **constructor** for a pre-allocated `0x34`-byte block. Installs **`PTR_FUN_009ce1b8`**, initializes log2 (`+0x1c`), provisional bucket count (`+0x08 = 1<<log2`), clears lock (`+0x1d`), zeros list/table slots, then `FUN_004cb410` allocates empty buckets (mask post-condition). **Does not write `+0x24`** (preserved oddity).

## Signature (sealed)

```c
void *__thiscall SkillCNDHash_Ctor_Inferred(void *block, unsigned char log2);
// returns this in EAX; ret 4; SEH LAB_009a371b
```

## Algorithm

1. SEH install.
2. Vtbl + field init (see clean; skip `+0x24`).
3. `FUN_004cb410(this)`.
4. Return this; `ret 4`.

## Related

- `aa_004cbdc0` `SkillCNDHash_Recreate_Inferred`
- `aa_00518e30` `Object_CreateOrRecreateSkillHash_Inferred` (sole caller)
- Scalar dtor peer `FUN_0051de60` (not dualled)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
