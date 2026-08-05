// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00996ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00996ff0
// Callee of Named_CalleeOf_Client_PacketDispatch (+1 other named callers)
// Address:   0x00996ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_PacketDispatch (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×9, goto×2, return×1.
//  - Notable callees: FUN_004010f0×2, FUN_004017b0×2, FUN_007fe140, FUN_00996ff0, Object_ResolveFromTFID.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00996ff0(uint param_1,int param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  void *pvVar4;

  uint *puVar5;

  int unaff_ESI;

  uint local_8;

  uint local_4;

  

  local_8 = FUN_004017b0();

  if (local_8 == *(uint *)(unaff_ESI + 0x154)) {

LAB_0099702c:

    local_4 = *(uint *)(unaff_ESI + 0x154);

    puVar5 = &local_4;

  }

  else {

    if ((param_2 < *(int *)(local_8 + 0x14)) ||

       ((param_2 <= *(int *)(local_8 + 0x14) && (param_1 < *(uint *)(local_8 + 0x10)))))

    goto LAB_0099702c;

    puVar5 = &local_8;

  }

  uVar1 = *puVar5;

  if (uVar1 != *(uint *)(unaff_ESI + 0x154)) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(uVar1 + 0x18);

    FUN_007fe140(unaff_ESI);

    if (*(int *)(unaff_ESI + 0xe98) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) + 4 +

              *(int *)(unaff_ESI + 0xe98);

    }

    if (((puVar2[0x2b] != iVar3) &&

        (iVar3 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar3 != 0)) &&

       (puVar2[0x2b] != *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3)) {

      pvVar4 = Object_ResolveFromTFID((TFID_16 *)(puVar2 + 0x58));

      if (pvVar4 == (void *)0x0) {

        (**(code **)*puVar2)(1);

      }

    }

    FUN_004010f0(unaff_ESI + 0x150,&local_4,uVar1);

  }

  local_4 = FUN_004017b0();

  if (local_4 != *(uint *)(unaff_ESI + 0x3094)) {

    if ((*(int *)(local_4 + 0x14) <= param_2) &&

       ((*(int *)(local_4 + 0x14) < param_2 || (*(uint *)(local_4 + 0x10) <= param_1)))) {

      puVar5 = &local_4;

      goto LAB_009970f7;

    }

  }

  puVar5 = &param_1;

  param_1 = *(uint *)(unaff_ESI + 0x3094);

LAB_009970f7:

  if (*puVar5 != *(uint *)(unaff_ESI + 0x3094)) {

    FUN_004010f0(unaff_ESI + 0x3090,&param_1,*puVar5);

  }

  return;

}
