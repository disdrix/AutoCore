// =============================================================================
// FUN_0086efc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086efc0
// Address:   0x0086efc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086efc0 @ 0x0086efc0
// Stable ID: aa_0086efc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0086ed60, FUN_0086efc0.
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

void FUN_0086efc0(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ local_20 [2];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  

  FUN_0086ed60();

  local_20[0] = 0x9016;

  iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

  local_18 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + DAT_00d1b6d8);

  local_14 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + DAT_00d1b6d8);

  local_8 = *(uint8_t *)(in_EAX + 0x510);

  local_10 = 0xffffffff;

  local_c = 0xffffffff;

  if (DAT_00d1b4bc != (int *)0x0) {

    cVar2 = (**(code **)(*DAT_00d1b4bc + 8))();

    if (cVar2 != '\0') {

      (**(code **)(*DAT_00d1b4bc + 0x18))(0xffffffff,local_20,0x20,0);

    }

  }

  return;

}
