// =============================================================================
// FUN_005ebca0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ebca0
// Address:   0x005ebca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ebca0 @ 0x005ebca0
// Stable ID: aa_005ebca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_005ebca0.
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

void __thiscall FUN_005ebca0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0xc4) + -1;

  uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0xcc);

  if (-1 < iVar3) {

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc0) + iVar3 * 8);

      (**(code **)(*(int *)*puVar1 + 4))(param_1 + 0xc,puVar1[1],uVar2,param_2);

      iVar3 = iVar3 + -1;

    } while (-1 < iVar3);

  }

  return;

}
