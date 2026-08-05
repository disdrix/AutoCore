// =============================================================================
// FUN_004bdb70
// -----------------------------------------------------------------------------
// Stable ID: aa_004bdb70
// Address:   0x004bdb70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bdb70 @ 0x004bdb70
// Stable ID: aa_004bdb70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, do×1, while×1.
//  - Notable callees: FUN_0076c3c0×3, FUN_0074c9c0×2, FUN_004bdb70, FUN_00764dc0, FUN_00765170.
//  - Return sites: 3.

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

bool __thiscall FUN_004bdb70(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint8_t *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  *(uint8_t *)(param_1 + 0x5b0) = 0;

  if ((*(int *)(param_1 + 0x1c) != 0) && (*(char *)(*(int *)(param_1 + 0x5d4) + 0x7d) == '\0')) {

    if (*(int *)(param_1 + 0x5b4) == 0) {

      if (*(void **)(param_1 + 0x340) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 0x340));

      }

      (**(code **)(*(int *)(param_1 + 0x2c8) + 0x58))();

      iVar2 = (**(code **)(*(int *)(param_1 + 0x2c8) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc) = 0xffffffff;

      *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x598);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x94) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    if (*(int *)(param_1 + 0x5b4) < *(int *)(param_1 + 0x1c)) {

      iVar2 = 0;

      do {

        if (iVar2 < *(int *)(param_1 + 0x5b4)) {

          iVar2 = iVar2 + 1;

        }

        else {

          if (*(int *)(param_1 + 0x18) != 0) {

            piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 0xc);

            if (*piVar1 != 0) {

              if ((char)piVar1[2] == '\0') {

                FUN_00765170(*piVar1,0);

              }

              else {

                piVar1 = (int *)*piVar1;

                uVar5 = (**(code **)(*piVar1 + 0xc))();

                uVar6 = (**(code **)(*piVar1 + 0x48))(uVar5);

                FUN_0074c9c0(&DAT_00d1eb60,uVar6,uVar5);

              }

            }

          }

          *(int *)(param_1 + 0x5b4) = *(int *)(param_1 + 0x5b4) + 1;

          iVar2 = *(int *)(param_1 + 0x5b4);

          iVar3 = FUN_0076c3c0();

          if (*param_3 <= iVar3) break;

        }

        if ((*(int *)(param_1 + 0x18) == 0) ||

           (iVar3 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar3 == 0)) break;

        *(int *)(param_1 + 0x18) = iVar3;

      } while( true );

    }

    iVar2 = FUN_0076c3c0();

    if (*param_3 <= iVar2) {

      return true;

    }

    piVar1 = (int *)(param_1 + 0x2c8);

    FUN_00764dc0(0);

    (**(code **)(*piVar1 + 0x50))();

    puVar4 = operator_new(0xc);

    *puVar4 = 10;

    *(int *)(puVar4 + 4) = param_1;

    *(uint8_t **)(param_1 + 0x340) = puVar4;

    uVar5 = (**(code **)(*piVar1 + 0xc))();

    uVar6 = (**(code **)(*piVar1 + 0x48))(uVar5);

    FUN_0074c9c0(&DAT_00d1eb60,uVar6,uVar5);

  }

  *(uint8_t *)(param_1 + 0x5c4) = 1;

  *(uint8_t *)(param_1 + 0x571) = 0;

  *(uint8_t *)(param_1 + 0x574) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b4) = 0;

  iVar2 = FUN_0076c3c0();

  return *param_3 <= iVar2;

}
