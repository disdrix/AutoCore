// =============================================================================
// FUN_00866c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00866c70
// Address:   0x00866c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00866c70 @ 0x00866c70
// Stable ID: aa_00866c70
// Embedded strings (evidence for future rename):
//   - "i_w_say.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_00866c70, FUN_0087b890, NDUIWindow_ReloadInterface.
//  - Strings: "i_w_say.xml".
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

uint32_t /* width from decompiler */ * FUN_00866c70(uint32_t /* width from decompiler */ *param_1)



{

  uint8_t *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8868;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a60904;

  *(uint8_t *)((int)param_1 + 0x526) = 0;

  *(uint8_t *)((int)param_1 + 0x53a) = 0;

  *(uint8_t *)((int)param_1 + 0x515) = 0;

  *(uint16_t *)(param_1 + 0x14e) = 0;

  param_1[0x144] = 6;

  *(uint8_t *)(param_1 + 0x145) = 0;

  puVar1 = (uint8_t *)((int)param_1 + 0x966);

  iVar2 = 100;

  do {

    puVar1[-0x14] = 0;

    *puVar1 = 0;

    puVar1[-0x25] = 0;

    *(uint16_t *)(puVar1 + -2) = 0;

    *(uint32_t /* width from decompiler */ *)(puVar1 + -0x2a) = 6;

    puVar1[-0x26] = 0;

    puVar1 = puVar1 + 0x418;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  param_1[0x68a9] = 0;

  param_1[0x68aa] = 0;

  param_1[0x68ab] = 0;

  param_1[0x68ac] = 0;

  param_1[0x68ad] = 0;

  param_1[0x68ae] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x68a8) = 0;

  param_1[0x144] = 10;

  *(uint8_t *)((int)param_1 + 0x515) = 0;

  *(uint8_t *)((int)param_1 + 0x526) = 0;

  *(uint8_t *)((int)param_1 + 0x53a) = 0;

  *(uint16_t *)(param_1 + 0x14e) = 0;

  *(uint8_t *)(param_1 + 0x249) = 0;

  NDUIWindow_ReloadInterface("i_w_say.xml");

  puVar3 = param_1 + 0x24e;

  for (iVar2 = 0x6658; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  param_1[0x68a6] = 0;

  param_1[0x68a7] = 0;

  ExceptionList = local_c;

  return param_1;

}
