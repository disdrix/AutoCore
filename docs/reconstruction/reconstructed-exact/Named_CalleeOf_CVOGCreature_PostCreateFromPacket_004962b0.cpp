// =============================================================================
// Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004962b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004962b0
// Address:   0x004962b0
// Alias of:  EquipGfxHost_ClearListIfFlag_Inferred / FUN_004962b0
// Note:      Parent-seed scaffold name only — primary role is shared gfx-host
//            list clear (equip/create/destroy), not PostCreate-specific.
// Dual A/B:  2026-07-29 accept-with-gaps
// =============================================================================

// See FUN_004962b0.cpp for bytes-faithful body.

void __thiscall FUN_004367f0(void *vec, unsigned count, unsigned fill);

void __fastcall Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004962b0(void *host)
{
  if (*(char *)((char *)host + 0x53) == 0) {
    return;
  }

  FUN_004367f0((char *)host + 0xA8, 0, 0);
}
