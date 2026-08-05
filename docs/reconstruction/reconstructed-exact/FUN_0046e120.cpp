// =============================================================================
// FUN_0046e120
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e120
// Address:   0x0046e120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046e120 @ 0x0046e120
// Stable ID: aa_0046e120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_0046e120, FUN_0046e1c0.
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

void FUN_0046e120(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar2 = param_2;

  while( true ) {

    iVar3 = iVar2 * 2 + 2;

    if (param_3 <= iVar3) break;

    piVar1 = (int *)**(uint32_t /* width from decompiler */ **)(param_1 + -4 + iVar3 * 4);

    fVar4 = (float10)(**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + iVar3 * 4) + 0x10))();

    fVar5 = (float10)(**(code **)(*piVar1 + 0x10))();

    if (fVar5 - (float10)DAT_00aaa620 <= (float10)(float)fVar4) {

      iVar3 = iVar2 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 4);

    iVar2 = iVar3;

  }

  if (iVar3 == param_3) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_3 * 4);

  }

  FUN_0046e1c0(param_1,param_2,param_4,param_5);

  return;

}
