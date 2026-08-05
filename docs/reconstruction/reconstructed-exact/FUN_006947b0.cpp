// =============================================================================
// FUN_006947b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006947b0
// Address:   0x006947b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006947b0 @ 0x006947b0
// Stable ID: aa_006947b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×12, do×3, while×3, goto×2, for×1, return×1.
//  - Notable callees: FUN_006935a0×7, FUN_00694560, FUN_006947b0.
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

void FUN_006947b0(uint *param_1,uint param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  float *pfVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint local_4;

  

  uVar4 = ((int)(param_3 - param_2) / 0x60) * 0x30 + param_2;

  FUN_00694560(param_2,uVar4,param_3 - 0x30,param_4);

  for (local_4 = uVar4;

      ((param_2 < local_4 && (*(float *)(local_4 - 0xc) <= *(float *)(local_4 + 0x24))) &&

      (*(float *)(local_4 + 0x24) <= *(float *)(local_4 - 0xc))); local_4 = local_4 - 0x30) {

  }

  do {

    uVar3 = uVar4 + 0x30;

    uVar1 = uVar3;

    uVar5 = local_4;

    if ((param_3 <= uVar3) || (*(float *)(local_4 + 0x24) < *(float *)(uVar4 + 0x54))) break;

    pfVar2 = (float *)(uVar4 + 0x54);

    uVar4 = uVar3;

  } while (*(float *)(local_4 + 0x24) <= *pfVar2);

joined_r0x00694852:

  do {

    if (uVar1 < param_3) {

      uVar4 = uVar3;

      if (*(float *)(uVar5 + 0x24) <= *(float *)(uVar1 + 0x24)) {

        if (*(float *)(uVar5 + 0x24) < *(float *)(uVar1 + 0x24)) goto LAB_00694888;

        uVar4 = uVar3 + 0x30;

        FUN_006935a0(uVar3,uVar1);

      }

      uVar3 = uVar4;

      uVar1 = uVar1 + 0x30;

      goto joined_r0x00694852;

    }

LAB_00694888:

    if (param_2 < local_4) {

      pfVar2 = (float *)(local_4 - 0xc);

      do {

        if (*pfVar2 <= *(float *)(uVar5 + 0x24)) {

          if (*pfVar2 < *(float *)(uVar5 + 0x24)) break;

          uVar5 = uVar5 - 0x30;

          FUN_006935a0(uVar5,pfVar2 + -9);

        }

        local_4 = local_4 - 0x30;

        pfVar2 = pfVar2 + -0xc;

      } while (param_2 < local_4);

    }

    if (local_4 == param_2) {

      if (uVar1 == param_3) {

        *param_1 = uVar5;

        param_1[1] = uVar3;

        return;

      }

      if (uVar3 != uVar1) {

        FUN_006935a0(uVar5,uVar3);

      }

      uVar3 = uVar3 + 0x30;

      FUN_006935a0(uVar5,uVar1);

      uVar1 = uVar1 + 0x30;

      uVar5 = uVar5 + 0x30;

    }

    else {

      local_4 = local_4 - 0x30;

      if (uVar1 == param_3) {

        uVar5 = uVar5 - 0x30;

        if (local_4 != uVar5) {

          FUN_006935a0(local_4,uVar5);

        }

        uVar3 = uVar3 - 0x30;

        FUN_006935a0(uVar5,uVar3);

      }

      else {

        FUN_006935a0(uVar1,local_4);

        uVar1 = uVar1 + 0x30;

      }

    }

  } while( true );

}
