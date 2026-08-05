// =============================================================================
// FUN_007462e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007462e0
// Address:   0x007462e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007462e0 @ 0x007462e0
// Stable ID: aa_007462e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: CONCAT22, FUN_007462e0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ * FUN_007462e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  short sVar3;

  int in_EAX;

  short sVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar2 = param_1;

  if (DAT_00d1f644 != 0) {

    *(uint16_t *)param_1 = 0xffff;

    *(uint16_t *)((int)param_1 + 2) = 0xffff;

    return param_1;

  }

  puVar5 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

  sVar4 = 0;

  DAT_00d1f644 = 1;

  while( true ) {

    if (puVar5 == puVar1) {

      *(uint16_t *)param_1 = 0xffff;

      *(uint16_t *)((int)param_1 + 2) = 0xffff;

      DAT_00d1f644 = 0;

      return param_1;

    }

    sVar3 = (**(code **)(*(int *)*puVar5 + 8))(param_2);

    if (-1 < sVar3) break;

    puVar5 = puVar5 + 1;

    sVar4 = sVar4 + 1;

  }

  param_1 = (uint32_t /* width from decompiler */ *)CONCAT22(sVar3,sVar4);

  *puVar2 = param_1;

  DAT_00d1f644 = 0;

  return puVar2;

}
