// =============================================================================
// FUN_0073ecf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ecf0
// Address:   0x0073ecf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073ecf0 @ 0x0073ecf0
// Stable ID: aa_0073ecf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0073ebf0, FUN_0073ecf0.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __thiscall FUN_0073ecf0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  void *pvVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac0a2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0073ebf0();

  pvVar1 = operator_new__(unaff_EDI * 4);

  *(void **)(param_1 + 0xc) = pvVar1;

  pvVar1 = operator_new__(unaff_EDI * 4);

  *(void **)(param_1 + 0x10) = pvVar1;

  piVar2 = operator_new__(unaff_EDI * 0x10 + 4);

  local_4 = 0;

  if (piVar2 == (int *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = piVar2 + 1;

    *piVar2 = unaff_EDI;

    _eh_vector_constructor_iterator_

              (piVar3,0x10,unaff_EDI,(_func_void_void_ptr *)&LAB_00456430,FUN_00449d40);

  }

  iVar4 = 0;

  if (0 < unaff_EDI) {

    piVar5 = (int *)(param_3 + 0xc);

    piVar2 = piVar3 + 2;

    do {

      piVar2[-1] = *(int *)(param_1 + 0xc) + iVar4 * 4;

      *piVar2 = *(int *)(param_1 + 0x10) + iVar4 * 4;

      if (param_3 != 0) {

        piVar2[1] = *piVar5;

      }

      iVar4 = iVar4 + 1;

      piVar5 = piVar5 + 4;

      piVar2 = piVar2 + 4;

    } while (iVar4 < unaff_EDI);

  }

  *(int **)(param_1 + 8) = piVar3;

  *(int *)(param_1 + 0x14) = unaff_EDI;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = param_2;

  ExceptionList = local_c;

  return 0;

}
