// =============================================================================
// FUN_00729c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00729c10
// Address:   0x00729c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00729c10 @ 0x00729c10
// Stable ID: aa_00729c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, do×2, while×2.
//  - Notable callees: FUN_0074f320×4, FUN_0074f360×3, FUN_0074fca0×3, FUN_0043b7d0×2, FUN_00729c10, FUN_0074dfd0, FUN_0074f200, FUN_0074fba0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00729c10(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int in_EAX;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int unaff_EBP;

  int iVar6;

  int iVar7;

  float local_28;

  int *local_24;

  int local_20;

  int *local_1c;

  int *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ *local_c;

  uint32_t /* width from decompiler */ *local_8;

  int *local_4;

  

  iVar1 = DAT_00d1a54c;

  iVar6 = 0;

  if ((*(int *)(in_EAX + 0xc) == 0) ||

     (local_4 = (int *)(*(int *)(in_EAX + 0x10) - *(int *)(in_EAX + 0xc) >> 2),

     local_4 == (int *)0x0)) {

    return 0;

  }

  if ((DAT_00d1a54c != 0) && (cVar3 = FUN_0074dfd0(DAT_00d1a54c), cVar3 != '\0')) {

    local_c = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x3c);

    local_1c = (int *)local_c[0x36];

    local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(in_EAX + 0x18) + 0x20) + 8);

    FUN_0074fca0(2);

    FUN_0074f320(0);

    FUN_0075b6a0(&local_24,&local_28);

    iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + 0x2c);

    if ((((iVar1 != 0) &&

         (local_4 = (int *)(*(int *)(*(int *)(in_EAX + 0x18) + 0x30) - iVar1 >> 4),

         local_4 != (int *)0x0)) && (iVar1 != 0)) &&

       ((*(float *)(iVar1 + 8) != (float)local_24 || (*(float *)(iVar1 + 0xc) != local_28)))) {

      local_24 = *(int **)(iVar1 + 8);

      local_28 = *(float *)(iVar1 + 0xc);

      FUN_0075b720(local_24,local_28);

    }

    local_14 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

    local_28 = 0.0;

    local_20 = 0;

    FUN_0074fca0(2);

    FUN_0074f320(0);

    local_24 = *(int **)(in_EAX + 0xc);

    local_4 = *(int **)(in_EAX + 0x10);

    if (local_24 != local_4) {

      do {

        puVar5 = (uint32_t /* width from decompiler */ *)*local_24;

        local_8 = puVar5;

        if (((-1 < *(int *)(puVar5[2] + 0x24 + (int)local_1c * 4)) && (puVar5[3] != 0)) &&

           ((local_c[0x38] & *(uint *)(puVar5[3] + 0x1c)) == 0)) {

          piVar2 = (int *)puVar5[1];

          local_18 = (int *)*puVar5;

          iVar1 = piVar2[2];

          cVar3 = (**(code **)(*local_18 + 0x1c))();

          if (cVar3 != '\0') {

            (**(code **)(*local_18 + 0xc))(puVar5);

            FUN_0043b7d0(3);

            if (local_24 != piVar2) {

              if ((iVar1 != unaff_EBP) || (puVar5[2] != iVar6)) {

                iVar6 = puVar5[2];

                FUN_0074fba0(iVar6);

                FUN_0074fca0(2);

                unaff_EBP = iVar1;

              }

              FUN_0074f200(piVar2[3]);

              local_24 = piVar2;

              FUN_0043b7d0(2);

              iVar1 = *(int *)(iVar6 + 0x24 + local_20 * 4);

              if (((*(byte *)(*(int *)(iVar6 + 200) + iVar1 * 0x24 + 0x21) & 0x80) == 0) &&

                 (iVar7 = 0, 0 < iVar1)) {

                iVar4 = 0;

                do {

                  if ((*(byte *)(*(int *)(iVar6 + 200) + iVar4 + 0x20) & 3) != 0) {

                    FUN_0074f320(iVar7);

                  }

                  iVar7 = iVar7 + 1;

                  iVar4 = iVar4 + 0x24;

                  puVar5 = local_c;

                } while (iVar7 < iVar1);

              }

              FUN_0074f320(iVar1);

            }

            (**(code **)(*local_1c + 8))(puVar5);

          }

        }

        local_24 = local_24 + 1;

      } while (local_24 != local_4);

      if (local_28 != 0.0) {

        FUN_0074f360();

      }

    }

    FUN_0074f360();

    FUN_0074f360();

    return 0;

  }

  return 1;

}
