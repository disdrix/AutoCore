// =============================================================================
// FUN_0040a890
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a890
// Address:   0x0040a890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040a890 @ 0x0040a890
// Stable ID: aa_0040a890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040a7d0×3, FUN_0040a890.
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

void FUN_0040a890(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  code *unaff_EBX;

  

  cVar1 = (*unaff_EBX)(param_2,param_1);

  if (cVar1 != '\0') {

    FUN_0040a7d0(param_2,param_1);

  }

  cVar1 = (*unaff_EBX)(param_3,param_2);

  if (cVar1 != '\0') {

    FUN_0040a7d0(param_3,param_2);

  }

  cVar1 = (*unaff_EBX)(param_2,param_1);

  if (cVar1 != '\0') {

    FUN_0040a7d0(param_2,param_1);

  }

  return;

}
