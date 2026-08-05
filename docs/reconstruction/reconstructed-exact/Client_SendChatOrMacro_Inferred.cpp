// =============================================================================
// Client_SendChatOrMacro_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00941fb0
// Address:   0x00941fb0  (autoassault.exe, image base 0x400000)
// System:    chat / sector-broadcast
// Generated: 2026-07-29 dual A/B seal (from raw + live decompile/read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   C2S chat/macro send. Builds either:
//     - Sector Broadcast opcode 0x2021, size = msgLen + 0x29  → Client_SendSectorPacket
//     - Global Chat     opcode 0x8000, size = msgLen + 0x31  → FUN_008073b0
//   Selected by ChatType (param_4) and convoy flag for type 3.
//
// ABI (sealed):
//   ECX = recipientName (char*)   — 17-byte private/target name field
//   EDX = message (char*)         — required non-null, non-empty
//   [ebp+8]  = client*
//   [ebp+0xc]= chatType (int)
//   [ebp+0x10]= doFilters (char)
//   ret 0x0C
//
// SEALED 2026-07-29:
//   - imm 0x2021 / 0x8000, sizes +0x29 / +0x31
//   - type groups; channel mask DAT_00af9218
//   - sector layout (Sender[17] unwritten); coid from char+0x164/168
//
// Ghidra alias: FUN_00941fb0
// =============================================================================

extern "C" int  FUN_0093bd10(void *client, void *globalPkt);
extern "C" void FUN_00865970();
extern "C" char FUN_00807370();
extern "C" int  FUN_008073b0(short size, void *buffer);
extern "C" char FUN_00807440();
extern "C" int  Client_SendSectorPacket(void *client, short size, void *buffer);
extern "C" void FUN_007a75e0();
extern "C" void FUN_008f8200(int a, int b, char *name, void *buf, int e);
extern "C" unsigned DAT_00af9218;
extern "C" int    DAT_00d1b8dc;
extern "C" char   s_DEBUG_00a28b7c[];

#include <cstring>
#include <windows.h>

