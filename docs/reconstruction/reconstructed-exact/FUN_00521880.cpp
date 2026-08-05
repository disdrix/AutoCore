// =============================================================================
// FUN_00521880
// -----------------------------------------------------------------------------
// Stable ID: aa_00521880
// Address:   0x00521880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521880 @ 0x00521880
// Stable ID: aa_00521880
// Embedded strings (evidence for future rename):
//   - "Unknown"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_007a69d0×4, FUN_007a6de0×4, FUN_00521880.
//  - Strings: "Unknown".
//  - Return sites: 4.

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

void __fastcall FUN_00521880(int param_1)



{

  char cVar1;

  char *pcVar2;

  undefined *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                   + 0x532);

  if (cVar1 == '\0') {

    uVar4 = 0xffffffff;

    puVar3 = &DAT_009cef04;

    FUN_007a69d0(&DAT_009cef04,0xffffffff);

    FUN_007a6de0(puVar3,uVar4);

    return;

  }

  if (cVar1 != '\x01') {

    if (cVar1 != '\x02') {

      uVar4 = 0xffffffff;

      pcVar2 = "Unknown";

      FUN_007a69d0("Unknown",0xffffffff);

      FUN_007a6de0(pcVar2,uVar4);

      return;

    }

    uVar4 = 0xffffffff;

    puVar3 = &DAT_009cef0c;

    FUN_007a69d0(&DAT_009cef0c,0xffffffff);

    FUN_007a6de0(puVar3,uVar4);

    return;

  }

  uVar4 = 0xffffffff;

  puVar3 = &DAT_009cef08;

  FUN_007a69d0(&DAT_009cef08,0xffffffff);

  FUN_007a6de0(puVar3,uVar4);

  return;

}
