// =============================================================================
// FUN_008845c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008845c0
// Address:   0x008845c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008845c0 @ 0x008845c0
// Stable ID: aa_008845c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, goto×1, return×1.
//  - Notable callees: FUN_00404c90×2, FUN_00791f30, FUN_008845c0, FUN_0094c430, SQRT.
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

void __thiscall FUN_008845c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  iVar1 = *(int *)(param_1 + 0x510);

  if (iVar1 != 0) {

    iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    if (*(char *)(*(int *)(iVar2 + 0xa8 + DAT_00d1b6d8) + 0xf5) == '\0') {

      if ((*(int *)(DAT_00d1b6d8 + 0x250) == 0) || (*(int *)(iVar1 + 0x250) == 0))

      goto LAB_00884709;

      pfVar3 = (float *)FUN_00404c90();

      fVar5 = *pfVar3;

      fVar6 = pfVar3[1];

      fVar7 = pfVar3[2];

      pfVar3 = (float *)FUN_00404c90();

      fVar5 = *pfVar3 - fVar5;

      fVar6 = pfVar3[1] - fVar6;

      fVar7 = pfVar3[2] - fVar7;

    }

    else {

      if (*(int *)(DAT_00d1b6d8 + 8) == 0) {

        pfVar3 = (float *)(iVar2 + DAT_00d1b6d8 + 0x84);

      }

      else {

        pfVar3 = (float *)(*(int *)(*(int *)(DAT_00d1b6d8 + 8) + 0x3c) + 0xb0);

      }

      if (*(int *)(iVar1 + 8) == 0) {

        pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);

      }

      else {

        pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);

      }

      fVar5 = *pfVar4 - *pfVar3;

      fVar6 = pfVar4[1] - pfVar3[1];

      fVar7 = pfVar4[2] - pfVar3[2];

    }

    if (DAT_00a1109c < SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7)) {

      FUN_0094c430();

    }

  }

LAB_00884709:

  FUN_00791f30(param_2);

  return;

}
