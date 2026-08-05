// =============================================================================
// FUN_00468860
// -----------------------------------------------------------------------------
// Stable ID: aa_00468860
// Address:   0x00468860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00468860 @ 0x00468860
// Stable ID: aa_00468860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00468860, FUN_00468a30.
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

void FUN_00468860(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = param_2;

  while( true ) {

    iVar6 = iVar5 * 2 + 2;

    if (param_3 <= iVar6) break;

    iVar3 = *(int *)(param_1 + -4 + iVar6 * 4);

    iVar4 = *(int *)(param_1 + iVar6 * 4);

    fVar2 = *(float *)(iVar3 + 0xc + param_5 * 4);

    pfVar1 = (float *)(iVar4 + 0xc + param_5 * 4);

    if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

       ((*(float *)(iVar4 + 0xc + param_5 * 4) == *(float *)(iVar3 + 0xc + param_5 * 4) &&

        (fVar2 = *(float *)(iVar3 + param_5 * 4), pfVar1 = (float *)(iVar4 + param_5 * 4),

        *pfVar1 <= fVar2 && fVar2 != *pfVar1)))) {

      iVar6 = iVar5 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar6 * 4);

    iVar5 = iVar6;

  }

  if (iVar6 == param_3) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_3 * 4);

  }

  FUN_00468a30(param_1,param_2,param_5);

  return;

}
