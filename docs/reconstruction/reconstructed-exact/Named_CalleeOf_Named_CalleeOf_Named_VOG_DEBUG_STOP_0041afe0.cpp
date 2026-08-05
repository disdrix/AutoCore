// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0041afe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041afe0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0041afe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0041afe0, FUN_0041ca90, FUN_004220f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0041afe0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int local_4;

  

  iVar1 = *(int *)(param_1 + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x3d4) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x3d4))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_004220f0(param_1);

    *(int *)(param_1 + 8) = iVar1 + 0x3d4;

    return;

  }

  FUN_0041ca90(&local_4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),in_EAX);

  return;

}
