// =============================================================================
// FUN_006f1570
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1570
// Address:   0x006f1570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1570 @ 0x006f1570
// Stable ID: aa_006f1570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006f1570.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006f1570(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  

  puVar3 = param_2;

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_00a0ede0;

  param_1[0xc] = 0x80000001;

  piVar1 = param_1 + 10;

  *piVar1 = (int)(param_1 + 0xd);

  param_1[0xb] = 0;

  param_1[0x15] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 1;

  param_1[0x16] = 0;

  param_1[0x14] = 0;

  param_1[8] = param_2[1];

  param_1[4] = param_2[4];

  param_1[5] = param_2[5];

  param_1[6] = param_2[6];

  param_1[7] = param_2[7];

  iVar2 = param_2[0x1c];

  if ((int)(param_1[0xc] & 0x7fffffff) < iVar2) {

    iVar5 = (param_1[0xc] & 0x7fffffff) * 2;

    if (iVar5 <= iVar2) {

      iVar5 = iVar2;

    }

    FUN_005b3300(piVar1,iVar5,0x30);

  }

  iVar5 = 0;

  param_1[0xb] = iVar2;

  if (0 < iVar2) {

    param_2 = (uint32_t /* width from decompiler */ *)0x0;

    do {

      puVar4 = (uint32_t /* width from decompiler */ *)(*piVar1 + (int)param_2);

      *puVar4 = *(uint32_t /* width from decompiler */ *)(puVar3[9] + iVar5 * 4);

      puVar4[1] = *(uint32_t /* width from decompiler */ *)(puVar3[0xc] + iVar5 * 4);

      puVar4[2] = *(uint32_t /* width from decompiler */ *)(puVar3[0xf] + iVar5 * 4);

      puVar4[3] = *(uint32_t /* width from decompiler */ *)(puVar3[0x12] + iVar5 * 4);

      *(uint8_t *)(puVar4 + 4) = *(uint8_t *)(iVar5 + puVar3[0x15]);

      puVar4[5] = *(uint32_t /* width from decompiler */ *)(puVar3[0x18] + iVar5 * 4);

      puVar4[6] = *(uint32_t /* width from decompiler */ *)(puVar3[0x1b] + iVar5 * 4);

      puVar4[7] = *(uint32_t /* width from decompiler */ *)(puVar3[0x1e] + iVar5 * 4);

      puVar4[8] = *(uint32_t /* width from decompiler */ *)(puVar3[0x21] + iVar5 * 4);

      puVar4[9] = *(uint32_t /* width from decompiler */ *)(puVar3[0x24] + iVar5 * 4);

      puVar4[10] = *(uint32_t /* width from decompiler */ *)(puVar3[0x27] + iVar5 * 4);

      puVar4[0xb] = *(uint32_t /* width from decompiler */ *)(puVar3[0x2a] + iVar5 * 4);

      if (puVar4[7] == 0) {

        puVar4[0xb] = 1;

        puVar4[9] = &DAT_00bc5630;

        puVar4[7] = &DAT_00bc5630;

      }

      iVar5 = iVar5 + 1;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 0x30);

    } while (iVar5 < iVar2);

  }

  param_1[9] = puVar3[8];

  return param_1;

}
