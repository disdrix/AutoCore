// =============================================================================
// FUN_00867a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00867a20
// Address:   0x00867a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867a20 @ 0x00867a20
// Stable ID: aa_00867a20
// Embedded strings (evidence for future rename):
//   - "Resistances:"
//   - "Immunities:"
//   - "Physical"
//   - "Moderately Resistant to"
//   - "Partially Resistant to"
//   - "Lightly Resistant to"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×8, goto×4, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_007a6de0×10, FUN_007a69d0, FUN_00867a20, sprintf.
//  - Strings: "Resistances:"; "Immunities:"; "Physical"; "Moderately Resistant to".
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

void FUN_00867a20(int *param_1,short param_2,char param_3)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char local_64 [2];

  uint32_t /* width from decompiler */ local_62 [24];

  

  FUN_007a69d0();

  local_64[0] = '\0';

  local_64[1] = '\0';

  puVar7 = local_62;

  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  *(uint16_t *)puVar7 = 0;

  if (5 < in_EAX) {

    if (param_2 < 1000) {

      if (0 < param_2) {

        pcVar2 = (char *)FUN_007a6de0("Resistances:",0xffffffff);

        pcVar6 = local_64;

        do {

          cVar1 = *pcVar2;

          *pcVar6 = cVar1;

          pcVar2 = pcVar2 + 1;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

      }

    }

    else {

      pcVar2 = (char *)FUN_007a6de0("Immunities:",0xffffffff);

      pcVar6 = local_64;

      do {

        cVar1 = *pcVar2;

        *pcVar6 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

    }

    goto LAB_00867bad;

  }

  if ((param_2 < 1000) || (param_3 != '\0')) {

    if (param_2 < 0x12d) {

      if (100 < param_2) {

        uVar3 = FUN_007a6de0("Physical" + in_EAX * 0x10,0xffffffff);

        uVar4 = FUN_007a6de0("Moderately Resistant to",0xffffffff);

        goto LAB_00867ba4;

      }

      if (0x32 < param_2) {

        uVar3 = FUN_007a6de0("Physical" + in_EAX * 0x10,0xffffffff);

        pcVar6 = "Partially Resistant to";

        goto LAB_00867b5e;

      }

      if (param_2 < 1) goto LAB_00867bad;

      uVar3 = FUN_007a6de0("Physical" + in_EAX * 0x10,0xffffffff);

      pcVar6 = "Lightly Resistant to";

    }

    else {

      uVar3 = FUN_007a6de0("Physical" + in_EAX * 0x10,0xffffffff);

      pcVar6 = "Highly Resistant to";

    }

    uVar4 = FUN_007a6de0(pcVar6,0xffffffff);

  }

  else {

    uVar3 = FUN_007a6de0("Physical" + in_EAX * 0x10,0xffffffff);

    pcVar6 = "Immune to";

LAB_00867b5e:

    uVar4 = FUN_007a6de0(pcVar6,0xffffffff);

  }

LAB_00867ba4:

  sprintf(local_64,"%s %s",uVar4,uVar3);

LAB_00867bad:

  (**(code **)(*param_1 + 0x308))(local_64);

  return;

}
