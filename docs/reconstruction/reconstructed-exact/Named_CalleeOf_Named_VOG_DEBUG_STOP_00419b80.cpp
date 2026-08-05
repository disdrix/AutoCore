// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00419b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00419b80
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00419b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00419ad0×2, FUN_00419b40, FUN_00419b80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

int Named_CalleeOf_Named_VOG_DEBUG_STOP_00419b80(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int unaff_EBX;

  

  iVar1 = FUN_00419b40(param_1,param_2);

  if (iVar1 != 0) {

    if (param_1 != 0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

      FUN_00419ad0();

      return iVar1;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

  }

  FUN_00419ad0();

  return iVar1;

}
