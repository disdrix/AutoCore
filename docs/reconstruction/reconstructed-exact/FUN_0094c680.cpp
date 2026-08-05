// =============================================================================
// FUN_0094c680
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c680
// Address:   0x0094c680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094c680 @ 0x0094c680
// Stable ID: aa_0094c680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0094c680.
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

void FUN_0094c680(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_10 [2];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_10[0] = 0x8021;

  local_8 = param_1;

  local_4 = param_2;

  if (*(int *)(unaff_ESI + 0xc7c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x18))(0xffffffff,local_10,0x10,0);

    }

  }

  return;

}
