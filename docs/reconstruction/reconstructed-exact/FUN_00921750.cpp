// =============================================================================
// FUN_00921750
// -----------------------------------------------------------------------------
// Stable ID: aa_00921750
// Address:   0x00921750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00921750 @ 0x00921750
// Stable ID: aa_00921750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: ABS, Client_MaybeShowFirstTimeTip, FUN_00921750.
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

void __fastcall FUN_00921750(uint32_t /* width from decompiler */ param_1)



{

  float *pfVar1;

  int unaff_ESI;

  

  if (((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x30c) != '\0')) &&

     ((*(uint *)(DAT_00d1b6d8 + 0xd30) >> 5 & 1) == 0)) {

    if ((DAT_00d1bc26 != '\0') || (DAT_00d1bc5a != '\0')) {

      *(int *)(unaff_ESI + 0xc60) = *(int *)(unaff_ESI + 0xc60) + 1;

    }

    pfVar1 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))(param_1);

    if (DAT_00aaaca8 <

        ABS((pfVar1[2] * pfVar1[2] + pfVar1[1] * pfVar1[1] + *pfVar1 * *pfVar1) -

            (*(float *)(unaff_ESI + 0xc58) * *(float *)(unaff_ESI + 0xc58) +

            *(float *)(unaff_ESI + 0xc54) * *(float *)(unaff_ESI + 0xc54) +

            *(float *)(unaff_ESI + 0xc50) * *(float *)(unaff_ESI + 0xc50)))) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc60) = 0;

      *(float *)(unaff_ESI + 0xc50) = *pfVar1;

      *(float *)(unaff_ESI + 0xc54) = pfVar1[1];

      *(float *)(unaff_ESI + 0xc58) = pfVar1[2];

      *(float *)(unaff_ESI + 0xc5c) = pfVar1[3];

      return;

    }

    if (0x28 < *(int *)(unaff_ESI + 0xc60)) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc60) = 0;

      *(float *)(unaff_ESI + 0xc50) = *pfVar1;

      *(float *)(unaff_ESI + 0xc54) = pfVar1[1];

      *(float *)(unaff_ESI + 0xc58) = pfVar1[2];

      *(float *)(unaff_ESI + 0xc5c) = pfVar1[3];

      Client_MaybeShowFirstTimeTip(5);

    }

  }

  return;

}
