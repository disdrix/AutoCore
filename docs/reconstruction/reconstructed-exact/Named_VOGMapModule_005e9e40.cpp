// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: vog_LogMessage×2, FUN_005e9e40, sprintf.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapModule.cpp"; ",unaff_EDI,0x3e

             );

      vog_LogMessage(".
//  - Return sites: 1.

// =============================================================================
// Named_VOGMapModule_005e9e40
// -----------------------------------------------------------------------------
// Stable ID: aa_005e9e40
// Address:   0x005e9e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGMapModule"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_VOGMapModule_005e9e40(int param_1,int *param_2)



{

  int unaff_EDI;

  int iVar1;

  uint8_t local_84 [132];

  

  (**(code **)(*param_2 + 0x14))(local_84,4);

  if (unaff_EDI != 0x3e) {

    if (unaff_EDI < 4) {

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapModule.cpp",0x5d,3,

                     "This module version is too old to import. Get ready for a crash.");

    }

    else {

      sprintf(&stack0xffffff78,

              "Module version %d is older than the current version %d. Converting...",unaff_EDI,0x3e

             );

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapModule.cpp",0x5a,2,

                     &stack0xffffff78);

    }

  }

  (**(code **)(*param_2 + 0x14))(param_1 + 0x1c,4);

  iVar1 = param_1 + 0x18;

  (**(code **)(*param_2 + 0x14))(iVar1,4);

  (**(code **)(*param_2 + 0x14))(param_1 + 0x14,4);

  return iVar1;

}
