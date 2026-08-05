// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006c0640
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0640
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006c0640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×9, do×4, while×4, goto×2, return×1.
//  - Notable callees: FUN_006c0640.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006c0640(char *param_1,int *param_2,int *param_3,int *param_4,float param_5)



{

  int iVar1;

  int iVar2;

  char cVar3;

  float *pfVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_24;

  int local_18;

  

  local_18 = param_4[1];

  cVar3 = '\x01';

  if (0 < local_18) {

    iVar1 = param_2[1];

    local_24 = 0;

    cVar3 = '\x01';

    do {

      iVar6 = 0;

      if (3 < iVar1) {

        iVar7 = 0;

        iVar8 = (iVar1 - 4U >> 2) + 1;

        iVar6 = iVar8 * 4;

        do {

          if (cVar3 == '\0') {

LAB_006c074f:

            cVar3 = '\0';

          }

          else {

            pfVar4 = (float *)(*param_4 + local_24);

            iVar2 = *param_2;

            if ((((param_5 <=

                   *pfVar4 * *(float *)(iVar7 + iVar2) +

                   *(float *)(iVar7 + 8 + iVar2) * pfVar4[2] +

                   *(float *)(iVar7 + 4 + iVar2) * pfVar4[1] + pfVar4[3]) ||

                 (param_5 <=

                  *(float *)(iVar7 + 0x10 + iVar2) * *pfVar4 +

                  *(float *)(iVar7 + 0x18 + iVar2) * pfVar4[2] +

                  *(float *)(iVar7 + 0x14 + iVar2) * pfVar4[1] + pfVar4[3])) ||

                (param_5 <=

                 *(float *)(iVar7 + 0x28 + iVar2) * pfVar4[2] +

                 *(float *)(iVar7 + 0x24 + iVar2) * pfVar4[1] +

                 *(float *)(iVar7 + 0x20 + iVar2) * *pfVar4 + pfVar4[3])) ||

               (param_5 <=

                *(float *)(iVar7 + 0x38 + iVar2) * pfVar4[2] +

                *(float *)(iVar7 + 0x34 + iVar2) * pfVar4[1] +

                *(float *)(iVar7 + 0x30 + iVar2) * *pfVar4 + pfVar4[3])) goto LAB_006c074f;

            cVar3 = '\x01';

          }

          iVar7 = iVar7 + 0x40;

          iVar8 = iVar8 + -1;

        } while (iVar8 != 0);

      }

      if (iVar6 < iVar1) {

        iVar7 = iVar6 << 4;

        iVar6 = iVar1 - iVar6;

        do {

          if ((cVar3 == '\0') ||

             (pfVar4 = (float *)(*param_4 + local_24), pfVar5 = (float *)(*param_2 + iVar7),

             param_5 <=

             *pfVar4 * *pfVar5 +

             pfVar5[1] * pfVar4[1] + *(float *)(*param_2 + 8 + iVar7) * pfVar4[2] + pfVar4[3])) {

            cVar3 = '\0';

          }

          else {

            cVar3 = '\x01';

          }

          iVar7 = iVar7 + 0x10;

          iVar6 = iVar6 + -1;

        } while (iVar6 != 0);

      }

      if (0 < param_3[1]) {

        iVar7 = 0;

        iVar6 = param_3[1];

        do {

          if (cVar3 == '\0') {

LAB_006c081c:

            cVar3 = '\0';

          }

          else {

            pfVar4 = (float *)(*param_4 + local_24);

            pfVar5 = (float *)(*param_3 + iVar7);

            if (param_5 <=

                pfVar4[1] * pfVar5[1] + *pfVar4 * *pfVar5 + pfVar4[2] * pfVar5[2] + pfVar4[3])

            goto LAB_006c081c;

            cVar3 = '\x01';

          }

          iVar7 = iVar7 + 0x10;

          iVar6 = iVar6 + -1;

        } while (iVar6 != 0);

      }

      local_24 = local_24 + 0x10;

      local_18 = local_18 + -1;

    } while (local_18 != 0);

  }

  *param_1 = cVar3;

  return;

}
