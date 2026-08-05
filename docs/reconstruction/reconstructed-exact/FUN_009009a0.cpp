// =============================================================================
// FUN_009009a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009009a0
// Address:   0x009009a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009009a0 @ 0x009009a0
// Stable ID: aa_009009a0
// Embedded strings (evidence for future rename):
//   - "Your Money: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004fcd80, FUN_0078bd40, FUN_0078bd70, FUN_0078bde0, FUN_007a69d0, FUN_007a6de0, FUN_00833a90, FUN_00833e30.
//  - Strings: "Your Money: ".
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

void __fastcall FUN_009009a0(int *param_1)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 != '\0') {

    FUN_007a69d0();

    FUN_008fe650(param_1);

    if (DAT_00d1b6d8 != 0) {

      iVar1 = param_1[0x1cc];

      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x508) == 0)) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0))

      {

        FUN_00833e30(*(int *)(DAT_00d1b6d8 + 0x250));

        FUN_008fee00(param_1);

        *(uint32_t /* width from decompiler */ *)(param_1[0x1cc] + 0x488) = 1;

        FUN_0078bd70();

        FUN_0078bde0();

        FUN_0078bd40();

        if (*(int *)(iVar1 + 0x508) != 0) {

          FUN_00833a90(0x3fc00000);

          FUN_004fcd80(0);

        }

      }

      if (param_1[0x1c9] != 0) {

        (**(code **)(*(int *)param_1[0x1c9] + 0x1d8))(0,1,1);

        iVar1 = *(int *)param_1[0x1c9];

        uVar3 = FUN_007a6de0("Your Money: ",0xffffffff);

        (**(code **)(iVar1 + 0x250))(uVar3);

        if (DAT_00d1b6d8 != 0) {

          FUN_00977a30(DAT_00d1ad30,

                       *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728),

                       (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                       (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)));

        }

        (**(code **)(*(int *)param_1[0x1c9] + 0x34c))();

      }

      FUN_008fe4e0();

      FUN_008fdb60(param_1);

    }

  }

  return;

}
