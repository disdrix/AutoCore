// =============================================================================
// FUN_0055f280
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f280
// Address:   0x0055f280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055f280 @ 0x0055f280
// Stable ID: aa_0055f280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: block×6, FUN_0055e570×4, FUN_0055ed50, FUN_0055ede0, FUN_0055ef30, FUN_0055f280, FUN_005b3370.
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

/* WARNING: Removing unreachable block (ram,0x0055f440) */

/* WARNING: Removing unreachable block (ram,0x0055f3b8) */

/* WARNING: Removing unreachable block (ram,0x0055f2da) */

/* WARNING: Removing unreachable block (ram,0x0055f2fb) */

/* WARNING: Removing unreachable block (ram,0x0055f3d9) */

/* WARNING: Removing unreachable block (ram,0x0055f461) */



void FUN_0055f280(int param_1,int *param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_c;

  uint local_8;

  uint local_4;

  

  FUN_0055ed50();

  local_8 = 0;

  local_4 = 0x80000000;

  local_c = 0;

  FUN_0055e570(param_2[1],&local_c);

  if (0 < *(int *)(param_1 + 0x124)) {

    uVar1 = *(uint *)(param_1 + 0x124);

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x120);

    local_c = uVar2;

    local_8 = uVar1;

    local_4 = uVar1 | 0x80000000;

    FUN_0055e570(param_2[1],&local_c);

    if (-1 < (int)(uVar1 | 0x80000000)) {

      (**(code **)(*DAT_00b05060 + 0x14))(uVar2,uVar1 * 4,0x12);

    }

  }

  FUN_0055ede0(param_1);

  local_8 = 0;

  local_4 = 0x80000000;

  local_c = 0;

  FUN_0055e570(param_2[1],&local_c);

  FUN_0055ef30();

  local_8 = 0;

  local_4 = 0x80000000;

  local_c = 0;

  FUN_0055e570(param_2[1],&local_c);

  iVar3 = *(int *)(param_1 + 0xd0);

  if (iVar3 != 0) {

    if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

      FUN_005b3370(param_2,4);

    }

    *(int *)(*param_2 + param_2[1] * 4) = iVar3;

    param_2[1] = param_2[1] + 1;

  }

  return;

}
