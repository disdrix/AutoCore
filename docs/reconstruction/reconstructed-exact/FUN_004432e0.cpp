// =============================================================================
// FUN_004432e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004432e0
// Address:   0x004432e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004432e0 @ 0x004432e0
// Stable ID: aa_004432e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00442fa0, FUN_004432e0.
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

void __fastcall FUN_004432e0(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int in_EAX;

  

  puVar1 = (uint32_t /* width from decompiler */ *)*param_1;

  iVar2 = *(int *)(in_EAX + 8);

  *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar2 + -0x14);

  puVar1[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + -0x10);

  puVar1[2] = *(uint32_t /* width from decompiler */ *)(iVar2 + -0xc);

  puVar1[3] = *(uint32_t /* width from decompiler */ *)(iVar2 + -8);

  puVar1[4] = *(uint32_t /* width from decompiler */ *)(iVar2 + -4);

  FUN_00442fa0(0,0,0,0,0);

  return;

}
