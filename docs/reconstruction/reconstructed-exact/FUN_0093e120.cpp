// =============================================================================
// FUN_0093e120
// -----------------------------------------------------------------------------
// Stable ID: aa_0093e120
// Address:   0x0093e120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093e120 @ 0x0093e120
// Stable ID: aa_0093e120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×15, goto×2, return×2.
//  - Notable callees: Client_MaybeShowFirstTimeTip×2, FUN_0040b1b0, FUN_004f3700, FUN_005172d0, FUN_00893580, FUN_008b2470, FUN_008e9690, FUN_0093e120.
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

void FUN_0093e120(int *param_1)



{

  uint *puVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int unaff_ESI;

  

  if ((((param_1 != (int *)0x0) && (iVar4 = (**(code **)(*param_1 + 0x214))(), iVar4 != 0)) &&

      (iVar4 = (**(code **)(*param_1 + 0x214))(),

      *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) + 0x4f9)

      != '\0')) &&

     (((*(int *)(unaff_ESI + 0xf38) != 0 &&

       (piVar2 = *(int **)(*(int *)(unaff_ESI + 0xf38) + 0xcc0), piVar2 != (int *)0x0)) &&

      (((int *)piVar2[0x158] != param_1 &&

       ((cVar3 = (**(code **)(*piVar2 + 0x3d8))(), cVar3 != '\0' &&

        (cVar3 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xf38) + 0xcc0) + 0xd0))(),

        cVar3 != '\0')))))))) {

    (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xf38) + 0xcc0) + 0x444))(param_1);

  }

  iVar4 = *(int *)(unaff_ESI + 0xe98);

  if (iVar4 == 0) goto LAB_0093e30b;

  if (*(char *)(iVar4 + 0x4f1) != '\0') {

    return;

  }

  if (*(char *)(iVar4 + 0xd78) == '\0') {

    if (*(int *)(iVar4 + 0x250) != 0) {

      FUN_004f3700();

    }

LAB_0093e223:

    FUN_005172d0(param_1);

  }

  else if ((*(char *)(iVar4 + 0x6b9) != '\0') &&

          (*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) != 0)) goto LAB_0093e223;

  if ((*(int **)(unaff_ESI + 0x10a4) != (int *)0x0) &&

     (cVar3 = (**(code **)(**(int **)(unaff_ESI + 0x10a4) + 0x3d8))(), cVar3 != '\0')) {

    FUN_008b2470();

  }

  if ((*(int **)(unaff_ESI + 0x10b4) != (int *)0x0) &&

     (cVar3 = (**(code **)(**(int **)(unaff_ESI + 0x10b4) + 0x3d8))(), cVar3 != '\0')) {

    FUN_00893580();

  }

  piVar2 = *(int **)(unaff_ESI + 0x10a0);

  if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x3d8))(), cVar3 != '\0')) {

    FUN_008e9690(piVar2);

  }

  if (((param_1 != (int *)0x0) &&

      (cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) + 4 +

                                    *(int *)(unaff_ESI + 0xe98)) + 0x298))(param_1), cVar3 != '\0'))

     && (iVar4 = (**(code **)(*param_1 + 0x214))(), iVar4 != 0)) {

    (**(code **)(*param_1 + 0x214))();

    cVar3 = FUN_0040b1b0();

    if (cVar3 == '\0') {

      Client_MaybeShowFirstTimeTip(4);

      iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) + 4 +

                                   *(int *)(unaff_ESI + 0xe98)) + 0x27c))();

      iVar5 = (**(code **)(*param_1 + 0x27c))();

      if (iVar4 + 2 <= iVar5) {

        Client_MaybeShowFirstTimeTip(9);

      }

    }

  }

LAB_0093e30b:

  piVar2 = *(int **)(unaff_ESI + 0x3048);

  if (piVar2 != param_1) {

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 0x17c))();

      puVar1 = (uint *)(*(int *)(unaff_ESI + 0x3048) + 0x184);

      *puVar1 = *puVar1 & 0xfffffffd;

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x3048) + 0x118) = 0;

    }

    if (param_1 != (int *)0x0) {

      (**(code **)(*param_1 + 0x178))(g_flOne,g_flOne,g_flOne,g_flOne);

    }

    *(int **)(unaff_ESI + 0x3048) = param_1;

    *(uint8_t *)(unaff_ESI + 0x304c) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3050) = 0;

  }

  return;

}
