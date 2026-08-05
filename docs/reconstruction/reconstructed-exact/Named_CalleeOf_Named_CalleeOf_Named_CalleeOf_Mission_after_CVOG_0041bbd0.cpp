// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_after_CVOG_0041bbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041bbd0
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions
// Address:   0x0041bbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_0040f100×7, FUN_0040ed60, FUN_0041bbd0, FUN_005a2850, FUN_00673070.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_after_CVOG_0041bbd0(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  int *unaff_EDI;

  uint8_t local_8 [8];

  

  piVar1 = *(int **)(unaff_EBX + 4);

  if (*(int *)(unaff_EBX + 8) == 0) {

    FUN_0040f100(unaff_ESI,1,piVar1,unaff_EDI);

    return;

  }

  if (param_1 == (int *)*piVar1) {

    if (*unaff_EDI < param_1[3]) {

      FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);

      return;

    }

  }

  else if (param_1 == piVar1) {

    if (*(int *)(piVar1[2] + 0xc) < *unaff_EDI) {

      FUN_0040f100(unaff_ESI,0,piVar1[2],unaff_EDI);

      return;

    }

  }

  else {

    if (*unaff_EDI < param_1[3]) {

      FUN_005a2850();

      if (param_1[3] < *unaff_EDI) {

        if (*(char *)(param_1[2] + 0x15) != '\0') {

          FUN_0040f100(unaff_ESI,0,param_1,unaff_EDI);

          return;

        }

        FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);

        return;

      }

    }

    if (param_1[3] < *unaff_EDI) {

      FUN_00673070();

      if ((param_1 == *(int **)(unaff_EBX + 4)) || (*unaff_EDI < param_1[3])) {

        if (*(char *)(param_1[2] + 0x15) != '\0') {

          FUN_0040f100(unaff_ESI,0,param_1,unaff_EDI);

          return;

        }

        FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);

        return;

      }

    }

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_0040ed60(local_8,unaff_EDI);

  *unaff_ESI = *puVar2;

  return;

}
