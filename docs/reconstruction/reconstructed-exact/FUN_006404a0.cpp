// =============================================================================
// FUN_006404a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006404a0
// Address:   0x006404a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006404a0 @ 0x006404a0
// Stable ID: aa_006404a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00641680×2, FUN_006401e0, FUN_006404a0, FUN_006416b0, FUN_00641860, FUN_00641870, FUN_00641900, FUN_00641920.
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

void __fastcall FUN_006404a0(uint param_1)



{

  uint extraout_ECX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int local_24;

  uint8_t local_20 [32];

  

  FUN_00641960((uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_1 & 0xffffff00);

  local_24 = *(int *)(param_1 + 0x2c);

  if (0 < local_24) {

    iVar1 = 0;

    do {

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x28) + iVar1);

      FUN_006416b0(0xc2);

      FUN_00641920(*puVar2,puVar2[1]);

      FUN_006401e0(puVar2[2],local_20);

      FUN_00641870(*(uint32_t /* width from decompiler */ *)(param_1 + 8),extraout_ECX & 0xffffff00);

      FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

      FUN_00641860(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

      FUN_00641680();

      if ((uint32_t /* width from decompiler */ *)puVar2[2] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)puVar2[2])(1);

      }

      iVar1 = iVar1 + 0x10;

      local_24 = local_24 + -1;

    } while (local_24 != 0);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  FUN_00641680();

  return;

}
