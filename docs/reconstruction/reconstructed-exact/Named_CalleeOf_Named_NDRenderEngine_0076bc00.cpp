// =============================================================================
// Named_CalleeOf_Named_NDRenderEngine_0076bc00
// -----------------------------------------------------------------------------
// Stable ID: aa_0076bc00
// Callee of Named_NDRenderEngine (+1 other named callers)
// Address:   0x0076bc00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_NDRenderEngine: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_NDRenderEngine (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CreateDirectoryA×2, FUN_0076adc0, FUN_0076b080, FUN_0076ba10, FUN_0076bc00, stat.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_NDRenderEngine (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

bool Named_CalleeOf_Named_NDRenderEngine_0076bc00(LPCSTR param_1,char param_2)



{

  char cVar1;

  BOOL BVar2;

  int iVar3;

  uint8_t local_24 [6];

  uint local_1e;

  

  if (param_2 != '\0') {

    cVar1 = FUN_0076adc0(param_1);

    if (cVar1 != '\0') {

      FUN_0076ba10(param_1,1);

      BVar2 = CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);

      return BVar2 != 0;

    }

    iVar3 = stat(param_1,local_24);

    if ((iVar3 == 0) && ((local_1e >> 0xf & 1) != 0)) {

      FUN_0076b080(1);

    }

  }

  BVar2 = CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);

  return BVar2 != 0;

}
