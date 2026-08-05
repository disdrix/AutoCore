// =============================================================================
// FUN_00976d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00976d30
// Address:   0x00976d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00976d30 @ 0x00976d30
// Stable ID: aa_00976d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00976d30.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00976d30(int *param_1,int *param_2,int param_3)



{

  uint in_EAX;

  uint uVar1;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  if ((param_1 != (int *)0x0) && (*(int *)(param_3 + 0x14) != 0)) {

    if (param_2 == (int *)0x0) {

      local_28 = (int)((float)DAT_00d1e818 * DAT_00aaa7b8);

      local_24 = (int)((float)DAT_00d1e81c * _DAT_00aaa7b4);

    }

    else {

      local_28 = *param_2;

      local_24 = param_2[1];

    }

    uVar1 = in_EAX & 0x80000007;

    if ((int)uVar1 < 0) {

      uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;

    }

    local_c = ((int)(in_EAX + ((int)in_EAX >> 0x1f & 7U)) >> 3) * 0x20;

    local_4 = local_c + 0x20;

    local_10 = uVar1 * 0x20;

    local_8 = local_10 + 0x20;

    local_18 = 1;

    local_20 = 1;

    local_14 = 0;

    local_1c = 0;

    (**(code **)(*param_1 + 600))(*(int *)(param_3 + 0x14),&local_28,&local_10,&local_18,&local_20);

  }

  return;

}
