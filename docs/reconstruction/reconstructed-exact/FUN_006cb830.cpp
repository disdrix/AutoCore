// =============================================================================
// FUN_006cb830
// -----------------------------------------------------------------------------
// Stable ID: aa_006cb830
// Address:   0x006cb830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cb830 @ 0x006cb830
// Stable ID: aa_006cb830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_006c89d0, FUN_006cb830.
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

void __thiscall FUN_006cb830(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  int iStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  

  fVar4 = (float10)(**(code **)(*param_1 + 0x30))(0,0);

  fStack_40 = (float)fVar4;

  if ((float)param_1[0x15] < g_flZero) {

    iVar2 = 0;

    fStack_3c = fStack_40;

    if (0 < param_1[3]) {

      do {

        iVar3 = 0;

        if (0 < param_1[4]) {

          do {

            fVar4 = (float10)(**(code **)(*param_1 + 0x30))(iVar2,iVar3);

            if (fVar4 <= (float10)fStack_40) {

              fStack_40 = (float)fVar4;

            }

            if ((float10)fStack_3c <= fVar4) {

              fStack_3c = (float)fVar4;

            }

            iVar3 = iVar3 + 1;

          } while (iVar3 < param_1[4]);

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < param_1[3]);

    }

    fVar1 = fStack_40 * (float)param_1[9];

    fStack_3c = fStack_3c * (float)param_1[9];

    fStack_40 = fVar1;

    if (fStack_3c <= fVar1) {

      fStack_40 = fStack_3c;

    }

    if (fStack_3c < fVar1) {

      fStack_3c = fVar1;

    }

    param_1[6] = (int)((fStack_40 + fStack_3c) * DAT_00a0f298);

    param_1[0x15] = (int)(fStack_3c - fStack_40);

  }

  iStack_34 = param_1[6];

  fStack_38 = (float)param_1[0x14] * DAT_00a0f298;

  fStack_24 = (float)param_1[0x15] * DAT_00a0f298;

  fStack_30 = (float)param_1[0x16] * DAT_00a0f298;

  fStack_2c = (float)param_1[0x17] * DAT_00a0f298;

  fStack_28 = fStack_38;

  fStack_20 = fStack_30;

  fStack_1c = fStack_2c;

  FUN_006c89d0(param_2,&fStack_28,&fStack_38,param_3,param_4);

  return;

}
