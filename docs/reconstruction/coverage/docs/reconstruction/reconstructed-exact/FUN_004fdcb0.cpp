// =============================================================================
// FUN_004fdcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004fdcb0
// Address:   0x004fdcb0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004fdcb0(int param_1,int *param_2)

{
  int *piVar1;
  uint8_t uVar2;
  short sVar3;
  uint16_t uVar4;
  void *pvVar5;
  int iVar6;
  uint32_t /* width from decompiler */ *puVar7;
  uint uVar8;
  uint32_t /* width from decompiler */ uVar9;
  int iVar10;
  uint uVar11;
  
  piVar1 = param_2;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;
  uVar11 = 0;
  if ((((*(int *)(iVar6 + 0xb0) != 0) && (*(int *)(iVar6 + 0xa8) != 0)) && (param_2 != (int *)0x0))
     && (pvVar5 = Object_ResolveFromTFID
                            ((TFID_16 *)
                             (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x160
                             )), pvVar5 != (void *)0x0)) {
    if (piVar1[0x1c] != 0) {
      param_2 = (int *)0x0;
      FUN_00402c40();
      iVar6 = FUN_00411900(&param_2);
      while (iVar6 != 0) {
        if ((*(uint *)(iVar6 + 0x614) & 0x100) != 0) {
          if (*(int *)(param_1 + 8) == 0) {
            iVar10 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1;
          }
          else {
            iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
          }
          CVOGReaction_CastSkillOnTarget
                    (iVar6,piVar1,
                     *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),1,0,
                     iVar10,0,0xffffffff,0,0);
        }
        iVar6 = FUN_00411900(&param_2);
      }
      *(uint8_t *)(piVar1[0x1c] + 0x1d) = 0;
    }
    param_2 = (int *)FUN_004ce940();
    if (param_2 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar1 + 0x60))();
      if (iVar6 != 0) {
        do {
          sVar3 = (**(code **)(*piVar1 + 0x5c))(uVar11);
          if (sVar3 != 0) {
            uVar2 = (**(code **)(*piVar1 + 0x70))(uVar11);
            uVar4 = (**(code **)(*piVar1 + 0x5c))(uVar11,uVar2);
            pvVar5 = (void *)FUN_00509940(uVar4);
            puVar7 = CVOGReaction_ResolveSkillTargets(pvVar5,uVar11);
            if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {
              CVOGReaction_CastSkillOnTarget
                        (puVar7,piVar1,
                         *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),0,0,
                         &DAT_00b041b0,0,0xffffffff,0,0);
            }
                    /* WARNING: Subroutine does not return */
            operator_delete(puVar7);
          }
          uVar11 = uVar11 + 1;
          uVar8 = (**(code **)(*piVar1 + 0x60))();
        } while (uVar11 < uVar8);
      }
      uVar11 = 0;
      iVar6 = (**(code **)(*piVar1 + 0x80))();
      if (iVar6 != 0) {
        do {
          sVar3 = (**(code **)(*piVar1 + 0x7c))(uVar11);
          if (sVar3 != 0) {
            uVar4 = (**(code **)(*piVar1 + 0x7c))(uVar11);
            iVar6 = FUN_00404d70(uVar4);
            if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x3c), iVar6 != 0)) {
              uVar9 = (**(code **)(*piVar1 + 0x94))(uVar11);
              uVar9 = CONCAT22((short)((uint)uVar9 >> 0x10),(ushort)(byte)uVar9);
              pvVar5 = (void *)FUN_00509940(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x4c0));
              puVar7 = CVOGReaction_ResolveSkillTargets(pvVar5,uVar9);
              if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {
                CVOGReaction_CastSkillOnTarget
                          (puVar7,piVar1,
                           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),0,0
                           ,&DAT_00b041b0,0,0xffffffff,0,0);
              }
                    /* WARNING: Subroutine does not return */
              operator_delete(puVar7);
            }
          }
          uVar11 = uVar11 + 1;
          uVar8 = (**(code **)(*piVar1 + 0x80))();
        } while (uVar11 < uVar8);
      }
    }
  }
  return;
}
