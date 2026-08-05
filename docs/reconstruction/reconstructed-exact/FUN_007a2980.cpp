// =============================================================================
// FUN_007a2980
// -----------------------------------------------------------------------------
// Stable ID: aa_007a2980
// Address:   0x007a2980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a2980 @ 0x007a2980
// Stable ID: aa_007a2980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×6, switch×3, do×2, return×2, while×2.
//  - Notable callees: FUN_0079f640×3, FUN_0079dd50, FUN_0079e680, FUN_0079e6b0, FUN_0079e710, FUN_0079e7a0, FUN_007a0840, FUN_007a0870.
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

void __thiscall FUN_007a2980(int param_1,char param_2)



{

  char cVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  char cVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  int *piVar10;

  int local_fc;

  int local_f8;

  int local_f4;

  int local_ec;

  int local_e8;

  int local_e4;

  int local_e0;

  int local_dc;

  uint32_t /* width from decompiler */ local_d8;

  int local_d4;

  int local_d0;

  int local_cc;

  int local_c8;

  int local_c4;

  int local_c0;

  int local_b8;

  int local_b4;

  int local_b0;

  int local_ac;

  int local_a8;

  uint32_t /* width from decompiler */ local_a4;

  int local_a0;

  int local_9c;

  int local_98;

  int local_90;

  int local_8c;

  uint32_t /* width from decompiler */ local_88;

  int local_84;

  int local_80;

  int local_7c;

  int local_74;

  int local_70;

  int local_6c;

  int local_68;

  int local_64;

  uint32_t /* width from decompiler */ local_60;

  int local_5c;

  int local_58;

  int local_54;

  uint32_t /* width from decompiler */ local_50 [16];

  int local_10;

  int local_c;

  int local_8;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x2e4) + 8);

  piVar10 = (int *)**(int **)(param_1 + 0x2dc);

  cVar6 = '\x01';

  if (piVar10 != *(int **)(param_1 + 0x2dc)) {

    do {

      if (cVar6 == '\0') {

        return;

      }

      if ((param_2 == (char)piVar10[0x29]) &&

         (fVar3 = *(float *)(iVar2 + 0x98) - (float)piVar10[0x14],

         fVar5 = *(float *)(iVar2 + 0x94) - (float)piVar10[0x13],

         fVar4 = *(float *)(iVar2 + 0x90) - (float)piVar10[0x12],

         SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4) < DAT_00aaa8a8)) {

        cVar1 = (char)piVar10[2];

        if (cVar1 == '\0') {

          local_d0 = piVar10[0x1c];

          local_dc = piVar10[5];

          local_cc = piVar10[0x1d];

          local_fc = piVar10[0x12];

          local_f8 = piVar10[0x13];

          local_f4 = piVar10[0x14];

          local_ec = piVar10[0x25];

          local_e8 = piVar10[0x26];

          local_e4 = piVar10[0x27];

          local_e0 = piVar10[0x28];

          local_d4 = piVar10[0x20];

          local_d8 = 0;

          switch(*(uint8_t *)((int)piVar10 + 9)) {

          case 1:

            cVar6 = FUN_0079e710(&local_fc);

            break;

          case 2:

            cVar6 = FUN_0079e7a0(&local_fc);

            break;

          default:

            cVar6 = FUN_0079dd50(&local_fc,*(uint32_t /* width from decompiler */ *)(param_1 + 0x16c));

            break;

          case 5:

            cVar6 = FUN_0079e6b0(&local_fc);

            break;

          case 6:

            cVar6 = FUN_0079e680(&local_fc);

          }

        }

        else if (cVar1 == '\x01') {

          local_c8 = piVar10[0x12];

          local_a8 = piVar10[5];

          local_c4 = piVar10[0x13];

          local_c0 = piVar10[0x14];

          local_b8 = piVar10[0x25];

          local_b4 = piVar10[0x26];

          local_b0 = piVar10[0x27];

          local_ac = piVar10[0x28];

          local_90 = piVar10[0x1c];

          local_8c = piVar10[0x1d];

          local_a0 = piVar10[0x15];

          local_9c = piVar10[0x16];

          local_98 = piVar10[0x17];

          local_a4 = 0;

          local_88 = 0;

          switch(*(uint8_t *)((int)piVar10 + 9)) {

          case 1:

            cVar6 = FUN_007a24c0(&local_c8);

            break;

          case 2:

            cVar6 = FUN_007a2550(&local_c8);

            break;

          default:

            cVar6 = FUN_007a2490(&local_c8);

            break;

          case 5:

            cVar6 = FUN_007a2450(&local_c8);

            break;

          case 6:

            cVar6 = FUN_007a2410(&local_c8);

          }

        }

        else if (cVar1 == '\x02') {

          puVar7 = (uint32_t /* width from decompiler */ *)piVar10[0x1b];

          puVar8 = local_50 + 1;

          iVar9 = 4;

          do {

            puVar8[-1] = *puVar7;

            *puVar8 = puVar7[1];

            puVar8[1] = puVar7[2];

            puVar7 = puVar7 + 3;

            puVar8 = puVar8 + 4;

            iVar9 = iVar9 + -1;

          } while (iVar9 != 0);

          local_58 = piVar10[0x1c];

          local_54 = piVar10[0x1d];

          local_74 = piVar10[0x25];

          local_64 = piVar10[5];

          local_70 = piVar10[0x26];

          local_6c = piVar10[0x27];

          local_68 = piVar10[0x28];

          local_84 = piVar10[0x12];

          local_80 = piVar10[0x13];

          local_7c = piVar10[0x14];

          local_5c = piVar10[0x20];

          local_10 = piVar10[0x15];

          local_c = piVar10[0x16];

          local_8 = piVar10[0x17];

          local_60 = 0;

          switch(*(uint8_t *)((int)piVar10 + 9)) {

          case 1:

            cVar6 = FUN_0079f640(&local_84,*(uint32_t /* width from decompiler */ *)(param_1 + 0x180));

            break;

          case 2:

            cVar6 = FUN_0079f640(&local_84,*(uint32_t /* width from decompiler */ *)(param_1 + 0x194));

            break;

          default:

            cVar6 = FUN_0079f640(&local_84,*(uint32_t /* width from decompiler */ *)(param_1 + 0x16c));

            break;

          case 5:

            cVar6 = FUN_007a0870();

            break;

          case 6:

            cVar6 = FUN_007a0840();

          }

        }

      }

      piVar10 = (int *)*piVar10;

    } while (piVar10 != (int *)*(int *)(param_1 + 0x2dc));

  }

  return;

}
