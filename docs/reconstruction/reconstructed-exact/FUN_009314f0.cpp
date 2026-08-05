// =============================================================================
// FUN_009314f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009314f0
// Address:   0x009314f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009314f0 @ 0x009314f0
// Stable ID: aa_009314f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fca10×2, FUN_009314f0.
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

void FUN_009314f0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ local_28 [2];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  

  FUN_007fca10();

  FUN_007fca10();

  if (*(int *)(in_EAX + 0xe98) != 0) {

    iVar1 = *(int *)(in_EAX + 0xe98);

    local_28[0] = 0x9005;

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    local_20 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

    local_1c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    if (*(int *)(in_EAX + 0xc78) != 0) {

      (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,local_28,0x28,0);

    }

  }

  return;

}
