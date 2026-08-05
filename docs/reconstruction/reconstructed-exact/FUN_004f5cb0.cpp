// =============================================================================
// FUN_004f5cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5cb0
// Address:   0x004f5cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f5cb0 @ 0x004f5cb0
// Stable ID: aa_004f5cb0
// Embedded strings (evidence for future rename):
//   - "%S%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_004f5ae0, FUN_004f5cb0, _snprintf.
//  - Strings: "%S%s".
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

void __fastcall FUN_004f5cb0(int param_1)



{

  int iVar1;

  byte bVar2;

  uint uVar3;

  int *piVar4;

  int *piVar5;

  int local_108;

  char local_104 [260];

  

  piVar4 = (int *)(param_1 + 0x28c);

  local_108 = 8;

  do {

    if (0 < *piVar4) {

      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

      uVar3 = 0;

      if (*(char *)(iVar1 + 0x716) != '\0') {

        do {

          piVar5 = (int *)(uVar3 * 0x110 + *(int *)(iVar1 + 0x720));

          if (*piVar5 == *piVar4) {

            _snprintf(local_104,0x104,"%S%s",(int)piVar5 + 10,&DAT_00a28904);

            FUN_004f5ae0((char)piVar5[2],local_104);

          }

          iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

          bVar2 = (char)uVar3 + 1;

          uVar3 = (uint)bVar2;

        } while (bVar2 < *(byte *)(iVar1 + 0x716));

      }

    }

    piVar4 = piVar4 + 1;

    local_108 = local_108 + -1;

  } while (local_108 != 0);

  return;

}
