// =============================================================================
// FUN_00974700
// -----------------------------------------------------------------------------
// Stable ID: aa_00974700
// Address:   0x00974700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974700 @ 0x00974700
// Stable ID: aa_00974700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0077bad0, FUN_0077bb70, FUN_0077bc40, FUN_009746a0, FUN_00974700.
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

void __fastcall FUN_00974700(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  

  if (*(int *)(in_EAX + 8) == 0) {

    *(int *)(in_EAX + 8) = param_1;

  }

  if (30000 < (uint)(param_1 - *(int *)(in_EAX + 4))) {

    uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20);

    *(int *)(in_EAX + 4) = param_1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c) = uVar1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x18) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

    FUN_009746a0();

    if (DAT_00d179d9 == '\0') {

      DAT_00d179d9 = '\x01';

      FUN_0077bc40(&DAT_00d0a3b8);

      FUN_0077bb70(&DAT_00d0a3b8);

    }

    FUN_0077bad0(in_EAX + 0xc,8,&DAT_00d0a3b8);

  }

  return;

}
