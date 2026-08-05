// =============================================================================
// FUN_005dd430
// -----------------------------------------------------------------------------
// Stable ID: aa_005dd430
// Address:   0x005dd430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dd430 @ 0x005dd430
// Stable ID: aa_005dd430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0043fb00, FUN_0057fb40, FUN_005db4a0, FUN_005dd430, FUN_005dd990, FUN_005ddbe0, FUN_005dde30, memmove.
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

void __thiscall FUN_005dd430(int param_1,int param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *pvVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar7 = *(int *)(*(int *)(param_2 + 4) + 4);

  local_20 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x84 + param_2);

  iVar7 = iVar7 + 0x84 + param_2;

  local_1c = *(uint32_t /* width from decompiler */ *)(iVar7 + 4);

  local_18 = *(uint32_t /* width from decompiler */ *)(iVar7 + 8);

  local_14 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc);

  FUN_005db4a0(&local_20);

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0xb8))

            (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xbc + param_2));

  pcVar4 = (char *)(param_2 + 0xe3);

  iVar7 = (param_1 + 0xe3) - (int)pcVar4;

  do {

    cVar1 = *pcVar4;

    pcVar4[iVar7] = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 300);

  iVar7 = *(int *)(param_1 + 300);

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x128);

  if (*(int *)(param_1 + 0x128) != iVar7) {

    uVar5 = FUN_0043fb00(iVar7,iVar7,*(int *)(param_1 + 0x128),uStack_28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 300) = uVar5;

  }

  FUN_005dd990(*(uint32_t /* width from decompiler */ *)(param_1 + 0x128),uVar3,uVar2,uStack_28);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x148);

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14c);

  if (*(void **)(param_1 + 0x148) != *(void **)(param_1 + 0x14c)) {

    pvVar6 = memmove(*(void **)(param_1 + 0x148),*(void **)(param_1 + 0x14c),0);

    *(void **)(param_1 + 0x14c) = pvVar6;

  }

  FUN_005ddbe0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x148),uVar2,uVar3,uVar2);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

  iVar7 = *(int *)(param_1 + 0x16c);

  if (*(int *)(param_1 + 0x168) != iVar7) {

    uVar5 = FUN_0057fb40(iVar7,iVar7,*(int *)(param_1 + 0x168),uVar3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = uVar5;

  }

  FUN_005dde30(*(uint32_t /* width from decompiler */ *)(param_1 + 0x168),uVar2,uVar3,uVar3);

  *(uint8_t *)(param_1 + 0xdc) = *(uint8_t *)(param_2 + 0xdc);

  *(uint8_t *)(param_1 + 0xde) = *(uint8_t *)(param_2 + 0xde);

  *(uint8_t *)(param_1 + 0xdf) = *(uint8_t *)(param_2 + 0xdf);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x154);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x158);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x15c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x178);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x17c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x180);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x184);

  *(uint8_t *)(param_1 + 0x188) = *(uint8_t *)(param_2 + 0x188);

  *(uint8_t *)(param_1 + 0x189) = *(uint8_t *)(param_2 + 0x189);

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = *(uint32_t /* width from decompiler */ *)(param_2 + 400);

  *(uint8_t *)(param_1 + 0xe0) = *(uint8_t *)(param_2 + 0xe0);

  *(uint8_t *)(param_1 + 0xe1) = *(uint8_t *)(param_2 + 0xe1);

  *(uint8_t *)(param_1 + 0x18b) = *(uint8_t *)(param_2 + 0x18b);

  return;

}
