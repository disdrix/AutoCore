// =============================================================================
// FUN_00782f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00782f60
// Address:   0x00782f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782f60 @ 0x00782f60
// Stable ID: aa_00782f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×2, while×2, do×1.
//  - Notable callees: FUN_00782de0, FUN_00782f60.
//  - Return sites: 3.

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

byte FUN_00782f60(void)



{

  int iVar1;

  byte bVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  byte bVar5;

  

  iVar4 = *(int *)(in_EAX + 4);

  bVar5 = 1;

  if (iVar4 != 0) {

    for (iVar1 = *(int *)(iVar4 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {

      iVar4 = iVar1;

    }

    do {

      bVar2 = FUN_00782de0();

      bVar5 = bVar5 & bVar2;

      iVar1 = *(int *)(iVar4 + 8);

      if (iVar1 == 0) {

        iVar1 = *(int *)(iVar4 + 0x10);

        if (*(int *)(iVar4 + 0x10) == 0) {

          return bVar5;

        }

        while (iVar3 = iVar1, iVar4 != *(int *)(iVar3 + 0xc)) {

          iVar1 = *(int *)(iVar3 + 0x10);

          iVar4 = iVar3;

          if (*(int *)(iVar3 + 0x10) == 0) {

            return bVar5;

          }

        }

        iVar4 = *(int *)(iVar4 + 0x10);

      }

      else {

        iVar4 = iVar1;

        for (iVar1 = *(int *)(iVar1 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {

          iVar4 = iVar1;

        }

      }

    } while (iVar4 != 0);

  }

  return bVar5;

}
