// =============================================================================
// CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00521310
// Address:   0x00521310 – 0x00521430 (0x120 bytes)
// Module:    autoassault.exe (image base 0x400000)
// System:    character create / vehicle attach / sector map
// Generated: 2026-07-29 W18-R dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED (not run).
// =============================================================================

// PURPOSE:
//   Finish character create-apply on the client: resolve CurrentVehicleCoid,
//   Creature::SetVehicle, optional vehicle post flag, CVOGSectorMap_AddCharacter,
//   optional AutoAssault LOD handler boost for packet type 0x2016, optional
//   equip-gfx host list clear.
//
//   Explains why player vehicles always received SetVehicle/HP framing (NPC.md).
//
// ABI: __thiscall on character subobject (this_adj); ret 0x18 (6 stack args).
// Caller: CVOGCharacter_CreateFromPacket @ 0x005238c7.

#include <cstdint>

extern void *FUN_004bafe0(uint8_t type_or_global, uint32_t coid_lo, uint32_t coid_hi);
extern void  FUN_004c49d0(void *vehicle);           // Creature::SetVehicle (this=creature)
extern void  FUN_0053d970(int zero);                // vehicle post
extern void  CVOGSectorMap_AddCharacter(void *character_base);
extern void  FUN_005c93f0(void *a, void *b, void *c, void *d, void *e, void *f);
extern void * __RTDynamicCast(void *in, int, void *src_td, void *dst_td, int);
extern void  FUN_00760fe0(int zero, float value);   // LOD / camera helper
extern void  FUN_004962b0();                        // EquipGfxHost_ClearListIfFlag

// RTTI descriptors (Ghidra symbols)
extern char gfxLODHandler_RTTI_Type_Descriptor[];
extern char gfxLODHandler_AutoAssault_RTTI_Type_Descriptor[];

void __thiscall CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred(
    int this_adj,
    int *pkt_or_ctx,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5,
    uint32_t param_6,
    uint32_t param_7)
{
  void *vehicle;
  void *lod;
  void *aa;
  void *obj;
  int *mi_base;
  int mi_off;

  if ((char)param_7 != '\0') {
    FUN_005c93f0(pkt_or_ctx,
                 reinterpret_cast<void *>(static_cast<uintptr_t>(param_3)),
                 reinterpret_cast<void *>(static_cast<uintptr_t>(param_4)),
                 reinterpret_cast<void *>(static_cast<uintptr_t>(param_5)),
                 reinterpret_cast<void *>(static_cast<uintptr_t>(param_6)),
                 reinterpret_cast<void *>(static_cast<uintptr_t>(param_7)));
  }

  // Resolve CurrentVehicleCoid via Object_ResolveTarget_VCall1d4
  mi_base = *reinterpret_cast<int **>(this_adj + -0xd9c);
  mi_off = mi_base[1];
  vehicle = FUN_004bafe0(
      *reinterpret_cast<uint8_t *>(mi_off + -0xc34 + this_adj),
      *reinterpret_cast<uint32_t *>(this_adj + -0xb90),
      *reinterpret_cast<uint32_t *>(this_adj + -0xb8c));

  FUN_004c49d0(vehicle);  // Creature::SetVehicle — retail binds creature this via ECX

  if (vehicle != nullptr) {
    FUN_0053d970(0);
    *reinterpret_cast<bool *>(reinterpret_cast<char *>(vehicle) + 0x101) =
        (*reinterpret_cast<char *>(this_adj + -0xa94) == '\0');
  }

  CVOGSectorMap_AddCharacter(reinterpret_cast<void *>(this_adj + -0xda0));

  if ((*pkt_or_ctx == 0x2016) &&
      (*reinterpret_cast<int *>(this_adj + -0xd58) != 0) &&
      ((lod = *reinterpret_cast<void **>(
            *reinterpret_cast<int *>(this_adj + -0xd58) + 0x94),
        lod != nullptr))) {
    aa = __RTDynamicCast(lod, 0,
                         &gfxLODHandler_RTTI_Type_Descriptor,
                         &gfxLODHandler_AutoAssault_RTTI_Type_Descriptor, 0);
    if (aa != nullptr) {
      FUN_00760fe0(0, 999.0f);  // 0x4479c000
    }
  }

  obj = *reinterpret_cast<void **>(
      (*reinterpret_cast<int **>(this_adj + -0xd9c))[1] + -0xcf8 + this_adj);
  if ((obj != nullptr) &&
      (*reinterpret_cast<int *>(reinterpret_cast<char *>(obj) + 0xe898) != 0)) {
    FUN_004962b0();
  }
}

void __thiscall FUN_00521310(
    int this_adj, int *pkt_or_ctx,
    uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7)
{
  CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred(
      this_adj, pkt_or_ctx, p3, p4, p5, p6, p7);
}
