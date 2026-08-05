// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec_00702bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00702bb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec
// Address:   0x00702bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1, for×1.
//  - Notable callees: FUN_00703190×3, FUN_00702bb0, realloc.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec_00702bb0(int *param_1,uint param_2,int param_3)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  

  iVar1 = param_3;

  if (param_1[6] <= (param_1[3] + param_3 >> 3) + param_1[2]) {

    FUN_00703190(s_Buffer_too_small_to_pack_bits_00af59c4);

    if (param_1[4] == 0) {

      FUN_00703190(s_Do_not_own_input_buffer__not_pac_00af5a10);

      return;

    }

    pvVar2 = realloc((void *)*param_1,(param_1[6] + 5) * 3 >> 1);

    if (pvVar2 == (void *)0x0) {

      FUN_00703190(s_Could_not_resize_input_buffer__n_00af59e4);

      return;

    }

    iVar3 = param_1[6];

    if (iVar3 < iVar3 * 3 + 0xf >> 1) {

      do {

        *(uint8_t *)(iVar3 + (int)pvVar2) = 0;

        iVar3 = iVar3 + 1;

      } while (iVar3 < (param_1[6] + 5) * 3 >> 1);

    }

    param_1[6] = (param_1[6] + 5) * 3 >> 1;

    *param_1 = (int)pvVar2;

  }

  for (; param_3 != 0; param_3 = param_3 + -1) {

    *(byte *)(*param_1 + param_1[2]) =

         *(byte *)(*param_1 + param_1[2]) |

         ((byte)(param_2 >> ((byte)(iVar1 + -1) & 0x1f)) & 1) << (7U - (char)param_1[3] & 0x1f);

    iVar3 = param_1[3];

    param_1[3] = iVar3 + 1;

    if (iVar3 + 1 == 8) {

      param_1[3] = 0;

      param_1[2] = param_1[2] + 1;

    }

    param_1[1] = param_1[1] + 1;

    iVar1 = iVar1 + -1;

  }

  return;

}
