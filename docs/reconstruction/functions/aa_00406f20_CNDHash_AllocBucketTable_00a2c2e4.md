# Function record: CNDHash_AllocBucketTable_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406f20` |
| **Canonical name** | `CNDHash_AllocBucketTable_00a2c2e4` |
| **Ghidra name** | `FUN_00406f20` |
| **Address** | `0x00406f20`–`0x00406faf` (**144 B** / `0x90`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md`, `B_aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-J OWN-ONLY) |

## Alias

- `FUN_00406f20`

## Purpose

Host-family CNDHash (**vtbl `00a2c2b0`**) **alloc empty bucket table** nested under recreate and ctor. Requires log2 `@+0x1c` in **[1,16]**; builds `N=*(+8)` pointer slots + contiguous 0xc sentinels stamped **`PTR_LAB_00a2c2e4`**; post-condition **`*(+8) = N-1` (mask)**. Out-of-range log2 → `VOG_DEBUG_STOP` + throw `0x80004003`. Parallel to skill/medal/inventory alloc twins (different VA/stamp/ABI).

## Signature (sealed)

```c
// custom ESI = hash*; bare ret on success; noreturn on bad log2
void CNDHash_AllocBucketTable_00a2c2e4(/* ESI */ void *hash);
```

## Algorithm

1. Gate log2 ∈ 1..16 else log+throw.
2. `new[](N*4)` → `+0x10`; `malloc(N*0xc)` slab.
3. Init each sentinel: stamp `00a2c2e4`, next=0, val=0.
4. `*(+8)--` → mask.
5. Bare ret.

## Related

- `aa_00406fc0` `CNDHash_DestroyBucketTable_00a2c2e4` (destroy twin)
- Callers: ctor `FUN_004063a0`, Recreate `FUN_004195d0`
- Parallel: `SkillCNDHash_AllocBucketTable_Inferred` (`0x004cb410`); `CNDHash_AllocBucketTable_009cb348`; `CNDHash_AllocBucketTable_Inferred` (`0x00413d80`)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
