// READABILITY (auto CF):
//  - Body size: ~329 non-empty decompiler lines.
//  - Control keywords: if×30, goto×4, return×2, do×2, while×2.
//  - Notable callees: _wcsicmp×27, c_str×14, wcslen×9, block×4, FUN_004a1d80, FUN_004a1f20, _snwscanf.
//  - Strings: "flags"; "NX_CLF_PRESSURE"; "NX_CLF_STATIC"; "NX_CLF_DISABLE_COLLISION".
//  - Return sites: 2.

// =============================================================================
// Named_attachmentResponseCoefficient_004a1f20
// -----------------------------------------------------------------------------
// Stable ID: aa_004a1f20
// Address:   0x004a1f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "attachmentResponseCoefficient"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x004a2382) */

/* WARNING: Removing unreachable block (ram,0x004a238a) */

/* WARNING: Removing unreachable block (ram,0x004a2390) */

/* WARNING: Removing unreachable block (ram,0x004a239f) */



uint32_t /* width from decompiler */ Named_attachmentResponseCoefficient_004a1f20(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  wchar_t *pwVar6;

  size_t _MaxCount;

  int *unaff_EBP;

  int *unaff_ESI;

  wchar_t *unaff_EDI;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *this;

  wchar_t *pwVar7;

  int iStack_38;

  int *piStack_34;

  int local_24 [2];

  uint32_t /* width from decompiler */ uStack_1c;

  wchar_t *pwStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uVar1 = DAT_00a0f718;

  fVar3 = g_flOne;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a108f;

  local_c = ExceptionList;

  if (((*(byte *)(param_1 + 0x90c) & 0x80) != 0) || ((*(byte *)(param_1 + 0x90d) & 1) != 0)) {

    return 0;

  }

  ExceptionList = &local_c;

  *(byte *)(param_1 + 0x90d) = *(byte *)(param_1 + 0x90d) | 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  *(float *)(param_1 + 0xe8) = fVar3;

  *(float *)(param_1 + 0xf8) = fVar3;

  *(float *)(param_1 + 0x108) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  *(float *)(param_1 + 0x11c) = fVar3;

  *(float *)(param_1 + 0x120) = fVar3;

  *(float *)(param_1 + 0x124) = fVar3;

  *(float *)(param_1 + 0x130) = fVar3;

  uVar2 = DAT_00aaa68c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x134) = DAT_00aaa68c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x140) = uVar2;

  uVar4 = DAT_00a0f70c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = uVar1;

  uVar2 = DAT_00a0f298;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = uVar4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x138) = uVar4;

  uVar1 = DAT_009c7b84;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 300) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0) = 0x20;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = 5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = 0;

  *(uint16_t *)(param_1 + 0x19c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x168) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

  piStack_34 = local_24;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0) = 0;

  local_24[0] = 0;

  (**(code **)(*param_2 + 0x34))();

  do {

    if (unaff_ESI == (int *)0x0) {

      ExceptionList = pwStack_14;

      return 1;

    }

    uStack_4 = 0;

    (**(code **)(*unaff_ESI + 0xa4))(unaff_ESI,&stack0xffffffd0);

    (**(code **)(*piStack_34 + 0x68))(piStack_34,&local_c);

    iVar5 = _wcsicmp(unaff_EDI,L"flags");

    if (iVar5 == 0) {

      uStack_1c = 0;

      iStack_38 = FUN_004a1d80(&piStack_34);

      if (0 < iStack_38) {

        this = (basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                *)0x0;

        do {

          pwVar7 = L"NX_CLF_PRESSURE";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 1;

          }

          pwVar7 = L"NX_CLF_STATIC";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 2;

          }

          pwVar7 = L"NX_CLF_DISABLE_COLLISION";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 4;

          }

          pwVar7 = L"NX_CLF_SELFCOLLISION";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 8;

          }

          pwVar7 = L"NX_CLF_VISUALIZATION";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 0x10;

          }

          pwVar7 = L"NX_CLF_GRAVITY";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 0x20;

          }

          pwVar7 = L"NX_CLF_BENDING";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) | 0x40;

          }

          pwVar7 = L"NX_CLF_BENDING_ORTHO";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b0) = *(byte *)(param_1 + 0x1b0) | 0x80;

          }

          pwVar7 = L"NX_CLF_DAMPING";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b1) = *(byte *)(param_1 + 0x1b1) | 1;

          }

          pwVar7 = L"NX_CLF_COLLISION_TWOWAY";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b1) = *(byte *)(param_1 + 0x1b1) | 2;

          }

          pwVar7 = L"NX_CLF_TRIANGLE_COLLISION";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b1) = *(byte *)(param_1 + 0x1b1) | 8;

          }

          pwVar7 = L"NX_CLF_TEARABLE";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b1) = *(byte *)(param_1 + 0x1b1) | 0x10;

          }

          pwVar7 = L"NX_CLF_HARDWARE";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b1) = *(byte *)(param_1 + 0x1b1) | 0x20;

          }

          pwVar7 = L"NX_CLF_COMDAMPING";

          pwVar6 = std::

                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   ::c_str(this);

          iVar5 = _wcsicmp(pwVar6,pwVar7);

          if (iVar5 == 0) {

            *(byte *)(param_1 + 0x1b1) = *(byte *)(param_1 + 0x1b1) | 0x40;

          }

          this = this + 0x1c;

          iStack_38 = iStack_38 + -1;

        } while (iStack_38 != 0);

      }

      uStack_1c = 0xffffffff;

      unaff_ESI = (int *)0x0;

    }

    else {

      iVar5 = _wcsicmp(unaff_EDI,L"thickness");

      if (iVar5 == 0) {

        iVar5 = param_1 + 0x118;

        pwVar6 = L"%f";

        _MaxCount = wcslen(pwStack_14);

      }

      else {

        iVar5 = _wcsicmp(unaff_EDI,L"density");

        if (iVar5 == 0) {

          iVar5 = param_1 + 0x11c;

          pwVar6 = L"%f";

          _MaxCount = wcslen(pwStack_14);

        }

        else {

          iVar5 = _wcsicmp(unaff_EDI,L"bendingStiffness");

          if (iVar5 == 0) {

            iVar5 = param_1 + 0x120;

            pwVar6 = L"%f";

            goto LAB_004a2604;

          }

          iVar5 = _wcsicmp(unaff_EDI,L"stretchingStiffness");

          if (iVar5 == 0) {

            iVar5 = param_1 + 0x124;

            pwVar6 = L"%f";

            _MaxCount = wcslen(pwStack_14);

          }

          else {

            iVar5 = _wcsicmp(unaff_EDI,L"dampingCoefficient");

            if (iVar5 == 0) {

              iVar5 = param_1 + 0x128;

              pwVar6 = L"%f";

              _MaxCount = wcslen(pwStack_14);

            }

            else {

              iVar5 = _wcsicmp(unaff_EDI,L"friction");

              if (iVar5 == 0) {

                iVar5 = param_1 + 300;

                pwVar6 = L"%f";

                goto LAB_004a2604;

              }

              iVar5 = _wcsicmp(unaff_EDI,L"pressure");

              if (iVar5 == 0) {

                iVar5 = param_1 + 0x130;

                pwVar6 = L"%f";

                _MaxCount = wcslen(pwStack_14);

              }

              else {

                iVar5 = _wcsicmp(unaff_EDI,L"tearFactor");

                if (iVar5 == 0) {

                  iVar5 = param_1 + 0x134;

                  pwVar6 = L"%f";

                  _MaxCount = wcslen(pwStack_14);

                }

                else {

                  iVar5 = _wcsicmp(unaff_EDI,L"collisionResponseCoefficient");

                  if (iVar5 == 0) {

                    iVar5 = param_1 + 0x138;

                    pwVar6 = L"%f";

LAB_004a2604:

                    _MaxCount = wcslen(pwStack_14);

                  }

                  else {

                    iVar5 = _wcsicmp(unaff_EDI,L"attachmentResponseCoefficient");

                    if (iVar5 == 0) {

                      iVar5 = param_1 + 0x13c;

                      pwVar6 = L"%f";

                      _MaxCount = wcslen(pwStack_14);

                    }

                    else {

                      iVar5 = _wcsicmp(unaff_EDI,L"attachmentTearFactor");

                      if (iVar5 != 0) {

                        iVar5 = _wcsicmp(unaff_EDI,L"solverIterations");

                        if (iVar5 != 0) goto LAB_004a2621;

                        iVar5 = param_1 + 0x144;

                        pwVar6 = L"%d";

                        goto LAB_004a2604;

                      }

                      iVar5 = param_1 + 0x140;

                      pwVar6 = L"%f";

                      _MaxCount = wcslen(pwStack_14);

                    }

                  }

                }

              }

            }

          }

        }

      }

      _snwscanf(pwStack_14,_MaxCount,pwVar6,iVar5);

    }

LAB_004a2621:

    (**(code **)(*unaff_EBP + 0x40))(unaff_EBP,&stack0xffffffc4);

  } while( true );

}
