// =============================================================================
// FUN_00489f20  (scaffold twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_00489f20
// Address:   0x00489f20 – 0x0048a05d inclusive (318 B / 0x13E)
// Canonical: SoftCastHitList_QuickSortRange_KeyFloat14_Inferred
// Prefer:    SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.cpp
// Generated: 2026-08-05 MEGA-115 OWN dual
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
// =============================================================================

#include <cstdint>

// cdecl; void; bare RET; caller ADD ESP,0x10
// elem stride 0x30; ascending float key @ +0x14; mid-pivot Hoare qsort
// partial swap: +0,+4,+8,+c,+10,+14,+20 (not +18,+1c,+24,+28,+2c)
void FUN_00489f20(int param_1, int param_2, int param_3, uint32_t param_4)
{
  uint32_t *puVar1;
  float fVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  float *pfVar10;
  uint32_t *puVar11;
  int iVar12;
  int iVar13;

  do {
    fVar2 = *(float *)((param_2 + param_3 >> 1) * 0x30 + 0x14 + param_1);
    iVar12 = param_3;
    iVar13 = param_2;
    do {
      for (pfVar10 = (float *)(iVar13 * 0x30 + 0x14 + param_1); *pfVar10 < fVar2;
           pfVar10 = pfVar10 + 0xc) {
        iVar13 = iVar13 + 1;
      }
      for (pfVar10 = (float *)(iVar12 * 0x30 + 0x14 + param_1); fVar2 < *pfVar10;
           pfVar10 = pfVar10 + -0xc) {
        iVar12 = iVar12 + -1;
      }
      if (iVar12 < iVar13)
        break;
      if (iVar12 != iVar13) {
        uVar3 = *(uint32_t *)(iVar12 * 0x30 + param_1);
        puVar1 = (uint32_t *)(iVar12 * 0x30 + param_1);
        uVar5 = puVar1[2];
        uVar4 = puVar1[1];
        uVar6 = puVar1[4];
        uVar7 = puVar1[3];
        uVar8 = puVar1[5];
        uVar9 = puVar1[8];
        puVar11 = (uint32_t *)(iVar13 * 0x30 + param_1);
        *puVar1 = *puVar11;
        puVar1[1] = puVar11[1];
        puVar1[2] = puVar11[2];
        puVar1[3] = puVar11[3];
        puVar1[4] = puVar11[4];
        puVar1[5] = puVar11[5];
        puVar1[8] = puVar11[8];
        *puVar11 = uVar3;
        puVar11[1] = uVar4;
        puVar11[2] = uVar5;
        puVar11[3] = uVar7;
        puVar11[5] = uVar8;
        puVar11[4] = uVar6;
        puVar11[8] = uVar9;
      }
      iVar12 = iVar12 + -1;
      iVar13 = iVar13 + 1;
    } while (iVar13 <= iVar12);
    if (param_2 < iVar12) {
      FUN_00489f20(param_1, param_2, iVar12, param_4);
    }
    param_2 = iVar13;
    if (param_3 <= iVar13) {
      return;
    }
  } while (true);
}
