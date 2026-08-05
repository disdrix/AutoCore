// =============================================================================
// FUN_004c2980
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2980
// Address:   0x004c2980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2980 @ 0x004c2980
// Stable ID: aa_004c2980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004c2980, FUN_004c2bb0, _time64.
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

void __thiscall FUN_004c2980(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _time64((__time64_t *)&local_8);

  puVar4 = operator_new(0x48);

  iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

  *puVar4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_2);

  puVar4[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_2);

  puVar4[9] = 1;

  puVar4[0xc] = *(uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x34);

  puVar4[10] = local_8;

  puVar4[0xb] = local_4;

  uVar6 = 0xffffffff;

  if ((*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) != 0) &&

     (iVar2 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2), iVar2 != -0xa0)) {

    uVar6 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xfc);

  }

  puVar4[7] = uVar6;

  puVar4[8] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x730);

  local_c = puVar4;

  pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x160)

                   )();

  pcVar7 = (char *)(puVar4 + 2);

  do {

    cVar1 = *pcVar5;

    *pcVar7 = cVar1;

    pcVar5 = pcVar5 + 1;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  iVar2 = *(int *)(param_1 + 500);

  if ((iVar2 != 0) &&

     ((uint)(*(int *)(param_1 + 0x1f8) - iVar2 >> 2) <

      (uint)(*(int *)(param_1 + 0x1fc) - iVar2 >> 2))) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1f8);

    *puVar3 = puVar4;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x1f8) = puVar3 + 1;

    return;

  }

  FUN_004c2bb0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1f8),1,&local_c);

  return;

}
