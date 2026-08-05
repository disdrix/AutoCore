// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_0096fff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096fff0
// Callee of Named_gfxDeviceVB (+1 other named callers)
// Address:   0x0096fff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceVB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00448fc0, FUN_00753160, FUN_0096fdf0, FUN_0096fff0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB (+1 other named callers)
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

int Named_CalleeOf_Named_gfxDeviceVB_0096fff0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar3;

  int iVar4;

  

  cVar2 = FUN_0096fdf0();

  iVar3 = FUN_00753160(param_2,*in_EAX,in_EAX[1],in_EAX[2],in_EAX[3]);

  if (((iVar3 == -1) && (cVar2 != '\0')) && (iVar1 = *param_1, iVar1 != 0)) {

    iVar4 = *(int *)(iVar1 + 0x18);

    if (*(int *)(iVar1 + 0x18) == 0) {

      iVar4 = iVar1;

    }

    if (iVar4 != iVar1) {

      FUN_00448fc0(iVar4);

    }

  }

  return iVar3;

}
