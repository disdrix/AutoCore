// =============================================================================
// FUN_0041de50
// -----------------------------------------------------------------------------
// Stable ID: aa_0041de50
// Address:   0x0041de50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041de50 @ 0x0041de50
// Stable ID: aa_0041de50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0041de50, FUN_00421aa0, FUN_004229e0.
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

int FUN_0041de50(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char param_3,uint32_t /* width from decompiler */ param_4)



{

  int in_EAX;

  int iVar1;

  uint8_t *puVar2;

  uint8_t local_c [4];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(in_EAX + 0xc) == 0) {

    puVar2 = (uint8_t *)0x0;

  }

  else {

    iVar1 = FUN_004229e0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x24),local_c);

    if (iVar1 < 0) {

      return iVar1;

    }

    local_4 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x28);

    local_8 = 1;

    puVar2 = local_c;

  }

  iVar1 = FUN_00421aa0((int *)(in_EAX + 0x10),puVar2,param_2,param_4);

  if (((-1 < iVar1) && (param_3 != '\0')) && (*(int *)(in_EAX + 4) != 0)) {

    iVar1 = (-(uint)(*(int *)(in_EAX + 0x10) != 0) & 0x7fffbffb) + 0x80004005;

  }

  return iVar1;

}
