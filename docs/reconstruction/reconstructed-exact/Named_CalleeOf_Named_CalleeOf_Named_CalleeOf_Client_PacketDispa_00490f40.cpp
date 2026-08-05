// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_00490f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00490f40
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x00490f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper. Evidence string: "SkyBox". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "SkyBox"
//   - "SkyBoxCloud"
//   - "SkyBoxForeground"
//   - "DiffuseTextureBlending"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, goto×2, do×1, return×1.
//  - Notable callees: FUN_00746270×3, FUN_00970140×3, FUN_00490f40, FUN_004aa6c0.
//  - Strings: "SkyBox"; "SkyBoxCloud"; "SkyBoxForeground"; "DiffuseTextureBlending".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_00490f40(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  short local_c;

  short local_a;

  short local_8;

  short local_6;

  short local_4;

  short local_2;

  

  FUN_004aa6c0();

  FUN_00746270(&local_c,"SkyBox");

  FUN_00746270(&local_8,"SkyBoxCloud");

  FUN_00746270(&local_4,"SkyBoxForeground");

  if ((*(short *)(param_1 + 0xa0) < 1) &&

     (iVar5 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar5 != 0)) {

    iVar5 = **(int **)(iVar5 + 0x3f4);

  }

  else {

    iVar5 = *(int *)(param_1 + 0xa4);

  }

  if ((*(short *)(param_1 + 0xb0) < 1) &&

     (iVar4 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar4 != 0)) {

    iVar4 = **(int **)(iVar4 + 0x3f0);

  }

  else {

    iVar4 = *(int *)(param_1 + 0xb4);

  }

  *(uint8_t *)(param_1 + 0x90) = 1;

  iVar6 = 0;

  do {

    while( true ) {

      iVar1 = *(int *)(param_1 + 0x94);

      if (*(int *)(iVar1 + 0xc0) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(iVar1 + 0xc4) - *(int *)(iVar1 + 0xc0) >> 2;

      }

      if (iVar3 <= iVar6) {

        return;

      }

      iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xc0) + iVar6 * 4) + 0x20);

      if ((*(short *)(iVar1 + 0x1c) != local_c) || (*(short *)(iVar1 + 0x1e) != local_a)) break;

      if (iVar4 == 0) {

LAB_004910cd:

        iVar6 = iVar6 + 1;

      }

      else {

        FUN_00970140("DiffuseTextureBlending",iVar4);

        iVar6 = iVar6 + 1;

      }

    }

    if ((*(short *)(iVar1 + 0x1c) != local_8) || (*(short *)(iVar1 + 0x1e) != local_6)) {

      if ((((*(short *)(iVar1 + 0x1c) == local_4) && (*(short *)(iVar1 + 0x1e) == local_2)) &&

          (iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar1 != 0)) &&

         (puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x3f8), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

        FUN_00970140("DiffuseTextureBlending",*puVar2);

      }

      goto LAB_004910cd;

    }

    if (iVar5 == 0) goto LAB_004910cd;

    FUN_00970140("DiffuseTextureBlending",iVar5);

    iVar6 = iVar6 + 1;

  } while( true );

}
