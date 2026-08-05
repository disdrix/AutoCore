// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069b040
// -----------------------------------------------------------------------------
// Stable ID: aa_0069b040
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069b040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×13, for×2, do×2, while×2, goto×2, return×1.
//  - Notable callees: FUN_0069ac80, FUN_0069b040.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069b040(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int *local_4;

  

  local_4 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                      1);

  FUN_0069ac80(param_2,local_4,param_3 + -1,param_4);

  piVar5 = local_4 + 1;

  for (; param_2 < local_4; local_4 = local_4 + -1) {

    if ((*(float *)(*local_4 + 0x2c) < *(float *)(local_4[-1] + 0x2c)) ||

       (*(float *)(local_4[-1] + 0x2c) < *(float *)(*local_4 + 0x2c))) break;

  }

  piVar6 = piVar5;

  piVar3 = local_4;

  if (piVar5 < param_3) {

    do {

      piVar6 = piVar5;

      if ((*(float *)(*local_4 + 0x2c) < *(float *)(*piVar5 + 0x2c)) ||

         (*(float *)(*piVar5 + 0x2c) < *(float *)(*local_4 + 0x2c))) break;

      piVar5 = piVar5 + 1;

      piVar6 = piVar5;

    } while (piVar5 < param_3);

  }

joined_r0x0069b0d4:

  do {

    piVar4 = local_4;

    if (param_3 <= piVar5) {

joined_r0x0069b110:

      for (; param_2 < local_4; local_4 = local_4 + -1) {

        piVar4 = piVar4 + -1;

        iVar1 = *piVar4;

        if (*(float *)(iVar1 + 0x2c) <= *(float *)(*piVar3 + 0x2c)) {

          if (*(float *)(iVar1 + 0x2c) < *(float *)(*piVar3 + 0x2c)) break;

          iVar2 = piVar3[-1];

          piVar3 = piVar3 + -1;

          *piVar3 = iVar1;

          *piVar4 = iVar2;

        }

      }

      if (local_4 == param_2) {

        if (piVar5 == param_3) {

          param_1[1] = piVar6;

          *param_1 = piVar3;

          return;

        }

        if (piVar6 != piVar5) {

          iVar1 = *piVar3;

          *piVar3 = *piVar6;

          *piVar6 = iVar1;

        }

        iVar1 = *piVar3;

        *piVar3 = *piVar5;

        *piVar5 = iVar1;

        piVar5 = piVar5 + 1;

        piVar6 = piVar6 + 1;

        piVar3 = piVar3 + 1;

      }

      else {

        local_4 = local_4 + -1;

        if (piVar5 == param_3) {

          piVar3 = piVar3 + -1;

          if (local_4 != piVar3) {

            iVar1 = *local_4;

            *local_4 = *piVar3;

            *piVar3 = iVar1;

          }

          iVar1 = *piVar3;

          *piVar3 = piVar6[-1];

          piVar6[-1] = iVar1;

          piVar6 = piVar6 + -1;

        }

        else {

          iVar1 = *piVar5;

          *piVar5 = *local_4;

          piVar5 = piVar5 + 1;

          *local_4 = iVar1;

        }

      }

      goto joined_r0x0069b0d4;

    }

    iVar1 = *piVar5;

    if (*(float *)(*piVar3 + 0x2c) <= *(float *)(iVar1 + 0x2c)) {

      if (*(float *)(*piVar3 + 0x2c) < *(float *)(iVar1 + 0x2c)) goto joined_r0x0069b110;

      iVar2 = *piVar6;

      *piVar6 = iVar1;

      piVar6 = piVar6 + 1;

      *piVar5 = iVar2;

    }

    piVar5 = piVar5 + 1;

  } while( true );

}
