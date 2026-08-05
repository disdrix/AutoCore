// =============================================================================
// FUN_004337d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004337d0
// Address:   0x004337d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004337d0 @ 0x004337d0
// Stable ID: aa_004337d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_004337d0.
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

void __fastcall FUN_004337d0(int param_1,uint param_2,int param_3)



{

  byte in_AL;

  byte bVar1;

  char cVar2;

  byte bVar3;

  byte *pbVar4;

  

  if ((((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x28) != 0)) && (-1 < (int)param_2)) &&

     (((-1 < param_3 && ((int)param_2 < *(int *)(param_1 + 0xc))) &&

      (param_3 < *(int *)(param_1 + 0x10))))) {

    if (*(short *)(param_1 + 0x16) == 8) {

      *(byte *)(*(int *)(param_1 + 0x30) * param_3 + *(int *)(param_1 + 0x34) + param_2) = in_AL;

      return;

    }

    pbVar4 = (byte *)(((int)(*(ushort *)(param_1 + 0x16) * param_2) >> 3) +

                      *(int *)(param_1 + 0x30) * param_3 + *(int *)(param_1 + 0x34));

    if (*(ushort *)(param_1 + 0x16) == 4) {

      param_2 = param_2 & 0x80000001;

      if ((int)param_2 < 0) {

        param_2 = (param_2 - 1 | 0xfffffffe) + 1;

      }

      cVar2 = '\x0f';

      bVar1 = ('\x01' - (char)param_2) * '\x04';

      bVar3 = 0xf;

    }

    else {

      if (*(short *)(param_1 + 0x16) != 1) {

        return;

      }

      param_2 = param_2 & 0x80000007;

      if ((int)param_2 < 0) {

        param_2 = (param_2 - 1 | 0xfffffff8) + 1;

      }

      bVar1 = 7 - (char)param_2;

      cVar2 = '\x01';

      bVar3 = 1;

    }

    *pbVar4 = ~(cVar2 << (bVar1 & 0x1f)) & *pbVar4 | (in_AL & bVar3) << (bVar1 & 0x1f);

  }

  return;

}
