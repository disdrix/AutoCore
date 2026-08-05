// =============================================================================
// Named_CalleeOf_CVOGWaypoint_UpdateState_005d5680
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5680
// Callee of CVOGWaypoint_UpdateState
// Address:   0x005d5680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGWaypoint_UpdateState: AI/path helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005d5680, SQRT.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGWaypoint_UpdateState
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

void __fastcall Named_CalleeOf_CVOGWaypoint_UpdateState_005d5680(int param_1)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  iVar1 = *(int *)(param_1 + 0x10);

  if (*(int *)(iVar1 + 8) == 0) {

    pfVar2 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);

  }

  else {

    pfVar2 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);

  }

  fVar5 = pfVar2[2] - *(float *)(param_1 + 0x28);

  fVar4 = pfVar2[1] - *(float *)(param_1 + 0x24);

  fVar3 = *pfVar2 - *(float *)(param_1 + 0x20);

  if ((g_flLevelUpUiBase_Inferred <= SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5)) &&

     ((*(uint *)(param_1 + 0x54) == 0 || (g_dwClientTickMs <= *(uint *)(param_1 + 0x54))))) {

    *(uint8_t *)(param_1 + 0x53) = 0;

    *(uint8_t *)(param_1 + 0x52) = 1;

    return;

  }

  *(uint8_t *)(param_1 + 0x50) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0xffffffff;

  *(uint8_t *)(param_1 + 0x51) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint8_t *)(param_1 + 0x52) = 0;

  return;

}
