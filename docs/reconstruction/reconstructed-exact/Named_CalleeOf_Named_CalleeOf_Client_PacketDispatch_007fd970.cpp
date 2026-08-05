// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_007fd970
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd970
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x007fd970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: return×9, switch×1.
//  - Notable callees: FUN_007fd970.
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_007fd970(uint8_t param_1)



{

  uint8_t *in_EAX;

  

  switch(param_1) {

  case 0:

    in_EAX[3] = 0xff;

    in_EAX[2] = 0xc1;

    in_EAX[1] = 0xc1;

    *in_EAX = 0xc1;

    return;

  case 1:

    in_EAX[2] = 0;

    in_EAX[1] = 0x8f;

    in_EAX[3] = 0xff;

    *in_EAX = 0xff;

    return;

  case 2:

    in_EAX[2] = 0xff;

    in_EAX[1] = 0x4b;

    *in_EAX = 0x2c;

    in_EAX[3] = 0xff;

    return;

  case 3:

    in_EAX[2] = 0x6c;

    in_EAX[1] = 0xf4;

    *in_EAX = 0xb;

    in_EAX[3] = 0xff;

    return;

  case 4:

    in_EAX[2] = 0xff;

    in_EAX[1] = 0xc9;

    *in_EAX = 0;

    in_EAX[3] = 0xff;

    return;

  default:

    in_EAX[3] = 0xff;

    in_EAX[2] = 0xff;

    in_EAX[1] = 0xff;

    *in_EAX = 0xff;

    return;

  case 100:

    in_EAX[2] = 0xff;

    in_EAX[1] = 0;

    *in_EAX = 0;

    in_EAX[3] = 0xff;

    return;

  case 0x65:

    in_EAX[2] = 0;

    in_EAX[1] = 0xff;

    *in_EAX = 0;

    in_EAX[3] = 0xff;

    return;

  case 0x66:

    in_EAX[2] = 0;

    in_EAX[1] = 0;

    in_EAX[3] = 0xff;

    *in_EAX = 0xff;

    return;

  }

}
