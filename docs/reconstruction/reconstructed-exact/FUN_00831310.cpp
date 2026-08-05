// =============================================================================
// FUN_00831310
// -----------------------------------------------------------------------------
// Stable ID: aa_00831310
// Address:   0x00831310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00831310 @ 0x00831310
// Stable ID: aa_00831310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00831310.
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

void __fastcall FUN_00831310(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5a0);

  iVar2 = 0x19;

  do {

    puVar1[-0x19] = 0;

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
