// =============================================================================
// FUN_008f5dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f5dd0
// Address:   0x008f5dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f5dd0 @ 0x008f5dd0
// Stable ID: aa_008f5dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, return×1.
//  - Notable callees: FUN_008f5dd0.
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

void FUN_008f5dd0(void)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  char unaff_BL;

  int *piVar3;

  int iVar4;

  

  piVar3 = (int *)(in_EAX + 0x540);

  iVar4 = 2;

  do {

    if (*piVar3 != 0) {

      iVar2 = 0xe88;

      do {

        iVar1 = *(int *)(iVar2 + *piVar3);

        if ((iVar1 != 0) && (*(uint8_t *)(iVar1 + 0x51c) = 1, unaff_BL != '\0')) {

          *(uint8_t *)(iVar1 + 0x51d) = 1;

        }

        iVar2 = iVar2 + 4;

      } while (iVar2 < 0x10e0);

    }

    piVar3 = piVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return;

}
