// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00977a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00977a30
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows (+4 other named callers)
// Address:   0x00977a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper. Evidence string: "Globes". Supports parent flow (not a free-standing entry point). Named_CalleeOf_Client_RefreshOpenMissionUiWindows (+4 other named callers).
// Embedded strings (evidence):
//   - "Globes"
//   - "Scrip"
//   - "Clink"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×10, goto×4, return×2.
//  - Notable callees: FUN_0051fb50×4, FUN_007a69d0×4, FUN_007a6de0×4, FUN_00977000×4, FUN_00977a30, sprintf.
//  - Strings: "Globes"; "%I64i"; "Scrip"; "Clink".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows (+4 other named callers)
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



void Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00977a30(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  bool bVar1;

  bool bVar2;

  char in_AL;

  int iVar3;

  int *unaff_ESI;

  code *pcVar4;

  longlong lVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  undefined *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uStack_14;

  

  if (unaff_ESI == (int *)0x0) {

    return;

  }

  iVar3 = (**(code **)(*unaff_ESI + 0x1b8))();

  if (iVar3 != 0) {

    (**(code **)(*unaff_ESI + 0x1b8))();

  }

  lVar5 = FUN_0051fb50(3,param_2,param_3);

  if ((lVar5 == 0) && (in_AL == '\0')) {

    bVar1 = false;

    pcVar4 = sprintf_exref;

  }

  else {

    iVar3 = *unaff_ESI;

    uVar10 = 0xffffffff;

    pcVar7 = "Globes";

    FUN_007a69d0("Globes",0xffffffff);

    uVar10 = FUN_007a6de0(pcVar7,uVar10);

    (**(code **)(iVar3 + 0x260))(3,0,0,0,0,uVar10);

    FUN_00977000(uStack_14,unaff_ESI,0,3);

    pcVar4 = sprintf_exref;

    sprintf(&stack0xfffffee8,"%I64i",(int)lVar5,(int)((ulonglong)lVar5 >> 0x20));

    (**(code **)(*unaff_ESI + 0x250))(&stack0xfffffee8);

    (**(code **)(*unaff_ESI + 0x264))();

    bVar1 = true;

  }

  lVar5 = FUN_0051fb50(2,param_2,param_3);

  if (lVar5 == 0) {

    if (bVar1) {

LAB_00977b86:

      (**(code **)(*unaff_ESI + 0x250))(&DAT_00a84d80);

      goto LAB_00977b95;

    }

    bVar1 = false;

  }

  else {

    if (bVar1) goto LAB_00977b86;

LAB_00977b95:

    iVar3 = *unaff_ESI;

    uVar10 = 0xffffffff;

    puVar8 = &DAT_00a84d78;

    FUN_007a69d0(&DAT_00a84d78,0xffffffff);

    uVar10 = FUN_007a6de0(puVar8,uVar10);

    uVar9 = 0;

    uVar6 = 0;

    (**(code **)(iVar3 + 0x260))(3,0,0,0,0,uVar10);

    FUN_00977000(uStack_14,unaff_ESI,0,2);

    (*pcVar4)(&stack0xfffffee8,"%I64i",uVar6,uVar9);

    (**(code **)(*unaff_ESI + 0x250))(&stack0xfffffee8);

    (**(code **)(*unaff_ESI + 0x264))();

    bVar1 = true;

    param_1 = uStack_14;

  }

  lVar5 = FUN_0051fb50(1,param_2,param_3);

  if (lVar5 == 0) {

    bVar2 = false;

    if (!bVar1) goto LAB_00977c8a;

LAB_00977c10:

    (**(code **)(*unaff_ESI + 0x250))(&DAT_00a84d80);

  }

  else if (bVar1) goto LAB_00977c10;

  iVar3 = *unaff_ESI;

  uVar10 = 0xffffffff;

  pcVar7 = "Scrip";

  FUN_007a69d0("Scrip",0xffffffff);

  uVar10 = FUN_007a6de0(pcVar7,uVar10);

  uVar9 = 0;

  uVar6 = 0;

  (**(code **)(iVar3 + 0x260))(3,0,0,0,0,uVar10);

  FUN_00977000(param_1,unaff_ESI,0,1);

  (*pcVar4)(&stack0xfffffee8,"%I64i",uVar6,uVar9);

  (**(code **)(*unaff_ESI + 0x250))(&stack0xfffffee8);

  (**(code **)(*unaff_ESI + 0x264))();

  bVar2 = true;

LAB_00977c8a:

  FUN_0051fb50(0,param_2,param_3);

  if (bVar2) {

    (**(code **)(*unaff_ESI + 0x250))(&DAT_00a84d80);

  }

  iVar3 = *unaff_ESI;

  uVar10 = 0xffffffff;

  pcVar7 = "Clink";

  FUN_007a69d0("Clink",0xffffffff);

  uVar10 = FUN_007a6de0(pcVar7,uVar10);

  uVar9 = 0;

  uVar6 = 0;

  (**(code **)(iVar3 + 0x260))(3,0,0,0,0,uVar10);

  FUN_00977000(param_1,unaff_ESI,0,0);

  (*pcVar4)(&stack0xfffffee8,"%I64i",uVar6,uVar9);

  (**(code **)(*unaff_ESI + 0x250))(&stack0xfffffee8);

  (**(code **)(*unaff_ESI + 0x264))();

  return;

}
