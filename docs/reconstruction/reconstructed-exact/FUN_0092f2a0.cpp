// =============================================================================
// FUN_0092f2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f2a0
// Address:   0x0092f2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092f2a0 @ 0x0092f2a0
// Stable ID: aa_0092f2a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004faaf0, FUN_004fab40, FUN_0092f2a0.
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

void FUN_0092f2a0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int in_EAX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_28 [2];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  uint8_t local_7;

  

  if (in_EAX < 0) {

    in_EAX = 0;

  }

  if (param_3 == 0) {

    FUN_004faaf0(in_EAX);

  }

  else if (param_3 == 1) {

    FUN_004fab40(in_EAX);

  }

  local_28[0] = 0x2044;

  iVar2 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250);

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);

  local_18 = *puVar1;

  local_14 = puVar1[1];

  local_10 = puVar1[2];

  local_c = puVar1[3];

  local_8 = (uint8_t)in_EAX;

  local_7 = (uint8_t)param_3;

  local_20 = param_1;

  local_1c = param_2;

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_28,0x28,0);

  }

  return;

}
