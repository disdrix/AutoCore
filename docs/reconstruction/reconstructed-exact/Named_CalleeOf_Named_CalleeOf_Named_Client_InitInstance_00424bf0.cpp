// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00424bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00424bf0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00424bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00424bf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00424bf0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  *in_EAX = 0;

  in_EAX[1] = 0;

  *(uint8_t *)(in_EAX + 2) = 0;

  *(uint8_t *)((int)in_EAX + 10) = 0;

  *(uint8_t *)((int)in_EAX + 0xb) = 0;

  *(uint8_t *)(in_EAX + 3) = 0;

  *(uint8_t *)((int)in_EAX + 0xd) = 0;

  *(uint8_t *)((int)in_EAX + 0xe) = 0;

  *(uint8_t *)((int)in_EAX + 0x11) = 0;

  *(uint8_t *)((int)in_EAX + 0x12) = 0;

  in_EAX[9] = 0;

  in_EAX[10] = 0;

  *(uint8_t *)((int)in_EAX + 9) = 1;

  *(uint8_t *)((int)in_EAX + 0xf) = 1;

  *(uint8_t *)(in_EAX + 4) = 1;

  in_EAX[5] = 0x20;

  in_EAX[6] = 0x18;

  in_EAX[7] = 8;

  in_EAX[8] = 4;

  in_EAX[0xc] = 600;

  in_EAX[0xb] = 800;

  in_EAX[0xd] = 0x400;

  in_EAX[0xe] = 0x300;

  in_EAX[0x10] = 600;

  in_EAX[0xf] = 800;

  in_EAX[0x11] = 0x20;

  in_EAX[0x12] = 0x80000000;

  in_EAX[0x13] = 0x80000000;

  return;

}
