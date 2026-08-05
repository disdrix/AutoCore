// =============================================================================
// FUN_006e96c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e96c0
// Address:   0x006e96c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e96c0 @ 0x006e96c0
// Stable ID: aa_006e96c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_005b3370, FUN_006e96c0.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ * __thiscall

FUN_006e96c0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,int *param_4,

            uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uStack_134;

  int iStack_130;

  uint32_t /* width from decompiler */ *local_128;

  uint32_t /* width from decompiler */ *puStack_124;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ *local_114;

  uint8_t auStack_110 [268];

  

  param_1[2] = param_5;

  *param_1 = &PTR_FUN_00a0e8d4;

  piVar1 = param_1 + 3;

  *piVar1 = (int)(param_1 + 6);

  param_1[4] = 0;

  param_1[5] = 0x80000004;

  local_118 = param_2[2];

  piVar2 = (int *)*param_2;

  local_114 = param_2;

  local_128 = param_1;

  iStack_130 = (**(code **)(*piVar2 + 0x28))();

  if ((int)(param_1[5] & 0x7fffffff) < iStack_130) {

    iVar7 = (param_1[5] & 0x7fffffff) * 2;

    iVar5 = iStack_130;

    if (iStack_130 < iVar7) {

      iVar5 = iVar7;

    }

    FUN_005b3300(piVar1,iVar5,8);

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x2c))();

  if (0 < iStack_130) {

    do {

      uStack_134 = puVar3;

      local_128 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x34))(puVar3,auStack_110);

      puVar8 = param_2;

      puStack_124 = puVar3;

      pcVar4 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_4[1])

                                 ((int)&uStack_134 + 3,param_4,param_3,param_2,piVar2,puVar3);

      if (*pcVar4 != '\0') {

        iVar7 = *param_4;

        iVar5 = (**(code **)(*unaff_EDI + 0x14))();

        iVar6 = (**(code **)(*(int *)*param_3 + 0x14))();

        puVar3 = puVar8;

        iVar7 = (**(code **)(iVar7 + 0x18c + (iVar5 * 0x20 + iVar6) * 4))

                          (&stack0xfffffec0,param_3,param_4,param_5);

        if (iVar7 != 0) {

          if (param_1[4] == (param_1[5] & 0x7fffffff)) {

            FUN_005b3370(piVar1,8);

          }

          puVar8 = (uint32_t /* width from decompiler */ *)(*piVar1 + param_1[4] * 8);

          param_1[4] = param_1[4] + 1;

          puVar8[1] = iVar7;

          *puVar8 = puVar3;

        }

      }

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x30))(puVar3);

      iStack_130 = iStack_130 + -1;

    } while (iStack_130 != 0);

  }

  return local_128;

}
