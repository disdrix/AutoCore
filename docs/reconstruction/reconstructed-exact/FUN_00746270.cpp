// =============================================================================
// FUN_00746270
// -----------------------------------------------------------------------------
// Stable ID: aa_00746270
// Address:   0x00746270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746270 @ 0x00746270
// Stable ID: aa_00746270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: CONCAT22×2, FUN_00746270.
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

void __thiscall FUN_00746270(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  short sVar2;

  short sVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  sVar3 = 0;

  local_4 = 0xffffffff;

  while( true ) {

    if (puVar4 == puVar1) {

      *param_2 = local_4;

      return;

    }

    sVar2 = (**(code **)(*(int *)*puVar4 + 4))(param_3);

    local_4 = CONCAT22(sVar2,(uint16_t)local_4);

    if (-1 < sVar2) break;

    puVar4 = puVar4 + 1;

    sVar3 = sVar3 + 1;

  }

  local_4 = CONCAT22(sVar2,sVar3);

  *param_2 = local_4;

  return;

}
