// =============================================================================
// FUN_00877790
// -----------------------------------------------------------------------------
// Stable ID: aa_00877790
// Address:   0x00877790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00877790 @ 0x00877790
// Stable ID: aa_00877790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00877790.
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

void FUN_00877790(void)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int unaff_ESI;

  int iStack_20;

  uint32_t /* width from decompiler */ auStack_10 [4];

  

  if ((*(int *)(unaff_ESI + 0x574) != 0) && (*(int **)(unaff_ESI + 0x570) != (int *)0x0)) {

    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x1b8))();

    if (iVar2 != 0) {

      iStack_20 = 1;

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x570) + 0x140))(auStack_10);

      auStack_10[0] = *puVar3;

      iVar2 = puVar3[1];

      (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x204))(&iStack_20);

      if (iStack_20 <= iVar2) {

        (**(code **)(**(int **)(unaff_ESI + 0x574) + 0xd4))(0);

        (**(code **)(**(int **)(unaff_ESI + 0x574) + 0x34c))();

        return;

      }

      piVar4 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x570) + 0x1b8))();

      iVar2 = ((*(int *)(*piVar4 + 0x7c) - iVar2) + -1 + iStack_20) / *(int *)(*piVar4 + 0x7c);

      *(int *)(unaff_ESI + 0x540) = iVar2;

      if (iVar2 < 1) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x540) = 1;

      }

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x574) + 0xd0))();

      if (cVar1 == '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0x574) + 0xfc))(1,0x3f000000);

      }

      (**(code **)(**(int **)(unaff_ESI + 0x574) + 0x460))

                (g_flOne / (float)*(int *)(unaff_ESI + 0x540));

      iVar2 = **(int **)(unaff_ESI + 0x574);

      iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x218))(0);

      (**(code **)(iVar2 + 0x454))((float)iVar5 / (float)*(int *)(unaff_ESI + 0x540));

    }

  }

  return;

}
