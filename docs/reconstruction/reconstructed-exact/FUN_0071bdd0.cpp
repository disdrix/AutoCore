// =============================================================================
// FUN_0071bdd0 (scaffold alias of DES_BuildSBoxLookupTables)
// -----------------------------------------------------------------------------
// Stable ID: aa_0071bdd0
// Address:   0x0071bdd0  (autoassault.exe, image base 0x400000)
// System:    auth / DES
// Generated: 2026-07-29 dual A/B seal (W19-P); keeps Ghidra name as alias
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Canonical clean: reconstructed-exact/DES_BuildSBoxLookupTables.cpp
// =============================================================================

void FUN_0071bdd0(void)
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
