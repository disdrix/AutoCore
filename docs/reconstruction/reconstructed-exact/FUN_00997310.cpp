// =============================================================================
// FUN_00997310
// -----------------------------------------------------------------------------
// Stable ID: aa_00997310
// Address:   0x00997310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00997310 @ 0x00997310
// Stable ID: aa_00997310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00401430×2, FUN_00401380, FUN_008024d0, FUN_00997310.
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

void FUN_00997310(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  bool bVar1;

  int in_EAX;

  int *piVar2;

  int local_30;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(in_EAX + 0xe98) != 0) {

    FUN_00401430();

    piVar2 = (int *)FUN_00401430();

    if ((*piVar2 == *(int *)(in_EAX + 0x3094)) && (local_30 == *(int *)(in_EAX + 0x154))) {

      bVar1 = false;

    }

    else {

      bVar1 = true;

    }

    if (bVar1) {

      if (local_30 != *(int *)(in_EAX + 0x154)) {

        FUN_008024d0(&DAT_00d1a840,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x302c),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3030)

                     ,0,0,0,param_1,param_2);

        return;

      }

    }

    else {

      FUN_00401380();

      local_4 = param_2;

      local_18[0] = 0x20b4;

      local_10 = param_3;

      local_c = param_4;

      local_8 = param_1;

      if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

        (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,local_18,0x18,0);

      }

    }

  }

  return;

}
