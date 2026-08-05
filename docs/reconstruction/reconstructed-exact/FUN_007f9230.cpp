// =============================================================================
// FUN_007f9230
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9230
// Address:   0x007f9230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9230 @ 0x007f9230
// Stable ID: aa_007f9230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, while×5, do×1, switch×1.
//  - Notable callees: FUN_007a6de0×4, _stricmp×4, FUN_007a69d0, FUN_007f9230.
//  - Return sites: 7.

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

uint __thiscall FUN_007f9230(int param_1,char *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ in_EAX;

  char *pcVar2;

  int iVar3;

  uint uVar4;

  

  if (param_2 != (char *)0x0) {

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    if ((pcVar2 != param_2 + 1) && ((uint)((int)pcVar2 - (int)(param_2 + 1)) < 0x22)) {

      FUN_007a69d0();

      switch(in_EAX) {

      case 0:

        uVar4 = 0;

        param_1 = param_1 + 0xd;

        while( true ) {

          pcVar2 = (char *)FUN_007a6de0(param_1,0xffffffff);

          iVar3 = _stricmp(param_2,pcVar2);

          if (iVar3 == 0) break;

          uVar4 = uVar4 + 1;

          param_1 = param_1 + 0x34;

          if (4 < (int)uVar4) {

            return 0;

          }

        }

        break;

      case 1:

        uVar4 = 0;

        param_1 = param_1 + 0x111;

        while( true ) {

          pcVar2 = (char *)FUN_007a6de0(param_1,0xffffffff);

          iVar3 = _stricmp(param_2,pcVar2);

          if (iVar3 == 0) break;

          uVar4 = uVar4 + 1;

          param_1 = param_1 + 0x34;

          if (5 < (int)uVar4) {

            return 0;

          }

        }

        break;

      case 2:

        uVar4 = 0;

        param_1 = param_1 + 0x249;

        while( true ) {

          pcVar2 = (char *)FUN_007a6de0(param_1,0xffffffff);

          iVar3 = _stricmp(param_2,pcVar2);

          if (iVar3 == 0) break;

          uVar4 = uVar4 + 1;

          param_1 = param_1 + 0x34;

          if (0x77 < (int)uVar4) {

            return 0;

          }

        }

        break;

      case 3:

        uVar4 = 0;

        param_1 = param_1 + 0x1aa9;

        while( true ) {

          pcVar2 = (char *)FUN_007a6de0(param_1,0xffffffff);

          iVar3 = _stricmp(param_2,pcVar2);

          if (iVar3 == 0) break;

          uVar4 = uVar4 + 1;

          param_1 = param_1 + 0x34;

          if (0x13 < (int)uVar4) {

            return 0;

          }

        }

        break;

      default:

        return 0;

      }

      return uVar4 & 0xff;

    }

  }

  return 0;

}
