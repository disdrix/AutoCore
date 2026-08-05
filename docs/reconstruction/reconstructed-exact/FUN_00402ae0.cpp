// =============================================================================
// FUN_00402ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00402ae0
// Address:   0x00402ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00402ae0 @ 0x00402ae0
// Stable ID: aa_00402ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00402ae0, FUN_00403e50.
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

int * FUN_00402ae0(int *param_1)



{

  int in_EAX;

  int iVar1;

  uint *unaff_EDI;

  

  iVar1 = FUN_00403e50();

  if (iVar1 != *(int *)(in_EAX + 4)) {

    if ((*(int *)(iVar1 + 0x14) <= (int)unaff_EDI[1]) &&

       ((*(int *)(iVar1 + 0x14) < (int)unaff_EDI[1] || (*(uint *)(iVar1 + 0x10) <= *unaff_EDI)))) {

      *param_1 = iVar1;

      return param_1;

    }

  }

  *param_1 = *(int *)(in_EAX + 4);

  return param_1;

}
