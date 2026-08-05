// =============================================================================
// FUN_0085e130
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e130
// Address:   0x0085e130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085e130 @ 0x0085e130
// Stable ID: aa_0085e130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×11, goto×1, return×1.
//  - Notable callees: FUN_00758460×3, CONCAT13×2, FUN_0040ada0×2, FUN_00413680×2, FUN_006a3db0, FUN_0085de00, FUN_0085df40, FUN_0085e130.
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

void __fastcall FUN_0085e130(int *param_1)



{

  int iVar1;

  char cVar2;

  uint8_t uVar3;

  int iVar4;

  int *piVar5;

  undefined *puVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  int local_8;

  int local_4;

  

  if (param_1[0xa5] == 0) {

    if (*(char *)((int)param_1 + 0x22b) == '\0') goto LAB_0085e39b;

    iVar4 = (**(code **)(*param_1 + 0x140))(&local_18,1);

    iVar1 = *(int *)(iVar4 + 4);

    piVar5 = (int *)(**(code **)(*param_1 + 0x140))(&stack0xffffffd8,1);

    iVar8 = param_1[0x8a];

    iVar4 = *piVar5;

    iVar7 = 0;

    puVar6 = &DAT_00d1ec78;

  }

  else {

    if (*(char *)((int)param_1 + 0x22b) != '\0') {

      FUN_00758460(0,0,(float)param_1[0x12a],(float)param_1[299],&DAT_00d1ec78,0,param_1[0x8a],1,0,0

                   ,&DAT_00d1ecac);

      param_1[0x1a] = param_1[0x1a] + 1;

      iVar4 = param_1[0x1a];

      param_1[0x1d] = (int)(float)-iVar4;

      if (param_1[0x1c] < iVar4) {

        param_1[0x1c] = iVar4;

      }

      if ((param_1[0x144] != 0) && (*(char *)((int)param_1 + 0x492) != '\0')) {

        local_8 = param_1[0x12a];

        local_4 = param_1[299];

        local_10 = 0;

        local_c = 0;

        FUN_00413680(&local_10,param_1[0x144],0,param_1[0x8c],1,0,0,&DAT_00d1ecac);

        FUN_0040ada0();

      }

      if (((param_1[0x143] != 0) && (param_1[0x123] != 0)) &&

         ((*(uint *)(param_1[0x123] + 0x17c) >> 0x13 & 1) != 0)) {

        local_8 = param_1[0x12a];

        local_4 = param_1[299];

        local_20 = CONCAT13((char)(((uint)*(byte *)((int)param_1 + 0x22b) * 0x2b) / 100),0xffffff);

        local_10 = 0;

        local_c = 0;

        FUN_00413680(&local_10,param_1[0x143],0,local_20,1,0,0,&DAT_00d1ecac);

        FUN_0040ada0();

      }

    }

    local_18 = DAT_00afdf0c;

    cVar2 = (**(code **)(*param_1 + 0xf8))();

    if (cVar2 != '\0') {

      uVar3 = FUN_006a3db0();

      local_18 = CONCAT13(uVar3,(undefined3)local_18);

    }

    iVar1 = param_1[0x5f];

    iVar4 = param_1[0x5e];

    iVar7 = param_1[0x86];

    puVar6 = (undefined *)param_1[0xa5];

    iVar8 = local_18;

  }

  FUN_00758460(0,0,(float)iVar4,(float)iVar1,puVar6,iVar7,iVar8,1,0,0,&DAT_00d1ecac);

LAB_0085e39b:

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar4 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  if (param_1[0x122] != 4) {

    FUN_0085df40(param_1,0);

    (**(code **)(*param_1 + 0x3ac))(0);

    FUN_0085de00(param_1);

    cVar2 = (**(code **)(*param_1 + 0x3c4))();

    if ((cVar2 == '\0') && (*(char *)((int)param_1 + 0x22b) != '\0')) {

      param_1[0x1a] = param_1[0x1a] + 1;

      iVar4 = param_1[0x1a];

      param_1[0x1d] = (int)(float)-iVar4;

      if (param_1[0x1c] < iVar4) {

        param_1[0x1c] = iVar4;

      }

      uVar9 = 1;

      iVar4 = (**(code **)(*param_1 + 0x140))(&local_18,1);

      iVar4 = *(int *)(iVar4 + 4);

      piVar5 = (int *)(**(code **)(*param_1 + 0x140))(&local_18,1);

      FUN_00758460(0,0,(float)*piVar5,(float)iVar4,&DAT_00d1ec78,0,uVar9,1,0,0,&DAT_00d1ecac);

    }

  }

  return;

}
