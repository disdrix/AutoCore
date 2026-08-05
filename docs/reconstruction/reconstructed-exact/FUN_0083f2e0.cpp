// =============================================================================
// FUN_0083f2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083f2e0
// Address:   0x0083f2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083f2e0 @ 0x0083f2e0
// Stable ID: aa_0083f2e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×18, return×2.
//  - Notable callees: FUN_007916e0, FUN_0083f2e0.
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

void __thiscall FUN_0083f2e0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  uint8_t uVar4;

  uint8_t uVar5;

  uint8_t uVar6;

  uint8_t uVar7;

  uint8_t uVar8;

  

  cVar1 = (**(code **)(*param_1 + 0xd0))();

  if (cVar1 != (char)param_2) {

    uVar2 = 0;

    uVar3 = 0;

    uVar4 = 0;

    uVar5 = 0;

    uVar6 = 0;

    uVar7 = 0;

    uVar8 = 0;

    if (param_1[0x2d5] != 0) {

      uVar2 = (**(code **)(*(int *)param_1[0x2d5] + 0xd0))();

    }

    if (param_1[0x2d6] != 0) {

      uVar3 = (**(code **)(*(int *)param_1[0x2d6] + 0xd0))();

    }

    if (param_1[0x2d9] != 0) {

      uVar4 = (**(code **)(*(int *)param_1[0x2d9] + 0xd0))();

    }

    if (param_1[0x2d8] != 0) {

      uVar5 = (**(code **)(*(int *)param_1[0x2d8] + 0xd0))();

    }

    if (param_1[0x2da] != 0) {

      uVar6 = (**(code **)(*(int *)param_1[0x2da] + 0xd0))();

    }

    if (param_1[0x2db] != 0) {

      uVar7 = (**(code **)(*(int *)param_1[0x2db] + 0xd0))();

    }

    if (param_1[0x2dc] != 0) {

      uVar8 = (**(code **)(*(int *)param_1[0x2dc] + 0xd0))();

    }

    if (param_1[0x2dd] != 0) {

      (**(code **)(*(int *)param_1[0x2dd] + 0xd0))();

    }

    FUN_007916e0(param_2);

    if ((char)param_2 != '\0') {

      if (param_1[0x2d5] != 0) {

        (**(code **)(*(int *)param_1[0x2d5] + 0xcc))(uVar2);

      }

      if (param_1[0x2d6] != 0) {

        (**(code **)(*(int *)param_1[0x2d6] + 0xcc))(uVar3);

      }

      if (param_1[0x2d9] != 0) {

        (**(code **)(*(int *)param_1[0x2d9] + 0xcc))(uVar4);

      }

      if (param_1[0x2d8] != 0) {

        (**(code **)(*(int *)param_1[0x2d8] + 0xcc))(uVar5);

      }

      if (param_1[0x2da] != 0) {

        (**(code **)(*(int *)param_1[0x2da] + 0xcc))(uVar6);

      }

      if (param_1[0x2db] != 0) {

        (**(code **)(*(int *)param_1[0x2db] + 0xcc))(uVar7);

      }

      if (param_1[0x2dc] != 0) {

        (**(code **)(*(int *)param_1[0x2dc] + 0xcc))(uVar8);

      }

      if (param_1[0x2dd] != 0) {

                    /* WARNING: Could not recover jumptable at 0x0083f4db. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(*(int *)param_1[0x2dd] + 0xcc))();

        return;

      }

    }

  }

  return;

}
