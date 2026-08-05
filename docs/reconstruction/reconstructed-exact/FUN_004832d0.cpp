// =============================================================================
// FUN_004832d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004832d0
// Address:   0x004832d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004832d0 @ 0x004832d0
// Stable ID: aa_004832d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×6, return×6, do×1, switch×1, while×1.
//  - Notable callees: FUN_004824e0×5, FUN_00481ee0, FUN_00481f00, FUN_004823b0, FUN_004832d0.
//  - Return sites: 6.

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

int __fastcall

FUN_004832d0(int param_1,int param_2,int param_3,int *param_4,int param_5,int param_6)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  int local_30;

  int local_2c;

  int local_20;

  int local_1c;

  int *local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((((((param_3 != 0) && (param_4 != (int *)0x0)) && (param_5 != 0)) &&

       ((0 < param_2 && (param_2 < 10)))) && ((-1 < param_1 && ((param_1 < 5 && (-1 < in_EAX))))))

     && (in_EAX < 0xfb)) {

    if (in_EAX == 0) {

      in_EAX = 0x1e;

    }

    local_c = 0;

    local_8 = 0;

    local_4 = 0;

    iVar3 = FUN_00481f00(param_2,param_1,in_EAX);

    if (iVar3 == 0) {

      local_30 = param_5;

      local_1c = *param_4;

      local_20 = param_3;

      local_2c = param_6;

      if ((local_10 != (int *)0x0) && ((int *)*local_10 == &local_30)) {

        iVar3 = local_10[1];

        piVar1 = local_10 + 1;

        do {

          switch(iVar3) {

          case 2:

            local_10[3] = param_6;

            *piVar1 = 4;

            iVar3 = *piVar1;

            break;

          case 4:

            if ((local_10[3] == *(int *)(*local_10 + 4)) && (cVar2 = FUN_004823b0(), cVar2 != '\0'))

            {

              if ((local_10[3] == 0) &&

                 ((cVar2 = FUN_00481ee0(), cVar2 != '\0' && (local_10[0x13] <= local_10[0x14])))) {

                *piVar1 = 1;

                *param_4 = *param_4 - local_1c;

                FUN_004824e0();

                return 0;

              }

              FUN_004824e0();

              return -8;

            }

          case 1:

          case 3:

            FUN_004824e0();

            return -1;

          default:

            FUN_004824e0();

            return 0;

          }

        } while( true );

      }

      FUN_004824e0();

      iVar3 = -2;

    }

    return iVar3;

  }

  return -2;

}
