// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055aec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055aec0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0055aec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper. Evidence string: "Rigid body of object \'%s\' is zero length". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Rigid body of object \'%s\' is zero length"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×5, do×4, while×4, return×2.
//  - Notable callees: FUN_005f3160×2, FUN_004367f0, FUN_0055aec0, FUN_0055c7a0, FUN_005f3120, FUN_005f3740, FUN_007a4480, FUN_007b6a20.
//  - Strings: "Rigid body of object \'%s\' is zero length".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055aec0(char *param_1,int param_2,int param_3)



{

  char cVar1;

  char *pcVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint uStack_150;

  uint8_t auStack_14c [12];

  float fStack_140;

  float fStack_13c;

  float fStack_138;

  float fStack_134;

  uint32_t /* width from decompiler */ uStack_129;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a48d6;

  local_1c = ExceptionList;

  pcVar2 = param_1;

  do {

    cVar1 = *pcVar2;

    pcVar2[(int)&uStack_129 + (1 - (int)param_1)] = cVar1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  puVar8 = &uStack_129;

  do {

    pcVar2 = (char *)((int)puVar8 + 1);

    puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

  } while (*pcVar2 != '\0');

  iVar4 = (int)&uStack_129 + 1;

  *puVar8 = DAT_009cb318;

  ExceptionList = &local_1c;

  FUN_007b6a20(iVar4);

  piVar3 = (int *)FUN_007b7420(iVar4);

  if (piVar3 != (int *)0x0) {

    iVar4 = (**(code **)(*piVar3 + 0x1c))();

    if (iVar4 == 0) {

      (**(code **)*piVar3)(1);

      FUN_007a4480(1,"Rigid body of object \'%s\' is zero length",param_1);

    }

    else {

      fStack_140 = g_flOne;

      fStack_13c = g_flOne;

      fStack_138 = g_flOne;

      fStack_134 = g_flOne;

      iVar4 = piVar3[1];

      uVar5 = (**(code **)(*piVar3 + 0x1c))();

      FUN_005f3120(iVar4,uVar5);

      uStack_14 = 0;

      uVar5 = 0x55afa1;

      piVar6 = (int *)FUN_005f3740(auStack_14c,&fStack_140);

      uVar10 = 1;

      uVar9 = 0x55afae;

      (**(code **)*piVar3)(1);

      if ((piVar6 != (int *)0x0) && (0 < piVar6[1])) {

        FUN_0055c7a0(piVar6[1],uVar5,uVar9,uVar10);

        uStack_150 = 0;

        if (piVar6[1] != 0) {

          iVar7 = 0;

          iVar4 = 0;

          do {

            *(uint32_t /* width from decompiler */ *)(iVar4 + *(int *)(param_2 + 4)) = *(uint32_t /* width from decompiler */ *)(iVar7 + *piVar6);

            *(uint32_t /* width from decompiler */ *)(iVar4 + 4 + *(int *)(param_2 + 4)) =

                 *(uint32_t /* width from decompiler */ *)(*piVar6 + 4 + iVar7);

            *(uint32_t /* width from decompiler */ *)(iVar4 + 8 + *(int *)(param_2 + 4)) =

                 *(uint32_t /* width from decompiler */ *)(*piVar6 + 8 + iVar7);

            uStack_150 = uStack_150 + 1;

            iVar4 = iVar4 + 0xc;

            iVar7 = iVar7 + 0x10;

          } while (uStack_150 < (uint)piVar6[1]);

        }

        FUN_004367f0(piVar6[4] * 3,0);

        uStack_150 = 0;

        if (piVar6[4] != 0) {

          iVar7 = 0;

          iVar4 = 0;

          do {

            *(uint32_t /* width from decompiler */ *)(iVar4 + *(int *)(param_3 + 4)) = *(uint32_t /* width from decompiler */ *)(iVar7 + piVar6[3]);

            *(uint32_t /* width from decompiler */ *)(iVar4 + 4 + *(int *)(param_3 + 4)) =

                 *(uint32_t /* width from decompiler */ *)(piVar6[3] + 4 + iVar7);

            *(uint32_t /* width from decompiler */ *)(iVar4 + 8 + *(int *)(param_3 + 4)) =

                 *(uint32_t /* width from decompiler */ *)(piVar6[3] + 8 + iVar7);

            uStack_150 = uStack_150 + 1;

            iVar4 = iVar4 + 0xc;

            iVar7 = iVar7 + 0xc;

          } while (uStack_150 < (uint)piVar6[4]);

        }

        uStack_14 = 0xffffffff;

        FUN_005f3160();

        ExceptionList = local_1c;

        return 1;

      }

      uStack_14 = 0xffffffff;

      FUN_005f3160();

    }

  }

  ExceptionList = local_1c;

  return 0;

}
