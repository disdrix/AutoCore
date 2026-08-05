// =============================================================================
// FUN_006908e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006908e0
// Address:   0x006908e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006908e0 @ 0x006908e0
// Stable ID: aa_006908e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, for×1, do×1, return×1.
//  - Notable callees: FUN_0068cda0, FUN_006908e0.
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

void FUN_006908e0(int param_1,uint32_t /* width from decompiler */ param_2,float *param_3,char param_4)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  float *pfVar4;

  float local_20 [8];

  

  pfVar4 = local_20;

  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

    *pfVar4 = *param_3;

    param_3 = param_3 + 1;

    pfVar4 = pfVar4 + 1;

  }

  if (param_4 != '\0') {

    iVar2 = 1;

    do {

      iVar1 = iVar2 + 2;

      local_20[iVar2] = -local_20[iVar2];

      iVar2 = iVar1;

    } while (iVar1 < 8);

  }

  *(uint16_t *)(param_1 + 0x1a) = 0;

  iVar2 = 0;

  while( true ) {

    if (*(int *)(param_1 + 100) == 0) {

      uVar3 = 0;

    }

    else {

      uVar3 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;

    }

    if ((int)(uVar3 / 3 & 0xffff) <= iVar2) break;

    FUN_0068cda0(param_2,local_20);

    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 1;

    iVar2 = iVar2 + 1;

  }

  return;

}
