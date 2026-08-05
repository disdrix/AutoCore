// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004c4e80
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4e80
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x004c4e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_004c4e20×4, ABS, FUN_004c4e80, FUN_004fbef0, FUN_005d63c0, FUN_005d6410, FUN_005d6720.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004c4e80(int param_1)



{

  uint uVar1;

  int iVar2;

  float10 fVar3;

  uint32_t /* width from decompiler */ uVar4;

  float local_34;

  float local_30;

  uint8_t local_28 [12];

  float local_1c;

  

  if (*(int *)(param_1 + 0x250) != 0) {

    uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1);

    if (((~*(uint *)(param_1 + 0x318) & uVar1 & 6) == 0) && ((uVar1 & 1) == 0)) {

      uVar4 = 0;

    }

    else {

      uVar4 = 1;

    }

    FUN_004fbef0(uVar4);

    iVar2 = *(int *)(param_1 + 0x250);

    if (*(int *)(iVar2 + 0x1a0) != 0) {

      local_34 = (float)(int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac +

                                                         iVar2) + 0x3c) + 0x69a);

      local_30 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) +

                                    0x3c) + 0x5a8);

      uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1);

      if ((uVar1 & 0x1000) == 0) {

        if ((uVar1 & 0x4000) != 0) {

          local_34 = local_34 * DAT_00aaa6c4;

        }

      }

      else {

        local_30 = DAT_00af0bcc * g_flOverheatCoolFrac + local_30;

      }

      fVar3 = (float10)FUN_004c4e20();

      if (fVar3 < (float10)g_flZero) {

        fVar3 = (float10)FUN_004c4e20();

        local_30 = (float)(ABS(fVar3) * (float10)DAT_00af0bcc + (float10)local_30);

      }

      iVar2 = *(int *)(*(int *)(param_1 + 0x250) + 0x1a0);

      FUN_005d6720();

      FUN_005d63c0(local_28);

      fVar3 = (float10)FUN_004c4e20();

      if (fVar3 * (float10)local_34 <= (float10)g_flZero) {

        local_1c = 0.0;

      }

      else {

        fVar3 = (float10)FUN_004c4e20();

        local_1c = (float)(fVar3 * (float10)local_34);

      }

      local_1c = local_1c + local_34;

      if (local_1c <= DAT_00a0f524) {

        local_1c = DAT_00a0f524;

      }

      FUN_005d6410(local_28);

      *(float *)(*(int *)(*(int *)(iVar2 + 4) + 0x2c) + 0x30) = local_30;

    }

  }

  return;

}