int __fastcall Client_SendChatOrMacro_Inferred(
    char *recipientName,
    char *message,
    void *client,
    int chatType,
    char doFilters)
{
  int prefilterResult;
  char c;
  short msgLen;
  char *p;
  char *nameSrc;
  int character;
  DWORD tick;
  int miAdj;
  int miBase;
  unsigned *zeroWalk;
  int i;

  // Local packet workspaces (frame layout mirrors decompiler locals).
  int unused_c38;
  char nameScratch[20];          // local_c34 / local_c30 — character display name
  // Global Chat 0x8000 packet (uStack_c20 base):
  unsigned globalPkt_opcode;     // +0x00 = 0x8000
  int globalPkt_chatType;        // +0x04
  unsigned char globalPkt_isGM;  // +0x08
  char globalPkt_recipient[17];  // +0x09
  char globalPkt_sender[18];     // +0x1A (17 used + room)
  unsigned globalPkt_lenAndMsg;  // +0x2C length short; message at +0x2E via overlay
  char globalMsgOverlay[1002];   // message body for global (strncpy target conceptually)

  // Sector Broadcast 0x2021 packet (local_808 base):
  unsigned sector_opcode;        // +0x00 = 0x2021
  int sector_chatType;           // +0x04
  unsigned sector_coidLo;        // +0x08
  unsigned sector_coidHi;        // +0x0c
  unsigned char sector_isGM;     // +0x10
  unsigned sector_lenField;      // +0x12 MessageLength (low 16)
  char sector_message[1003];     // +0x25 message (Sender[17] at +0x14 unwritten)

  unsigned short pmUiPad;
  unsigned pmUiBuf[252];

  (void)globalMsgOverlay;
  (void)unused_c38;

  if (message == nullptr) {
    return (int)0x80070057;
  }

  prefilterResult = 0;
  p = message;
  do {
    c = *p;
    p = p + 1;
  } while (c != '\0');
  if ((int)(p - (message + 1)) <= 0) {
    return (int)0x80070057;
  }

  if ((DAT_00af9218 & (1u << (chatType & 0x1f))) == 0) {
    return 0;
  }

  character = *(int *)((char *)client + 0xe98);
  if (character == 0) {
    // "DEBUG"
    nameScratch[0] = s_DEBUG_00a28b7c[0];
    nameScratch[1] = s_DEBUG_00a28b7c[1];
    nameScratch[2] = s_DEBUG_00a28b7c[2];
    nameScratch[3] = s_DEBUG_00a28b7c[3];
    nameScratch[4] = s_DEBUG_00a28b7c[4];
    nameScratch[5] = '\0';
  } else {
    // multi-inherit this-adjust then vtbl+0x160 name getter
    miBase = *(int *)(*(int *)(character + 4) + 4);
    nameSrc = (char *)(**(int (**)())(
        *(int *)(miBase + 4 + character) + 0x160))();
    p = nameScratch;
    do {
      c = *nameSrc;
      *p = c;
      nameSrc = nameSrc + 1;
      p = p + 1;
    } while (c != '\0');
  }

  sector_coidLo = 0xffffffffu;
  sector_coidHi = 0xffffffffu;
  sector_lenField = (sector_lenField & 0xff000000u);
  sector_message[0] = '\0';
  sector_isGM = 0;
  sector_opcode = 0x2021;
  sector_chatType = 5; // seed only; overwritten on sector arms

  globalPkt_sender[0] = '\0';
  globalPkt_lenAndMsg = (globalPkt_lenAndMsg & 0xff000000u);
  globalPkt_recipient[0] = '\0';
  globalPkt_isGM = 0;
  globalPkt_opcode = 0x8000;
  globalPkt_chatType = chatType;

  // Message into global packet message area (decomp: strncpy to &uStack_bf4+2).
  std::strncpy(reinterpret_cast<char *>(&globalPkt_lenAndMsg) + 2, message, 1000);

  // Recipient name (ECX) → global recipient[17].
  {
    char *src = recipientName;
    char *dst = globalPkt_recipient;
    do {
      c = *src;
      *dst = c;
      src = src + 1;
      dst = dst + 1;
    } while (c != '\0');
  }

  // Character name → global sender.
  i = 0;
  do {
    c = nameScratch[i];
    globalPkt_sender[i] = c;
    i = i + 1;
  } while (c != '\0');

  // strlen(message) into MessageLength.
  p = reinterpret_cast<char *>(&globalPkt_lenAndMsg) + 2;
  do {
    c = *p;
    p = p + 1;
  } while (c != '\0');
  msgLen = (short)(p - (reinterpret_cast<char *>(&globalPkt_lenAndMsg) + 3));
  globalPkt_lenAndMsg = (globalPkt_lenAndMsg & 0xffff0000u) | (unsigned short)msgLen;

  if (doFilters != '\0') {
    prefilterResult = FUN_0093bd10(client, &globalPkt_opcode);
    msgLen = (short)globalPkt_lenAndMsg;
  }

  if (msgLen <= 0) {
    return (int)0x80070057;
  }

  if (doFilters != '\0') {
    FUN_00865970();
    msgLen = (short)globalPkt_lenAndMsg;
  }

  if (prefilterResult != 0) {
    return prefilterResult;
  }

  switch (globalPkt_chatType) {
  case 1:
  case 2:
  case 4:
  case 0xd:
  case 0xe:
  case 0xf:
    if ((globalPkt_chatType == 2) && (doFilters != '\0')) {
      pmUiPad = 0;
      zeroWalk = pmUiBuf;
      for (i = 0xf9; i != 0; i = i + -1) {
        *zeroWalk = 0;
        zeroWalk = zeroWalk + 1;
      }
      *(unsigned short *)zeroWalk = 0;
      FUN_007a75e0();
      if (DAT_00d1b8dc != 0) {
        FUN_008f8200(DAT_00d1b8dc, 7, globalPkt_recipient, &pmUiPad, 0);
      }
    }
    c = FUN_00807370();
    if (c != '\0') {
      return FUN_008073b0((short)(msgLen + 0x31), &globalPkt_opcode);
    }
    break;

  case 3:
    character = *(int *)((char *)client + 0xe98);
    miBase = *(int *)(*(int *)(character + 4) + 4);
    miAdj = miBase + character;
    if (*(char *)(*(int *)(miBase + 0xa8 + character) + 0xf6) == '\0') {
      c = FUN_00807440();
      if (c != '\0') {
        return FUN_008073b0((short)(msgLen + 0x31), &globalPkt_opcode);
      }
    } else {
      if (character == 0) {
        sector_coidLo = 0xffffffffu;
        sector_coidHi = 0xffffffffu;
      } else {
        sector_coidLo = *(unsigned *)(miAdj + 0x164);
        sector_coidHi = *(unsigned *)(miAdj + 0x168);
      }
      sector_chatType = globalPkt_chatType;
      sector_lenField = (sector_lenField & 0xffff0000u) | (unsigned short)msgLen;
      i = 0;
      do {
        c = *(reinterpret_cast<char *>(&globalPkt_lenAndMsg) + i + 2);
        sector_message[i] = c;
        i = i + 1;
      } while (c != '\0');
      c = FUN_00807440();
      if (c != '\0') {
        return Client_SendSectorPacket(
            client, (short)((short)sector_lenField + 0x29), &sector_opcode);
      }
    }
    break;

  case 5:
  case 8:
  case 9:
  case 10:
    character = *(int *)((char *)client + 0xe98);
    if (character == 0) {
      sector_coidLo = 0xffffffffu;
      sector_coidHi = 0xffffffffu;
    } else {
      miBase = *(int *)(*(int *)(character + 4) + 4);
      sector_coidLo = *(unsigned *)(miBase + 0x164 + character);
      sector_coidHi = *(unsigned *)(miBase + 0x168 + character);
    }
    sector_chatType = globalPkt_chatType;
    sector_lenField = (sector_lenField & 0xffff0000u) | (unsigned short)msgLen;
    i = 0;
    do {
      c = *(reinterpret_cast<char *>(&globalPkt_lenAndMsg) + i + 2);
      sector_message[i] = c;
      i = i + 1;
    } while (c != '\0');
    tick = GetTickCount();
    *(DWORD *)((char *)client + 0x30e8) = tick;
    *(int *)((char *)client + 0x30ec) = (int)msgLen;
    c = FUN_00807440();
    if (c != '\0') {
      return Client_SendSectorPacket(
          client, (short)((short)sector_lenField + 0x29), &sector_opcode);
    }
    break;

  default:
    break;
  }

  return 1;
}
