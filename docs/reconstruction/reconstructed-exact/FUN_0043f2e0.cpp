// =============================================================================
// FUN_0043f2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f2e0
// Address:   0x0043f2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043f2e0 @ 0x0043f2e0
// Stable ID: aa_0043f2e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0043f2e0.
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

void FUN_0043f2e0(float param_1,float param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float *in_EAX;

  float in_XMM1_Da;

  float fVar3;

  float in_XMM4_Da;

  float in_XMM5_Da;

  

  fVar2 = g_flLevelUpUiBase_Inferred;

  fVar1 = g_flOne;

  fVar3 = g_flLevelUpUiBase_Inferred / (in_XMM4_Da - in_XMM1_Da);

  in_EAX[1] = 0.0;

  in_EAX[2] = 0.0;

  in_EAX[3] = 0.0;

  in_EAX[4] = 0.0;

  in_EAX[6] = 0.0;

  in_EAX[7] = 0.0;

  in_EAX[8] = 0.0;

  in_EAX[9] = 0.0;

  in_EAX[0xb] = 0.0;

  *in_EAX = fVar3;

  in_EAX[0xc] = (in_XMM1_Da + in_XMM4_Da) / (in_XMM1_Da - in_XMM4_Da);

  in_EAX[5] = fVar2 / (in_XMM5_Da - param_1);

  in_EAX[0xd] = (param_1 + in_XMM5_Da) / (param_1 - in_XMM5_Da);

  fVar2 = g_flOne;

  in_EAX[10] = fVar1 / (param_3 - param_2);

  in_EAX[0xe] = param_2 / (param_2 - param_3);

  in_EAX[0xf] = fVar2;

  return;

}
