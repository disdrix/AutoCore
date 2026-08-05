// =============================================================================
// FUN_00513b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00513b00
// Address:   0x00513b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513b00 @ 0x00513b00
// Stable ID: aa_00513b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00513b00.
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

void __fastcall FUN_00513b00(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  int *unaff_retaddr;

  

  iVar3 = (**(code **)(*param_1 + 0x210))(0);

  if (iVar3 != 0) {

    iVar3 = (**(code **)(*param_1 + 0x210))(0);

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x164 + iVar3);

    *unaff_ESI = *puVar1;

    unaff_ESI[1] = puVar1[1];

    unaff_ESI[2] = puVar1[2];

    unaff_ESI[3] = puVar1[3];

    return;

  }

  iVar3 = (**(code **)(*param_1 + 0x214))();

  if (iVar3 != 0) {

    iVar3 = (**(code **)(*param_1 + 0x214))();

    piVar2 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x164 + iVar3);

    *unaff_retaddr = *piVar2;

    unaff_retaddr[1] = piVar2[1];

    unaff_retaddr[2] = piVar2[2];

    unaff_retaddr[3] = piVar2[3];

    return;

  }

  *unaff_retaddr = param_1[0x58];

  unaff_retaddr[1] = param_1[0x59];

  unaff_retaddr[2] = param_1[0x5a];

  unaff_retaddr[3] = param_1[0x5b];

  return;

}
