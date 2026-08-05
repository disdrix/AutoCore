// =============================================================================
// CVOGFXGeometry_particle_already_gfxBody_tried_ch
// -----------------------------------------------------------------------------
// Stable ID: aa_0058f780
// Address:   0x0058f780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CVOGFXGeometry_particle_already_gfxBody_tried_ch @ 0x0058f780
// Stable ID: aa_0058f780
// Embedded strings (evidence for future rename):
//   - "CVOGFXGeometry particle already has a gfxBody <%s>, tried changing it to <%s>"
//   - "Point"
//   - "Color"
//   - "Range"
//   - "Atten1"
//   - "Atten2"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~201 non-empty decompiler lines.
//  - Control keywords: if×15, do×3, while×3, return×2, for×2.
//  - Notable callees: FUN_00764030×2, FUN_009733d0×2, FUN_00989e00×2, CVOGFXGeometry_particle_already_gfxBody_tried_ch, FUN_007a4480, FUN_00969160, FUN_0096a630, FUN_0096e430.
//  - Strings: "Point"; "Color"; "Range"; "Atten1".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGFXGeometry particle already has a gfxBody <%s>, tried changing it to <%s>"
 * Domain alias of FUN_0058f780 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall CVOGFXGeometry_particle_already_gfxBody_tried_ch(int param_1,char *param_2)



