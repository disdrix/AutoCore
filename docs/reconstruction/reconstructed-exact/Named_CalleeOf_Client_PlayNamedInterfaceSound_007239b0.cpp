// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_007239b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007239b0
// Callee of Client_PlayNamedInterfaceSound
// Address:   0x007239b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PlayNamedInterfaceSound: presentation helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_0071f0f0, FUN_0071f810, FUN_007239b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_PlayNamedInterfaceSound
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Client_PlayNamedInterfaceSound_007239b0(int param_1,int param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int *piVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad3f9;

  pvStack_c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_2 + 0x3f8);

  ExceptionList = &pvStack_c;

  EnterCriticalSection(lpCriticalSection);

  local_4 = 0;

  FUN_0071f810();

  if (((*(int **)(param_1 + 0x10) != (int *)0x0) && (*(int *)(param_1 + 0x1c) != 0)) &&

     (piVar1 = (int *)**(int **)(param_1 + 0x10), piVar1 != (int *)0x0)) {

    iVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,0);

    if (iVar2 != 0) {

      LeaveCriticalSection(lpCriticalSection);

      ExceptionList = pvStack_c;

      return 0;

    }

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x218) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x228) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x23c) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x230) = 0;

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0071f0f0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x240) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x218) = 0;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x70 + *(int *)(param_1 + 0x30) * 4) + 0x10c) = 1;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x70 + *(int *)(param_1 + 0x30) * 4) + 0x110) =

       *(uint32_t /* width from decompiler */ *)(param_2 + 0x3dc);

  *(uint8_t *)(param_1 + 0x1c4) = 1;

  LeaveCriticalSection(lpCriticalSection);

  ExceptionList = pvStack_c;

  return 1;

}
