// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ec1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ec1d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005ec1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, switch×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_005ec1d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ec1d0(int *param_1,float param_2,float param_3,float param_4,float param_5,int *param_6,

            int *param_7,int *param_8)



{

  float *pfVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  float fVar9;

  

  iVar6 = *param_1;

  iVar7 = param_1[1] - iVar6 >> 0x1f;

  uVar8 = 0;

  if ((param_1[1] - iVar6) / 0x1c + iVar7 != iVar7) {

    iVar7 = 0;

    do {

      iVar4 = *(int *)param_1[4];

      iVar2 = *(int *)(iVar7 + 4 + iVar6);

      pfVar1 = (float *)(iVar4 + *(int *)(iVar7 + iVar6) * 0xc);

      fVar3 = param_2 * *pfVar1 +

              param_4 * pfVar1[2] + param_3 * *(float *)(iVar4 + 4 + *(int *)(iVar7 + iVar6) * 0xc)

              + param_5;

      fVar9 = *(float *)(iVar4 + 4 + iVar2 * 0xc) * param_3 +

              *(float *)(iVar4 + 8 + iVar2 * 0xc) * param_4 +

              *(float *)(iVar4 + iVar2 * 0xc) * param_2 + param_5;

      if ((float)_DAT_009dcfb0 <= fVar3) {

        if (fVar3 <= (float)_DAT_009dcfa8) {

          iVar6 = 0;

        }

        else {

          iVar6 = 1;

        }

      }

      else {

        iVar6 = -1;

      }

      if ((float)_DAT_009dcfb0 <= fVar9) {

        if ((double)fVar9 <= _DAT_009dcfa8) {

          iVar4 = 0;

        }

        else {

          iVar4 = 1;

        }

      }

      else {

        iVar4 = -1;

      }

      switch(iVar6 + (iVar4 * 5 + 5) * 2) {

      case 0:

      case 9:

      case 0xb:

      case 0x14:

        piVar5 = param_8;

        break;

      case 1:

      case 0x13:

        piVar5 = param_7;

        break;

      default:

        goto switchD_005ec2e1_caseD_2;

      case 10:

        piVar5 = param_6;

      }

      *piVar5 = *piVar5 + 1;

switchD_005ec2e1_caseD_2:

      iVar6 = *param_1;

      uVar8 = uVar8 + 1;

      iVar7 = iVar7 + 0x1c;

    } while (uVar8 < (uint)((param_1[1] - iVar6) / 0x1c));

  }

  return;

}
