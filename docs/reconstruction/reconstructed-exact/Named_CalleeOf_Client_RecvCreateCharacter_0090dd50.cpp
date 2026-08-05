// =============================================================================
// Named_CalleeOf_Client_RecvCreateCharacter_0090dd50
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dd50
// Callee of Client_RecvCreateCharacter
// Address:   0x0090dd50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×10, return×2.
//  - Notable callees: FUN_0090dd50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvCreateCharacter
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Client_RecvCreateCharacter_0090dd50(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  float fVar2;

  float fVar3;

  float fVar4;

  

  if (*(int *)(in_EAX + 0x60c) == 0) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x524) = DAT_00af9154;

    fVar2 = DAT_00af915c;

    if (DAT_00d1b26c == '\0') {

      fVar2 = DAT_00af9158;

    }

    fVar4 = g_flOne / _DAT_00af9150;

    *(float *)(in_EAX + 0x528) = fVar2;

    *(float *)(in_EAX + 0x534) = (fVar2 - *(float *)(in_EAX + 0x524)) * fVar4;

    if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) {

      fVar2 = DAT_00af9168;

      if (DAT_00d1b26c == '\0') {

        fVar2 = DAT_00af9164;

      }

      fVar2 = fVar2 - DAT_00af9160;

      fVar3 = fVar2 * DAT_00a0f298;

      *(float *)(in_EAX + 0x52c) = fVar3;

      *(float *)(in_EAX + 0x530) = fVar2 * fVar4 + fVar3;

    }

  }

  else {

    if (*(int *)(in_EAX + 0x60c) == 1) {

      *(float *)(in_EAX + 0x524) = DAT_00af9160;

      fVar2 = DAT_00af9168;

      if (DAT_00d1b26c == '\0') {

        fVar2 = DAT_00af9164;

      }

      *(float *)(in_EAX + 0x528) = fVar2;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x524) = DAT_00af916c;

      uVar1 = DAT_00af9170;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x528) = DAT_00af9170;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x530) = uVar1;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x52c) = uVar1;

    }

    *(float *)(in_EAX + 0x534) =

         (*(float *)(in_EAX + 0x528) - *(float *)(in_EAX + 0x524)) / _DAT_00af9150;

  }

  if (*(float *)(in_EAX + 0x530) < *(float *)(in_EAX + 0x528) ||

      *(float *)(in_EAX + 0x530) == *(float *)(in_EAX + 0x528)) {

    if (*(float *)(in_EAX + 0x530) <= *(float *)(in_EAX + 0x524) &&

        *(float *)(in_EAX + 0x524) != *(float *)(in_EAX + 0x530)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x530) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x524);

    }

  }

  else {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x530) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x528);

  }

  if (*(float *)(in_EAX + 0x528) <= *(float *)(in_EAX + 0x52c) &&

      *(float *)(in_EAX + 0x52c) != *(float *)(in_EAX + 0x528)) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x52c) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x528);

    return;

  }

  if (*(float *)(in_EAX + 0x52c) <= *(float *)(in_EAX + 0x524) &&

      *(float *)(in_EAX + 0x524) != *(float *)(in_EAX + 0x52c)) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x52c) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x524);

  }

  return;

}
