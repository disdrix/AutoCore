// =============================================================================
// FUN_005c6170
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6170
// Address:   0x005c6170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c6170 @ 0x005c6170
// Stable ID: aa_005c6170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_005c5fe0, FUN_005c6170.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005c6170(int param_1,float *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float local_8;

  uint16_t local_4;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  cVar1 = *(char *)((int)puVar5 + 0x15);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    if (*param_2 < (float)puVar5[3] || *param_2 == (float)puVar5[3]) {

      puVar3 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)puVar5[2];

      puVar5 = puVar2;

    }

    puVar2 = puVar5;

    puVar5 = puVar3;

    cVar1 = *(char *)((int)puVar3 + 0x15);

  }

  if ((puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) &&

     ((float)puVar2[3] < *param_2 || (float)puVar2[3] == *param_2)) {

    return puVar2 + 4;

  }

  local_8 = *param_2;

  local_4 = 0;

  piVar4 = (int *)FUN_005c5fe0(&param_2,puVar2,&local_8);

  return (uint32_t /* width from decompiler */ *)(*piVar4 + 0x10);

}
