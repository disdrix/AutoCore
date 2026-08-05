// =============================================================================
// FUN_006ca890
// -----------------------------------------------------------------------------
// Stable ID: aa_006ca890
// Address:   0x006ca890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ca890 @ 0x006ca890
// Stable ID: aa_006ca890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006ca890.
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

void __thiscall

FUN_006ca890(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ *local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  *(uint32_t /* width from decompiler */ **)(param_1 + 4) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = param_6;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  if (param_4 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_4 + 0x14;

  }

  *(int *)(param_1 + 8) = iVar1;

  if (*(char *)(param_3 + 8) == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  }

  else if (param_4 == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = param_3[9];

  }

  else {

    *(int *)(param_1 + 0x44) = param_4 + 0x10;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = param_3[9];

  }

  local_30 = *param_3;

  local_2c = param_3[1];

  local_28 = param_3[2];

  local_24 = param_3[3];

  local_1c = param_3 + 4;

  local_14 = param_5;

  local_20 = 1;

  local_18 = 0x10;

  (**(code **)(*param_2 + 0x30))(&local_30,param_1,0);

  return;

}
