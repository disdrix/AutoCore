// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Sending_punch_packet_s_s_to_007837e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007837e0
// Callee of Named_CalleeOf_Named_Sending_punch_packet_s_s_to_s
// Address:   0x007837e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Sending_punch_packet_s_s_to_s: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0077c610, FUN_007837e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Sending_punch_packet_s_s_to_s
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_Sending_punch_packet_s_s_to_007837e0(byte *param_1,int param_2)



{

  byte bVar1;

  byte *in_EAX;

  int unaff_ESI;

  

  for (; param_2 != 0; param_2 = param_2 + -1) {

    if (*(int *)(unaff_ESI + 0x270) == 0x10) {

      FUN_0077c610(unaff_ESI + 0x5c,unaff_ESI + 0x5c,unaff_ESI + 0x6c);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x270) = 0;

    }

    bVar1 = *(byte *)(*(int *)(unaff_ESI + 0x270) + 0x5c + unaff_ESI) ^ *param_1;

    param_1 = param_1 + 1;

    *in_EAX = bVar1;

    *(byte *)(*(int *)(unaff_ESI + 0x270) + 0x5c + unaff_ESI) = bVar1;

    *(int *)(unaff_ESI + 0x270) = *(int *)(unaff_ESI + 0x270) + 1;

    in_EAX = in_EAX + 1;

  }

  return;

}
