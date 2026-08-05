// =============================================================================
// FUN_0082aa20
// -----------------------------------------------------------------------------
// Stable ID: aa_0082aa20
// Address:   0x0082aa20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082aa20 @ 0x0082aa20
// Stable ID: aa_0082aa20
// Embedded strings (evidence for future rename):
//   - "macro"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×2.
//  - Notable callees: FUN_0082aa20, sprintf.
//  - Strings: "macro".
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

void __fastcall FUN_0082aa20(int *param_1)



{

  int iVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  char local_64 [100];

  

  if (param_1[0x148] < 0) {

    (**(code **)(*param_1 + 0xcc))(0);

    return;

  }

  if ((char)param_1[0x13f] == '\0') {

    if (param_1[0x14a] == 0) goto LAB_0082aa8f;

    uVar3 = 1;

  }

  else {

    if (param_1[0x14a] == 0) goto LAB_0082aa8f;

    uVar3 = 2;

  }

  iVar1 = *(int *)param_1[0x14a];

  uVar3 = (**(code **)(*param_1 + 0x164))(uVar3);

  (**(code **)(iVar1 + 0x154))(0,uVar3);

  (**(code **)(*(int *)param_1[0x14a] + 0x34c))();

LAB_0082aa8f:

  if (param_1[0x14b] != 0) {

    sprintf(local_64,"%d",param_1[0x148] + 1);

    (**(code **)(*(int *)param_1[0x14b] + 0x1d8))(local_64,1,1);

  }

  if (param_1[0x14a] != 0) {

    pcVar2 = (char *)param_1[0x146];

    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x14a] + 0x1d8))(pcVar2,1,1);

      (**(code **)(*(int *)param_1[0x14a] + 0x34c))();

      return;

    }

    (**(code **)(*(int *)param_1[0x14a] + 0x1d8))("macro",1,1);

    (**(code **)(*(int *)param_1[0x14a] + 0x34c))();

  }

  return;

}
