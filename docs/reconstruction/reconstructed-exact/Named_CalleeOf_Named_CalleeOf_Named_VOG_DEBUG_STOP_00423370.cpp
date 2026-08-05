// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00423370
// -----------------------------------------------------------------------------
// Stable ID: aa_00423370
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00423370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_0041d7b0×3, FUN_00437cd0×2, CoCreateInstance, FUN_00423370, VariantInit.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

HRESULT Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00423370(uint32_t /* width from decompiler */ param_1,char param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  HRESULT HVar1;

  int *local_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  _union_2683 _Stack_1c;

  int *piStack_4;

  

  FUN_00437cd0();

  HVar1 = CoCreateInstance((IID *)&DAT_00a8605c,(LPUNKNOWN)0x0,1,(IID *)&DAT_00a8604c,&local_50);

  if (-1 < HVar1) {

    HVar1 = (**(code **)(*local_50 + 0xc))(local_50,0,1,param_1,&DAT_00a8607c);

    if (-1 < HVar1) {

      if (param_2 != '\0') {

        FUN_00437cd0();

        (*(code *)**(uint32_t /* width from decompiler */ **)*in_EAX)((uint32_t /* width from decompiler */ *)*in_EAX,&DAT_00a8606c,&param_2);

        VariantInit((VARIANTARG *)&_Stack_1c.n2);

        uStack_30 = DAT_00a140ec;

        uStack_24 = DAT_00a140f8;

        uStack_34 = DAT_00a140e8;

        uStack_2c = DAT_00a140f0;

        local_50 = DAT_00a140d8;

        uStack_28 = DAT_00a140f4;

        uStack_20 = DAT_00a140fc;

        uStack_44 = DAT_00a140e4;

        uStack_4c = DAT_00a140dc;

        uStack_3c = 0;

        uStack_40 = 0x40;

        _Stack_1c.n2.vt = 2;

        _Stack_1c._8_4_ = 3;

        uStack_48 = DAT_00a140e0;

        HVar1 = (**(code **)(*piStack_4 + 0x14))(piStack_4,1,&stack0xffffffa8);

        FUN_0041d7b0();

        if (HVar1 < 0) goto LAB_004234a6;

      }

      HVar1 = (**(code **)(*(int *)*in_EAX + 0xc))((int *)*in_EAX);

      FUN_0041d7b0();

      return HVar1;

    }

  }

LAB_004234a6:

  FUN_0041d7b0();

  return HVar1;

}
