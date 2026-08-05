// =============================================================================
// FUN_00499580
// -----------------------------------------------------------------------------
// Stable ID: aa_00499580
// Address:   0x00499580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00499580 @ 0x00499580
// Stable ID: aa_00499580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~224 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00499580, FUN_005b8240.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00499580(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a0e6e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005b8240();

  *param_1 = &PTR_LAB_009c7bcc;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  iVar7 = g_nInferredThreatDefault;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  uVar8 = DAT_00aaab3c;

  uVar5 = DAT_00a0f524;

  uVar4 = DAT_00a0f520;

  uVar3 = DAT_00a0f298;

  uVar2 = DAT_009c7b80;

  uVar1 = DAT_009c7b7c;

  param_1[0x49] = 0;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  uVar6 = DAT_00a10e78;

  param_1[0x4e] = 0;

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = 0;

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  param_1[0x5a] = 0;

  puVar10 = param_1 + 0x12;

  for (iVar9 = 0x4a; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  param_1[0x28] = iVar7;

  param_1[0x29] = DAT_00aaa8dc;

  param_1[0x21] = 0x7fff;

  param_1[0x22] = uVar5;

  param_1[0x23] = uVar4;

  param_1[0x24] = uVar8;

  param_1[0x25] = uVar2;

  param_1[0x26] = uVar1;

  param_1[0x27] = 0x10;

  param_1[0x2a] = 0;

  param_1[0x2d] = 0;

  param_1[0x2c] = 0;

  param_1[0x2b] = 0;

  param_1[0x2e] = uVar3;

  param_1[0x2f] = uVar6;

  uVar6 = DAT_00a0f70c;

  param_1[0x30] = uVar3;

  param_1[0x31] = uVar3;

  param_1[0x32] = uVar6;

  *(uint16_t *)(param_1 + 0x35) = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x33] = 1;

  param_1[0x34] = 3;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  param_1[0x4e] = 0;

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = 0;

  param_1[0x53] = 0x19;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x59] = param_1[0x58];

  param_1[0x57] = 0;

  uVar6 = DAT_00a110d8;

  *(uint8_t *)(param_1 + 0x5f) = 0;

  param_1[0x60] = 0;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0;

  param_1[100] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  param_1[0x6a] = 0;

  param_1[0x6b] = 0;

  param_1[0x6c] = 0;

  param_1[0x6d] = 0;

  param_1[0x6e] = 0;

  param_1[0x6f] = 0;

  param_1[0x70] = 0;

  param_1[0x71] = 0;

  param_1[0x72] = 0;

  param_1[0x74] = 0;

  param_1[0x75] = 0;

  param_1[0x76] = 0;

  *(uint8_t *)(param_1 + 0x77) = 0;

  *(uint8_t *)((int)param_1 + 0x1dd) = 0;

  param_1[0x5c] = 0;

  param_1[0x5d] = uVar6;

  *(uint8_t *)(param_1 + 0x5e) = 1;

  *(uint8_t *)((int)param_1 + 0x179) = 0;

  param_1[0x21] = 0x7fff;

  param_1[0x22] = uVar5;

  param_1[0x23] = uVar4;

  param_1[0x24] = uVar8;

  param_1[0x28] = g_nInferredThreatDefault;

  uVar4 = DAT_00aaa8dc;

  param_1[0x2a] = 0;

  param_1[0x25] = uVar2;

  param_1[0x26] = uVar1;

  param_1[0x27] = 0x10;

  param_1[0x29] = uVar4;

  param_1[0x2d] = 0;

  param_1[0x2c] = 0;

  param_1[0x2b] = 0;

  param_1[0x2f] = DAT_00a10e78;

  uVar1 = DAT_00a0f70c;

  param_1[0x33] = 1;

  param_1[0x34] = 3;

  *(uint16_t *)(param_1 + 0x35) = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x2e] = uVar3;

  param_1[0x30] = uVar3;

  param_1[0x31] = uVar3;

  param_1[0x32] = uVar1;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  param_1[0x4e] = 0;

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = 0;

  param_1[0x53] = 0x19;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x59] = param_1[0x58];

  param_1[0x53] = 0x18;

  ExceptionList = local_c;

  return param_1;

}
