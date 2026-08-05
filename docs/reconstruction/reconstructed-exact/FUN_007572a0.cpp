// =============================================================================
// FUN_007572a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007572a0
// Address:   0x007572a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007572a0 @ 0x007572a0
// Stable ID: aa_007572a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×17, while×3, do×2, return×1.
//  - Notable callees: FUN_00441a20×3, FUN_0074f360×2, FUN_0043f410, FUN_0043f4b0, FUN_00441a80, FUN_00441ad0, FUN_00734550, FUN_0074f200.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_007572a0(int *param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  byte bVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puStack_20;

  uint32_t /* width from decompiler */ *puStack_1c;

  int iStack_18;

  int iStack_14;

  int local_8;

  int local_4;

  

  if ((char)param_1[0x23] != '\0') {

    local_8 = param_1[0x1e] + *param_2;

    local_4 = param_1[0x1f] + param_2[1];

    if ((_DAT_00d20ba8 & 1) == 0) {

      _DAT_00d20ba8 = _DAT_00d20ba8 | 1;

      FUN_0076c500(4);

    }

    bVar5 = FUN_0076c3c0();

    param_2._0_1_ = bVar5 & 1;

    if (param_1[6] != 0) {

      (**(code **)(*param_1 + 0x1c))();

      FUN_00756b40();

      if (param_1[0xd] != 0) {

        FUN_0043f4b0();

      }

      if (*(int *)(param_1[0xd] + 0x34) == 0) {

        FUN_00967150(param_1[0xd] + 0x24);

      }

      FUN_00734550();

      piVar2 = *(int **)param_1[5];

      iStack_18 = 0;

      iStack_14 = 0;

      if (piVar2 != (int *)param_1[5]) {

        do {

          if (piVar2[6] != 0) {

            if ((bVar5 & 1) == 0) {

              puStack_1c = (uint32_t /* width from decompiler */ *)piVar2[5];

              puStack_20 = (uint32_t /* width from decompiler */ *)*puStack_1c;

              FUN_00441a20();

            }

            else {

              puStack_20 = (uint32_t /* width from decompiler */ *)piVar2[5];

              FUN_00441a20();

              puStack_1c = (uint32_t /* width from decompiler */ *)*puStack_20;

            }

            while( true ) {

              if (0 < (int)puStack_20[8]) {

                if (DAT_00d1f614 != 0) {

                  piVar1 = (int *)(DAT_00d1f614 + 0xd8 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

                  *piVar1 = *piVar1 + 1;

                }

                iVar3 = puStack_20[9];

                iVar4 = *(int *)(iVar3 + 8);

                if (iVar4 == iStack_18) {

                  if ((iVar3 != iStack_14) &&

                     (FUN_0074f200(*(uint32_t /* width from decompiler */ *)(iVar3 + 0xc)), iStack_14 = iVar3,

                     DAT_00d1f614 != 0)) {

                    piVar1 = (int *)(DAT_00d1f614 + 0xd4 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

                    *piVar1 = *piVar1 + 1;

                  }

                }

                else {

                  if (iStack_18 != 0) {

                    FUN_0074f360();

                  }

                  FUN_0074fba0(*(uint32_t /* width from decompiler */ *)(puStack_20[9] + 0x14));

                  FUN_0074fca0(2);

                  FUN_0043f410();

                  iStack_18 = iVar4;

                }

                FUN_0075e8e0(4,puStack_20[7],puStack_20[8]);

              }

              if (puStack_20 == puStack_1c) break;

              if ((byte)param_2 == 0) {

                FUN_00441a80();

              }

              else {

                FUN_00441a20();

              }

            }

          }

          FUN_00441ad0();

        } while (piVar2 != (int *)param_1[5]);

        if (iStack_18 != 0) {

          FUN_0074f360();

        }

      }

    }

    puVar6 = (uint32_t /* width from decompiler */ *)param_1[0x25];

    if (puVar6 != (uint32_t /* width from decompiler */ *)param_1[0x26]) {

      do {

        (**(code **)(*(int *)*puVar6 + 0x18))(&local_8);

        puVar6 = puVar6 + 1;

      } while (puVar6 != (uint32_t /* width from decompiler */ *)param_1[0x26]);

    }

  }

  return 0;

}
