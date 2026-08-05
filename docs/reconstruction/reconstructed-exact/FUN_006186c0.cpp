// =============================================================================
// FUN_006186c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006186c0
// Address:   0x006186c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006186c0 @ 0x006186c0
// Stable ID: aa_006186c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×18, return×1.
//  - Notable callees: FUN_004c4e20, FUN_004c6710, FUN_00512150, FUN_00578ce0, FUN_00589e60, FUN_0058a280, FUN_0058a310, FUN_0058a390.
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

void __fastcall FUN_006186c0(int param_1)



{

  char *pcVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if (*(int *)(param_1 + 0x18) != 0) {

    if (*(char *)(param_1 + 0x44) != '\0') {

      pcVar1 = (char *)(*(int *)(param_1 + 0x18) + 0x25);

      *pcVar1 = *pcVar1 + -1;

      iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x19c))();

      if (iVar3 == 0) {

        (**(code **)(**(int **)(param_1 + 0x18) + 0x1b8))(0);

        uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x620);

      }

      else {

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1b8))();

        uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x620);

      }

      FUN_00512150(6,0,uVar5,0);

    }

    if (*(float *)(param_1 + 0x10c) != g_flZero) {

      iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

      if (iVar3 != 0) {

        fVar2 = *(float *)(param_1 + 0x10c);

        iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

        *(float *)(iVar3 + 0x118) = *(float *)(iVar3 + 0x118) - fVar2;

      }

    }

    if ((*(byte *)(param_1 + 0x648) & 4) != 0) {

      FUN_0058a280(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x644),0);

    }

    if ((*(byte *)(param_1 + 0x648) & 8) != 0) {

      FUN_0058a310(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668,0x3f800000);

    }

    if ((*(byte *)(param_1 + 0x648) & 0x40) != 0) {

      FUN_0058a5d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668,0x3f800000);

    }

    if ((*(byte *)(param_1 + 0x649) & 4) != 0) {

      FUN_00589e60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

    }

    if ((*(uint *)(param_1 + 0x648) & 0x20000) != 0) {

      FUN_0058a760(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

      if ((*(uint *)(param_1 + 0x648) & 0x20000) != 0) {

        FUN_0058a7c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                     *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

      }

    }

    if (*(float *)(param_1 + 0x118) != g_flZero) {

      iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

      if (iVar3 != 0) {

        iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

        if (iVar3 != 0) {

          fVar2 = *(float *)(param_1 + 0x118);

          fVar4 = (float10)FUN_004c4e20();

          FUN_004c6710((float)((float10)fVar2 * (float10)*(float *)(param_1 + 0x6c4) *

                               (float10)DAT_00aaa668 + fVar4));

        }

      }

    }

    if ((*(byte *)(param_1 + 0x648) & 0x80) != 0) {

      FUN_0058a390(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

    }

    if ((*(byte *)(param_1 + 0x649) & 1) != 0) {

      FUN_0058a540(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

    }

    if ((*(byte *)(param_1 + 0x649) & 2) != 0) {

      FUN_0058a4b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

    }

    if ((*(byte *)(param_1 + 0x64a) & 1) != 0) {

      FUN_0058a6c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                   *(float *)(param_1 + 0x6c4) * DAT_00aaa668);

    }

  }

  FUN_00578ce0();

  return;

}
