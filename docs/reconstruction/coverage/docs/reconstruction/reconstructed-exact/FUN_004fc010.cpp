// =============================================================================
// FUN_004fc010
// -----------------------------------------------------------------------------
// Stable ID: aa_004fc010
// Address:   0x004fc010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_004fc010(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float *pfVar6;
  uint32_t /* width from decompiler */ *puVar7;
  int *piVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint32_t /* width from decompiler */ uVar17;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_8c;
  float local_88;
  float local_84;
  uint32_t /* width from decompiler */ local_80;
  uint32_t /* width from decompiler */ local_7c;
  uint32_t /* width from decompiler */ local_78;
  uint32_t /* width from decompiler */ local_74;
  float local_68;
  float local_60;
  int local_50;
  float local_44;
  float local_38;
  uint8_t local_30 [16];
  uint8_t local_20 [28];
  
  if ((*(int *)(param_1 + 0x264) != 0) && (iVar3 = *(int *)(param_1 + 0x3b8), iVar3 != 0)) {
    piVar8 = *(int **)(iVar3 + 4);
    piVar4 = *(int **)(iVar3 + 8);
    if ((piVar8 != (int *)0x0) && (local_50 = (int)piVar4 - (int)piVar8 >> 2, local_50 != 0)) {
      iVar3 = *(int *)(param_1 + 8);
      if (iVar3 == 0) {
        pfVar6 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
      }
      else {
        pfVar6 = (float *)(*(int *)(iVar3 + 0x3c) + 0xb0);
      }
      local_a0 = *pfVar6;
      local_9c = pfVar6[1];
      local_98 = pfVar6[2];
      if (iVar3 == 0) {
        pfVar6 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);
      }
      else {
        pfVar6 = (float *)(*(int *)(iVar3 + 0x3c) + 0x30);
      }
      local_d0 = *pfVar6;
      local_cc = pfVar6[1];
      local_c8 = pfVar6[2];
      local_c4 = pfVar6[3];
      local_c0 = local_d0;
      local_bc = local_cc;
      local_b8 = local_c8;
      local_b4 = local_c4;
      for (; piVar8 != piVar4; piVar8 = piVar8 + 1) {
        piVar5 = (int *)*piVar8;
        if (*piVar5 != 0) {
          fVar1 = (float)piVar5[2];
          local_68 = (float)piVar5[3];
          fVar2 = (float)piVar5[1];
          fVar10 = local_c4 * local_c4 * g_flLevelUpUiBase_Inferred - g_flOne;
          local_44 = local_c4 * g_flLevelUpUiBase_Inferred;
          fVar9 = (local_68 * local_c8 + fVar1 * local_cc + fVar2 * local_d0) *
                  g_flLevelUpUiBase_Inferred;
          local_38 = local_68 * fVar10;
          local_a8 = (local_b8 * fVar2 - local_68 * local_d0) * local_44 +
                     local_bc * fVar9 + fVar1 * fVar10 + local_9c;
          local_ac = (local_68 * local_cc - fVar1 * local_b8) * local_44 +
                     fVar9 * local_c0 + fVar10 * fVar2 + local_a0;
          local_a4 = (fVar1 * local_d0 - local_bc * fVar2) * local_44 + local_b8 * fVar9 + local_38
                     + local_98;
          local_8c = local_ac;
          local_88 = local_a8;
          local_84 = local_a4;
          pfVar6 = (float *)FUN_004e96e0(local_30,piVar5 + 4);
          fVar1 = *pfVar6;
          fVar2 = pfVar6[1];
          fVar9 = pfVar6[2];
          fVar10 = pfVar6[3];
          fVar14 = fVar9 * local_d0;
          fVar15 = fVar2 * local_d0;
          fVar16 = local_cc * fVar1;
          fVar11 = fVar1 * local_d0;
          fVar12 = fVar2 * local_cc;
          fVar13 = fVar9 * local_c4;
          local_d0 = fVar10 * local_d0 + local_c4 * fVar1 + (fVar9 * local_cc - fVar2 * local_c8);
          local_cc = fVar10 * local_cc + fVar2 * local_c4 + (local_c8 * fVar1 - fVar14);
          local_c4 = fVar10 * local_c4 - (fVar9 * local_c8 + fVar12 + fVar11);
          local_c8 = fVar10 * local_c8 + fVar13 + (fVar15 - fVar16);
          local_60 = local_d0;
          puVar7 = (uint32_t /* width from decompiler */ *)FUN_004e87d0(local_20,&local_d0);
          local_80 = *puVar7;
          local_7c = puVar7[1];
          local_78 = puVar7[2];
          local_74 = puVar7[3];
          uVar17 = 3;
          (**(code **)(**(int **)*piVar8 + 0x10))(3,&local_8c);
          FUN_0040cf90(uVar17);
          (**(code **)(**(int **)*piVar8 + 0x14))(&local_84);
          local_c4 = local_b4;
          local_cc = local_bc;
          local_c8 = local_b8;
          local_d0 = local_c0;
        }
      }
    }
  }
  return;
}
