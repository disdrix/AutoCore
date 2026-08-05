// =============================================================================
// FUN_00465260
// -----------------------------------------------------------------------------
// Stable ID: aa_00465260
// Address:   0x00465260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00465260 @ 0x00465260
// Stable ID: aa_00465260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: ABS×6, FUN_00465260.
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



void __fastcall FUN_00465260(uint32_t /* width from decompiler */ param_1,int param_2)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float local_4;

  

  if (*(char *)(param_2 + 0x218) == '\0') {

    pfVar2 = (float *)(param_2 + 0x1f0);

    pfVar1 = (float *)(param_2 + 0x1e0);

    pfVar3 = (float *)(param_2 + 0x1e4);

    *(float *)(param_2 + 0x21c) =

         (ABS(*pfVar1) * g_flOverheatCoolFrac +

         ABS(*(float *)(param_2 + 0x1e4)) * _DAT_00aaa798 +

         ABS(*(float *)(param_2 + 0x1e8)) * _DAT_00aaa79c +

         ABS(*pfVar2) * g_flOverheatCoolFrac +

         ABS(*(float *)(param_2 + 500)) * _DAT_00aaa798 +

         ABS(*(float *)(param_2 + 0x1f8)) * _DAT_00aaa79c) * *(float *)(param_2 + 0x214);

    if (*pfVar3 <= *pfVar1 && *pfVar1 != *pfVar3) {

      pfVar3 = pfVar1;

    }

    pfVar1 = (float *)(param_2 + 0x1e8);

    if (*pfVar1 <= *pfVar3 && *pfVar3 != *pfVar1) {

      pfVar1 = pfVar3;

    }

    pfVar3 = (float *)(param_2 + 0x134);

    *pfVar3 = *pfVar1;

    pfVar1 = (float *)(param_2 + 500);

    if (*(float *)(param_2 + 500) <= *pfVar2 && *pfVar2 != *(float *)(param_2 + 500)) {

      pfVar1 = pfVar2;

    }

    pfVar2 = (float *)(param_2 + 0x1f8);

    if (*pfVar1 < *pfVar2 || *pfVar1 == *pfVar2) {

      pfVar1 = pfVar2;

    }

    local_4 = *pfVar1;

    pfVar2 = pfVar3;

    if (*pfVar3 <= *pfVar1) {

      pfVar2 = &local_4;

    }

    *pfVar3 = *pfVar2;

    *(uint8_t *)(param_2 + 0x218) = 1;

  }

  return;

}
