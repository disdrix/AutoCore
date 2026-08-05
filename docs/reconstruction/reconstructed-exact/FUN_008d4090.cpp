// =============================================================================
// FUN_008d4090
// -----------------------------------------------------------------------------
// Stable ID: aa_008d4090
// Address:   0x008d4090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d4090 @ 0x008d4090
// Stable ID: aa_008d4090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×14, return×6, goto×2.
//  - Notable callees: FUN_008d3e20, FUN_008d4090.
//  - Return sites: 6.

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



uint32_t /* width from decompiler */ __thiscall FUN_008d4090(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char cVar2;

  short sVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  

  sVar3 = (short)((uint)param_2 >> 0x10);

  iVar1 = param_1[0x12e];

  if (iVar1 != 0) {

    if ((iVar1 == param_1[0x194]) || (iVar1 == param_1[0x197])) {

      if ((int *)param_1[0x197] != (int *)0x0) {

        cVar2 = (**(code **)(*(int *)param_1[0x197] + 0xd8))();

        if (cVar2 != '\0') {

          if (0 < sVar3) {

            (**(code **)(*(int *)param_1[0x197] + 0x45c))(0xbf800000);

            return 1;

          }

          (**(code **)(*(int *)param_1[0x197] + 0x45c))(0x3f800000);

          return 1;

        }

      }

    }

    else if (((iVar1 == param_1[0x19a]) || (iVar1 == param_1[0x19d])) &&

            ((int *)param_1[0x19d] != (int *)0x0)) {

      cVar2 = (**(code **)(*(int *)param_1[0x19d] + 0xd8))();

      if (cVar2 != '\0') {

        if (0 < sVar3) {

          (**(code **)(*(int *)param_1[0x19d] + 0x45c))(0xbf800000);

          return 1;

        }

        (**(code **)(*(int *)param_1[0x19d] + 0x45c))(0x3f800000);

        return 1;

      }

    }

    if (param_1[0x12e] == param_1[0x154]) {

      iVar1 = param_1[0x151];

      if (sVar3 < 1) {

        if (*(float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xbc + iVar1) - DAT_00a0f718 <

            DAT_00a0f698) goto LAB_008d427c;

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xb8))

                  (*(float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xbc + iVar1) - DAT_00a0f718);

        fVar5 = (float)param_1[0x16c] - DAT_00a0f718;

      }

      else {

        if (DAT_00a0f734 <

            *(float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xbc + iVar1) + DAT_00a0f718)

        goto LAB_008d427c;

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xb8))

                  (*(float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xbc + iVar1) + DAT_00a0f718);

        fVar5 = (float)param_1[0x16c] + DAT_00a0f718;

      }

      param_1[0x16c] = (int)fVar5;

      if ((int *)param_1[0x1d7] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x1d7] + 0x454))(fVar5 * _DAT_00aaab04 + DAT_00a0f298,1);

      }

      FUN_008d3e20();

    }

  }

LAB_008d427c:

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 != '\0') && ((int *)param_1[0x12e] != (int *)0x0)) {

    uVar4 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))(param_2,param_3);

    return uVar4;

  }

  return 0;

}
