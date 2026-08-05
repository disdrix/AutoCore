// =============================================================================
// FUN_004910e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004910e0
// Address:   0x004910e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004910e0 @ 0x004910e0
// Stable ID: aa_004910e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004910e0, FUN_0049c5f0, memmove.
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

void __fastcall FUN_004910e0(int param_1)



{

  size_t _Size;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int local_4;

  

  pvVar2 = *(void **)(param_1 + 0x168);

  local_4 = param_1;

  puVar1 = (uint32_t /* width from decompiler */ *)

           FUN_0049c5f0(&local_4,*(uint32_t /* width from decompiler */ *)(param_1 + 0x164),pvVar2,&stack0x00000004);

  if ((void *)*puVar1 != pvVar2) {

    _Size = (*(int *)(param_1 + 0x168) - (int)pvVar2 >> 2) * 4;

    pvVar2 = memmove((void *)*puVar1,pvVar2,_Size);

    *(void **)(param_1 + 0x168) = (void *)((int)pvVar2 + _Size);

  }

  return;

}
