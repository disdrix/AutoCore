// =============================================================================
// FUN_0073b1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b1e0
// Address:   0x0073b1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b1e0 @ 0x0073b1e0
// Stable ID: aa_0073b1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00456780, FUN_00456960, FUN_0073b1e0.
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

void __thiscall FUN_0073b1e0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  FUN_00456780(0);

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    iVar3 = *(int *)(param_2 + 4);

    if ((iVar3 == 0) ||

       ((uint)(*(int *)(param_2 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(param_2 + 8) - iVar3 >> 2)))

    {

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_2 + 8));

    }

    else {

      puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

      *puVar4 = puVar2[5];

      *(uint32_t /* width from decompiler */ **)(param_2 + 8) = puVar4 + 1;

    }

  }

  return;

}
