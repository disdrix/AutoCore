// =============================================================================
// FUN_0068cb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0068cb80
// Address:   0x0068cb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068cb80 @ 0x0068cb80
// Stable ID: aa_0068cb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004490a0×3, FUN_0068cb80.
//  - Return sites: 2.

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

void __thiscall FUN_0068cb80(int param_1,float *param_2)



{

  int iVar1;

  float *pfVar2;

  float local_c;

  float local_8;

  float local_4;

  

  local_8 = param_2[2];

  local_4 = param_2[1];

  local_c = -*param_2;

  iVar1 = *(int *)(param_1 + 0xa4);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0xac) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0xa8) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa8),1,&local_c);

  }

  else {

    pfVar2 = *(float **)(param_1 + 0xa8);

    *pfVar2 = local_c;

    *(float **)(param_1 + 0xa8) = pfVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 0xa4);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0xac) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0xa8) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa8),1,&local_8);

  }

  else {

    pfVar2 = *(float **)(param_1 + 0xa8);

    *pfVar2 = local_8;

    *(float **)(param_1 + 0xa8) = pfVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 0xa4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0xa8) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xac) - iVar1 >> 2))

     ) {

    pfVar2 = *(float **)(param_1 + 0xa8);

    *pfVar2 = local_4;

    *(float **)(param_1 + 0xa8) = pfVar2 + 1;

    return;

  }

  FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa8),1,&local_4);

  return;

}