{

  char cVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  int iVar5;

  int *piVar6;

  uint8_t *puVar7;

  void *pvVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uVar10;

  char *pcVar11;

  int *piVar12;

  char *pcVar13;

  uint32_t /* width from decompiler */ *local_160;

  float fStack_15c;

  float fStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  float fStack_150;

  float fStack_14c;

  float fStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_13c [43];

  char cStack_111;

  char local_110 [256];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5863;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x914) != 0) {

    ExceptionList = &local_c;

    this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

           FUN_0096a630(local_13c);

    local_4 = 0;

    pcVar2 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             c_str(this);

    FUN_007a4480(0xffffffff,

                 "CVOGFXGeometry particle already has a gfxBody <%s>, tried changing it to <%s>",

                 pcVar2,param_2);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_13c);

    ExceptionList = local_c;

    return 1;

  }

  if ((*(byte *)(param_1 + 0x90d) & 1) == 0) {

    ExceptionList = &local_c;

    local_160 = operator_new(0x14c);

    local_4 = 2;

    if (local_160 == (uint32_t /* width from decompiler */ *)0x0) {

      uVar9 = 0;

    }

    else {

      uVar9 = FUN_00764030();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x914) = uVar9;

  }

  else {

    ExceptionList = &local_c;

    puVar3 = operator_new(0x14c);

    local_4 = 1;

    local_160 = puVar3;

    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x914) = 0;

    }

    else {

      FUN_00764030();

      *puVar3 = &PTR_FUN_009d51e4;

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x914) = puVar3;

    }

  }

  local_4 = 0xffffffff;

  *(uint8_t *)(DAT_00d1f048 + 0xe) = 1;

  if (param_2 == (char *)0x0) {

    FUN_00989e00(&local_160,param_1 + 0x33d);

    iVar5 = (**(code **)(**(int **)(param_1 + 0x914) + 0x5c))(&local_160);

  }

  else {

    iVar5 = -(int)param_2;

    do {

      cVar1 = *param_2;

      param_2[(int)(local_110 + iVar5)] = cVar1;

      param_2 = param_2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = (char *)(param_1 + 0x33d);

    pcVar4 = pcVar2;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar13 = &cStack_111;

    do {

      pcVar11 = pcVar13 + 1;

      pcVar13 = pcVar13 + 1;

    } while (*pcVar11 != '\0');

    pcVar11 = pcVar2;

    for (uVar10 = (uint)((int)pcVar4 - (int)pcVar2) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar13 = *(uint32_t /* width from decompiler */ *)pcVar11;

      pcVar11 = pcVar11 + 4;

      pcVar13 = pcVar13 + 4;

    }

    for (uVar10 = (int)pcVar4 - (int)pcVar2 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

      *pcVar13 = *pcVar11;

      pcVar11 = pcVar11 + 1;

      pcVar13 = pcVar13 + 1;

    }

    FUN_00989e00(&local_160,local_110);

    iVar5 = (**(code **)(**(int **)(param_1 + 0x914) + 0x5c))(&local_160);

  }

  *(uint8_t *)(DAT_00d1f048 + 0xe) = 0;

  if (iVar5 < 0) {

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x914) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x914))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x914) = 0;

    uVar9 = 0;

  }

  else {

    if ((*(byte *)(param_1 + 0x90d) & 1) != 0) {

      iVar5 = (int)*(short *)(param_1 + 700);

      piVar6 = operator_new__(iVar5 * 0xc0 + 0x10);

      puStack_8 = (uint8_t *)0x3;

      if (piVar6 == (int *)0x0) {

        piVar12 = (int *)0x0;

      }

      else {

        piVar12 = piVar6 + 4;

        *piVar6 = iVar5;

        _eh_vector_constructor_iterator_(piVar12,0xc0,iVar5,FUN_00972cc0,FUN_0056f570);

      }

      puStack_8 = (uint8_t *)0xffffffff;

      FUN_00969160((int)*(short *)(param_1 + 700),piVar12);

      if (piVar12 != (int *)0x0) {

        _eh_vector_destructor_iterator_(piVar12,0xc0,piVar12[-4],FUN_0056f570);

        operator_delete__(piVar12 + -4);

      }

    }

    iVar5 = (**(code **)(**(int **)(param_1 + 0x914) + 0x48))();

    if (((*(float *)(iVar5 + 0xc) < DAT_00a0f718) && ((*(byte *)(param_1 + 0x90c) & 0x80) == 0)) &&

       ((*(byte *)(param_1 + 0x90d) & 1) == 0)) {

      *(uint8_t *)(param_1 + 0x795) = 1;

    }

    puVar7 = operator_new(0xc);

    *puVar7 = 9;

    *(int *)(puVar7 + 4) = param_1;

    *(uint8_t **)(*(int *)(param_1 + 0x914) + 0x78) = puVar7;

    iVar5 = *(int *)(*(int *)(param_1 + 0x914) + 0xc0);

    if ((iVar5 != 0) && (0 < *(int *)(*(int *)(param_1 + 0x914) + 0xc4) - iVar5 >> 2)) {

      FUN_0096fdf0();

    }

    if ((*(byte *)(param_1 + 0x90f) & 2) != 0) {

      pvVar8 = operator_new(0x94);

      puStack_8 = (uint8_t *)0x4;

      if (pvVar8 == (void *)0x0) {

        uVar9 = 0;

      }

      else {

        uVar9 = FUN_0096e4b0();

      }

      puStack_8 = (uint8_t *)0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x91c) = uVar9;

      FUN_0096e430("Point");

      iVar5 = *(int *)(*(int *)(param_1 + 0x914) + 0xa4);

      if ((iVar5 == 0) || (*(int *)(*(int *)(param_1 + 0x914) + 0xa8) - iVar5 >> 2 == 0)) {

        *(byte *)(param_1 + 0x90f) = *(byte *)(param_1 + 0x90f) | 0x40;

      }

      else {

        *(byte *)(param_1 + 0x90f) = *(byte *)(param_1 + 0x90f) & 0xbf;

      }

      (**(code **)(**(int **)(param_1 + 0x91c) + 0x34))();

      FUN_009733d0(param_1 + 0x8e0);

      FUN_009733d0(param_1 + 0x8e0);

      iVar5 = *(int *)(param_1 + 0x91c);

      local_160 = (uint32_t /* width from decompiler */ *)(fStack_150 * g_flLevelUpUiBase_Inferred);

      fStack_15c = fStack_14c * g_flLevelUpUiBase_Inferred;

      fStack_158 = fStack_148 * g_flLevelUpUiBase_Inferred;

      uStack_154 = uStack_144;

      uVar9 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("Color");

      (**(code **)(**(int **)(iVar5 + 0x8c) + 0x4c))(uVar9,&stack0xfffffe9c);

      iVar5 = *(int *)(param_1 + 0x91c);

      uVar9 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("Range");

      (**(code **)(**(int **)(iVar5 + 0x8c) + 0x48))(uVar9,param_1 + 0x8f0);

      iVar5 = *(int *)(param_1 + 0x91c);

      uVar9 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("Atten1");

      (**(code **)(**(int **)(iVar5 + 0x8c) + 0x48))(uVar9,param_1 + 0x8f8);

      iVar5 = *(int *)(param_1 + 0x91c);

      uVar9 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("Atten2");

      (**(code **)(**(int **)(iVar5 + 0x8c) + 0x48))(uVar9,param_1 + 0x8fc);

      (**(code **)(**(int **)(param_1 + 0x91c) + 0x50))();

    }

    *(byte *)(param_1 + 0x90e) = *(byte *)(param_1 + 0x90e) | 4;

    uVar9 = 1;

  }

  ExceptionList = pvStack_10;

  return uVar9;

}
