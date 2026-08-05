// =============================================================================
// FUN_00476540
// -----------------------------------------------------------------------------
// Stable ID: aa_00476540
// Address:   0x00476540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476540 @ 0x00476540
// Stable ID: aa_00476540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1.
//  - Notable callees: FUN_00476540.
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

int __thiscall FUN_00476540(uint param_1,int param_2)



{

  uint in_EAX;

  int iVar1;

  byte *pbVar2;

  byte *pbVar3;

  bool bVar4;

  bool bVar5;

  byte local_8 [8];

  

  local_8[0] = 0x89;

  local_8[1] = 0x50;

  local_8[2] = 0x4e;

  local_8[3] = 0x47;

  local_8[4] = 0xd;

  local_8[5] = 10;

  local_8[6] = 0x1a;

  local_8[7] = 10;

  if (param_1 < 9) {

    if (param_1 == 0) {

      return 0;

    }

  }

  else {

    param_1 = 8;

  }

  if (7 < in_EAX) {

    return 0;

  }

  if (8 < in_EAX + param_1) {

    param_1 = 8 - in_EAX;

  }

  bVar4 = false;

  iVar1 = 0;

  bVar5 = true;

  pbVar2 = (byte *)(param_2 + in_EAX);

  pbVar3 = local_8 + in_EAX;

  do {

    if (param_1 == 0) break;

    param_1 = param_1 - 1;

    bVar4 = *pbVar2 < *pbVar3;

    bVar5 = *pbVar2 == *pbVar3;

    pbVar2 = pbVar2 + 1;

    pbVar3 = pbVar3 + 1;

  } while (bVar5);

  if (!bVar5) {

    iVar1 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);

  }

  return iVar1;

}
