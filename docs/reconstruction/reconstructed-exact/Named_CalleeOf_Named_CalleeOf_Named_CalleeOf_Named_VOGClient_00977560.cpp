// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00977560
// -----------------------------------------------------------------------------
// Stable ID: aa_00977560
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGClient
// Address:   0x00977560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGClient: callee helper. Evidence string: "Globes". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Globes"
//   - "Scrip"
//   - "Clink"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~184 non-empty decompiler lines.
//  - Control keywords: if×35, goto×4, return×2.
//  - Notable callees: FUN_00798720×7, FUN_0051fb50×4, FUN_007a69d0×4, FUN_007a6de0×4, FUN_00977000×4, sprintf×4, FUN_00977560.
//  - Strings: "Globes"; "%I64i"; "Scrip"; "Clink".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGClient
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00977560(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *unaff_ESI;

  int unaff_EDI;

  longlong lVar5;

  uint64_t uVar6;

  char *pcVar7;

  undefined *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  char local_11d;

  uint32_t /* width from decompiler */ local_11c;

  int *piStack_118;

  float fStack_114;

  uint32_t /* width from decompiler */ uStack_10c;

  int iStack_108;

  int iStack_104;

  char acStack_100 [256];

  

  if ((unaff_ESI == (int *)0x0) && (unaff_EDI == 0)) {

    return;

  }

  local_11d = param_4;

  iVar4 = (int)((float)DAT_00d1e81c * _DAT_00aaab24);

  if ((unaff_ESI != (int *)0x0) && (iVar1 = (**(code **)(*unaff_ESI + 0x1b8))(), iVar1 != 0)) {

    piVar2 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

    iVar4 = *(int *)(*piVar2 + 0x7c);

  }

  if (unaff_EDI == 0) {

    puVar3 = &DAT_00afdf0c;

  }

  else {

    local_11c = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc4);

    puVar3 = &local_11c;

  }

  local_11c = *puVar3;

  if (unaff_EDI == 0) {

    piStack_118 = (int *)0x0;

    fStack_114 = g_flOne;

  }

  else {

    piStack_118 = *(int **)(unaff_EDI + 0xc0);

    fStack_114 = *(float *)(unaff_EDI + 0xb8);

  }

  if (piStack_118 != (int *)0x0) {

    iVar4 = *(int *)(*piStack_118 + 0x7c);

  }

  iStack_108 = iVar4;

  iStack_104 = iVar4;

  lVar5 = FUN_0051fb50(3,param_2,param_3);

  uStack_10c = (uint32_t /* width from decompiler */)((ulonglong)lVar5 >> 0x20);

  if ((lVar5 != 0) || (param_4 != '\0')) {

    if (unaff_ESI != (int *)0x0) {

      iVar4 = *unaff_ESI;

      uVar9 = 0xffffffff;

      pcVar7 = "Globes";

      FUN_007a69d0("Globes",0xffffffff);

      uVar9 = FUN_007a6de0(pcVar7,uVar9);

      (**(code **)(iVar4 + 0x260))(3,0,0,0,0,uVar9);

    }

    uVar9 = uStack_10c;

    FUN_00977000(param_1,unaff_ESI,unaff_EDI,3);

    sprintf(acStack_100,"%I64i",(int)lVar5,uVar9);

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_100);

    }

    if (unaff_EDI != 0) {

      FUN_00798720(unaff_EDI,acStack_100,local_11c,piStack_118,fStack_114,0);

    }

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 0x264))();

    }

    local_11d = '\x01';

  }

  lVar5 = FUN_0051fb50(2,param_2,param_3);

  uVar9 = (uint32_t /* width from decompiler */)((ulonglong)lVar5 >> 0x20);

  uStack_10c = uVar9;

  if (lVar5 == 0) {

    if (local_11d != '\0') {

LAB_0097772e:

      if (unaff_ESI != (int *)0x0) {

        (**(code **)(*unaff_ESI + 0x250))(&DAT_00a84d80);

      }

      if (unaff_EDI != 0) {

        FUN_00798720(unaff_EDI,&DAT_00a84d80,local_11c,piStack_118,fStack_114,0);

      }

      goto LAB_00977761;

    }

  }

  else {

    if (local_11d != '\0') goto LAB_0097772e;

LAB_00977761:

    if (unaff_ESI != (int *)0x0) {

      iVar4 = *unaff_ESI;

      uVar9 = 0xffffffff;

      puVar8 = &DAT_00a84d78;

      FUN_007a69d0(&DAT_00a84d78,0xffffffff);

      uVar9 = FUN_007a6de0(puVar8,uVar9);

      (**(code **)(iVar4 + 0x260))(3,0,0,0,0,uVar9);

      uVar9 = uStack_10c;

    }

    FUN_00977000(param_1,unaff_ESI,unaff_EDI,2);

    sprintf(acStack_100,"%I64i",(int)lVar5,uVar9);

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_100);

    }

    if (unaff_EDI != 0) {

      FUN_00798720(unaff_EDI,acStack_100,local_11c,piStack_118,fStack_114,0);

    }

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 0x264))();

    }

    local_11d = '\x01';

  }

  lVar5 = FUN_0051fb50(1,param_2,param_3);

  uVar9 = (uint32_t /* width from decompiler */)((ulonglong)lVar5 >> 0x20);

  uStack_10c = uVar9;

  if (lVar5 == 0) {

    if (local_11d == '\0') goto LAB_0097790e;

LAB_0097783b:

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 0x250))(&DAT_00a84d80);

    }

    if (unaff_EDI != 0) {

      FUN_00798720(unaff_EDI,&DAT_00a84d80,local_11c,piStack_118,fStack_114,0);

    }

  }

  else if (local_11d != '\0') goto LAB_0097783b;

  if (unaff_ESI != (int *)0x0) {

    iVar4 = *unaff_ESI;

    uVar9 = 0xffffffff;

    pcVar7 = "Scrip";

    FUN_007a69d0("Scrip",0xffffffff);

    uVar9 = FUN_007a6de0(pcVar7,uVar9);

    (**(code **)(iVar4 + 0x260))(3,0,0,0,0,uVar9);

    uVar9 = uStack_10c;

  }

  FUN_00977000(param_1,unaff_ESI,unaff_EDI,1);

  sprintf(acStack_100,"%I64i",(int)lVar5,uVar9);

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x250))(acStack_100);

  }

  if (unaff_EDI != 0) {

    FUN_00798720(unaff_EDI,acStack_100,local_11c,piStack_118,fStack_114,0);

  }

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x264))();

  }

  local_11d = '\x01';

LAB_0097790e:

  uVar6 = FUN_0051fb50(0,param_2,param_3);

  uStack_10c = (uint32_t /* width from decompiler */)((ulonglong)uVar6 >> 0x20);

  if (local_11d != '\0') {

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 0x250))(&DAT_00a84d80);

    }

    if (unaff_EDI != 0) {

      FUN_00798720(unaff_EDI,&DAT_00a84d80,local_11c,piStack_118,fStack_114,0);

    }

  }

  if (unaff_ESI != (int *)0x0) {

    iVar4 = *unaff_ESI;

    uVar9 = 0xffffffff;

    pcVar7 = "Clink";

    FUN_007a69d0("Clink",0xffffffff);

    uVar9 = FUN_007a6de0(pcVar7,uVar9);

    (**(code **)(iVar4 + 0x260))(3,0,0,0,0,uVar9);

  }

  FUN_00977000(param_1,unaff_ESI,unaff_EDI,0);

  sprintf(acStack_100,"%I64i",(int)uVar6,uStack_10c);

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x250))(acStack_100);

  }

  if (unaff_EDI != 0) {

    FUN_00798720(unaff_EDI,acStack_100,local_11c,piStack_118,fStack_114,0);

  }

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x264))();

  }

  return;

}
