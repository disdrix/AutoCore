# Function record: FUN_004cba60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba60` |
| **Canonical name** | `FUN_004cba60` (Ghidra); prefer named `SkillCNDHash_DestroyBucketTable_Inferred` |
| **Address** | `0x004cba60`–`0x004cba93` (**52 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (WQ9E-A 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md`, `B_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9E-A OWN-ONLY) |

## Alias

- Ghidra: `FUN_004cba60`
- Named: `SkillCNDHash_DestroyBucketTable_Inferred`

## Purpose

Destroy skill-family CNDHash bucket table: zero live count `@+0xc`, freelist-release chains (`FUN_004cb680`), `free` slab + `delete[]` pointer array.

## Signature

```c
void __thiscall FUN_004cba60(void *hash);
// stack cleanup: bare ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cba60_FUN_004cba60.md`
- Annotated: `docs/reconstruction/raw/aa_004cba60_FUN_004cba60.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillCNDHash_DestroyBucketTable_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cba60.cpp`
- Function named: `docs/reconstruction/functions/aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_004cb680`, `free`, `operator_delete[]` |
| **Callers** | `FUN_004cbdc0` (`SkillCNDHash_Recreate_Inferred`), `FUN_0051de80` (skill hash dtor body) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| thiscall + bare ret | **High** |
| Role destroy bucket table | **High** |
| Product English class | **Open** |
