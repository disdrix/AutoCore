// =============================================================================
// FUN_006ea390
// -----------------------------------------------------------------------------
// Stable ID: aa_006ea390
// Address:   0x006ea390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ea390 @ 0x006ea390
// Stable ID: aa_006ea390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_006cb7d0×3, FUN_006ea390.
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

void __thiscall FUN_006ea390(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  char *pcVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  uint32_t /* width from decompiler */ uStack_130;

  int local_12c;

  int *piStack_120;

  int *piStack_11c;

  uint8_t local_110 [268];

  

  piVar4 = *(int **)(*param_3 + 0xc);

  iVar10 = 0;

  local_12c = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    do {

      piVar4 = (int *)(**(code **)(*piVar4 + 0x34))

                                (*(uint32_t /* width from decompiler */ *)(iVar10 + *(int *)(param_1 + 0xc)),local_110);

      piStack_120 = (int *)param_3[2];

      piStack_11c = param_3;

      pcVar5 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_4[1])

                                 (&stack0xfffffecb,param_4,param_2,param_3,uStack_130,

                                  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + iVar10));

      if (*pcVar5 == '\0') {

        piVar1 = *(int **)(iVar10 + 8 + *(int *)(param_1 + 0xc));

        piVar6 = (int *)FUN_006cb7d0();

        if (piVar1 != piVar6) {

          (**(code **)(*piVar1 + 0x14))();

          iVar3 = *(int *)(param_1 + 0xc);

          uVar9 = FUN_006cb7d0();

          goto LAB_006ea4b1;

        }

      }

      else {

        piVar1 = *(int **)(iVar10 + 8 + *(int *)(param_1 + 0xc));

        piVar6 = (int *)FUN_006cb7d0();

        if (piVar1 == piVar6) {

          uVar9 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

          iVar2 = *param_4;

          iVar7 = (**(code **)(*(int *)*param_2 + 0x14))();

          iVar8 = (**(code **)(*piStack_120 + 0x14))();

          iVar3 = *(int *)(param_1 + 0xc);

          uVar9 = (**(code **)(iVar2 + 0x18c + (iVar7 * 0x20 + iVar8) * 4))

                            (param_2,&piStack_120,param_4,uVar9);

LAB_006ea4b1:

          *(uint32_t /* width from decompiler */ *)(iVar3 + iVar10 + 8) = uVar9;

        }

        else {

          (**(code **)(*piVar1 + 0x1c))(param_2,&piStack_120,param_4);

        }

      }

      local_12c = local_12c + 1;

      iVar10 = iVar10 + 0xc;

    } while (local_12c < *(int *)(param_1 + 0x10));

  }

  return;

}
