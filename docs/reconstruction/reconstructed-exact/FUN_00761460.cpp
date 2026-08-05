// =============================================================================
// FUN_00761460
// -----------------------------------------------------------------------------
// Stable ID: aa_00761460
// Address:   0x00761460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00761460 @ 0x00761460
// Stable ID: aa_00761460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_00761210, FUN_00761460.
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

uint32_t /* width from decompiler */ __thiscall FUN_00761460(int param_1,int param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  FUN_00761210(*(uint32_t /* width from decompiler */ *)(param_2 + 0x30));

  uVar3 = 0;

  if (*(int *)(param_1 + 0xc) != 0) {

    uVar3 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

  }

  uVar1 = *(uint *)(param_1 + 0x18);

  if (uVar1 < uVar3) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xc) + 8 + uVar1 * 0x28);

    for (puVar4 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xc) + uVar1 * 0x28 + 4); puVar4 != puVar2;

        puVar4 = puVar4 + 1) {

      (**(code **)(**(int **)(param_1 + 4) + 0x6c))(*puVar4,param_2);

    }

  }

  return 0;

}
