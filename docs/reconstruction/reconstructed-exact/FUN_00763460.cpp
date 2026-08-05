// =============================================================================
// FUN_00763460
// -----------------------------------------------------------------------------
// Stable ID: aa_00763460
// Address:   0x00763460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00763460 @ 0x00763460
// Stable ID: aa_00763460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, while×2, goto×2, return×2, for×1.
//  - Notable callees: block×3, FUN_0044cb20×2, FUN_0043a420, FUN_00763460.
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

/* WARNING: Removing unreachable block (ram,0x00763594) */

/* WARNING: Removing unreachable block (ram,0x00763536) */

/* WARNING: Removing unreachable block (ram,0x0076355e) */



uint32_t /* width from decompiler */ __thiscall FUN_00763460(int *param_1,uint param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  uint uVar4;

  int unaff_EBX;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009acd45;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  iVar1 = (**(code **)(*param_1 + 4))();

  if (iVar1 == 0x47504345) {

    piVar3 = *(int **)(unaff_EBX + 8);

    piVar2 = *(int **)(unaff_EBX + 4);

    if (piVar2 != piVar3) {

      do {

        if (*piVar2 == param_1[0x16]) break;

        piVar2 = piVar2 + 1;

      } while (piVar2 != piVar3);

      if (piVar2 != piVar3) goto LAB_00763532;

    }

    FUN_0044cb20();

  }

  else {

    iVar1 = (**(code **)(*param_1 + 4))();

    if (iVar1 == 0x47534b4e) {

      for (uVar4 = 0;

          (iVar1 = param_1[0x38], iVar1 != 0 && (uVar4 < (uint)(param_1[0x39] - iVar1 >> 2)));

          uVar4 = uVar4 + 1) {

        piVar3 = *(int **)(unaff_EBX + 4);

        piVar2 = *(int **)(unaff_EBX + 8);

        if (piVar3 == piVar2) {

LAB_0076351b:

          FUN_0044cb20();

        }

        else {

          do {

            if (*piVar3 == *(int *)(iVar1 + uVar4 * 4)) break;

            piVar3 = piVar3 + 1;

          } while (piVar3 != piVar2);

          if (piVar3 == piVar2) goto LAB_0076351b;

        }

      }

    }

  }

LAB_00763532:

  if (*(int *)(unaff_EBX + 4) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = *(int *)(unaff_EBX + 8) - *(int *)(unaff_EBX + 4) >> 2;

  }

  if (param_2 < uVar4) {

    ExceptionList = pvStack_c;

    return 0;

  }

  FUN_0043a420(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),0,0,param_2);

  ExceptionList = pvStack_c;

  return 1;

}
