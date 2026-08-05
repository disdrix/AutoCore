// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ecbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ecbc0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005ecbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_005ecbc0, FUN_005ee310.
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



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ecbc0(int *param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float local_c;

  float local_8;

  float local_4;

  

  iVar6 = *param_1;

  iVar4 = param_1[1] - iVar6 >> 0x1f;

  uVar5 = 0;

  if ((param_1[1] - iVar6) / 0x1c + iVar4 != iVar4) {

    iVar4 = 0;

    do {

      iVar7 = *(int *)param_1[4];

      iVar2 = *(int *)(iVar4 + iVar6) * 0xc;

      iVar6 = *(int *)(iVar4 + 4 + iVar6) * 0xc;

      fVar8 = *(float *)(iVar6 + 4 + iVar7) * param_3 + *(float *)(iVar6 + 8 + iVar7) * param_4 +

              *(float *)(iVar6 + iVar7) * param_2 + param_5;

      fVar1 = param_2 * *(float *)(iVar7 + iVar2) +

              param_4 * *(float *)(iVar7 + 8 + iVar2) + param_3 * *(float *)(iVar7 + 4 + iVar2) +

              param_5;

      if ((float)_DAT_009dcfb0 <= fVar1) {

        if ((double)fVar1 <= _DAT_009dcfa8) {

          iVar7 = 0;

        }

        else {

          iVar7 = 1;

        }

      }

      else {

        iVar7 = -1;

      }

      if ((float)_DAT_009dcfb0 <= fVar8) {

        if ((double)fVar8 <= _DAT_009dcfa8) {

          iVar3 = 0;

        }

        else {

          iVar3 = 1;

        }

      }

      else {

        iVar3 = -1;

      }

      iVar7 = iVar7 + iVar3 * 10;

      if ((iVar7 == -9) || (iVar7 == 9)) {

        iVar7 = *(int *)param_1[4];

        fVar8 = g_flOne / (fVar1 - fVar8);

        local_c = *(float *)(iVar7 + iVar2) +

                  (*(float *)(iVar7 + iVar6) - *(float *)(iVar7 + iVar2)) * fVar1 * fVar8;

        local_8 = *(float *)(iVar7 + 4 + iVar2) +

                  (*(float *)(iVar7 + 4 + iVar6) - *(float *)(iVar7 + 4 + iVar2)) * fVar1 * fVar8;

        local_4 = *(float *)(iVar7 + 8 + iVar2) +

                  (*(float *)(iVar7 + 8 + iVar6) - *(float *)(iVar7 + 8 + iVar2)) * fVar1 * fVar8;

        FUN_005ee310(&local_c);

      }

      iVar6 = *param_1;

      uVar5 = uVar5 + 1;

      iVar4 = iVar4 + 0x1c;

    } while (uVar5 < (uint)((param_1[1] - iVar6) / 0x1c));

  }

  return;

}
