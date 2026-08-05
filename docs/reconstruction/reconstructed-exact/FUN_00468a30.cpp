// =============================================================================
// FUN_00468a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00468a30
// Address:   0x00468a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00468a30 @ 0x00468a30
// Stable ID: aa_00468a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00468a30.
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

void FUN_00468a30(int param_1,int param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int in_EAX;

  int iVar4;

  int unaff_EBX;

  

  while (param_2 < in_EAX) {

    iVar4 = (in_EAX + -1) / 2;

    iVar3 = *(int *)(param_1 + iVar4 * 4);

    fVar2 = *(float *)(unaff_EBX + 0xc + param_3 * 4);

    pfVar1 = (float *)(iVar3 + 0xc + param_3 * 4);

    if ((fVar2 < *pfVar1 || fVar2 == *pfVar1) &&

       ((*(float *)(iVar3 + 0xc + param_3 * 4) != *(float *)(unaff_EBX + 0xc + param_3 * 4) ||

        (fVar2 = *(float *)(unaff_EBX + param_3 * 4), pfVar1 = (float *)(iVar3 + param_3 * 4),

        fVar2 < *pfVar1 || fVar2 == *pfVar1)))) break;

    *(uint32_t /* width from decompiler */ *)(param_1 + in_EAX * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar4 * 4);

    in_EAX = iVar4;

  }

  *(int *)(param_1 + in_EAX * 4) = unaff_EBX;

  return;

}
