// =============================================================================
// Drive_WHEELSET
// -----------------------------------------------------------------------------
// Stable ID: aa_005a9760
// Address:   0x005a9760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Drive_WHEELSET @ 0x005a9760
// Stable ID: aa_005a9760
// Embedded strings (evidence for future rename):
//   - "%s_WHEELSET_%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, for×1, while×1.
//  - Notable callees: FUN_005829d0×2, FUN_004073a0, FUN_004a0b90, Drive_WHEELSET, _snprintf.
//  - Strings: "%s_WHEELSET_%d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%s_WHEELSET_%d"
 * Domain alias of FUN_005a9760 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Drive_WHEELSET(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uStack_114;

  char local_110 [2];

  uint32_t /* width from decompiler */ local_10e [66];

  

  if (*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb0 + param_1) != 0) {

    cVar3 = '\0';

    if ('\0' < *(char *)(param_1 + -0xb0)) {

      do {

        local_110[0] = '\0';

        local_110[1] = '\0';

        puVar4 = local_10e;

        for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar4 = 0;

          puVar4 = puVar4 + 1;

        }

        *(uint16_t *)puVar4 = 0;

        _snprintf(local_110,0x104,"%s_WHEELSET_%d",param_2 + 0xd5,(int)cVar3);

        uVar1 = FUN_004a0b90(param_2,local_110,1,0xffffffff,(int)cVar3);

        uStack_114 = uVar1;

        if (param_4 != 0) {

          iVar2 = *(int *)(param_4 + 4);

          if ((iVar2 == 0) ||

             ((uint)(*(int *)(param_4 + 0xc) - iVar2 >> 2) <=

              (uint)(*(int *)(param_4 + 8) - iVar2 >> 2))) {

            FUN_004073a0(*(uint32_t /* width from decompiler */ *)(param_4 + 8),1,&uStack_114);

          }

          else {

            puVar4 = *(uint32_t /* width from decompiler */ **)(param_4 + 8);

            *puVar4 = uVar1;

            *(uint32_t /* width from decompiler */ **)(param_4 + 8) = puVar4 + 1;

          }

        }

        FUN_005829d0(uVar1,param_3,param_4);

        cVar3 = cVar3 + '\x01';

      } while (cVar3 < *(char *)(param_1 + -0xb0));

    }

    return;

  }

  FUN_005829d0(param_2,param_3,param_4);

  return;

}
