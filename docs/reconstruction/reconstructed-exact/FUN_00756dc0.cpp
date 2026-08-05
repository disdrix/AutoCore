// =============================================================================
// FUN_00756dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00756dc0
// Address:   0x00756dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756dc0 @ 0x00756dc0
// Stable ID: aa_00756dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00756dc0, FUN_00973690.
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

int __fastcall FUN_00756dc0(int param_1,float *param_2,float *param_3)



{

  bool bVar1;

  float *in_EAX;

  float *pfVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float in_XMM5_Da;

  int local_c;

  int local_8;

  

  fVar6 = 0.0;

  pfVar2 = in_EAX + param_1 * 6 + -6;

  fVar4 = in_EAX[param_1 * 6 + -5] * param_3[1] + in_EAX[param_1 * 6 + -6] * *param_3 + in_XMM5_Da;

  bVar3 = 0.0 <= fVar4;

  local_c = 0;

  local_8 = param_1;

  if (0 < param_1) {

    do {

      if (bVar3 != false) {

        *param_2 = *pfVar2;

        param_2[1] = pfVar2[1];

        param_2[2] = pfVar2[2];

        param_2[3] = pfVar2[3];

        param_2[4] = pfVar2[4];

        local_c = local_c + 1;

        param_2[5] = pfVar2[5];

        param_2 = param_2 + 6;

      }

      fVar5 = *param_3 * *in_EAX + in_EAX[1] * param_3[1] + in_XMM5_Da;

      bVar1 = fVar6 <= fVar5;

      if (bVar3 != bVar1) {

        fVar4 = fVar6 - fVar4 / (fVar5 - fVar4);

        *param_2 = (*in_EAX - *pfVar2) * fVar4 + *pfVar2;

        param_2[1] = (in_EAX[1] - pfVar2[1]) * fVar4 + pfVar2[1];

        param_2[4] = (in_EAX[4] - pfVar2[4]) * fVar4 + pfVar2[4];

        param_2[5] = (in_EAX[5] - pfVar2[5]) * fVar4 + pfVar2[5];

        FUN_00973690(fVar4,pfVar2[3],in_EAX[3]);

        param_2 = param_2 + 6;

        local_c = local_c + 1;

      }

      fVar4 = fVar5;

      local_8 = local_8 + -1;

      pfVar2 = in_EAX;

      in_EAX = in_EAX + 6;

      bVar3 = bVar1;

    } while (local_8 != 0);

    return local_c;

  }

  return 0;

}
