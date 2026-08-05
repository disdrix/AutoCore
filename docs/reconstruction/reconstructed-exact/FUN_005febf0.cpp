// =============================================================================
// FUN_005febf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005febf0
// Address:   0x005febf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005febf0 @ 0x005febf0
// Stable ID: aa_005febf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: CreateSimpleObject_Serialize, FUN_005febf0.
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

uint32_t /* width from decompiler */ __thiscall

FUN_005febf0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  

  CreateSimpleObject_Serialize(param_2,param_3,param_4);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  *param_2 = 0x2060;

  param_2[0x36] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x30);

  param_2[0x37] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c);

  param_2[0x38] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x28);

  param_2[0x39] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x24);

  param_2[0x3a] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x20);

  pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1)

                               + 0x15c))();

  pcVar3 = (char *)(param_2 + 0x3c);

  do {

    cVar1 = *pcVar2;

    *pcVar3 = cVar1;

    pcVar2 = pcVar2 + 1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  param_2[0x3b] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1);

  *(uint8_t *)(param_2 + 0x28) = 0;

  *(uint16_t *)(param_2 + 0x55) = *(uint16_t *)(param_1 + -0x14);

  return 0x158;

}
