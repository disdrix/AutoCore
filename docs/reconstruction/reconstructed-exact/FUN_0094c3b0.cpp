// =============================================================================
// FUN_0094c3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c3b0
// Address:   0x0094c3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094c3b0 @ 0x0094c3b0
// Stable ID: aa_0094c3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0094c3b0.
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

void __thiscall FUN_0094c3b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_20 [2];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  

  if (*(int *)(param_1 + 0xe98) != 0) {

    iVar1 = *(int *)(param_1 + 0xe98);

    local_20[0] = 0x2092;

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    local_18 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

    local_14 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    local_8 = 1;

    local_10 = param_2;

    local_c = param_3;

    if (*(int *)(param_1 + 0xc78) != 0) {

      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_20,0x20,0);

    }

  }

  return;

}
