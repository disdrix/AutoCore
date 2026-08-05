// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00784af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00784af0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
// Address:   0x00784af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007843e0, FUN_00784af0, getsockname, htonl.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00784af0(SOCKET *param_1)



{

  uint32_t /* width from decompiler */ *unaff_EBX;

  int local_28;

  sockaddr local_24;

  uint32_t /* width from decompiler */ local_14;

  u_long local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_14 = 0;

  local_4 = 0;

  local_8 = 0;

  local_c = 0;

  local_10 = htonl(0);

  local_28 = 0x10;

  getsockname(*param_1,&local_24,&local_28);

  FUN_007843e0();

  *unaff_EBX = local_14;

  unaff_EBX[1] = local_10;

  unaff_EBX[2] = local_c;

  unaff_EBX[3] = local_8;

  unaff_EBX[4] = local_4;

  return;

}
