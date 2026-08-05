// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080cbf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080cbf0
// Callee of Client_PacketDispatch
// Address:   0x0080cbf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fef20, FUN_0080cbf0, FUN_0086d580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_0080cbf0(int param_1)



{

  char cVar1;

  int unaff_ESI;

  

  FUN_007fef20(0x39,1,0);

  if (*(int **)(param_1 + 0x1114) != (int *)0x0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x1114) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_0086d580(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),

                   *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),unaff_ESI + 0x14,unaff_ESI + 0x1c,

                   unaff_ESI + 0x30);

    }

  }

  return;

}
