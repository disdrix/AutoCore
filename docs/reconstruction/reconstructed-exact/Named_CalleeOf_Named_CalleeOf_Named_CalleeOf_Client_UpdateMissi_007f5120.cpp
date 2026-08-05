// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UpdateMissi_007f5120
// -----------------------------------------------------------------------------
// Stable ID: aa_007f5120
// Callee of Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal
// Address:   0x007f5120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal: mission/objective helper. Evidence string: "Joy_POV%d_%c". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Joy_POV%d_%c"
//   - "Joy_Button%03d"
//   - "Joy_Axis%s%c%c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~610 non-empty decompiler lines.
//  - Control keywords: goto×12, if×10, return×5, switch×3, do×1, while×1.
//  - Notable callees: CONCAT22×63, CONCAT12×10, SUB42×3, _snprintf×3, FUN_007f5120, SUB41.
//  - Strings: "Joy_POV%d_%c"; "Joy_Button%03d"; "Joy_Axis%s%c%c".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal
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



uint8_t * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UpdateMissi_007f5120(uint32_t /* width from decompiler */ param_1,uint param_2)



{

  uint uVar1;

  uint16_t uVar2;

  uint16_t uVar3;

  uint16_t uVar4;

  char *pcVar5;

  uint8_t *puVar6;

  byte bVar7;

  char cVar8;

  uint uVar9;

  char *pcVar10;

  ushort uVar11;

  uint16_t local_10;

  uint16_t uStack_e;

  char acStack_c [2];

  uint local_a;

  uint32_t /* width from decompiler */ local_6;

  uint16_t local_2;

  

  uVar1 = (uint)_DAT_00d1f73c;

  uVar9 = param_2 & 0xffff;

  _DAT_00d1f73c = (uint8_t *)((uint)_DAT_00d1f73c & 0xffffff00);

  puVar6 = _DAT_00d1f73c;

  uVar3 = _DAT_00d1f742;

  if (0xf00 < uVar9) {

    switch(uVar9) {

    case 0xf01:

      _DAT_00d1f73c = (uint8_t *)s_MOUSE2_00a84ea0._0_4_;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,s_MOUSE2_00a84ea0._4_2_);

      cVar8 = s_MOUSE2_00a84ea0[6];

      break;

    case 0xf02:

      _DAT_00d1f73c = (uint8_t *)s_MOUSE3_00a84e98._0_4_;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,s_MOUSE3_00a84e98._4_2_);

      cVar8 = s_MOUSE3_00a84e98[6];

      break;

    case 0xf03:

      _DAT_00d1f73c = DAT_00a84e90;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,DAT_00a84e94);

      cVar8 = DAT_00a84e96;

      break;

    case 0xf04:

      _DAT_00d1f73c = DAT_00a84e88;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,DAT_00a84e8c);

      cVar8 = DAT_00a84e8e;

      break;

    case 0xf05:

      _DAT_00d1f73c = (uint8_t *)s_MOUSE6_00a84e80._0_4_;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,s_MOUSE6_00a84e80._4_2_);

      cVar8 = s_MOUSE6_00a84e80[6];

      break;

    case 0xf06:

      _DAT_00d1f73c = DAT_00a84e78;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,DAT_00a84e7c);

      cVar8 = DAT_00a84e7e;

      break;

    case 0xf07:

      _DAT_00d1f73c = DAT_00a84e70;

      _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,DAT_00a84e74);

      cVar8 = DAT_00a84e76;

      break;

    default:

      goto switchD_007f5157_caseD_54;

    }

    goto LAB_007f5c0c;

  }

  if (uVar9 == 0xf00) {

    _DAT_00d1f73c = (uint8_t *)s_MOUSE1_00a84ea8._0_4_;

    _DAT_00d1f740 = CONCAT22(_DAT_00d1f742,s_MOUSE1_00a84ea8._4_2_);

    cVar8 = s_MOUSE1_00a84ea8[6];

    goto LAB_007f5c0c;

  }

  _DAT_00d1f73e = SUB42(uVar1,2);

  uVar2 = _DAT_00d1f73e;

  uVar4 = _DAT_00d1f746;

  DAT_00d1f73c_2._1_1_ = SUB41(uVar1,3);

  switch(uVar9) {

  case 1:

    _DAT_00d1f73c = (uint8_t *)s_ESCAPE_00a84f2c._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_ESCAPE_00a84f2c._4_2_);

    cVar8 = s_ESCAPE_00a84f2c[6];

    goto LAB_007f5c0c;

  case 2:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x31);

    puVar6 = _DAT_00d1f73c;

    break;

  case 3:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x32);

    puVar6 = _DAT_00d1f73c;

    break;

  case 4:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x33);

    puVar6 = _DAT_00d1f73c;

    break;

  case 5:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x34);

    puVar6 = _DAT_00d1f73c;

    break;

  case 6:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x35);

    puVar6 = _DAT_00d1f73c;

    break;

  case 7:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x36);

    puVar6 = _DAT_00d1f73c;

    break;

  case 8:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x37);

    puVar6 = _DAT_00d1f73c;

    break;

  case 9:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x38);

    puVar6 = _DAT_00d1f73c;

    break;

  case 10:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x39);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xb:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x30);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xc:

    _DAT_00d1f73c = (uint8_t *)s_MINUS_00a84f3c._0_4_;

    _DAT_00d1f740 = s_MINUS_00a84f3c._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xd:

    _DAT_00d1f73c = (uint8_t *)s_EQUALS_00a84f34._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_EQUALS_00a84f34._4_2_);

    cVar8 = s_EQUALS_00a84f34[6];

    goto LAB_007f5c0c;

  case 0xe:

    _DAT_00d1f73c = DAT_00a84f24;

    DAT_00d1f740 = DAT_00a84f28;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xf:

    _DAT_00d1f73c = (uint8_t *)0x424154;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x10:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x51);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x11:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x57);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x12:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x45);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x13:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x52);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x14:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x54);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x15:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x59);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x16:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x55);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x17:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x49);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x18:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x4f);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x19:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x50);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x1a:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x5b);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x1b:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x5d);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x1c:

    _DAT_00d1f73c = (uint8_t *)s_RETURN_00a84f04._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_RETURN_00a84f04._4_2_);

    cVar8 = s_RETURN_00a84f04[6];

    goto LAB_007f5c0c;

  case 0x1d:

  case 0x9d:

    _DAT_00d1f73c = (uint8_t *)s_CONTROL_00a84fb4._0_4_;

    _DAT_00d1f740 = s_CONTROL_00a84fb4._4_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x1e:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x41);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x1f:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,DAT_00a70518);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x20:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,DAT_00a70510);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x21:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x46);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x22:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x47);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x23:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x48);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x24:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x4a);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x25:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x4b);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x26:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x4c);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x27:

    _DAT_00d1f73c = (uint8_t *)s_SEMICOLON_00a84ef8._0_4_;

    _DAT_00d1f740 = s_SEMICOLON_00a84ef8._4_4_;

    _DAT_00d1f744 = s_SEMICOLON_00a84ef8._8_2_;

    _DAT_00d1f744 = CONCAT22(uVar4,_DAT_00d1f744);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x28:

    _DAT_00d1f73c = (uint8_t *)s_APOSTROPHE_00a84eec._0_4_;

    _DAT_00d1f740 = s_APOSTROPHE_00a84eec._4_4_;

    DAT_00d1f746 = s_APOSTROPHE_00a84eec[10];

    _DAT_00d1f744 = s_APOSTROPHE_00a84eec._8_2_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x29:

    _DAT_00d1f73c = (uint8_t *)s_GRAVE_00a84fe8._0_4_;

    _DAT_00d1f740 = s_GRAVE_00a84fe8._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x2a:

  case 0x36:

    _DAT_00d1f73c = (uint8_t *)s_SHIFT_00a84fcc._0_4_;

    _DAT_00d1f740 = s_SHIFT_00a84fcc._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x2b:

    _DAT_00d1f73c = (uint8_t *)s_BACKSLASH_00a84fdc._0_4_;

    _DAT_00d1f740 = s_BACKSLASH_00a84fdc._4_4_;

    _DAT_00d1f744 = s_BACKSLASH_00a84fdc._8_2_;

    _DAT_00d1f744 = CONCAT22(uVar4,_DAT_00d1f744);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x2c:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x5a);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x2d:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x58);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x2e:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x43);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x2f:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x56);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x30:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,DAT_00a7050c);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x31:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,0x4e);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x32:

    _DAT_00d1f73c = (uint8_t *)CONCAT22(uVar2,DAT_00a70514);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x33:

    _DAT_00d1f73c = (uint8_t *)s_COMMA_00a84ee4._0_4_;

    _DAT_00d1f740 = s_COMMA_00a84ee4._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x34:

    _DAT_00d1f73c = (uint8_t *)s_PERIOD_00a85030._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_PERIOD_00a85030._4_2_);

    cVar8 = s_PERIOD_00a85030[6];

    goto LAB_007f5c0c;

  case 0x35:

    _DAT_00d1f73c = (uint8_t *)s_SLASH_00a84ff0._0_4_;

    _DAT_00d1f740 = s_SLASH_00a84ff0._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x37:

    _DAT_00d1f73c = (uint8_t *)s_MULTIPLY_00a85024._0_4_;

    _DAT_00d1f740 = s_MULTIPLY_00a85024._4_4_;

    DAT_00d1f744 = s_MULTIPLY_00a85024[8];

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x38:

  case 0xb8:

    _DAT_00d1f73c = &LAB_00544c41;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x39:

    _DAT_00d1f73c = (uint8_t *)s_SPACE_00a84fd4._0_4_;

    _DAT_00d1f740 = s_SPACE_00a84fd4._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x3a:

    _DAT_00d1f73c = (uint8_t *)s_CAPITAL_00a84edc._0_4_;

    _DAT_00d1f740 = s_CAPITAL_00a84edc._4_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x3b:

    _DAT_00d1f73c = CONCAT12(DAT_00a850d6,DAT_00a850d4);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x3c:

    _DAT_00d1f73c = CONCAT12(DAT_00a850d2,DAT_00a850d0);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x3d:

    _DAT_00d1f73c = CONCAT12(DAT_00a850ce,DAT_00a850cc);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x3e:

    _DAT_00d1f73c = CONCAT12(DAT_00a850ca,DAT_00a850c8);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x3f:

    _DAT_00d1f73c = CONCAT12(DAT_00a850c6,DAT_00a850c4);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x40:

    _DAT_00d1f73c = CONCAT12(DAT_00a850c2,DAT_00a850c0);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x41:

    _DAT_00d1f73c = CONCAT12(DAT_00a850be,DAT_00a850bc);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x42:

    _DAT_00d1f73c = CONCAT12(DAT_00a850ba,DAT_00a850b8);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x43:

    _DAT_00d1f73c = CONCAT12(DAT_00a850b6,DAT_00a850b4);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x44:

    _DAT_00d1f73c = (uint8_t *)0x303146;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x45:

    _DAT_00d1f73c = (uint8_t *)s_NUMLOCK_00a84ed4._0_4_;

    _DAT_00d1f740 = s_NUMLOCK_00a84ed4._4_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x46:

    _DAT_00d1f73c = (uint8_t *)s_SCROLL_00a84ecc._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_SCROLL_00a84ecc._4_2_);

    cVar8 = s_SCROLL_00a84ecc[6];

    goto LAB_007f5c0c;

  case 0x47:

    _DAT_00d1f73c = DAT_00a85068;

    _DAT_00d1f740 = DAT_00a8506c;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x48:

    _DAT_00d1f73c = DAT_00a85060;

    _DAT_00d1f740 = DAT_00a85064;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x49:

    _DAT_00d1f73c = DAT_00a85058;

    _DAT_00d1f740 = DAT_00a8505c;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x4a:

    _DAT_00d1f73c = (uint8_t *)s_SUBTRACT_00a85018._0_4_;

    _DAT_00d1f740 = s_SUBTRACT_00a85018._4_4_;

    DAT_00d1f744 = s_SUBTRACT_00a85018[8];

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x4b:

    _DAT_00d1f73c = DAT_00a85080;

    _DAT_00d1f740 = DAT_00a85084;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x4c:

    _DAT_00d1f73c = DAT_00a85078;

    _DAT_00d1f740 = DAT_00a8507c;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x4d:

    _DAT_00d1f73c = DAT_00a85070;

    _DAT_00d1f740 = DAT_00a85074;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x4e:

    _DAT_00d1f73c = (uint8_t *)0x444441;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x4f:

    _DAT_00d1f73c = (uint8_t *)s_NUMPAD1_00a85098._0_4_;

    _DAT_00d1f740 = s_NUMPAD1_00a85098._4_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x50:

    _DAT_00d1f73c = DAT_00a85090;

    _DAT_00d1f740 = DAT_00a85094;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x51:

    _DAT_00d1f73c = DAT_00a85088;

    _DAT_00d1f740 = DAT_00a8508c;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x52:

    _DAT_00d1f73c = DAT_00a850a0;

    _DAT_00d1f740 = DAT_00a850a4;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x53:

    _DAT_00d1f73c = (uint8_t *)s_DECIMAL_00a8500c._0_4_;

    _DAT_00d1f740 = s_DECIMAL_00a8500c._4_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x57:

    _DAT_00d1f73c = (uint8_t *)0x313146;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x58:

    _DAT_00d1f73c = (uint8_t *)0x323146;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x8d:

    _DAT_00d1f73c = (uint8_t *)s_NUMPADEQUALS_00a84e4c._0_4_;

    _DAT_00d1f740 = s_NUMPADEQUALS_00a84e4c._4_4_;

    _DAT_00d1f744 = s_NUMPADEQUALS_00a84e4c._8_4_;

    DAT_00d1f748 = s_NUMPADEQUALS_00a84e4c[0xc];

    puVar6 = _DAT_00d1f73c;

    break;

  case 0x9c:

    _DAT_00d1f73c = (uint8_t *)s_NUMPADENTER_00a8504c._0_4_;

    _DAT_00d1f740 = s_NUMPADENTER_00a8504c._4_4_;

    _DAT_00d1f744 = s_NUMPADENTER_00a8504c._8_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xb5:

    _DAT_00d1f73c = (uint8_t *)s_DIVIDE_00a85004._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_DIVIDE_00a85004._4_2_);

    cVar8 = s_DIVIDE_00a85004[6];

    goto LAB_007f5c0c;

  case 0xb7:

    _DAT_00d1f73c = (uint8_t *)s_PRINTSCREEN_00a84ff8._0_4_;

    _DAT_00d1f740 = s_PRINTSCREEN_00a84ff8._4_4_;

    _DAT_00d1f744 = s_PRINTSCREEN_00a84ff8._8_4_;

    puVar6 = _DAT_00d1f73c;

    break;

  case 199:

    _DAT_00d1f73c = DAT_00a84f74;

    DAT_00d1f740 = DAT_00a84f78;

    puVar6 = _DAT_00d1f73c;

    break;

  case 200:

    _DAT_00d1f73c = CONCAT12(DAT_00a84eca,DAT_00a84ec8);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xc9:

    _DAT_00d1f73c = DAT_00a84f7c;

    DAT_00d1f740 = DAT_00a84f80;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xcb:

    _DAT_00d1f73c = _DAT_00a84ec0;

    DAT_00d1f740 = DAT_00a84ec4;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xcd:

    _DAT_00d1f73c = (uint8_t *)s_RIGHT_00a84eb8._0_4_;

    _DAT_00d1f740 = s_RIGHT_00a84eb8._4_2_;

    _DAT_00d1f740 = CONCAT22(uVar3,_DAT_00d1f740);

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xcf:

    _DAT_00d1f73c = (uint8_t *)0x444e45;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xd0:

    _DAT_00d1f73c = DAT_00a84eb0;

    DAT_00d1f740 = DAT_00a84eb4;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xd1:

    _DAT_00d1f73c = DAT_00a84f8c;

    _DAT_00d1f740 = CONCAT22(uVar3,DAT_00a84f90);

    cVar8 = DAT_00a84f92;

    goto LAB_007f5c0c;

  case 0xd2:

    _DAT_00d1f73c = (uint8_t *)s_INSERT_00a84f68._0_4_;

    _DAT_00d1f740 = CONCAT22(uVar3,s_INSERT_00a84f68._4_2_);

    cVar8 = s_INSERT_00a84f68[6];

