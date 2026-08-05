// =============================================================================
// FUN_0084af70
// -----------------------------------------------------------------------------
// Stable ID: aa_0084af70
// Address:   0x0084af70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084af70 @ 0x0084af70
// Stable ID: aa_0084af70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_007916e0, FUN_0084af70.
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

void __thiscall FUN_0084af70(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uVar1 = param_2;

  cVar2 = (**(code **)(*param_1 + 0xd0))();

  cVar3 = (char)param_2;

  if (cVar2 != cVar3) {

    param_2 = 0;

    if ((param_1[0x159] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x159] + 0xd0))(), cVar2 != '\0')) {

      param_2 = 1;

    }

    uStack_10 = 0;

    if ((param_1[0x156] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x156] + 0xd0))(), cVar2 != '\0')) {

      uStack_10 = 1;

    }

    uStack_c = 0;

    if ((param_1[0x151] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x151] + 0xd0))(), cVar2 != '\0')) {

      uStack_c = 1;

    }

    uStack_8 = 0;

    if ((param_1[0x155] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x155] + 0xd0))(), cVar2 != '\0')) {

      uStack_8 = 1;

    }

    uStack_4 = 0;

    if ((param_1[0x157] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x157] + 0xd0))(), cVar2 != '\0')) {

      uStack_4 = 1;

    }

    FUN_007916e0(uVar1);

    if (cVar3 != '\0') {

      if (param_1[0x159] != 0) {

        (**(code **)(*(int *)param_1[0x159] + 0xcc))(param_2);

      }

      if (param_1[0x156] != 0) {

        (**(code **)(*(int *)param_1[0x156] + 0xcc))(uStack_10);

      }

      if (param_1[0x151] != 0) {

        (**(code **)(*(int *)param_1[0x151] + 0xcc))(uStack_c);

      }

      if (param_1[0x155] != 0) {

        (**(code **)(*(int *)param_1[0x155] + 0xcc))(uStack_8);

      }

      if (param_1[0x157] != 0) {

        (**(code **)(*(int *)param_1[0x157] + 0xcc))(uStack_4);

      }

      if (param_1[0x158] != 0) {

        (**(code **)(*(int *)param_1[0x158] + 0xcc))(uStack_4);

      }

    }

  }

  return;

}
