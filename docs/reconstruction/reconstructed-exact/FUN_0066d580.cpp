// =============================================================================
// FUN_0066d580
// -----------------------------------------------------------------------------
// Stable ID: aa_0066d580
// Address:   0x0066d580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066d580 @ 0x0066d580
// Stable ID: aa_0066d580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0066d580.
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

void __thiscall FUN_0066d580(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  *(uint8_t *)param_2 = *(uint8_t *)(param_1 + 0x18);

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  iVar2 = 0x20;

  do {

    param_2 = param_2 + 1;

    *param_2 = *puVar1;

    puVar1 = puVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
