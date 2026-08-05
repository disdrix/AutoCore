// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00772b90
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00772b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00770490, FUN_00770650, FUN_00770820, FUN_00771c00, FUN_00772b90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772b90(int *param_1,int param_2)



{

  int *in_EAX;

  int iVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  uint *puVar5;

  int local_c;

  

  if ((((param_1 == in_EAX) || (iVar1 = FUN_00770650(), iVar1 == 0)) &&

      ((param_2 / 0x1c + 1 + *in_EAX <= in_EAX[1] || (iVar1 = FUN_00770490(), iVar1 == 0)))) &&

     ((param_2 < 0x1c || (iVar1 = FUN_00771c00(), iVar1 == 0)))) {

    if (param_2 % 0x1c != 0) {

      bVar2 = (byte)(param_2 % 0x1c);

      local_c = 0;

      uVar4 = 0;

      puVar5 = (uint *)in_EAX[3];

      if (0 < *in_EAX) {

        do {

          uVar3 = *puVar5 >> (0x1c - bVar2 & 0x1f) & (1 << (bVar2 & 0x1f)) - 1U;

          *puVar5 = (*puVar5 << (bVar2 & 0x1f) | uVar4) & 0xfffffff;

          local_c = local_c + 1;

          uVar4 = uVar3;

          puVar5 = puVar5 + 1;

        } while (local_c < *in_EAX);

        if (uVar3 != 0) {

          *(uint *)(in_EAX[3] + *in_EAX * 4) = uVar3;

          *in_EAX = *in_EAX + 1;

        }

      }

    }

    FUN_00770820();

    iVar1 = 0;

  }

  return iVar1;

}
