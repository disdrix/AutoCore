// =============================================================================
// FUN_009294d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009294d0
// Address:   0x009294d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009294d0 @ 0x009294d0
// Stable ID: aa_009294d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×13, do×5, while×5, return×2, for×1.
//  - Notable callees: FUN_00928d60×4, FUN_00928e20×2, FUN_009294d0, free, malloc.
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

uint32_t /* width from decompiler */ * FUN_009294d0(int param_1,uint param_2,uint param_3,int param_4,uint param_5)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *_Memory;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  uint uVar8;

  uint uVar9;

  

  uVar8 = param_5;

  if (param_4 == 0) {

    param_5 = *(int *)(param_1 + 0x18);

  }

  else {

    param_5 = *(int *)(param_1 + 0x14);

  }

  uVar2 = FUN_00928e20();

  uVar3 = FUN_00928e20();

  iVar5 = (((param_2 - 1) + uVar8) / uVar8) * (((param_3 - 1) + uVar8) / uVar8);

  _Memory = malloc(iVar5 * 4 + 0x50);

  puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  if (_Memory != (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = _Memory;

    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    puVar4 = _Memory + 0x14;

    _Memory[0x12] = puVar4;

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    _Memory[10] = iVar5;

    _Memory[9] = param_5 * param_2 + 0xf & 0xfffffff0;

    _Memory[6] = param_3;

    _Memory[0xd] = uVar2;

    *_Memory = uVar1;

    _Memory[4] = param_5;

    _Memory[0xe] = uVar3;

    _Memory[5] = param_2;

    _Memory[0xb] = param_2 / uVar8;

    _Memory[0xf] = param_2 % uVar8;

    _Memory[3] = param_4;

    _Memory[0xc] = param_3 / uVar8;

    _Memory[0x10] = param_3 % uVar8;

    _Memory[0x11] = uVar8;

    if (param_4 == 0) {

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    }

    else {

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

    }

    _Memory[2] = uVar2;

    if (param_4 == 0) {

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

    }

    else {

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

    }

    uVar9 = 0;

    _Memory[1] = uVar2;

    if (param_3 / uVar8 != 0) {

      do {

        uVar8 = 0;

        if (_Memory[0xb] != 0) {

          do {

            uVar2 = FUN_00928d60(_Memory[1],_Memory[4]);

            *puVar4 = uVar2;

            uVar8 = uVar8 + 1;

            puVar4 = puVar4 + 1;

          } while (uVar8 < (uint)_Memory[0xb]);

        }

        if (_Memory[0xd] != 0) {

          uVar2 = FUN_00928d60(_Memory[1],_Memory[4]);

          *puVar4 = uVar2;

          puVar4 = puVar4 + 1;

        }

        uVar9 = uVar9 + 1;

      } while (uVar9 < (uint)_Memory[0xc]);

    }

    if (_Memory[0xe] != 0) {

      uVar8 = 0;

      if (_Memory[0xb] != 0) {

        do {

          uVar2 = FUN_00928d60(_Memory[1],_Memory[4]);

          *puVar4 = uVar2;

          uVar8 = uVar8 + 1;

          puVar4 = puVar4 + 1;

        } while (uVar8 < (uint)_Memory[0xb]);

      }

      if (_Memory[0xd] != 0) {

        uVar2 = FUN_00928d60(_Memory[1],_Memory[4]);

        *puVar4 = uVar2;

      }

    }

    uVar8 = 0;

    if (_Memory[10] != 0) {

      piVar7 = (int *)_Memory[0x12];

      do {

        if (*piVar7 == 0) {

          uVar8 = 0;

          do {

            if (*(int *)(_Memory[0x12] + uVar8 * 4) != 0) {

              piVar7 = *(int **)(_Memory[0x12] + uVar8 * 4);

              (**(code **)(*piVar7 + 8))(piVar7);

              *(uint32_t /* width from decompiler */ *)(_Memory[0x12] + uVar8 * 4) = 0;

            }

            uVar8 = uVar8 + 1;

          } while (uVar8 < (uint)_Memory[10]);

          free(_Memory);

          return (uint32_t /* width from decompiler */ *)0x0;

        }

        uVar8 = uVar8 + 1;

        piVar7 = piVar7 + 1;

      } while (uVar8 < (uint)_Memory[10]);

    }

    _Memory[8] = 0;

    puVar4 = _Memory;

  }

  return puVar4;

}
