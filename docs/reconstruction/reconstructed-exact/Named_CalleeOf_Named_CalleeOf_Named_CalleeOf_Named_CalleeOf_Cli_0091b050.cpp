// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0091b050
// -----------------------------------------------------------------------------
// Stable ID: aa_0091b050
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
// Address:   0x0091b050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007fea50, FUN_0091b050.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0091b050(void)



{

  int *unaff_ESI;

  

  *(uint8_t *)((int)unaff_ESI + 0xc65) = 0;

  *(uint8_t *)((int)unaff_ESI + 0xc66) = 0;

  FUN_007fea50();

  if (unaff_ESI[0x31a] != 0) {

    (**(code **)(*unaff_ESI + 0xb0))(unaff_ESI[0x31a]);

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x31a] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x31a])(1);

    }

    unaff_ESI[0x31a] = 0;

  }

  if (unaff_ESI[0x31b] != 0) {

    (**(code **)(*unaff_ESI + 0xb0))(unaff_ESI[0x31b]);

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x31b] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x31b])(1);

    }

    unaff_ESI[0x31b] = 0;

  }

  return;

}
