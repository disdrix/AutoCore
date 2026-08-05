// =============================================================================
// FUN_005b4a30
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4a30
// Address:   0x005b4a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4a30 @ 0x005b4a30
// Stable ID: aa_005b4a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: D3DXMatrixTranslation, FUN_005b4a30, FUN_006864c0.
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

void FUN_005b4a30(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  float *pfVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t *puVar4;

  float *pfStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint8_t *puStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint8_t auStack_50 [16];

  float local_40 [6];

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  uStack_60 = 0x5b4a3b;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_006864c0();

  uStack_68 = *puVar1;

  puStack_64 = (uint8_t *)puVar1[1];

  uStack_60 = puVar1[2];

  pfStack_6c = local_40;

  local_8 = 0;

  local_c = 0;

  local_10 = 0;

  local_14 = 0;

  local_1c = 0;

  local_20 = 0;

  local_24 = 0;

  local_28 = 0;

  local_40[4] = 0.0;

  local_40[3] = 0.0;

  local_40[2] = 0.0;

  local_40[1] = 0.0;

  local_4 = g_flOne;

  local_18 = g_flOne;

  local_40[5] = g_flOne;

  local_40[0] = g_flOne;

  local_5c = uStack_68;

  local_58 = puStack_64;

  local_54 = uStack_60;

  D3DXMatrixTranslation();

  puVar4 = auStack_50;

  uVar3 = 0x100;

  pfVar2 = DAT_00b05340;

  (**(code **)((int)*DAT_00b05340 + 0xb0))(DAT_00b05340,0x100,puVar4);

  uStack_60 = 0;

  pfStack_6c = pfVar2;

  uStack_68 = uVar3;

  puStack_64 = puVar4;

  (**(code **)((int)*DAT_00b05340 + 0x178))(DAT_00b05340,0x34,&pfStack_6c,1);

  return;

}
