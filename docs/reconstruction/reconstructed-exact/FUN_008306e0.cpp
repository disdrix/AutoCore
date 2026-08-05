// =============================================================================
// FUN_008306e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008306e0
// Address:   0x008306e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008306e0 @ 0x008306e0
// Stable ID: aa_008306e0
// Embedded strings (evidence for future rename):
//   - "Instant Repair - "
//   - "(In Town)"
//   - "(In Arena)"
//   - "(HP Already Full)"
//   - "sec left"
//   - "(%d%s %d%s)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×8, goto×5, return×1.
//  - Notable callees: FUN_007a6de0×7, sprintf×2, CONCAT44, FUN_0040ad20, FUN_0051f710, FUN_00791f30, FUN_007a69d0, FUN_008306e0.
//  - Strings: "Instant Repair - "; "(In Town)"; "(In Arena)"; "(HP Already Full)".
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

/* WARNING: Removing unreachable block (ram,0x00830928) */



void __thiscall FUN_008306e0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  char cVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  char *pcVar9;

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (((cVar2 == '\0') || (FUN_007a69d0(), param_1[0x151] == 0)) || (DAT_00d1b6d8 == 0))

  goto LAB_0083093f;

  uVar3 = FUN_0051f710();

  (**(code **)(*(int *)param_1[0x151] + 0x34c))();

  (**(code **)(*(int *)param_1[0x151] + 0x268))();

  iVar7 = *(int *)param_1[0x151];

  uVar4 = FUN_007a6de0("Instant Repair - ",0xffffffff);

  (**(code **)(iVar7 + 0x250))(uVar4);

  if (*(char *)(DAT_00d1b644 + 0xf5) == '\x01') {

    iVar7 = *(int *)param_1[0x151];

    uVar4 = FUN_007a6de0("(In Town)",0xffffffff);

    (**(code **)(iVar7 + 0x250))(uVar4);

    uVar4 = 0;

LAB_0083092e:

    (**(code **)(*(int *)param_1[0x151] + 0xd4))(uVar4);

    goto LAB_0083093f;

  }

  if (*(char *)(DAT_00d1b644 + 0xf6) == '\x01') {

    iVar7 = *(int *)param_1[0x151];

    pcVar9 = "(In Arena)";

LAB_008308bc:

    uVar4 = FUN_007a6de0(pcVar9,0xffffffff);

    (**(code **)(iVar7 + 0x250))(uVar4);

  }

  else if (uVar3 == 0) {

    piVar1 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);

    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x1ac))();

    iVar6 = (**(code **)(*piVar1 + 0x1b0))();

    if (iVar7 <= iVar6) {

      iVar7 = *(int *)param_1[0x151];

      pcVar9 = "(HP Already Full)";

      goto LAB_008308bc;

    }

    lVar8 = FUN_0040ad20();

    FUN_00977a30(DAT_00d1ad30,lVar8);

    if (lVar8 <= CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                          (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),

                          *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))) {

      uVar4 = 1;

      goto LAB_0083092e;

    }

  }

  else {

    if (uVar3 < 0x2bf21) {

      if (uVar3 < 0xea61) {

        uVar4 = FUN_007a6de0("sec left",0xffffffff);

        uVar3 = uVar3 / 1000;

        goto LAB_00830856;

      }

      uVar4 = FUN_007a6de0("sec left",0xffffffff);

      iVar7 = uVar3 / 1000 + (uVar3 / 60000) * -0x3c;

      uVar5 = FUN_007a6de0(&DAT_00a71bc8,0xffffffff);

      sprintf(&stack0xffffff7c,"(%d%s %d%s)",uVar3 / 60000,uVar5,iVar7,uVar4);

    }

    else {

      uVar4 = FUN_007a6de0("min left",0xffffffff);

      uVar3 = (uVar3 + 59999) / 60000;

LAB_00830856:

      sprintf(&stack0xffffff7c,"(%d%s)",uVar3,uVar4);

    }

    (**(code **)(*(int *)param_1[0x151] + 0x250))(&stack0xffffff7c);

  }

  (**(code **)(*(int *)param_1[0x151] + 0xd4))(0);

LAB_0083093f:

  FUN_00791f30(param_2);

  return;

}
