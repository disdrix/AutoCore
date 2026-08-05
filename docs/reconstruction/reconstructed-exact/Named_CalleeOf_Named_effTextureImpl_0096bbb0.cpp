// =============================================================================
// Named_CalleeOf_Named_effTextureImpl_0096bbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bbb0
// Callee of Named_effTextureImpl
// Address:   0x0096bbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effTextureImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0096bbb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_effTextureImpl
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

void Named_CalleeOf_Named_effTextureImpl_0096bbb0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  in_EAX[1] = &PTR_LAB_009d45f0;

  in_EAX[2] = 0;

  *in_EAX = &PTR_LAB_00aa0a20;

  in_EAX[1] = &PTR_LAB_00aa0a10;

  in_EAX[3] = 0;

  in_EAX[4] = 0;

  in_EAX[5] = 0;

  in_EAX[6] = 0;

  in_EAX[7] = DAT_00d1f01c;

  in_EAX[8] = DAT_00d1f020;

  in_EAX[9] = 0;

  in_EAX[10] = 0;

  in_EAX[0xb] = 0x101;

  in_EAX[0xc] = 1;

  in_EAX[0xd] = 1;

  in_EAX[0xe] = 0xffffffff;

  in_EAX[0xf] = 0xffffffff;

  in_EAX[0x10] = 0;

  in_EAX[0x11] = 0;

  in_EAX[0x12] = 1;

  in_EAX[0x13] = 0;

  in_EAX[0x14] = 0;

  return;

}
