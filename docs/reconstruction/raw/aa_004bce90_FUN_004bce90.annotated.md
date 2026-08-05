# Annotated low-level: CNDHash_Ctor_009cb450 (FUN_004bce90)

| Field | Value |
|---|---|
| Stable ID | `aa_004bce90` |
| VA | `0x004bce90`–`0x004bcf01` (**114 B / `0x72`) |
| Ghidra | `FUN_004bce90` |
| Canonical | `CNDHash_Ctor_009cb450` |
| System | container / CNDHash (COList nested tableC; vtbl `009cb450`) |
| Date | 2026-07-29 W28-J |

## Machine-level notes

- Byte-identical to `FUN_004bcf90` except two immediates: vtbl and call target.
- SEH prolog `6A FF 68 EB 16 9A 00` (`LAB_009a16eb`) shared with twin.
- `C7 06 50 B4 9C 00` — install `PTR_FUN_009cb450`.
- Call `E8 B1 F8 FF FF` @ `0x004bcee6` → `FUN_004bc7a0` (AllocBucketTable twin; bucket heads stamped `PTR_LAB_009cb348`).
- Field init identical to `CNDHash_Ctor_009cb45c` including unwritten `+0x24`.
- Sole production caller: `COList_Constructor` (`FUN_004bbfb0`) @ `0x004bc0b0` — **always** `operator_new(0x34)` + this ctor with **fixed log2 = 5** → host `+0x18`.
- Sibling RemoveAll `FUN_004bcf10` walks node next at **+0x0C** (matches sealed `CNDHash_LookupByKey` node layout); twin family `FUN_004bd010` uses next at **+0x10** — do not merge families.

## Pseudocode (annotated)

```c
// __thiscall; stack byte log2; ret 4; returns this
void *CNDHash_Ctor_009cb450(void *thisHash, uint8_t log2)
{
  // SEH LAB_009a16eb
  uint32_t *p = (uint32_t *)thisHash;
  p[0] = (uint32_t)&PTR_FUN_009cb450;     // +0x00 vtbl
  p[1] = 0;                               // +0x04
  p[3] = 0;                               // +0x0C
  p[2] = 1u << (log2 & 0x1f);             // +0x08 provisional N
  p[4] = p[5] = p[6] = 0;
  *(uint8_t *)(p + 7) = log2;             // +0x1C
  *((uint8_t *)p + 0x1d) = 0;
  p[8] = 0;                               // +0x20 freelist
  // +0x24 not written
  p[10] = p[11] = p[12] = 0;
  FUN_004bc7a0(thisHash);                 // AllocBucketTable → mask N-1 + table
  return thisHash;
}
```

## Twin / family

| VA | Role |
|---|---|
| `0x004bcf90` | `CNDHash_Ctor_009cb45c` — COList hashA/hashB |
| `0x004bc7a0` | AllocBucketTable for this stamp (not OWN) |
| `0x004bbfb0` | COList_Constructor sole caller (fixed arg 5) |
| `0x0051db60` | Parallel stamp-qualified CNDHash ctor pattern |

## Open gaps

- Full vtbl method English matrix at `009cb450` (scalar dtor `004bd090`, RemoveAll-class `004bcf10` sibling-only).
- Product / PDB class name beyond CNDHash family inference.
- Semantic of unwritten `+0x24`.
- Runtime / bit-exact / differential.
