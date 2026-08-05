// =============================================================================
// FUN_00604dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00604dd0
// Address:   0x00604dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00604dd0 @ 0x00604dd0
// Stable ID: aa_00604dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGHBBase_RescheduleAfterFire, FUN_005134e0, FUN_00604dd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall FUN_00604dd0(CVOGHBBase *param_1,uint *param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint *extraout_EDX;

  uint *extraout_EDX_00;

  

  if (param_1->pOwnerObject != (void *)0x0) {

    cVar1 = FUN_005134e0();

    param_2 = extraout_EDX;

    if (cVar1 != '\0') {

      (**(code **)((int)param_1->pVTable + 0x18))(1,1);

      param_2 = extraout_EDX_00;

    }

  }

  CVOGHBBase_RescheduleAfterFire(param_1,param_2);

  return param_3;

}
