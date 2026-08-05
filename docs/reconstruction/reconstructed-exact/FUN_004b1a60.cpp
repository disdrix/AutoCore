// =============================================================================
// FUN_004b1a60
// -----------------------------------------------------------------------------
// Stable ID: aa_004b1a60
// Address:   0x004b1a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b1a60 @ 0x004b1a60
// Stable ID: aa_004b1a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004b0d60, FUN_004b1a60, FUN_0079ef30.
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

void __fastcall FUN_004b1a60(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint8_t local_34 [16];

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  float local_8;

  float local_4;

  

  if (param_1[2] != 0) {

    iVar1 = param_1[2];

    local_8 = *(float *)(*param_1 + 0x8bc) * *(float *)(iVar1 + 0x10);

    uVar2 = 0;

    local_4 = *(float *)(*param_1 + 0x8bc) * *(float *)(iVar1 + 0x18);

    local_44 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x178);

    local_40 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x17c);

    local_3c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x180);

    local_20 = 0;

    FUN_004b0d60(local_34,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x80));

    local_24 = *(uint32_t /* width from decompiler */ *)(param_1[2] + 0x34);

    local_1c = *(uint32_t /* width from decompiler */ *)(param_1[2] + 0x2c);

    local_14 = g_flOne;

    local_18 = uVar2;

    local_10 = uVar2;

    FUN_0079ef30(&local_44,&DAT_00afdfc8,&DAT_00afdfd4,&DAT_00afdfe0,0);

  }

  return;

}
