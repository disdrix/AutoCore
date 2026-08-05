// =============================================================================
// FUN_004254a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004254a0
// Address:   0x004254a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004254a0 @ 0x004254a0
// Stable ID: aa_004254a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: CONCAT31, FUN_004254a0, FUN_00426180.
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

uint __fastcall FUN_004254a0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint in_EAX;

  uint uVar1;

  uint uVar2;

  

  uVar1 = in_EAX;

  if (*(int *)(in_EAX + 0x128) == 0) {

    if (*(int *)(in_EAX + 0x114) == 0) {

      *(int *)(in_EAX + 0x114) = param_2;

    }

    uVar1 = *(uint *)(in_EAX + 0xac);

    uVar2 = *(uint *)(in_EAX + 0xb0);

    if ((*(byte *)(in_EAX + 0xb4) & 0xc) != 0) {

      if (*(int *)(in_EAX + 0x94) == *(int *)(in_EAX + 0x90)) {

        uVar2 = 4;

        if (*(int *)(in_EAX + 0x110) == 0) {

          uVar1 = 60000;

        }

      }

      else {

        uVar1 = 3000;

      }

    }

    if (uVar1 < (uint)(param_2 - *(int *)(in_EAX + 0x114))) {

      uVar1 = *(uint *)(in_EAX + 0x110);

      if (uVar2 <= uVar1) {

        return CONCAT31((int3)(uVar1 >> 8),1);

      }

      *(int *)(in_EAX + 0x114) = param_2;

      *(uint *)(in_EAX + 0x110) = uVar1 + 1;

      uVar1 = FUN_00426180();

    }

  }

  return uVar1 & 0xffffff00;

}
