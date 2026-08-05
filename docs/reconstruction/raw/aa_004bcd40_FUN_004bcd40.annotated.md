# Annotated low-level: FUN_004bcd40 → CNDHash_Recreate_009cb45c

| Field | Value |
|---|---|
| Stable ID | `aa_004bcd40` |
| VA | `0x004bcd40`–`0x004bcd94` (**84 B / `0x54`**) |
| System | container / CNDHash (COList hashA/hashB family; object vtbl `009cb45c`) |
| Date | 2026-07-23 scaffold; **W30-G seal 2026-07-29** |
| Named | `CNDHash_Recreate_009cb45c` |

## Machine-level notes

- Source: raw capture for `aa_004bcd40` + live decompile/`read_memory` W30-G.
- Prefer bytes when decompiler reorders stores vs shift.
- **No** `disassemble_bytes`.
- Lock path is **warn-only** (fall-through), not abort.
- After Alloc, `+0x08` is **mask** `N-1` (callee-owned post-condition, W29-K sealed).

## Control flow (sealed)

```
ESI = this
if (this+0x1D != 0):
  log "HashError:Recreate, already locked for traversal"
  log "VOG_DEBUG_STOP"
  // continue — no return
FUN_004bcca0(this)           // FreeBuckets twin: zero count, reclaim nodes, free table
CL = stack log2
EAX = 1 << CL
this+0x1C = CL               // log2 bits
this+0x18 = 0                // list tail
this+0x08 = EAX              // provisional N = 1<<log2
this+0x14 = 0                // list head
FUN_004bc840(this)           // CNDHash_AllocBucketTable_009cb350 → mask, buckets
ret 4
```

## Layout touched

| Off | Role |
|---|---|
| `+0x08` | provisional N then mask after Alloc |
| `+0x14` | list head zeroed |
| `+0x18` | list tail zeroed |
| `+0x1C` | log2 (u8) stored from arg |
| `+0x1D` | traversal lock (read only; warn if set) |

## Call surface

| Direction | Detail |
|---|---|
| Callees | `FUN_004bcca0`, `FUN_004bc840`, `FUN_007a4480` ×2 |
| Callers | **none** static (dead / no xref in this image) |
| Twin | `CNDHash_Recreate_009cb450` @ `0x004bcce0` |
| Parallel | `CNDHash_Recreate` @ `0x0051d230` (medal; same template) |

## Pseudocode (annotated)

```c
// void __thiscall CNDHash_Recreate_009cb45c(CNDHash *this, byte log2);
// ret 4; destroys contents; empty table sized 1<<log2 (mask after Alloc)
void __thiscall FUN_004bcd40(int thisHash, byte log2)
{
  if (*(char *)(thisHash + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Recreate, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004bcca0(); // FreeBuckets for 009cb45c family
  *(byte *)(thisHash + 0x1c) = log2;
  *(undefined4 *)(thisHash + 0x18) = 0;
  *(int *)(thisHash + 8) = 1 << (log2 & 0x1f);
  *(undefined4 *)(thisHash + 0x14) = 0;
  FUN_004bc840(); // AllocBucketTable_009cb350
  return;
}
```

## Open residual

- Product / PDB English beyond Recreate string + stamp family.
- FreeBuckets body `FUN_004bcca0` not OWN (template sealed as twin of medal FreeBuckets).
- Zero static callers — runtime / dead-code status open.
- Runtime / bit-exact open.
