// =============================================================================
// FUN_004beb10
// -----------------------------------------------------------------------------
// Stable ID: aa_004beb10
// Address:   0x004beb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004beb10 @ 0x004beb10
// Stable ID: aa_004beb10
// Embedded strings (evidence for future rename):
//   - "BuildGlom"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×10, goto×3, return×1.
//  - Notable callees: FUN_004bdf80×2, FUN_004bdb10, FUN_004bdb70, FUN_004bde20, FUN_004be440, FUN_004be7d0, FUN_004beb10, FUN_0076c4d0.
//  - Strings: "BuildGlom".
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



void __thiscall FUN_004beb10(int param_1,int param_2)



{

  char cVar1;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1852;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("BuildGlom");

  local_4 = 0;

  if (*(char *)(param_1 + 0x570) != '\0') {

    FUN_004bde20();

  }

  if (((*(char *)(param_1 + 0x571) != '\0') ||

      ((*(float *)(param_1 + 0x5c8) <= DAT_00aef954 + _DAT_00aefa4c &&

       ((*(char *)(param_1 + 0x572) != '\0' || (*(char *)(param_1 + 0x573) != '\0')))))) &&

     (0 < param_2)) {

    if ((DAT_00b03778 & 1) == 0) {

      DAT_00b03778 = DAT_00b03778 | 1;

      local_4._0_1_ = 1;

      FUN_0076c500(1000);

      local_4 = (uint)local_4._1_3_ << 8;

    }

    FUN_0076c4d0();

    if ((DAT_00b03740 == '\0') || (*(char *)(param_1 + 0x571) == '\0')) {

      FUN_004bdb10();

      *(uint8_t *)(param_1 + 0x571) = 0;

    }

    else {

      cVar1 = FUN_004bdb70(&DAT_00b03748,&param_2);

      if (cVar1 != '\0') goto LAB_004bec8c;

    }

    if (*(float *)(param_1 + 0x5c8) <= DAT_00aef954 + _DAT_00aefa4c) {

      if (*(char *)(param_1 + 0x572) != '\0') {

        cVar1 = FUN_004be440(&DAT_00b03748,&param_2);

        if (cVar1 != '\0') goto LAB_004bec8c;

        FUN_004bdf80(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8));

      }

      if (*(char *)(param_1 + 0x573) != '\0') {

        cVar1 = FUN_004be7d0(&DAT_00b03748,&param_2);

        if (cVar1 != '\0') goto LAB_004bec8c;

        FUN_004bdf80(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8));

      }

    }

    *(uint8_t *)(param_1 + 0x5b0) = 1;

  }

LAB_004bec8c:

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
