// =============================================================================
// FUN_0041a070
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a070
// Address:   0x0041a070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041a070 @ 0x0041a070
// Stable ID: aa_0041a070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0041a070, _com_issue_errorex.
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

void FUN_0041a070(void)



{

  HRESULT HVar1;

  IUnknown *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  HVar1 = (*unaff_ESI->lpVtbl[0x14].QueryInterface)(unaff_ESI,(IID *)&stack0xfffffffc,(void **)0x0);

  if (HVar1 < 0) {

    _com_issue_errorex(HVar1,unaff_ESI,(_GUID *)&DAT_00a86138);

    *unaff_EDI = unaff_retaddr;

    return;

  }

  *unaff_EDI = unaff_retaddr;

  return;

}
