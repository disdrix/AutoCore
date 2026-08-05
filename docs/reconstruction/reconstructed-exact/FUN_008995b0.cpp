// =============================================================================
// FUN_008995b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008995b0
// Address:   0x008995b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008995b0 @ 0x008995b0
// Stable ID: aa_008995b0
// Embedded strings (evidence for future rename):
//   - "Are you sure you want to change map instances?"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_008995b0.
//  - Strings: "Are you sure you want to change map instances?".
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

void FUN_008995b0(void)



{

  int iVar1;

  char cVar2;

  int *in_EAX;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  if ((in_EAX[0x14a] != 0) && (cVar2 = (**(code **)(*in_EAX + 0x3d8))(), cVar2 != '\0')) {

    iVar3 = (**(code **)(*(int *)in_EAX[0x14a] + 0x464))();

    iVar3 = iVar3 - in_EAX[0x150];

    if ((-1 < iVar3) && (iVar3 < DAT_00d1b4a8)) {

      iVar1 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8);

      iVar3 = iVar3 * 0x18;

      if ((*(int *)(iVar3 + DAT_00d1b4ac) != *(int *)(iVar1 + 0x948)) ||

         (*(int *)(iVar3 + 4 + DAT_00d1b4ac) != *(int *)(iVar1 + 0x94c))) {

        *(uint8_t *)(DAT_00d1b6d8 + 0x4ff) = *(uint8_t *)(iVar3 + 0x10 + DAT_00d1b4ac);

        iVar1 = DAT_00d1b8c0;

        if (DAT_00d1b8c0 != 0) {

          *(uint32_t /* width from decompiler */ *)(DAT_00d1b8c0 + 0x544) =

               *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xfc);

          *(uint32_t /* width from decompiler */ *)(iVar1 + 0x548) = *(uint32_t /* width from decompiler */ *)(iVar3 + DAT_00d1b4ac);

          *(uint32_t /* width from decompiler */ *)(iVar1 + 0x54c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + DAT_00d1b4ac);

        }

        uVar8 = 0;

        uVar7 = 1;

        uVar6 = 0x4e23;

        uVar5 = 0xffffffff;

        pcVar4 = "Are you sure you want to change map instances?";

        FUN_007a69d0("Are you sure you want to change map instances?",0xffffffff,0x4e23,1,0);

        uVar5 = FUN_007a6de0(pcVar4,uVar5);

        FUN_007fdfb0(&DAT_00d1a840,uVar5,uVar6,uVar7,uVar8);

      }

    }

  }

  return;

}
