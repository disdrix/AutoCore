// =============================================================================
// Named_nfx_00556b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00556b10
// Address:   0x00556b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_nfx_00556b10 @ 0x00556b10
// Stable ID: aa_00556b10
// Embedded strings (evidence for future rename):
//   - "_nfx.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, while×2, return×2.
//  - Notable callees: FUN_0043d670×2, FUN_004b88e0×2, FUN_007b6730×2, FUN_007b6a20×2, FUN_00989e00×2, strstr×2, FUN_0043d650, FUN_00553ce0.
//  - Strings: "_nfx.xml".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "_nfx.xml"
 * Domain alias of FUN_00556b10 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_nfx_00556b10(uint8_t param_1 [4],uint32_t /* width from decompiler */ param_2,int param_3,char param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t local_108 [4];

  char local_104 [8];

  uint8_t local_fc [252];

  

  local_108 = param_1;

  FUN_0043d650(0);

  if (param_3 != 0) {

    if (param_4 == '\0') {

      cVar2 = FUN_00555660(*(uint32_t /* width from decompiler */ *)(param_3 + 0x558),local_104);

      if (cVar2 != '\0') {

        pcVar3 = strstr(local_104,"_nfx.xml");

        if (pcVar3 == (char *)0x0) {

          puVar1 = (uint32_t /* width from decompiler */ *)(local_108 + 3);

          do {

            puVar5 = puVar1;

            puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

          } while (*(char *)((int)puVar5 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar5 + 1) = DAT_009ca184;

          *(uint32_t /* width from decompiler */ *)((int)puVar5 + 5) = DAT_009ca188;

          *(uint8_t *)((int)puVar5 + 9) = DAT_009ca18c;

          param_1 = local_108;

        }

        pcVar3 = local_104;

        uVar6 = 0xffffffff;

        FUN_007b6a20(pcVar3,0xffffffff);

        cVar2 = FUN_007b6730(pcVar3,uVar6);

        if (cVar2 != '\0') {

          FUN_00989e00(local_108,local_104);

          FUN_0043d670(local_108);

        }

      }

      cVar2 = FUN_00553ce0(*(uint32_t /* width from decompiler */ *)((int)param_1 + 0x150),local_104);

      if (cVar2 != '\0') {

        pcVar3 = strstr(local_104,"_nfx.xml");

        if (pcVar3 == (char *)0x0) {

          puVar1 = (uint32_t /* width from decompiler */ *)(local_108 + 3);

          do {

            puVar5 = puVar1;

            puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

          } while (*(char *)((int)puVar5 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar5 + 1) = DAT_009ca184;

          *(uint32_t /* width from decompiler */ *)((int)puVar5 + 5) = DAT_009ca188;

          *(uint8_t *)((int)puVar5 + 9) = DAT_009ca18c;

        }

        pcVar3 = local_104;

        uVar6 = 0xffffffff;

        FUN_007b6a20(pcVar3,0xffffffff);

        cVar2 = FUN_007b6730(pcVar3,uVar6);

        if (cVar2 != '\0') {

          FUN_00989e00(local_108,local_104);

          FUN_0043d670(local_108);

        }

      }

    }

    else {

      iVar4 = FUN_00555600(*(uint32_t /* width from decompiler */ *)(param_3 + 0x558));

      if (iVar4 != 0) {

        FUN_004b88e0(param_2,1,0,0);

      }

      if (((-1 < *(int *)((int)param_1 + 0x150)) && (*(int *)((int)param_1 + 0x150) < 4)) &&

         (iVar4 = FUN_00553d20(0), iVar4 != 0)) {

        FUN_004b88e0(param_2,1,0,0);

        return;

      }

    }

  }

  return;

}
