// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_007a6410
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6410
// Callee of Named_CalleeOf_Client_RecvDestroyObject
// Address:   0x007a6410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvDestroyObject: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, return×2, while×2.
//  - Notable callees: FUN_007a6410.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvDestroyObject
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_007a6410(int param_1,int *param_2,int *param_3)



{

  int iVar1;

  uint uVar2;

  int in_EAX;

  int iVar3;

  uint unaff_EBX;

  int *piVar4;

  int iVar5;

  

  iVar3 = *(int *)(param_1 + 0x58 + in_EAX * 4);

  iVar5 = iVar3 + -1;

  if (-1 < iVar5) {

    piVar4 = (int *)(param_1 + (iVar3 + 0xb + in_EAX * 2) * 4);

    do {

      iVar3 = 0;

      do {

        uVar2 = *(uint *)(*piVar4 + iVar3 * 0x14);

        iVar1 = *piVar4 + iVar3 * 0x14;

        if (unaff_EBX == uVar2) {

          if (iVar3 != -1) {

            *param_2 = iVar5;

            *param_3 = iVar3;

            return;

          }

          break;

        }

        if (uVar2 < unaff_EBX) {

          iVar3 = *(int *)(iVar1 + 0xc);

        }

        else {

          iVar3 = *(int *)(iVar1 + 0x10);

        }

      } while (iVar3 != -1);

      iVar5 = iVar5 + -1;

      piVar4 = piVar4 + -1;

    } while (-1 < iVar5);

  }

  *param_3 = -1;

  *param_2 = -1;

  return;

}
