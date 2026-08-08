# Function record: SkillCNDHash_DestroyBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba60` |
| **Canonical name** | `SkillCNDHash_DestroyBucketTable_Inferred` |
| **Ghidra name** | `FUN_004cba60` |
| **Address** | `0x004cba60`–`0x004cba93` (**52 B** / `0x34`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md`, `B_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9E-A OWN-ONLY) |

## Alias

- `FUN_004cba60`

## Purpose

Skill-family CNDHash **destroy bucket table** helper nested under recreate and dtor. Zeros live count `+0xc`, releases chain nodes to freelist via `FUN_004cb680`, frees contiguous 0xc sentinel slab (`free(*table)`) and pointer array (`delete[]`). Peer of inventory `CNDHash_DestroyBucketTable_Inferred` (`0x00413e20`) under **thiscall ECX** (not EAX).

## Signature (sealed)

```c
void __thiscall SkillCNDHash_DestroyBucketTable_Inferred(void *hash);
// bare ret
```

## Algorithm

1. `*(hash+0x0c) = 0`.
2. `FUN_004cb680(hash)` — freelist-walk chains.
3. If `*(hash+0x10)`: `free(**table)`; `delete[] table`; null `+0x10`.
4. Bare ret (does not write mask/ordered lists/lock).

## Related

- `aa_004cb410` `SkillCNDHash_AllocBucketTable_Inferred` (alloc twin)
- `aa_004cbdc0` `SkillCNDHash_Recreate_Inferred` (primary recreate caller)
- `aa_00413e20` inventory destroy twin (ABI contrast)
- Nested residual: `FUN_004cb680` freelist release

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
