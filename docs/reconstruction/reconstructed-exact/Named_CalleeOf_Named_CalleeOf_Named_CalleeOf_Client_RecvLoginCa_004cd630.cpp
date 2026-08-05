// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_004cd630
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd630
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
// Address:   0x004cd630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004cd630.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_004cd630(int param_1)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 0x78);

  if (piVar1 != (int *)0x0) {

    if (*(int *)(param_1 + 0xe4ec) != 0) {

      (**(code **)(*piVar1 + 0x18))(1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

      return;

    }

    (**(code **)*piVar1)(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  }

  return;

}
