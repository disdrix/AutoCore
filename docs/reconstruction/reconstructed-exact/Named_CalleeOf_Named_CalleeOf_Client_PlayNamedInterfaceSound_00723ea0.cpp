// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00723ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00723ea0
// Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x00723ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper. Evidence string: "replaceSoundInChannel found a dead sound in reserves(0x%X), removing it\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "replaceSoundInChannel found a dead sound in reserves(0x%X), removing it\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0071f810, FUN_00723ab0, FUN_00723ea0, FUN_007a4480, reserves.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
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

void Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00723ea0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int *piVar4;

  int unaff_EBX;

  int iVar5;

  

  FUN_00723ab0();

  if (0 < *(int *)(param_1 + 0x214)) {

    iVar5 = 0x2f;

    iVar3 = 0x30 - *(int *)(param_1 + 0x214);

    if (iVar3 < 0x30) {

      piVar4 = (int *)(param_1 + 0x3d8);

      do {

        iVar1 = *piVar4;

        if (iVar1 == 0) break;

        if ((*(char *)(iVar1 + 0x1c5) == '\0') && (*(char *)(iVar1 + 0x3a) == '\0')) {

          FUN_007a4480(0,"replaceSoundInChannel found a dead sound in reserves(0x%X), removing it\n"

                       ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x31c + iVar5 * 4));

          FUN_0071f810();

          puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x31c + iVar5 * 4);

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar2)(1);

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c + iVar5 * 4) = 0;

          break;

        }

        iVar5 = iVar5 + -1;

        piVar4 = piVar4 + -1;

      } while (iVar3 <= iVar5);

    }

    if (0x30 - *(int *)(param_1 + 0x214) <= iVar5) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c + iVar5 * 4) =

           *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c + unaff_EBX * 4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c + unaff_EBX * 4) = 0;

    }

  }

  return;

}
