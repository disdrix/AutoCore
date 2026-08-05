// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069a730
// -----------------------------------------------------------------------------
// Stable ID: aa_0069a730
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069a730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: NAN×4, CONCAT22×2, CONCAT31, FUN_0069a730, FUN_006a1be0.
//  - Return sites: 2.

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

uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069a730(int *param_1,float param_2)



{

  float fVar1;

  float10 fVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  float10 fVar6;

  

  piVar3 = *(int **)(DAT_00d08ebc + 0x28);

  if (piVar3 == (int *)0x0) {

    iVar5 = 1;

    piVar3 = param_1;

    while (piVar3 != (int *)0x0) {

      if (((int *)*piVar3 == (int *)0x0) || (-1 < iVar5)) {

        param_2 = (float)piVar3[1];

        break;

      }

      iVar5 = iVar5 + 1;

      piVar3 = (int *)*piVar3;

    }

  }

  fVar1 = *(float *)(DAT_00d08ebc + 0x20);

  uVar4 = CONCAT22((short)((uint)piVar3 >> 0x10),

                   (ushort)(param_2 < fVar1) << 8 | (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |

                   (ushort)(param_2 == fVar1) << 0xe);

  if (param_2 < fVar1 == 0 && (param_2 == fVar1) == 0) {

    fVar6 = (float10)FUN_006a1be0(0,0x3f800000);

    fVar2 = (float10)*(float *)(DAT_00d08ebc + 0x24);

    uVar4 = CONCAT31((int3)(CONCAT22((short)((uint)DAT_00d08ebc >> 0x10),

                                     (ushort)(fVar6 < fVar2) << 8 |

                                     (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                                     (ushort)(fVar6 == fVar2) << 0xe) >> 8),1);

    if (fVar6 < fVar2 != (fVar6 == fVar2)) {

      return uVar4;

    }

  }

  return uVar4 & 0xffffff00;

}
