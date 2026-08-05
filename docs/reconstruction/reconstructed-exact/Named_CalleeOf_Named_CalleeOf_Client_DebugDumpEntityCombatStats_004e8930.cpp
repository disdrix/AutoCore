// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEntityCombatStats_004e8930
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8930
// Callee of Named_CalleeOf_Client_DebugDumpEntityCombatStats
// Address:   0x004e8930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_DebugDumpEntityCombatStats: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00424b50×2, FUN_004e8930, SQRT.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_DebugDumpEntityCombatStats
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEntityCombatStats_004e8930(float *param_1,float param_2,float param_3,float param_4,float param_5)



{

  float *in_EAX;

  float *unaff_ESI;

  float local_40;

  float local_3c;

  float local_38 [2];

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_14;

  

  local_14 = (SQRT((param_1[2] - in_EAX[2]) * (param_1[2] - in_EAX[2]) +

                   (*param_1 - *in_EAX) * (*param_1 - *in_EAX)) - param_2) - param_3;

  if (local_14 <= param_5) {

    local_40 = *in_EAX - *param_1;

    local_3c = 0.0;

    local_38[0] = in_EAX[2] - param_1[2];

    FUN_00424b50(&local_40,&local_3c,local_38);

    local_30 = *unaff_ESI;

    local_28 = unaff_ESI[2];

    local_24 = unaff_ESI[3];

    local_2c = 0.0;

    FUN_00424b50(&local_30,&local_2c,&local_28);

    if ((param_4 < local_2c * local_3c + local_28 * local_38[0] + local_40 * local_30) &&

       (local_14 <= g_flMsToSeconds_Inferred)) {

      return;

    }

  }

  return;

}
