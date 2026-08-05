// =============================================================================
// FUN_00710bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00710bf0
// Address:   0x00710bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710bf0 @ 0x00710bf0
// Stable ID: aa_00710bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×10, return×10, for×2.
//  - Notable callees: CONCAT22, FUN_00710bf0, FUN_00711f10.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ FUN_00710bf0(int *param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_64 [12];

  uint32_t /* width from decompiler */ local_34 [13];

  

  if ((param_1 == (int *)0x0) || (*param_1 != 0xface)) {

    return 0x17d4;

  }

  if ((char)param_1[3] != '\v') {

    return 0x17e3;

  }

  if (param_2 == (int *)0x0) {

    return 0x181a;

  }

  if (param_2[2] == 0) {

    return 0x17f2;

  }

  if (*param_2 == 0) {

    return 0x17ed;

  }

  if (*(ushort *)(param_2 + 3) <= *(ushort *)((int)param_2 + 0xe)) {

    return 0x1801;

  }

  if (*(ushort *)(param_2 + 3) <= *(ushort *)((int)param_2 + 0x12)) {

    return 0x1806;

  }

  if (7 < *(byte *)(param_2 + 4)) {

    return 0x17f7;

  }

  if (7 < *(byte *)(param_2 + 5)) {

    return 0x17fc;

  }

  param_1[7] = (int)param_2;

  FUN_00711f10(param_1[4],*param_2,param_2 + 1,param_2[2],

               CONCAT22((short)((uint)(param_2 + 4) >> 0x10),(short)param_2[3]),

               (ushort *)((int)param_2 + 0xe),param_2 + 4,local_64,local_34,&param_1);

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_3 = param_1;

    puVar2 = local_34;

    puVar3 = param_3;

    for (iVar1 = 0xc; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

    }

    puVar3 = local_64;

    puVar2 = param_3 + 0xd;

    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar2 = puVar2 + 1;

    }

  }

  return 0;

}
