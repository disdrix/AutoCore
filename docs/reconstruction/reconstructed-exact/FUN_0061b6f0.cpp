// =============================================================================
// FUN_0061b6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b6f0
// Address:   0x0061b6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061b6f0 @ 0x0061b6f0
// Stable ID: aa_0061b6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_00578270×6, FUN_005134e0×2, FUN_005787a0, FUN_00589bc0, FUN_00589c70, FUN_00589d90, FUN_0058c3b0, FUN_0058cc40.
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

void __thiscall FUN_0061b6f0(int *param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int local_18;

  int iStack_14;

  uint8_t auStack_10 [16];

  

  FUN_005787a0(&local_18);

  param_1[0x1b2] = param_1[0x1b2] + 1;

  if (((local_18 != DAT_00af4bd0) && ((char)param_1[8] == '\0')) &&

     ((1 < param_1[3] || (param_1[3] == -1000)))) {

    if ((short)param_1[0x1d] != 0) {

      iVar2 = (**(code **)(*(int *)param_1[6] + 0x214))();

      if (iVar2 != 0) {

        piVar3 = (int *)(**(code **)(*(int *)param_1[6] + 0x214))();

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_0061b960(auStack_10);

        (**(code **)(*piVar3 + 0x88))

                  ((int)((float)(int)(short)param_1[0x1d] * (float)param_1[0x1b1]),*puVar4,puVar4[1]

                   ,puVar4[2],puVar4[3]);

      }

    }

    if ((float)param_1[0x45] != g_flZero) {

      uVar5 = FUN_00578270(param_1[6],(float)param_1[0x1b1] * (float)param_1[0x45]);

      FUN_00589bc0(uVar5);

    }

    if ((char)param_1[0x11] != '\0') {

      iVar2 = (**(code **)(*(int *)param_1[6] + 0x19c))();

      if (iVar2 == 0) {

        cVar1 = FUN_005134e0();

        if (cVar1 == '\0') {

          (**(code **)(*param_1 + 0x18))(1,1);

        }

      }

      else {

        cVar1 = FUN_005134e0();

        if (cVar1 == '\0') {

          (**(code **)(*param_1 + 0x18))(1,1);

        }

      }

    }

    if ((*(byte *)(param_1 + 0x192) & 2) != 0) {

      uVar5 = FUN_00578270(param_1[6],(float)param_1[0x1b1] * (float)param_1[0x18],0);

      FUN_00589c70(uVar5);

    }

    if ((float)param_1[0x51] != g_flZero) {

      uVar5 = FUN_00578270(param_1[6],(float)param_1[0x1b1] * (float)param_1[0x51]);

      FUN_00589d90(uVar5);

    }

    if ((*(byte *)((int)param_1 + 0x649) & 0x80) != 0) {

      uVar5 = FUN_00578270(param_1[6],(float)param_1[0x1b1] * (float)param_1[0x19]);

      FUN_0058cc40(uVar5);

    }

    if ((*(byte *)(param_1 + 0x192) & 1) != 0) {

      uVar5 = FUN_00578270(param_1[6],param_1 + 9,param_1[0x1a2],param_1[0x1a8],param_1[0x1b2]);

      FUN_0058d8e0(uVar5);

    }

    if ((float)param_1[0x44] != g_flZero) {

      iStack_14 = param_1[0x44];

      uVar5 = FUN_00578270(param_1[6],iStack_14,&DAT_00d02ac0);

      FUN_0058c3b0(uVar5);

    }

    (**(code **)(*param_1 + 0x50))();

  }

  *param_2 = local_18;

  return;

}
