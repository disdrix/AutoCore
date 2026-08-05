// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0076d9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d9d0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0076d9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×2, do×1, while×1.
//  - Notable callees: FUN_0076d9d0, GetCurrentThread.
//  - Return sites: 3.

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

int Named_CalleeOf_Named_VOG_DEBUG_STOP_0076d9d0(char *param_1,int param_2,int param_3,int param_4)



{

  uint32_t /* width from decompiler */ *in_EAX;

  HANDLE pvVar1;

  int iVar2;

  int iVar3;

  uint8_t *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ local_3e0 [8];

  uint8_t *local_3c0;

  uint32_t /* width from decompiler */ local_3bc;

  uint32_t /* width from decompiler */ local_3b4;

  uint32_t /* width from decompiler */ local_3b0;

  uint32_t /* width from decompiler */ local_3ac;

  uint32_t /* width from decompiler */ local_3a4;

  uint32_t /* width from decompiler */ local_2d8 [45];

  uint8_t *local_224;

  uint32_t /* width from decompiler */ local_220;

  uint32_t /* width from decompiler */ local_214;

  

  puVar4 = &stack0xfffffffc;

  if (*param_1 == '\0') {

    return 0;

  }

  puVar5 = local_3e0;

  for (iVar3 = 0x42; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  local_3e0[3] = 3;

  local_3b4 = 3;

  local_3a4 = 3;

  local_3e0[0] = unaff_retaddr;

  if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = local_2d8;

    for (iVar3 = 0xb3; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *in_EAX;

      in_EAX = in_EAX + 1;

      puVar5 = puVar5 + 1;

    }

    local_3e0[0] = local_220;

    local_3b0 = local_214;

    local_3ac = 0;

    puVar4 = local_224;

  }

  local_3e0[1] = 0;

  local_3bc = 0;

  local_3c0 = puVar4;

  pvVar1 = GetCurrentThread();

  iVar6 = 0;

  iVar3 = 0;

  if (0 < param_4) {

    do {

      iVar2 = (*DAT_00d0dfd0)(0x14c,*(uint32_t /* width from decompiler */ *)(param_1 + 4),pvVar1,local_3e0,local_2d8,0,

                              DAT_00d0dfac,DAT_00d0dfc0,0);

      if (iVar2 == 0) {

        return iVar3;

      }

      if (param_2 < iVar6) {

        *(uint32_t /* width from decompiler */ *)(param_3 + iVar3 * 4) = local_3e0[0];

        iVar3 = iVar3 + 1;

      }

      iVar6 = iVar6 + 1;

    } while (iVar3 < param_4);

  }

  return iVar3;

}
