// =============================================================================
// FUN_007ac470
// -----------------------------------------------------------------------------
// Stable ID: aa_007ac470
// Address:   0x007ac470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ac470 @ 0x007ac470
// Stable ID: aa_007ac470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_007ac470.
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

void __thiscall FUN_007ac470(int *param_1,int *param_2)



{

  char *pcVar1;

  char cVar2;

  uint8_t uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  int iStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  

  iVar6 = *param_1;

  uStack_20 = 0;

  uStack_24 = 0x7ac48a;

  uStack_24 = (**(code **)(*param_2 + 0x164))();

  uStack_28 = 0;

  uStack_2c = 0x7ac495;

  (**(code **)(iVar6 + 0x154))();

  iVar6 = *param_1;

  uStack_2c = 1;

  uStack_30 = 0x7ac4a3;

  uStack_30 = (**(code **)(*param_2 + 0x164))();

  uStack_34 = 1;

  uStack_38 = 0x7ac4ae;

  (**(code **)(iVar6 + 0x154))();

  iVar6 = *param_1;

  uStack_38 = 2;

  uStack_3c = 0x7ac4bc;

  uStack_3c = (**(code **)(*param_2 + 0x164))();

  uStack_40 = 2;

  iStack_44 = 0x7ac4c7;

  (**(code **)(iVar6 + 0x154))();

  iVar6 = *param_1;

  iStack_44 = 0x7ac4d3;

  iStack_44 = (**(code **)(*param_2 + 0x2a0))();

  uStack_48 = 0x7ac4dc;

  (**(code **)(iVar6 + 0x29c))();

  iVar6 = *param_1;

  uStack_48 = 1;

  uStack_4c = 1;

  uVar4 = (**(code **)(*param_2 + 0x1dc))();

  (**(code **)(iVar6 + 0x1d8))(uVar4);

  param_1[0x4d] = param_2[0x4d];

  puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_2 + 0x140))(&uStack_3c,1);

  uStack_4c = *puVar5;

  uStack_48 = puVar5[1];

  (**(code **)(*param_1 + 8))(&uStack_4c);

  uVar3 = (**(code **)(*param_2 + 0x2c8))();

  iVar6 = *param_1;

  *(uint8_t *)((int)param_1 + 0xcf) = uVar3;

  uVar4 = (**(code **)(*param_2 + 0x298))(&uStack_48);

  (**(code **)(iVar6 + 0x294))(uVar4);

  iVar6 = (**(code **)(*param_2 + 0x290))();

  if (iVar6 != 0) {

    pcVar7 = (char *)(**(code **)(*param_2 + 0x28c))();

    pcVar1 = pcVar7 + 1;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    iStack_44 = (int)pcVar7 - (int)pcVar1;

    if (iStack_44 != 0) {

      iVar6 = *param_1;

      uVar4 = (**(code **)(*param_2 + 0x28c))();

      (**(code **)(iVar6 + 0x3c))(uVar4);

    }

  }

  iVar6 = (**(code **)(*param_2 + 700))();

  if (iVar6 != 0) {

    iVar6 = *param_1;

    uVar4 = (**(code **)(iVar6 + 0x2c8))(0);

    uVar4 = (**(code **)(*param_2 + 0x2b8))(uVar4);

    (**(code **)(iVar6 + 0x50))(uVar4);

  }

  return;

}
