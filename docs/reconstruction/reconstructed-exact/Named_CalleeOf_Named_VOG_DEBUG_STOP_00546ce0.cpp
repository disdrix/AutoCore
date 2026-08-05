// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00546ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00546ce0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00546ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: fwrite×3, FUN_00546ce0.
//  - Return sites: 1.

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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00546ce0(void *param_1,FILE *param_2)



{

  int iVar1;

  uint local_4;

  

  local_4 = (uint)*(byte *)((int)param_1 + 0x130);

  fwrite(param_1,0x138,1,param_2);

  fwrite(&local_4,4,1,param_2);

  iVar1 = 0;

  if (0 < (int)local_4) {

    do {

      fwrite((void *)(*(int *)(*(int *)((int)param_1 + 0x13c) + iVar1 * 4) + 0xc),0x140,1,param_2);

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)local_4);

  }

  return;

}
