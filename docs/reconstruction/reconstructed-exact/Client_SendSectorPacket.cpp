// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: ifA-1, returnA-1.
//  - Notable callees: AutoPatrol, C2S, Client_SendSectorPacket, size, state.
//  - Return sites: 1.

// =============================================================================
// Client_SendSectorPacket
// -----------------------------------------------------------------------------
// Purpose:  Generic C2S sector transport. If client+0xc78 (sector connection) is
//           non-null, calls connection vtable +0x18 with (0xffffffff, buffer,
//           (int)size, reliabilityFlags). Always returns 0.
//
// Address:  0x00807460  (autoassault.exe, image base 0x400000)
// Stable:   aa_00807460
// System:   network-sector
//
// Signature:
//   undefined4 __thiscall Client_SendSectorPacket(void* client, short size, void* buffer)
//   + live-in EAX: send-mode bits (see Reliability flag)
//
// Control flow:
//   1) conn = *(client+0xc78); if null -> skip send (intentional silent drop)
//   2) (*conn)->vtbl[+0x18](0xffffffff, buffer, (int)size, ~(EAX>>2)&2)
//   3) return 0
//
// Key offsets:
//   client+0xc78  TNL/sector connection*
//   conn vtbl+0x18 send method
//
// Reliability flag (dual residual sealed 2026-07-29 — reviews/a_00807460.md):
//   flags = ~(in_EAX >> 2) & 2   ∈ {0, 2}
//   equivalent: (EAX & 8) ? 0 : 2
//   0 = RPCGuaranteedOrdered, 1 = RPCGuaranteed (unreachable here),
//   2 = RPCUnguaranteed  (lib/TNL.NET/.../RPCEvent.cs)
//   Canonical callers: MOV EAX, 0x8 immediately before CALL → flags 0
//   Alternate idioms: MOV EAX,EBP under CMP EBP,8; CMP EAX,8 fall-through
//   Sibling inlines (SendUseObject, Flush 0x206E, QB update) hardcode flags 0
//
// Primary residual owners (EAX=8 proven live asm):
//   Client_RequestCastSkill         @ 0x00941883  opcode 0x2030 size 0x28
//   Client_InteractClickPickTarget  @ 0x00924fc0  size 0x10 (class-4 path)
//
// Other call sites (examples; EAX=8 or gated bit3):
//   AutoPatrol C2S 0x20B3 size 0x18
//   FailMission C2S 0x20B2 size 0x18
//   InventoryGrab hardpoint size 0x20
//   DropToGrid 0x2036 size 0x20 / alternate size 0x40
//   RespawnInSector size 0x28
//   MissionDialog state0 0x206F size 0x18
//   Xref total: 67 (Ghidra)
//
// Exactness: CF mirrors raw + live asm + 48B body bytes. Bit-for-bit / runtime / diff: DEFERRED.
// Dual reviews:
//   reviews/A_aa_00807460_Client_SendSectorPacket.md
//   reviews/B_aa_00807460_Client_SendSectorPacket.md
//   reviews/a_00807460.md  (residual seal)
// =============================================================================

uint32_t /* width from decompiler */ __thiscall Client_SendSectorPacket(void *this,short size,void *buffer)



{

  uint in_EAX;

  

  if (*(int *)((int)this + 0xc78) != 0) {

    (**(code **)(**(int **)((int)this + 0xc78) + 0x18))

              (0xffffffff,buffer,(int)size,~(in_EAX >> 2) & 2);

  }

  return 0;

}
