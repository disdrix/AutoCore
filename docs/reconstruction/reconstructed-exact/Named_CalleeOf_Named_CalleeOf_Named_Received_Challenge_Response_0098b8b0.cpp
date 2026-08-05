// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Received_Challenge_Response_0098b8b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098b8b0
// Callee of Named_CalleeOf_Named_Received_Challenge_Response_8x
// Address:   0x0098b8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Received_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00424d60×2, FUN_00432040×2, CONCAT11, CONCAT21, CONCAT31, FUN_00424ce0, FUN_00432070, FUN_0077a370.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Received_Challenge_Response_8x
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_Received_Challenge_Response_0098b8b0(int param_1)



{

  char *pcVar1;

  uint uVar2;

  void *pvVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int unaff_ESI;

  

  iVar5 = param_1;

  *(uint8_t *)(unaff_ESI + 0x20) = 0;

  pvVar3 = malloc(0x48);

  pcVar1 = *(char **)(iVar5 + 0xc);

  *(bool *)(unaff_ESI + 0x14) = *pcVar1 == '\0';

  uVar2 = *(uint *)(iVar5 + 0x10);

  if (4 < uVar2) {

    *(uint *)(unaff_ESI + 0x10) =

         CONCAT31(CONCAT21(CONCAT11(pcVar1[1],pcVar1[2]),pcVar1[3]),pcVar1[4]);

    iVar4 = FUN_0077a370(uVar2 - 5,pvVar3);

    if (iVar4 == 0) {

      *(void **)(unaff_ESI + 0xc) = pvVar3;

      if (*(char *)(unaff_ESI + 0x14) == '\0') {

        puVar7 = operator_new(0x18);

        if (puVar7 == (uint32_t /* width from decompiler */ *)0x0) {

          puVar7 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          puVar7[1] = 0;

          puVar7[2] = 0;

          *puVar7 = &PTR_LAB_009d7b00;

          puVar7[4] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10);

          puVar7[3] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

          *(uint8_t *)(puVar7 + 5) = 0;

        }

      }

      else {

        uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

        DAT_00d0d6a0._0_1_ = (uint8_t)((uint)uVar6 >> 0x18);

        DAT_00d0d6a0._1_1_ = (uint8_t)((uint)uVar6 >> 0x10);

        DAT_00d0d6a0._3_1_ = (uint8_t)uVar6;

        param_1 = 0x7fb;

        DAT_00d0d6a0._2_1_ = (uint8_t)((uint)uVar6 >> 8);

        iVar5 = FUN_0077a590(&param_1,1,pvVar3);

        if (iVar5 != 0) {

          return;

        }

        iVar5 = param_1 + 5;

        pvVar3 = operator_new(0x18);

        if (pvVar3 == (void *)0x0) {

          uVar6 = 0;

        }

        else {

          uVar6 = FUN_00424ce0(&DAT_00d0d6a0,iVar5);

        }

        FUN_00432040(uVar6);

        FUN_00424d60();

        pvVar3 = operator_new(0x18);

        if (pvVar3 == (void *)0x0) {

          puVar7 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          puVar7 = (uint32_t /* width from decompiler */ *)FUN_00432070();

        }

      }

      FUN_00432040(puVar7);

      FUN_00424d60();

      *(uint8_t *)(unaff_ESI + 0x20) = 1;

    }

  }

  return;

}
