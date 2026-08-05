# Annotated low-level: DES_BuildPermutationP_Tables

| Field | Value |
|---|---|
| Stable ID | `aa_0071b5a0` |
| VA | `0x0071b5a0` |
| Canonical name | `DES_BuildPermutationP_Tables` |
| System | auth |
| Date | 2026-07-29 (W19-Q dual seal) |

## Role

**Builder** for the four DES **P-permutation** OR-contribution banks consumed by `DES_CalculatePermutationP` (`0x0071bc40`):

| Bank k | Base | Size |
|---|---|---|
| 0 | `DAT_00d11658` | 256 × 4 bytes |
| 1 | `DAT_00d11a58` (+0x400) | 256 × 4 |
| 2 | `DAT_00d11e58` (+0x800) | 256 × 4 |
| 3 | `DAT_00d12258` (+0xc00) | 256 × 4 |

Total clear: **0x400 dwords** = **0x1000 bytes** starting at `d11658`.

## Inputs (static tables)

| Symbol | VA | Contents |
|---|---|---|
| `DAT_00afcd48` | `0x00afcd48` | FIPS 46-3 **P** bit select table (32 entries, 1-based positions 16,7,20,…,25) |
| `DAT_00afcd68` | `0x00afcd68` | Per-bit masks within a byte as `uint32_t[8]`: 0x80…0x01 |

## Algorithm (CF-faithful)

```
// local_4 = output-byte bank index 0..3
// local_c = bank base index (0, 0x100, 0x200, 0x300)
// uVar4   = input byte value 0..0xff (row)
// bit b   = 0..31 unrolled ×4: local_8, uVar5, uVar8, uVar6

clear DAT_00d11658[0 .. 0x3ff] as dwords

for bank in 0..3:
  for inByte in 0..255:
    for b in 0..31 step 4 (unrolled 4):
      // srcBit0based = P[b] - 1
      // if srcBit lives in bank byte (srcBit>>3 == bank) AND (mask[srcBit&7] & inByte):
      //   OR mask[b&7] into bank row out[inByte] at byte (b>>3)
```

First unrolled leg uses address form `*(char*)(uVar5 + 0xafcd47)` which equals `DAT_00afcd48[local_8]` when the quartet starts (`uVar5 = local_8+1`); remaining legs use `DAT_00afcd48[bit]`.

## Call graph

| Direction | Target | Notes |
|---|---|---|
| Caller | `DES_InitializeCipher` (`0x0071c000`) | After `FUN_0071bdd0` (S-box bank builder sibling) |
| Callees | none (leaf) | Pure table fill |

## Pseudocode (annotated)

```c
void DES_BuildPermutationP_Tables(void)
{
  // clear 0x400 dwords @ DAT_00d11658
  // triple loop: bank (local_4/local_c) × inByte (uVar4) × bit quartet
  // OR contrib into 4-byte row at bank[inByte]
  // tables: P @ 0xafcd48, masks @ 0xafcd68
}
```

See raw for full decompiler body; clean for CF-preserving rewrite.

## Open questions

- Post-init dump of banks vs hand-built FIPS P vectors (runtime only; static BSS zero).
- Exact packing of which output byte receives which mask when compared to naive bit-walk P — sealed only via this builder + consumer duals.
