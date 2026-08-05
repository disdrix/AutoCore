// =============================================================================
// FUN_0046fc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0046fc80
// Address:   0x0046fc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046fc80 @ 0x0046fc80
// Stable ID: aa_0046fc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00476d60×2, FUN_0046fc80.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0046fc80(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,

                 int param_7,int param_8,int param_9)



{

  float fVar1;

  int in_EAX;

  

  if ((param_1 != 0) && (in_EAX != 0)) {

    if (((-1 < param_2) && (((-1 < param_3 && (-1 < param_4)) && (-1 < param_5)))) &&

       ((((-1 < param_6 && (-1 < param_7)) && (-1 < param_8)) && (-1 < param_9)))) {

      if ((((double)param_2 <= _DAT_00aaa618) && ((double)param_3 <= _DAT_00aaa618)) &&

         (((double)param_4 <= _DAT_00aaa618 &&

          (((((double)param_5 <= _DAT_00aaa618 && ((double)param_6 <= _DAT_00aaa618)) &&

            ((double)param_7 <= _DAT_00aaa618)) &&

           (((double)param_8 <= _DAT_00aaa618 && ((float)param_9 <= (float)_DAT_00aaa618)))))))) {

        fVar1 = (float)_DAT_00aaa600;

        *(uint *)(in_EAX + 8) = *(uint *)(in_EAX + 8) | 4;

        *(float *)(in_EAX + 0x80) = (float)param_2 * fVar1;

        *(int *)(in_EAX + 0x100) = param_2;

        fVar1 = (float)_DAT_00aaa600;

        *(int *)(in_EAX + 0x104) = param_3;

        *(float *)(in_EAX + 0x84) = (float)param_3 * fVar1;

        *(int *)(in_EAX + 0x108) = param_4;

        *(float *)(in_EAX + 0x88) = (float)param_4 * (float)_DAT_00aaa600;

        *(int *)(in_EAX + 0x10c) = param_5;

        *(int *)(in_EAX + 0x110) = param_6;

        fVar1 = (float)_DAT_00aaa600;

        *(int *)(in_EAX + 0x114) = param_7;

        *(float *)(in_EAX + 0x8c) = (float)param_5 * fVar1;

        *(int *)(in_EAX + 0x118) = param_8;

        *(int *)(in_EAX + 0x11c) = param_9;

        *(float *)(in_EAX + 0x90) = (float)param_6 * (float)_DAT_00aaa600;

        *(float *)(in_EAX + 0x94) = (float)param_7 * (float)_DAT_00aaa600;

        *(float *)(in_EAX + 0x98) = (float)param_8 * (float)_DAT_00aaa600;

        *(float *)(in_EAX + 0x9c) = (float)param_9 * (float)_DAT_00aaa600;

        return;

      }

      FUN_00476d60();

      return;

    }

    FUN_00476d60();

  }

  return;

}
