// =============================================================================
// Named_CalleeOf_Named_Server_deleted_0055e410
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e410
// Callee of Named_Server_deleted
// Address:   0x0055e410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Server_deleted: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0055e410.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Server_deleted
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

void __thiscall Named_CalleeOf_Named_Server_deleted_0055e410(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  if (0 < *(int *)(param_1 + 0x70)) {

    piVar2 = *(int **)(param_1 + 0x6c);

    do {

      if (*piVar2 == param_2) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x6c) + iVar1 * 4) = 0;

        return;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < *(int *)(param_1 + 0x70));

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x6c) + -4) = 0;

  return;

}
