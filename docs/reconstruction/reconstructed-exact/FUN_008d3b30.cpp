// =============================================================================
// FUN_008d3b30
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3b30
// Address:   0x008d3b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d3b30 @ 0x008d3b30
// Stable ID: aa_008d3b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008cf740, FUN_008cf7f0, FUN_008d0d60, FUN_008d3090, FUN_008d3b30.
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

void FUN_008d3b30(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  int in_EAX;

  int iVar6;

  

  FUN_008d0d60(*(uint8_t *)

                (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                  *(int *)(in_EAX + 0x544)) + 0x3c) + 0x532));

  if (DAT_00d1b77c != 0) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x568) = 2;

    *(uint8_t *)(in_EAX + 0x5bc) = 1;

    piVar4 = *(int **)(*(int *)(in_EAX + 0x548) + 0x48);

    if (piVar4 != (int *)0x0) {

      iVar6 = (**(code **)(*piVar4 + 0xc))();

      iVar5 = DAT_00d1b77c;

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x90);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x94);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x98);

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x600) = uVar1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x604) = uVar2;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x608) = uVar3;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x600) = 0;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x604) = 0;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x608) = 0;

      iVar5 = DAT_00d1b77c;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5d0) = uVar1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x5d4) = uVar2;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x5d8) = uVar3;

      FUN_008cf7f0(0);

      FUN_008cf740();

      *(uint8_t *)(*(int *)(in_EAX + 0x568) + 0x5c0 + in_EAX) = 1;

      FUN_008d3090();

      *(uint8_t *)(in_EAX + 0x5c2) = 1;

    }

  }

  return;

}
