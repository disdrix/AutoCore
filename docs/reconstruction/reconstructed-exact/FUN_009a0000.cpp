// =============================================================================
// FUN_009a0000
// -----------------------------------------------------------------------------
// Stable ID: aa_009a0000
// Address:   0x009a0000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009a0000 @ 0x009a0000
// Stable ID: aa_009a0000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00414cd0, FUN_00448fc0, FUN_0044c370, FUN_00999960, FUN_009a0000, gfxVertexBufferImpl_Unserialize.
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

int FUN_009a0000(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2e12;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar3 = FUN_00414cd0();

  local_4 = 0;

  if (iVar3 == 0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_00999960();

  }

  local_4 = 0xffffffff;

  if (piVar4 == (int *)0x0) {

    ExceptionList = local_c;

    return -1;

  }

  piVar4[1] = piVar4[1] + 1;

  if (piVar4[1] == 1) {

    (**(code **)(*piVar4 + 4))();

  }

  piVar2 = *(int **)(param_1 + 4);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(param_1 + 4) = piVar4;

  iVar3 = gfxVertexBufferImpl_Unserialize(piVar4,param_2,param_3);

  if (iVar3 == -2) {

    uVar5 = FUN_0044c370(piVar4[2],piVar4[3]);

    FUN_00448fc0(uVar5);

    iVar3 = 0;

  }

  ExceptionList = local_c;

  return iVar3;

}
