// =============================================================================
// FUN_0046b3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046b3c0
// Address:   0x0046b3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046b3c0 @ 0x0046b3c0
// Stable ID: aa_0046b3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×2, while×2.
//  - Notable callees: FUN_00435df0, FUN_00435f30, FUN_0046b3c0, FUN_00768760.
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

uint32_t /* width from decompiler */ __fastcall FUN_0046b3c0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_2 + 0x4044) == 0) {

    if (0xf < in_EAX) {

      uVar2 = FUN_00435f30(param_1,in_EAX * 4);

      return uVar2;

    }

    if (-1 < in_EAX + -1) {

      do {

        if ((*(int *)(param_2 + 0x18) + 4 <= *(int *)(param_2 + 0x20)) ||

           ((iVar1 = FUN_00435df0(*(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x18)), -1 < iVar1

            && (3 < *(int *)(param_2 + 0x20))))) {

          *param_1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c + *(int *)(param_2 + 0x18));

          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 4;

        }

        param_1 = param_1 + 1;

        in_EAX = in_EAX + -1;

      } while (in_EAX != 0);

      return 0;

    }

  }

  else if (-1 < in_EAX + -1) {

    do {

      FUN_00768760(param_1);

      param_1 = param_1 + 1;

      in_EAX = in_EAX + -1;

    } while (in_EAX != 0);

  }

  return 0;

}
