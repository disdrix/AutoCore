// =============================================================================
// FUN_00574e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00574e60
// Address:   0x00574e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574e60 @ 0x00574e60
// Stable ID: aa_00574e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00574e60, SQRT.
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

uint __thiscall FUN_00574e60(int param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  char cVar6;

  float *pfVar7;

  int *piVar8;

  int iVar9;

  uint local_30;

  int iStack_24;

  

  local_30 = (uint)*(byte *)(param_1 + 0x1d8);

  pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1a0

                                ))();

  fVar1 = *pfVar7;

  fVar2 = pfVar7[2];

  iVar9 = 0;

  piVar8 = (int *)(param_1 + 0x1a0);

  iStack_24 = 4;

  do {

    if (((-1 < iVar9) && (iVar9 < 4)) && (iVar5 = *piVar8, iVar5 != 0)) {

      pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1a0

                                    ))();

      fVar3 = pfVar7[2];

      fVar4 = *pfVar7;

      cVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))();

      if ((cVar6 != '\0') ||

         (DAT_00aaa8a8 <=

          SQRT((fVar2 - fVar3) * (fVar2 - fVar3) + (fVar1 - fVar4) * (fVar1 - fVar4)))) {

        local_30 = local_30 - 1;

      }

    }

    iVar9 = iVar9 + 1;

    piVar8 = piVar8 + 4;

    iStack_24 = iStack_24 + -1;

  } while (iStack_24 != 0);

  if ((int)local_30 < 1) {

    local_30 = 1;

  }

  return local_30;

}
