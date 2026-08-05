# Annotated low-level: CNDHash_Ctor_009cb45c (FUN_004bcf90)

| Field | Value |
|---|---|
| Stable ID | `aa_004bcf90` |
| VA | `0x004bcf90`–`0x004bd001` (**114 B / `0x72`) |
| Ghidra | `FUN_004bcf90` |
| Canonical | `CNDHash_Ctor_009cb45c` |
| System | container / CNDHash (COList nested hashA/hashB; vtbl `009cb45c`) |
| Date | 2026-07-29 W28-J |

## Machine-level notes

- SEH prolog `6A FF 68 EB 16 9A 00` (`LAB_009a16eb`) shared with twin `FUN_004bce90`.
- `56 8B F1` — thiscall; ESI = this.
- `8A 4C 24 18` — log2 from stack slot after SEH frame.
- `BA 01 00 00 00 / D3 E2` — N = `1 << log2` (CL masked by x86 shift to 5 bits).
- `C7 06 5C B4 9C 00` — install `PTR_FUN_009cb45c`.
- Zero +0x04, +0x0C, +0x10, +0x14, +0x18, +0x20, +0x28, +0x2C, +0x30; store log2 at +0x1C; clear lock +0x1D.
- **No store to +0x24** (same residual as other CNDHash ctors).
- `8B CE; E8 …` → `FUN_004bc840` AllocBucketTable-class helper (bucket heads stamped `PTR_LAB_009cb350`; validates `0 < log2 < 0x11`).
- Epilogue restores SEH, `ADD ESP,0x10`, **`RET 4`**, EAX=this.
- Sole production caller: `COList_Constructor` (`FUN_004bbfb0`) for optional tables at host +0x04 / +0x08; allocation size **0x34**.

## Pseudocode (annotated)

```c
// __thiscall; stack byte log2; ret 4; returns this
void *CNDHash_Ctor_009cb45c(void *thisHash, uint8_t log2)
{
  // SEH LAB_009a16eb
  uint32_t *p = (uint32_t *)thisHash;
  p[0] = (uint32_t)&PTR_FUN_009cb45c;     // +0x00 vtbl
  p[1] = 0;                               // +0x04
  p[3] = 0;                               // +0x0C
  p[2] = 1u << (log2 & 0x1f);             // +0x08 provisional N
  p[4] = p[5] = p[6] = 0;                 // +0x10 buckets*, +0x14, +0x18
  *(uint8_t *)(p + 7) = log2;             // +0x1C
  *((uint8_t *)p + 0x1d) = 0;             // traversal lock
  p[8] = 0;                               // +0x20 freelist
  // +0x24 not written
  p[10] = p[11] = p[12] = 0;             // +0x28..+0x30
  FUN_004bc840(thisHash);                 // AllocBucketTable → mask N-1 + table
  return thisHash;
}
```

## Twin / family

| VA | Role |
|---|---|
| `0x004bce90` | `CNDHash_Ctor_009cb450` — same body; vtbl `009cb450`; Alloc `FUN_004bc7a0` |
| `0x0051db60` | `CNDHash_Ctor_009ce1a0` — medal-family stamp twin (W26-P) |
| `0x004bc840` | AllocBucketTable for this stamp (not OWN) |
| `0x004bbfb0` | COList_Constructor sole caller |

## Open gaps

- Full vtbl method English matrix at `009cb45c` (scalar dtor `004bd120`, RemoveAll-class `004bd010` observed only as sibling context).
- Product / PDB class name beyond CNDHash family inference.
- Semantic of unwritten `+0x24`.
- Runtime / bit-exact / differential.
