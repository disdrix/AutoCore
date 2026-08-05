// =============================================================================
// Client_SendItemPickup
// -----------------------------------------------------------------------------
// Stable ID: aa_00925580
// Address:   0x00925580  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / interaction-activation (special gather C2S)
// Generated: 2026-07-29 dual A/B seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   C2S ItemPickup (opcode 0x2055, size 0x30). Custom ABI: ESI = pointer to
//   gather TFID pair (two dwords from FUN_0058cd60-family). Gates on inventory
//   busy, character empty-select pair, dead/UI vtbls; packs opcode + TFID lo/hi
//   + zeros + g_flMsToSeconds float; Client_SendSectorPacket(&DAT_00d1a840,
//   0x30, pkt) with EAX=8 (Ordered).
//
// CALLERS (3):
//   Client_Input_PollBoundActions @ 0x0092794c  (Activate exclusive 20f gather)
//   FUN_00925670                  @ 0x00925707  (~100 ms auto gather)
//   FUN_00925820                  @ 0x00925be3  (interact hub; clears select)
//
// SEALED: opcode 0x2055, size 0x30, ESI ABI, layout, 3 callers.
// =============================================================================

#include <cstdint>

extern char  DAT_00d1b4b0;
extern int*  DAT_00d1b6d8;
extern int*  DAT_00d1b958;
extern int*  DAT_00d1b95c;
extern char  DAT_00d1a840;
extern float g_flMsToSeconds_Inferred; // VA 0x00a0f72c → 0.001f

extern uint32_t __thiscall Client_SendSectorPacket(void* self, int16_t size, void* buffer);

// Register convention (not expressible in MSVC prototype): ESI = tfidPair*.
// All three call sites: LEA ESI, <pair>; CALL 0x00925580.
void Client_SendItemPickup(void)
{
  uint32_t* unaff_ESI; // ESI — set by caller
  char cVar1;
  uint32_t auStack_30[2];
  uint32_t uStack_28;
  uint32_t uStack_24;
  uint32_t uStack_20;
  uint32_t uStack_1c;
  uint32_t uStack_18;
  uint32_t uStack_14;
  uint32_t uStack_10;
  uint32_t uStack_c;
  float fStack_8;
  // Frame is 0x30; trailing 4 B after fStack_8 unwritten within send size.

  if (DAT_00d1b4b0 != '\0')
    return;
  if (*(int*)((char*)DAT_00d1b6d8 + 0xcd0) != 0)
    return;
  if ((*(uint32_t*)((char*)DAT_00d1b6d8 + 0xcd8) &
       *(uint32_t*)((char*)DAT_00d1b6d8 + 0xcdc)) != 0xFFFFFFFFu)
    return;
  if ((unaff_ESI[0] & unaff_ESI[1]) == 0xFFFFFFFFu)
    return;

  // Multi-inherit character this + vtbl+0x194 (dead / hard modal)
  {
    int baseAdj = *(int*)((char*)DAT_00d1b6d8 + 4);
    int off = *(int*)(baseAdj + 4);
    int* obj = (int*)((char*)DAT_00d1b6d8 + off + 4);
    int* vtbl = (int*)*obj;
    cVar1 = ((char(__thiscall*)(void*))vtbl[0x194 / 4])(obj);
  }
  if (cVar1 != '\0')
    return;

  cVar1 = ((char(__thiscall*)(void*))(*(int**)DAT_00d1b958)[0x3d8 / 4])(DAT_00d1b958);
  if (cVar1 != '\0')
    return;
  cVar1 = ((char(__thiscall*)(void*))(*(int**)DAT_00d1b95c)[0x3d8 / 4])(DAT_00d1b95c);
  if (cVar1 != '\0')
    return;

  // Pack (offsets from buffer base = &auStack_30[0])
  uStack_28 = unaff_ESI[0]; // +0x08
  uStack_24 = unaff_ESI[1]; // +0x0c
  uStack_20 = 0;            // +0x10
  uStack_1c = 0;            // +0x14
  uStack_18 = 0;            // +0x18
  uStack_14 = 0;            // +0x1c
  uStack_10 = 0;            // +0x20
  uStack_c  = 0;            // +0x24
  fStack_8  = g_flMsToSeconds_Inferred; // +0x28 = 0.001f
  auStack_30[0] = 0x2055;   // +0x00 opcode
  // auStack_30[1] (+0x04) intentionally unwritten (pad / UnknownField)

  // EAX=8 before call (Client_SendSectorPacket Ordered path)
  Client_SendSectorPacket(&DAT_00d1a840, 0x30, auStack_30);
}
