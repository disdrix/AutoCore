// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn_0071f060
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f060
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x0071f060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper. Evidence string: "couldn\'t seek ogg file". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "couldn\'t seek ogg file"
//   - "bad link ogg file"
//   - "invalid ogg file"
//   - "fault ogg file"
//   - "couldn\'t read ogg file"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_007a4480×5, FUN_0071f060.
//  - Strings: "couldn\'t seek ogg file"; "bad link ogg file"; "invalid ogg file"; "fault ogg file".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn_0071f060(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  

  switch(in_EAX) {

  case 0xffffff76:

    FUN_007a4480(0,"couldn\'t seek ogg file");

    return;

  case 0xffffff77:

    FUN_007a4480(0,"bad link ogg file");

    return;

  case 0xffffff7d:

    FUN_007a4480(0,"invalid ogg file");

    return;

  case 0xffffff7f:

    FUN_007a4480(0,"fault ogg file");

    break;

  case 0xffffff80:

    FUN_007a4480(0,"couldn\'t read ogg file");

    return;

  }

  return;

}
