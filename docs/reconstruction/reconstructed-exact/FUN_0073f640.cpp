// =============================================================================
// FUN_0073f640
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f640
// Address:   0x0073f640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073f640 @ 0x0073f640
// Stable ID: aa_0073f640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004506a0, FUN_004506f0, FUN_0073f2f0, FUN_0073f640, FUN_007532a0.
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

void FUN_0073f640(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  int *piVar1;

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puStack_4;

  

  if ((*in_EAX != 0) && (iVar3 = (int)*(short *)(*in_EAX + 0x1c), -1 < iVar3)) {

    piVar4 = *(int **)(*(int *)(param_1 + 0x14) + iVar3 * 4);

    if (piVar4 == (int *)0x0) {

      FUN_0073f2f0(iVar3);

      piVar4 = *(int **)(*(int *)(param_1 + 0x14) + iVar3 * 4);

    }

    piVar1 = (int *)*in_EAX;

    piVar1[1] = piVar1[1] + 1;

    if (piVar1[1] == 1) {

      (**(code **)(*piVar1 + 4))();

    }

    if (param_5 == 0) {

      param_5 = FUN_007532a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x30));

    }

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_004506f0();

    *puVar2 = param_2;

    puVar2[1] = piVar1;

    puVar2[2] = param_5;

    puVar2[3] = param_3;

    puVar2[4] = param_4;

    puStack_4 = puVar2;

    FUN_004506a0(&puStack_4);

    (**(code **)(*piVar4 + 0x14))(puVar2);

  }

  return;

}
