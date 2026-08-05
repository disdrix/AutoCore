// =============================================================================
// FUN_006c0d20
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0d20
// Address:   0x006c0d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c0d20 @ 0x006c0d20
// Stable ID: aa_006c0d20
// Embedded strings (evidence for future rename):
//   - "rigidbodysoftcloth"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: do×5, while×5, if×4, return×1.
//  - Notable callees: FUN_006c0d20.
//  - Strings: "rigidbodysoftcloth".
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

int FUN_006c0d20(char *param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int local_184;

  uint local_180 [64];

  byte abStack_80 [128];

  

  local_180[0] = 2;

  local_180[1] = 3;

  local_180[3] = 2;

  local_180[4] = 3;

  local_180[7] = 3;

  local_180[8] = 2;

  local_180[10] = 3;

  local_180[0xc] = 2;

  local_180[0xd] = 2;

  local_180[0xe] = 3;

  local_180[0xf] = 3;

  local_180[0x10] = 2;

  local_180[0x11] = 3;

  local_180[0x13] = 2;

  local_180[0x14] = 3;

  local_180[0x17] = 3;

  local_180[0x18] = 2;

  local_180[0x1a] = 3;

  local_180[0x1c] = 2;

  local_180[0x1d] = 2;

  local_180[0x1e] = 3;

  local_180[0x1f] = 3;

  local_180[0x20] = 2;

  local_180[0x21] = 3;

  local_180[0x23] = 2;

  local_180[0x24] = 3;

  local_180[0x27] = 3;

  local_180[0x28] = 2;

  local_180[0x2a] = 3;

  local_180[0x2c] = 2;

  local_180[0x2d] = 2;

  local_180[0x2e] = 3;

  local_180[0x2f] = 3;

  local_180[0x30] = 2;

  local_180[0x31] = 3;

  local_180[0x33] = 2;

  local_180[0x34] = 3;

  local_180[0x37] = 3;

  local_180[0x38] = 2;

  local_180[0x3a] = 3;

  local_180[0x3c] = 2;

  local_180[0x3d] = 2;

  local_180[0x3e] = 3;

  local_180[0x3f] = 3;

  local_180[2] = 1;

  local_180[5] = 1;

  local_180[6] = 4;

  local_180[9] = 1;

  local_180[0xb] = 1;

  local_180[0x12] = 1;

  local_180[0x15] = 1;

  local_180[0x16] = 4;

  local_180[0x19] = 1;

  local_180[0x1b] = 1;

  local_180[0x22] = 1;

  local_180[0x25] = 1;

  local_180[0x26] = 4;

  local_180[0x29] = 1;

  local_180[0x2b] = 1;

  local_180[0x32] = 1;

  local_180[0x35] = 1;

  local_180[0x36] = 4;

  local_180[0x39] = 1;

  local_180[0x3b] = 1;

  iVar1 = 0;

  iVar4 = 0x40;

  do {

    abStack_80[iVar1 + 0x7f] = 0;

    abStack_80[iVar1 + 0x3f] = 0;

    iVar1 = iVar1 + -1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = 0;

  iVar1 = 0x40 - (int)param_1;

  do {

    if (*param_1 == '\0') break;

    iVar4 = iVar4 + 1;

    param_1[(int)(abStack_80 + iVar1)] = *param_1;

    param_1 = param_1 + 1;

  } while (iVar4 < 0x40);

  iVar1 = 0;

  do {

    if ("rigidbodysoftcloth"[iVar1] == 0) break;

    abStack_80[iVar1] = "rigidbodysoftcloth"[iVar1];

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x40);

  local_184 = 0;

  uVar5 = 0xc18f77a2;

  iVar1 = 1;

  iVar4 = 0;

  do {

    uVar2 = (char)(abStack_80[iVar4] ^ abStack_80[iVar4 + 0x40]) * 0x1010101;

    if (iVar1 == 0) {

      uVar2 = uVar2 / local_180[iVar4];

    }

    else {

      uVar2 = local_180[iVar4] * uVar2;

    }

    local_184 = local_184 + uVar2;

    iVar1 = 1 - iVar1;

    iVar3 = 0;

    if (0 < iVar4) {

      do {

        uVar5 = uVar5 * 2 ^

                ((int)(char)abStack_80[iVar3] + (int)(char)abStack_80[iVar3 + 0x40]) * 0x1010101;

        local_184 = local_184 + uVar5;

        iVar3 = iVar3 + 1;

      } while (iVar3 < iVar4);

    }

    iVar4 = iVar4 + 1;

  } while (iVar4 < 0x40);

  return local_184;

}
