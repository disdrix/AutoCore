// =============================================================================
// FUN_005df350
// -----------------------------------------------------------------------------
// Stable ID: aa_005df350
// Address:   0x005df350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005df350 @ 0x005df350
// Stable ID: aa_005df350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_005b3370, FUN_005df350.
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

void FUN_005df350(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int local_c;

  uint local_8;

  uint local_4;

  

  local_c = 0;

  local_8 = 0;

  local_4 = 0x80000000;

  FUN_005b3300(&local_c,0x10,4);

  for (iVar2 = DAT_00d030dc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {

    if (local_8 == (local_4 & 0x7fffffff)) {

      FUN_005b3370(&local_c,4);

    }

    *(int *)(local_c + local_8 * 4) = iVar2;

    local_8 = local_8 + 1;

  }

  iVar2 = local_8 - 1;

  while (-1 < iVar2) {

    puVar1 = (uint32_t /* width from decompiler */ *)**(int **)(*(int *)(local_c + iVar2 * 4) + 8);

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    iVar2 = iVar2 + -1;

    **(uint32_t /* width from decompiler */ **)(*(int *)(local_c + 4 + iVar2 * 4) + 8) = 0;

  }

  if (-1 < (int)local_4) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c,local_4 * 4,0x12);

  }

  return;

}
