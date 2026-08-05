// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00530670, FUN_007a69d0, FUN_007a6de0, FUN_007fc360, FUN_007fdfb0, FUN_00809dd0.
//  - Strings: "FAILED: Server reports failure.".
//  - Return sites: 2.

// =============================================================================
// Named_FAILED_Server_reports_failure_00809dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00809dd0
// Address:   0x00809dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "FAILED: Server reports failure."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_FAILED_Server_reports_failure_00809dd0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  if (*(int *)(unaff_ESI + 0xe98) != 0) {

    if (*(char *)(unaff_EDI + 4) != '\0') {

      FUN_00530670(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8));

      if (*(int **)(unaff_ESI + 0x1074) != (int *)0x0) {

        (**(code **)(**(int **)(unaff_ESI + 0x1074) + 0x448))();

      }

      FUN_007fc360();

      return;

    }

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("FAILED: Server reports failure.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

  }

  return;

}
