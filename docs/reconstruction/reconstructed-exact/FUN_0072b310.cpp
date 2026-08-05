// =============================================================================
// FUN_0072b310
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b310
// Address:   0x0072b310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b310 @ 0x0072b310
// Stable ID: aa_0072b310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004406e0×2, FUN_0072b310, FUN_0072b710, FUN_0072b9b0.
//  - Return sites: 2.

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

void FUN_0072b310(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  uint uVar2;

  int unaff_EBX;

  

  if (*(int *)(unaff_EBX + 0x18) == 1) {

    FUN_004406e0();

    if (*(int *)(unaff_EBX + 0x30) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = *(int *)(unaff_EBX + 0x34) - *(int *)(unaff_EBX + 0x30) >> 2;

    }

    if ((DAT_00afa620 <= uVar2) && (0 < param_2)) {

      FUN_0072b9b0(param_2 + -1);

      return;

    }

  }

  else {

    cVar1 = FUN_0072b710(param_1,param_2);

    if (cVar1 == '\0') {

      FUN_004406e0();

    }

  }

  return;

}
