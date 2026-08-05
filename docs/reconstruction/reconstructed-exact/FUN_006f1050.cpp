// =============================================================================
// FUN_006f1050
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1050
// Address:   0x006f1050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1050 @ 0x006f1050
// Stable ID: aa_006f1050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_006f0fb0, FUN_006f1050.
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

uint __thiscall FUN_006f1050(int *param_1,uint param_2)



{

  int *piVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  byte bVar5;

  uint8_t uStack_119;

  int *local_118;

  uint32_t /* width from decompiler */ local_114;

  uint8_t local_110 [268];

  

  local_118 = param_1;

  while( true ) {

    piVar1 = local_118;

    param_2 = param_2 + 1;

    bVar5 = 0x20 - (byte)param_1[9];

    uVar2 = param_2 >> (bVar5 & 0x1f);

    local_114 = 0xffffffff;

    if (*(int *)(uVar2 * 0x30 + 0x18 + param_1[10]) <=

        (int)(0xffffffffU >> ((byte)param_1[9] & 0x1f) & param_2)) {

      bVar5 = 0x20 - (char)local_118[9];

      param_2 = uVar2 + 1 << (bVar5 & 0x1f);

    }

    if ((uint)local_118[0xb] <= param_2 >> (bVar5 & 0x1f)) break;

    uVar3 = (**(code **)(*local_118 + 0x34))(param_2,local_110);

    pcVar4 = (char *)FUN_006f0fb0(&uStack_119,uVar3);

    param_1 = piVar1;

    if (*pcVar4 == '\0') {

      return param_2;

    }

  }

  return 0xffffffff;

}
