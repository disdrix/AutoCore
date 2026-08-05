// =============================================================================
// FUN_00560c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00560c90
// Address:   0x00560c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00560c90 @ 0x00560c90
// Stable ID: aa_00560c90
// Embedded strings (evidence for future rename):
//   - "LthkWorld::getPenetrations"
//   - "Stnarrowphase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: rdtsc×3, FUN_00560c90.
//  - Strings: "LthkWorld::getPenetrations"; "Stnarrowphase".
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

void __thiscall FUN_00560c90(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  uint64_t uVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  int unaff_EBX;

  int *piVar5;

  int *piVar6;

  int iVar7;

  uint8_t auStack_44c [8];

  int local_444;

  uint8_t local_440 [12];

  int iStack_434;

  int iStack_430;

  uint8_t *puStack_42c;

  uint32_t /* width from decompiler */ uStack_428;

  uint32_t /* width from decompiler */ uStack_424;

  uint8_t auStack_420 [1052];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LthkWorld::getPenetrations";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (param_4 == (int *)0x0) {

    param_4 = *(int **)(param_1 + 0xcc);

  }

  local_444 = param_1;

  (**(code **)(*(int *)*param_2 + 0x18))(param_2[2] + 0x20,param_4[2],local_440);

  puStack_42c = auStack_420;

  uStack_428 = 0;

  uStack_424 = 0x80000080;

  (**(code **)(**(int **)(param_1 + 0xc4) + 0x24))(auStack_44c,&puStack_42c);

  iVar7 = iStack_434;

  iVar2 = (**(code **)(*(int *)*param_2 + 0x14))();

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "Stnarrowphase";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (-1 < iStack_430 + -1) {

    piVar5 = (int *)(iVar7 + 4);

    iVar7 = iStack_430;

    do {

      if (*piVar5 == 0) {

        piVar6 = (int *)0x0;

      }

      else {

        piVar6 = (int *)(*piVar5 + -0x10);

      }

      if (((param_2 != piVar6) &&

          (pcVar3 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(unaff_EBX + 0xd0) + 8))

                                      (&stack0xfffffba3,param_2,piVar6), *pcVar3 != '\0')) &&

         ((int *)*piVar6 != (int *)0x0)) {

        iVar4 = (**(code **)(*(int *)*piVar6 + 0x14))();

        (**(code **)(*param_4 + 0x118c + (iVar2 * 0x20 + iVar4) * 4))

                  (param_2,piVar6,param_4,param_3);

      }

      piVar5 = piVar5 + 2;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (-1 < (int)puStack_42c) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_434,(int)puStack_42c * 8,0x12);

  }

  return;

}
