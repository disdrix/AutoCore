// =============================================================================
// CVOGHBMissionEscort_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_006507c0
// Address:   0x006507c0–0x006508c8  (autoassault.exe, image base 0x400000)
// System:    missions-progression / heartbeat
// Generated: 2026-08-04 WQ9G-E dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + bytes ABI.
// Verdict:   accept-with-gaps
// Terminal:  false
// Bit-for-bit / runtime / differential: DEFERRED / OPEN
// =============================================================================
//
// PURPOSE:
//   Construct CVOGHBMissionEscort HB action used by escort objective residual
//   (factory FUN_0060c860 → operator_new(0x78) → this → Enqueue → Start).
//
// CLASS:  CVOGHBMissionEscort
//   RTTI TD 0x00af4a10  .?AVCVOGHBMissionEscort@@
//   COL     0x00ab1e9c  (at vtable-4 / 0x009e52c0)
//   Vtable  PTR_FUN_009e52c4:
//     +0x00 dtor 00650d00
//     +0x04 StampLastFire 00508270
//     +0x08 TryFire 005082c0
//     +0x0C OnHeartBeat 006508d0  (dualed aa_006508d0)
//
// ABI:    MSVC __thiscall (ECX = this)
//         stack: void* ownerCtx, void* reqHost
//         ret 8; returns this
//
// FIELD MAP (dword indices as Ghidra param_1[n]; matches OnHB dual):
//   +0x00  pVTable
//   +0x08  nPeriodMs           (= 1000 after SetPeriod)
//   +0x1C  tag                 (= 0x0b)
//   +0x24  nested world/slot from ownerCtx
//   +0x28  missionKey          from *(reqHost+4)+0x10
//   +0x2C  targetMatchRef      from reqHost+0x44 (post FUN_0060c3c0)
//   +0x30  matchByObjRefMode   from reqHost+0x48 (byte)
//   +0x38  cachedEscortTfid[4] default DAT_009e52b0 = {−1,−1,0,0}
//   +0x48  maxEscortRange      from reqHost+0x1c (float bits)
//   +0x50..+0x68 complete-zone dual keys/radius from reqHost +0x28..+0x3c
//   +0x6C  pReqHost            = reqHost
//   +0x70  dwLastTick          = g_dwClientTickMs
//
// CALLEES:
//   CVOGHBBase_ctor
//   FUN_0060c3c0(reqHost) — fill req+0x44/+0x48 if match ref still −1
//   CVOGHBBase_SetPeriodAndCounter(this, −1000, true)
//   CVOGHBBase_AttachOwnerObject(this, nested owner object)
//
// GAPS:
//   - Product English for full reqHost schema
//   - Second call site 0x00613e62 (Ghidra function gap)
//   - Runtime / bit-exact
// =============================================================================

#include <cstdint>

extern "C" void* CVOGHBBase_ctor(void* self);
extern "C" void  CVOGHBBase_SetPeriodAndCounter(void* self, int periodMs, bool flag);
extern "C" void  CVOGHBBase_AttachOwnerObject(void* self, void* ownerObj);
extern "C" void  FUN_0060c3c0(void* reqHost); // ECX = reqHost

extern std::uint32_t DAT_009e52b0; // −1
extern std::uint32_t DAT_009e52b4; // −1
extern std::uint32_t DAT_009e52b8; // 0
extern std::uint32_t DAT_009e52bc; // 0
extern std::uint32_t g_dwClientTickMs;
extern void*         PTR_FUN_009e52c4;

struct CVOGHBMissionEscort {
  void*         pVTable;           // +0x00
  std::int32_t  nRefOrFlags;       // +0x04
  std::int32_t  nPeriodMs;         // +0x08
  std::int32_t  pad_0c;            // +0x0C
  std::int32_t  pad_10;            // +0x10
  std::int32_t  pad_14;            // +0x14
  std::int32_t  pad_18;            // +0x18
  std::int32_t  nTag_0b;           // +0x1C
  std::int32_t  pad_20;            // +0x20
  std::uint32_t nestedWorldSlot;   // +0x24
  std::uint32_t missionKey;        // +0x28
  std::uint32_t targetMatchRef;    // +0x2C
  std::uint8_t  matchByObjRefMode; // +0x30
  std::uint8_t  pad_31[7];
  std::uint32_t cachedTfid[4];     // +0x38
  float         maxEscortRange;    // +0x48
  std::uint32_t pad_4c;
  std::uint32_t completeZoneA_lo;  // +0x50
  std::uint32_t completeZoneA_hi;  // +0x54
  std::uint32_t completeZoneR;     // +0x58
  std::uint32_t pad_5c;
  std::uint32_t completeZoneB_lo;  // +0x60
  std::uint32_t completeZoneB_hi;  // +0x64
  std::uint32_t completeZonePad;   // +0x68
  void*         pReqHost;          // +0x6C
  std::uint32_t dwLastTick;        // +0x70
  // sizeof factory alloc 0x78
};

CVOGHBMissionEscort* __thiscall CVOGHBMissionEscort_ctor(
    CVOGHBMissionEscort* self,
    void* ownerCtx,
    void* reqHost)
{
  CVOGHBBase_ctor(self);
  self->pVTable = &PTR_FUN_009e52c4;

  // Nested chain: *(*(ownerCtx+4)+4) + 0xa8 + ownerCtx
  int vft = *(int*)((char*)ownerCtx + 4);
  int mid = *(int*)(vft + 4);
  self->nestedWorldSlot = *(std::uint32_t*)(mid + 0xa8 + (int)ownerCtx);

  self->cachedTfid[0] = DAT_009e52b0;
  self->cachedTfid[1] = DAT_009e52b4;
  self->cachedTfid[2] = DAT_009e52b8;
  self->cachedTfid[3] = DAT_009e52bc;

  self->pReqHost = reqHost;
  FUN_0060c3c0(reqHost); // thiscall ECX=reqHost

  self->targetMatchRef    = *(std::uint32_t*)((char*)reqHost + 0x44);
  self->matchByObjRefMode = *(std::uint8_t*)((char*)reqHost + 0x48);

  int reqMid = *(int*)((char*)reqHost + 4);
  self->missionKey = *(std::uint32_t*)(reqMid + 0x10);

  self->maxEscortRange   = *(float*)((char*)reqHost + 0x1c);
  self->completeZoneA_lo = *(std::uint32_t*)((char*)reqHost + 0x28);
  self->completeZoneA_hi = *(std::uint32_t*)((char*)reqHost + 0x2c);
  self->completeZoneR    = *(std::uint32_t*)((char*)reqHost + 0x38);
  self->completeZoneB_lo = *(std::uint32_t*)((char*)reqHost + 0x30);
  self->completeZoneB_hi = *(std::uint32_t*)((char*)reqHost + 0x34);
  self->completeZonePad  = *(std::uint32_t*)((char*)reqHost + 0x3c);

  self->nTag_0b = 0x0b;
  CVOGHBBase_SetPeriodAndCounter(self, /*periodMs=*/-1000, /*flag=*/true);

  // Owner object: *(*(ownerCtx+4)+4) + 4 + ownerCtx
  void* ownerObj = (void*)(mid + 4 + (int)ownerCtx);
  CVOGHBBase_AttachOwnerObject(self, ownerObj);

  self->nPeriodMs   = 1000;
  self->dwLastTick  = g_dwClientTickMs;
  return self;
}
