// =============================================================================
// FUN_008697c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008697c0
// Address:   0x008697c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008697c0 @ 0x008697c0
// Stable ID: aa_008697c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_008697c0.
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

void FUN_008697c0(uint param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int *piVar3;

  int *unaff_ESI;

  int iVar4;

  uint uVar5;

  

  (**(code **)(*(int *)unaff_ESI[0x141] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x162] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x163] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x164] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x170] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x16f] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x165] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x167] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x18b] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x168] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x16b] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x16c] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x16d] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x16e] + 4))(param_1);

  uVar5 = param_1;

  (**(code **)(*(int *)unaff_ESI[0x171] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x18c] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x18d] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x18e] + 4))(param_1);

  cVar2 = (char)param_1;

  if (((char)param_1 != '\0') && ((unaff_ESI[0x152] & unaff_ESI[0x153]) == 0xffffffff)) {

    cVar2 = '\0';

    param_1 = uVar5 & 0xffffff00;

  }

  (**(code **)(*(int *)unaff_ESI[0x166] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x172] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x173] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x174] + 4))(param_1);

  piVar3 = unaff_ESI + 0x177;

  iVar4 = 5;

  do {

    if ((cVar2 == '\0') || (piVar3[-0x1c] == -1)) {

      uVar1 = 0;

    }

    else {

      uVar1 = 1;

    }

    (**(code **)(*(int *)piVar3[10] + 4))(uVar1);

    if ((cVar2 == '\0') || (piVar3[-0x1c] == -1)) {

      uVar1 = 0;

    }

    else {

      uVar1 = 1;

    }

    (**(code **)(*(int *)*piVar3 + 4))(uVar1);

    if ((cVar2 == '\0') || (piVar3[-0x1c] == -1)) {

      uVar1 = 0;

    }

    else {

      uVar1 = 1;

    }

    (**(code **)(*(int *)piVar3[5] + 4))(uVar1);

    piVar3 = piVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if ((cVar2 == '\0') || (unaff_ESI[0x15b] == -1)) {

    uVar1 = 0;

  }

  else {

    uVar1 = 1;

  }

  (**(code **)(*(int *)unaff_ESI[0x175] + 4))(uVar1);

  if ((cVar2 == '\0') || (unaff_ESI[0x15c] == -1)) {

    uVar1 = 0;

  }

  else {

    uVar1 = 1;

  }

  (**(code **)(*(int *)unaff_ESI[0x176] + 4))(uVar1);

  (**(code **)(*(int *)unaff_ESI[0x186] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x187] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x188] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x189] + 4))(param_1);

  (**(code **)(*(int *)unaff_ESI[0x18a] + 4))(param_1);

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
