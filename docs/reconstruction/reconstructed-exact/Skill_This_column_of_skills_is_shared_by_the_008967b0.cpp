// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007a6de0×6, FUN_0051f940×2, sprintf×2, FUN_007a69d0, FUN_008967b0.
//  - Strings: "class"; "This column of skills is shared by the"; "%s %s %s.".
//  - Return sites: 1.

// =============================================================================
// Skill_This_column_of_skills_is_shared_by_the_008967b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008967b0
// Address:   0x008967b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "This column of skills is shared by the"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_This_column_of_skills_is_shared_by_the_008967b0(void)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ local_160 [24];

  char local_100 [256];

  

  FUN_007a69d0();

  if (DAT_00d1b6d8 != 0) {

    local_160[0] = 1;

    local_160[1] = 3;

    local_160[2] = 0;

    local_160[3] = 2;

    local_160[4] = 1;

    local_160[5] = 3;

    local_160[6] = 0;

    local_160[7] = 2;

    local_160[8] = 1;

    local_160[9] = 3;

    local_160[10] = 0;

    local_160[0xb] = 2;

    local_160[0xc] = 1;

    local_160[0xd] = 3;

    local_160[0xe] = 0;

    local_160[0xf] = 2;

    local_160[0x10] = 1;

    local_160[0x11] = 3;

    local_160[0x12] = 0;

    local_160[0x13] = 2;

    local_160[0x14] = 3;

    local_160[0x15] = 1;

    local_160[0x16] = 2;

    local_160[0x17] = 0;

    if (*(int *)(unaff_EDI + 0x51c) == 1) {

      if (*(int *)(unaff_EDI + 0x744) != 0) {

        iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                        0x3c);

        bVar1 = *(byte *)(iVar3 + 0x531);

        bVar2 = *(byte *)(iVar3 + 0x532);

        uVar4 = FUN_007a6de0("class",0xffffffff);

        uVar5 = 0xffffffff;

        uVar4 = FUN_0051f940(local_160[((uint)bVar1 + (uint)bVar2 * 4) * 2],bVar2,0xffffffff,uVar4);

        uVar4 = FUN_007a6de0(uVar4,uVar5);

        uVar5 = FUN_007a6de0("This column of skills is shared by the",0xffffffff);

        sprintf(local_100,"%s %s %s.",uVar5,uVar4);

        (**(code **)(**(int **)(unaff_EDI + 0x744) + 0x308))(local_100);

      }

      if (*(int *)(unaff_EDI + 0x748) != 0) {

        iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                        0x3c);

        bVar1 = *(byte *)(iVar3 + 0x531);

        bVar2 = *(byte *)(iVar3 + 0x532);

        uVar4 = FUN_007a6de0("class",0xffffffff);

        uVar5 = 0xffffffff;

        uVar4 = FUN_0051f940(local_160[((uint)bVar1 + (uint)bVar2 * 4) * 2 + 1],bVar2,0xffffffff,

                             uVar4);

        uVar4 = FUN_007a6de0(uVar4,uVar5);

        uVar5 = FUN_007a6de0("This column of skills is shared by the",0xffffffff);

        sprintf(local_100,"%s %s %s.",uVar5,uVar4);

        (**(code **)(**(int **)(unaff_EDI + 0x748) + 0x308))(local_100);

      }

    }

  }

  return;

}
