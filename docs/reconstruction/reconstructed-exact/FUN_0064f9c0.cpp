// =============================================================================
// FUN_0064f9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064f9c0
// Address:   0x0064f9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064f9c0 @ 0x0064f9c0
// Stable ID: aa_0064f9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0064f9c0, FUN_0065e1d0.
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

void __thiscall FUN_0064f9c0(int param_1,int param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t *puVar3;

  int iVar4;

  int iVar5;

  

  FUN_0065e1d0(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  uVar1 = *(uint *)(param_2 + 0x14) & 0x7fffffff;

  if ((int)uVar1 < *(int *)(param_1 + 0x30)) {

    if (-1 < (int)*(uint *)(param_2 + 0x14)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 0xc),uVar1,0x12);

    }

    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x30),0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = uVar2;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  }

  puVar3 = *(uint8_t **)(param_2 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  iVar5 = *(int *)(param_1 + 0x30);

  if (0 < iVar5) {

    iVar4 = *(int *)(param_1 + 0x2c) - (int)puVar3;

    do {

      *puVar3 = puVar3[iVar4];

      puVar3 = puVar3 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  return;

}
