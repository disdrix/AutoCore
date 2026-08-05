// =============================================================================
// FUN_007795f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007795f0
// Address:   0x007795f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007795f0 @ 0x007795f0
// Stable ID: aa_007795f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×13, return×2, goto×2, do×1, while×1.
//  - Notable callees: FUN_00775f50×4, FUN_00774e60×3, FUN_00770250, FUN_00771cb0, FUN_00772250, FUN_00774b50, FUN_00775200, FUN_00775b30.
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

uint32_t /* width from decompiler */ __fastcall FUN_007795f0(int param_1)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  iVar1 = FUN_00771cb0(local_20,local_10,0);

  if (iVar1 != 0) {

    return 0xd;

  }

  if ((in_EAX[2] == 1) || (*in_EAX == 0)) {

    iVar1 = -3;

  }

  else {

    if ((*in_EAX < 1) || ((*(byte *)in_EAX[3] & 1) == 0)) {

      iVar1 = FUN_00775200(param_1 + 0x20);

    }

    else {

      iVar1 = FUN_00775b30(param_1 + 0x20);

    }

    if (iVar1 == 0) {

      iVar1 = FUN_00774b50(local_20,local_10);

      if (iVar1 == 0) {

        iVar1 = FUN_00775f50(local_10);

        if (iVar1 == 0) {

          iVar1 = FUN_00774e60(local_20,local_10,local_20);

          if (iVar1 == 0) {

            iVar1 = FUN_00775f50(local_20);

            if (iVar1 == 0) {

              iVar1 = FUN_00774e60(param_1,local_10,param_1);

              if (iVar1 == 0) {

                iVar1 = FUN_00775f50(param_1);

                if (iVar1 == 0) {

                  param_1 = param_1 + 0x10;

                  iVar1 = FUN_00774e60(param_1,local_20,param_1);

                  if (iVar1 == 0) {

                    iVar1 = FUN_00775f50(param_1);

                    if (iVar1 == 0) {

                      FUN_00770250();

                      uVar3 = 0;

                      goto LAB_00779747;

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }

  iVar2 = 0;

  do {

    if (iVar1 == (&DAT_00a240d0)[iVar2 * 2]) {

      uVar3 = *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar2 * 8);

      goto LAB_00779747;

    }

    iVar2 = iVar2 + 1;

  } while (iVar2 < 3);

  uVar3 = 1;

LAB_00779747:

  FUN_00772250(local_20,local_10,0);

  return uVar3;

}
