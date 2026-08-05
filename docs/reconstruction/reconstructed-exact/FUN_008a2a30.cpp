// =============================================================================
// FUN_008a2a30
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2a30
// Address:   0x008a2a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a2a30 @ 0x008a2a30
// Stable ID: aa_008a2a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×14, do×2, while×2, return×1.
//  - Notable callees: memmove×2, FUN_008a2a30.
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

void FUN_008a2a30(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  char cVar4;

  void *pvVar5;

  int iVar6;

  int iVar7;

  int *unaff_ESI;

  

  if (unaff_ESI[0x169] == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = unaff_ESI[0x16a] - unaff_ESI[0x169] >> 2;

  }

  iVar6 = 0;

  if (0 < iVar7) {

    do {

      iVar1 = iVar6 * 4;

      if (*(int *)(unaff_ESI[0x169] + iVar1) != 0) {

        cVar4 = (**(code **)(**(int **)(unaff_ESI[0x169] + iVar1) + 0x3d8))();

        if (cVar4 != '\0') {

          (**(code **)(**(int **)(unaff_ESI[0x169] + iVar1) + 0x440))();

        }

        if (*(int *)(*(int *)(unaff_ESI[0x169] + iVar1) + 0x2b0) != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(*(int *)(unaff_ESI[0x169] + iVar1));

        }

        if ((*(int *)(unaff_ESI[0x169] + iVar1) != 0) &&

           (puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x169] + iVar1), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

          (**(code **)*puVar2)(1);

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x169] + iVar1) = 0;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar7);

  }

  pvVar5 = (void *)unaff_ESI[0x169];

  if (((pvVar5 != (void *)0x0) &&

      (pvVar3 = (void *)unaff_ESI[0x16a], (int)pvVar3 - (int)pvVar5 >> 2 != 0)) &&

     (pvVar5 != pvVar3)) {

    pvVar5 = memmove(pvVar5,pvVar3,0);

    unaff_ESI[0x16a] = (int)pvVar5;

  }

  if (unaff_ESI[0x16d] == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = unaff_ESI[0x16e] - unaff_ESI[0x16d] >> 2;

  }

  iVar6 = 0;

  if (0 < iVar7) {

    do {

      iVar1 = iVar6 * 4;

      if (*(int *)(iVar1 + unaff_ESI[0x16d]) != 0) {

        cVar4 = (**(code **)(**(int **)(iVar1 + unaff_ESI[0x16d]) + 0x3d8))();

        if (cVar4 != '\0') {

          (**(code **)(**(int **)(unaff_ESI[0x16d] + iVar1) + 0x440))();

        }

        if (*(int *)(*(int *)(unaff_ESI[0x16d] + iVar1) + 0x2b0) != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(*(int *)(unaff_ESI[0x16d] + iVar1));

        }

        if ((*(int *)(iVar1 + unaff_ESI[0x16d]) != 0) &&

           (puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + unaff_ESI[0x16d]), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

          (**(code **)*puVar2)(1);

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x16d] + iVar1) = 0;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar7);

  }

  pvVar5 = (void *)unaff_ESI[0x16d];

  if (((pvVar5 != (void *)0x0) &&

      (pvVar3 = (void *)unaff_ESI[0x16e], (int)pvVar3 - (int)pvVar5 >> 2 != 0)) &&

     (pvVar5 != pvVar3)) {

    pvVar5 = memmove(pvVar5,pvVar3,0);

    unaff_ESI[0x16e] = (int)pvVar5;

  }

  return;

}
