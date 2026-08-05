// =============================================================================
// Client_InteractPrompt_SetTarget_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008a81a0
// Address:   0x008a81a0–0x008a856e  (autoassault.exe, image base 0x400000)
// System:    interaction-activation / UI chrome
// Generated: 2026-07-29 W19-I OWN dual A/B seal; supersedes scaffold FUN_008a81a0.cpp
// Exactness: Behavior-preserving rewrite of decompiler + sealed constants.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Classify ESI target and update interact prompt host chrome
//   ("Press <key> to talk/pick up/trade/interact …"). No UseObject send.
//
// ABI: stack formal promptHost*; ESI = target object* (or NULL); RET 4.
// Primary caller: Client_RefreshInteractPromptTarget_Inferred @ 0x009210e0
//                 (host = DAT_00d1b8c8, ESI = picked object).
//
// Dual: reviews/A|B_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md
// =============================================================================

#include <cstdint>
#include <cstdio>

// Globals
extern int  DAT_00d1b6d8;
extern int  DAT_00d1b644;
extern char DAT_00d1be65[];
extern char DAT_00d1c20d[];

// Callees
extern "C" void  FUN_007a69d0(void);
extern "C" char* FUN_007a6de0(const char* s, unsigned n);
extern "C" char  FUN_007f9160(int tipId, int a);
extern "C" char  FUN_008a8140(void); // EAX staged by caller
extern "C" char  __thiscall FUN_005130e0(void* obj, char flag);
extern "C" unsigned __thiscall FUN_00524520(void* character, void* worldObj);
extern "C" void* __RTDynamicCast(void);

// Retail keeps target in ESI across CALL (decompiler unaff_ESI).
// For a free-standing C reconstruction, pass it explicitly as pTarget.
// Call sites must place the same pointer in ESI if hooking retail.

extern "C" void Client_InteractPrompt_SetTarget_Inferred(int* promptHost, int* pTarget /* retail: ESI */)
{
  char cVar1;
  int iVar2, iVar4, iVar6;
  unsigned uVar3, uVar5, uVar9;
  unsigned* puVar7;
  char* _Format;
  char* pcVar8;
  unsigned local_210;
  char local_208[2];
  unsigned local_206[63];
  char local_108[2];
  unsigned local_106[64];

  int* unaff_ESI = pTarget;

  if (unaff_ESI == *reinterpret_cast<int**>(reinterpret_cast<char*>(promptHost) + 0x50c))
    return;
  if (DAT_00d1b6d8 == 0)
    return;
  if (*reinterpret_cast<int*>(reinterpret_cast<char*>(promptHost) + 0x68c) == 0)
    return;

  FUN_007a69d0();

  local_108[0] = 0; local_108[1] = 0;
  puVar7 = local_106;
  for (iVar6 = 0x3f; iVar6 != 0; --iVar6) { *puVar7 = 0; ++puVar7; }
  *reinterpret_cast<std::uint16_t*>(puVar7) = 0;

  local_208[0] = 0; local_208[1] = 0;
  puVar7 = local_206;
  for (iVar6 = 0x3f; iVar6 != 0; --iVar6) { *puVar7 = 0; ++puVar7; }
  *reinterpret_cast<std::uint16_t*>(puVar7) = 0;

  local_210 = 0;

  if (unaff_ESI == nullptr) {
    *reinterpret_cast<int**>(reinterpret_cast<char*>(promptHost) + 0x50c) = nullptr;
    goto LAB_008a854f;
  }

  // cloneBase type token @ +0x38 == 0x12 → talk path
  if (*reinterpret_cast<int*>(unaff_ESI[0x2a] + 0x38) == 0x12) {
    iVar6 = reinterpret_cast<int>(__RTDynamicCast());
    cVar1 = FUN_008a8140();
    if (cVar1 != 0) {
      cVar1 = FUN_007f9160(0xc, 0);
      if (cVar1 == 0) {
        iVar2 = 0;
        do {
          cVar1 = DAT_00d1be65[iVar2];
          reinterpret_cast<char*>(local_206)[iVar2 - 2] = cVar1;
          ++iVar2;
        } while (cVar1 != 0);
      }
      uVar9 = 0xffffffff;
      uVar3 = (**(unsigned(__thiscall**)(int, unsigned))(
          *reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))(
          iVar6, 0xffffffff);
      uVar3 = reinterpret_cast<unsigned>(FUN_007a6de0(reinterpret_cast<char*>(uVar3), uVar9));
      pcVar8 = "to talk to";
LAB_008a8431:
      uVar9 = reinterpret_cast<unsigned>(FUN_007a6de0(pcVar8, 0xffffffff));
      pcVar8 = local_208;
      uVar5 = reinterpret_cast<unsigned>(FUN_007a6de0("Press", 0xffffffff));
      _Format = "%s <%s> %s %s";
      goto LAB_008a84f8;
    }
  } else {
    cVar1 = FUN_005130e0(unaff_ESI, 1);
    if (cVar1 != 0) {
      cVar1 = FUN_007f9160(0xc, 0);
      if (cVar1 == 0) {
        iVar6 = 0;
        do {
          cVar1 = DAT_00d1be65[iVar6];
          reinterpret_cast<char*>(local_206)[iVar6 - 2] = cVar1;
          ++iVar6;
        } while (cVar1 != 0);
      }
      uVar9 = 0xffffffff;
      uVar3 = (**(unsigned(__thiscall**)(int*, unsigned))(*unaff_ESI + 0x15c))(unaff_ESI, 0xffffffff);
      uVar3 = reinterpret_cast<unsigned>(FUN_007a6de0(reinterpret_cast<char*>(uVar3), uVar9));
      pcVar8 = "to pick up";
      goto LAB_008a8431;
    }
    iVar6 = (**(int(__thiscall**)(int*, int))(*unaff_ESI + 0x210))(unaff_ESI, 0);
    if (iVar6 != 0) {
      if (*reinterpret_cast<int*>(DAT_00d1b6d8 + 0x6b4) < 1) {
        iVar6 = (**(int(__thiscall**)(int*, int))(*unaff_ESI + 0x210))(unaff_ESI, 0);
        if (iVar6 != 0)
          iVar6 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar6 + 4) + 4) + 4 + iVar6;
        cVar1 = (**(char(__thiscall**)(int, int))(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +
            0x298))(DAT_00d1b6d8, iVar6);
        if (cVar1 != 0)
          goto LAB_008a8457;
      }
      if (DAT_00d1b644 == 0 || *reinterpret_cast<char*>(DAT_00d1b644 + 0xf6) == 0) {
        iVar4 = (**(int(__thiscall**)(int*, int))(*unaff_ESI + 0x210))(unaff_ESI, 0);
        iVar6 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(DAT_00d1b6d8 + 4) + 4);
        iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar4 + 4) + 4);
        if (*reinterpret_cast<int*>(iVar6 + 0x164 + DAT_00d1b6d8) ==
                *reinterpret_cast<int*>(iVar2 + 0x164 + iVar4) &&
            *reinterpret_cast<int*>(iVar6 + 0x168 + DAT_00d1b6d8) ==
                *reinterpret_cast<int*>(iVar2 + 0x168 + iVar4))
          goto LAB_008a851c;
        cVar1 = FUN_007f9160(0x1e, 0);
        if (cVar1 == 0) {
          iVar6 = 0;
          do {
            cVar1 = DAT_00d1c20d[iVar6];
            reinterpret_cast<char*>(local_206)[iVar6 - 2] = cVar1;
            ++iVar6;
          } while (cVar1 != 0);
        }
        uVar9 = 0;
        iVar6 = (**(int(__thiscall**)(int*, int))(*unaff_ESI + 0x210))(unaff_ESI, 0);
        uVar3 = (**(unsigned(__thiscall**)(int, unsigned))(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))(
            iVar6, 0xffffffff);
        uVar3 = reinterpret_cast<unsigned>(FUN_007a6de0(reinterpret_cast<char*>(uVar3), uVar9));
        pcVar8 = "to trade with";
        goto LAB_008a8431;
      }
    }
