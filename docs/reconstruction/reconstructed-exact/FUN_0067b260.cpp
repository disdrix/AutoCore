// =============================================================================
// FUN_0067b260
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b260
// Address:   0x0067b260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067b260 @ 0x0067b260
// Stable ID: aa_0067b260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0067b260, FUN_006847f0, htonl, htons.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_0067b260(int param_1,u_short param_2,uint32_t /* width from decompiler */ *param_3)



{

  u_short uVar1;

  u_long uVar2;

  

  if (*(uint *)(param_1 + 0x18) < 0x10) {

    param_1 = param_1 + 4;

  }

  else {

    param_1 = *(int *)(param_1 + 4);

  }

  uVar2 = FUN_006847f0(param_1);

  if (uVar2 != 0xffffffff) {

    uVar2 = htonl(uVar2);

    *param_3 = 0;

    param_3[1] = 0;

    param_3[2] = 0;

    param_3[3] = 0;

    param_3[1] = uVar2;

    *(uint16_t *)param_3 = 2;

    uVar1 = htons(param_2);

    *(u_short *)((int)param_3 + 2) = uVar1;

    return 0;

  }

  return 0xffffffff;

}
