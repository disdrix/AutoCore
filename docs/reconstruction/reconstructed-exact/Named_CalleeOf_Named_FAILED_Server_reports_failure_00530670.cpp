// =============================================================================
// Named_CalleeOf_Named_FAILED_Server_reports_failure_00530670
// -----------------------------------------------------------------------------
// Stable ID: aa_00530670
// Callee of Named_FAILED_Server_reports_failure
// Address:   0x00530670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_FAILED_Server_reports_failure: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00418b80×2, FUN_005305b0, FUN_00530670.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_FAILED_Server_reports_failure
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_FAILED_Server_reports_failure_00530670(uint param_1,uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint local_4;

  

  uVar2 = param_2;

  local_4 = param_1;

  FUN_00418b80(&local_4,&param_2);

  uVar1 = *(uint *)(param_1 + 0x588);

  if ((local_4 != uVar1) && (0 < *(int *)(local_4 + 0x14))) {

    param_2 = uVar2;

    FUN_00418b80(&local_4,&param_2);

    if (local_4 != uVar1) {

      *(uint32_t /* width from decompiler */ *)(local_4 + 0x10) = 0;

      if (*(int *)(local_4 + 0x14) < 0) {

        *(int *)(local_4 + 0x10) = *(int *)(local_4 + 0x14);

      }

      *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;

    }

    FUN_005305b0(uVar2,0);

    *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;

    return 1;

  }

  return 0;

}
