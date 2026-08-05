// =============================================================================
// FUN_0096e1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e1f0
// Address:   0x0096e1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096e1f0 @ 0x0096e1f0
// Stable ID: aa_0096e1f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00449dc0, FUN_0096e1f0.
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

void FUN_0096e1f0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  fVar1 = g_flOne;

  *(float *)(unaff_ESI + 0x10) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = DAT_00d1a6c0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = DAT_00d1a6c4;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = DAT_00d1a6c8;

  *(float *)(unaff_ESI + 0x20) = fVar1;

  *(float *)(unaff_ESI + 0x24) = fVar1;

  *(float *)(unaff_ESI + 0x28) = fVar1;

  FUN_00449dc0();

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x144) = param_1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x148) = param_2;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x150) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x154) = 0;

  return;

}
