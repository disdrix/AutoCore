// =============================================================================
// FUN_0041a0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a0b0
// Address:   0x0041a0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041a0b0 @ 0x0041a0b0
// Stable ID: aa_0041a0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, while×3, do×1.
//  - Notable callees: FUN_004236f0×13, FUN_00423890×13, FUN_004236a0×3, FUN_0041a0b0, FUN_004238b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0041a0b0(int param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bcea0;

  local_10 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_10;

  if (param_3 == '\0') {

    ExceptionList = &local_10;

    FUN_004238b0();

  }

  uVar2 = FUN_00423890();

  FUN_004236f0(param_2,uVar2);

  FUN_004236a0();

  uVar2 = FUN_00423890();

  FUN_004236f0(param_2,uVar2);

  uVar2 = FUN_00423890();

  FUN_004236f0(param_2,uVar2);

  FUN_004236a0();

  uVar2 = FUN_00423890();

  FUN_004236f0(param_2,uVar2);

  uVar2 = FUN_00423890();

  FUN_004236f0(param_2,uVar2);

  uVar4 = 1;

  do {

    if (*(uint *)(param_1 + 0xc) < uVar4) {

      uVar2 = FUN_00423890();

      FUN_004236f0(param_2,uVar2);

      ExceptionList = local_10;

      return 0;

    }

    if (*(char *)(param_1 + 0x1c) != '\0') {

      uVar3 = 0;

      while ((uVar3 < *(uint *)(param_1 + 0xc) &&

             (*(uint *)(uVar3 * 0x30 + 8 + *(int *)(param_1 + 0x14)) != uVar4))) {

        uVar3 = uVar3 + 1;

      }

    }

    uVar2 = FUN_00423890();

    FUN_004236f0(param_2,uVar2);

    uVar2 = FUN_00423890();

    FUN_004236f0(param_2,uVar2);

    uVar2 = FUN_00423890();

    FUN_004236f0(param_2,uVar2);

    if (*(char *)(param_1 + 0x1c) == '\0') {

      iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 8);

      if ((uint)(*(int *)(param_1 + 0xc) + -1 + iVar1) < uVar4) {

        ExceptionList = local_10;

        return 0x80004005;

      }

      uVar3 = uVar4 - iVar1;

    }

    else {

      uVar3 = 0;

      while( true ) {

        if (*(uint *)(param_1 + 0xc) <= uVar3) {

          ExceptionList = local_10;

          return 0x80004005;

        }

        if (*(uint *)(uVar3 * 0x30 + 8 + *(int *)(param_1 + 0x14)) == uVar4) break;

        uVar3 = uVar3 + 1;

      }

    }

    if (*(int *)(*(int *)(param_1 + 8) +

                (*(int *)(uVar3 * 0x30 + 4 + *(int *)(param_1 + 0x14)) + 3 +

                 *(int *)(uVar3 * 0x30 + *(int *)(param_1 + 0x14) + 0x10) & 0xfffffffcU) + 4) != 3)

    {

      FUN_004236a0();

      uVar2 = FUN_00423890();

      FUN_004236f0(param_2,uVar2);

    }

    uVar2 = FUN_00423890();

    FUN_004236f0(param_2,uVar2);

    uVar2 = FUN_00423890();

    FUN_004236f0(param_2,uVar2);

    uVar2 = FUN_00423890();

    FUN_004236f0(param_2,uVar2);

    uVar4 = uVar4 + 1;

  } while( true );

}
