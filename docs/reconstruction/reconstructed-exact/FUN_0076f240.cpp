// =============================================================================
// FUN_0076f240
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f240
// Address:   0x0076f240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076f240 @ 0x0076f240
// Stable ID: aa_0076f240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040d450, FUN_0076f240.
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



float * FUN_0076f240(float *param_1)



{

  char cVar1;

  float *unaff_ESI;

  float *unaff_EDI;

  float fVar2;

  float local_20;

  float local_1c;

  float local_18;

  

  if (((((_DAT_00a240ec < unaff_ESI[3] || _DAT_00a240ec == unaff_ESI[3]) ||

        (unaff_ESI[3] <= DAT_00aaa640)) ||

       (_DAT_00a240ec < unaff_ESI[7] || _DAT_00a240ec == unaff_ESI[7])) ||

      ((unaff_ESI[7] <= DAT_00aaa640 ||

       (_DAT_00a240ec < unaff_ESI[0xb] || _DAT_00a240ec == unaff_ESI[0xb])))) ||

     ((unaff_ESI[0xb] <= DAT_00aaa640 ||

      ((DAT_00a11078 < unaff_ESI[0xf] || DAT_00a11078 == unaff_ESI[0xf] ||

       (unaff_ESI[0xf] <= _DAT_00a110e0)))))) {

    local_20 = unaff_ESI[0xc] * unaff_EDI[3] + unaff_ESI[4] * unaff_EDI[1] +

               unaff_ESI[8] * unaff_EDI[2] + *unaff_EDI * *unaff_ESI;

    local_1c = unaff_ESI[0xd] * unaff_EDI[3] + unaff_ESI[5] * unaff_EDI[1] +

               unaff_ESI[1] * *unaff_EDI + unaff_ESI[9] * unaff_EDI[2];

    local_18 = unaff_ESI[0xe] * unaff_EDI[3] + unaff_ESI[6] * unaff_EDI[1] +

               unaff_ESI[2] * *unaff_EDI + unaff_ESI[10] * unaff_EDI[2];

    fVar2 = unaff_ESI[0xf] * unaff_EDI[3] + unaff_ESI[7] * unaff_EDI[1] +

            unaff_ESI[0xb] * unaff_EDI[2] + *unaff_EDI * unaff_ESI[3];

  }

  else if ((_DAT_00a240ec < unaff_EDI[3] || _DAT_00a240ec == unaff_EDI[3]) ||

          (unaff_EDI[3] <= DAT_00aaa640)) {

    cVar1 = FUN_0040d450(unaff_EDI[3],0x3f800000,0x358637bd,0x358637bd);

    if (cVar1 == '\0') {

      local_20 = unaff_ESI[0xc] * unaff_EDI[3] + unaff_ESI[4] * unaff_EDI[1] +

                 unaff_ESI[8] * unaff_EDI[2] + *unaff_EDI * *unaff_ESI;

      local_1c = unaff_ESI[0xd] * unaff_EDI[3] + unaff_ESI[5] * unaff_EDI[1] +

                 unaff_ESI[1] * *unaff_EDI + unaff_ESI[9] * unaff_EDI[2];

      local_18 = unaff_ESI[0xe] * unaff_EDI[3] + unaff_ESI[6] * unaff_EDI[1] +

                 unaff_ESI[2] * *unaff_EDI + unaff_ESI[10] * unaff_EDI[2];

      fVar2 = unaff_EDI[3];

    }

    else {

      local_20 = unaff_ESI[4] * unaff_EDI[1] + unaff_ESI[8] * unaff_EDI[2] + *unaff_EDI * *unaff_ESI

                 + unaff_ESI[0xc];

      local_1c = unaff_ESI[5] * unaff_EDI[1] + unaff_ESI[1] * *unaff_EDI +

                 unaff_ESI[9] * unaff_EDI[2] + unaff_ESI[0xd];

      local_18 = unaff_ESI[6] * unaff_EDI[1] + unaff_ESI[2] * *unaff_EDI +

                 unaff_ESI[10] * unaff_EDI[2] + unaff_ESI[0xe];

      fVar2 = g_flOne;

    }

  }

  else {

    local_20 = unaff_ESI[4] * unaff_EDI[1] + unaff_ESI[8] * unaff_EDI[2] + *unaff_EDI * *unaff_ESI;

    local_1c = unaff_ESI[5] * unaff_EDI[1] + unaff_ESI[1] * *unaff_EDI + unaff_ESI[9] * unaff_EDI[2]

    ;

    local_18 = unaff_ESI[6] * unaff_EDI[1] + unaff_ESI[2] * *unaff_EDI +

               unaff_ESI[10] * unaff_EDI[2];

    fVar2 = 0.0;

  }

  *param_1 = local_20;

  param_1[1] = local_1c;

  param_1[2] = local_18;

  param_1[3] = fVar2;

  return param_1;

}
