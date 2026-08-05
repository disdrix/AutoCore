// =============================================================================
// FUN_006f0c20
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0c20
// Address:   0x006f0c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0c20 @ 0x006f0c20
// Stable ID: aa_006f0c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f0c20.
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

void __thiscall FUN_006f0c20(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_00a0edac;

  param_1[4] = param_2[4];

  param_1[5] = param_2[5];

  param_1[6] = param_2[6];

  param_1[7] = param_2[7];

  param_1[7] = -((float)param_2[0xc] * (float)param_2[4] +

                (float)param_2[0xd] * (float)param_2[5] + (float)param_2[0xe] * (float)param_2[6]);

  param_1[8] = param_2[0xc];

  param_1[9] = param_2[0xd];

  param_1[10] = param_2[0xe];

  param_1[0xb] = param_2[0xf];

  param_1[0xc] = param_2[8];

  param_1[0xd] = param_2[9];

  param_1[0xe] = param_2[10];

  param_1[0xf] = param_2[0xb];

  return;

}
