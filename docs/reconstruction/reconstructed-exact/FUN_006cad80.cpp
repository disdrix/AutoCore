// =============================================================================
// WorldCast_SetupCollectorAndDispatch_Inferred  (FUN_006cad80)
// -----------------------------------------------------------------------------
// Stable ID: aa_006cad80
// Address:   0x006cad80  (autoassault.exe, image base 0x400000)
// Body:      0x006cad80 – 0x006cae18 (exclusive end 0x006cae19)
// System:    world / map collision cast
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W19-M)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Fill a cast-collector object from (ray, filter, result), pack a stack
// ray packet, and dispatch world->vtbl[+0x30](packet, collector, 0).
// Sole known caller: MapCollisionCtx_CastRay (FUN_0055e530). Used by map terrain
// height via CVOGMap_CastTerrainHeight — NOT vehicle TtPhantom::castRay.
//
// ABI: __thiscall; ECX = collector; 5 stack args; epilogue ret 0x14 (20 bytes).
//   this (ECX)  = Collector*
//   [ebp+08]    = World*          (object with vtbl cast at +0x30)
//   [ebp+0c]    = Ray*            (at least 0x24 bytes; flag at +0x20)
//   [ebp+10]    = Filter* or null (offsets +0x10 / +0x14 used when non-null)
//   [ebp+14]    = extra dword     (wrapper passes 0)
//   [ebp+18]    = Result*
//
// Collector fields written:
//   +0x04  ray*
//   +0x08  filter ? filter+0x14 : 0
//   +0x0c  result*
//   +0x34  (ray+0x20 != 0 && filter) ? filter+0x10 : 0
//
// RELATED:
//   - MapCollisionCtx_CastRay @ 0x0055e530 (sole CODE xref)
//   - CVOGMap_CastTerrainHeight @ 0x004cfe60 (parent path)
//   - Contrast: TtPhantom::castRay @ 0x00580ed0
//

#include <cstdint>

struct WorldCast_RayPacket {
  uint32_t ray_dwords[4];  // copy of ray[0..3]
  uint32_t flag_one;       // 1
  uint32_t *ray_mid;       // ray + 0x10
  uint32_t const_10;       // 0x10
  uint32_t extra;          // param_5
};

// Clean structural name
void __thiscall WorldCast_SetupCollectorAndDispatch_Inferred(
    void *collector,
    void *world,
    uint32_t *ray,
    uint8_t *filter,
    uint32_t extra,
    void *result)
{
  int shapeOfs;

  *(uint32_t **)((char *)collector + 4) = ray;
  *(void **)((char *)collector + 0xc) = result;

  if (filter == 0) {
    shapeOfs = 0;
  } else {
    shapeOfs = (int)(filter + 0x14);
  }
  *(int *)((char *)collector + 8) = shapeOfs;

  // decompiler: *(char *)(ray + 8) as undefined4*  ==  ray+0x20
  if (*(char *)((char *)ray + 0x20) == '\0') {
    *(uint32_t *)((char *)collector + 0x34) = 0;
  } else if (filter == 0) {
    *(uint32_t *)((char *)collector + 0x34) = 0;
  } else {
    *(int *)((char *)collector + 0x34) = (int)(filter + 0x10);
  }

  WorldCast_RayPacket packet;
  packet.ray_dwords[0] = ray[0];
  packet.ray_dwords[1] = ray[1];
  packet.ray_dwords[2] = ray[2];
  packet.ray_dwords[3] = ray[3];
  packet.flag_one = 1;
  packet.ray_mid = ray + 4;  // ray + 0x10
  packet.const_10 = 0x10;
  packet.extra = extra;

  // thiscall: ECX = world; stack (packet*, collector*, 0)
  void **vtbl = *(void ***)world;
  typedef void (__thiscall *WorldCastVfn)(void *world, void *packet, void *collector, int zero);
  ((WorldCastVfn)vtbl[0x30 / 4])(world, &packet, collector, 0);
}

// Ghidra alias (scaffold signature preserved)
void __thiscall FUN_006cad80(
    int param_1,
    int *param_2,
    uint32_t *param_3,
    int param_4,
    uint32_t param_5,
    uint32_t param_6)
{
  WorldCast_SetupCollectorAndDispatch_Inferred(
      (void *)param_1,
      (void *)param_2,
      param_3,
      (uint8_t *)param_4,
      param_5,
      (void *)param_6);
}

// Misleading auto parent-seed alias (callee-of scan) — keep as name only
void Named_CalleeOf_Named_CalleeOf_CVOGMap_CastTerrainHeight_006cad80(
    int param_1,
    int *param_2,
    uint32_t *param_3,
    int param_4,
    uint32_t param_5,
    uint32_t param_6)
{
  FUN_006cad80(param_1, param_2, param_3, param_4, param_5, param_6);
}
