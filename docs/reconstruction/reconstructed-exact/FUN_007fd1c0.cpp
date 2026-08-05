// =============================================================================
// FUN_007fd1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd1c0
// Address:   0x007fd1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd1c0 @ 0x007fd1c0
// Stable ID: aa_007fd1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007fd1c0, FUN_0083e810.
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

void FUN_007fd1c0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  char *in_EAX;

  uint32_t /* width from decompiler */ unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  if (*(int *)(unaff_EDI + 0x30b0) != 0) {

    if ((in_EAX != (char *)0x0) && (*in_EAX != '\0')) {

      cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1168) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(unaff_EDI + 0x30b0) + 0x444))();

        FUN_0083e810(unaff_ESI,unaff_retaddr,param_1,param_2);

        *(uint8_t *)(unaff_EDI + 0x30be) = 0;

        *(uint8_t *)(unaff_EDI + 0x30bf) = 1;

        return;

      }

    }

    *(uint8_t *)(unaff_EDI + 0x30be) = 1;

    *(uint8_t *)(unaff_EDI + 0x30bf) = 0;

    if (*(int **)(unaff_EDI + 0x30b0) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_EDI + 0x30b0) + 4))(0);

    }

  }

  return;

}
