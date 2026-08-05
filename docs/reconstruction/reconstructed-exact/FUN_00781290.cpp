// =============================================================================
// FUN_00781290
// -----------------------------------------------------------------------------
// Stable ID: aa_00781290
// Address:   0x00781290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00781290 @ 0x00781290
// Stable ID: aa_00781290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00974d80×2, FUN_00781290.
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

void FUN_00781290(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = operator_new(0x24);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[4] = 0;

    puVar1[3] = 1;

    *puVar1 = &PTR_LAB_00a9b7c4;

    puVar1[6] = &PTR_LAB_00a9b7b0;

    puVar1[7] = &LAB_00431f50;

    puVar1[5] = puVar1 + 6;

    puVar1[8] = param_2;

    FUN_00974d80(puVar1);

    return;

  }

  uRam00000020 = param_2;

  FUN_00974d80(0);

  return;

}
