// =============================================================================
// FUN_0046d820
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d820
// Address:   0x0046d820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046d820 @ 0x0046d820
// Stable ID: aa_0046d820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, goto×5, return×1.
//  - Notable callees: FUN_0046d820.
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

void FUN_0046d820(int *param_1,int param_2,int param_3,int *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  

  iVar6 = param_3 - param_2 >> 2;

joined_r0x0046d830:

  iVar3 = iVar6;

  if (iVar3 < 1) {

    *param_1 = param_2;

    return;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)*param_4;

  iVar6 = iVar3 / 2;

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + iVar6 * 4);

  if (*(uint *)(puVar1[1] + 8) <= *(uint *)(puVar2[1] + 8)) goto code_r0x0046d857;

  goto LAB_0046d889;

code_r0x0046d857:

  if (*(uint *)(puVar2[1] + 8) == *(uint *)(puVar1[1] + 8)) {

    if ((uint)puVar1[2] <= (uint)puVar2[2]) {

      if (puVar2[2] != puVar1[2]) goto joined_r0x0046d830;

      uVar4 = (**(code **)(*(int *)*puVar2 + 0x14))();

      uVar5 = (**(code **)(*(int *)*puVar1 + 0x14))();

      if ((uVar5 <= uVar4) && ((uVar4 != uVar5 || ((uint)puVar1[1] <= (uint)puVar2[1]))))

      goto joined_r0x0046d830;

    }

LAB_0046d889:

    param_2 = param_2 + 4 + iVar6 * 4;

    iVar6 = iVar3 + (-1 - iVar6);

  }

  goto joined_r0x0046d830;

}
