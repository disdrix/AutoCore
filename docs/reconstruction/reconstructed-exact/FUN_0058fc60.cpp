// =============================================================================
// FUN_0058fc60
// -----------------------------------------------------------------------------
// Stable ID: aa_0058fc60
// Address:   0x0058fc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058fc60 @ 0x0058fc60
// Stable ID: aa_0058fc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00403450, FUN_0058fc60, FUN_0096fdf0, block.
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x0058fd1b) */



void __thiscall FUN_0058fc60(int param_1,int param_2)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  int iVar5;

  char local_80 [128];

  

  iVar5 = *(int *)(param_2 + 8);

  *(int *)(param_1 + 0x914) = iVar5;

  if (iVar5 != 0) {

    if ((*(int *)(iVar5 + 0xc0) != 0) && (0 < *(int *)(iVar5 + 0xc4) - *(int *)(iVar5 + 0xc0) >> 2))

    {

      FUN_0096fdf0();

    }

    pvVar2 = *(void **)(*(int *)(param_1 + 0x914) + 0x78);

    if (pvVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x914) + 0x78) = 0;

    *(byte *)(param_1 + 0x90e) = *(byte *)(param_1 + 0x90e) | 4;

  }

  iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c);

  pcVar4 = local_80;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(iVar5 + 0x10,uVar3);

  iVar5 = (param_1 + 0x33d) - (int)pcVar4;

  do {

    cVar1 = *pcVar4;

    pcVar4[iVar5] = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  return;

}
