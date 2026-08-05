// =============================================================================
// FUN_0075d6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d6f0
// Address:   0x0075d6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d6f0 @ 0x0075d6f0
// Stable ID: aa_0075d6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×2.
//  - Notable callees: FUN_00745f80×2, FUN_0043bcc0, FUN_00463e30, FUN_00745df0, FUN_0075d6f0, FUN_00971050, block.
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

/* WARNING: Removing unreachable block (ram,0x0075d7a0) */



void __fastcall FUN_0075d6f0(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar4 = (int *)**(int **)(unaff_ESI + 8);

  uStack_4 = param_1;

  if (piVar4 != *(int **)(unaff_ESI + 8)) {

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)piVar4[3];

      if ((puVar3 == (uint32_t /* width from decompiler */ *)0x0) || (iVar2 = FUN_00745df0(), iVar2 != 0)) {

        piVar4 = (int *)*piVar4;

      }

      else {

        FUN_00745f80();

        (**(code **)*puVar3)(1);

        puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043bcc0(&uStack_4,piVar4);

        piVar4 = (int *)*puVar3;

      }

    } while (piVar4 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8));

  }

  piVar4 = (int *)**(int **)(unaff_ESI + 8);

  if (piVar4 != *(int **)(unaff_ESI + 8)) {

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)piVar4[3];

      if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        FUN_00745f80();

        (**(code **)*puVar3)(1);

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(unaff_ESI + 8));

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

  pvVar1 = (void *)*puVar3;

  *puVar3 = puVar3;

  *(int *)(*(int *)(unaff_ESI + 8) + 4) = *(int *)(unaff_ESI + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  if (pvVar1 != *(void **)(unaff_ESI + 8)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  uStack_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

  if (*(int *)(unaff_ESI + 0x14) != *(int *)(unaff_ESI + 0x18)) {

    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x14);

  }

  FUN_00463e30(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),9,&uStack_4);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = 1;

  if (*(int *)(unaff_ESI + 0x6c) != 0) {

    FUN_00971050();

  }

  return;

}
