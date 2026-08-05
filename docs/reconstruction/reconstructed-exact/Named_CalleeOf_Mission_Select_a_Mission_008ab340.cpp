// =============================================================================
// Named_CalleeOf_Mission_Select_a_Mission_008ab340
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab340
// Callee of Mission_Select_a_Mission
// Address:   0x008ab340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Select_a_Mission: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×14, do×2, while×2, return×1.
//  - Notable callees: memmove×2, FUN_008ab340.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Select_a_Mission
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Mission_Select_a_Mission_008ab340(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  char cVar4;

  void *pvVar5;

  int iVar6;

  int iVar7;

  int *unaff_ESI;

  

  if (unaff_ESI[0x1cb] == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = unaff_ESI[0x1cc] - unaff_ESI[0x1cb] >> 2;

  }

  iVar6 = 0;

  if (0 < iVar7) {

    do {

      iVar1 = iVar6 * 4;

      if (*(int *)(unaff_ESI[0x1cb] + iVar1) != 0) {

        cVar4 = (**(code **)(**(int **)(unaff_ESI[0x1cb] + iVar1) + 0x3d8))();

        if (cVar4 != '\0') {

          (**(code **)(**(int **)(unaff_ESI[0x1cb] + iVar1) + 0x440))();

        }

        if (*(int *)(*(int *)(unaff_ESI[0x1cb] + iVar1) + 0x2b0) != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(*(int *)(unaff_ESI[0x1cb] + iVar1));

        }

        if ((*(int *)(unaff_ESI[0x1cb] + iVar1) != 0) &&

           (puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x1cb] + iVar1), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

          (**(code **)*puVar2)(1);

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x1cb] + iVar1) = 0;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar7);

  }

  pvVar5 = (void *)unaff_ESI[0x1cb];

  if (((pvVar5 != (void *)0x0) &&

      (pvVar3 = (void *)unaff_ESI[0x1cc], (int)pvVar3 - (int)pvVar5 >> 2 != 0)) &&

     (pvVar5 != pvVar3)) {

    pvVar5 = memmove(pvVar5,pvVar3,0);

    unaff_ESI[0x1cc] = (int)pvVar5;

  }

  if (unaff_ESI[0x1cf] == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = unaff_ESI[0x1d0] - unaff_ESI[0x1cf] >> 2;

  }

  iVar6 = 0;

  if (0 < iVar7) {

    do {

      iVar1 = iVar6 * 4;

      if (*(int *)(iVar1 + unaff_ESI[0x1cf]) != 0) {

        cVar4 = (**(code **)(**(int **)(iVar1 + unaff_ESI[0x1cf]) + 0x3d8))();

        if (cVar4 != '\0') {

          (**(code **)(**(int **)(unaff_ESI[0x1cf] + iVar1) + 0x440))();

        }

        if (*(int *)(*(int *)(unaff_ESI[0x1cf] + iVar1) + 0x2b0) != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(*(int *)(unaff_ESI[0x1cf] + iVar1));

        }

        if ((*(int *)(iVar1 + unaff_ESI[0x1cf]) != 0) &&

           (puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + unaff_ESI[0x1cf]), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

          (**(code **)*puVar2)(1);

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x1cf] + iVar1) = 0;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar7);

  }

  pvVar5 = (void *)unaff_ESI[0x1cf];

  if (((pvVar5 != (void *)0x0) &&

      (pvVar3 = (void *)unaff_ESI[0x1d0], (int)pvVar3 - (int)pvVar5 >> 2 != 0)) &&

     (pvVar5 != pvVar3)) {

    pvVar5 = memmove(pvVar5,pvVar3,0);

    unaff_ESI[0x1d0] = (int)pvVar5;

  }

  return;

}
