// =============================================================================
// FUN_0074c420
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c420
// Address:   0x0074c420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074c420 @ 0x0074c420
// Stable ID: aa_0074c420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×16, goto×4, return×3.
//  - Notable callees: FUN_0074c420, FUN_009728e0, FUN_009730e0, FUN_009732d0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0074c420(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  float *unaff_EBX;

  int unaff_EDI;

  float fVar1;

  float fVar2;

  float fVar3;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (*(char *)(unaff_EDI + 0x2c) == '\0') {

    FUN_009732d0(&local_18,param_1);

    if ((*(uint *)(in_EAX + 0xbc) >> 1 & 1) != 0) {

      FUN_009730e0();

    }

    FUN_009728e0(&local_c);

    if ((local_8 < 0.0) &&

       (*(float *)(unaff_EDI + 0x18) <= local_14 && local_14 != *(float *)(unaff_EDI + 0x18))) {

      fVar3 = (*(float *)(unaff_EDI + 0x24) - local_14) / local_8;

      fVar1 = local_c * fVar3 + local_18;

      fVar2 = local_4 * fVar3 + local_10;

      if ((*(float *)(unaff_EDI + 0x14) <= fVar1 && fVar1 != *(float *)(unaff_EDI + 0x14)) &&

         (((fVar1 < *(float *)(unaff_EDI + 0x20) &&

           (*(float *)(unaff_EDI + 0x1c) <= fVar2 && fVar2 != *(float *)(unaff_EDI + 0x1c))) &&

          (fVar2 < *(float *)(unaff_EDI + 0x28))))) goto LAB_0074c67b;

    }

    if ((g_flZero < local_8) && (local_14 < *(float *)(unaff_EDI + 0x24))) {

      fVar3 = (*(float *)(unaff_EDI + 0x18) - local_14) / local_8;

      fVar1 = local_c * fVar3 + local_18;

      fVar2 = local_4 * fVar3 + local_10;

      if ((*(float *)(unaff_EDI + 0x14) <= fVar1 && fVar1 != *(float *)(unaff_EDI + 0x14)) &&

         (((fVar1 < *(float *)(unaff_EDI + 0x20) &&

           (*(float *)(unaff_EDI + 0x1c) <= fVar2 && fVar2 != *(float *)(unaff_EDI + 0x1c))) &&

          (fVar2 < *(float *)(unaff_EDI + 0x28))))) goto LAB_0074c67b;

    }

    if ((local_c < 0.0) &&

       (*(float *)(unaff_EDI + 0x14) <= local_18 && local_18 != *(float *)(unaff_EDI + 0x14))) {

      fVar3 = (*(float *)(unaff_EDI + 0x20) - local_18) / local_c;

      fVar1 = local_8 * fVar3 + local_14;

      fVar2 = local_4 * fVar3 + local_10;

      if ((*(float *)(unaff_EDI + 0x18) <= fVar1 && fVar1 != *(float *)(unaff_EDI + 0x18)) &&

         (((fVar1 < *(float *)(unaff_EDI + 0x24) &&

           (*(float *)(unaff_EDI + 0x1c) <= fVar2 && fVar2 != *(float *)(unaff_EDI + 0x1c))) &&

          (fVar2 < *(float *)(unaff_EDI + 0x28))))) goto LAB_0074c67b;

    }

    if ((g_flZero < local_c) && (local_18 < *(float *)(unaff_EDI + 0x20))) {

      fVar3 = (*(float *)(unaff_EDI + 0x14) - local_18) / local_c;

      fVar1 = local_8 * fVar3 + local_14;

      fVar2 = local_4 * fVar3 + local_10;

      if ((*(float *)(unaff_EDI + 0x18) <= fVar1 && fVar1 != *(float *)(unaff_EDI + 0x18)) &&

         (((fVar1 < *(float *)(unaff_EDI + 0x24) &&

           (*(float *)(unaff_EDI + 0x1c) <= fVar2 && fVar2 != *(float *)(unaff_EDI + 0x1c))) &&

          (fVar2 < *(float *)(unaff_EDI + 0x28))))) goto LAB_0074c67b;

    }

    if ((local_4 < 0.0) &&

       (*(float *)(unaff_EDI + 0x1c) <= local_10 && local_10 != *(float *)(unaff_EDI + 0x1c))) {

      fVar3 = (*(float *)(unaff_EDI + 0x28) - local_10) / local_4;

      fVar1 = local_c * fVar3 + local_18;

      fVar2 = local_8 * fVar3 + local_14;

      if ((*(float *)(unaff_EDI + 0x14) <= fVar1 && fVar1 != *(float *)(unaff_EDI + 0x14)) &&

         (((fVar1 < *(float *)(unaff_EDI + 0x20) &&

           (*(float *)(unaff_EDI + 0x18) <= fVar2 && fVar2 != *(float *)(unaff_EDI + 0x18))) &&

          (fVar2 < *(float *)(unaff_EDI + 0x24))))) {

LAB_0074c67b:

        if (unaff_EBX != (float *)0x0) {

          *unaff_EBX = fVar3;

        }

        return 1;

      }

    }

    if ((g_flZero < local_4) && (local_10 < *(float *)(unaff_EDI + 0x20))) {

      local_4 = (*(float *)(unaff_EDI + 0x1c) - local_10) / local_4;

      local_18 = local_c * local_4 + local_18;

      local_14 = local_8 * local_4 + local_14;

      if (((*(float *)(unaff_EDI + 0x14) <= local_18 && local_18 != *(float *)(unaff_EDI + 0x14)) &&

          ((local_18 < *(float *)(unaff_EDI + 0x20) &&

           (*(float *)(unaff_EDI + 0x18) <= local_14 && local_14 != *(float *)(unaff_EDI + 0x18)))))

         && (local_14 < *(float *)(unaff_EDI + 0x24))) {

        if (unaff_EBX != (float *)0x0) {

          *unaff_EBX = local_4;

        }

        return 1;

      }

    }

  }

  return 0;

}
