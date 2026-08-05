// =============================================================================
// FUN_008d7350
// -----------------------------------------------------------------------------
// Stable ID: aa_008d7350
// Address:   0x008d7350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d7350 @ 0x008d7350
// Stable ID: aa_008d7350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, goto×3.
//  - Notable callees: FUN_0087b500×5, FUN_008d7350.
//  - Return sites: 5.

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

void __thiscall FUN_008d7350(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar2 = DAT_00aaa6c8;

  uVar1 = DAT_00aaa6c4;

  if (param_3 == 0x9c42) {

    if (param_2 == 7) {

      *(uint8_t *)(param_1 + 0x56c) = 1;

    }

LAB_008d740c:

    FUN_0087b500(param_2,param_3);

    return;

  }

  if (param_3 == 0x9c43) {

    if (param_2 == 6) goto LAB_008d73a5;

    if (param_2 == 7) {

      *(uint8_t *)(param_1 + 0x56d) = 1;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = uVar1;

      FUN_0087b500(7,0x9c43);

      return;

    }

  }

  else {

    if (param_3 != 0x9c44) goto LAB_008d740c;

    if (param_2 == 6) goto LAB_008d73a5;

    if (param_2 == 7) {

      *(uint8_t *)(param_1 + 0x56d) = 1;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = uVar2;

      FUN_0087b500(7,0x9c44);

      return;

    }

  }

  if (param_2 != 8) {

    FUN_0087b500(param_2,param_3);

    return;

  }

LAB_008d73a5:

  *(uint8_t *)(param_1 + 0x56d) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = 0;

  FUN_0087b500(param_2,param_3);

  return;

}
