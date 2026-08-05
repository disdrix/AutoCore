// =============================================================================
// FUN_0090bdc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090bdc0
// Address:   0x0090bdc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090bdc0 @ 0x0090bdc0
// Stable ID: aa_0090bdc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, goto×1.
//  - Notable callees: FUN_00791f30×3, FUN_0040d950, FUN_0040d980, FUN_0090b9c0, FUN_0090bdc0, FUN_0097ae30.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_0090bdc0(int *param_1,float param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  uint32_t /* width from decompiler */ ***pppuVar10;

  int iStack_34;

  uint32_t /* width from decompiler */ **ppuStack_30;

  int iStack_2c;

  float fStack_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  uint8_t auStack_18 [4];

  uint8_t auStack_14 [16];

  

  cVar3 = (**(code **)(*param_1 + 0xd0))();

  fVar9 = DAT_00aaa688;

  if (cVar3 == '\x01') {

    fVar8 = (float)param_1[0x141] + param_2;

    param_1[0x141] = (int)fVar8;

    if (fVar9 <= fVar8) {

      if (DAT_00aaaa54 <= fVar8) {

        if (fVar8 < DAT_00aaaa44) {

          (**(code **)(*(int *)param_1[0x13f] + 0xcc))(0);

          fVar9 = ((((float)param_1[0x141] - DAT_00aaa688) - DAT_00aaaa4c) + g_flMultiKillCountBlend

                  ) * _DAT_00aaaa40;

          iStack_24 = (int)((float)param_1[0x149] * fVar9);

          iStack_20 = (int)((float)param_1[0x14a] * fVar9);

          (**(code **)(*(int *)param_1[0x140] + 300))(&iStack_24);

          iVar6 = (**(code **)(*(int *)param_1[0x140] + 0x140))(auStack_18,1);

          iVar6 = *(int *)(iVar6 + 4);

          iVar1 = param_1[0x144];

          piVar4 = (int *)(**(code **)(*(int *)param_1[0x140] + 0x140))(&fStack_28,1);

          iStack_34 = param_1[0x143] - *piVar4 / 2;

          ppuStack_30 = (uint32_t /* width from decompiler */ **)(iVar1 - iVar6 / 2);

          goto LAB_0090c18d;

        }

        if (DAT_00aaa944 < fVar8) {

          if (param_1[0x140] != 0) {

            FUN_0097ae30();

          }

          (**(code **)(*param_1 + 0xcc))(0);

          if (param_1[0x14f] != 0) {

            FUN_0040d950();

            FUN_0040d980();

            FUN_0090b9c0();

          }

        }

      }

      else {

        iVar6 = param_1[0x144];

        iVar1 = param_1[0x146];

        fVar8 = fVar8 - fVar9;

        fVar9 = fVar8 * _DAT_00aaaa50;

        iVar7 = (int)((float)(param_1[0x143] - param_1[0x145]) * fVar9 + (float)param_1[0x145]);

        iVar2 = param_1[0x146];

        fStack_28 = ((DAT_00aaaa4c - fVar8) + DAT_00a0f704) * _DAT_00aaaa48;

        if ((int *)param_1[0x13f] != (int *)0x0) {

          ppuStack_30 = (uint32_t /* width from decompiler */ **)(int)((float)param_1[0x147] * fStack_28 * DAT_00aaa68c);

          iStack_2c = (int)((float)param_1[0x148] * fStack_28 * DAT_00aaa68c);

          pppuVar10 = &ppuStack_30;

          (**(code **)(*(int *)param_1[0x13f] + 300))(pppuVar10);

          (**(code **)(*(int *)param_1[0x13f] + 0x140))(&iStack_1c,1);

          piVar4 = (int *)(**(code **)(*(int *)param_1[0x13f] + 0x140))(&iStack_1c,1);

          iStack_34 = iVar7 - *piVar4 / 2;

          ppuStack_30 = pppuVar10;

          (**(code **)(*(int *)param_1[0x13f] + 0x110))(&iStack_34);

          (**(code **)(*(int *)param_1[0x13f] + 0x34c))();

        }

        if ((int *)param_1[0x140] != (int *)0x0) {

          iStack_20 = (int)((float)param_1[0x149] * fStack_28 * DAT_00aaa68c);

          iStack_1c = (int)((float)param_1[0x14a] * fStack_28 * DAT_00aaa68c);

          (**(code **)(*(int *)param_1[0x140] + 300))(&iStack_20);

          iVar5 = (**(code **)(*(int *)param_1[0x140] + 0x140))(auStack_14,1);

          iVar5 = *(int *)(iVar5 + 4);

          piVar4 = (int *)(**(code **)(*(int *)param_1[0x140] + 0x140))(&iStack_24,1);

          iStack_34 = iVar7 - *piVar4 / 2;

          ppuStack_30 = (uint32_t /* width from decompiler */ **)

                        ((int)((float)(iVar6 - iVar1) * fVar9 + (float)iVar2) - iVar5 / 2);

LAB_0090c18d:

          (**(code **)(*(int *)param_1[0x140] + 0x110))(&iStack_34);

          (**(code **)(*(int *)param_1[0x140] + 0x34c))();

          FUN_00791f30(param_2);

          return;

        }

      }

    }

    else {

      ppuStack_30 = (uint32_t /* width from decompiler */ **)((fVar8 + DAT_00a110d8) * g_flMultiKillCountBlend);

      if ((int *)param_1[0x140] != (int *)0x0) {

        fStack_28 = (float)(int)((float)param_1[0x149] * (float)ppuStack_30);

        iStack_24 = (int)((float)param_1[0x14a] * (float)ppuStack_30);

        (**(code **)(*(int *)param_1[0x140] + 300))(&fStack_28);

        (**(code **)(*(int *)param_1[0x140] + 0x140))(&iStack_24,1);

        (**(code **)(*(int *)param_1[0x140] + 0x140))(&iStack_24,1);

        (**(code **)(*(int *)param_1[0x140] + 0x110))(&stack0xffffffc4);

        (**(code **)(*(int *)param_1[0x140] + 0x34c))();

      }

      if ((int *)param_1[0x13f] != (int *)0x0) {

        fStack_28 = (float)(int)((float)param_1[0x147] * (float)ppuStack_30);

        iStack_24 = (int)((float)param_1[0x148] * (float)ppuStack_30);

        (**(code **)(*(int *)param_1[0x13f] + 300))(&fStack_28);

        (**(code **)(*(int *)param_1[0x13f] + 0x140))(&iStack_1c,1);

        (**(code **)(*(int *)param_1[0x13f] + 0x140))(&iStack_2c,1);

        (**(code **)(*(int *)param_1[0x13f] + 0x110))(&stack0xffffffc4);

        (**(code **)(*(int *)param_1[0x13f] + 0x34c))();

        FUN_00791f30(param_2);

        return;

      }

    }

  }

  FUN_00791f30(param_2);

  return;

}
