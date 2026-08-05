// =============================================================================
// FUN_00712980
// -----------------------------------------------------------------------------
// Stable ID: aa_00712980
// Address:   0x00712980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712980 @ 0x00712980
// Stable ID: aa_00712980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×15, return×1.
//  - Notable callees: FUN_00712980.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00712980(float param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = *param_2;

  if (DAT_00a0f6f4 <= fVar1) {

    if (_DAT_00a0f740 <= fVar1) {

      fVar2 = fVar1 * _DAT_00a0f738;

    }

    else {

      fVar2 = fVar1 * _DAT_00a0f73c;

    }

  }

  else {

    fVar2 = fVar1 * _DAT_00a0f748;

    if (fVar1 * _DAT_00a0f748 < fVar1 + _DAT_00a0f744) {

      fVar2 = fVar1 + _DAT_00a0f744;

    }

  }

  if (fVar1 <= param_1) {

    if ((*(char *)((int)param_2 + 0x13) == '\0') &&

       (fVar1 = param_1 * DAT_00a0f704 + fVar1 * DAT_00a0f708, fVar2 <= fVar1)) {

      fVar2 = fVar1;

    }

  }

  else {

    if ((*(char *)((int)param_2 + 0x12) < '\x01') &&

       (fVar3 = fVar1 * g_flMultiKillCountBlend + (param_1 + g_flOne) * DAT_00a0f734, fVar3 <= fVar2

       )) {

      fVar2 = fVar3;

    }

    if (fVar1 * g_flMsToSeconds_Inferred < param_1) {

      if (fVar1 * DAT_00a0f718 < param_1) {

        fVar1 = param_1 * DAT_00a0f698 + fVar1 * DAT_00a0f70c;

        if (fVar1 <= fVar2) {

          fVar2 = fVar1;

        }

      }

      else {

        fVar1 = param_1 * DAT_00a0f710 + fVar1 * g_flOverheatCoolFrac;

        if (fVar1 <= fVar2) {

          fVar2 = fVar1;

        }

      }

    }

    else if (g_flOne <= param_1) {

      fVar1 = param_1 * DAT_00a0f71c + fVar1 * DAT_00a0f720;

      if (fVar1 <= fVar2) {

        fVar2 = fVar1;

      }

    }

    else {

      fVar1 = fVar1 * _DAT_00a0f724 + (param_1 + g_flOne) * DAT_00a0f728;

      if (fVar1 <= fVar2) {

        fVar2 = fVar1;

      }

    }

  }

  if (_DAT_00a0f700 < fVar2) {

    fVar2 = _DAT_00a0f700;

  }

  if (*(char *)((int)param_2 + 0x12) < '\x01') {

    *(char *)((int)param_2 + 0x12) = *(char *)((int)param_2 + 0x12) + '\x01';

  }

  *param_2 = fVar2;

  return;

}
