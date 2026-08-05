// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00770ea0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00770ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, for×1, return×1.
//  - Notable callees: FUN_00770490, FUN_00770ea0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770ea0(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int *in_EAX;

  int iVar3;

  int *piVar4;

  uint uVar5;

  int *piVar6;

  uint uVar7;

  int iVar8;

  uint *puVar9;

  int local_c;

  int local_8;

  

  iVar8 = *param_2;

  iVar1 = *param_1;

  if ((iVar8 <= in_EAX[1]) || (iVar3 = FUN_00770490(), iVar3 == 0)) {

    iVar3 = *in_EAX;

    *in_EAX = iVar8;

    piVar6 = (int *)param_2[3];

    uVar7 = 0;

    piVar4 = (int *)param_1[3];

    puVar9 = (uint *)in_EAX[3];

    local_8 = 0;

    local_c = iVar1;

    if (0 < iVar1) {

      do {

        iVar2 = *piVar4;

        piVar4 = piVar4 + 1;

        uVar7 = (*piVar6 - iVar2) - uVar7;

        *puVar9 = uVar7;

        *puVar9 = uVar7 & 0xfffffff;

        piVar6 = piVar6 + 1;

        uVar7 = uVar7 >> 0x1f;

        puVar9 = puVar9 + 1;

        local_c = local_c + -1;

        local_8 = iVar1;

      } while (local_c != 0);

    }

    if (local_8 < iVar8) {

      iVar8 = iVar8 - local_8;

      do {

        uVar5 = *piVar6 - uVar7;

        *puVar9 = uVar5;

        uVar7 = uVar5 >> 0x1f;

        *puVar9 = uVar5 & 0xfffffff;

        piVar6 = piVar6 + 1;

        puVar9 = puVar9 + 1;

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

    }

    if (*in_EAX < iVar3) {

      for (iVar3 = iVar3 - *in_EAX; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar9 = 0;

        puVar9 = puVar9 + 1;

      }

    }

    iVar8 = *in_EAX;

    if (0 < iVar8) {

      do {

        if (*(int *)(in_EAX[3] + -4 + *in_EAX * 4) != 0) break;

        iVar8 = *in_EAX + -1;

        *in_EAX = iVar8;

      } while (0 < iVar8);

      iVar8 = *in_EAX;

    }

    if (iVar8 == 0) {

      in_EAX[2] = 0;

    }

    iVar3 = 0;

  }

  return iVar3;

}
