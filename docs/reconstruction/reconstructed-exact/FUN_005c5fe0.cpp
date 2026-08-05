// =============================================================================
// FUN_005c5fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5fe0
// Address:   0x005c5fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5fe0 @ 0x005c5fe0
// Stable ID: aa_005c5fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×12, return×8, goto×1.
//  - Notable callees: FUN_005c5d40×7, FUN_0058d960×2, FUN_005a2850, FUN_005c5f30, FUN_005c5fe0, FUN_00673070.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ * __thiscall FUN_005c5fe0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,float *param_4)



{

  float *pfVar1;

  int *piVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_005c5d40(param_2,1,*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4);

    return param_2;

  }

  piVar2 = *(int **)(param_1 + 4);

  if (param_3 == (int *)*piVar2) {

    if (*param_4 <= (float)param_3[3] && (float)param_3[3] != *param_4) {

      FUN_005c5d40(param_2,1,param_3,param_4);

      return param_2;

    }

  }

  else if (param_3 == piVar2) {

    pfVar1 = (float *)(piVar2[2] + 0xc);

    if (*pfVar1 <= *param_4 && *param_4 != *pfVar1) {

      FUN_005c5d40(param_2,0,piVar2[2],param_4);

      return param_2;

    }

  }

  else {

    if (*param_4 <= (float)param_3[3] && (float)param_3[3] != *param_4) {

      FUN_005a2850();

      cVar3 = FUN_0058d960(param_3 + 3,param_4);

      if (cVar3 != '\0') {

        if (*(char *)(param_3[2] + 0x15) != '\0') {

          FUN_005c5d40(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_005c5d40(param_2,1,param_3,param_4);

        return param_2;

      }

    }

    if ((float)param_3[3] <= *param_4 && *param_4 != (float)param_3[3]) {

      FUN_00673070();

      if (param_3 != *(int **)(param_1 + 4)) {

        cVar3 = FUN_0058d960(param_4,param_3 + 3);

        if (cVar3 == '\0') goto LAB_005c6149;

      }

      if (*(char *)(param_3[2] + 0x15) != '\0') {

        FUN_005c5d40(param_2,0,param_3,param_4);

        return param_2;

      }

      FUN_005c5d40(param_2,1,param_3,param_4);

      return param_2;

    }

  }

LAB_005c6149:

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_005c5f30(local_8,param_4);

  *param_2 = *puVar4;

  return param_2;

}
