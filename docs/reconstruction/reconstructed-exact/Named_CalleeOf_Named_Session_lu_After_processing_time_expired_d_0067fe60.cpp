// =============================================================================
// Named_CalleeOf_Named_Session_lu_After_processing_time_expired_d_0067fe60
// -----------------------------------------------------------------------------
// Stable ID: aa_0067fe60
// Callee of Named_Session_lu_After_processing_time_expired_d_packe
// Address:   0x0067fe60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Session_lu_After_processing_time_expired_d: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0067f930, FUN_0067fe60, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Session_lu_After_processing_time_expired_d_packe
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

void __thiscall Named_CalleeOf_Named_Session_lu_After_processing_time_expired_d_0067fe60(int param_1,uint param_2)



{

  void *_Dst;

  uint uVar1;

  int iVar2;

  void *pvVar3;

  

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 2;

  }

  if (uVar1 < param_2) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 2;

    }

    FUN_0067f930(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2,&stack0x00000008);

    return;

  }

  if (((iVar2 != 0) &&

      (pvVar3 = *(void **)(param_1 + 8), param_2 < (uint)((int)pvVar3 - iVar2 >> 2))) &&

     (_Dst = (void *)(iVar2 + param_2 * 4), _Dst != pvVar3)) {

    pvVar3 = memmove(_Dst,pvVar3,0);

    *(void **)(param_1 + 8) = pvVar3;

  }

  return;

}
