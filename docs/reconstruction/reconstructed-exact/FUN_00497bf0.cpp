// =============================================================================
// FUN_00497bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00497bf0
// Address:   0x00497bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497bf0 @ 0x00497bf0
// Stable ID: aa_00497bf0
// Embedded strings (evidence for future rename):
//   - "CVOGFlairObject"
//   - "m_cbidVisualID"
//   - "m_fDrawSizeMin"
//   - "m_fDrawSizeVariance"
//   - "m_chThreshholdMin"
//   - "m_chThreshholdMax"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004988c0×3, FUN_00498800×2, FUN_00497bf0, FUN_00498740, FUN_00498980, FUN_0079d1e0, FUN_0079d290.
//  - Strings: "CVOGFlairObject"; "m_cbidVisualID"; "m_fDrawSizeMin"; "m_fDrawSizeVariance".
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

void __fastcall FUN_00497bf0(int param_1)



{

  FUN_0079d290(1,"CVOGFlairObject");

  FUN_00498740("m_cbidVisualID",param_1);

  FUN_00498800("m_fDrawSizeMin",param_1 + 4);

  FUN_00498800("m_fDrawSizeVariance",param_1 + 8);

  FUN_004988c0("m_chThreshholdMin",param_1 + 0xc);

  FUN_004988c0("m_chThreshholdMax",param_1 + 0xd);

  FUN_004988c0("m_chLayerMask",param_1 + 0xe);

  FUN_00498980("m_bPlaceWithGroundNormal",param_1 + 0xf);

  FUN_0079d1e0();

  return;

}
