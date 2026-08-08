# Function record: SkillCNDHash_AllocBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb410` |
| **Canonical name** | `SkillCNDHash_AllocBucketTable_Inferred` |
| **Ghidra name** | `FUN_004cb410` |
| **Address** | `0x004cb410`–`0x004cb4a0` (**145 B** / `0x91`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md`, `B_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9E-A OWN-ONLY) |

## Alias

- `FUN_004cb410`

## Purpose

Skill-family CNDHash **alloc empty bucket table** nested under recreate and ctor. Requires log2 `@+0x1c` in **[1,16]**; builds `N=*(+8)` pointer slots + contiguous 0xc sentinels stamped **`PTR_LAB_009cb970`**; post-condition **`*(+8) = N-1` (mask)**. Out-of-range log2 → `VOG_DEBUG_STOP` + throw `0x80004003`. Parallel to medal/inventory `CNDHash_AllocBucketTable_*` (different VA/stamp).

## Signature (sealed)

```c
void __thiscall SkillCNDHash_AllocBucketTable_Inferred(void *hash);
// bare ret on success; noreturn on bad log2
```

## Algorithm

1. Gate log2 ∈ 1..16 else log+throw.
2. `new[](N*4)` → `+0x10`; `malloc(N*0xc)` slab.
3. Init each sentinel: stamp `009cb970`, next=0, val=0.
4. `*(+8)--` → mask.
5. Bare ret.

## Related

- `aa_004cba60` `SkillCNDHash_DestroyBucketTable_Inferred` (destroy twin)
- `aa_004cbdc0` `SkillCNDHash_Recreate_Inferred`
- `aa_0051dd60` `SkillCNDHash_Ctor_Inferred`
- Parallel: `CNDHash_AllocBucketTable_009ce090` / `CNDHash_AllocBucketTable_Inferred`

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
