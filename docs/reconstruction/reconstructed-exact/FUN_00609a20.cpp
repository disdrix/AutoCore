// =============================================================================
// FUN_00609a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00609a20
// Address:   0x00609a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00609a20 @ 0x00609a20
// Stable ID: aa_00609a20
// Embedded strings (evidence for future rename):
//   - "Powerplant modifier %d does not exist for item %d %I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_004ce940, FUN_00508b60, FUN_00609a20, FUN_007a4480.
//  - Strings: "Powerplant modifier %d does not exist for item %d %I64d".
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

float10 __fastcall FUN_00609a20(int param_1)



{

  int iVar1;

  uint16_t uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  

  FUN_004ce940();

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) +

                           0x3c) + 0x3ac);

  uVar5 = 0;

  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0x60))

                    ();

  if (iVar3 != 0) {

    do {

      uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) +

                          0x5c))(uVar5);

      iVar3 = FUN_00508b60(uVar2);

      if (iVar3 == 0) {

        iVar3 = *(int *)(*(int *)(param_1 + -0xdc) + 4);

        uVar2 = (**(code **)(*(int *)(iVar3 + param_1 + -0xdc) + 0x5c))

                          (uVar5,*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + -0x34 + param_1) + 0x34),

                           *(uint32_t /* width from decompiler */ *)(iVar3 + param_1 + 0x84),

                           *(uint32_t /* width from decompiler */ *)(iVar3 + 0x88 + param_1));

        FUN_007a4480(1,"Powerplant modifier %d does not exist for item %d %I64d",uVar2);

      }

      uVar5 = uVar5 + 1;

      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) +

                          0x60))();

    } while (uVar5 < uVar4);

  }

  return (float10)iVar1;

}
