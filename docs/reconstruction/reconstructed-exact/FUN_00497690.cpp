// =============================================================================
// FUN_00497690
// -----------------------------------------------------------------------------
// Stable ID: aa_00497690
// Address:   0x00497690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497690 @ 0x00497690
// Stable ID: aa_00497690
// Embedded strings (evidence for future rename):
//   - "_den.pgm"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00497690, FUN_007874b0, FUN_00787810, FUN_00793a10, FUN_00793f30.
//  - Strings: "_den.pgm".
//  - Return sites: 3.

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

char __thiscall FUN_00497690(uint8_t *param_1,char *param_2)



{

  char cVar1;

  uint8_t local_800 [1024];

  uint8_t local_400 [1024];

  

  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

    FUN_00793f30(local_400,local_800,param_2,&DAT_00a285c4,0x400);

    FUN_00793a10(local_800,local_400,"_den.pgm",0x400);

    cVar1 = FUN_00787810(local_800);

    if (cVar1 == '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

      FUN_007874b0(0,0);

      *param_1 = 1;

    }

    else {

      *param_1 = 0;

      *(int *)(param_1 + 4) = *(int *)(param_1 + 0xb8);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

      if (*(int *)(param_1 + 0xb8) < 1) {

        *param_1 = 1;

        return cVar1;

      }

    }

    return cVar1;

  }

  return '\0';

}
