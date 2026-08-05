// =============================================================================
// FUN_005f5600
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5600
// Address:   0x005f5600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f5600 @ 0x005f5600
// Stable ID: aa_005f5600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005b3300, FUN_005f5600.
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

void __thiscall FUN_005f5600(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  

  param_2[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint8_t *)(param_2 + 2) = *(uint8_t *)(param_1 + 0x24);

  iVar5 = *(int *)(param_1 + 0x34);

  if ((int)(param_2[5] & 0x7fffffff) < iVar5) {

    iVar4 = (param_2[5] & 0x7fffffff) * 2;

    if (iVar4 <= iVar5) {

      iVar4 = iVar5;

    }

    FUN_005b3300(param_2 + 3,iVar4,8);

  }

  iVar5 = 0;

  if (*(int *)(param_1 + 0x34) < 1) {

    *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

    return;

  }

  do {

    iVar4 = param_2[4];

    iVar2 = param_2[3];

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x30) + iVar5 * 8);

    uVar3 = puVar1[1];

    *(uint32_t /* width from decompiler */ *)(iVar2 + iVar4 * 8) = *puVar1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + iVar4 * 8) = uVar3;

    param_2[4] = param_2[4] + 1;

    iVar5 = iVar5 + 1;

  } while (iVar5 < *(int *)(param_1 + 0x34));

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  return;

}
