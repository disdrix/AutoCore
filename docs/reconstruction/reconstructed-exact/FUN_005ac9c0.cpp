// =============================================================================
// FUN_005ac9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ac9c0
// Address:   0x005ac9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ac9c0 @ 0x005ac9c0
// Stable ID: aa_005ac9c0
// Embedded strings (evidence for future rename):
//   - "CrazyTaxi mission without any taxi points."
//   - "Get to your next destination."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007a6de0×2, FUN_005ac9c0, FUN_007a69d0, sprintf, strncat.
//  - Strings: "CrazyTaxi mission without any taxi points."; "Get to your next destination.".
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

int __thiscall

FUN_005ac9c0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char *param_4,size_t param_5)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  local_208[0] = '\0';

  local_208[1] = '\0';

  puVar4 = local_206;

  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  FUN_007a69d0();

  if (*(int *)(param_1 + 0x58) < 1) {

    pcVar2 = (char *)FUN_007a6de0("CrazyTaxi mission without any taxi points.",0xffffffff);

  }

  else {

    pcVar2 = (char *)FUN_007a6de0("Get to your next destination.",0xffffffff);

  }

  sprintf(local_208,pcVar2);

  strncat(param_4,local_208,param_5);

  pcVar2 = local_208;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  return (int)pcVar2 - (int)(local_208 + 1);

}
