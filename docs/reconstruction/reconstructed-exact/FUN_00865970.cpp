// =============================================================================
// FUN_00865970
// -----------------------------------------------------------------------------
// Stable ID: aa_00865970
// Address:   0x00865970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00865970 @ 0x00865970
// Stable ID: aa_00865970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×1, for×1, return×1.
//  - Notable callees: FUN_00865970.
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

void FUN_00865970(void)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  int iVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  if (in_EAX != 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x510) = *(uint32_t /* width from decompiler */ *)(in_EAX + 4);

    pcVar2 = (char *)(in_EAX + 0x2e);

    *(uint16_t *)(unaff_EBX + 0x538) = *(uint16_t *)(in_EAX + 0x2c);

    iVar3 = (unaff_EBX + 0x53a) - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = (char *)(in_EAX + 9);

    iVar3 = (unaff_EBX + 0x515) - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    iVar4 = (*(int *)(unaff_EBX + 0x1a298) + 1) % 100;

    *(int *)(unaff_EBX + 0x1a298) = iVar4;

    puVar5 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x50c);

    puVar6 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x938 + iVar4 * 0x418);

    for (iVar3 = 0x106; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1a29c) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1a298);

  }

  return;

}
