// =============================================================================
// FUN_00561b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00561b60
// Address:   0x00561b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00561b60 @ 0x00561b60
// Stable ID: aa_00561b60
// Embedded strings (evidence for future rename):
//   - "LtSimulate"
//   - "TtPostIntegrateCb"
//   - "TtPostSimulateCb"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×15, while×2, do×1, return×1.
//  - Notable callees: rdtsc×6, FUN_0055eb10, FUN_0055ec40, FUN_0055ecb0, FUN_0055f190, FUN_00560110, FUN_00561320, FUN_005618b0.
//  - Strings: "LtSimulate"; "TtPostIntegrateCb"; "TtPostSimulateCb".
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

void __thiscall FUN_00561b60(int param_1,float *param_2)



{

  int iVar1;

  uint64_t uVar2;

  float *pfVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  

  pfVar3 = param_2;

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtSimulate";

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  *(float *)(param_1 + 0x150) = *param_2;

  *(float *)(param_1 + 0x154) = param_2[1];

  *(float *)(param_1 + 0x170) = *(float *)(param_1 + 0x180) * *param_2;

  *(float *)(param_1 + 0x174) = (float)*(int *)(param_1 + 0x17c) * param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x170);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x19c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x174);

  *(float *)(param_1 + 0x1a0) = (float)*(int *)(param_1 + 0x17c) * *(float *)(param_1 + 0x170);

  *(float *)(param_1 + 0x1a4) = *(float *)(param_1 + 0x180) * *(float *)(param_1 + 0x174);

  FUN_0056f570();

  if (0 < *(int *)(param_1 + 0x24)) {

    FUN_00561320();

  }

  if (*(int *)(param_1 + 0x10c) != 0) {

    FUN_0055ecb0();

  }

  iVar6 = *(int *)(param_1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  *(uint8_t *)(param_1 + 300) = 1;

  while (iVar6 = iVar6 + -1, -1 < iVar6) {

    iVar1 = *(int *)(*(int *)(param_1 + 8) + iVar6 * 4);

    if ((*(char *)(param_1 + 0x23d) == '\0') ||

       (pcVar4 = (char *)FUN_00629080(&param_2,pfVar3), *pcVar4 == '\0')) {

      FUN_00628f70(param_1 + 0x140);

      *(uint8_t *)(iVar1 + 0x30) = 0;

    }

    else {

      FUN_0055eb10(iVar1);

    }

    if (*(int *)(param_1 + 0xa0) != 0) {

      if (DAT_00bc5644 < DAT_00bc5648) {

        *DAT_00bc5644 = "TtPostIntegrateCb";

        uVar2 = rdtsc();

        DAT_00bc5644[1] = (int)uVar2;

        DAT_00bc5644 = DAT_00bc5644 + 3;

      }

      FUN_0062a8e0(param_1,iVar1,pfVar3);

      if (DAT_00bc5644 < DAT_00bc5648) {

        *DAT_00bc5644 = &DAT_009d2878;

        uVar2 = rdtsc();

        DAT_00bc5644[1] = (int)uVar2;

        DAT_00bc5644 = DAT_00bc5644 + 3;

      }

    }

  }

  if (*(char *)(param_1 + 0x23c) != '\0') {

    FUN_00560110();

  }

  *(uint8_t *)(param_1 + 300) = 0;

  if (*(int *)(param_1 + 0xf4) != 0) {

    FUN_005618b0();

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    FUN_0055ec40();

  }

  iVar6 = 0;

  if (0 < *(int *)(param_1 + 0x118)) {

    do {

      FUN_0055f190();

      puVar5 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x114) + iVar6 * 4);

      *(short *)((int)puVar5 + 6) = *(short *)((int)puVar5 + 6) + -1;

      if (*(short *)((int)puVar5 + 6) == 0) {

        (**(code **)*puVar5)(1);

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(param_1 + 0x118));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 0;

  puVar5 = DAT_00bc5644;

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar2 = rdtsc();

    param_2 = (float *)uVar2;

    DAT_00bc5644[1] = param_2;

    puVar5 = DAT_00bc5644 + 3;

    if (puVar5 < DAT_00bc5648) {

      *puVar5 = "TtPostSimulateCb";

      uVar2 = rdtsc();

      param_2 = (float *)uVar2;

      DAT_00bc5644[4] = param_2;

      puVar5 = DAT_00bc5644 + 6;

    }

  }

  DAT_00bc5644 = puVar5;

  FUN_0062a840(param_1,pfVar3);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
