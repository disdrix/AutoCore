// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0053d430
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d430
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0053d430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00507100, FUN_0053d430, FUN_005d4440.
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_0053d430(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 8) != 0) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    iVar2 = *(int *)(iVar1 + 0xa8 + param_1);

    if (*(char *)(iVar2 + 0x7d) == '\0') {

      if (((*(char *)(iVar2 + 0xf5) != '\0') &&

          (iVar1 = *(int *)(*(int *)(iVar1 + param_1 + 0xac) + 0x38), iVar1 != 0x14)) &&

         (iVar1 != 0x12)) {

        (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1bc))(1);

        FUN_005d4440(7);

      }

      if ((*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x38) != 0xe)

         && (*(char *)(*(int *)(param_1 + 8) + 0x40) == '\0')) {

        FUN_00507100();

        return;

      }

    }

  }

  return;

}
