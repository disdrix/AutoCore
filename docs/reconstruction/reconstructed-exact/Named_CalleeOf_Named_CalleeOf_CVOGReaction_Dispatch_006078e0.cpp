// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_006078e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006078e0
// Callee of Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x006078e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper. Evidence string: "Total beacons was %f on map %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Total beacons was %f on map %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGMap_LookupVariable, FUN_00606ff0, FUN_006070e0, FUN_006078e0, FUN_007a4480.
//  - Strings: "Total beacons was %f on map %s".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_Dispatch
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

void __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_006078e0(int param_1)



{

  float local_c;

  float local_8;

  float local_4;

  

  local_c = g_flOne;

  local_8 = 0.0;

  local_4 = *(float *)(param_1 + 0x24c);

  CVOGMap_LookupVariable(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1d0),&local_c,0);

  CVOGMap_LookupVariable

            (*(uint32_t /* width from decompiler */ *)(param_1 + 0xf0 + *(int *)(param_1 + 0x234) * 0x48),&local_8,0);

  if (local_c <= g_flZero) {

    FUN_007a4480(0,"Total beacons was %f on map %s",(double)local_c,

                 *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xb4);

  }

  else {

    *(float *)(param_1 + 0x24c) = local_8 / local_c;

    if (local_4 != local_8 / local_c) {

      FUN_00606ff0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

      FUN_006070e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

      return;

    }

  }

  return;

}
