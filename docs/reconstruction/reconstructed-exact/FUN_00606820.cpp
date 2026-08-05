// =============================================================================
// FUN_00606820
// -----------------------------------------------------------------------------
// Stable ID: aa_00606820
// Address:   0x00606820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00606820 @ 0x00606820
// Stable ID: aa_00606820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00606820.
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

void __thiscall FUN_00606820(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  if ((-1 < param_2) && (param_2 < 4)) {

    iVar1 = param_1 + param_2 * 0x48;

    for (uVar3 = 0;

        (iVar2 = *(int *)(iVar1 + 0xb4), iVar2 != 0 &&

        (uVar3 < (uint)(*(int *)(iVar1 + 0xb8) - iVar2 >> 3))); uVar3 = uVar3 + 1) {

      CVOGReaction_RemoveObject

                (*(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),

                 *(uint *)(iVar2 + uVar3 * 8),*(uint32_t /* width from decompiler */ *)(iVar2 + 4 + uVar3 * 8),'\x01');

    }

  }

  return;

}
