// =============================================================================
// FUN_00414ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00414ec0
// Address:   0x00414ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00414ec0 @ 0x00414ec0
// Stable ID: aa_00414ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, while×2, goto×1, do×1.
//  - Notable callees: EnterCriticalSection×2, FUN_0040e490×2, LeaveCriticalSection×2, FUN_0040e380, FUN_0040fb90, FUN_00414ec0, FUN_00415340.
//  - Return sites: 3.

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

void __thiscall FUN_00414ec0(int *param_1,float *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  float fVar1;
  float fVar2;
  int *piVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint32_t /* width from decompiler */ *puVar9;
  int iVar10;
  int iStack_b0;
  int iStack_ac;
  uint8_t local_a8 [4];
  uint32_t /* width from decompiler */ *local_a4;
  uint32_t /* width from decompiler */ local_a0;
  int *local_9c;
  int local_98;
  LPCRITICAL_SECTION local_94;
  uint32_t /* width from decompiler */ local_90;
  uint32_t /* width from decompiler */ local_8c;
  uint32_t /* width from decompiler */ local_88;
  uint32_t /* width from decompiler */ local_84 [2];
  uint8_t auStack_7c [24];
  uint8_t auStack_64 [28];
  uint8_t auStack_48 [12];
  uint8_t auStack_3c [12];
  uint8_t local_30 [4];
  uint8_t auStack_2c [16];
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009bd92b;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  local_a4 = (uint32_t /* width from decompiler */ *)FUN_0040fb90();
  local_a0 = 0;
  local_14 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x193);
  local_94 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x18a] == 0) {
    local_98 = 0;
  }
  else {
    local_98 = *(int *)(param_1[0x18a] + 4);
  }
  LeaveCriticalSection(lpCriticalSection);
  piVar3 = (int *)FUN_0040e490(param_1 + 0x189);
  while (piVar3 != (int *)0x0) {
    iVar7 = piVar3[0x133];
    if (iVar7 != 0) {
      local_9c = (int *)CVOGReaction_ResolveObjectTarget
                                  (0,*(uint32_t /* width from decompiler */ *)(iVar7 + 8),*(uint32_t /* width from decompiler */ *)(iVar7 + 0xc));
      if (local_9c == (int *)0x0) {
LAB_00415020:
        local_88 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x18);
        local_8c = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x14);
        local_90 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x10);
        local_84[0] = 0;
      }
      else {
        puVar9 = (uint32_t /* width from decompiler */ *)*local_a4;
        *local_a4 = local_a4;
        local_a4[1] = local_a4;
        local_a0 = 0;
        if (puVar9 != local_a4) {
                    /* WARNING: Subroutine does not return */
          operator_delete(puVar9);
        }
        (**(code **)(*local_9c + 0x124))(local_a8);
        puVar9 = (uint32_t /* width from decompiler */ *)*local_a4;
        if (puVar9 == local_a4) goto LAB_00415020;
        do {
          (**(code **)(*(int *)puVar9[2] + 0x144))();
          iVar6 = puVar9[2];
          local_90 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x80);
          puVar9 = (uint32_t /* width from decompiler */ *)*puVar9;
          local_8c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x84);
          local_88 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x88);
          local_84[0] = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x8c);
        } while (puVar9 != local_a4);
      }
      pfVar4 = (float *)FUN_00415340(local_30);
      fVar1 = pfVar4[1];
      fVar2 = param_2[1];
      iVar10 = (int)(*pfVar4 + *param_2);
      iStack_b0 = iVar10 - param_1[0x14e] / 2;
      iVar6 = param_1[0x14f];
      iVar8 = (int)(fVar1 + fVar2);
      piVar3[0x99] = (int)((*pfVar4 + *param_2) - (float)iVar10);
      iStack_ac = iVar8 - iVar6 / 2;
      piVar3[0x9a] = (int)((fVar1 + fVar2) - (float)iVar8);
      (**(code **)(*piVar3 + 0x118))(&iStack_b0);
      if ((((iVar7 < -param_1[0x14e]) || (iStack_b0 < -param_1[0x14f])) ||
          (piVar5 = (int *)(**(code **)(*param_1 + 0x140))(auStack_3c,1), *piVar5 <= iVar7)) ||
         (iVar6 = (**(code **)(*param_1 + 0x140))(auStack_2c,1), *(int *)(iVar6 + 4) <= iStack_b0))
      {
        (**(code **)(*piVar3 + 4))(0);
      }
      else if (((iVar7 < 0) || (iStack_b0 < 0)) ||
              ((piVar5 = (int *)(**(code **)(*param_1 + 0x140))(auStack_7c,1),
               *piVar5 - param_1[0x14e] <= iVar7 ||
               (iVar7 = (**(code **)(*param_1 + 0x140))(auStack_64,1),
               *(int *)(iVar7 + 4) - param_1[0x14f] <= iStack_b0)))) {
        *(uint8_t *)(piVar3 + 0x36) = 1;
        (**(code **)(*piVar3 + 0x24))(1);
        iVar6 = 1;
        (**(code **)(*piVar3 + 0x120))(auStack_48,1,0);
        iVar7 = (**(code **)(*param_1 + 0x140))(auStack_64,1);
        iVar7 = *(int *)(iVar7 + 4);
        iVar6 = *(int *)(iVar6 + 4);
        iVar10 = 1;
        (**(code **)(*piVar3 + 0x120))(&local_8c,1,0);
        (**(code **)(*param_1 + 0x140))(&local_90,1);
        puVar9 = &local_88;
        (**(code **)(*piVar3 + 0x120))(puVar9,1,0);
        piVar5 = (int *)(**(code **)(*piVar3 + 0x120))(local_84,1,0);
        iVar8 = *piVar5;
        piVar3[0x65] = (int)puVar9;
        piVar3[100] = -iVar8;
        piVar3[0x66] = iVar10;
        piVar3[0x67] = iVar7 - iVar6;
        (**(code **)(*piVar3 + 0x34c))();
        (**(code **)(*piVar3 + 4))(1);
      }
      else {
        *(uint8_t *)(piVar3 + 0x36) = 0;
        (**(code **)(*piVar3 + 0x24))(0);
        (**(code **)(*piVar3 + 4))(1);
      }
    }
    FUN_0040e380(param_1 + 0x189,piVar3);
    EnterCriticalSection(local_94);
    if (param_1[0x18a] == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(param_1[0x18a] + 4);
    }
    LeaveCriticalSection(local_94);
    if (iVar7 == local_98) break;
    piVar3 = (int *)FUN_0040e490(param_1 + 0x189);
  }
  local_14 = 0xffffffff;
  puVar9 = (uint32_t /* width from decompiler */ *)*local_a4;
  *local_a4 = local_a4;
  local_a4[1] = local_a4;
  local_a0 = 0;
  if (puVar9 != local_a4) {
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar9);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(local_a4);
}
