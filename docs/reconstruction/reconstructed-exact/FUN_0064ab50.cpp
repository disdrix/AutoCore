// =============================================================================
// FUN_0064ab50
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ab50
// Address:   0x0064ab50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ab50 @ 0x0064ab50
// Stable ID: aa_0064ab50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0064ab50.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0064ab50(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  *param_1 = &PTR_LAB_009cc290;

  *(uint16_t *)(param_1 + 1) = *(uint16_t *)(param_2 + 4);

  *(uint16_t *)((int)param_1 + 6) = *(uint16_t *)(param_2 + 6);

  *param_1 = &PTR_FUN_009e4954;

  param_1[2] = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  param_1[3] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  iVar2 = *(int *)(param_2 + 0x14);

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(iVar2 * 0x30,0x12);

  iVar4 = 0;

  param_1[4] = iVar1;

  param_1[5] = iVar2;

  param_1[6] = iVar2;

  if (0 < *(int *)(param_2 + 0x14)) {

    puVar3 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x18);

    do {

      if (puVar3 != (uint32_t /* width from decompiler */ *)0x18) {

        iVar2 = *(int *)(param_2 + 0x10);

        puVar3[-6] = &PTR_LAB_009cc290;

        iVar2 = iVar2 + (-0x18 - iVar1);

        *(uint16_t *)(puVar3 + -5) = *(uint16_t *)(iVar2 + 4 + (int)puVar3);

        *(uint16_t *)((int)puVar3 + -0x12) = *(uint16_t *)(iVar2 + 6 + (int)puVar3);

        puVar3[-6] = &PTR_LAB_009e4950;

        puVar3[-2] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x10);

        puVar3[-1] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x14);

        *puVar3 = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x18);

        puVar3[1] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x1c);

        puVar3[2] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x20);

        puVar3[3] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x24);

        puVar3[4] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x28);

        puVar3[5] = *(uint32_t /* width from decompiler */ *)((int)puVar3 + iVar2 + 0x2c);

      }

      iVar4 = iVar4 + 1;

      puVar3 = puVar3 + 0xc;

    } while (iVar4 < *(int *)(param_2 + 0x14));

  }

  return param_1;

}
