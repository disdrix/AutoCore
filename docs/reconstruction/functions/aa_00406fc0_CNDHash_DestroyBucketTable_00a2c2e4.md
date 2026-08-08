# Function record: CNDHash_DestroyBucketTable_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406fc0` |
| **Canonical name** | `CNDHash_DestroyBucketTable_00a2c2e4` |
| **Ghidra name** | `FUN_00406fc0` |
| **Address** | `0x00406fc0`–`0x00406ff3` (**52 B** / `0x34`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md`, `B_aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-J OWN-ONLY) |

## Alias

- `FUN_00406fc0`

## Purpose

Host-family CNDHash (**vtbl `00a2c2b0`**) **destroy bucket table** helper nested under recreate and dtor. Zeros live count `+0xc`, releases chain nodes to freelist via `FUN_004085e0`, frees contiguous 0xc sentinel slab (`free(*table)`) and pointer array (`delete[]`). Peer of inventory destroy under **EAX** (not skill thiscall).

## Signature (sealed)

```c
// custom EAX = hash*; bare ret
void CNDHash_DestroyBucketTable_00a2c2e4(/* EAX */ void *hash);
```

## Algorithm

1. `*(hash+0x0c) = 0`.
2. `FUN_004085e0` with EBX=hash — freelist-walk chains.
3. If `*(hash+0x10)`: `free(**table)`; `delete[] table`; null `+0x10`.
4. Bare ret (does not write mask/ordered lists/lock).

## Related

- `aa_00406f20` `CNDHash_AllocBucketTable_00a2c2e4` (alloc twin)
- Callers: dtor `FUN_00406420`, Recreate `FUN_004195d0`
- Nested residual: `FUN_004085e0` freelist release
- Parallel: `CNDHash_DestroyBucketTable_Inferred` (`0x00413e20`); contrast `SkillCNDHash_DestroyBucketTable_Inferred` (`0x004cba60`)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
