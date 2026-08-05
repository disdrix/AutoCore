// =============================================================================
// FUN_00462600
// -----------------------------------------------------------------------------
// Stable ID: aa_00462600
// Address:   0x00462600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00462600 @ 0x00462600
// Stable ID: aa_00462600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004540b0, FUN_00462600.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00462600(void)



{

  uint in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  if (in_EAX == 0) {

    return 0;

  }

  if (0x1fffffff < in_EAX) {

    uVar1 = FUN_004540b0();

    return uVar1;

  }

  pvVar2 = operator_new(in_EAX * 8);

  *(void **)(unaff_ESI + 4) = pvVar2;

  *(void **)(unaff_ESI + 8) = pvVar2;

  *(void **)(unaff_ESI + 0xc) = (void *)(in_EAX * 8 + (int)pvVar2);

  return 1;

}
