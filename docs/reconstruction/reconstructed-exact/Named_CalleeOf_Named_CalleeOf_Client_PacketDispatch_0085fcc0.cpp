// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0085fcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0085fcc0
// Callee of Named_CalleeOf_Client_PacketDispatch (+1 other named callers)
// Address:   0x0085fcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_PacketDispatch (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00413a60, FUN_007fbb70, FUN_0085fcc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0085fcc0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *unaff_ESI;

  int *local_4;

  

  if (unaff_ESI[0x15c] != 0) {

    local_4 = (int *)0x0;

    FUN_00413a60(param_1,param_2,&local_4);

    piVar1 = local_4;

    if (local_4 != (int *)0x0) {

      (**(code **)(*local_4 + 0x3ac))();

      FUN_007fbb70();

      (**(code **)(*unaff_ESI + 0xbc))(piVar1);

      unaff_ESI[0x140] = unaff_ESI[0x140] + -1;

    }

  }

  return;

}
