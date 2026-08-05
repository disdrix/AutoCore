// =============================================================================
// FUN_00476c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00476c00
// Address:   0x00476c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476c00 @ 0x00476c00
// Stable ID: aa_00476c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_004766e0, FUN_00476c00, free.
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

void FUN_00476c00(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  int unaff_ESI;

  

  FUN_004766e0();

  if (*(int *)(unaff_ESI + 0x220) != 0) {

    if (*(void **)(unaff_ESI + 0x224) != (void *)0x0) {

      if (*(code **)(unaff_ESI + 0x24c) == (code *)0x0) {

        free(*(void **)(unaff_ESI + 0x224));

      }

      else {

        (**(code **)(unaff_ESI + 0x24c))();

      }

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x224) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x220) = 0;

  }

  for (iVar1 = 0x48; iVar1 != 0; iVar1 = iVar1 + -1) {

    *in_EAX = 0;

    in_EAX = in_EAX + 1;

  }

  return;

}
