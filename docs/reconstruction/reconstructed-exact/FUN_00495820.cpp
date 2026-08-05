// =============================================================================
// FUN_00495820
// -----------------------------------------------------------------------------
// Stable ID: aa_00495820
// Address:   0x00495820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00495820 @ 0x00495820
// Stable ID: aa_00495820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×9, for×2, return×2, do×1, while×1.
//  - Notable callees: memmove×3, FUN_0049bfb0×2, FUN_00495820.
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

void __thiscall FUN_00495820(int *param_1,int param_2)



{

  size_t sVar1;

  int iVar2;

  int *piVar3;

  void *pvVar4;

  int *piVar5;

  int *local_4;

  

  iVar2 = param_2;

  for (piVar3 = (int *)param_1[0x27]; local_4 = param_1, piVar3 != (int *)param_1[0x28];

      piVar3 = piVar3 + 1) {

    if (*piVar3 == param_2) {

      memmove(piVar3,piVar3 + 1,(param_1[0x28] - (int)(piVar3 + 1) >> 2) * 4);

      param_1[0x28] = param_1[0x28] + -4;

      break;

    }

  }

  param_2 = *(int *)(iVar2 + 8);

  if (param_2 != 0) {

    piVar5 = (int *)param_1[0x2c];

    for (piVar3 = (int *)param_1[0x2b]; piVar3 != piVar5; piVar3 = piVar3 + 1) {

      if (*piVar3 == param_2) {

        if (piVar3 != piVar5) {

          FUN_0049bfb0(&local_4,piVar3 + 1,piVar5,piVar3,&param_2);

          piVar3 = local_4;

        }

        break;

      }

    }

    if (piVar3 != piVar5) {

      sVar1 = (param_1[0x2c] - (int)piVar5 >> 2) * 4;

      pvVar4 = memmove(piVar3,piVar5,sVar1);

      param_1[0x2c] = (int)((int)pvVar4 + sVar1);

    }

    piVar3 = (int *)param_1[0x30];

    piVar5 = (int *)param_1[0x2f];

    param_2 = *(int *)(iVar2 + 8);

    if (piVar5 != piVar3) {

      do {

        if (*piVar5 == param_2) {

          if (piVar5 == piVar3) {

            return;

          }

          FUN_0049bfb0(&local_4,piVar5 + 1,piVar3,piVar5,&param_2);

          piVar5 = local_4;

          break;

        }

        piVar5 = piVar5 + 1;

      } while (piVar5 != piVar3);

      if (piVar5 != piVar3) {

        sVar1 = (param_1[0x30] - (int)piVar3 >> 2) * 4;

        pvVar4 = memmove(piVar5,piVar3,sVar1);

        param_1[0x30] = (int)((int)pvVar4 + sVar1);

      }

    }

  }

  return;

}