LAB_008a8457:
    if (unaff_ESI[0x47] == 0 &&
        (DAT_00d1b6d8 == 0 || FUN_00524520(reinterpret_cast<void*>(DAT_00d1b6d8), unaff_ESI) == 0))
      goto LAB_008a851c;
    cVar1 = FUN_007f9160(0xc, 0);
    if (cVar1 == 0) {
      iVar6 = 0;
      do {
        cVar1 = DAT_00d1be65[iVar6];
        reinterpret_cast<char*>(local_206)[iVar6 - 2] = cVar1;
        ++iVar6;
      } while (cVar1 != 0);
    }
    uVar9 = 0xffffffff;
    uVar3 = (**(unsigned(__thiscall**)(int*, unsigned))(*unaff_ESI + 0x15c))(unaff_ESI, 0xffffffff);
    uVar3 = reinterpret_cast<unsigned>(FUN_007a6de0(reinterpret_cast<char*>(uVar3), uVar9));
    uVar9 = reinterpret_cast<unsigned>(FUN_007a6de0("to interact with", 0xffffffff));
    pcVar8 = local_208;
    uVar5 = reinterpret_cast<unsigned>(FUN_007a6de0("Press", 0xffffffff));
    _Format = FUN_007a6de0("%s <%s> %s %s", 0xffffffff);
LAB_008a84f8:
    std::sprintf(local_108, _Format,
                 reinterpret_cast<char*>(uVar5), pcVar8,
                 reinterpret_cast<char*>(uVar9), reinterpret_cast<char*>(uVar3));
    local_210 = 1;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(promptHost) + 0x50c) = unaff_ESI;
  }

LAB_008a851c:
  {
    int* widget = *reinterpret_cast<int**>(reinterpret_cast<char*>(promptHost) + 0x68c);
    (**(void(__thiscall**)(int*, char*, int, int))(*widget + 0x1d8))(widget, local_108, 1, 1);
    *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(promptHost) + 0x51c) =
        *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(promptHost) + 0x518);
  }
LAB_008a854f:
  {
    int* widget = *reinterpret_cast<int**>(reinterpret_cast<char*>(promptHost) + 0x68c);
    // showFlag, 0.5f
    (**(void(__thiscall**)(int*, unsigned, unsigned))(*widget + 0xfc))(widget, local_210, 0x3f000000u);
  }
}
