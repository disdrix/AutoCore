// =============================================================================
// FUN_0056a570
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a570
// Address:   0x0056a570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a570 @ 0x0056a570
// Stable ID: aa_0056a570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: CreateSimpleObject_Serialize, FUN_0056a570.
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

FUN_0056a570(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  

  CreateSimpleObject_Serialize(param_2,param_3,param_4);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  *param_2 = 0x201c;

  param_2[0x45] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x20);

  param_2[0x46] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c);

  param_2[0x47] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x18);

  param_2[0x42] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c);

  param_2[0x43] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x28);

  param_2[0x44] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x24);

  pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1

                                        ) + 0x15c))();

  pcVar3 = (char *)(param_2 + 0x48);

  do {

    cVar1 = *pcVar2;

    *pcVar3 = cVar1;

    pcVar2 = pcVar2 + 1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  param_2[0x3d] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x80);

  param_2[0x3f] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c);

  param_2[0x40] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x68);

  param_2[0x41] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x74);

  param_2[0x36] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x54);

  param_2[0x37] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x50);

  param_2[0x38] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x4c);

  param_2[0x39] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x48);

  *(uint16_t *)(param_2 + 0x3a) = *(uint16_t *)(param_1 + -0x44);

  param_2[0x3b] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x40);

  *(uint16_t *)(param_2 + 0x3c) = *(uint16_t *)(param_1 + -0x38);

  *(uint8_t *)(param_2 + 0x28) = 0;

  return 0x188;

}
