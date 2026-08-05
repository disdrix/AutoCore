// =============================================================================
// FUN_008090d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008090d0
// Address:   0x008090d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008090d0 @ 0x008090d0
// Stable ID: aa_008090d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_005acc30, FUN_005acc90, FUN_008090d0.
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

void FUN_008090d0(void)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int unaff_EDI;

  

  iVar2 = (**(code **)(**(int **)(DAT_00d1b644 + 0xe8a0) + 0x210))(0);

  pvVar3 = CNDHash_LookupByKey(*(void **)(iVar2 + 0x548),*(uint *)(unaff_EDI + 4));

  if ((pvVar3 != (void *)0x0) &&

     (piVar7 = *(int **)((int)pvVar3 + 0x158), piVar7 != *(int **)((int)pvVar3 + 0x15c))) {

    do {

      piVar1 = (int *)*piVar7;

      iVar4 = (**(code **)(*piVar1 + 0x50))();

      if (iVar4 == 0xe) {

        piVar1[0x29] = (int)(*(float *)(unaff_EDI + 0x10) - (float)piVar1[0x29]);

        piVar1[0x28] = *(int *)(unaff_EDI + 0x10);

        piVar1[0x25] = *(int *)(unaff_EDI + 0xc);

        piVar1[0x26] = *(int *)(unaff_EDI + 8);

        *(uint8_t *)(piVar1 + 0x27) = 1;

        *(uint8_t *)((int)piVar1 + 0xa9) = 1;

        iVar4 = *(int *)(unaff_EDI + 8);

        if (0 < iVar4) {

          uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))

                            (iVar4);

          FUN_005acc90(uVar5,iVar4);

          uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

          uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))

                            (uVar5);

          iVar4 = FUN_005acc30(uVar6,uVar5);

          if (0 < iVar4) {

            *(uint8_t *)(piVar1 + 0x2a) = 1;

          }

        }

        *(uint8_t *)(DAT_00d1ad10 + 4) = 1;

      }

      piVar7 = piVar7 + 1;

    } while (piVar7 != *(int **)((int)pvVar3 + 0x15c));

  }

  return;

}
