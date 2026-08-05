// =============================================================================
// Named_CalleeOf_Mission_Client_ClaimSelectedReward_0087b500
// -----------------------------------------------------------------------------
// Stable ID: aa_0087b500
// Callee of Mission_Client_ClaimSelectedReward (+1 other named callers)
// Address:   0x0087b500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Client_ClaimSelectedReward: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Client_ClaimSelectedReward (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0087b500.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_Client_ClaimSelectedReward (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Mission_Client_ClaimSelectedReward_0087b500(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((6 < param_2) && (param_2 < 0x10)) {

    return 1;

  }

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar2;

  }

  return 0;

}
