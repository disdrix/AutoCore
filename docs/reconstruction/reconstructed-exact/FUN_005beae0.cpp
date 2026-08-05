// =============================================================================
// FUN_005beae0
// -----------------------------------------------------------------------------
// Stable ID: aa_005beae0
// Address:   0x005beae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005beae0 @ 0x005beae0
// Stable ID: aa_005beae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_004b0b40×6, FUN_005beae0.
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

void __thiscall

FUN_005beae0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,int param_5,int param_6)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  int local_60;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  iVar1 = *(int *)(param_1 + 0xd0) * -0x10;

  uVar5 = param_3 + iVar1;

  param_5 = param_5 + iVar1;

  iVar1 = *(int *)(param_1 + 0xd4) * -0x10;

  uVar2 = param_6 + iVar1;

  param_4 = param_4 + iVar1;

  uVar2 = ((int)uVar2 < 1) - 1 & uVar2;

  if (0xe < param_4) {

    param_4 = 0xf;

  }

  uVar5 = ((int)uVar5 < 1) - 1 & uVar5;

  if (0xe < param_5) {

    param_5 = 0xf;

  }

  if ((int)uVar5 <= param_5) {

    puVar3 = (uint32_t /* width from decompiler */ *)((uVar5 * 0x10 + uVar2) * 0x180 + 0xe0 + param_1);

    local_60 = (param_5 - uVar5) + 1;

    do {

      if ((int)uVar2 <= param_4) {

        iVar1 = (param_4 - uVar2) + 1;

        puVar4 = puVar3;

        do {

          local_14 = puVar4[-2];

          local_10 = puVar4[-1];

          local_c = *puVar4;

          FUN_004b0b40(&local_14);

          local_14 = puVar4[0xe];

          local_10 = puVar4[0xf];

          local_c = puVar4[0x10];

          FUN_004b0b40(&local_14);

          local_14 = puVar4[0x1e];

          local_10 = puVar4[0x1f];

          local_c = puVar4[0x20];

          FUN_004b0b40(&local_14);

          local_14 = puVar4[0x2e];

          local_10 = puVar4[0x2f];

          local_c = puVar4[0x30];

          FUN_004b0b40(&local_14);

          local_14 = puVar4[0x3e];

          local_10 = puVar4[0x3f];

          local_c = puVar4[0x40];

          FUN_004b0b40(&local_14);

          local_14 = puVar4[0x4e];

          local_10 = puVar4[0x4f];

          local_c = puVar4[0x50];

          FUN_004b0b40(&local_14);

          puVar4 = puVar4 + 0x60;

          iVar1 = iVar1 + -1;

        } while (iVar1 != 0);

      }

      puVar3 = puVar3 + 0x600;

      local_60 = local_60 + -1;

    } while (local_60 != 0);

  }

  return;

}
