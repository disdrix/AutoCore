// =============================================================================
// FUN_004380f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004380f0
// Address:   0x004380f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004380f0 @ 0x004380f0
// Stable ID: aa_004380f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_004380f0.
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

void FUN_004380f0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

    return;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 8);

  for (; puVar2 != puVar1; puVar2 = puVar2 + 2) {

    (**(code **)*puVar2)(0);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_EBX + 4));

}
