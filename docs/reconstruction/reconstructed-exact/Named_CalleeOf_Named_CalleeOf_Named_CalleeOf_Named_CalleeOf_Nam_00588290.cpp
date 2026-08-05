// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00588290
// -----------------------------------------------------------------------------
// Stable ID: aa_00588290
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x00588290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×1.
//  - Notable callees: FUN_004022a0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00512670, FUN_00513e70, FUN_005713a0, FUN_005714e0, FUN_00571620.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00588290(int param_1,int *param_2,int param_3)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_retaddr;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((param_2 == (int *)0x0) || (*(int *)(param_1 + 0x35c) == 0)) {

    return 0;

  }

  local_4 = 0;

  FUN_004294f0();

  iVar3 = FUN_004022a0(&local_4,&local_8);

  piVar1 = local_8;

  while (iVar3 == 0) {

    local_8 = piVar1;

    if (((piVar1 != (int *)0x0) && (*(int *)(piVar1[0x2a] + 0x34) == *(int *)(param_2[0x2a] + 0x34))

        ) && (cVar2 = FUN_00513e70(), cVar2 != '\0')) {

      iVar3 = (**(code **)(*piVar1 + 0x25c))();

      (**(code **)(*piVar1 + 0x260))(iVar3 + param_3);

      iVar3 = *(int *)(param_1 + 0x35c);

      if (*(char *)(iVar3 + 0x54) != '\0') {

        *(uint8_t *)(iVar3 + 0x54) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x30));

      }

      return param_3;

    }

    iVar3 = FUN_004022a0(&local_4,&local_8);

    piVar1 = local_8;

  }

  iVar3 = *(int *)(param_1 + 0x35c);

  if (*(char *)(iVar3 + 0x54) != '\0') {

    *(uint8_t *)(iVar3 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x30));

  }

  (**(code **)(*param_2 + 0x260))(param_3);

  param_2[0x5f] = param_2[0x5f] | 0x10;

  FUN_00512670();

  if ((*(char *)(*(int *)(param_2[0x2a] + 0x3c) + 0x406) == '\0') &&

     (*(char *)(*(int *)(param_2[0x2a] + 0x3c) + 0x407) == '\0')) {

    cVar2 = FUN_005713a0(2,2,&stack0xfffffff0,&stack0x00000000,0xffffffff);

  }

  else {

    cVar2 = FUN_005714e0(param_2,&stack0xfffffff0,&stack0x00000000,1,0xffffffff);

  }

  if (cVar2 != '\0') {

    uVar4 = (**(code **)(*param_2 + 0x25c))();

    FUN_00571620(param_2,unaff_EBX,unaff_retaddr,uVar4);

    return param_3;

  }

  return 0;

}
