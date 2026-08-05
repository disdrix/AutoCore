// =============================================================================
// FUN_00792b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00792b50
// Address:   0x00792b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00792b50 @ 0x00792b50
// Stable ID: aa_00792b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00428220×2, FUN_00792b50, FUN_007b5dd0, NDUIWindow_ApplyXmlNodeAttributes.
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

void FUN_00792b50(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4035;

  local_c = ExceptionList;

  if (*(int *)(unaff_EDI + 0x4c8) != 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x488);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      piVar2 = (int *)0x0;

    }

    else {

      piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

    }

    local_4 = 0xffffffff;

    NDUIWindow_ApplyXmlNodeAttributes(param_1,0,0);

    (**(code **)(*piVar2 + 0x28))(0);

    iVar3 = FUN_00428220(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4c8),piVar2,0);

    if (-1 < iVar3) {

      *(int *)(unaff_EDI + 0x4e8) = *(int *)(unaff_EDI + 0x4e8) + 1;

    }

    iVar3 = FUN_00428220(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4d8),piVar2,0);

    if (-1 < iVar3) {

      *(int *)(unaff_EDI + 0x4f8) = *(int *)(unaff_EDI + 0x4f8) + 1;

    }

  }

  ExceptionList = local_c;

  return;

}
