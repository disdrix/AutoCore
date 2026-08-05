// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069a090
// -----------------------------------------------------------------------------
// Stable ID: aa_0069a090
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069a090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_006a3db0×3, FUN_0068c5d0, FUN_0069a090.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069a090(int param_1,int param_2,int param_3)



{

  short sVar1;

  short sVar2;

  void *pvVar3;

  uint uVar4;

  int iVar5;

  int local_4;

  

  if (1 < *(ushort *)(param_1 + 0x20)) {

    uVar4 = (uint)*(ushort *)(param_1 + 0x20);

    local_4 = *(int *)(param_1 + 0x1c) + -1;

    iVar5 = (uVar4 + 2) * local_4;

    pvVar3 = operator_new__(iVar5 * 4);

    FUN_0068c5d0(param_2,pvVar3,iVar5 * 2);

    iVar5 = 0;

    if (0 < local_4) {

      do {

        sVar1 = FUN_006a3db0();

        sVar2 = FUN_006a3db0();

        *(short *)((int)pvVar3 + iVar5 * 2) =

             *(short *)(param_1 + 0x24) + sVar2 + *(short *)(param_1 + 0x20) + 1;

        *(short *)((int)pvVar3 + (iVar5 + 1) * 2) = *(short *)(param_1 + 0x24) + sVar2;

        iVar5 = iVar5 + 2;

        if (1 < uVar4) {

          param_2 = uVar4 - 1;

          do {

            sVar2 = FUN_006a3db0();

            *(short *)((int)pvVar3 + iVar5 * 2) =

                 *(short *)(param_1 + 0x24) + sVar2 + *(short *)(param_1 + 0x20) + 1;

            *(short *)((int)pvVar3 + (iVar5 + 1) * 2) = *(short *)(param_1 + 0x24) + sVar2;

            iVar5 = iVar5 + 2;

            param_2 = param_2 + -1;

          } while (param_2 != 0);

        }

        *(short *)((int)pvVar3 + (iVar5 + 1) * 2 + -2) =

             *(short *)(param_1 + 0x20) * 2 + *(short *)(param_1 + 0x24) + 1 + sVar1;

        *(short *)((int)pvVar3 + (iVar5 + 2) * 2 + -2) =

             *(short *)(param_1 + 0x24) + sVar1 + *(short *)(param_1 + 0x20);

        *(short *)((int)pvVar3 + (iVar5 + 3) * 2 + -2) =

             *(short *)(param_1 + 0x24) + *(short *)(param_1 + 0x20) + 1 + sVar1;

        *(short *)((int)pvVar3 + (iVar5 + 3) * 2) =

             *(short *)(param_1 + 0x24) + sVar1 + *(short *)(param_1 + 0x20) + 1;

        iVar5 = iVar5 + 4;

        local_4 = local_4 + -1;

      } while (local_4 != 0);

    }

    *(short *)(param_3 + 0x1e) = *(short *)(param_3 + 0x1e) + 1;

  }

  return;

}
