// =============================================================================
// FUN_00929730
// -----------------------------------------------------------------------------
// Stable ID: aa_00929730
// Address:   0x00929730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00929730 @ 0x00929730
// Stable ID: aa_00929730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×2, do×1.
//  - Notable callees: FUN_00929730.
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

bool FUN_00929730(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  int *piVar3;

  int *unaff_EDI;

  int local_70 [28];

  

  local_70[6] = 3;

  local_70[9] = 3;

  local_70[0] = 0x16;

  local_70[1] = 0;

  local_70[2] = 4;

  local_70[3] = 0;

  local_70[4] = 0x14;

  local_70[5] = 8;

  local_70[7] = 0;

  local_70[8] = 0x17;

  local_70[10] = 2;

  local_70[0xb] = 0;

  local_70[0xc] = 0x18;

  local_70[0xd] = 2;

  local_70[0xe] = 2;

  local_70[0xf] = 0;

  local_70[0x10] = 0x15;

  local_70[0x11] = 1;

  local_70[0x12] = 4;

  local_70[0x13] = 1;

  local_70[0x14] = 0x1a;

  local_70[0x15] = 5;

  local_70[0x16] = 2;

  local_70[0x17] = 1;

  local_70[0x18] = 0x19;

  local_70[0x19] = 4;

  local_70[0x1a] = 2;

  local_70[0x1b] = 1;

  uVar2 = 0;

  do {

    iVar1 = (**(code **)(*unaff_EDI + 0x28))();

    if (-1 < iVar1) {

      *(int *)(param_2 + 0x10) = local_70[uVar2 * 4];

      iVar1 = local_70[uVar2 * 4 + 2];

      *(int *)(param_2 + 0x20) = local_70[uVar2 * 4 + 1];

      *(int *)(param_2 + 0x18) = iVar1;

      break;

    }

    uVar2 = uVar2 + 1;

  } while (uVar2 < 7);

  if (uVar2 == 7) {

    return false;

  }

  uVar2 = 0;

  piVar3 = local_70;

  while ((piVar3[3] == 0 || (iVar1 = (**(code **)(*unaff_EDI + 0x28))(), iVar1 < 0))) {

    uVar2 = uVar2 + 1;

    piVar3 = piVar3 + 4;

    if (6 < uVar2) {

      return uVar2 != 7;

    }

  }

  *(int *)(param_2 + 0xc) = local_70[uVar2 * 4];

  iVar1 = local_70[uVar2 * 4 + 1];

  *(int *)(param_2 + 0x14) = local_70[uVar2 * 4 + 2];

  *(int *)(param_2 + 0x1c) = iVar1;

  return uVar2 != 7;

}
