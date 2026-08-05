// =============================================================================
// FUN_0048a550
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a550
// Address:   0x0048a550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a550 @ 0x0048a550
// Stable ID: aa_0048a550
// Embedded strings (evidence for future rename):
//   - "EffectProc - ENTER\n"
//   - "Effect"
//   - "Zone1"
//   - "Zone2"
//   - "Zone3"
//   - "Zone4"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_0048c470×6, FUN_0056f570×4, CONCAT11, CONCAT13, FUN_0048a410, FUN_0048a550, FUN_0048aec0, FUN_0048af30.
//  - Strings: "EffectProc - ENTER\n"; "Effect"; "Zone1"; "Zone2".
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

uint32_t /* width from decompiler */ FUN_0048a550(void)



{

  int *piVar1;

  int iVar2;

  DWORD DStack_74;

  uint uStack_70;

  uint uStack_6c;

  uint uStack_68;

  uint uStack_64;

  uint8_t uStack_60;

  uint3 uStack_5f;

  uint8_t uStack_5c;

  undefined **ppuStack_58;

  char cStack_2c;

  int iStack_28;

  uint32_t /* width from decompiler */ *puStack_24;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0490;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0056f570("EffectProc - ENTER\n");

  FUN_0048b7c0(&DAT_00b033f0);

  local_4 = 0;

  FUN_0048ca90(0);

  if ((cStack_2c == '\0') || (iStack_28 != 2)) {

    piVar1 = (int *)FUN_0048aec0("Effect");

    if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x18))(), iVar2 != 0)) {

      piVar1 = (int *)FUN_0048af30();

      while ((piVar1 != (int *)0x0 && (DAT_00b034f8 == 0))) {

        uStack_60 = 0;

        _uStack_5f = 0;

        uStack_70 = 0;

        uStack_6c = 0;

        uStack_68 = 0;

        uStack_64 = 0;

        DStack_74 = 0;

        if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x18))(), iVar2 != 0)) {

          FUN_0048c470("Zone1",&uStack_70);

          FUN_0048c470("Zone2",&uStack_6c);

          FUN_0048c470("Zone3",&uStack_68);

          FUN_0048c470("Zone4",&stack0xffffff88);

          FUN_0048c470("Intensity",&uStack_64);

          FUN_0048c470(&DAT_009c6ca0,&DStack_74);

          uStack_60 = (uint8_t)uStack_70;

          _uStack_5f = CONCAT13((uint8_t)uStack_64,

                                (uint3)CONCAT11((uint8_t)uStack_68,(uint8_t)uStack_6c));

          FUN_0056f570("Zone1: %d, Zone2: %d, Zone3: %d, Zone4: %d, Intensity: %d, Time: %d\n",

                       uStack_70 & 0xff,uStack_6c & 0xff,uStack_68 & 0xff,0,uStack_64 & 0xff,

                       DStack_74);

          FUN_0048a410(&uStack_60,DAT_00b034f4,0);

          WaitForSingleObject(DAT_00b034fc,DStack_74);

        }

        piVar1 = (int *)piVar1[10];

      }

    }

  }

  else {

    FUN_0056f570("EffectProc - Error opening file %s\n",&DAT_00b033f0);

  }

  FUN_0056f570("EffectProc - EXIT\n");

  ppuStack_58 = &PTR_FUN_009c6c00;

  puStack_8 = (uint8_t *)0x1;

  if (puStack_24 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puStack_24);

  }

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_0048b3f0();

  ExceptionList = pvStack_10;

  return 0;

}
