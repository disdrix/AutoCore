// =============================================================================
// FUN_0059b620
// -----------------------------------------------------------------------------
// Stable ID: aa_0059b620
// Address:   0x0059b620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059b620 @ 0x0059b620
// Stable ID: aa_0059b620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~266 non-empty decompiler lines.
//  - Control keywords: for×10, if×8, return×3.
//  - Notable callees: block×91, FUN_007ddac0×6, FUN_0041c370×4, CONCAT31, FUN_0041ab20, FUN_0059b190, FUN_0059b620, FUN_0059c4c0.
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

/* WARNING: Removing unreachable block (ram,0x0059bec6) */

/* WARNING: Removing unreachable block (ram,0x0059bdd8) */

/* WARNING: Removing unreachable block (ram,0x0059bd9d) */

/* WARNING: Removing unreachable block (ram,0x0059bc5b) */

/* WARNING: Removing unreachable block (ram,0x0059bb18) */

/* WARNING: Removing unreachable block (ram,0x0059badf) */

/* WARNING: Removing unreachable block (ram,0x0059b9a9) */

/* WARNING: Removing unreachable block (ram,0x0059b96a) */

/* WARNING: Removing unreachable block (ram,0x0059b85c) */

/* WARNING: Removing unreachable block (ram,0x0059b823) */

/* WARNING: Removing unreachable block (ram,0x0059b73d) */

/* WARNING: Removing unreachable block (ram,0x0059b7f7) */

/* WARNING: Removing unreachable block (ram,0x0059b846) */

/* WARNING: Removing unreachable block (ram,0x0059b854) */

/* WARNING: Removing unreachable block (ram,0x0059b858) */

/* WARNING: Removing unreachable block (ram,0x0059b86f) */

/* WARNING: Removing unreachable block (ram,0x0059b8cc) */

/* WARNING: Removing unreachable block (ram,0x0059b8e8) */

/* WARNING: Removing unreachable block (ram,0x0059b8ea) */

/* WARNING: Removing unreachable block (ram,0x0059b918) */

/* WARNING: Removing unreachable block (ram,0x0059b87a) */

/* WARNING: Removing unreachable block (ram,0x0059b88d) */

/* WARNING: Removing unreachable block (ram,0x0059b88f) */

/* WARNING: Removing unreachable block (ram,0x0059b8ae) */

/* WARNING: Removing unreachable block (ram,0x0059b8b7) */

/* WARNING: Removing unreachable block (ram,0x0059b94d) */

/* WARNING: Removing unreachable block (ram,0x0059b986) */

/* WARNING: Removing unreachable block (ram,0x0059b9bf) */

/* WARNING: Removing unreachable block (ram,0x0059b9d2) */

/* WARNING: Removing unreachable block (ram,0x0059ba2f) */

/* WARNING: Removing unreachable block (ram,0x0059ba4b) */

/* WARNING: Removing unreachable block (ram,0x0059ba4d) */

/* WARNING: Removing unreachable block (ram,0x0059ba7b) */

/* WARNING: Removing unreachable block (ram,0x0059b9dd) */

/* WARNING: Removing unreachable block (ram,0x0059b9f0) */

/* WARNING: Removing unreachable block (ram,0x0059b9f2) */

/* WARNING: Removing unreachable block (ram,0x0059ba11) */

/* WARNING: Removing unreachable block (ram,0x0059ba1a) */

/* WARNING: Removing unreachable block (ram,0x0059b9b7) */

/* WARNING: Removing unreachable block (ram,0x0059b9bb) */

/* WARNING: Removing unreachable block (ram,0x0059bb02) */

/* WARNING: Removing unreachable block (ram,0x0059bb10) */

/* WARNING: Removing unreachable block (ram,0x0059bb14) */

/* WARNING: Removing unreachable block (ram,0x0059bb2b) */

/* WARNING: Removing unreachable block (ram,0x0059bb88) */

/* WARNING: Removing unreachable block (ram,0x0059bba4) */

/* WARNING: Removing unreachable block (ram,0x0059bba6) */

/* WARNING: Removing unreachable block (ram,0x0059bbd4) */

/* WARNING: Removing unreachable block (ram,0x0059bb36) */

/* WARNING: Removing unreachable block (ram,0x0059bb49) */

/* WARNING: Removing unreachable block (ram,0x0059bb4b) */

