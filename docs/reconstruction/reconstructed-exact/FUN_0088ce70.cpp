// =============================================================================
// FUN_0088ce70
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ce70
// Address:   0x0088ce70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088ce70 @ 0x0088ce70
// Stable ID: aa_0088ce70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_0088ce70.
//  - Return sites: 4.

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

void __fastcall FUN_0088ce70(int param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int unaff_EDI;

  uint32_t /* width from decompiler */ auStack_10 [4];

  

  if (*(int *)(param_1 + 0x5c4) == 0) {

    return;

  }

  if ((*(int **)(param_1 + 0x5c0) != (int *)0x0) &&

     (iVar2 = (**(code **)(**(int **)(param_1 + 0x5c0) + 0x1b8))(), iVar2 != 0)) {

    puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1 + 0x5c0) + 0x140))(auStack_10,1);

    auStack_10[0] = *puVar3;

    iVar2 = puVar3[1];

    (**(code **)(**(int **)(param_1 + 0x5c0) + 0x204))(&stack0xffffffe0);

    if (unaff_EDI <= iVar2) {

      (**(code **)(**(int **)(param_1 + 0x5c4) + 4))(0);

      return;

    }

    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x5c0) + 0x1b8))();

    iVar2 = ((*(int *)(*piVar4 + 0x7c) - iVar2) + -1 + unaff_EDI) / *(int *)(*piVar4 + 0x7c);

    *(int *)(param_1 + 0x540) = iVar2;

    if (iVar2 < 1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 1;

    }

    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c4) + 0xd0))();

    if (cVar1 == '\0') {

      (**(code **)(**(int **)(param_1 + 0x5c4) + 0xfc))(1,0x3f000000);

    }

    (**(code **)(**(int **)(param_1 + 0x5c4) + 0x460))(g_flOne / (float)*(int *)(param_1 + 0x540));

    iVar2 = **(int **)(param_1 + 0x5c4);

    iVar5 = (**(code **)(**(int **)(param_1 + 0x5c0) + 0x218))(0);

    (**(code **)(iVar2 + 0x454))((float)iVar5 / (float)*(int *)(param_1 + 0x540));

    return;

  }

  (**(code **)(**(int **)(param_1 + 0x5c4) + 4))();

  return;

}
