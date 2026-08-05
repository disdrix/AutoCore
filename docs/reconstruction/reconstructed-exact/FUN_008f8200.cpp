// =============================================================================
// CDlgChatLog_AppendChannelMessage  (Ghidra: FUN_008f8200)
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8200
// Address:   0x008f8200  (autoassault.exe, image base 0x400000)
// System:    chat UI (RequestCast failure toast path among many callers)
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow + asm
//            recoveries for file-log registers and ignore-list thiscall.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Append a styled chat/toast line to CDlgChatLog dual panes, optionally
//   append to chat_log.txt / chat_log_combat.txt, optional profanity filter.
//
// RequestCast path (caller Client_RequestCastSkill @ 0x00941590):
//   FUN_008f8200(DAT_00d1b8dc, 0x18, &DAT_00a156cc /* "!" */, failMsg, 0);
//
// Signature:
//   void (pHost, nChannel, pszStyle, pszText, bGmPrefix)
//
// Sealed strings (this body):
//   chat_log_combat.txt @ 0x00a36c70
//   chat_log.txt        @ 0x00a36c84
//   "%s%s"              @ 0x00a36c94
//   "(GM)"              @ 0x00a36c9c
//
// Dual: reviews/A_aa_008f8200_*, reviews/B_aa_008f8200_*
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" unsigned int DAT_00af9218;
extern "C" char DAT_00a36c9c[];          // "(GM)"
extern "C" char DAT_00a1419b[];          // ""
extern "C" char DAT_00a36c94[];          // "%s%s"
extern "C" char DAT_00a36c84[];          // "chat_log.txt"   (EAX into file log)
extern "C" char DAT_00a36c70[];          // "chat_log_combat.txt"
extern "C" void *DAT_00d1da2c;           // ignore-list object (this for FUN_00573af0)
extern "C" void *DAT_00d1d8c8;
extern "C" char DAT_00d1b225;
extern "C" unsigned short _DAT_00d1775c;
extern "C" void *DAT_00d1b978;

extern "C" int __thiscall FUN_00573af0(void *pIgnoreList, char *pszStyle);
extern "C" void FUN_0079d560(void *ctx, char *text);
extern "C" void FUN_008f6800(int nChannel, char *pszText); // EAX=path, EBX=styleBuf
extern "C" void FUN_0095ab00(char *pszText);               // ESI slot, EDI style
extern "C" void FUN_008f7cf0(int *pPane, int idx, char, char, char, char);
extern "C" void FUN_008f62a0(int *pPane);
extern "C" void FUN_008f6100(int);
extern "C" void *_snprintf(char *, unsigned, const char *, ...);
extern "C" char *strncpy(char *, const char *, unsigned);
extern "C" void *operator_new__(unsigned);
extern "C" void operator_delete__(void *);

void FUN_008f8200(int param_1, int param_2, char *param_3, char *param_4, char param_5)
{
  int *piVar1;
  unsigned char bVar2;
  char cVar3;
  char *puVar4;
  int iVar5;
  char *pcVar6;
  char *_Dest;
  char local_18[20];
  unsigned char local_4;

  // pHost=param_1, nChannel=param_2, pszStyle=param_3, pszText=param_4, bGm=param_5

  if ((param_2 < 0) || (0x18 < param_2)) {
    param_2 = 0;
  }
  if ((DAT_00af9218 & 1 << ((unsigned char)param_2 & 0x1f)) == 0) {
    return;
  }
  local_4 = 0;
  puVar4 = &DAT_00a36c9c[0]; // "(GM)"
  if (param_5 == '\0') {
    puVar4 = &DAT_00a1419b[0]; // ""
  }
  _snprintf(local_18, 0x14, "%s%s", puVar4, param_3);

  // ASM: MOV ECX, [DAT_00d1da2c]; thiscall find style in ignore list
  iVar5 = FUN_00573af0(DAT_00d1da2c, param_3);
  if (iVar5 != 0) {
    return;
  }

  pcVar6 = param_4;
  do {
    cVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  _Dest = (char *)operator_new__((unsigned)(pcVar6 + (1 - (int)(param_4 + 1))));
  strncpy(_Dest, param_4, (unsigned)(pcVar6 + (1 - (int)(param_4 + 1))));

  if ((DAT_00d1d8c8 != 0) && (DAT_00d1b225 != '\0')) {
    FUN_0079d560(DAT_00d1d8c8, _Dest);
  }

  // File-log enable pair in _DAT_00d1775c; decomp CF preserved.
  // ASM recovery into FUN_008f6800:
  //   EAX = (param_2 in [0x10,0x18]) ? chat_log_combat.txt : chat_log.txt
  //   EBX = local_18 (style prefix)
  if (((char)_DAT_00d1775c == '\0') || ((0xf < param_2 && (param_2 < 0x19)))) {
    if ((char)((unsigned short)_DAT_00d1775c >> 8) == '\0') goto LAB_008f82f1;
    if (0xf < param_2) {
      if (param_2 < 0x19) goto LAB_008f82e6;
      goto LAB_008f82f1;
    }
  }
  else {
  LAB_008f82e6:
    FUN_008f6800(param_2, _Dest);
  LAB_008f82f1:
    if ((0xf < param_2) && (param_2 < 0x19)) {
      bVar2 = 1; // host+0x544 combat/special pane
      goto LAB_008f8301;
    }
  }
  bVar2 = 0; // host+0x540 normal pane
LAB_008f8301:
  piVar1 = *(int **)(param_1 + 0x540 + (unsigned)bVar2 * 4);
  if (piVar1 != (int *)0x0) {
    FUN_0095ab00(_Dest);
    // dword indices: +0x51c total, +0x50c last, +0x518 write, +0x500 wrap, +0x508
    piVar1[0x147] = piVar1[0x147] + 1;
    piVar1[0x143] = piVar1[0x146];
    iVar5 = piVar1[0x146] + 1;
    piVar1[0x146] = iVar5;
    if (0x95 < iVar5) { // capacity 0x96
      *(unsigned char *)(piVar1 + 0x140) = 1;
      piVar1[0x146] = 0;
    }
    if ((char)piVar1[0x140] != '\0') {
      piVar1[0x142] = piVar1[0x146];
    }
    cVar3 = (**(char (**)())(*piVar1 + 0x3d8))();
    if (cVar3 != '\0') {
      FUN_008f7cf0(piVar1, piVar1[0x143], 1, 1, 1, 0);
      FUN_008f62a0(piVar1);
      FUN_008f6100(1);
    }
  }

  if ((param_2 == 2) && (DAT_00d1b978 != 0)) {
    pcVar6 = (char *)((char *)DAT_00d1b978 + 0x924);
    do {
      cVar3 = *param_3;
      *pcVar6 = cVar3;
      param_3 = param_3 + 1;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
  }
  operator_delete__(_Dest);
  return;
}