/* WARNING: Removing unreachable block (ram,0x0059bb6a) */

/* WARNING: Removing unreachable block (ram,0x0059bb73) */

/* WARNING: Removing unreachable block (ram,0x0059bc38) */

/* WARNING: Removing unreachable block (ram,0x0059bc78) */

/* WARNING: Removing unreachable block (ram,0x0059bc8b) */

/* WARNING: Removing unreachable block (ram,0x0059bce8) */

/* WARNING: Removing unreachable block (ram,0x0059bcff) */

/* WARNING: Removing unreachable block (ram,0x0059bd01) */

/* WARNING: Removing unreachable block (ram,0x0059bd39) */

/* WARNING: Removing unreachable block (ram,0x0059bc96) */

/* WARNING: Removing unreachable block (ram,0x0059bca9) */

/* WARNING: Removing unreachable block (ram,0x0059bcab) */

/* WARNING: Removing unreachable block (ram,0x0059bcca) */

/* WARNING: Removing unreachable block (ram,0x0059bcd3) */

/* WARNING: Removing unreachable block (ram,0x0059bc70) */

/* WARNING: Removing unreachable block (ram,0x0059bc74) */

/* WARNING: Removing unreachable block (ram,0x0059bdc0) */

/* WARNING: Removing unreachable block (ram,0x0059bdd0) */

/* WARNING: Removing unreachable block (ram,0x0059bdd4) */

/* WARNING: Removing unreachable block (ram,0x0059bdeb) */

/* WARNING: Removing unreachable block (ram,0x0059bdf1) */

/* WARNING: Removing unreachable block (ram,0x0059be09) */

/* WARNING: Removing unreachable block (ram,0x0059be0b) */

/* WARNING: Removing unreachable block (ram,0x0059be2a) */

/* WARNING: Removing unreachable block (ram,0x0059be33) */

/* WARNING: Removing unreachable block (ram,0x0059bea3) */

/* WARNING: Removing unreachable block (ram,0x0059bedc) */

/* WARNING: Removing unreachable block (ram,0x0059beef) */

/* WARNING: Removing unreachable block (ram,0x0059bf4c) */

/* WARNING: Removing unreachable block (ram,0x0059bf68) */

/* WARNING: Removing unreachable block (ram,0x0059bf6a) */

/* WARNING: Removing unreachable block (ram,0x0059bf98) */

/* WARNING: Removing unreachable block (ram,0x0059befa) */

/* WARNING: Removing unreachable block (ram,0x0059bf0d) */

/* WARNING: Removing unreachable block (ram,0x0059bf0f) */

/* WARNING: Removing unreachable block (ram,0x0059bf2e) */

/* WARNING: Removing unreachable block (ram,0x0059bf37) */

/* WARNING: Removing unreachable block (ram,0x0059bed4) */

/* WARNING: Removing unreachable block (ram,0x0059bed8) */

/* WARNING: Removing unreachable block (ram,0x0059bfd5) */



