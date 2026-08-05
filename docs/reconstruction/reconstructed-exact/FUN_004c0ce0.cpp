// =============================================================================
// FUN_004c0ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0ce0
// Address:   0x004c0ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c0ce0 @ 0x004c0ce0
// Stable ID: aa_004c0ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, for×2.
//  - Notable callees: CONCAT31, FUN_004c0ce0, FUN_007464e0, FUN_00746520.
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

uint __fastcall FUN_004c0ce0(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint *puVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if (*(int *)(param_1 + 0xc0) == 0) {

    uVar5 = *(uint *)(param_1 + 0xb0);

    *(uint32_t /* width from decompiler */ *)(uVar5 + 0xa8) = 0;

    return uVar5 & 0xffffff00;

  }

  iVar1 = *(int *)(param_1 + 0xb0);

  *(uint *)(iVar1 + 0xbc) = *(uint *)(iVar1 + 0xbc) | 1;

  iVar6 = *(int *)(iVar1 + 0x14);

  iVar2 = *(int *)(param_1 + 0xc0) * 4;

  if (*(int *)(iVar6 + 0x10) != 0) {

    if (iVar2 < 1) {

      iVar2 = *(int *)(iVar6 + 0x18);

    }

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),iVar2,1);

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar7 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xb4);

      for (uVar5 = (uint)(*(int *)(param_1 + 0xc0) * 0x70) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar3 = *puVar7;

        puVar7 = puVar7 + 1;

        puVar3 = puVar3 + 1;

      }

      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar7;

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

    }

  }

  if (*(int *)(*(int *)(iVar1 + 0x14) + 0x10) != 0) {

    FUN_007464e0();

  }

  *(int *)(*(int *)(param_1 + 0xb0) + 0xa8) = *(int *)(param_1 + 0xc0) * 6 + -4;

  puVar4 = (uint *)(*(int *)(param_1 + 0xb0) + 0xbc);

  *puVar4 = *puVar4 & 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  return CONCAT31((int3)((uint)puVar4 >> 8),1);

}
