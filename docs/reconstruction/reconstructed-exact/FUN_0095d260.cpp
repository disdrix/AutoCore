// =============================================================================
// FUN_0095d260
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d260
// Address:   0x0095d260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095d260 @ 0x0095d260
// Stable ID: aa_0095d260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×19, do×1, while×1, return×1.
//  - Notable callees: FUN_00435df0×8, FUN_007693e0×6, FUN_00445170×2, FUN_007689e0×2, FUN_00768ee0×2, FUN_00417190, FUN_0095d260.
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

uint32_t /* width from decompiler */ __thiscall FUN_0095d260(int param_1,uint param_2)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint8_t local_15;

  uint8_t local_14 [4];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  uint8_t local_7;

  uint16_t local_6;

  uint16_t local_4;

  uint8_t local_2 [2];

  

  uVar1 = param_2;

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00445170(&param_2);

  }

  else {

    FUN_007693e0(&param_2);

  }

  if (*(int *)(uVar1 + 0x4044) == 0) {

    FUN_00445170(&local_15);

  }

  else {

    FUN_007693e0(&local_15);

  }

  uVar2 = param_2 & 0xff;

  if (uVar2 != 0) {

    param_2 = param_1 + 0x10;

    do {

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (0 < *(int *)(uVar1 + 0x20))))) {

          local_14[0] = *(uint8_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;

        }

      }

      else {

        FUN_007693e0(local_14);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 4 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (3 < *(int *)(uVar1 + 0x20))))) {

          local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 4;

        }

      }

      else {

        FUN_007689e0(&local_10);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 4 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (3 < *(int *)(uVar1 + 0x20))))) {

          local_c = *(uint32_t /* width from decompiler */ *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 4;

        }

      }

      else {

        FUN_007689e0(&local_c);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (0 < *(int *)(uVar1 + 0x20))))) {

          local_8 = *(uint8_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;

        }

      }

      else {

        FUN_007693e0(&local_8);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (0 < *(int *)(uVar1 + 0x20))))) {

          local_7 = *(uint8_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;

        }

      }

      else {

        FUN_007693e0(&local_7);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 2 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (1 < *(int *)(uVar1 + 0x20))))) {

          local_6 = *(uint16_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 2;

        }

      }

      else {

        FUN_00768ee0(&local_6);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 2 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (1 < *(int *)(uVar1 + 0x20))))) {

          local_4 = *(uint16_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 2;

        }

      }

      else {

        FUN_00768ee0(&local_4);

      }

      if (*(int *)(uVar1 + 0x4044) == 0) {

        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||

           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&

            (0 < *(int *)(uVar1 + 0x20))))) {

          local_2[0] = *(uint8_t *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);

          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;

        }

      }

      else {

        FUN_007693e0(local_2);

      }

      FUN_00417190();

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  return 0;

}
