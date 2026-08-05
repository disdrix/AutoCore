// =============================================================================
// FUN_008cc750
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc750
// Address:   0x008cc750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc750 @ 0x008cc750
// Stable ID: aa_008cc750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_008cc750, FUN_008d7420.
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

void FUN_008cc750(void)



{

  int extraout_ECX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  FUN_008d7420();

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x584) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x588) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x58c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x590) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x594) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x598) = 0;

  *(uint8_t *)(extraout_ECX + 0x658) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x62c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x630) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x634) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x638) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x63c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x640) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x644) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x648) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x64c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x650) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x654) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5cc);

  iVar2 = 0xc;

  do {

    puVar1[-0xc] = 0;

    *puVar1 = 0;

    puVar1[0xc] = 0;

    puVar1 = puVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
