// =============================================================================
// FUN_00618270
// -----------------------------------------------------------------------------
// Stable ID: aa_00618270
// Address:   0x00618270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00618270 @ 0x00618270
// Stable ID: aa_00618270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×28, return×1.
//  - Notable callees: FUN_00578270×7, FUN_004c32e0, FUN_004c4e20, FUN_004c6710, FUN_00578b30, FUN_00589bc0, FUN_00589c70, FUN_00589d90.
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

void __fastcall FUN_00618270(int param_1)



{

  char *pcVar1;

  float fVar2;

  int iVar3;

  void *pObject;

  RACE_ID_INFERRED RVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  float10 fVar7;

  

  if ((*(byte *)(param_1 + 0x648) & 4) != 0) {

    FUN_0058a280(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x644),1);

  }

  if ((*(byte *)(param_1 + 0x648) & 8) != 0) {

    FUN_0058a310(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4),

                 0x3f800000);

  }

  if ((*(byte *)(param_1 + 0x648) & 0x80) != 0) {

    FUN_0058a390(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

  }

  if ((*(uint *)(param_1 + 0x648) & 0x100) != 0) {

    FUN_0058a540(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

  }

  if ((*(byte *)(param_1 + 0x649) & 2) != 0) {

    FUN_0058a4b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

  }

  if ((*(byte *)(param_1 + 0x648) & 0x40) != 0) {

    FUN_0058a5d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4),

                 0x3f800000);

  }

  if ((*(byte *)(param_1 + 0x649) & 4) != 0) {

    FUN_00589e60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

  }

  if ((*(byte *)(param_1 + 0x64a) & 1) != 0) {

    FUN_0058a6c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

  }

  if ((*(uint *)(param_1 + 0x648) & 0x20000) != 0) {

    FUN_0058a760(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

    if ((*(uint *)(param_1 + 0x648) & 0x20000) != 0) {

      FUN_0058a7c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4));

    }

  }

  if (*(float *)(param_1 + 0x10c) != g_flZero) {

    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

    if (iVar3 != 0) {

      fVar2 = *(float *)(param_1 + 0x10c);

      iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

      *(float *)(iVar3 + 0x118) = *(float *)(iVar3 + 0x118) + fVar2;

    }

  }

  if (*(char *)(param_1 + 0x44) != '\0') {

    pcVar1 = (char *)(*(int *)(param_1 + 0x18) + 0x25);

    *pcVar1 = *pcVar1 + '\x01';

    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x19c))();

    if (iVar3 == 0) {

      (**(code **)(**(int **)(param_1 + 0x18) + 0x1b8))(1);

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1b8))();

    }

  }

  if (*(char *)(param_1 + 0x45) != '\0') {

    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

    if (iVar3 != 0) {

      piVar5 = *(int **)(param_1 + 0x18);

      pObject = (void *)FUN_00578270();

      RVar4 = Object_GetRootRaceId(pObject);

      (**(code **)(*piVar5 + 0x214))(RVar4);

      FUN_004c32e0(RVar4);

    }

  }

  if (*(float *)(param_1 + 0x118) != g_flZero) {

    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

    if (iVar3 != 0) {

      iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

      if (iVar3 != 0) {

        fVar2 = *(float *)(param_1 + 0x118);

        fVar7 = (float10)FUN_004c4e20();

        FUN_004c6710((float)((float10)fVar2 * (float10)*(float *)(param_1 + 0x6c4) + fVar7));

      }

    }

  }

  if ((*(uint *)(param_1 + 0x638) & 0x100) == 0) {

    if (*(short *)(param_1 + 0x74) != 0) {

      iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

      if (iVar3 != 0) {

        piVar5 = (int *)(**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

        (**(code **)(*piVar5 + 0x88))

                  ((int)((float)(int)*(short *)(param_1 + 0x74) * *(float *)(param_1 + 0x6c4)),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x668),*(uint32_t /* width from decompiler */ *)(param_1 + 0x66c),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x670),*(uint32_t /* width from decompiler */ *)(param_1 + 0x674));

      }

    }

    if (*(float *)(param_1 + 0x114) != g_flZero) {

      uVar6 = FUN_00578270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),

                           *(float *)(param_1 + 0x6c4) * *(float *)(param_1 + 0x114));

      FUN_00589bc0(uVar6);

    }

    if ((*(byte *)(param_1 + 0x648) & 2) != 0) {

      uVar6 = FUN_00578270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),

                           *(float *)(param_1 + 0x6c4) * *(float *)(param_1 + 0x60),0);

      FUN_00589c70(uVar6);

    }

    if (*(float *)(param_1 + 0x144) != g_flZero) {

      uVar6 = FUN_00578270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),

                           *(float *)(param_1 + 0x6c4) * *(float *)(param_1 + 0x144));

      FUN_00589d90(uVar6);

    }

    if ((*(byte *)(param_1 + 0x649) & 0x80) != 0) {

      uVar6 = FUN_00578270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),

                           *(float *)(param_1 + 0x6c4) * *(float *)(param_1 + 100));

      FUN_0058cc40(uVar6);

    }

    if (((*(byte *)(param_1 + 0x648) & 1) != 0) && (*(char *)(param_1 + 0x6c0) == '\0')) {

      uVar6 = FUN_00578270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x688),*(uint32_t /* width from decompiler */ *)(param_1 + 0x6a0),

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c8));

      FUN_0058d8e0(uVar6);

    }

    if (*(float *)(param_1 + 0x110) != g_flZero) {

      uVar6 = FUN_00578270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x110),

                           &DAT_00d02ac0);

      FUN_0058c3b0(uVar6);

    }

  }

  FUN_00578b30();

  return;

}
