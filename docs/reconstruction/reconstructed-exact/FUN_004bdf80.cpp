// =============================================================================
// FUN_004bdf80
// -----------------------------------------------------------------------------
// Stable ID: aa_004bdf80
// Address:   0x004bdf80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bdf80 @ 0x004bdf80
// Stable ID: aa_004bdf80
// Embedded strings (evidence for future rename):
//   - "MatDiffuse"
//   - "Translucent"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×18, while×6, return×4.
//  - Notable callees: FUN_007522a0×4, FUN_009700f0×4, FUN_0096f5d0×2, FUN_0096fdf0×2, ABS, FUN_004bdf80.
//  - Strings: "MatDiffuse"; "Translucent".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_004bdf80(int param_1,float param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  *(float *)(param_1 + 0x5c8) = param_2;

  if (*(char *)(param_1 + 0x571) == '\0') {

    param_2 = param_2 - _DAT_00aefa4c;

    local_8 = 0.0;

    local_4 = g_flOne;

    if ((param_2 <= 0.0) || (DAT_00aef954 <= param_2)) {

      cVar1 = '\0';

    }

    else {

      local_8 = g_flOne;

      local_4 = g_flOne - param_2 / DAT_00aef954;

      cVar1 = '\x01';

    }

    local_10 = local_8;

    local_c = local_8;

    if (*(char *)(param_1 + 0x5c5) == cVar1) {

      if (*(char *)(param_1 + 0x5c5) == '\0') {

        return;

      }

      if (ABS(*(float *)(param_1 + 0x5cc) - local_4) <= DAT_00a0f718) {

        return;

      }

      iVar3 = 0;

      while( true ) {

        if (*(int *)(param_1 + 0xf0) == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;

        }

        if (iVar2 <= iVar3) break;

        FUN_009700f0("MatDiffuse",&local_10);

        FUN_007522a0("Translucent");

        iVar3 = iVar3 + 1;

      }

      iVar3 = 0;

      while( true ) {

        if (*(int *)(param_1 + 0x23c) == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;

        }

        if (iVar2 <= iVar3) break;

        FUN_009700f0("MatDiffuse",&local_10);

        FUN_007522a0("Translucent");

        iVar3 = iVar3 + 1;

      }

    }

    else {

      *(char *)(param_1 + 0x5c5) = cVar1;

      if (cVar1 == '\0') {

        iVar3 = 0;

        while( true ) {

          if (*(int *)(param_1 + 0xf0) == 0) {

            iVar2 = 0;

          }

          else {

            iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;

          }

          if (iVar2 <= iVar3) break;

          FUN_0096f5d0();

          iVar3 = iVar3 + 1;

        }

        iVar3 = 0;

        while( true ) {

          if (*(int *)(param_1 + 0x23c) == 0) {

            iVar2 = 0;

          }

          else {

            iVar2 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;

          }

          if (iVar2 <= iVar3) break;

          FUN_0096f5d0();

          iVar3 = iVar3 + 1;

        }

        return;

      }

      iVar3 = 0;

      while( true ) {

        if (*(int *)(param_1 + 0xf0) == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;

        }

        if (iVar2 <= iVar3) break;

        FUN_0096fdf0();

        FUN_009700f0("MatDiffuse",&local_10);

        FUN_007522a0("Translucent");

        iVar3 = iVar3 + 1;

      }

      iVar3 = 0;

      while( true ) {

        if (*(int *)(param_1 + 0x23c) == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;

        }

        if (iVar2 <= iVar3) break;

        FUN_0096fdf0();

        FUN_009700f0("MatDiffuse",&local_10);

        FUN_007522a0("Translucent");

        iVar3 = iVar3 + 1;

      }

    }

    *(float *)(param_1 + 0x5cc) = local_4;

  }

  return;

}
