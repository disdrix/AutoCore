// =============================================================================
// FUN_009371e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009371e0
// Address:   0x009371e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009371e0 @ 0x009371e0
// Stable ID: aa_009371e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_009371e0.
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

void __fastcall FUN_009371e0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_a8 [8];

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  uint8_t local_28;

  uint8_t local_27;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_18;

  

  iVar1 = *(int *)(param_1 + 0xe98);

  local_a8[0] = 0x9000;

  local_18 = 0xffffffff;

  local_28 = 0;

  local_27 = 0;

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  local_88 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

  local_84 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

  if (*(int *)(param_1 + 0xc78) != 0) {

    local_24 = param_2;

    (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_a8,0xa8,0);

  }

  return;

}
