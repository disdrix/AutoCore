// =============================================================================
// FUN_00962c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00962c80
// Address:   0x00962c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962c80 @ 0x00962c80
// Stable ID: aa_00962c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, while×2, return×1.
//  - Notable callees: SQRT×2, FUN_00962c80.
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

void FUN_00962c80(void)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x40);

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(in_EAX + 0x44)) {

    pfVar1 = (float *)(in_EAX + 0x18);

    pfVar2 = (float *)(in_EAX + 0x10);

    pfVar7 = (float *)(in_EAX + 0x1c);

    do {

      pfVar6 = (float *)*puVar5;

      pfVar8 = (float *)(in_EAX + 0xc);

      if (*pfVar6 < *(float *)(in_EAX + 0xc) || *pfVar6 == *(float *)(in_EAX + 0xc)) {

        pfVar8 = pfVar6;

      }

      *(float *)(in_EAX + 0xc) = *pfVar8;

      pfVar8 = pfVar6 + 3;

      if (pfVar6[3] <= *pfVar1 && *pfVar1 != pfVar6[3]) {

        pfVar8 = pfVar1;

      }

      *pfVar1 = *pfVar8;

      pfVar8 = pfVar6 + 1;

      if (*pfVar2 <= pfVar6[1] && pfVar6[1] != *pfVar2) {

        pfVar8 = pfVar2;

      }

      *pfVar2 = *pfVar8;

      pfVar8 = pfVar6 + 4;

      if (pfVar6[4] <= *pfVar7 && *pfVar7 != pfVar6[4]) {

        pfVar8 = pfVar7;

      }

      *pfVar7 = *pfVar8;

      pfVar8 = pfVar6 + 2;

      if (*(float *)(in_EAX + 0x14) <= pfVar6[2] && pfVar6[2] != *(float *)(in_EAX + 0x14)) {

        pfVar8 = (float *)(in_EAX + 0x14);

      }

      *(float *)(in_EAX + 0x14) = *pfVar8;

      pfVar6 = pfVar6 + 5;

      if (*pfVar6 <= *(float *)(in_EAX + 0x20) && *(float *)(in_EAX + 0x20) != *pfVar6) {

        pfVar6 = (float *)(in_EAX + 0x20);

      }

      *(float *)(in_EAX + 0x20) = *pfVar6;

      puVar5 = puVar5 + 1;

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(in_EAX + 0x44));

  }

  local_4 = DAT_00a0f298;

  puVar5 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x40);

  local_c = (*(float *)(in_EAX + 0x18) - *(float *)(in_EAX + 0xc)) * DAT_00a0f298;

  pfVar1 = (float *)(in_EAX + 0x24);

  *pfVar1 = local_c;

  local_8 = (*(float *)(in_EAX + 0x1c) - *(float *)(in_EAX + 0x10)) * local_4;

  *(float *)(in_EAX + 0x28) = local_8;

  local_4 = (*(float *)(in_EAX + 0x20) - *(float *)(in_EAX + 0x14)) * local_4;

  *(float *)(in_EAX + 0x2c) = local_4;

  pfVar2 = (float *)(in_EAX + 0x30);

  *pfVar2 = 0.0;

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(in_EAX + 0x44)) {

    do {

      pfVar6 = (float *)*puVar5;

      fVar4 = *(float *)(in_EAX + 0x28) - pfVar6[1];

      fVar3 = *(float *)(in_EAX + 0x2c) - pfVar6[2];

      local_10 = SQRT((*pfVar1 - *pfVar6) * (*pfVar1 - *pfVar6) + fVar4 * fVar4 + fVar3 * fVar3);

      pfVar7 = pfVar2;

      if (*pfVar2 <= local_10) {

        pfVar7 = &local_10;

      }

      *pfVar2 = *pfVar7;

      fVar4 = pfVar6[4] - *(float *)(in_EAX + 0x28);

      fVar3 = pfVar6[5] - *(float *)(in_EAX + 0x2c);

      local_10 = SQRT((pfVar6[3] - *pfVar1) * (pfVar6[3] - *pfVar1) + fVar4 * fVar4 + fVar3 * fVar3)

      ;

      pfVar7 = pfVar2;

      if (*pfVar2 <= local_10) {

        pfVar7 = &local_10;

      }

      puVar5 = puVar5 + 1;

      *pfVar2 = *pfVar7;

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(in_EAX + 0x44));

  }

  return;

}
