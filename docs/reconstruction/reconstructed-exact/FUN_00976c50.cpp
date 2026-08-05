// =============================================================================
// FUN_00976c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00976c50
// Address:   0x00976c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00976c50 @ 0x00976c50
// Stable ID: aa_00976c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, goto×1, return×1.
//  - Notable callees: FUN_00976c50.
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



void __thiscall FUN_00976c50(int *param_1,int param_2,int param_3)



{

  int *in_EAX;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (in_EAX == (int *)0x0) {

    local_28 = (int)((float)DAT_00d1e818 * _DAT_00a10e38);

    local_24 = (int)((float)DAT_00d1e81c * _DAT_00aaa7b0);

  }

  else {

    local_28 = *in_EAX;

    local_24 = in_EAX[1];

  }

  if (param_3 == 0) {

    local_10 = 0;

    local_8 = 0x14;

  }

  else if (param_3 == 1) {

    local_10 = 0x15;

    local_8 = 0x29;

  }

  else {

    if (param_3 != 2) goto LAB_00976cee;

    local_10 = 0x2a;

    local_8 = 0x3e;

  }

  local_c = 10;

  local_4 = 0x20;

LAB_00976cee:

  local_18 = 1;

  local_20 = 1;

  local_14 = 0;

  local_1c = 0;

  (**(code **)(*param_1 + 600))

            (*(uint32_t /* width from decompiler */ *)(param_2 + 0x18),&local_28,&local_10,&local_18,&local_20);

  return;

}
