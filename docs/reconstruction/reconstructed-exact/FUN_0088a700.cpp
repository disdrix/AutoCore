// =============================================================================
// FUN_0088a700
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a700
// Address:   0x0088a700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088a700 @ 0x0088a700
// Stable ID: aa_0088a700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_0088a700.
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

void FUN_0088a700(void)



{

  int *unaff_ESI;

  int *unaff_EDI;

  

  if (unaff_ESI != (int *)0x0) {

    if (*unaff_ESI != 0) {

      (**(code **)(*unaff_EDI + 0xb0))(*unaff_ESI);

      if ((uint32_t /* width from decompiler */ *)*unaff_ESI != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*unaff_ESI)(1);

      }

    }

    *unaff_ESI = 0;

    if (unaff_ESI[1] != 0) {

      (**(code **)(*unaff_EDI + 0xb0))(unaff_ESI[1]);

    }

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[1] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[1])(1);

    }

    unaff_ESI[1] = 0;

    if (unaff_ESI[2] != 0) {

      (**(code **)(*unaff_EDI + 0xb0))(unaff_ESI[2]);

    }

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[2] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[2])(1);

    }

    unaff_ESI[2] = 0;

    if (unaff_ESI[3] != 0) {

      (**(code **)(*unaff_EDI + 0xb0))(unaff_ESI[3]);

    }

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[3] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[3])(1);

    }

    unaff_ESI[3] = 0;

  }

  return;

}
