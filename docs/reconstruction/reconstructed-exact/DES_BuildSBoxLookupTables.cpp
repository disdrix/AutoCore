// =============================================================================
// DES_BuildSBoxLookupTables
// -----------------------------------------------------------------------------
// Stable ID: aa_0071bdd0
// Address:   0x0071bdd0  (autoassault.exe, image base 0x400000)
// System:    auth / DES
// Generated: 2026-07-29 dual A/B seal (W19-P); supersedes 2026-07-23 scaffold
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Expands FIPS DES S-box constants (DAT_00afcb48 / DAT_00afcb88) into four
 *   0x1000-byte runtime LUT banks at DAT_00d12e90, d13e90, d14e90, d15e90.
 * - Consumer: DES_CalculateSBoxSubstitution (aa_0071ba90).
 * - Sole caller: DES_InitializeCipher after DES_KeySchedule, before FUN_0071b5a0.
 * - BSS tables are zero in static image until this runs.
 * - Control flow and index expressions preserved from Ghidra decompile.
 */

void DES_BuildSBoxLookupTables(void)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;

  iVar3 = 0;
  pbVar4 = &DAT_00d12e91;
  do {
    uVar5 = 2;
    do {
      uVar1 = uVar5 - 2;
      pbVar4[-1] = (&DAT_00afcb88)
                   [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                    (((int)(uVar1 & 0x3f) >> 4 & 2U) + iVar3) * 0x10] & 0xf |
                   (&DAT_00afcb48)
                   [((int)uVar1 >> 7 & 0xfU) +
                    (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      uVar1 = uVar5 - 1;
      *pbVar4 = (&DAT_00afcb88)
                [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                 (((int)(uVar1 & 0x3f) >> 4 & 2U | uVar1 & 1) + iVar3) * 0x10] & 0xf |
                (&DAT_00afcb48)
                [((int)uVar1 >> 7 & 0xfU) +
                 (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      pbVar4[1] = (&DAT_00afcb88)
                  [((int)(uVar5 & 0x3f) >> 1 & 0xfU) +
                   (((int)(uVar5 & 0x3f) >> 4 & 2U) + iVar3) * 0x10] & 0xf |
                  (&DAT_00afcb48)
                  [((int)uVar5 >> 7 & 0xfU) +
                   (((int)uVar5 >> 10 & 2U | (int)uVar5 >> 6 & 1U) + iVar3) * 0x10] << 4;
      uVar1 = uVar5 + 1;
      pbVar4[2] = (&DAT_00afcb88)
                  [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                   (((int)(uVar1 & 0x3f) >> 4 & 2U | uVar1 & 1) + iVar3) * 0x10] & 0xf |
                  (&DAT_00afcb48)
                  [((int)uVar1 >> 7 & 0xfU) +
                   (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      iVar2 = uVar5 + 2;
      pbVar4 = pbVar4 + 4;
      uVar5 = uVar5 + 4;
    } while (iVar2 < 0x1000);
    iVar3 = iVar3 + 8;
  } while ((int)pbVar4 < 0xd16e91);
  return;
}
