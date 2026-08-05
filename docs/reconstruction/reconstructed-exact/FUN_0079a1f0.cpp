// =============================================================================
// FUN_0079a1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a1f0
// Address:   0x0079a1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a1f0 @ 0x0079a1f0
// Stable ID: aa_0079a1f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×1, return×1.
//  - Notable callees: FUN_0079a1f0.
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

void __fastcall FUN_0079a1f0(int param_1)



{

  int *piVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  

  pfVar2 = (float *)(param_1 + 0xa0);

  iVar4 = 2;

  do {

    *pfVar2 = pfVar2[-0x1c] + *pfVar2;

    pfVar2[1] = pfVar2[-0x1b] + pfVar2[1];

    pfVar2[2] = pfVar2[-0x1a] + pfVar2[2];

    pfVar2[3] = pfVar2[-0x19] + pfVar2[3];

    pfVar2[4] = pfVar2[-0x18] + pfVar2[4];

    pfVar2[5] = pfVar2[-0x17] + pfVar2[5];

    pfVar2[6] = pfVar2[-0x16] + pfVar2[6];

    pfVar2 = pfVar2 + 7;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = 0;

  if (0 < *(int *)(param_1 + 0x1c)) {

    iVar3 = 0;

    do {

      piVar1 = (int *)(*(int *)(param_1 + 0x18) + 0xc + iVar3);

      *piVar1 = *piVar1 + *(int *)(*(int *)(param_1 + 0x18) + 4 + iVar3);

      piVar1 = (int *)(*(int *)(param_1 + 0x18) + 0x10 + iVar3);

      *piVar1 = *piVar1 + *(int *)(*(int *)(param_1 + 0x18) + 8 + iVar3);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + *(int *)(param_1 + 0x18)) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 8 + *(int *)(param_1 + 0x18)) = 0;

      iVar4 = iVar4 + 1;

      iVar3 = iVar3 + 0x2c;

    } while (iVar4 < *(int *)(param_1 + 0x1c));

  }

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  return;

}
