// =============================================================================
// FUN_0074d0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074d0c0
// Address:   0x0074d0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074d0c0 @ 0x0074d0c0
// Stable ID: aa_0074d0c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_0074bf40×6, FUN_00972fa0×2, FUN_0074c310, FUN_0074d0c0, FUN_00972cc0.
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

uint8_t __thiscall FUN_0074d0c0(int param_1,int param_2)



{

  char cVar1;

  int in_EAX;

  int unaff_EBX;

  float local_10c;

  float local_108;

  float local_104;

  float local_f4;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  uint8_t local_d0 [204];

  

  cVar1 = FUN_0074c310(param_1,unaff_EBX,in_EAX);

  if (cVar1 == '\0') {

    local_f4 = (*(float *)(unaff_EBX + 0x90) - *(float *)(param_1 + 0x90)) +

               *(float *)(in_EAX + 0x14);

    local_ec = *(float *)(in_EAX + 0x1c) +

               (*(float *)(unaff_EBX + 0x98) - *(float *)(param_1 + 0x98));

    local_f0 = *(float *)(in_EAX + 0x18) +

               (*(float *)(unaff_EBX + 0x94) - *(float *)(param_1 + 0x94));

    local_e8 = (*(float *)(unaff_EBX + 0x90) - *(float *)(param_1 + 0x90)) +

               *(float *)(in_EAX + 0x20);

    local_e4 = *(float *)(in_EAX + 0x24) +

               (*(float *)(unaff_EBX + 0x94) - *(float *)(param_1 + 0x94));

    local_e0 = *(float *)(in_EAX + 0x28) +

               (*(float *)(unaff_EBX + 0x98) - *(float *)(param_1 + 0x98));

    local_dc = local_e8 - local_f4;

    local_d8 = local_e4 - local_f0;

    local_d4 = local_e0 - local_ec;

    FUN_00972cc0();

    FUN_00972fa0(&local_f4);

    if ((((*(float *)(param_2 + 0x20) < local_10c) || (local_10c < *(float *)(param_2 + 0x14))) ||

        (*(float *)(param_2 + 0x24) < local_108)) ||

       (((local_108 < *(float *)(param_2 + 0x18) || (*(float *)(param_2 + 0x28) < local_104)) ||

        (local_104 < *(float *)(param_2 + 0x1c))))) {

      FUN_00972fa0(&local_e8);

      if (((*(float *)(param_2 + 0x20) < local_10c) || (local_10c < *(float *)(param_2 + 0x14))) ||

         ((*(float *)(param_2 + 0x24) < local_108 ||

          (((local_108 < *(float *)(param_2 + 0x18) || (*(float *)(param_2 + 0x28) < local_104)) ||

           (local_104 < *(float *)(param_2 + 0x1c))))))) {

        cVar1 = FUN_0074bf40(local_d0);

        if (cVar1 == '\0') {

          cVar1 = FUN_0074bf40(local_d0);

          if (cVar1 == '\0') {

            cVar1 = FUN_0074bf40(local_d0);

            if (cVar1 == '\0') {

              cVar1 = FUN_0074bf40(local_d0);

              if (cVar1 == '\0') {

                cVar1 = FUN_0074bf40(local_d0);

                if (cVar1 == '\0') {

                  cVar1 = FUN_0074bf40(local_d0);

                  if (cVar1 == '\0') {

                    return 0;

                  }

                }

              }

            }

          }

        }

      }

    }

  }

  return 1;

}
