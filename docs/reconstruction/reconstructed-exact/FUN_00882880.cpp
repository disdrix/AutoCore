// =============================================================================
// FUN_00882880
// -----------------------------------------------------------------------------
// Stable ID: aa_00882880
// Address:   0x00882880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00882880 @ 0x00882880
// Stable ID: aa_00882880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0078ff90, FUN_00882880.
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

void __thiscall FUN_00882880(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  

  if (*(int *)(param_1 + 0x550) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x550) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x550) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(param_1 + 0x554) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x554) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x554) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(param_1 + 0x558) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x558) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x558) + 0xfc))(0,0x3e800000);

    }

  }

  FUN_0078ff90(param_2,param_3);

  return;

}
