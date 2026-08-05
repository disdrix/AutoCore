// =============================================================================
// FUN_008becd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008becd0
// Address:   0x008becd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008becd0 @ 0x008becd0
// Stable ID: aa_008becd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT22, FUN_00514050, FUN_005140d0, FUN_0085d970, FUN_008becd0, FUN_0092fb30.
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

void __fastcall FUN_008becd0(int param_1)



{

  int *piVar1;

  int iVar2;

  int *in_EAX;

  uint16_t extraout_var;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int unaff_EBX;

  uint8_t **ppuStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint8_t *puStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint8_t *puStack_118;

  uint8_t local_104 [260];

  

  if ((in_EAX != (int *)0x0) && (*(int *)(unaff_EBX + 0x570 + param_1 * 4) != 0)) {

    puStack_118 = local_104;

    puStack_120 = (uint8_t *)0x8becfe;

    FUN_0085d970();

    piVar1 = *(int **)(unaff_EBX + 0x570 + param_1 * 4);

    iVar2 = *piVar1;

    puStack_118 = (uint8_t *)0x0;

    uStack_11c = 0x8bed16;

    uStack_11c = (**(code **)(*piVar1 + 0x2c8))();

    puStack_120 = local_104;

    uStack_124 = 0x8bed26;

    (**(code **)(iVar2 + 0x50))();

    uStack_124 = 1;

    uStack_128 = 0x8bed37;

    (**(code **)(**(int **)(unaff_EBX + 0x570 + param_1 * 4) + 0xcc))();

    uStack_128 = 0x8bed46;

    (**(code **)(**(int **)(unaff_EBX + 0x570 + param_1 * 4) + 0x34c))();

    uStack_128 = 1;

    uStack_12c = 0x8bed54;

    (**(code **)(**(int **)(unaff_EBX + 0x558 + param_1 * 4) + 4))();

    uStack_12c = 1;

    uStack_130 = 0x8bed62;

    (**(code **)(**(int **)(unaff_EBX + 0x564 + param_1 * 4) + 4))();

    uStack_130 = CONCAT22(extraout_var,*(uint16_t *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b8));

    iVar2 = **(int **)(unaff_EBX + 0x558 + param_1 * 4);

    ppuStack_134 = &puStack_120;

    uStack_130 = FUN_005140d0();

    ppuStack_134 = (uint8_t **)0x0;

    (**(code **)(iVar2 + 0x15c))();

    iVar2 = **(int **)(unaff_EBX + 0x57c + param_1 * 4);

    uVar3 = (**(code **)(*in_EAX + 0x15c))(1,1);

    (**(code **)(iVar2 + 0x1d8))(uVar3);

    iVar2 = **(int **)(unaff_EBX + 0x57c + param_1 * 4);

    uVar3 = FUN_00514050(&ppuStack_134);

    (**(code **)(iVar2 + 0x15c))(1,uVar3);

    iVar2 = **(int **)(unaff_EBX + 0x564 + param_1 * 4);

    iVar4 = FUN_0092fb30();

    (**(code **)(iVar2 + 0x15c))(0,&DAT_00afdacc + iVar4 * 4);

    (**(code **)(**(int **)(unaff_EBX + 0x540 + param_1 * 4) + 4))(1);

    (**(code **)(**(int **)(unaff_EBX + 0x54c + param_1 * 4) + 4))(1);

    (**(code **)(**(int **)(unaff_EBX + 0x57c + param_1 * 4) + 4))(1);

    (**(code **)(**(int **)(unaff_EBX + 0x57c + param_1 * 4) + 0x34c))();

    (**(code **)(**(int **)(unaff_EBX + 0x558 + param_1 * 4) + 0x34c))();

    (**(code **)(**(int **)(unaff_EBX + 0x564 + param_1 * 4) + 0x180))();

    (**(code **)(**(int **)(unaff_EBX + 0x570 + param_1 * 4) + 0x34c))();

  }

  return;

}
