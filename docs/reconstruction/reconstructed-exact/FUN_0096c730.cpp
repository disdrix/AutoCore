// =============================================================================
// FUN_0096c730
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c730
// Address:   0x0096c730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096c730 @ 0x0096c730
// Stable ID: aa_0096c730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_0044b1f0, FUN_0096c730.
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

int FUN_0096c730(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int unaff_EBX;

  int unaff_EDI;

  int local_1c;

  int local_18;

  int iStack_14;

  int aiStack_10 [3];

  int local_4;

  

  if ((*(int *)(unaff_EDI + 0x10) != 0) && (*(int *)(unaff_EDI + 0x30) == 1)) {

    local_1c = *(int *)(unaff_EDI + 0x34);

    iVar2 = *(int *)(unaff_EDI + 0x48);

    iVar1 = *(int *)(unaff_EDI + 0x1c);

    local_18 = 0;

    local_4 = iVar2;

    iStack_14 = (**(code **)(**(int **)(unaff_EDI + 0x10) + 0x30))(*(int **)(unaff_EDI + 0x10));

    local_18 = 0;

    if (0 < iVar2) {

      aiStack_10[0] = 1;

      aiStack_10[1] = 1;

      do {

        iVar2 = local_18;

        if (iStack_14 <= local_18) {

          iVar2 = FUN_0044b1f0();

          local_1c = local_1c + iVar2 * unaff_EBX;

          iVar2 = local_18;

        }

        local_18 = iVar1 / 2;

        piVar3 = aiStack_10;

        if (0 < iVar1 / 2) {

          piVar3 = &local_18;

        }

        iVar1 = *piVar3;

        if ((*(byte *)(unaff_EDI + 0x2c) & 4) != 0) {

          unaff_EBX = unaff_EBX / 2;

        }

        local_18 = iVar2 + 1;

      } while (local_18 < aiStack_10[2]);

    }

    return local_1c;

  }

  return 0;

}
