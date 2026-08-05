// =============================================================================
// FUN_0089c6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0089c6c0
// Address:   0x0089c6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089c6c0 @ 0x0089c6c0
// Stable ID: aa_0089c6c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fbd30×2, FUN_0089b090, FUN_0089bc30, FUN_0089bf50, FUN_0089c330, FUN_0089c6c0.
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

void FUN_0089c6c0(char param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_EDI;

  uint64_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if ((*(int *)(unaff_EDI + 0x568) != 0) && (*(int *)(unaff_EDI + 0x56c) != 0)) {

    uVar2 = (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x44c))();

    uVar1 = (**(code **)(**(int **)(unaff_EDI + 0x56c) + 0x44c))();

    if (param_1 != '\0') {

      (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x458))();

      (**(code **)(**(int **)(unaff_EDI + 0x56c) + 0x458))();

    }

    FUN_0089bc30(unaff_EDI);

    (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x484))(0,1);

    (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x488))(1,0);

    (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x488))(0,0);

    uVar3 = 0;

    (**(code **)(**(int **)(unaff_EDI + 0x56c) + 0x484))(0,1);

    (**(code **)(**(int **)(unaff_EDI + 0x56c) + 0x488))(0,0);

    (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x448))(uVar2);

    (**(code **)(**(int **)(unaff_EDI + 0x56c) + 0x448))(uVar1,uVar3);

    FUN_0089b090(unaff_EDI);

    FUN_0089c330();

    FUN_0089bf50();

    FUN_007fbd30();

    FUN_007fbd30();

  }

  return;

}
