// =============================================================================
// FUN_00713130
// -----------------------------------------------------------------------------
// Stable ID: aa_00713130
// Address:   0x00713130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713130 @ 0x00713130
// Stable ID: aa_00713130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00713130, FUN_007132c0.
//  - Return sites: 1.

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

void FUN_00713130(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,uint32_t /* width from decompiler */ *param_4,uint param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  float *pfVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float10 fVar6;

  float local_8 [2];

  

  puVar1 = param_4;

  if (0 < (int)param_5) {

    pfVar3 = local_8;

    for (uVar2 = param_5 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {

      *pfVar3 = 3.40282e+38;

      pfVar3 = pfVar3 + 1;

    }

    for (uVar2 = param_5 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {

      *param_4 = 0;

      param_4 = param_4 + 1;

    }

  }

  param_4 = (uint32_t /* width from decompiler */ *)0x0;

  if (0 < param_3) {

    do {

      fVar6 = (float10)FUN_007132c0(param_1,param_2);

      param_2 = param_2 + 8;

      if (fVar6 < (float10)*(float *)(&stack0xfffffff4 + param_5 * 4)) {

        iVar4 = param_5 - 1;

        if (0 < iVar4) {

          puVar5 = puVar1 + iVar4;

          pfVar3 = (float *)(&stack0xfffffff4 + iVar4 * 4);

          do {

            if ((float10)*pfVar3 < fVar6) break;

            iVar4 = iVar4 + -1;

            pfVar3[1] = *pfVar3;

            *puVar5 = *(uint32_t /* width from decompiler */ *)((int)pfVar3 + ((int)puVar1 - (int)local_8));

            pfVar3 = pfVar3 + -1;

            puVar5 = puVar5 + -1;

          } while (0 < iVar4);

        }

        local_8[iVar4] = (float)fVar6;

        puVar1[iVar4] = param_4;

      }

      param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 1);

    } while ((int)param_4 < param_3);

  }

  return;

}
