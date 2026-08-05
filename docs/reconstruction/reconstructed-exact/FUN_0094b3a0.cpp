// =============================================================================
// FUN_0094b3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094b3a0
// Address:   0x0094b3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094b3a0 @ 0x0094b3a0
// Stable ID: aa_0094b3a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: CVOGHBList_Enqueue, FUN_005081d0, FUN_00599550, FUN_00729620, FUN_008078b0, FUN_0094b3a0.
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

uint32_t /* width from decompiler */ FUN_0094b3a0(void)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bbf1c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(int *)(unaff_ESI + 0xcc) != 0) {

    ExceptionList = &pvStack_c;

    FUN_00729620();

  }

  FUN_008078b0(unaff_ESI);

  if (((*(int *)(unaff_ESI + 0xf38) != 0) && (*(int *)(unaff_ESI + 0xe98) != 0)) &&

     (iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar1 != 0)) {

    cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x198))();

    if (cVar3 == '\0') {

      if (*(char *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) + 0x104) != '\0') {

        if ((*(int *)(unaff_ESI + 0xf38) != 0) &&

           (*(int *)(*(int *)(unaff_ESI + 0xf38) + 0xc70) == 0)) {

          pvVar4 = operator_new(0x44);

          uStack_4 = 0;

          if (pvVar4 == (void *)0x0) {

            uVar5 = 0;

          }

          else {

            uVar5 = FUN_00599550(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xe98) + 0x250),

                                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe04));

          }

          uStack_4 = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xf38) + 0xc70) = uVar5;

          CVOGHBList_Enqueue(*(void **)(unaff_ESI + 0xd38),

                             *(CVOGHBBase **)(*(int *)(unaff_ESI + 0xf38) + 0xc70));

          FUN_005081d0();

        }

        *(uint8_t *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) + 0x104) = 0;

      }

    }

    else {

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xf38) + 0xc70) = 0;

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xf38) + 0xc74) = 0;

    }

  }

  if (((*(char *)(unaff_ESI + 0x13) != '\0') &&

      (piVar2 = *(int **)(unaff_ESI + 0xf40), piVar2 != (int *)0x0)) && (*piVar2 != 0)) {

    cVar3 = (**(code **)(*(int *)*piVar2 + 0x3d8))();

    if (cVar3 != '\0') {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x468))();

    }

  }

  ExceptionList = pvStack_c;

  return 0;

}
