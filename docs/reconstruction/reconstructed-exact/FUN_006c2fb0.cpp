// =============================================================================
// FUN_006c2fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c2fb0
// Address:   0x006c2fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c2fb0 @ 0x006c2fb0
// Stable ID: aa_006c2fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c2fb0.
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

void FUN_006c2fb0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_2[1];

  uVar2 = *param_2;

  uVar3 = param_1[1];

  puVar1[3] = *param_1;

  puVar1[2] = param_3;

  puVar1[4] = uVar3;

  puVar1[5] = param_4;

  *puVar1 = 0x11801;

  puVar1[1] = uVar2;

  param_2[1] = puVar1 + 6;

  return;

}
