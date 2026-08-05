// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CVOGTacArc_Initialize, CVOGTacArc_InitializeMesh, CVOGTacArc_SetStateColor, CVOGTacArc_UpdateMesh, FUN_0074b8f0.
//  - Return sites: 2.

// =============================================================================
// CVOGTacArc_Initialize
// -----------------------------------------------------------------------------
// Stable ID: aa_006334e0
// Address:   0x006334e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

int __thiscall CVOGTacArc_Initialize(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  float local_18 [3];

  float local_c [3];

  

  if (param_2 == 0) {

    return -1;

  }

  *(int *)(param_1 + 0x20) = param_2;

  CVOGTacArc_SetStateColor(param_3);

  iVar1 = CVOGTacArc_InitializeMesh();

  if (-1 < iVar1) {

    if (*(int **)(param_1 + 0x18) != (int *)0x0) {

      local_18[0] = *(float *)(*(int *)(param_1 + 0x20) + 0xe8);

      local_c[0] = 0.0 - local_18[0];

      pfVar3 = local_18;

      local_c[2] = 0.0 - local_18[0];

      pfVar2 = local_c;

      local_18[1] = 0.0;

      local_c[1] = 0.0;

      local_18[2] = local_18[0];

      (**(code **)(**(int **)(param_1 + 0x18) + 0x4c))(pfVar2,pfVar3);

      FUN_0074b8f0(pfVar2,pfVar3);

    }

    iVar1 = CVOGTacArc_UpdateMesh(0);

  }

  return iVar1;

}
