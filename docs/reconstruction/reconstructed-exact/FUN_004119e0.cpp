// =============================================================================
// FUN_004119e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004119e0
// Address:   0x004119e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004119e0 @ 0x004119e0
// Stable ID: aa_004119e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: __allmul×2, FUN_004119e0, block.
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

/* WARNING: Removing unreachable block (ram,0x00411a08) */



uint32_t /* width from decompiler */ FUN_004119e0(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint64_t uVar2;

  longlong lVar3;

  

  param_1 = *(int *)(in_EAX + 0x654) + param_1;

  uVar2 = __allmul(param_1,param_1 >> 0x1f,param_1,param_1 >> 0x1f);

  lVar3 = __allmul(uVar2,2000,0);

  uVar1 = (uint32_t /* width from decompiler */)lVar3;

  if (0x1312d0 < lVar3) {

    uVar1 = 0x1312d0;

  }

  return uVar1;

}
