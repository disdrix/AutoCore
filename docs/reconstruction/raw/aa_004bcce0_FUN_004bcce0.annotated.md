# Annotated low-level: FUN_004bcce0 → CNDHash_Recreate_009cb450

| Field | Value |
|---|---|
| Stable ID | `aa_004bcce0` |
| VA | `0x004bcce0`–`0x004bcd34` (**84 B / `0x54`**) |
| System | container / CNDHash (COList tableC family; object vtbl `009cb450`) |
| Date | 2026-07-23 scaffold; **W30-G seal 2026-07-29** |
| Named | `CNDHash_Recreate_009cb450` |

## Machine-level notes

- Source: raw capture for `aa_004bcce0` + live decompile/`read_memory` W30-G.
- **No** `disassemble_bytes`.
- Lock path is **warn-only** (fall-through).
- After Alloc, `+0x08` is **mask** `N-1` (W29-K sealed for `FUN_004bc7a0`).
- Sole static consumer always passes **log2=5** (N=32 → mask 31).

## Control flow (sealed)

```
ESI = this
if (this+0x1D != 0): log Recreate-locked + VOG_DEBUG_STOP; continue
FUN_004bcc60(this)           // FreeBuckets twin
CL = stack log2
EAX = 1 << CL
this+0x1C = CL; +0x18 = 0; +0x08 = EAX; +0x14 = 0
FUN_004bc7a0(this)           // CNDHash_AllocBucketTable_009cb348
ret 4
```

## Layout touched

Same as twin `004bcd40` (`+0x08/+0x14/+0x18/+0x1C` write; `+0x1D` read).

## Call surface

| Direction | Detail |
|---|---|
| Callees | `FUN_004bcc60`, `FUN_004bc7a0`, `FUN_007a4480` ×2 |
| Callers | `FUN_004bbeb0` @ `0x004bbeb8` → **`Recreate(5)`** only |
| Twin | `CNDHash_Recreate_009cb45c` @ `0x004bcd40` |
| Parallel | `CNDHash_Recreate` @ `0x0051d230` |

## Pseudocode (annotated)

```c
// void __thiscall CNDHash_Recreate_009cb450(CNDHash *this, byte log2);
// ret 4
void __thiscall FUN_004bcce0(int thisHash, byte log2)
{
  if (*(char *)(thisHash + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Recreate, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004bcc60(); // FreeBuckets for 009cb450 family
  *(byte *)(thisHash + 0x1c) = log2;
  *(undefined4 *)(thisHash + 0x18) = 0;
  *(int *)(thisHash + 8) = 1 << (log2 & 0x1f);
  *(undefined4 *)(thisHash + 0x14) = 0;
  FUN_004bc7a0(); // AllocBucketTable_009cb348
  return;
}
```

## Open residual

- Product English; FreeBuckets `FUN_004bcc60` not OWN.
- Host role of `FUN_004bbeb0` (COList clear/recreate path) not OWN.
- Runtime / bit-exact open.
