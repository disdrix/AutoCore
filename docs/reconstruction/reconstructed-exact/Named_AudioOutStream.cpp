// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×10, while×2, return×2, do×1.
//  - Notable callees: FUN_00679120×2, FUN_00678f80, FUN_00679610, FUN_0076cec0, vog_LogMessage.
//  - Strings: "ERROR: Overan write cursor. play: %d write:%d offset:%d".
//  - Return sites: 2.

// =============================================================================
// Named_AudioOutStream
// -----------------------------------------------------------------------------
// Stable ID: aa_00679610
// Address:   0x00679610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioOutStream"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_AudioOutStream(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  

  if (0 < *(int *)(param_1 + 0x90)) {

    FUN_00678f80(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

  }

  piVar2 = *(int **)(param_1 + 0x10);

  if (piVar2 != (int *)0x0) {

    piVar1 = (int *)(param_1 + 0x74);

    (**(code **)(*piVar2 + 0x10))(piVar2,(uint *)(param_1 + 0x70),piVar1);

    if (*(char *)(param_1 + 0x78) != '\0') {

      uVar3 = *(uint *)(param_1 + 0x70);

      if (*(uint *)(param_1 + 0x18) < uVar3) {

        *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x1c) + *(uint *)(param_1 + 0x18);

      }

      iVar5 = *(int *)(param_1 + 0x18) - *piVar1;

      if (iVar5 < 0) {

        if (*(int *)(param_1 + 0x80) < 1) {

          uVar4 = FUN_0076cec0(&stack0xfffffff0,

                               "ERROR: Overan write cursor. play: %d write:%d offset:%d",uVar3,

                               *piVar1,*(int *)(param_1 + 0x18));

          vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"

                         ,0x1b3,2,uVar4);

          iVar5 = *piVar1;

          *(int *)(param_1 + 0x18) = iVar5;

          iVar6 = *(uint *)(*(int *)(param_1 + 4) + 8) / 5 + iVar5;

          while (iVar5 < iVar6) {

            FUN_00679120(*(uint *)(param_1 + 0x18) % *(uint *)(param_1 + 0x1c));

            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8);

            iVar5 = *(int *)(param_1 + 0x18);

          }

        }

        else {

          (**(code **)(**(int **)(param_1 + 0x10) + 0x48))(*(int **)(param_1 + 0x10));

          *(uint8_t *)(param_1 + 0x78) = 0;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0xffffffff;

        }

      }

      else if (iVar5 < 0x800) {

        if (*(int *)(param_1 + 0x80) < 1) {

          do {

            FUN_00679120(*(uint *)(param_1 + 0x18) % *(uint *)(param_1 + 0x1c));

            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8);

            iVar5 = iVar5 - *(int *)(param_1 + 8);

          } while (-1 < iVar5);

        }

        else {

          (**(code **)(**(int **)(param_1 + 0x10) + 0x48))(*(int **)(param_1 + 0x10));

          *(uint8_t *)(param_1 + 0x78) = 0;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0xffffffff;

        }

      }

      iVar5 = *(int *)(param_1 + 0x80);

      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) % *(uint *)(param_1 + 0x1c);

      if (-1 < iVar5) {

        if (iVar5 == 0) {

          (**(code **)(**(int **)(param_1 + 0x10) + 0x48))(*(int **)(param_1 + 0x10));

          *(uint8_t *)(param_1 + 0x78) = 0;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0xffffffff;

          return 0;

        }

        *(int *)(param_1 + 0x80) = iVar5 + -1;

      }

    }

  }

  return 0;

}
