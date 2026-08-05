# Annotated low-level: DES_BuildSBoxLookupTables (FUN_0071bdd0)

| Field | Value |
|---|---|
| Stable ID | `aa_0071bdd0` |
| VA | `0x0071bdd0` |
| Canonical | `DES_BuildSBoxLookupTables` |
| System | auth / DES |
| Date | 2026-07-29 (dual A/B seal W19-P; supersedes 2026-07-23 scaffold) |

## Machine-level notes

- Source: raw + live `decompile_function` / `read_memory` 2026-07-29.
- One-shot init helper: expands FIPS DES S-box constants into four **0x1000-byte** runtime LUT banks used by `DES_CalculateSBoxSubstitution` (`aa_0071ba90`).
- **No stack args**; `void` / `ret`.
- Write cursor starts at `DAT_00d12e91` so `pbVar4[-1]` fills `DAT_00d12e90` first.
- Outer loop: `iVar3` in `{0,8,16,24}`; stop when cursor ≥ `0x00d16e91` → **4 × 0x1000 = 0x4000** bytes (`d12e90`/`d13e90`/`d14e90`/`d15e90`).
- Inner loop: for each bank, emit all 0x1000 indices in groups of 4 (`uVar5 = 2..0x1000` step 4).
- Each output byte packs **two** 4-bit S results: low nibble from `DAT_00afcb88[...]`, high nibble from `DAT_00afcb48[...]`.
- `DAT_00afcb48` = contiguous classic DES S1..S8 (512 nibble values as bytes); `DAT_00afcb88 = afcb48+0x40` (S2 start) used as alternate base for the dual-index form.
- Sole caller: `DES_InitializeCipher` after `DES_KeySchedule`, before sibling builder `FUN_0071b5a0` (W19-Q owns that VA — P-table / other LUT path).
- Static image BSS at `d12e90` is zero until this runs.

## Pseudocode (annotated)

```c
// void DES_BuildSBoxLookupTables(void)
// Builds DAT_00d12e90[0x1000], d13e90, d14e90, d15e90 from FIPS S-boxes.
void FUN_0071bdd0(void)
{
  uint uVar1;          // linear index within bank
  int iVar2;           // inner stop temp
  int iVar3;           // S-table row-group base: 0,8,16,24
  byte *pbVar4;        // write ptr (points at out+1 style → [-1] is first byte)
  uint uVar5;          // inner cursor seed (starts 2 so uVar5-2 covers 0)

  iVar3 = 0;
  pbVar4 = &DAT_00d12e91;
  do {
    uVar5 = 2;
    do {
      // four consecutive LUT bytes per iteration (indices uVar5-2 .. uVar5+1)
      // each: lo = S-table@afcb88[bit-extract], hi = S-table@afcb48[bit-extract]
      uVar1 = uVar5 - 2;
      pbVar4[-1] = pack_sbox_byte(uVar1, iVar3);
      uVar1 = uVar5 - 1;
      *pbVar4     = pack_sbox_byte(uVar1, iVar3);
      pbVar4[1]   = pack_sbox_byte(uVar5, iVar3);
      uVar1 = uVar5 + 1;
      pbVar4[2]   = pack_sbox_byte(uVar1, iVar3);
      iVar2 = uVar5 + 2;
      pbVar4 = pbVar4 + 4;
      uVar5 = uVar5 + 4;
    } while (iVar2 < 0x1000);
    iVar3 = iVar3 + 8;
  } while ((int)pbVar4 < 0xd16e91);
  return;
}
```

(`pack_sbox_byte` is notational — clean keeps full decompiler index expressions.)

## Open questions

- Exact mapping of bank index ↔ classic S1..S8 pair order (formula sealed; pedagogical mapping optional).
- Vector / FIPS golden-vector proof of filled LUTs (deferred; no runtime).
- Product name of sibling `FUN_0071b5a0` body (owned by W19-Q).
