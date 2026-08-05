// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ClientSpecialEvent_Teleport_0044b5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b5c0
// Callee of Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn
// Address:   0x0044b5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00412d40×2, FUN_0044b5c0, FUN_00972e50, FUN_009730e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_ClientSpecialEvent_Teleport_0044b5c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_EDI;

  

  if ((*(uint *)(param_1 + 0xbc) >> 1 & 1) == 0) {

    param_1 = param_1 + 0x40;

  }

  else {

    param_1 = FUN_009730e0();

  }

  if ((*(byte *)(unaff_EDI + 0xbc) & 1) != 0) {

    uVar1 = FUN_00972e50();

    FUN_00412d40(param_2,uVar1,param_1);

    return param_2;

  }

  FUN_00412d40(param_2);

  return param_2;

}
