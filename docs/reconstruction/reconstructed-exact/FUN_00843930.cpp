// =============================================================================
// FUN_00843930
// -----------------------------------------------------------------------------
// Stable ID: aa_00843930
// Address:   0x00843930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00843930 @ 0x00843930
// Stable ID: aa_00843930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_007916e0, FUN_00843930.
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

void __thiscall FUN_00843930(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uStack_8;

  

  uVar1 = param_2;

  cVar2 = (**(code **)(*param_1 + 0xd0))();

  cVar3 = (char)param_2;

  if (cVar2 != cVar3) {

    param_2 = 0;

    if ((param_1[0x143] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x143] + 0xd0))(), cVar2 != '\0')) {

      param_2 = 1;

    }

    uStack_8 = 0;

    if ((param_1[0x144] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x144] + 0xd0))(), cVar2 != '\0')) {

      uStack_8 = 1;

    }

    if (param_1[0x146] != 0) {

      (**(code **)(*(int *)param_1[0x146] + 0xd0))();

    }

    FUN_007916e0(uVar1);

    if (cVar3 != '\0') {

      if (param_1[0x143] != 0) {

        (**(code **)(*(int *)param_1[0x143] + 0xcc))(param_2);

      }

      if (param_1[0x144] != 0) {

        (**(code **)(*(int *)param_1[0x144] + 0xcc))(uStack_8);

      }

      if (param_1[0x146] != 0) {

                    /* WARNING: Could not recover jumptable at 0x00843a1c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(*(int *)param_1[0x146] + 0xcc))();

        return;

      }

    }

  }

  return;

}
