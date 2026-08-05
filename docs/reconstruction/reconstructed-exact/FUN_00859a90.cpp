// =============================================================================
// FUN_00859a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00859a90
// Address:   0x00859a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00859a90 @ 0x00859a90
// Stable ID: aa_00859a90
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, switch×1, return×1.
//  - Notable callees: FUN_007a4480, FUN_0084fe60, FUN_008572f0, FUN_00859260, FUN_00859a90.
//  - Strings: "VOG_DEBUG_STOP".
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

void FUN_00859a90(uint32_t /* width from decompiler */ param_1,char param_2)



{

  char cVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t *puVar3;

  uint8_t local_14 [4];

  uint8_t local_10 [16];

  

  param_1 = 0;

  switch(param_2) {

  case '\0':

  case '\x01':

  case '\x02':

  case 'd':

  case 'e':

    param_1 = 1;

  }

  FUN_0084fe60();

  if ((param_2 == 'd') || (param_2 == 'e')) {

    param_2 = '\x01';

  }

  else if ('\x13' < param_2) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  cVar1 = FUN_008572f0(param_2,local_10);

  if (cVar1 == '\0') {

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5d4 + param_2 * 4);

    puVar3 = (uint8_t *)0x0;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x648);

    puVar3 = local_10;

  }

  FUN_00859260(unaff_EDI,local_14,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x538),

               *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x53c),uVar2,param_1,puVar3);

  return;

}
