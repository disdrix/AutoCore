// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_005f4230
// -----------------------------------------------------------------------------
// Stable ID: aa_005f4230
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x005f4230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1.
//  - Notable callees: FUN_00632400×4, FUN_006468d0×4, FUN_00646d40×2, FUN_005f4230, FUN_005f52b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_005f4230(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ unaff_retaddr;

  int iStack_c;

  uint32_t /* width from decompiler */ local_8 [2];

  

  local_8[0] = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_00646d40(param_1);

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    do {

      if (puVar3[2] == 2) {

        uVar5 = puVar3[5];

        pcVar4 = (char *)FUN_00632400(&stack0xfffffff0,uVar5);

        if (*pcVar4 == '\0') {

          pcVar4 = (char *)FUN_00632400(&stack0xfffffff1,uVar5);

          if (*pcVar4 == '\0') {

            pcVar4 = (char *)FUN_00632400(&stack0xfffffff2,uVar5);

            if (*pcVar4 == '\0') {

              pcVar4 = (char *)FUN_00632400(&stack0xfffffff3,uVar5);

              if (*pcVar4 != '\0') {

                uVar5 = FUN_006468d0(puVar3,0);

                *param_1 = uVar5;

              }

            }

            else {

              FUN_006468d0(puVar3,0);

              iStack_c = iStack_c + 1;

            }

          }

          else {

            FUN_006468d0(puVar3,0);

          }

        }

        else {

          local_8[0] = FUN_006468d0(puVar3,0);

          iVar1 = *(int *)(param_3 + 4);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)(param_3 + 0xc) - iVar1 >> 2) <=

              (uint)(*(int *)(param_3 + 8) - iVar1 >> 2))) {

            FUN_005f52b0(*(uint32_t /* width from decompiler */ *)(param_3 + 8),1,local_8);

          }

          else {

            puVar2 = *(uint32_t /* width from decompiler */ **)(param_3 + 8);

            *puVar2 = local_8[0];

            *(uint32_t /* width from decompiler */ **)(param_3 + 8) = puVar2 + 1;

          }

        }

      }

      *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

      if (*(short *)((int)puVar3 + 6) == 0) {

        (**(code **)*puVar3)(1);

      }

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00646d40(unaff_retaddr);

    } while (puVar3 != (uint32_t /* width from decompiler */ *)0x0);

    return iStack_c;

  }

  return 0;

}