LAB_007f5c0c:

    DAT_00d1f742 = cVar8;

    puVar6 = _DAT_00d1f73c;

    break;

  case 0xd3:

    _DAT_00d1f73c = (uint8_t *)s_DELETE_00a84f5c._0_4_;

    _DAT_00d1f740 = s_DELETE_00a84f5c._4_4_;

    DAT_00d1f744 = s_DELETE_00a84f5c[8];

    puVar6 = _DAT_00d1f73c;

  }

switchD_007f5157_caseD_54:

  _DAT_00d1f73c = puVar6;

  pcVar5 = &DAT_00d1f73c;

  do {

    pcVar10 = pcVar5;

    pcVar5 = pcVar10 + 1;

  } while (*pcVar10 != '\0');

  if (pcVar10 != &DAT_00d1f73c) {

    return &DAT_00d1f73c;

  }

  uVar11 = (ushort)param_2;

  if (uVar11 < 0xf000) {

    return &DAT_00a1419b;

  }

  if (0xf1ff < uVar11) {

    cVar8 = '\0';

    switch(param_2 & 0xf0) {

    case 0:

      cVar8 = 'N';

      break;

    case 0x10:

      cVar8 = 'E';

      break;

    case 0x20:

      cVar8 = 'S';

      break;

    case 0x40:

      cVar8 = 'W';

    }

    _snprintf(&DAT_00d1f0f8,0x104,"Joy_POV%d_%c",(param_2 & 0xf) + 1,(int)cVar8);

    return &DAT_00d1f0f8;

  }

  if (uVar11 < 0xf100) {

    _snprintf(&DAT_00d1f0f8,0x104,"Joy_Button%03d",param_2 & 0xff);

    return &DAT_00d1f0f8;

  }

  uStack_e = 0;

  acStack_c[0] = '\0';

  acStack_c[1] = '\0';

  local_a = 0;

  local_6 = 0;

  bVar7 = (byte)param_2 & 0xf;

  cVar8 = 'X';

  local_10 = 0;

  local_2 = 0;

  if ((param_2 & 0x70) != 0) {

    if ((param_2 & 0x10) == 0) {

      if ((param_2 & 0x20) != 0) {

        local_10 = (uint16_t)s_Slider_00a84e34._0_4_;

        uStack_e = SUB42(s_Slider_00a84e34._0_4_,2);

        acStack_c = (char  [2])s_Slider_00a84e34._4_2_;

        local_a = (uint)(byte)s_Slider_00a84e34[6];

        cVar8 = bVar7 + 0x31;

        goto LAB_007f5d39;

      }

      if ((param_2 & 0x40) == 0) goto LAB_007f5d39;

      local_10 = (uint16_t)s_Force_00a84e2c._0_4_;

      uStack_e = SUB42(s_Force_00a84e2c._0_4_,2);

      acStack_c = (char  [2])s_Force_00a84e2c._4_2_;

    }

    else {

      local_10 = 0x6f52;

      uStack_e = 0x74;

    }

  }

  cVar8 = bVar7 + 0x58;

LAB_007f5d39:

  _snprintf(&DAT_00d1f0f8,0x104,"Joy_Axis%s%c%c",&local_10,(int)cVar8,

            (int)(char)(((param_2 & 0x80) != 0) * '\x02' + '+'));

  return &DAT_00d1f0f8;

}
