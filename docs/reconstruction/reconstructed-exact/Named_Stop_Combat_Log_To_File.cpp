// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007a69d0×3, FUN_007a6de0×3, FUN_00831e70.
//  - Strings: "Log Chat To File"; "Stop Logging To File"; "Stop Combat Log To File"; "Log Combat Chat To File".
//  - Return sites: 3.

// =============================================================================
// Named_Stop_Combat_Log_To_File
// -----------------------------------------------------------------------------
// Stable ID: aa_00831e70
// Address:   0x00831e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Stop Combat Log To File"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Stop_Combat_Log_To_File(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  char *pcVar3;

  

  if (*(int *)(unaff_ESI + 0x544) != 0) {

    if (DAT_00d1775c == '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x3c8))(0,1);

      pcVar3 = "Log Chat To File";

    }

    else {

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x3c8))(1);

      pcVar3 = "Stop Logging To File";

    }

    uVar2 = 0xffffffff;

    iVar1 = **(int **)(unaff_ESI + 0x544);

    FUN_007a69d0(pcVar3,0xffffffff,1,1);

    uVar2 = FUN_007a6de0(pcVar3,uVar2);

    (**(code **)(iVar1 + 0x1d8))(uVar2);

    (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x548) != 0) {

    if (DAT_00d1775d != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x548) + 0x3c8))(1);

      iVar1 = **(int **)(unaff_ESI + 0x548);

      uVar2 = 0xffffffff;

      pcVar3 = "Stop Combat Log To File";

      FUN_007a69d0("Stop Combat Log To File",0xffffffff,1,1);

      uVar2 = FUN_007a6de0(pcVar3,uVar2);

      (**(code **)(iVar1 + 0x1d8))(uVar2);

                    /* WARNING: Could not recover jumptable at 0x00831f41. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x548) + 0x34c))();

      return;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x548) + 0x3c8))(0,1);

    iVar1 = **(int **)(unaff_ESI + 0x548);

    uVar2 = 0xffffffff;

    pcVar3 = "Log Combat Chat To File";

    FUN_007a69d0("Log Combat Chat To File",0xffffffff,1,1);

    uVar2 = FUN_007a6de0(pcVar3,uVar2);

    (**(code **)(iVar1 + 0x1d8))(uVar2);

                    /* WARNING: Could not recover jumptable at 0x00831f84. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x548) + 0x34c))();

    return;

  }

  return;

}
