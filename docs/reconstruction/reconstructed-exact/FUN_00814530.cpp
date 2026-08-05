// =============================================================================
// FUN_00814530
// -----------------------------------------------------------------------------
// Stable ID: aa_00814530
// Address:   0x00814530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00814530 @ 0x00814530
// Stable ID: aa_00814530
// Embedded strings (evidence for future rename):
//   - "Got a local obj ghost and no obj? coid:%I64d cbid:%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: FUN_004c0140, FUN_004e23d0, FUN_007971b0, FUN_007a4480, FUN_00812360, FUN_00814530.
//  - Strings: "Got a local obj ghost and no obj? coid:%I64d cbid:%d".
//  - Return sites: 4.

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

int * FUN_00814530(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar6;

  

  piVar5 = param_2;

  if (param_2 == (int *)0x0) {

    uVar4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x90);

    uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x94);

    iVar3 = FUN_004e23d0(uVar4,uVar6,&param_2);

    if (iVar3 != 0) {

      piVar5 = *(int **)(iVar3 + 0xc);

    }

    if (piVar5 == (int *)0x0) {

      FUN_007a4480(0,"Got a local obj ghost and no obj? coid:%I64d cbid:%d",uVar4,uVar6,

                   *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4));

      return (int *)0x0;

    }

    if (*(char *)(unaff_ESI + 0x8a) == '\0') {

      FUN_00812360(param_1);

      return piVar5;

    }

  }

  else if (*(char *)(unaff_ESI + 0x8a) == '\0') {

    iVar3 = (**(code **)(*param_2 + 0x1d0))();

    if (iVar3 == 0) {

      return (int *)0x0;

    }

    if (*(int *)(iVar3 + 0x48) == 0) {

      iVar1 = *(int *)(*(int *)(iVar3 + 4) + 4);

      iVar2 = *(int *)(*(int *)(iVar1 + 0xac + iVar3) + 0x3c);

      iVar1 = iVar1 + iVar3;

      if (((*(float *)(iVar2 + 0x3e4) <= 0.0) || ((*(byte *)(iVar2 + 0x3f2) >> 1 & 1) != 0)) ||

         ((*(float *)(unaff_ESI + 100) == 0.0 &&

          ((*(float *)(unaff_ESI + 0x68) == 0.0 && (*(float *)(unaff_ESI + 0x6c) == 0.0)))))) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 100) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x84);

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x68) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x88);

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x6c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x8c);

        FUN_007971b0(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x94 + iVar3);

      }

      uVar6 = 0;

      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 300))(0);

      FUN_004c0140(iVar3 + 0x40,unaff_ESI,2,0,1,1,uVar4,uVar6);

    }

  }

  return piVar5;

}
