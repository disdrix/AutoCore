// =============================================================================
// FUN_004553f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004553f0
// Address:   0x004553f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004553f0 @ 0x004553f0
// Stable ID: aa_004553f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_004553f0.
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

void __fastcall FUN_004553f0(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

  iVar3 = 7;

  puVar2 = in_EAX;

  do {

    *puVar2 = puVar1[-2];

    puVar2[1] = puVar1[-1];

    *(uint32_t /* width from decompiler */ *)(((int)in_EAX - param_1) + (int)puVar1) = *puVar1;

    puVar2 = puVar2 + 3;

    puVar1 = puVar1 + 3;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  in_EAX[0x15] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

  in_EAX[0x16] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58);

  puVar1 = in_EAX + 0x17;

  puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar1 + param_1 + (8 - (int)in_EAX));

  iVar3 = 7;

  do {

    *puVar1 = puVar2[-2];

    puVar1[1] = puVar2[-1];

    *(uint32_t /* width from decompiler */ *)((int)puVar2 + ((int)in_EAX - param_1)) = *puVar2;

    puVar1 = puVar1 + 3;

    puVar2 = puVar2 + 3;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
