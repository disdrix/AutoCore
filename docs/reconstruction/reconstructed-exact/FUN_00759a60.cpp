// =============================================================================
// FUN_00759a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00759a60
// Address:   0x00759a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00759a60 @ 0x00759a60
// Stable ID: aa_00759a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×24, return×4, while×2, do×1.
//  - Notable callees: FUN_00441a20×3, FUN_007599b0×3, FUN_0074f360×2, FUN_00988970×2, FUN_0043f410, FUN_0043f4b0, FUN_00441a80, FUN_00734550.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __thiscall FUN_00759a60(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  byte bVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ *puStack_10;

  int iStack_c;

  int local_8;

  int local_4;

  

  if ((char)param_1[0x23] != '\0') {

    if ((param_1[0x2c] != 0) && (iVar4 = FUN_00988970(param_1[0x2c]), iVar4 < 0)) {

      return iVar4;

    }

    if ((param_1[0x28] != 0) && (iVar4 = FUN_0075b3e0(param_1[0x28]), iVar4 < 0)) {

      return iVar4;

    }

    local_8 = param_1[0x1e] + *param_2;

    local_4 = param_1[0x1f] + param_2[1];

    if ((_DAT_00d21888 & 1) == 0) {

      _DAT_00d21888 = _DAT_00d21888 | 1;

      FUN_0076c500(4);

    }

    bVar3 = FUN_0076c3c0();

    iVar4 = param_1[0x26];

    if (iVar4 != param_1[0x25]) {

      do {

        (**(code **)(**(int **)(iVar4 + -4) + 0x14))(&local_8);

        iVar4 = iVar4 + -4;

      } while (iVar4 != param_1[0x25]);

    }

    if (param_1[3] != 0) {

      (**(code **)(*param_1 + 0x1c))();

      FUN_00756b40();

      if (param_1[0xd] != 0) {

        FUN_0043f4b0();

      }

      if (*(int *)(param_1[0xd] + 0x34) == 0) {

        FUN_00967150(param_1[0xd] + 0x24);

      }

      FUN_00734550();

      if ((bVar3 & 1) == 0) {

        puStack_10 = (uint32_t /* width from decompiler */ *)param_1[2];

        puStack_18 = (uint32_t /* width from decompiler */ *)*puStack_10;

        FUN_00441a20();

      }

      else {

        puStack_18 = (uint32_t /* width from decompiler */ *)param_1[2];

        FUN_00441a20();

        puStack_10 = (uint32_t /* width from decompiler */ *)*puStack_18;

      }

      iStack_14 = 0;

      iStack_c = 0;

      while( true ) {

        if (0 < (int)puStack_18[8]) {

          if (DAT_00d1f614 != 0) {

            piVar1 = (int *)(DAT_00d1f614 + 0xd8 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

            *piVar1 = *piVar1 + 1;

          }

          iVar4 = puStack_18[9];

          iVar2 = *(int *)(iVar4 + 8);

          if (iVar2 == iStack_14) {

            if ((iVar4 != iStack_c) &&

               (FUN_0074f200(*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc)), iStack_c = iVar4, DAT_00d1f614 != 0)) {

              piVar1 = (int *)(DAT_00d1f614 + 0xd4 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

              *piVar1 = *piVar1 + 1;

            }

          }

          else {

            if (iStack_14 != 0) {

              FUN_0074f360();

            }

            FUN_0074fba0(*(uint32_t /* width from decompiler */ *)(puStack_18[9] + 0x14));

            FUN_0074fca0(2);

            FUN_0043f410();

            iStack_14 = iVar2;

          }

          FUN_0075e8e0(4,puStack_18[7],puStack_18[8]);

        }

        if (puStack_18 == puStack_10) break;

        if ((bVar3 & 1) == 0) {

          FUN_00441a80();

        }

        else {

          FUN_00441a20();

        }

      }

      if (iStack_14 != 0) {

        FUN_0074f360();

      }

    }

    if (param_1[0x28] != 0) {

      (**(code **)(*param_1 + 0x1c))();

      *(float *)(param_1[0x28] + 0x100) = (float)(param_1[0x1c] + param_1[0x1b]) * DAT_00d0dfe4;

      (**(code **)(*(int *)param_1[0x28] + 0x14))(&local_8,4);

      if (((param_1[0x2c] == 0) && (param_1[0x2d] == 0)) && (param_1[0x22] != 0)) {

        if (*(int *)(DAT_00d1f05c + 4) != 0) {

          piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

          (**(code **)(*piVar1 + 0x50))(piVar1,DAT_00d0dfdc,&g_flZero,0xffffffff);

        }

        FUN_007599b0(param_1,&local_8,&DAT_00d1ecac);

        if (*(int *)(DAT_00d1f05c + 4) != 0) {

          piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

          (**(code **)(*piVar1 + 0x50))(piVar1,DAT_00d0dfdc,&DAT_00a9f3d0,0xffffffff);

        }

      }

    }

    iVar4 = param_1[0x2d];

    if (((iVar4 != 0) && (*(char *)(iVar4 + 0x14) == '\0')) &&

       (iVar4 = FUN_00988970(iVar4), iVar4 < 0)) {

      return iVar4;

    }

    iVar4 = param_1[0x2c];

    if ((iVar4 != 0) && (*(char *)(iVar4 + 0x15) != '\0')) {

      FUN_007599b0(param_1,&local_8,iVar4 + 0xc);

    }

    iVar4 = param_1[0x2d];

    if ((iVar4 != 0) && (*(char *)(iVar4 + 0x15) != '\0')) {

      FUN_007599b0(param_1,&local_8,iVar4 + 0xc);

    }

  }

  return 0;

}
