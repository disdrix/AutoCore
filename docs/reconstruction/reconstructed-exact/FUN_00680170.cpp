// =============================================================================
// FUN_00680170
// -----------------------------------------------------------------------------
// Stable ID: aa_00680170
// Address:   0x00680170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680170 @ 0x00680170
// Stable ID: aa_00680170
// Embedded strings (evidence for future rename):
//   - "Unable to find command"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: while×2, if×2, return×1.
//  - Notable callees: FUN_006808a0×2, FUN_00680170, FUN_0076c130.
//  - Strings: "Unable to find command".
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

void __fastcall FUN_00680170(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = 0;

  local_4 = 0;

  cVar2 = FUN_006808a0(&local_8);

  while (cVar2 != '\0') {

    puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 0x8c))[1];

    cVar2 = *(char *)((int)puVar5 + 0x15);

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x8c);

    while (cVar2 == '\0') {

      if ((int)puVar5[3] < local_8) {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar5[2];

        puVar5 = puVar1;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar5;

      }

      puVar1 = puVar5;

      puVar5 = puVar3;

      cVar2 = *(char *)((int)puVar3 + 0x15);

    }

    if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x8c)) {

      FUN_0076c130("Unable to find command");

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0xffffffff;

    }

    else {

      uVar4 = (*(code *)puVar1[4])(param_1,local_4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = uVar4;

    }

    cVar2 = FUN_006808a0(&local_8);

  }

  return;

}
