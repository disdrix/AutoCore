// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: block×11, FUN_0076cec0×4, vog_LogMessage×4, FUN_005aa2f0, FUN_00799460, SysFreeString.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_VOGMapText_005aa2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005aa2f0
// Address:   0x005aa2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGMapText"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x005aa3f5) */

/* WARNING: Removing unreachable block (ram,0x005aa413) */

/* WARNING: Removing unreachable block (ram,0x005aa420) */

/* WARNING: Removing unreachable block (ram,0x005aa4a2) */

/* WARNING: Removing unreachable block (ram,0x005aa4b5) */

/* WARNING: Removing unreachable block (ram,0x005aa45d) */

/* WARNING: Removing unreachable block (ram,0x005aa4ff) */

/* WARNING: Removing unreachable block (ram,0x005aa501) */

/* WARNING: Removing unreachable block (ram,0x005aa50b) */

/* WARNING: Removing unreachable block (ram,0x005aa522) */

/* WARNING: Removing unreachable block (ram,0x005aa523) */



void Named_VOGMapText_005aa2f0(int *param_1)



{

  char cVar1;

  int iVar2;

  BSTR unaff_ESI;

  int iStack_128;

  int iStack_120;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a649b;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  iVar2 = (**(code **)(*param_1 + 0x44))();

  if ((iVar2 == 0) && (iStack_120 != 0)) {

    cVar1 = FUN_00799460();

    if (cVar1 == '\0') {

      FUN_0076cec0();

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1b5);

    }

    else if ((iStack_128 < 8) && (-1 < iStack_128)) {

      (**(code **)(*param_1 + 0x30))();

      FUN_0076cec0();

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1c8);

    }

    else {

      FUN_0076cec0();

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1be,3);

    }

  }

  else {

    FUN_0076cec0();

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1ab);

  }

  SysFreeString(unaff_ESI);

  ExceptionList = pvStack_14;

  return;

}
