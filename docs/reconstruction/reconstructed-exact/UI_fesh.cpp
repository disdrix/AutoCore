// =============================================================================
// UI_fesh
// -----------------------------------------------------------------------------
// Stable ID: aa_008cb8c0
// Address:   0x008cb8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_fesh @ 0x008cb8c0
// Stable ID: aa_008cb8c0
// Embedded strings (evidence for future rename):
//   - "i_d_fesh.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_0087b890, FUN_008cafd0, UI_fesh, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_fesh.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_fesh.xml"
 * Domain alias of FUN_008cb8c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_fesh(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b6d4c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a4183c;

  puVar1 = param_1 + 0x158;

  iVar2 = 0x10;

  do {

    puVar1[1] = 0xffffffff;

    puVar1[2] = 0;

    *(uint16_t *)(puVar1 + 3) = 0;

    *(uint8_t *)(puVar1 + 5) = 0;

    *(uint8_t *)((int)puVar1 + 3) = 0;

    *(uint8_t *)((int)puVar1 + 2) = 0;

    *(uint8_t *)((int)puVar1 + 1) = 0;

    *(uint8_t *)puVar1 = 0;

    puVar1 = puVar1 + 0xf;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  param_1[0x13f] = 0xf;

  param_1[0x140] = 0;

  param_1[0x252] = 0;

  param_1[0x253] = 0;

  FUN_008cafd0();

  param_1[0x154] = 0xffffffff;

  param_1[0x155] = 0xffffffff;

  param_1[0x248] = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  param_1[0x156] = 0;

  param_1[0x157] = 0;

  puVar1 = param_1 + 0x15d;

  iVar2 = 0x10;

  do {

    puVar1[-4] = 0xffffffff;

    *(uint8_t *)puVar1 = 0;

    *(uint16_t *)(puVar1 + -2) = 0;

    puVar1 = puVar1 + 0xf;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  NDUIWindow_ReloadInterface("i_d_fesh.xml");

  ExceptionList = local_c;

  return param_1;

}
