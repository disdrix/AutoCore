// =============================================================================
// FUN_004bf450
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf450
// Address:   0x004bf450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bf450 @ 0x004bf450
// Stable ID: aa_004bf450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004bf3f0×2, FUN_004bf770×2, FUN_0074c9c0×2, FUN_004bdef0, FUN_004bf450, FUN_005b7df0, FUN_00972cc0.
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

void __thiscall FUN_004bf450(int param_1,int param_2,char param_3)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

  if ((*(char *)(*(int *)(iVar1 + 0xa8 + param_2) + 0x7d) == '\0') &&

     ((*(uint *)(iVar1 + param_2 + 0x180) >> 0xe & 1) != 0)) {

    *(uint8_t *)(param_1 + 0x571) = 1;

    *(uint8_t *)(param_1 + 0x572) = 1;

    FUN_004bf3f0();

    return;

  }

  if (param_3 != '\0') {

    FUN_005b7df0(param_2);

  }

  cVar3 = FUN_004bdef0(param_2);

  puVar4 = operator_new(0xc);

  *puVar4 = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  puVar4[1] = param_2;

  *(uint8_t *)(puVar4 + 2) = 0;

  if (cVar3 == '\0') {

    *(uint8_t *)(puVar4 + 2) = 1;

    FUN_004bf770(puVar4);

    piVar2 = (int *)*puVar4;

    uVar5 = (**(code **)(*piVar2 + 0xc))();

    uVar6 = (**(code **)(*piVar2 + 0x48))(uVar5);

    FUN_0074c9c0(&DAT_00d1eb60,uVar6,uVar5);

  }

  else {

    piVar2 = (int *)*puVar4;

    uVar5 = (**(code **)(*piVar2 + 0xc))();

    uVar6 = (**(code **)(*piVar2 + 0x48))(uVar5);

    uVar7 = FUN_00972cc0(uVar6);

    FUN_0074c9c0(uVar7,uVar6,uVar5);

    *(uint8_t *)(param_1 + 0x571) = 1;

  }

  FUN_004bf770(puVar4);

  FUN_004bf3f0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5bc) = 0;

  return;

}
