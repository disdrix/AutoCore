// =============================================================================
// FUN_0051f230
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f230
// Address:   0x0051f230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f230 @ 0x0051f230
// Stable ID: aa_0051f230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×3, switch×1, return×1.
//  - Notable callees: FUN_0051f230.
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

void FUN_0051f230(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  uVar1 = 0;

  uVar2 = 0;

  uVar3 = 0;

  switch(param_1) {

  case 0:

    uVar2 = 0;

    uVar3 = 0;

    break;

  case 1:

    uVar1 = DAT_009ceea8;

    uVar2 = DAT_009ceedc;

    uVar3 = DAT_009ceedc;

    break;

  case 2:

    uVar1 = DAT_009ceedc;

    uVar2 = DAT_009ceea8;

    uVar3 = DAT_009ceedc;

    break;

  case 3:

    uVar1 = DAT_009ceedc;

    uVar2 = DAT_009ceedc;

    uVar3 = DAT_009ceea8;

    break;

  case 4:

    uVar1 = DAT_00aaac18;

    uVar2 = DAT_00aaac1c;

    uVar3 = DAT_009ceed8;

    break;

  case 5:

    uVar1 = DAT_00aaac1c;

    uVar2 = DAT_00aaac18;

    uVar3 = DAT_009ceed8;

    break;

  case 6:

    uVar1 = DAT_00aaac1c;

    uVar2 = DAT_009ceed8;

    uVar3 = DAT_00aaac18;

    break;

  case 7:

    uVar1 = DAT_00aaac18;

    uVar2 = DAT_009ceed8;

    uVar3 = DAT_00aaac1c;

    break;

  case 8:

    uVar1 = DAT_009ceed8;

    uVar2 = DAT_00aaac18;

    uVar3 = DAT_00aaac1c;

    break;

  case 9:

    uVar1 = DAT_009ceed8;

    uVar2 = DAT_00aaac1c;

    uVar3 = DAT_00aaac18;

  }

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_2 = uVar1;

  }

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_3 = uVar2;

  }

  if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_4 = uVar3;

  }

  return;

}
