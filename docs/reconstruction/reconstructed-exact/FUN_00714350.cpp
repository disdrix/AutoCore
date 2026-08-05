// =============================================================================
// FUN_00714350
// -----------------------------------------------------------------------------
// Stable ID: aa_00714350
// Address:   0x00714350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714350 @ 0x00714350
// Stable ID: aa_00714350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×4, do×3, while×3, return×1.
//  - Notable callees: FUN_00714350, FUN_00714450.
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

void FUN_00714350(uint32_t /* width from decompiler */ *param_1,int param_2,byte param_3,uint32_t /* width from decompiler */ *param_4,

                 uint32_t /* width from decompiler */ *param_5)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  

  bVar1 = param_3 & 0x1f;

  iVar2 = param_2 >> 2;

  iVar7 = 0x100 - iVar2;

  puVar4 = param_4 + iVar7;

  puVar5 = param_5 + iVar7;

  _param_3 = iVar2;

  if (0 < iVar2) {

    do {

      puVar6 = param_1 + 1;

      *puVar4 = *param_1;

      puVar4 = puVar4 + 1;

      param_1 = param_1 + 2;

      *puVar5 = *puVar6;

      puVar5 = puVar5 + 1;

      _param_3 = _param_3 + -1;

    } while (_param_3 != 0);

  }

  iVar3 = param_2 + iVar2 * -2 >> 1;

  puVar4 = param_4;

  iVar2 = 0;

  puVar5 = param_5;

  _param_3 = iVar3;

  if (0 < iVar3) {

    do {

      puVar6 = param_1 + 1;

      *puVar4 = *param_1;

      puVar4 = puVar4 + 1;

      param_1 = param_1 + 2;

      *puVar5 = *puVar6;

      puVar5 = puVar5 + 1;

      _param_3 = _param_3 + -1;

      iVar2 = iVar3;

    } while (_param_3 != 0);

  }

  puVar6 = puVar5;

  if (param_2 != (param_2 >> 1) * 2) {

    puVar6 = puVar5 + 1;

    *puVar4 = *param_1;

    *puVar5 = 0;

    puVar4 = puVar4 + 1;

    iVar2 = iVar2 + 1;

  }

  if (iVar2 < iVar7) {

    iVar7 = iVar7 - iVar2;

    do {

      *puVar4 = 0;

      *puVar6 = 0;

      puVar4 = puVar4 + 1;

      puVar6 = puVar6 + 1;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  FUN_00714450(param_4,param_5,1 << bVar1);

  return;

}
