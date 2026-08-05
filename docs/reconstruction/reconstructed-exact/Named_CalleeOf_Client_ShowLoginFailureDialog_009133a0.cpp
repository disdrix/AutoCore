// =============================================================================
// Named_CalleeOf_Client_ShowLoginFailureDialog_009133a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009133a0
// Callee of Client_ShowLoginFailureDialog (+1 other named callers)
// Address:   0x009133a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowLoginFailureDialog: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_ShowLoginFailureDialog (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00912880×4, FUN_008c8f70, FUN_0090fc50, FUN_00913030, FUN_009133a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_ShowLoginFailureDialog (+1 other named callers)
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

void Named_CalleeOf_Client_ShowLoginFailureDialog_009133a0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int *in_EAX;

  int iVar2;

  

  if (param_1 != in_EAX[0x2a4]) {

    if (((int *)in_EAX[0x2a1] != (int *)0x0) &&

       (iVar2 = (**(code **)(*(int *)in_EAX[0x2a1] + 0xe8))(), iVar2 != 0)) {

      return;

    }

    iVar2 = FUN_00912880();

    if (iVar2 != 0) {

      (**(code **)(*(int *)in_EAX[0x2a1] + 0x318))();

      (**(code **)(*(int *)in_EAX[0x2a1] + 0xfc))(0,0x3f000000);

      iVar2 = FUN_00912880();

      in_EAX[0x2a1] = iVar2;

      in_EAX[0x2a4] = param_1;

      uVar1 = DAT_00af914c;

      if (param_1 == 3) {

        iVar2 = (**(code **)(*in_EAX + 0x1a0))();

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xf0) = DAT_00a10e78;

        *(uint8_t *)(iVar2 + 0x48) = 1;

        *(uint8_t *)(iVar2 + 0xcc) = 1;

        FUN_0090fc50();

      }

      else {

        iVar2 = (**(code **)(*in_EAX + 0x1a0))();

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xf0) = uVar1;

        *(uint8_t *)(iVar2 + 0x48) = 1;

        *(uint8_t *)(iVar2 + 0xcc) = 1;

        FUN_00913030();

      }

      iVar2 = FUN_00912880();

      in_EAX[0x2a2] = iVar2;

      iVar2 = FUN_00912880();

      in_EAX[0x2a3] = iVar2;

      if ((int *)in_EAX[0x2a1] != (int *)0x0) {

        (**(code **)(*(int *)in_EAX[0x2a1] + 0xcc))(1);

        (**(code **)(*(int *)in_EAX[0x2a1] + 0xfc))(1,0x3f000000);

        (**(code **)(*in_EAX + 0x3bc))(in_EAX[0x2a1]);

        if (param_1 == 3) {

          FUN_008c8f70();

        }

      }

      in_EAX[0x2a4] = param_1;

    }

  }

  return;

}
