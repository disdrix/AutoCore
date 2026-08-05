// =============================================================================
// FUN_006f0720
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0720
// Address:   0x006f0720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0720 @ 0x006f0720
// Stable ID: aa_006f0720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: ABS×3, CONCAT13, FUN_006f0720.
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

void __thiscall FUN_006f0720(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint uVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  float *pfVar6;

  float *pfVar7;

  undefined3 uStack_24;

  uint8_t uStack_21;

  

  pfVar7 = (float *)*param_2;

  uVar1 = param_2[1];

  if (-1 < (int)(uVar1 - 1)) {

    pfVar6 = (float *)(param_3 + 0xc);

    uStack_21 = (uint8_t)(uVar1 >> 0x18);

    do {

      fVar2 = ABS(*pfVar7 - *(float *)(param_1 + 0x20));

      fVar3 = ABS(pfVar7[1] - *(float *)(param_1 + 0x24));

      fVar4 = ABS(pfVar7[2] - *(float *)(param_1 + 0x28));

      uStack_24 = (undefined3)uVar1;

      if ((byte)((fVar4 < *(float *)(param_1 + 0x38) != (fVar4 == *(float *)(param_1 + 0x38))) << 1

                 | (fVar3 < *(float *)(param_1 + 0x34) != (fVar3 == *(float *)(param_1 + 0x34))) <<

                   2 | (fVar2 < *(float *)(param_1 + 0x30) != (fVar2 == *(float *)(param_1 + 0x30)))

                       * -8 & 0xeU) == 0xe) {

        pfVar6[-3] = *(float *)(param_1 + 0x10);

        pfVar6[-2] = *(float *)(param_1 + 0x14);

        pfVar6[-1] = *(float *)(param_1 + 0x18);

        *pfVar6 = *(float *)(param_1 + 0x1c);

        *pfVar6 = *pfVar7 * *(float *)(param_1 + 0x10) +

                  *(float *)(param_1 + 0x18) * pfVar7[2] + *(float *)(param_1 + 0x14) * pfVar7[1] +

                  *(float *)(param_1 + 0x1c);

      }

      else {

        *pfVar6 = 3.4028235e+38;

      }

      pfVar6 = pfVar6 + 4;

      pfVar7 = pfVar7 + 4;

      uVar5 = CONCAT13(uStack_21,uStack_24) - 1;

      uVar1 = uVar5 & 0xffffff;

      uStack_21 = (uint8_t)(uVar5 >> 0x18);

    } while (uVar5 != 0);

  }

  return;

}
