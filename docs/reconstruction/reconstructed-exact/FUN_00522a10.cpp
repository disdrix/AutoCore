// =============================================================================
// FUN_00522a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00522a10
// Address:   0x00522a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522a10 @ 0x00522a10
// Stable ID: aa_00522a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00522a10.
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

void __thiscall FUN_00522a10(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  uint8_t uVar6;

  char *pcVar7;

  char *pcVar8;

  uint64_t uVar9;

  

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_1);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_1);

  pcVar7 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x160)

                   )();

  pcVar8 = (char *)(param_2 + 0x60);

  do {

    cVar1 = *pcVar7;

    *pcVar8 = cVar1;

    pcVar7 = pcVar7 + 1;

    pcVar8 = pcVar8 + 1;

  } while (cVar1 != '\0');

  *(uint8_t *)(param_2 + 0x52) =

       *(uint8_t *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x531);

  uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

  *(uint8_t *)(param_2 + 0x50) = uVar6;

  *(uint8_t *)(param_2 + 0x51) =

       *(uint8_t *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x532);

  uVar3 = *(uint *)(param_1 + 0x720);

  uVar4 = *(uint *)(param_1 + 0x728);

  iVar2 = *(int *)(param_1 + 0x724);

  iVar5 = *(int *)(param_1 + 0x72c);

  *(uint *)(param_2 + 0x48) = uVar3 - *(uint *)(param_1 + 0x728);

  *(uint *)(param_2 + 0x4c) = (iVar2 - iVar5) - (uint)(uVar3 < uVar4);

  uVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x16c))();

  *(uint64_t *)(param_2 + 0x40) = uVar9;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6dc);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6e0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6e4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6e8);

  return;

}
