// =============================================================================
// FUN_005c5cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5cd0
// Address:   0x005c5cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5cd0 @ 0x005c5cd0
// Stable ID: aa_005c5cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_005c5cd0.
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

void __thiscall FUN_005c5cd0(int param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar4 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  cVar1 = *(char *)((int)puVar4 + 0x15);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    if (*param_3 < (float)puVar4[3] || *param_3 == (float)puVar4[3]) {

      puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)puVar4[2];

      puVar4 = puVar2;

    }

    puVar2 = puVar4;

    puVar4 = puVar3;

    cVar1 = *(char *)((int)puVar3 + 0x15);

  }

  if ((puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) &&

     ((float)puVar2[3] < *param_3 || (float)puVar2[3] == *param_3)) {

    *param_2 = puVar2;

    return;

  }

  *param_2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  return;

}
