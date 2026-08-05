// =============================================================================
// FUN_009284c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009284c0
// Address:   0x009284c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009284c0 @ 0x009284c0
// Stable ID: aa_009284c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: BringWindowToTop, FUN_00928290, FUN_009284c0, FUN_009298c0, FUN_009299d0, GetClientRect, _BinkOpen_8, _BinkSetSoundSystem_8.
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

uint32_t /* width from decompiler */ __fastcall FUN_009284c0(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  float fVar4;

  float fVar5;

  tagRECT tStack_b0;

  int *piStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  int *piStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  int *piStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  int *piStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  int *piStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  

  if ((char)param_1[1] == '\0') {

    uStack_2c = 0;

    uStack_30 = 0x3f800000;

    uStack_34 = 0;

    uStack_38 = 1;

    uStack_3c = 0;

    uStack_40 = 0;

    piStack_44 = DAT_00d17748;

    uStack_48 = 0x9284eb;

    (**(code **)(*DAT_00d17748 + 0xac))();

    uStack_48 = 0;

    uStack_4c = 0;

    uStack_50 = 0;

    uStack_54 = 0;

    piStack_58 = DAT_00d17748;

    uStack_5c = 0x9284fa;

    (**(code **)(*DAT_00d17748 + 0x44))();

    uStack_5c = 0;

    uStack_60 = 0x3f800000;

    uStack_64 = 0;

    uStack_68 = 1;

    uStack_6c = 0;

    uStack_70 = 0;

    piStack_74 = DAT_00d17748;

    uStack_78 = 0x928513;

    (**(code **)(*DAT_00d17748 + 0xac))();

    uStack_78 = 0;

    uStack_7c = 0;

    uStack_80 = 0;

    uStack_84 = 0;

    piStack_88 = DAT_00d17748;

    uStack_8c = 0x928522;

    (**(code **)(*DAT_00d17748 + 0x44))();

    uStack_8c = 0;

    uStack_90 = 0x3f800000;

    uStack_94 = 0;

    uStack_98 = 1;

    uStack_9c = 0;

    piStack_a0 = (int *)0x0;

    tStack_b0.bottom = (LONG)DAT_00d17748;

    tStack_b0.right = 0x92853b;

    (**(code **)(*DAT_00d17748 + 0xac))();

    tStack_b0.right = 0;

    tStack_b0.top = 0;

    tStack_b0.left = 0;

    (**(code **)(*DAT_00d17748 + 0x44))(DAT_00d17748,0);

    (**(code **)(*param_1 + 0x18))();

    (**(code **)(*param_1 + 0x1c))();

    _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,DAT_00d17754);

    iVar2 = FUN_009299d0(param_1[0x44],DAT_00d17748);

    param_1[0x4c] = iVar2;

    if (iVar2 != 0) {

      piStack_a0 = piStack_88;

      _BinkSetSoundTrack_8(1,&piStack_a0);

      piVar3 = (int *)_BinkOpen_8(uStack_8c,0x4000);

      param_1[0x4b] = (int)piVar3;

      uVar1 = DAT_00af9148;

      if (piVar3 != (int *)0x0) {

        param_1[0x4e] = 0;

        param_1[0x45] = *piVar3;

        param_1[0x46] = piVar3[1];

        iVar2 = FUN_009298c0(0,uVar1);

        param_1[0x4d] = iVar2;

        if (iVar2 != 0) {

          GetClientRect((HWND)param_1[0x44],&tStack_b0);

          fVar4 = (float)param_1[0x45] / (float)param_1[0x46];

          fVar5 = (float)tStack_b0.right / (float)tStack_b0.bottom;

          param_1[0x47] = 0;

          param_1[0x48] = 0;

          param_1[0x49] = 0;

          param_1[0x4a] = 0;

          if (fVar4 <= fVar5) {

            if (fVar5 <= fVar4) {

              param_1[0x47] = param_1[0x45];

              param_1[0x48] = param_1[0x46];

            }

            else {

              param_1[0x48] = tStack_b0.bottom;

              iVar2 = (int)((float)tStack_b0.bottom * fVar4);

              param_1[0x47] = iVar2;

              param_1[0x49] = (tStack_b0.right - iVar2) / 2;

            }

          }

          else {

            param_1[0x47] = tStack_b0.right;

            iVar2 = (int)((float)tStack_b0.right / fVar4);

            param_1[0x48] = iVar2;

            param_1[0x4a] = (tStack_b0.bottom - iVar2) / 2;

          }

          BringWindowToTop((HWND)param_1[0x44]);

          FUN_00928290();

          param_1[0x42] = 2;

          return 1;

        }

      }

    }

  }

  return 0;

}
