// =============================================================================
// FUN_00541950
// -----------------------------------------------------------------------------
// Stable ID: aa_00541950
// Address:   0x00541950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00541950 @ 0x00541950
// Stable ID: aa_00541950
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00541950, FUN_00545a90, FUN_007a4480, FUN_007dbce0.
//  - Strings: "VOG_DEBUG_STOP".
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

void __fastcall FUN_00541950(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puStack_1c;

  int iStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a3fe4;

  pvStack_c = ExceptionList;

  iVar4 = 0;

  ExceptionList = &pvStack_c;

  if (*(void **)(param_1 + 0xf20) != (void *)0x0) {

    ExceptionList = &pvStack_c;

    operator_delete__(*(void **)(param_1 + 0xf20));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf20) = 0;

  (**(code **)(**(int **)(param_1 + 0xf1c) + 4))();

  iStack_18 = 0;

  uStack_14 = 0;

  pvStack_10 = (void *)0x0;

  uStack_4 = 0;

  iVar1 = FUN_007dbce0(&puStack_1c);

  puVar5 = puStack_1c;

  if (iVar1 < 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  else {

    if (puStack_1c != (uint32_t /* width from decompiler */ *)0x0) {

      iVar4 = (iStack_18 - (int)puStack_1c) / 0x154;

    }

    puVar2 = operator_new__(iVar4 * 0x154);

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xf20) = puVar2;

    for (uVar3 = (uint)(iVar4 * 0x154) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar2 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar2 = puVar2 + 1;

    }

    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {

      *(uint8_t *)puVar2 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

    }

    if (0 < iVar4) {

      iVar1 = 0;

      do {

        FUN_00545a90(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xf20) + iVar1),

                     *(int *)(param_1 + 0xf20) + iVar1,0);

        iVar1 = iVar1 + 0x154;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

    }

  }

  if (puStack_1c == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = pvStack_10;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puStack_1c);

}
