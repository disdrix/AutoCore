// =============================================================================
// FUN_00856530
// -----------------------------------------------------------------------------
// Stable ID: aa_00856530
// Address:   0x00856530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00856530 @ 0x00856530
// Stable ID: aa_00856530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00856530.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00856530(int *param_1,float param_2)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  float unaff_ESI;

  int iVar5;

  float fVar6;

  float fVar7;

  uint8_t *puStack_50;

  int iStack_4c;

  uint8_t *puStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  int *piStack_3c;

  int *piStack_38;

  int iStack_24;

  int local_20;

  int local_1c;

  

  fVar7 = _DAT_00aaa7c8;

  if ((char)param_1[0x123] != '\0') {

    fVar6 = param_2 + (float)param_1[0x122];

    param_1[0x122] = (int)fVar6;

    if (fVar6 <= fVar7) {

      if (DAT_00a10e78 < fVar6) {

        fVar7 = g_flOne - (fVar6 - DAT_00a10e78) * _DAT_00aaa7c4;

        local_20 = (int)((float)DAT_00d1e818 * (float)(int)((float)param_1[0x95] * fVar7) *

                        DAT_00aaa67c);

        iVar5 = (int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * (float)param_1[0x93] *

                     DAT_00aaa67c);

        local_1c = (int)((float)DAT_00d1e81c * (float)(int)((float)param_1[0x96] * fVar7) *

                        DAT_00aaa678);

        piStack_38 = &local_20;

        iVar4 = (int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * (float)param_1[0x94] *

                     DAT_00aaa678);

        piStack_3c = (int *)0x856656;

        (**(code **)(*param_1 + 300))();

        iStack_24 = (int)((float)(param_1[0x124] - iVar5) * unaff_ESI + (float)iVar5);

        local_20 = (int)((float)(param_1[0x125] - iVar4) * unaff_ESI + (float)iVar4);

        piStack_3c = &iStack_24;

        uStack_40 = 0x8566ab;

        (**(code **)(*param_1 + 0x110))();

        uStack_40 = 0;

        uStack_44 = 1;

        puStack_48 = &stack0xffffffd0;

        iStack_4c = 0x8566be;

        iVar5 = (**(code **)(*param_1 + 0x120))();

        iStack_4c = 1;

        puStack_50 = &stack0xffffffd4;

        iVar4 = (**(code **)(*param_1 + 0x140))();

        iVar4 = *(int *)(iVar4 + 4);

        iVar5 = *(int *)(iVar5 + 4);

        piVar2 = (int *)(**(code **)(*param_1 + 0x120))(&stack0xffffffd4,1,0);

        piVar3 = (int *)(**(code **)(*param_1 + 0x140))(&stack0xffffffd0,1);

        puStack_50 = (uint8_t *)(*piVar2 - *piVar3 / 2);

        iStack_4c = iVar5 - iVar4 / 2;

        (**(code **)(*param_1 + 0x110))(&puStack_50);

        (**(code **)(*param_1 + 0x34c))();

      }

    }

    else {

      *(uint8_t *)(param_1 + 0x123) = 0;

      piStack_38 = (int *)0x856571;

      (**(code **)(*param_1 + 4))();

    }

  }

  piStack_38 = (int *)0x856740;

  (**(code **)(*param_1 + 500))();

  piStack_38 = (int *)0x85674a;

  cVar1 = (**(code **)(*param_1 + 0xf8))();

  if (cVar1 != '\0') {

    piStack_38 = (int *)param_2;

    piStack_3c = (int *)0x856759;

    (**(code **)(*param_1 + 0x348))();

  }

  if ((int *)param_1[0xad] != (int *)0x0) {

    piStack_38 = (int *)param_2;

    piStack_3c = (int *)0x85676b;

    (**(code **)(*(int *)param_1[0xad] + 8))();

  }

  return;

}
