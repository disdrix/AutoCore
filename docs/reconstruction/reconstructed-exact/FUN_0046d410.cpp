// =============================================================================
// FUN_0046d410
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d410
// Address:   0x0046d410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046d410 @ 0x0046d410
// Stable ID: aa_0046d410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, goto×3, return×1.
//  - Notable callees: FUN_0046d410.
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

void FUN_0046d410(int *param_1,int param_2,int param_3,int *param_4)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  

  iVar6 = param_3 - param_2 >> 2;

joined_r0x0046d421:

  iVar5 = iVar6;

  if (iVar5 < 1) {

    *param_1 = param_2;

    return;

  }

  uVar1 = ((uint32_t /* width from decompiler */ *)*param_4)[2];

  iVar6 = iVar5 / 2;

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + iVar6 * 4);

  uVar3 = puVar2[2];

  if (uVar1 <= uVar3) goto code_r0x0046d442;

  goto LAB_0046d468;

code_r0x0046d442:

  if (uVar3 == uVar1) {

    piVar4 = *(int **)*param_4;

    fVar7 = (float10)(**(code **)(*(int *)*puVar2 + 0x10))();

    fVar8 = (float10)(**(code **)(*piVar4 + 0x10))();

    if ((float10)(float)fVar7 <= fVar8 + (float10)DAT_00aaa620) {

LAB_0046d468:

      param_2 = param_2 + 4 + iVar6 * 4;

      iVar6 = iVar5 + (-1 - iVar6);

    }

  }

  goto joined_r0x0046d421;

}
