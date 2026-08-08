# Function record: CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004085e0` |
| **Canonical name** | `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` |
| **Ghidra name** | `FUN_004085e0` |
| **Address** | `0x004085e0`–`0x00408635` exclusive (**85 B** / `0x55`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md`, `B_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-A OWN-ONLY) |

## Alias

- `FUN_004085e0`

## Purpose

Host-family CNDHash (**vtbl `00a2c2b0`**, node stamp **`PTR_FUN_00a2c2bc`**) **release all bucket chains to freelist**. Nested under destroy-bucket-table and (via that) dtor / Recreate. Does **not** free the table or zero live count — parent `00406fc0` owns those steps.

## Signature (sealed)

```c
// custom EBX = hash*; bare ret
void CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred(/* EBX */ void *hash);
```

## Algorithm

1. `bucket = 0`; do-while `bucket <= *(hash+0x08)` (mask).
2. `node = *( *(hash+0x10)[bucket] + 4 )` — chain head.
3. While node: save `next = node[4]`; `*node = &PTR_FUN_00a2c2bc`; if `node[3]` → `operator_delete`; `node[3]=0`; freelist push via `*node = *(hash+0x20); *(hash+0x20)=node`; advance.
4. Clear chain head; bare ret.

## Related

| Link | VA / name |
|---|---|
| Parent destroy | `0x00406fc0` `CNDHash_DestroyBucketTable_00a2c2e4` |
| Grandparent dtor | `0x00406420` |
| Grandparent Recreate | `0x004195d0` |
| Alloc twin chain | `0x00406f20` |

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report `docs/agents/task-dual-ab-004085e0-00408050-wq9ha-report.md`
