// =============================================================================
// FUN_006ebad0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ebad0
// Address:   0x006ebad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ebad0 @ 0x006ebad0
// Stable ID: aa_006ebad0
// Embedded strings (evidence for future rename):
//   - "LtBvTree"
//   - "StNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: rdtsc×3, FUN_0063a3f0, FUN_006ebad0.
//  - Strings: "LtBvTree"; "StNarrowPhase".
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

void FUN_006ebad0(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  uint64_t uVar2;

  char *pcVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint8_t auStack_38c [12];

  uint8_t local_380 [32];

  uint8_t local_360 [44];

  uint32_t /* width from decompiler */ *puStack_334;

  int iStack_330;

  uint8_t *puStack_32c;

  uint32_t /* width from decompiler */ uStack_328;

  uint32_t /* width from decompiler */ uStack_324;

  uint8_t auStack_320 [508];

  uint8_t auStack_124 [288];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtBvTree";

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_0063a3f0(param_2[2] + 0x20,param_1[2] + 0x20);

  iVar7 = param_3[2];

  (**(code **)(*(int *)*param_1 + 0x18))(local_360,iVar7,local_380);

  piVar1 = (int *)*param_2;

  puStack_32c = auStack_320;

  uStack_328 = 0;

  uStack_324 = 0x80000080;

  (**(code **)(*piVar1 + 0x30))(auStack_38c,&puStack_32c);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StNarrowPhase";

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  (**(code **)(*(int *)*param_1 + 0x14))();

  piVar1 = (int *)piVar1[3];

  puVar8 = puStack_334 + iStack_330;

  puVar6 = puStack_334;

  if (puStack_334 != puVar8) {

    do {

      pcVar3 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_3[1])

                                 (&stack0xfffffc57,param_3,param_1,param_2,piVar1,*puVar6);

      if (*pcVar3 != '\0') {

        piVar4 = (int *)(**(code **)(*piVar1 + 0x34))(*puVar6,auStack_124);

        puVar8 = (uint32_t /* width from decompiler */ *)*puVar6;

        iVar5 = (**(code **)(*piVar4 + 0x14))();

        (**(code **)(*param_3 + 0x218c + (iVar7 * 0x20 + iVar5) * 4))

                  (param_1,&stack0xfffffc54,param_3,param_4);

      }

      puVar6 = puVar6 + 1;

    } while (puVar6 != puVar8);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (-1 < (int)puStack_32c) {

    (**(code **)(*DAT_00b05060 + 0x14))(puStack_334,(int)puStack_32c << 2,0x12);

  }

  return;

}
