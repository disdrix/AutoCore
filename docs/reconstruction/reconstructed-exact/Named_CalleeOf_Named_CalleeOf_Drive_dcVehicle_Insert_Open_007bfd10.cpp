// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_007bfd10
// -----------------------------------------------------------------------------
// Stable ID: aa_007bfd10
// Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
// Address:   0x007bfd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_dcVehicle_Insert_Open: drive/input helper. Evidence string: "no name!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "no name!"
//   - "DBReader: %u against %s"
//   - "dcCloneBase_Insert::MoveFirst"
//   - "dcCloneBase_Insert::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×1.
//  - Notable callees: FUN_00422fb0×22, wcscpy×4, FUN_00423170×3, FUN_0041a990×2, FUN_007a4480×2, FUN_0041a3e0, FUN_0041a810, FUN_0041a9b0.
//  - Strings: "no name!"; "DBReader: %u against %s"; "dcCloneBase_Insert::MoveFirst"; "dcCloneBase_Insert::Open".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_007bfd10(char *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint uVar1;

  size_t sVar2;

  int iVar3;

  wchar_t *_Str;

  uint32_t /* width from decompiler */ local_414;

  uint32_t /* width from decompiler */ local_410;

  uint32_t /* width from decompiler */ *local_40c;

  uint32_t /* width from decompiler */ local_408;

  int local_404;

  uint32_t /* width from decompiler */ local_400;

  uint32_t /* width from decompiler */ *local_3fc;

  uint32_t /* width from decompiler */ local_3f8;

  uint32_t /* width from decompiler */ local_3f4;

  uint32_t /* width from decompiler */ local_3f0;

  uint32_t /* width from decompiler */ local_3ec;

  uint32_t /* width from decompiler */ uStack_3e8;

  uint32_t /* width from decompiler */ local_3e4;

  int local_3e0;

  int local_3dc;

  int local_3d8;

  int local_3d4;

  int local_3d0;

  int local_3cc;

  int local_3c8;

  int local_3c4;

  int local_3c0;

  uint32_t /* width from decompiler */ local_3bc;

  int local_3b8;

  int local_3b4;

  int local_3b0;

  int local_3ac;

  int local_3a8;

  int local_3a4;

  int local_3a0;

  wchar_t local_39c [66];

  wchar_t local_318 [66];

  wchar_t local_294 [66];

  wchar_t local_210 [258];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae1a7;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c != '\0') {

    return 0;

  }

  local_3e4 = *param_3;

  local_3bc = param_2[1];

  local_3b0 = (param_2[0xe5] != 1) - 1;

  uVar1 = param_2[2];

  local_3b4 = -(uint)((uVar1 >> 1 & 1) != 0);

  local_3d4 = -(uint)((uVar1 >> 2 & 1) != 0);

  local_3a8 = -(uint)((uVar1 >> 3 & 1) != 0);

  local_3cc = -(uint)((uVar1 >> 4 & 1) != 0);

  local_3ac = -(uint)((uVar1 >> 5 & 1) != 0);

  local_3c4 = -(uint)((uVar1 >> 6 & 1) != 0);

  local_3a0 = -(uint)((uVar1 >> 7 & 1) != 0);

  local_3e0 = -(uint)((uVar1 & 0x100) != 0);

  local_3a4 = -(uint)((uVar1 >> 9 & 1) != 0);

  local_3dc = -(uint)((uVar1 >> 10 & 1) != 0);

  local_3d8 = -(uint)((uVar1 >> 0xb & 1) != 0);

  local_3d0 = -(uint)((uVar1 >> 0xc & 1) != 0);

  local_3c8 = -(uint)((*(byte *)(param_2 + 2) & 1) != 0);

  local_3c0 = (param_2[0xe6] != 1) - 1;

  local_3b8 = (param_2[0xe7] != 1) - 1;

  ExceptionList = &local_c;

  wcscpy(local_294,(wchar_t *)(param_2 + 3));

  _Str = (wchar_t *)((int)param_2 + 0x8e);

  sVar2 = wcslen(_Str);

  if (sVar2 == 0) {

    _Str = L"no name!";

  }

  wcscpy(local_39c,_Str);

  wcscpy(local_210,(wchar_t *)(param_2 + 0x44));

  wcscpy(local_318,(wchar_t *)((int)param_2 + 0x312));

  local_3fc = &local_414;

  local_414 = 0;

  local_410 = 0;

  local_40c = (uint32_t /* width from decompiler */ *)0x0;

  local_408 = 0;

  local_404 = 0;

  local_400 = 0;

  local_3f4 = 0;

  local_3f8 = 0;

  local_3f0 = 0;

  local_3ec = 0;

  local_4 = 0;

  FUN_004230d0(local_3fc,&local_3e4);

  iVar3 = FUN_00422fb0(1,1,4);

  if ((((((-1 < iVar3) && (iVar3 = FUN_00422fb0(1,2,4), -1 < iVar3)) &&

        (iVar3 = FUN_00422fb0(1,3,0x82), -1 < iVar3)) &&

       (((iVar3 = FUN_00422fb0(1,4,0x82), -1 < iVar3 &&

         (iVar3 = FUN_00422fb0(1,5,0x202), -1 < iVar3)) &&

        ((iVar3 = FUN_00422fb0(1,6,2), -1 < iVar3 &&

         ((iVar3 = FUN_00422fb0(1,7,2), -1 < iVar3 && (iVar3 = FUN_00422fb0(1,8,2), -1 < iVar3))))))

       )) && ((iVar3 = FUN_00422fb0(1,9,2), -1 < iVar3 &&

              ((((((iVar3 = FUN_00422fb0(1,10,2), -1 < iVar3 &&

                   (iVar3 = FUN_00422fb0(1,0xb,2), -1 < iVar3)) &&

                  (iVar3 = FUN_00422fb0(1,0xc,2), -1 < iVar3)) &&

                 ((iVar3 = FUN_00422fb0(1,0xd,2), -1 < iVar3 &&

                  (iVar3 = FUN_00422fb0(1,0xe,2), -1 < iVar3)))) &&

                ((iVar3 = FUN_00422fb0(1,0xf,2), -1 < iVar3 &&

                 ((iVar3 = FUN_00422fb0(1,0x10,2), -1 < iVar3 &&

                  (iVar3 = FUN_00422fb0(1,0x11,2), -1 < iVar3)))))) &&

               (iVar3 = FUN_00422fb0(1,0x12,2), -1 < iVar3)))))) &&

     ((((iVar3 = FUN_00422fb0(1,0x13,2), -1 < iVar3 &&

        (iVar3 = FUN_00422fb0(1,0x14,0x82), -1 < iVar3)) &&

       (iVar3 = FUN_00422fb0(1,0x15,2), -1 < iVar3)) && (iVar3 = FUN_00422fb0(1,0x16,2), -1 < iVar3)

      ))) {

    iVar3 = FUN_0041a810(&local_414,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

  }

  local_40c = &uStack_3e8;

  if ((-1 < iVar3) && (iVar3 = FUN_004231d0(&local_414,1,4), -1 < iVar3)) {

    if (local_404 != 0) {

      iVar3 = FUN_0041a9b0();

      if (iVar3 == 0) {

        *param_3 = uStack_3e8;

        *param_2 = uStack_3e8;

        FUN_0041a990();

        FUN_00423170();

      }

      else {

        FUN_0041a990();

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar3,"dcCloneBase_Insert::MoveFirst");

      }

      goto LAB_007c0314;

    }

    iVar3 = -0x7fffbffb;

  }

  FUN_00423170();

  FUN_007a4480(1,"DBReader: %u against %s",iVar3,"dcCloneBase_Insert::Open");

LAB_007c0314:

  local_4 = 0xffffffff;

  FUN_0041a3e0(&local_414);

  ExceptionList = local_c;

  return 0;

}
