// =============================================================================
// FUN_00570340
// -----------------------------------------------------------------------------
// Stable ID: aa_00570340
// Address:   0x00570340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00570340 @ 0x00570340
// Stable ID: aa_00570340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1.
//  - Notable callees: FUN_004e2ca0, FUN_00570340.
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

uint32_t /* width from decompiler */ __thiscall FUN_00570340(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  

  if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_4 = 0;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)

            (*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);

  while( true ) {

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

      return 0x80004005;

    }

    if (*(code **)(param_1 + 0x34) == (code *)0x0) {

      cVar2 = param_2 == puVar1[4];

    }

    else {

      cVar2 = (**(code **)(param_1 + 0x34))(puVar1[2],param_3);

    }

    if (cVar2 != '\0') break;

    puVar1 = (uint32_t /* width from decompiler */ *)puVar1[3];

  }

  FUN_004e2ca0(puVar1[4]);

  if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_4 = puVar1[2];

  }

  puVar1[2] = 0;

  if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x14)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = puVar1[5];

  }

  else {

    *(uint32_t /* width from decompiler */ *)(puVar1[6] + 0x14) = puVar1[5];

  }

  if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x18)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = puVar1[6];

  }

  else {

    *(uint32_t /* width from decompiler */ *)(puVar1[5] + 0x18) = puVar1[6];

  }

  *puVar1 = &PTR_LAB_009d2fa4;

  *puVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar1;

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

  return 0;

}
