// =============================================================================
// FUN_00927fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00927fe0
// Address:   0x00927fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00927fe0 @ 0x00927fe0
// Stable ID: aa_00927fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: goto×5, if×3, while×2, switch×2, return×1.
//  - Notable callees: PeekMessageA×5, DefWindowProcA, FUN_00927e70, FUN_00927fe0, TranslateMessage, _BinkWait_4.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __fastcall FUN_00927fe0(int *param_1)



{

  bool bVar1;

  char cVar2;

  int iVar3;

  tagMSG tStack_1c;

  

  bVar1 = false;

  cVar2 = (**(code **)(*param_1 + 0x2c))();

  while (cVar2 != '\0') {

    iVar3 = PeekMessageA(&tStack_1c,(HWND)param_1[0x44],0,0,0);

    while (iVar3 != 0) {

      TranslateMessage(&tStack_1c);

      if (tStack_1c.message < 0x107) {

        if (tStack_1c.message != 0x106) {

          switch(tStack_1c.message) {

          case 3:

          case 5:

code_r0x009280dc:

            bVar1 = true;

            goto LAB_009280de;

          default:

            goto LAB_0092807e;

          case 0xf:

          case 0x14:

          case 0x100:

            break;

          case 0x101:

            goto code_r0x009280c8;

          }

        }

LAB_00928068:

        PeekMessageA(&tStack_1c,(HWND)param_1[0x44],0,0,1);

      }

      else {

        switch(tStack_1c.message) {

        case 0x201:

        case 0x204:

        case 0x207:

          goto LAB_00928068;

        case 0x202:

        case 0x205:

        case 0x208:

code_r0x009280c8:

          PeekMessageA(&tStack_1c,(HWND)param_1[0x44],0,0,1);

          goto code_r0x009280dc;

        default:

LAB_0092807e:

          PeekMessageA(&tStack_1c,(HWND)param_1[0x44],0,0,1);

          DefWindowProcA((HWND)param_1[0x44],tStack_1c.message,tStack_1c.wParam,tStack_1c.lParam);

        }

      }

      iVar3 = PeekMessageA(&tStack_1c,(HWND)param_1[0x44],0,0,0);

    }

LAB_009280de:

    iVar3 = _BinkWait_4(param_1[0x4b]);

    if (((iVar3 == 0) && (cVar2 = FUN_00927e70(), cVar2 == '\0')) || (bVar1)) break;

    cVar2 = (**(code **)(*param_1 + 0x2c))();

  }

  (**(code **)(*param_1 + 0x18))();

  (**(code **)(*param_1 + 0x1c))();

  return 1;

}
