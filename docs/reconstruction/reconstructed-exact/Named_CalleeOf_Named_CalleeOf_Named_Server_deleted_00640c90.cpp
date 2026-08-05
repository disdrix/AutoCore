// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_deleted_00640c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00640c90
// Callee of Named_CalleeOf_Named_Server_deleted
// Address:   0x00640c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_deleted: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00640c90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_deleted
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Server_deleted_00640c90(int *param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < param_1[9]) {

    do {

      if (*(int *)(param_1[8] + iVar1 * 4) != 0) {

        (**(code **)(*param_1 + 0x10))(iVar1);

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < param_1[9]);

  }

  return;

}
