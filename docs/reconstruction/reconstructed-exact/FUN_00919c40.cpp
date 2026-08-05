// =============================================================================
// FUN_00919c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00919c40
// Address:   0x00919c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00919c40 @ 0x00919c40
// Stable ID: aa_00919c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004e88e0, FUN_00919c40.
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

void FUN_00919c40(void)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint32_t /* width from decompiler */ uVar5;

  float *pfVar6;

  int unaff_ESI;

  float fVar7;

  uint8_t auStack_c [12];

  

  fVar4 = DAT_00d1ad28;

  fVar3 = DAT_00d1ad24;

  fVar2 = DAT_00d1ad20;

  if (DAT_00d1ad1c != '\0') {

    if (DAT_00d1b6d8 == 0) {

      pfVar6 = (float *)&DAT_00d1a6c0;

    }

    else {

      uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x1a0))();

      pfVar6 = (float *)FUN_004e88e0(auStack_c,uVar5);

    }

    if ((pfVar6[2] - fVar4) * (pfVar6[2] - fVar4) + (pfVar6[1] - fVar3) * (pfVar6[1] - fVar3) +

        (*pfVar6 - fVar2) * (*pfVar6 - fVar2) < DAT_00aaa9b8) {

      DAT_00d1ad1c = '\0';

    }

  }

  iVar1 = *(int *)(unaff_ESI + 0xcac);

  if (iVar1 != 0) {

    if (DAT_00d1ad1c != '\0') {

      *(float *)(iVar1 + 0x508) = fVar2;

      fVar7 = fVar3 + g_flLevelUpUiBase_Inferred;

      *(float *)(iVar1 + 0x50c) = fVar3;

      *(float *)(iVar1 + 0x510) = fVar4;

      iVar1 = *(int *)(unaff_ESI + 0xcac);

      *(float *)(iVar1 + 0x514) = fVar2;

      *(float *)(iVar1 + 0x518) = fVar7;

      *(float *)(iVar1 + 0x51c) = fVar4;

      (**(code **)(**(int **)(unaff_ESI + 0xcac) + 0xcc))(1);

      (**(code **)(**(int **)(unaff_ESI + 0xcac) + 0x34c))();

      return;

    }

    (**(code **)(**(int **)(unaff_ESI + 0xcac) + 4))(0);

  }

  return;

}
