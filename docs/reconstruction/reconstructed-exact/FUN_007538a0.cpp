// =============================================================================
// FUN_007538a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007538a0
// Address:   0x007538a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007538a0 @ 0x007538a0
// Stable ID: aa_007538a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, goto×1.
//  - Notable callees: FUN_0043f1d0×2, FUN_0043f180, FUN_007538a0, FUN_0076c3c0.
//  - Return sites: 4.

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

uint8_t __thiscall FUN_007538a0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  char cVar2;

  int extraout_ECX;

  int iVar3;

  int unaff_EDI;

  int local_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009acc0c;

  local_c = ExceptionList;

  if (*(char *)(unaff_EDI + 0x8c) == '\0') {

    return 0;

  }

  ExceptionList = &local_c;

  FUN_0043f180(3);

  local_4 = 0;

  iVar3 = *(int *)(unaff_EDI + 0x108);

  if ((iVar3 != 0) && (*(int *)(unaff_EDI + 0x10c) - iVar3 >> 2 != 0)) {

    cVar2 = (**(code **)(**(int **)(iVar3 + *(int *)(unaff_EDI + 0x114) * 4) + 0xc))();

    if (cVar2 != '\0') goto LAB_0075397a;

  }

  if (param_1 == 0x204) {

    iVar3 = (int)(short)((uint)param_3 >> 0x10);

    if ((((*(int *)(unaff_EDI + 0x78) < (int)(short)param_3) && (*(int *)(unaff_EDI + 0x7c) < iVar3)

         ) && ((int)(short)param_3 < *(int *)(unaff_EDI + 0x80) + *(int *)(unaff_EDI + 0x78))) &&

       (iVar3 < *(int *)(unaff_EDI + 0x84) + *(int *)(unaff_EDI + 0x7c))) {

      *(uint8_t *)(unaff_EDI + 0xf0) = 1;

LAB_0075397a:

      FUN_0043f1d0();

      ExceptionList = local_c;

      return 1;

    }

  }

  else if ((*(char *)(unaff_EDI + 0xf0) != '\0') && (param_1 == 0x205)) {

    *(int *)(unaff_EDI + 0x114) = *(int *)(unaff_EDI + 0x114) + 1;

    *(uint8_t *)(unaff_EDI + 0xf0) = 0;

    if (*(int *)(unaff_EDI + 0x108) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(unaff_EDI + 0x10c) - *(int *)(unaff_EDI + 0x108) >> 2;

    }

    if (iVar3 <= *(int *)(unaff_EDI + 0x114)) {

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x114) = 0;

    }

    FUN_0043f1d0();

    ExceptionList = local_c;

    return 1;

  }

  if (*(char *)(local_14 + 200) == '\0') {

    iVar3 = FUN_0076c3c0();

    piVar1 = (int *)(extraout_ECX + 0x34 + *(int *)(extraout_ECX + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar3 - *(int *)(extraout_ECX + 0x30));

    *(int *)(extraout_ECX + 0x30) = iVar3;

    *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0xc4) = uStack_10;

  }

  ExceptionList = local_c;

  return 0;

}
