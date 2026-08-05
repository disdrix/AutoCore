// =============================================================================
// FUN_00753bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00753bc0
// Address:   0x00753bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753bc0 @ 0x00753bc0
// Stable ID: aa_00753bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00756be0×2, FUN_004406e0, FUN_00753bc0.
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

void FUN_00753bc0(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_EBX;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x88) != in_EAX) {

    if (*(int *)(unaff_EDI + 0x88) != 0) {

      FUN_00756be0(unaff_EDI);

    }

    *(int *)(unaff_EDI + 0x88) = in_EAX;

    if (in_EAX != 0) {

      FUN_00756be0(unaff_EDI);

    }

    *(int *)(unaff_EDI + 0x88) = in_EAX;

    FUN_004406e0();

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x78) = *unaff_EBX;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7c) = unaff_EBX[1];

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xf8) = *unaff_EBX;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xfc) = unaff_EBX[1];

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x100) = param_1;

  return;

}
