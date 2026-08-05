// =============================================================================
// Named_CalleeOf_Auth_i_d_fet_2d_wnd_frame_btn_login_xml_00795f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00795f20
// Callee of Auth_i_d_fet_2d_wnd_frame_btn_login_xml
// Address:   0x00795f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Auth_i_d_fet_2d_wnd_frame_btn_login_xml: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00795f20, FUN_007b5dd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Auth_i_d_fet_2d_wnd_frame_btn_login_xml
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

void Named_CalleeOf_Auth_i_d_fet_2d_wnd_frame_btn_login_xml_00795f20(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_007b5dd0(unaff_ESI,in_EAX);

  *(uint8_t *)(unaff_ESI + 0x122) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x489) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x48a) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x48b) = 0;

  *(uint8_t *)(unaff_ESI + 0x123) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x48d) = 0;

  *(uint8_t *)((int)unaff_ESI + 0xd9) = 0;

  unaff_ESI[0x124] = 0;

  *(uint8_t *)(unaff_ESI + 0x125) = 0;

  unaff_ESI[0x126] = 0;

  unaff_ESI[0x127] = 0;

  unaff_ESI[0x128] = 0;

  *unaff_ESI = &PTR_FUN_00a98b1c;

  unaff_ESI[0x8a] = DAT_00d1e7a8;

  unaff_ESI[0x8b] = DAT_00d1e7ac;

  return;

}
