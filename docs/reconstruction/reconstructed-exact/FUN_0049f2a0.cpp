// =============================================================================
// FUN_0049f2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049f2a0
// Address:   0x0049f2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049f2a0 @ 0x0049f2a0
// Stable ID: aa_0049f2a0
// Embedded strings (evidence for future rename):
//   - "range"
//   - "amount"
//   - "useBodyH"
//   - "useBodyMass"
//   - "extraForce"
//   - "extraForceScalar"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2.
//  - Notable callees: FUN_00799300×3, FUN_007996d0×2, SysFreeString×2, _wcsicmp×2, FUN_0049f2a0, FUN_00798bb0, FUN_00799160, FUN_007a4480.
//  - Strings: "range"; "amount"; "useBodyH"; "useBodyMass".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * FUN_0049f2a0(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *local_228;

  uint32_t /* width from decompiler */ local_224;

  wchar_t awStack_220 [2];

  uint32_t /* width from decompiler */ auStack_21c [129];

  void *pvStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009a0f8e;

  pvStack_14 = ExceptionList;

  local_224 = 0;

  local_c = 0;

  ExceptionList = &pvStack_14;

  if (param_1 != (int *)0x0) {

    ExceptionList = &pvStack_14;

    iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_228);

    if ((iVar1 == 0) && (local_228 != (int *)0x0)) {

      awStack_220[0] = L'\0';

      awStack_220[1] = L'\0';

      puVar3 = auStack_21c;

      for (iVar1 = 0x81; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      puVar2 = operator_new(0x30);

      puVar3 = puVar2;

      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      FUN_00799300(local_228,L"range",puVar2);

      FUN_00799300(local_228,L"amount",puVar2 + 1);

      FUN_007996d0(local_228,L"useBodyH",puVar2 + 9);

      FUN_007996d0(local_228,L"useBodyMass",(int)puVar2 + 0x25);

      FUN_00799160(local_228,L"extraForce",puVar2 + 4);

      FUN_00799300(local_228,L"extraForceScalar",puVar2 + 8);

      FUN_00798bb0(local_228,L"forceFalloff",awStack_220);

      iVar1 = _wcsicmp(awStack_220,L"Flat");

      if (iVar1 == 0) {

        puVar2[10] = 0;

      }

      else {

        iVar1 = _wcsicmp(awStack_220,L"Exponential");

        puVar2[10] = 2 - (uint)(iVar1 != 0);

      }

      (**(code **)(*local_228 + 8))(local_228);

      SysFreeString((BSTR)0x0);

      ExceptionList = pvStack_18;

      return puVar2;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  SysFreeString((BSTR)0x0);

  ExceptionList = pvStack_14;

  return (uint32_t /* width from decompiler */ *)0x0;

}
