// =============================================================================
// FUN_00450f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00450f30
// Address:   0x00450f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00450f30 @ 0x00450f30
// Stable ID: aa_00450f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00450f30.
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

uint32_t /* width from decompiler */ __fastcall FUN_00450f30(float *param_1)



{

  float *in_EAX;

  

  if ((*in_EAX < *param_1 || *in_EAX == *param_1) &&

     ((*in_EAX <= *param_1 && *param_1 != *in_EAX ||

      ((in_EAX[1] < param_1[1] || in_EAX[1] == param_1[1] &&

       ((in_EAX[1] <= param_1[1] && param_1[1] != in_EAX[1] ||

        ((in_EAX[2] < param_1[2] || in_EAX[2] == param_1[2] &&

         ((in_EAX[2] <= param_1[2] && param_1[2] != in_EAX[2] ||

          ((in_EAX[3] < param_1[3] || in_EAX[3] == param_1[3] &&

           ((in_EAX[3] <= param_1[3] && param_1[3] != in_EAX[3] ||

            ((in_EAX[4] < param_1[4] || in_EAX[4] == param_1[4] &&

             ((in_EAX[4] <= param_1[4] && param_1[4] != in_EAX[4] ||

              (in_EAX[5] < param_1[5] || in_EAX[5] == param_1[5])))))))))))))))))))) {

    return 0;

  }

  return 1;

}
