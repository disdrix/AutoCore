# Function record: CNDHash_Recreate_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_004195d0` |
| **Canonical name** | `CNDHash_Recreate_00a2c2e4` |
| **Ghidra name** | `FUN_004195d0` |
| **Address** | `0x004195d0`–`0x00419618` (**73 B** / `0x49`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004195d0_CNDHash_Recreate_00a2c2e4.md`, `B_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-E OWN-ONLY) |

## Alias

- `FUN_004195d0`

## Purpose

Host-family CNDHash (**vtbl `00a2c2b0`**, stamp **`00a2c2e4`**) **recreate** nested under post-traversal cleanup (`FUN_007fe640` seeds log2=**2**). Soft-logs if already locked; destroy + re-seed + alloc via dualed bucket helpers. Parallel to inventory `FUN_004138d0` (same ABI, different helpers) and skill thiscall recreate (different ABI).

## Signature (sealed)

```c
// custom: EAX = CNDHash*; BL = log2; bare ret
void CNDHash_Recreate_00a2c2e4(/* EAX */ void *hash, /* BL */ uint8_t log2);
```

## Algorithm

1. If lock `@+0x1d`: log Recreate HashError + `VOG_DEBUG_STOP`; continue.
2. Destroy bucket table (`00406fc0`, EAX).
3. Store log2 `@+0x1c`; provisional count `1<<log2` `@+8`; clear ordered `@+0x14`/`@+0x18`.
4. Alloc bucket table (`00406f20`, ESI) → mask at `@+8`.
5. Bare ret.

## Related

- `aa_00406f20` `CNDHash_AllocBucketTable_00a2c2e4`
- `aa_00406fc0` `CNDHash_DestroyBucketTable_00a2c2e4`
- Caller residual: `FUN_007fe640`
- Parallel: inventory `FUN_004138d0`; skill `SkillCNDHash_Recreate_Inferred`

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
