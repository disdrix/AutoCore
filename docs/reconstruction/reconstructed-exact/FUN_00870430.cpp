// =============================================================================
// FUN_00870430
// -----------------------------------------------------------------------------
// Stable ID: aa_00870430
// Address:   0x00870430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00870430 @ 0x00870430
// Stable ID: aa_00870430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00870430.
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

void FUN_00870430(void)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if ((unaff_ESI != (uint32_t /* width from decompiler */ *)0x0) && (unaff_EDI != (uint32_t /* width from decompiler */ *)0x0)) {

    *unaff_ESI = *unaff_EDI;

    if ((void *)unaff_ESI[1] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[1]);

    }

    unaff_ESI[1] = 0;

    pcVar2 = (char *)unaff_EDI[1];

    if (pcVar2 != (char *)0x0) {

      pcVar3 = pcVar2 + 1;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      pcVar3 = operator_new__((uint)(pcVar2 + (1 - (int)pcVar3)));

      unaff_ESI[1] = pcVar3;

      pcVar2 = (char *)unaff_EDI[1];

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

    }

    unaff_ESI[2] = unaff_EDI[2];

  }

  return;

}
