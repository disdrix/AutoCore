// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005743e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005743e0
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x005743e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00418e60, FUN_005743e0, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_005743e0(int param_1,uint param_2)



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

    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 3;

  }

  if (uVar1 < param_2) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 3;

    }

    FUN_00418e60(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2,&stack0x00000008);

    return;

  }

  if (((iVar2 != 0) &&

      (pvVar3 = *(void **)(param_1 + 8), param_2 < (uint)((int)pvVar3 - iVar2 >> 3))) &&

     (_Dst = (void *)(iVar2 + param_2 * 8), _Dst != pvVar3)) {

    pvVar3 = memmove(_Dst,pvVar3,0);

    *(void **)(param_1 + 8) = pvVar3;

  }

  return;

}
