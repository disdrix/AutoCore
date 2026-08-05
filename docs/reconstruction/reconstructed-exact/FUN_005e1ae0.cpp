// =============================================================================
// FUN_005e1ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1ae0
// Address:   0x005e1ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e1ae0 @ 0x005e1ae0
// Stable ID: aa_005e1ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005e1ae0.
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

void __fastcall FUN_005e1ae0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  uVar1 = DAT_009dc4d4;

  *param_1 = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  uVar3 = DAT_00a111a8;

  param_1[1] = uVar1;

  uVar1 = DAT_009dc4d0;

  param_1[5] = 0x400;

  *(uint8_t *)(param_1 + 4) = 1;

  param_1[0xb] = 0;

  param_1[8] = uVar1;

  param_1[9] = uVar1;

  param_1[10] = uVar1;

  uVar2 = DAT_00aaaa90;

  param_1[0xf] = 0;

  uVar1 = DAT_00a0f71c;

  param_1[0xc] = uVar2;

  param_1[0xd] = uVar2;

  param_1[0xe] = uVar2;

  uVar2 = DAT_00a0f718;

  param_1[0x11] = uVar1;

  param_1[0x12] = g_flOne;

  param_1[0x15] = DAT_009dc4cc;

  param_1[0x16] = g_flOverheatCoolFrac;

  param_1[0x17] = g_flMsToSeconds_Inferred;

  param_1[0x18] = g_flMultiKillCountBlend;

  param_1[0x1a] = DAT_00a10e78;

  uVar1 = DAT_00a0f70c;

  param_1[0x1b] = DAT_00a0f70c;

  param_1[0x22] = uVar1;

  uVar1 = DAT_00a110d8;

  param_1[0x10] = 0;

  param_1[0x13] = 4;

  *(uint8_t *)(param_1 + 0x14) = 0;

  *(uint8_t *)((int)param_1 + 0x51) = 0;

  *(uint8_t *)(param_1 + 0x19) = 1;

  param_1[0x1c] = uVar2;

  param_1[0x1d] = uVar3;

  *(uint8_t *)(param_1 + 0x1e) = 1;

  param_1[0x1f] = uVar2;

  param_1[0x20] = 0x14;

  *(uint8_t *)(param_1 + 0x21) = 1;

  param_1[0x23] = uVar1;

  return;

}
