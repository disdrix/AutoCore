// =============================================================================
// FUN_00471f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00471f50
// Address:   0x00471f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00471f50 @ 0x00471f50
// Stable ID: aa_00471f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00471f50.
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

void FUN_00471f50(void)



{

  uint8_t *in_EAX;

  uint8_t *puVar1;

  int iVar2;

  int *unaff_ESI;

  

  if (*(char *)((int)unaff_ESI + 9) == '\x10') {

    puVar1 = in_EAX;

    for (iVar2 = (uint)*(byte *)((int)unaff_ESI + 10) * *unaff_ESI; iVar2 != 0; iVar2 = iVar2 + -1)

    {

      *puVar1 = *in_EAX;

      in_EAX = in_EAX + 2;

      puVar1 = puVar1 + 1;

    }

    *(uint8_t *)((int)unaff_ESI + 9) = 8;

    *(byte *)((int)unaff_ESI + 0xb) = *(byte *)((int)unaff_ESI + 10) * '\b';

    unaff_ESI[1] = (uint)*(byte *)((int)unaff_ESI + 10) * *unaff_ESI;

  }

  return;

}
