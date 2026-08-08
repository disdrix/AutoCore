// =============================================================================
// FUN_006ca890  (scaffold twin — prefer SoftCastHitList_CoreFillAndRegister_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_006ca890
// Address:   0x006ca890  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-062 — machine ABI correction of 2026-07-23 scaffold
// Exactness: Behavior-preserving. Named clean is authoritative for ports.
// =============================================================================
//
// PURPOSE: Soft-cast hit-list core fill + register (entry init → vtbl+0x30).
// Canonical: SoftCastHitList_CoreFillAndRegister_Inferred
//
// ABI CORRECTION vs scaffold:
//   Scaffold used decompiler void __thiscall with generic params and no RET size.
//   Sealed: thiscall ECX=entry; 5 stack formals; RET 0x14; indirect vcall only.
// =============================================================================

#include <cstdint>

// Ghidra symbol retained for xref continuity; prefer the named clean.
void __thiscall FUN_006ca890(int entry, int *manager, uint32_t *soft_desc,
                             int related_obj, uint32_t query_payload,
                             uint32_t hit_list_backref)
{
  int related_link;

  *reinterpret_cast<uint32_t **>(entry + 4) = soft_desc;
  *reinterpret_cast<uint32_t *>(entry + 0xc) = hit_list_backref;
  *reinterpret_cast<uint32_t *>(entry + 0x10) = 0;

  if (related_obj == 0) {
    related_link = 0;
  } else {
    related_link = related_obj + 0x14;
  }
  *reinterpret_cast<int *>(entry + 8) = related_link;

  if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(soft_desc) + 0x20) ==
      '\0') {
    *reinterpret_cast<uint32_t *>(entry + 0x44) = 0;
  } else if (related_obj == 0) {
    *reinterpret_cast<uint32_t *>(entry + 0x44) = 0;
    *reinterpret_cast<uint32_t *>(entry + 0x40) = soft_desc[9];
  } else {
    *reinterpret_cast<int *>(entry + 0x44) = related_obj + 0x10;
    *reinterpret_cast<uint32_t *>(entry + 0x40) = soft_desc[9];
  }

  // 16-byte-aligned query packet (matches SUB ESP,0x2C / AND ESP,~0xF frame)
  uint32_t local_30 = soft_desc[0];
  uint32_t local_2c = soft_desc[1];
  uint32_t local_28 = soft_desc[2];
  uint32_t local_24 = soft_desc[3];
  uint32_t *local_1c = soft_desc + 4;
  uint32_t local_14 = query_payload;
  uint32_t local_20 = 1;
  uint32_t local_18 = 0x10;

  // silence unused in twin when compiling as translation unit without calls
  (void)local_2c;
  (void)local_28;
  (void)local_24;
  (void)local_1c;
  (void)local_14;
  (void)local_20;
  (void)local_18;

  // ECX = manager; PUSH 0; PUSH entry; PUSH &local_30; CALL [vtbl+0x30]
  auto vtbl = *reinterpret_cast<uint8_t ***>(manager);
  auto fn = *reinterpret_cast<void(__thiscall **)(int *, uint32_t *, int, int)>(
      vtbl + 0x30);
  fn(manager, &local_30, entry, 0);
}
