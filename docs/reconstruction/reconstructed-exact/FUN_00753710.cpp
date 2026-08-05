// =============================================================================
// FUN_00753710
// -----------------------------------------------------------------------------
// Stable ID: aa_00753710
// Address:   0x00753710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753710 @ 0x00753710
// Stable ID: aa_00753710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00753710.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00753710(void)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  int unaff_ESI;

  float local_c [3];

  

  pfVar3 = local_c;

  if (*(char *)(unaff_ESI + 0xf2) == '\0') {

    local_c[2] = (float)-*(int *)(unaff_ESI + 0xe8) * g_flMsToSeconds_Inferred;

  }

  else {

    local_c[2] = (float)*(int *)(unaff_ESI + 0xe8);

    if (*(int *)(unaff_ESI + 0xe8) < 0) {

      local_c[2] = local_c[2] + _DAT_00aaa5dc;

    }

    local_c[2] = local_c[2] * _DAT_00aaa7a0;

  }

  local_c[2] = local_c[2] + *(float *)(unaff_ESI + 0xf4);

  local_c[1] = g_flOne;

  local_c[0] = 0.0;

  if ((0.0 <= local_c[2]) && (pfVar3 = local_c + 1, local_c[2] <= g_flOne)) {

    pfVar3 = local_c + 2;

  }

  fVar1 = *pfVar3;

  *(float *)(unaff_ESI + 0xf4) = fVar1;

  if (0.0 < fVar1) {

    if ((*(int *)(unaff_ESI + 0x108) != 0) &&

       (local_c[2] = (float)(*(int *)(unaff_ESI + 0x10c) - *(int *)(unaff_ESI + 0x108) >> 2),

       local_c[2] != 0.0)) {

      *(uint8_t *)(DAT_00d1f614 + 200) = 1;

      (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x108) + *(int *)(unaff_ESI + 0x114) * 4) + 0x10)

      )();

      iVar5 = *(int *)(unaff_ESI + 0xf8);

      iVar4 = *(int *)(unaff_ESI + 0xfc);

      *(uint8_t *)(unaff_ESI + 0x8c) = 1;

      iVar2 = DAT_00d1f614;

      if ((*(uint *)(unaff_ESI + 0x100) & 1) != 0) {

        iVar5 = (*(int *)(*(int *)(unaff_ESI + 0x88) + 0x80) - *(int *)(unaff_ESI + 0x80)) - iVar5;

      }

      if ((*(uint *)(unaff_ESI + 0x100) & 2) != 0) {

        iVar4 = (*(int *)(*(int *)(unaff_ESI + 0x88) + 0x84) - *(int *)(unaff_ESI + 0xfc)) -

                *(int *)(unaff_ESI + 0x84);

      }

      *(int *)(unaff_ESI + 0x7c) = iVar4;

      *(int *)(unaff_ESI + 0x78) = iVar5;

      *(uint8_t *)(iVar2 + 200) = 0;

    }

    return;

  }

  *(uint8_t *)(unaff_ESI + 0x8c) = 0;

  return;

}
