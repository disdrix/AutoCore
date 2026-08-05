// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee400
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee400
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005ee400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_005ee310×2, FUN_005ee400.
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



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee400(int *param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  uint uVar5;

  

  iVar2 = *param_1;

  iVar4 = param_1[1] - iVar2 >> 0x1f;

  uVar5 = 0;

  if ((param_1[1] - iVar2) / 0xc + iVar4 != iVar4) {

    iVar4 = 0;

    do {

      pfVar3 = (float *)(iVar4 + iVar2);

      fVar1 = param_2 * *pfVar3 + param_3 * pfVar3[1] + param_4 * pfVar3[2] + param_5;

      if (fVar1 < (float)_DAT_009dcfb0) {

        iVar2 = 2;

      }

      else if (fVar1 <= (float)_DAT_009dcfa8) {

        iVar2 = 3;

      }

      else {

        iVar2 = 1;

      }

      if ((iVar2 == 1) || (iVar2 == 2)) {

LAB_005ee4af:

        FUN_005ee310(pfVar3);

      }

      else if (iVar2 == 3) {

        FUN_005ee310(pfVar3);

        pfVar3 = (float *)(*param_1 + iVar4);

        goto LAB_005ee4af;

      }

      iVar2 = *param_1;

      uVar5 = uVar5 + 1;

      iVar4 = iVar4 + 0xc;

    } while (uVar5 < (uint)((param_1[1] - iVar2) / 0xc));

  }

  return;

}
