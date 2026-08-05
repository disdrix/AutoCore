// =============================================================================
// FUN_007a70f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a70f0
// Address:   0x007a70f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a70f0 @ 0x007a70f0
// Stable ID: aa_007a70f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_007a70f0.
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

void FUN_007a70f0(void)



{

  char cVar1;

  void *pvVar2;

  char *pcVar3;

  char *unaff_EBX;

  int unaff_ESI;

  int unaff_EDI;

  

  pvVar2 = *(void **)(unaff_EDI + 0x45c + unaff_ESI * 4);

  if (pvVar2 != (void *)0x0) {

    operator_delete__(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x45c + unaff_ESI * 4) = 0;

  if (unaff_EBX != (char *)0x0) {

    pcVar3 = unaff_EBX;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(unaff_EBX + 1))));

    *(char **)(unaff_EDI + 0x45c + unaff_ESI * 4) = pcVar3;

    do {

      cVar1 = *unaff_EBX;

      *pcVar3 = cVar1;

      unaff_EBX = unaff_EBX + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
