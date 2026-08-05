// =============================================================================
// FUN_00520b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00520b30
// Address:   0x00520b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00520b30 @ 0x00520b30
// Stable ID: aa_00520b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: GetTickCount×2, FUN_004c4e80, FUN_0051f230, FUN_00520b30.
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

uint32_t /* width from decompiler */ __thiscall FUN_00520b30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  DWORD DVar2;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if (((iVar1 == 0) || (*(char *)(iVar1 + 0xf5) == '\0')) && (*(int *)(param_1 + 0x250) != 0)) {

    if (*(int *)(param_1 + 0xd54) != 0) {

      DVar2 = GetTickCount();

      if (DVar2 <= *(int *)(param_1 + 0xd54) + 10000U) {

        return *(uint32_t /* width from decompiler */ *)(param_1 + 0xd44);

      }

    }

    DVar2 = GetTickCount();

    *(DWORD *)(param_1 + 0xd54) = DVar2;

    local_c = 0;

    local_8 = 0;

    local_4 = 0;

    FUN_0051f230(param_2,&local_c,&local_8,&local_4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd48) = local_c;

    FUN_004c4e80();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4c) = local_8;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd44) = param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd50) = local_4;

    return param_2;

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xd44);

}
