// =============================================================================
// FUN_005a6920
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6920
// Address:   0x005a6920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6920 @ 0x005a6920
// Stable ID: aa_005a6920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, while×3, goto×3, do×2, return×1.
//  - Notable callees: FUN_00493830, FUN_00493e00, FUN_005a6920.
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

void __fastcall FUN_005a6920(int param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_00493e00(0,0);

  iVar4 = 0;

  do {

    while( true ) {

      if (*(int *)(param_1 + 0x24) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 2;

      }

      if (iVar3 <= iVar4) {

        return;

      }

      uVar1 = *(uint *)(*(int *)(param_1 + 0x24) + iVar4 * 4);

      if ((int)uVar1 < 0) break;

      iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x138) + 0xe568) +

                               (*(uint *)(*(int *)(param_1 + 0x138) + 0xe560) & uVar1) * 4) + 4);

      if (iVar3 == 0) {

LAB_005a69e2:

        local_4 = 0;

      }

      else {

        do {

          if (uVar1 == *(uint *)(iVar3 + 0x10)) {

            if (iVar3 == 0) goto LAB_005a69e2;

            local_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

            goto LAB_005a69e9;

          }

          iVar3 = *(int *)(iVar3 + 0xc);

        } while (iVar3 != 0);

        local_4 = 0;

      }

LAB_005a69e9:

      iVar3 = *(int *)(param_1 + 0x14);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0x1c) - iVar3 >> 2) <=

          (uint)(*(int *)(param_1 + 0x18) - iVar3 >> 2))) {

LAB_005a6a29:

        FUN_00493830(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),1,&local_4);

        iVar4 = iVar4 + 1;

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

        *puVar2 = local_4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2 + 1;

        iVar4 = iVar4 + 1;

      }

    }

    iVar3 = *(int *)(param_1 + 0x14);

    local_4 = 0;

    if ((iVar3 == 0) ||

       ((uint)(*(int *)(param_1 + 0x1c) - iVar3 >> 2) <=

        (uint)(*(int *)(param_1 + 0x18) - iVar3 >> 2))) goto LAB_005a6a29;

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

    *puVar2 = 0;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2 + 1;

    iVar4 = iVar4 + 1;

  } while( true );

}
