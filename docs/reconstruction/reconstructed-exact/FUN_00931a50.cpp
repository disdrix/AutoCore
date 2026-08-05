// =============================================================================
// FUN_00931a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00931a50
// Address:   0x00931a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00931a50 @ 0x00931a50
// Stable ID: aa_00931a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, FUN_00931a50.
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

void FUN_00931a50(float param_1)



{

  int iVar1;

  int iVar2;

  int unaff_ESI;

  float fVar3;

  

  iVar2 = *(int *)(unaff_ESI + 0xe98);

  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x250) != 0)) && (*(char *)(iVar2 + 0x30c) != '\0')) {

    if (*(float *)(unaff_ESI + 0x3bf0) != *(float *)(unaff_ESI + 0x3bf4)) {

      if (0.0 <= *(float *)(unaff_ESI + 0x3bf0) - *(float *)(unaff_ESI + 0x3bf4)) {

        param_1 = *(float *)(unaff_ESI + 0x3bf4) + param_1;

        *(float *)(unaff_ESI + 0x3bf4) = param_1;

        if (*(float *)(unaff_ESI + 0x3bf0) <= param_1 && param_1 != *(float *)(unaff_ESI + 0x3bf0))

        {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3bf4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3bf0);

        }

      }

      else {

        param_1 = *(float *)(unaff_ESI + 0x3bf4) - param_1;

        *(float *)(unaff_ESI + 0x3bf4) = param_1;

        if (param_1 < *(float *)(unaff_ESI + 0x3bf0)) {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3bf4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3bf0);

        }

      }

    }

    iVar2 = *(int *)(iVar2 + 0x250);

    if (((*(int *)(iVar2 + 0x1a0) != 0) &&

        (iVar1 = *(int *)(*(int *)(iVar2 + 0x1a0) + 4), iVar1 != 0)) &&

       (iVar1 = *(int *)(iVar1 + 0x1c), iVar1 != 0)) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3be8) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

    }

    fVar3 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c) +

                      0x6b4) * *(float *)(iVar2 + 0x1fc) + DAT_00a0f520;

    *(float *)(unaff_ESI + 0x3bec) = fVar3;

    if (fVar3 < *(float *)(unaff_ESI + 0x3be8)) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3bec) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3be8);

    }

    if (*(float *)(unaff_ESI + 0x3bec) == 0.0) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3bf0) = 0;

    }

    else {

      *(float *)(unaff_ESI + 0x3bf0) =

           *(float *)(unaff_ESI + 0x3be8) / *(float *)(unaff_ESI + 0x3bec);

    }

    iVar2 = Client_GetMissionCompleteAudioTable();

    if (*(char *)(iVar2 + 600) != '\0') {

      fVar3 = *(float *)(unaff_ESI + 0x3bec) * *(float *)(unaff_ESI + 0x3bf4) * DAT_00a0f718;

      iVar2 = Client_GetMissionCompleteAudioTable();

      *(float *)(iVar2 + 0x250) = fVar3;

    }

  }

  return;

}
