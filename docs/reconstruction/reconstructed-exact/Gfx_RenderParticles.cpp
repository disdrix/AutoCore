// =============================================================================
// Gfx_RenderParticles
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f660
// Address:   0x0048f660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_RenderParticles for FUN_0048f660 @ 0x0048f660
// Stable ID: aa_0048f660
// Embedded strings (evidence for future rename):
//   - "Effects"
//   - "Particles"
//   - "update Particles"
//   - "render Particles"
//   - "submit geo particles"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×14, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0076cef0×5, FUN_0076cf00×4, FUN_0079a0b0×2, FUN_007a2980×2, FUN_00404d80, FUN_0040b140, FUN_004148e0, Gfx_RenderParticles.
//  - Strings: "Effects"; "Particles"; "update Particles"; "render Particles".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "render Particles"
 * Domain alias of FUN_0048f660 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Gfx_RenderParticles(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  float10 fVar5;

  float fStack_14034;

  float fStack_14030;

  int *piStack_1402c;

  float fStack_14028;

  float fStack_14024;

  uint8_t auStack_14020 [81940];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0863;

  pvStack_c = ExceptionList;

  fStack_14028 = DAT_00d1f040;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("Effects");

  local_4 = 0;

  if (*(char *)(param_1 + 0x88) != '\0') {

    if ((*(int *)(param_1 + 0xb8) != 0) && (*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) != 0)) {

      fStack_14030 = DAT_00d1f040;

      FUN_0076cf00("Particles");

      _DAT_00b04e10 = 0;

      local_4._0_1_ = 1;

      if (*(int *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x170) != 0) {

        fVar5 = (float10)FUN_0079a0b0(0);

        fStack_14034 = (float)fVar5;

        FUN_0079ed10();

        FUN_0079e840(fStack_14034);

        iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

        piVar4 = *(int **)(iVar1 + 0x9c);

        piVar3 = *(int **)(iVar1 + 0xa0);

        if (*(char *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x2e1) != '\0') {

          FUN_0040b140("update Particles");

          local_4._0_1_ = 2;

          for (; piVar4 != piVar3; piVar4 = piVar4 + 1) {

            iVar1 = *piVar4;

            if (iVar1 == 0) {

              piVar2 = (int *)0x0;

            }

            else {

              piVar2 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

            }

            (**(code **)(*piVar2 + 0xec))(&fStack_14034);

          }

          local_4._0_1_ = 1;

          FUN_0076cef0();

          FUN_004ba290(&fStack_14034);

          FUN_00593b60(fStack_14034);

        }

        if ((*(int *)(param_1 + 0xb8) != 0) && (*(int *)(*(int *)(param_1 + 0xb8) + 0x78) != 0)) {

          FUN_00554070();

        }

        FUN_007a2980(0);

        if (g_flZero < DAT_00af06e0) {

          FUN_00404d80(auStack_14020,0x4004,5,FUN_0066dcf0);

          iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

          piVar4 = *(int **)(iVar1 + 0x9c);

          piStack_1402c = *(int **)(iVar1 + 0xa0);

          if (piVar4 != piStack_1402c) {

            do {

              fStack_14024 = DAT_00d1f040;

              FUN_0076cf00("render Particles");

              iVar1 = *piVar4;

              local_4._0_1_ = 3;

              if (iVar1 == 0) {

                piVar3 = (int *)0x0;

              }

              else {

                piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

              }

              (**(code **)(*piVar3 + 0xf0))(auStack_14020);

              local_4._0_1_ = 1;

              FUN_0076cef0();

              piVar4 = piVar4 + 1;

            } while (piVar4 != piStack_1402c);

          }

          FUN_004b74f0(auStack_14020);

          FUN_004b4910(auStack_14020);

        }

        FUN_007a2980(1);

        FUN_007a1e70();

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x198) + 0x3c))

                  (param_2);

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x170) + 0x3c))

                  (param_2);

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x184) + 0x3c))

                  (param_2);

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x1c0) + 0x3c))

                  (param_2);

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x1ac) + 0x3c))

                  (param_2);

        if (((*(char *)(param_1 + 0x172) != '\0') &&

            (iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe89c), 0 < *(int *)(iVar1 + 0x1cc))) &&

           (*(int *)(iVar1 + 0x1e0) != 0)) {

          FUN_004148e0(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x1e0));

          (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) + 0x1d4) + 0x3c))

                    (param_2);

        }

        iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe89c);

        if (*(char *)(iVar1 + 0x1f8) != '\0') {

          (**(code **)(**(int **)(iVar1 + 0x1f0) + 0x3c))(param_2);

        }

      }

      if (*(int *)(param_1 + 0xcc) != 0) {

        FUN_004c0db0(param_2);

      }

      local_4 = (uint)local_4._1_3_ << 8;

      FUN_0076cef0();

    }

    if (((*(char *)(param_1 + 0x88) != '\0') && (*(int *)(param_1 + 0xb8) != 0)) &&

       (*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) != 0)) {

      fStack_14024 = DAT_00d1f040;

      FUN_0076cf00("submit geo particles");

      iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

      piVar4 = *(int **)(iVar1 + 0x9c);

      piVar3 = *(int **)(iVar1 + 0xa0);

      local_4._0_1_ = 4;

      for (; piVar4 != piVar3; piVar4 = piVar4 + 1) {

        iVar1 = *piVar4;

        if (iVar1 == 0) {

          piVar2 = (int *)0x0;

        }

        else {

          piVar2 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

        }

        (**(code **)(*piVar2 + 0xf4))(param_1);

      }

      FUN_004b7520(param_1);

      fVar5 = (float10)FUN_0079a0b0(0);

      fStack_14030 = (float)fVar5;

      FUN_0058ee40(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc0),fStack_14030);

      local_4 = (uint)local_4._1_3_ << 8;

      FUN_0076cef0();

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return;

}
