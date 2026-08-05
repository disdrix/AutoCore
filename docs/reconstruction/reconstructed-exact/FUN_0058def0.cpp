// =============================================================================
// FUN_0058def0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058def0
// Address:   0x0058def0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058def0 @ 0x0058def0
// Stable ID: aa_0058def0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0058da40, FUN_0058def0.
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

void __thiscall FUN_0058def0(int param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  float fVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  bool bVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  puVar7 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  bVar4 = true;

  cVar2 = *(char *)((int)puVar7 + 0x29);

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar2 == '\0') {

    fVar1 = (float)puVar7[4];

    if (fVar1 < *param_3 || fVar1 == *param_3) {

      puVar6 = (uint32_t /* width from decompiler */ *)puVar7[2];

    }

    else {

      puVar6 = (uint32_t /* width from decompiler */ *)*puVar7;

    }

    bVar4 = fVar1 >= *param_3 && fVar1 != *param_3;

    puVar5 = puVar7;

    puVar7 = puVar6;

    cVar2 = *(char *)((int)puVar6 + 0x29);

  }

  puVar7 = (uint32_t /* width from decompiler */ *)FUN_0058da40(&param_3,bVar4,puVar5,param_3);

  uVar3 = *puVar7;

  *(uint8_t *)(param_2 + 1) = 1;

  *param_2 = uVar3;

  return;

}
