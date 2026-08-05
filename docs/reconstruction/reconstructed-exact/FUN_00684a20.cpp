// =============================================================================
// FUN_00684a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00684a20
// Address:   0x00684a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00684a20 @ 0x00684a20
// Stable ID: aa_00684a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00684830, FUN_00684a20, ntohl, ntohs.
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

uint32_t /* width from decompiler */ FUN_00684a20(uint32_t /* width from decompiler */ param_1,int param_2)



{

  u_short uVar1;

  u_long uVar2;

  

  uVar2 = ntohl(*(u_long *)(param_2 + 4));

  uVar1 = ntohs(*(u_short *)(param_2 + 2));

  FUN_00684830(param_1,uVar2,uVar1);

  return param_1;

}
