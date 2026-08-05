// =============================================================================
// FUN_006c8860
// -----------------------------------------------------------------------------
// Stable ID: aa_006c8860
// Address:   0x006c8860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c8860 @ 0x006c8860
// Stable ID: aa_006c8860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×8, goto×4, return×2, do×1, while×1.
//  - Notable callees: FUN_006c8860.
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

void __thiscall FUN_006c8860(int param_1,uint8_t *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  local_24 = param_4[5];

  iVar4 = *(int *)(param_1 + 0xd8) + -1;

  local_28 = -1.0;

  if (-1 < iVar4) {

    pfVar3 = (float *)(iVar4 * 0x10 + *(int *)(param_1 + 0xd4));

    do {

      fVar2 = param_3[2] * pfVar3[2] + *pfVar3 * *param_3 + pfVar3[1] * param_3[1] + pfVar3[3];

      fVar1 = *pfVar3 * param_3[4] + param_3[6] * pfVar3[2] + param_3[5] * pfVar3[1] + pfVar3[3];

      if (fVar2 < g_flZero) {

        if (g_flZero <= fVar1) {

          fVar2 = fVar2 / (fVar2 - fVar1);

          if (local_24 < fVar2) goto LAB_006c8945;

          goto LAB_006c8947;

        }

      }

      else {

        if (g_flZero <= fVar1) goto LAB_006c89b5;

        fVar2 = fVar2 / (fVar2 - fVar1);

        if (local_28 < fVar2 == (local_28 == fVar2)) {

LAB_006c8945:

          fVar2 = local_24;

        }

        else {

          local_20 = *pfVar3;

          local_1c = pfVar3[1];

          local_18 = pfVar3[2];

          local_14 = pfVar3[3];

          local_28 = fVar2;

          fVar2 = local_24;

        }

LAB_006c8947:

        local_24 = fVar2;

        if (local_24 < local_28) goto LAB_006c89b5;

      }

      iVar4 = iVar4 + -1;

      pfVar3 = pfVar3 + -4;

    } while (-1 < iVar4);

    if (g_flZero <= local_28) {

      *param_4 = local_20;

      param_4[1] = local_1c;

      param_4[2] = local_18;

      param_4[3] = local_14;

      param_4[5] = local_28;

      param_4[4] = -NAN;

      *param_2 = 1;

      return;

    }

  }

LAB_006c89b5:

  *param_2 = 0;

  return;

}
