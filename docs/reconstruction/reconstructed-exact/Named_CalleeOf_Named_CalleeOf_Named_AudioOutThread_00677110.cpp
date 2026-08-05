// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00677110
// -----------------------------------------------------------------------------
// Stable ID: aa_00677110
// Callee of Named_CalleeOf_Named_AudioOutThread
// Address:   0x00677110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_00676540×7, FUN_005a2850, FUN_00673070, FUN_00676be0, FUN_00677110.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioOutThread
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00677110(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,byte *param_4)



{

  byte bVar1;

  byte bVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00676540(param_2,1,*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4);

    return param_2;

  }

  piVar3 = *(int **)(param_1 + 4);

  if (param_3 == (int *)*piVar3) {

    if (*param_4 < *(byte *)(param_3 + 3)) {

      FUN_00676540(param_2,1,param_3,param_4);

      return param_2;

    }

  }

  else if (param_3 == piVar3) {

    if (*(byte *)(piVar3[2] + 0xc) < *param_4) {

      FUN_00676540(param_2,0,piVar3[2],param_4);

      return param_2;

    }

  }

  else {

    bVar1 = *param_4;

    bVar2 = *(byte *)(param_3 + 3);

    if (bVar1 < bVar2) {

      FUN_005a2850();

      if (*(byte *)(param_3 + 3) < bVar1) {

        if (*(char *)(param_3[2] + 0x15) != '\0') {

          FUN_00676540(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_00676540(param_2,1,param_3,param_4);

        return param_2;

      }

      bVar2 = *(byte *)(param_3 + 3);

    }

    if (bVar2 < bVar1) {

      FUN_00673070();

      if ((param_3 == *(int **)(param_1 + 4)) || (bVar1 < *(byte *)(param_3 + 3))) {

        if (*(char *)(param_3[2] + 0x15) != '\0') {

          FUN_00676540(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_00676540(param_2,1,param_3,param_4);

        return param_2;

      }

    }

  }

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00676be0(local_8,param_4);

  *param_2 = *puVar4;

  return param_2;

}
