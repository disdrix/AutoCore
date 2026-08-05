// =============================================================================
// FUN_005137f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005137f0
// Address:   0x005137f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005137f0 @ 0x005137f0
// Stable ID: aa_005137f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005137f0.
//  - Return sites: 2.

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

void __thiscall FUN_005137f0(int *param_1,byte param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = (**(code **)(*param_1 + 0x19c))();

  if (iVar2 != 0) {

    iVar3 = (**(code **)(*param_1 + 0x19c))();

    iVar2 = *(int *)(*(int *)(iVar3 + 4) + 4);

    puVar1 = (uint *)(iVar2 + iVar3 + 0x188);

    *puVar1 = *puVar1 ^ ((uint)param_2 * 2 ^ *(uint *)(iVar2 + 0x188 + iVar3)) & 2;

    return;

  }

  param_1[0x61] = param_1[0x61] ^ ((uint)param_2 * 2 ^ param_1[0x61]) & 2;

  return;

}