int FUN_0059b620(int param_1)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ auStack_178 [33];

  uint32_t /* width from decompiler */ uStack_f4;

  int iStack_f0;

  int iStack_ec;

  uint32_t /* width from decompiler */ *puStack_e8;

  int local_d0;

  uint32_t /* width from decompiler */ *local_b0;

  uint32_t /* width from decompiler */ local_a4 [38];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5c64;

  local_c = ExceptionList;

  puStack_e8 = (uint32_t /* width from decompiler */ *)0x59b649;

  ExceptionList = &local_c;

  pvVar2 = operator_new(0x570);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0059b190();

  }

  local_4 = 0xffffffff;

  *(int *)(param_1 + 0x3c) = iVar3;

  if (iVar3 == 0) {

    iVar3 = -0x7ff8fff2;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iStack_f0 = *(int *)(param_1 + 0x3c);

    puStack_e8 = (uint32_t /* width from decompiler */ *)(iStack_f0 + 0x4c0);

    iStack_ec = iStack_f0 + 0x3b8;

    iStack_f0 = iStack_f0 + 4;

    uStack_f4 = 0x59b6b7;

    iVar3 = FUN_007ece60();

    if (iVar3 == 0) {

      puStack_e8 = (uint32_t /* width from decompiler */ *)0x59b6c9;

      pvVar2 = operator_new(0x98);

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 4) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

      puStack_e8 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0x528);

      local_b0 = (uint32_t /* width from decompiler */ *)0x0;

      local_4 = 1;

      iStack_ec = 0x59b70b;

      iVar3 = FUN_007de350();

      if (iVar3 == 0) {

        cVar1 = FUN_0059c4c0();

        if (cVar1 == '\0') {

          for (local_d0 = 0; local_d0 < 0; local_d0 = local_d0 + 1) {

            puStack_e8 = (uint32_t /* width from decompiler */ *)0x59b764;

            puVar4 = operator_new(0x98);

            puVar5 = local_b0;

            puVar6 = puVar4;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar6 = *puVar5;

              puVar5 = puVar5 + 1;

              puVar6 = puVar6 + 1;

            }

            iStack_ec = *local_b0;

            iStack_f0 = 0x59b78f;

            puStack_e8 = puVar4;

            iVar3 = FUN_0059d100();

            if (iVar3 != 0) {

                    /* WARNING: Subroutine does not return */

              puStack_e8 = (uint32_t /* width from decompiler */ *)&UNK_0059b799;

              operator_delete(puVar4);

            }

            local_b0 = local_b0 + 0x26;

          }

        }

        local_4 = CONCAT31(local_4._1_3_,2);

        *(uint8_t *)((int)pvVar2 + 0x8e) = 0;

        puStack_e8 = (uint32_t /* width from decompiler */ *)0x59b7d8;

        FUN_0041ab20();

        iStack_ec = 0x59b7e9;

        puStack_e8 = pvVar2;

        iVar3 = FUN_007ddac0();

        if (iVar3 == 0) {

          *(uint8_t *)((int)pvVar2 + 0x8e) = 1;

          iStack_ec = 0x59b93d;

          puStack_e8 = pvVar2;

          iVar3 = FUN_007ddac0();

          if (iVar3 == 0) {

            puVar5 = local_a4;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar5 = 0;

              puVar5 = puVar5 + 1;

            }

            puVar5 = local_a4;

            puVar6 = auStack_178;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar6 = *puVar5;

              puVar5 = puVar5 + 1;

              puVar6 = puVar6 + 1;

            }

            *(uint8_t *)((int)pvVar2 + 0x8e) = 2;

            FUN_0041c370(0);

            iStack_ec = 0x59bad3;

            puStack_e8 = pvVar2;

            FUN_007ddac0();

            puVar5 = local_a4;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar5 = 0;

              puVar5 = puVar5 + 1;

            }

            puVar5 = local_a4;

            puVar6 = auStack_178;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar6 = *puVar5;

              puVar5 = puVar5 + 1;

              puVar6 = puVar6 + 1;

            }

            *(uint8_t *)((int)pvVar2 + 0x8e) = 3;

            FUN_0041c370(0);

            iStack_ec = 0x59bc2c;

            puStack_e8 = pvVar2;

            FUN_007ddac0();

            puVar5 = local_a4;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar5 = 0;

              puVar5 = puVar5 + 1;

            }

            puVar5 = local_a4;

            puVar6 = auStack_178;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar6 = *puVar5;

              puVar5 = puVar5 + 1;

              puVar6 = puVar6 + 1;

            }

            *(uint8_t *)((int)pvVar2 + 0x8e) = 4;

            FUN_0041c370(0);

            iStack_ec = 0x59bd91;

            puStack_e8 = pvVar2;

            FUN_007ddac0();

            puVar5 = local_a4;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar5 = 0;

              puVar5 = puVar5 + 1;

            }

            puVar5 = local_a4;

            puVar6 = auStack_178;

            for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar6 = *puVar5;

              puVar5 = puVar5 + 1;

              puVar6 = puVar6 + 1;

            }

            *(uint8_t *)((int)pvVar2 + 0x8e) = 5;

            FUN_0041c370(0);

            iStack_ec = 0x59be97;

            puStack_e8 = pvVar2;

            FUN_007ddac0();

                    /* WARNING: Subroutine does not return */

            puStack_e8 = (uint32_t /* width from decompiler */ *)&UNK_0059bfab;

            operator_delete(pvVar2);

          }

        }

      }

      else {

        iVar3 = 0;

      }

    }

  }

  ExceptionList = local_c;

  return iVar3;

}
