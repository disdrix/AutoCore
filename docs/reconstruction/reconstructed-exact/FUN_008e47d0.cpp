// =============================================================================
// FUN_008e47d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e47d0
// Address:   0x008e47d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e47d0 @ 0x008e47d0
// Stable ID: aa_008e47d0
// Embedded strings (evidence for future rename):
//   - "%s: 0/0"
//   - "%s: %d/%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_007a69d0×2, FUN_007a6de0×2, block×2, sprintf×2, FUN_00403450, FUN_00514050, FUN_0052ad60, FUN_0052ada0.
//  - Strings: "%s: 0/0"; "%s: %d/%d".
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x008e49bd) */

/* WARNING: Removing unreachable block (ram,0x008e4a35) */



void FUN_008e47d0(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  uint8_t *puVar4;

  uint8_t *puStack_4dc;

  uint32_t /* width from decompiler */ uStack_4d8;

  int iStack_4d4;

  uint32_t /* width from decompiler */ uStack_4d0;

  uint8_t auStack_448 [4];

  char acStack_444 [284];

  uint8_t auStack_328 [15];

  uint8_t uStack_319;

  uint8_t uStack_21f;

  uint8_t auStack_21c [42];

  uint8_t auStack_1f2 [474];

  uint32_t /* width from decompiler */ uStack_18;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad2c6;

  pvStack_c = ExceptionList;

  if (*(int *)(unaff_EDI + 0x7cc) == 0) {

    ExceptionList = &pvStack_c;

    if (*(int *)(unaff_EDI + 0x524) != 0) {

      uStack_4d0 = 0;

      iStack_4d4 = 0x8e4815;

      ExceptionList = &pvStack_c;

      (**(code **)(**(int **)(unaff_EDI + 0x524) + 0x1d8))();

      iStack_4d4 = 0x8e4823;

      (**(code **)(**(int **)(unaff_EDI + 0x524) + 0x34c))();

    }

    if (*(int *)(unaff_EDI + 0x774) != 0) {

      (**(code **)(**(int **)(unaff_EDI + 0x774) + 4))();

    }

    if (*(int *)(unaff_EDI + 0x778) != 0) {

      (**(code **)(**(int **)(unaff_EDI + 0x778) + 4))();

    }

    if (*(int *)(unaff_EDI + 0x780) != 0) {

      (**(code **)(**(int **)(unaff_EDI + 0x780) + 4))();

    }

    if (*(int *)(unaff_EDI + 0x77c) != 0) {

      (**(code **)(**(int **)(unaff_EDI + 0x77c) + 4))();

      ExceptionList = pvStack_10;

      return;

    }

  }

  else {

    iVar1 = **(int **)(unaff_EDI + 0x524);

    uStack_4d0 = 1;

    iStack_4d4 = 1;

    uStack_4d8 = 0x8e48a9;

    ExceptionList = &pvStack_c;

    uStack_4d8 = (**(code **)(**(int **)(unaff_EDI + 0x7cc) + 0x15c))();

    puStack_4dc = (uint8_t *)0x8e48b6;

    (**(code **)(iVar1 + 0x1d8))();

    iVar1 = **(int **)(unaff_EDI + 0x524);

    puStack_4dc = &stack0xfffffb3c;

    puStack_4dc = (uint8_t *)FUN_00514050();

    (**(code **)(iVar1 + 0x15c))(1);

    (**(code **)(**(int **)(unaff_EDI + 0x524) + 0x34c))();

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(unaff_EDI + 0x7cc) + 0xa8) + 0x3c) + 0x4ac);

    FUN_0052b040(uVar3,auStack_21c);

    iVar1 = FUN_0052ad60(uVar3);

    iVar2 = FUN_0052ada0(uVar3);

    iStack_4d4 = *(int *)(unaff_EDI + 0x7c4);

    uStack_4d0 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7c8);

    puVar4 = &stack0xfffffb3c;

    uStack_319 = 0;

    uStack_21f = 0;

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(auStack_1f2,uVar3);

    if (iVar1 < 1) {

      uStack_18 = 1;

      uVar3 = 0xffffffff;

      FUN_007a69d0(puVar4,0xffffffff);

      uVar3 = FUN_007a6de0(puVar4,uVar3);

      sprintf(acStack_444,"%s: 0/0",uVar3);

      iStack_4d4 = 0;

    }

    else {

      uStack_18 = 0;

      uVar3 = 0xffffffff;

      FUN_007a69d0(puVar4,0xffffffff,iVar2,iVar1);

      uVar3 = FUN_007a6de0(puVar4,uVar3);

      sprintf(acStack_444,"%s: %d/%d",uVar3);

      iStack_4d4 = (int)(((float)*(int *)(unaff_EDI + 0x7c4) * (float)iVar2) / (float)iVar1);

    }

    uStack_18 = 0xffffffff;

    (**(code **)(**(int **)(unaff_EDI + 0x778) + 300))(&iStack_4d4);

    (**(code **)(**(int **)(unaff_EDI + 0x774) + 0x1d8))(auStack_448,1,1);

    iVar1 = **(int **)(unaff_EDI + 0x780);

    uVar3 = FUN_008e4430(&puStack_4dc);

    (**(code **)(iVar1 + 0x15c))(0,uVar3);

    (**(code **)(**(int **)(unaff_EDI + 0x77c) + 0x1d8))(auStack_328,1,1);

    (**(code **)(**(int **)(unaff_EDI + 0x774) + 0x34c))();

    (**(code **)(**(int **)(unaff_EDI + 0x778) + 0x34c))();

    (**(code **)(**(int **)(unaff_EDI + 0x780) + 0x34c))();

    (**(code **)(**(int **)(unaff_EDI + 0x77c) + 0x34c))();

    (**(code **)(**(int **)(unaff_EDI + 0x774) + 4))(1);

    (**(code **)(**(int **)(unaff_EDI + 0x778) + 4))(1);

    (**(code **)(**(int **)(unaff_EDI + 0x780) + 4))(1);

    (**(code **)(**(int **)(unaff_EDI + 0x77c) + 4))(1);

  }

  ExceptionList = pvStack_c;

  return;

}
