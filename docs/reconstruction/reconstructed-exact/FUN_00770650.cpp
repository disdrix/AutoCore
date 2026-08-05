// =============================================================================
// FUN_00770650
// -----------------------------------------------------------------------------
// Stable ID: aa_00770650
// Address:   0x00770650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770650 @ 0x00770650
// Stable ID: aa_00770650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×2, while×2.
//  - Notable callees: FUN_00770490, FUN_00770650.
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

int FUN_00770650(void)



{

  int *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *unaff_EDI;

  

  if (unaff_EDI != in_EAX) {

    if ((in_EAX[1] < *unaff_EDI) && (iVar1 = FUN_00770490(), iVar1 != 0)) {

      return iVar1;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)unaff_EDI[3];

    puVar2 = (uint32_t /* width from decompiler */ *)in_EAX[3];

    iVar1 = 0;

    if (0 < *unaff_EDI) {

      do {

        *puVar2 = *puVar3;

        iVar1 = iVar1 + 1;

        puVar2 = puVar2 + 1;

        puVar3 = puVar3 + 1;

      } while (iVar1 < *unaff_EDI);

    }

    if (iVar1 < *in_EAX) {

      do {

        *puVar2 = 0;

        iVar1 = iVar1 + 1;

        puVar2 = puVar2 + 1;

      } while (iVar1 < *in_EAX);

    }

    *in_EAX = *unaff_EDI;

    in_EAX[2] = unaff_EDI[2];

  }

  return 0;

}
