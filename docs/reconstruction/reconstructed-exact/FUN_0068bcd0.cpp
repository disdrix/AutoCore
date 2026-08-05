// =============================================================================
// FUN_0068bcd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068bcd0
// Address:   0x0068bcd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068bcd0 @ 0x0068bcd0
// Stable ID: aa_0068bcd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_0056f570×2, FUN_0068bcd0, FUN_0069f950.
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

void __thiscall FUN_0068bcd0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint local_50;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint8_t local_3c [48];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa328;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 100) == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;

  }

  local_50 = uVar3 / 3 & 0xffff;

  if (local_50 != 0) {

    iVar4 = 0;

    ExceptionList = &local_c;

    do {

      iVar2 = *(int *)(param_1 + 100);

      local_40 = *(uint32_t /* width from decompiler */ *)(iVar4 + 8 + iVar2);

      local_44 = *(uint32_t /* width from decompiler */ *)(iVar4 + 4 + iVar2);

      local_48 = *(uint32_t /* width from decompiler */ *)(iVar4 + iVar2);

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_3c,&local_48);

      puVar5 = param_2;

      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar5 = *puVar1;

        puVar1 = puVar1 + 1;

        puVar5 = puVar5 + 1;

      }

      local_4 = 0;

      FUN_0056f570();

      local_4 = 0xffffffff;

      FUN_0056f570();

      iVar4 = iVar4 + 0xc;

      local_50 = local_50 - 1;

    } while (local_50 != 0);

  }

  ExceptionList = local_c;

  return;

}
