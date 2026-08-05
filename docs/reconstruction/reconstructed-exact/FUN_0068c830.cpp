// =============================================================================
// FUN_0068c830
// -----------------------------------------------------------------------------
// Stable ID: aa_0068c830
// Address:   0x0068c830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068c830 @ 0x0068c830
// Stable ID: aa_0068c830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004490a0×3, FUN_0068c830.
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

void __thiscall FUN_0068c830(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = *(int *)(param_1 + 0x84);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0x8c) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0x88) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88),1,param_2);

  }

  else {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x88);

    *puVar2 = *param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x88) = puVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 0x84);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0x8c) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0x88) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88),1,param_2 + 1);

  }

  else {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x88);

    *puVar2 = param_2[1];

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x88) = puVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 0x84);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0x88) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0x8c) - iVar1 >> 2))

     ) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x88);

    *puVar2 = param_2[2];

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x88) = puVar2 + 1;

    return;

  }

  FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88),1,param_2 + 2);

  return;

}
