// =============================================================================
// FUN_0064bbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064bbd0
// Address:   0x0064bbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064bbd0 @ 0x0064bbd0
// Stable ID: aa_0064bbd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00580ed0, FUN_0064bbd0.
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

void __thiscall FUN_0064bbd0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20;

  uint32_t /* width from decompiler */ local_1c;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(param_2 * 0xc0 + *(int *)(*(int *)(param_1 + 0xc) + 0x80));

  local_40 = *puVar1;

  local_3c = puVar1[1];

  local_38 = puVar1[2];

  local_34 = puVar1[3];

  local_30 = puVar1[4];

  local_2c = puVar1[5];

  local_28 = puVar1[6];

  local_24 = puVar1[7];

  local_1c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f8);

  local_20 = 1;

  FUN_00580ed0(&local_40,param_3);

  return;

}
