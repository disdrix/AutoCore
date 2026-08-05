// =============================================================================
// Named_CalleeOf_Named_matD3DXMathEmu_00973590
// -----------------------------------------------------------------------------
// Stable ID: aa_00973590
// Callee of Named_matD3DXMathEmu
// Address:   0x00973590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_matD3DXMathEmu: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: ROUND×7, FUN_00973590.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_matD3DXMathEmu
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_matD3DXMathEmu_00973590(float param_1,float param_2,float param_3,float param_4)



{

  int iVar1;

  uint8_t *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xff;

  local_8 = 0;

  if ((int)ROUND(param_1) < 0) {

    puVar2 = &local_8;

  }

  else {

    puVar2 = &local_4;

    if ((int)ROUND(param_1) < 0x100) {

      puVar2 = &param_1;

    }

  }

  in_EAX[2] = *(uint8_t *)puVar2;

  local_8 = 0xff;

  local_4 = 0;

  if ((int)ROUND(param_2) < 0) {

    puVar2 = &local_4;

  }

  else {

    puVar2 = &local_8;

    if ((int)ROUND(param_2) < 0x100) {

      puVar2 = &param_1;

    }

  }

  in_EAX[1] = *(uint8_t *)puVar2;

  local_4 = 0xff;

  if ((int)ROUND(param_3) < 0) {

    puVar2 = &param_2;

  }

  else {

    puVar2 = &local_4;

    if ((int)ROUND(param_3) < 0x100) {

      puVar2 = &param_1;

    }

  }

  *in_EAX = *(uint8_t *)puVar2;

  iVar1 = (int)ROUND(param_4);

  if (iVar1 < 0) {

    in_EAX[3] = 0;

    return;

  }

  if (0xff < iVar1) {

    in_EAX[3] = 0xff;

    return;

  }

  param_1._0_1_ = (uint8_t)iVar1;

  in_EAX[3] = param_1._0_1_;

  return;

}
