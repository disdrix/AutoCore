// =============================================================================
// FUN_009141e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009141e0
// Address:   0x009141e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009141e0 @ 0x009141e0
// Stable ID: aa_009141e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_009141e0.
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



void __fastcall FUN_009141e0(int param_1)



{

  int iVar1;

  bool bVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  iVar1 = DAT_00d09874;

  if (*(float *)(param_1 + 0x530) != *(float *)(param_1 + 0x52c)) {

    fVar6 = *(float *)(param_1 + 0x530) - *(float *)(param_1 + 0x52c);

    *(uint8_t *)(param_1 + 0xce0) = 1;

    if ((*(float *)(iVar1 + 0x30) == 0.0) ||

       (fVar4 = g_flOne / *(float *)(iVar1 + 0x30), fVar4 == 0.0)) {

      fVar4 = (float)g_nInferredThreatDefault;

    }

    fVar4 = (fVar6 / fVar4) * DAT_00aaa688;

    if (fVar4 <= 0.0) {

      if (_DAT_00aaa6d8 < (double)fVar4) {

        fVar4 = DAT_00aaa6d4;

      }

      fVar5 = *(float *)(param_1 + 0x52c) + fVar4;

      bVar3 = *(float *)(param_1 + 0x530) == fVar5;

      bVar2 = *(float *)(param_1 + 0x530) < fVar5;

    }

    else {

      if (fVar4 < (float)_DAT_00aaa6e0) {

        fVar4 = g_flMultiKillCountBlend;

      }

      fVar5 = *(float *)(param_1 + 0x52c) + fVar4;

      bVar3 = fVar5 == *(float *)(param_1 + 0x530);

      bVar2 = fVar5 < *(float *)(param_1 + 0x530);

    }

    if (!bVar2 && !bVar3) {

      fVar4 = fVar6;

    }

    fVar4 = *(float *)(param_1 + 0x52c) + fVar4;

    *(float *)(param_1 + 0x52c) = fVar4;

    if (*(float *)(param_1 + 0xcdc) <= fVar4 && fVar4 != *(float *)(param_1 + 0xcdc)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xcdc);

    }

  }

  return;

}
