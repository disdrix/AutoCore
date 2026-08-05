// =============================================================================
// FUN_0071b430  (scaffold twin of DES_BuildIPFPLookupTables)
// -----------------------------------------------------------------------------
// Stable ID: aa_0071b430
// Address:   0x0071b430  (autoassault.exe, image base 0x400000)
// System:    auth / DES
// Generated: 2026-07-29 dual A/B seal (W25-Q); CF ≡ named clean
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// Named twin: reconstructed-exact/DES_BuildIPFPLookupTables.cpp

void FUN_0071b430(undefined4 *param_1, int param_2)
{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *local_8;
  int local_4;
  
  puVar7 = param_1;
  for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_4 = 0;
  iVar4 = 0;
  do {
    uVar6 = 0;
    do {
      local_8 = (char *)(param_2 + 3);
      uVar3 = 1;
      do {
        uVar5 = (int)*(char *)((uVar3 - 1) + param_2) - 1;
        if (((int)uVar5 >> 2 == local_4) &&
           ((*(uint *)(&DAT_00afcd88 + (uVar5 & 3) * 4) & uVar6) != 0)) {
          pbVar2 = (byte *)((int)param_1 + (iVar4 + uVar6) * 8 + ((int)(uVar3 - 1) >> 3));
          *pbVar2 = *pbVar2 | (&DAT_00afcd68)[(uVar3 - 1 & 7) * 4];
        }
        uVar5 = (int)*(char *)(uVar3 + param_2) - 1;
        if (((int)uVar5 >> 2 == local_4) &&
           ((*(uint *)(&DAT_00afcd88 + (uVar5 & 3) * 4) & uVar6) != 0)) {
          pbVar2 = (byte *)((int)param_1 + (iVar4 + uVar6) * 8 + ((int)uVar3 >> 3));
          *pbVar2 = *pbVar2 | (&DAT_00afcd68)[(uVar3 & 7) * 4];
        }
        if (((int)((int)local_8[-1] - 1U) >> 2 == local_4) &&
           ((*(uint *)(&DAT_00afcd88 + ((int)local_8[-1] - 1U & 3) * 4) & uVar6) != 0)) {
          pbVar2 = (byte *)((int)param_1 + (iVar4 + uVar6) * 8 + ((int)(uVar3 + 1) >> 3));
          *pbVar2 = *pbVar2 | (&DAT_00afcd68)[(uVar3 + 1 & 7) * 4];
        }
        if (((int)((int)*local_8 - 1U) >> 2 == local_4) &&
           ((*(uint *)(&DAT_00afcd88 + ((int)*local_8 - 1U & 3) * 4) & uVar6) != 0)) {
          pbVar2 = (byte *)((int)param_1 + (iVar4 + uVar6) * 8 + ((int)(uVar3 + 2) >> 3));
          *pbVar2 = *pbVar2 | (&DAT_00afcd68)[(uVar3 + 2 & 7) * 4];
        }
        local_8 = local_8 + 4;
        iVar1 = uVar3 + 3;
        uVar3 = uVar3 + 4;
      } while (iVar1 < 0x40);
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 0x10);
    local_4 = local_4 + 1;
    iVar4 = iVar4 + 0x10;
  } while (iVar4 < 0x100);
  return;
}

