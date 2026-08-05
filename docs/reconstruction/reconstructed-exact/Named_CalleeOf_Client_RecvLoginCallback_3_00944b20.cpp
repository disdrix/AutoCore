// =============================================================================
// Named_CalleeOf_Client_RecvLoginCallback_3_00944b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00944b20
// Callee of Client_RecvLoginCallback_3 (+4 other named callers)
// Address:   0x00944b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvLoginCallback_3: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvLoginCallback_3 (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×14, for×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_00410420, FUN_00442fa0, FUN_0048f370, FUN_005742a0, FUN_007246d0, FUN_0079e7d0, FUN_007fc360.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvLoginCallback_3 (+4 other named callers)
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

void Named_CalleeOf_Client_RecvLoginCallback_3_00944b20(char param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_1 != '\0') {

    *(uint8_t *)(in_EAX + 0x30b4) = 1;

    *(uint8_t *)(in_EAX + 0x30b5) = 0;

    if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);

    }

    FUN_007fc970();

    *(uint8_t *)(in_EAX + 0x30ba) = 1;

    *(uint8_t *)(in_EAX + 0x30bb) = 0;

    if (*(int **)(in_EAX + 0x30a8) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x30a8) + 4))(0);

    }

    *(uint8_t *)(in_EAX + 0x30b8) = 1;

    *(uint8_t *)(in_EAX + 0x30b9) = 0;

    if (*(int **)(in_EAX + 0x30a4) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x30a4) + 4))(0);

    }

    *(uint8_t *)(in_EAX + 0x30bc) = 1;

    *(uint8_t *)(in_EAX + 0x30bd) = 0;

    if (*(int **)(in_EAX + 0x30ac) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x30ac) + 4))(0);

    }

    *(uint8_t *)(in_EAX + 0x30be) = 1;

    *(uint8_t *)(in_EAX + 0x30bf) = 0;

    if (*(int **)(in_EAX + 0x30b0) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x30b0) + 4))(0);

    }

    FUN_007fc360();

    Client_GetMissionCompleteAudioTable();

    FUN_007246d0();

    if (*(int *)(in_EAX + 0x31ec) != 0) {

      FUN_005742a0();

    }

    if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0) != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0);

      for (iVar1 = 0x82; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar2 = 0;

        puVar2 = puVar2 + 1;

      }

      **(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0) = 0xffffffff;

    }

    FUN_00943db0();

    FUN_0079e7d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0xde8));

    FUN_00943b80(0);

    FUN_00442fa0(0,0,0,0,0);

    FUN_00410420(0,0);

  }

  if (*(void **)(in_EAX + 0xf44) != (void *)0x0) {

    operator_delete__(*(void **)(in_EAX + 0xf44));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xf44) = 0;

  FUN_008076c0();

  *(uint8_t *)(in_EAX + 0x113) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x134) = 0;

  if (param_1 != '\0') {

    FUN_00801c50(in_EAX);

  }

  if ((*(int **)(in_EAX + 0xf40) != (int *)0x0) &&

     (**(int **)(in_EAX + 0xf40) == *(int *)(in_EAX + 0xf38))) {

    if (param_1 != '\0') {

      FUN_009302b0();

    }

    FUN_00937560(in_EAX);

  }

  if (DAT_00d1b77c != 0) {

    if (param_1 != '\0') {

      FUN_0048f370();

    }

    FUN_009133a0(0);

  }

  return;

}
