// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074ee40
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ee40
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0074ee40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00449070, FUN_0074eaa0, FUN_0074ee40, FUN_00963950, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074ee40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  

  uVar2 = FUN_00449070();

  piVar3 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_2,uVar2,0,0);

  *(int **)(param_1 + 0x70) = piVar3;

  if (piVar3 != (int *)0x0) {

    cVar1 = (**(code **)(*piVar3 + 4))();

    iVar4 = NDResource_AcquireInnerObject();

    *(int *)(param_1 + 0x74) = iVar4;

    if ((iVar4 != 0) && (iVar4 = FUN_00963950(iVar4), iVar4 != -1)) {

      FUN_0074eaa0();

      return (uint)(cVar1 != '\0');

    }

  }

  return 0xffffffff;

}
