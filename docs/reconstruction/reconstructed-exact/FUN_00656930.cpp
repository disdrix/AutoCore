// =============================================================================
// FUN_00656930
// -----------------------------------------------------------------------------
// Stable ID: aa_00656930
// Address:   0x00656930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656930 @ 0x00656930
// Stable ID: aa_00656930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_00656690, FUN_00656930.
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

void __thiscall FUN_00656930(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int local_c [3];

  

  iVar4 = 0;

  local_c[0] = 0;

  local_c[1] = 0;

  local_c[2] = -0x80000000;

  FUN_00656690(local_c);

  iVar3 = *(int *)(param_1 + 0x9c) * 2;

  if ((int)(param_2[2] & 0x7fffffffU) < iVar3) {

    iVar5 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar5 <= iVar3) {

      iVar5 = iVar3;

    }

    FUN_005b3300(param_2,iVar5,0x10);

  }

  param_2[1] = iVar3;

  if (0 < *(int *)(param_1 + 0x9c)) {

    iVar3 = 0;

    iVar5 = 0;

    do {

      iVar1 = *param_2;

      *(uint32_t /* width from decompiler */ *)(iVar1 + iVar3) = *(uint32_t /* width from decompiler */ *)(local_c[0] + iVar5);

      iVar1 = iVar1 + iVar3;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = *(uint32_t /* width from decompiler */ *)(local_c[0] + 4 + iVar5);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = *(uint32_t /* width from decompiler */ *)(local_c[0] + iVar5 + 8);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = *(uint32_t /* width from decompiler */ *)(local_c[0] + iVar5 + 0xc);

      iVar1 = iVar5 + 0x10 + local_c[0];

      puVar2 = (uint32_t /* width from decompiler */ *)(*param_2 + iVar3 + 0x10);

      *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10 + local_c[0]);

      puVar2[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

      puVar2[2] = *(uint32_t /* width from decompiler */ *)(iVar1 + 8);

      puVar2[3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

      iVar4 = iVar4 + 1;

      iVar3 = iVar3 + 0x20;

      iVar5 = iVar5 + 0x10;

    } while (iVar4 < *(int *)(param_1 + 0x9c));

  }

  if (-1 < local_c[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c[0],local_c[2] << 4,0x12);

  }

  return;

}
