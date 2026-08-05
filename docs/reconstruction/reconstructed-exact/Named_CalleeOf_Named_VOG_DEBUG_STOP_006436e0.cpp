// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_006436e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006436e0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x006436e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, return×2, while×2.
//  - Notable callees: FUN_006436e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_006436e0(int *param_1,int param_2,int param_3,int param_4)



{

  ushort *puVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  fVar3 = DAT_009e4534;

  iVar2 = *(int *)(param_4 + 0x3e0);

  iVar4 = param_1[1];

  iVar5 = 0;

  if (0 < iVar4) {

    do {

      if (*(int *)(param_4 + 0x14) <= param_3) {

        return;

      }

      iVar6 = 0;

      iVar7 = param_2;

      if (0 < iVar4) {

        do {

          if (*(int *)(param_4 + 0x10) <= iVar7) break;

          puVar1 = (ushort *)(iVar2 + (*(int *)(param_4 + 0x10) * param_3 + iVar7) * 2);

          iVar4 = (uint)*puVar1 - (int)(*(float *)(*param_1 + (iVar4 * iVar5 + iVar6) * 4) * fVar3);

          if (iVar4 < 0xffff) {

            if (iVar4 < 1) {

              iVar4 = 0;

            }

          }

          else {

            iVar4 = 0xffff;

          }

          *puVar1 = (ushort)iVar4;

          iVar4 = param_1[1];

          iVar6 = iVar6 + 1;

          iVar7 = iVar7 + 1;

        } while (iVar6 < iVar4);

      }

      iVar4 = param_1[1];

      param_3 = param_3 + 1;

      iVar5 = iVar5 + 1;

    } while (iVar5 < iVar4);

  }

  return;

}
