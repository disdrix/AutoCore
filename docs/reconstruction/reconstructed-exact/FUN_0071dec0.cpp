// =============================================================================
// FUN_0071dec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071dec0
// Address:   0x0071dec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071dec0 @ 0x0071dec0
// Stable ID: aa_0071dec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00435df0×2, FUN_007693e0×2, FUN_00445170, FUN_00480ca0, FUN_00718fd0, FUN_0071dec0, FUN_007689e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0071dec0(int param_1,uint param_2)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint8_t local_c [4];

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4 [4];

  

  uVar1 = param_2;

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00445170(&param_2);

  }

  else {

    FUN_007693e0(&param_2);

  }

  uVar2 = param_2 & 0xff;

  if (uVar2 != 0) {

    param_2 = param_1 + 0x10;

    do {

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (0 < *(int *)(uVar1 + 0x20))))) {

          local_c[0] = *(uint8_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;

        }

      }

      else {

        FUN_007693e0(local_c);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 4 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (3 < *(int *)(uVar1 + 0x20))))) {

          local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 4;

        }

      }

      else {

        FUN_007689e0(&local_8);

      }

      FUN_00718fd0(uVar1,local_4);

      FUN_00480ca0();

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  return 0;

}
