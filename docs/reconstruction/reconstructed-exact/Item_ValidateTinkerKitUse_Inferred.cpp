// =============================================================================
// Item_ValidateTinkerKitUse_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00513c10
// Address:   0x00513c10 – 0x00513cde (207 B)  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-036 dual seal (replaces Named_CalleeOf scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime Confirmed: NOT claimed (no Launcher).
// =============================================================================
//
// PURPOSE
//   Validate whether a CVOGTinkeringKit may be applied to a target item for the
//   local character. Returns a status code consumed by dualed UI tooltip
//   (FUN_0085ce20 mode 4) and apply dialog (FUN_0085f660).
//
//   Status codes (caller-sealed strings):
//     0  no openable slots (also early Broken inside this unit)
//     1  "You do not possess the Tinkering skill to work on this object."
//     2  "This Tinkering Kit is too primitive to use on this object."
//     3  category mismatch / null kit or character
//        (caller maps 3 → "This Tinkering Kit can only be used on %s.")
//     4  OK — proceed (success-chance path)
//
// ABI (assembly-sealed)
//   __thiscall: ECX = item*
//   stack:      character*, kit*   (RET 8)
//   return:     char/int status in EAX
//
// Callees
//   FUN_00513bc0(item, kit)  — category match
//   item->vtbl[+0x8c]()      — opened slot count (short)
//   FUN_00521eb0()           — character skill tier (ECX=character)
//
// =============================================================================

// Forward decls for unowned callees (leave-FUN until dualed).
// FUN_00513bc0: __thiscall ECX=item, stack kit → char category match.
// FUN_00521eb0: __fastcall ECX=character → int skill tier (from char+0x59b).
extern char __thiscall FUN_00513bc0(void* item_this, void* kit);
extern int  __fastcall FUN_00521eb0(void* character);

char __thiscall Item_ValidateTinkerKitUse_Inferred(
    int* item,       /* ECX */
    int* character,  /* stack+4 */
    int  kit)        /* stack+8 — CVOGTinkeringKit* */
{
  char categoryOk;
  short curSlots;
  short maxSlots;
  int skillTier;

  if (kit == 0) {
    return 3;
  }

  // Assembly LEA EBX,[kit+0xb0]; TEST EBX — address of level field (parity with raw).
  if ((short*)(kit + 0xb0) == (short*)0) {
    return 3;
  }

  categoryOk = FUN_00513bc0(item, (void*)kit);
  if (categoryOk == 0) {
    return 3;
  }

  // Broken flag: item[+0x17c] >> 19 & 1  (== item[0x5f] as uint dword index)
  if ((((unsigned)item[0x5f] >> 0x13) & 1) != 0) {
    return 0;
  }

  // max openable slots from item def blob @ host+0x3c → def+0x4b4
  maxSlots = *(short*)(*(int*)(item[0x2a] + 0x3c) + 0x4b4);
  curSlots = (**(short(__thiscall***)(int*))(*item + 0x8c))(item);
  if (maxSlots <= curSlots) {
    return 0;  // no available slots to open
  }

  if (character == 0) {
    return 3;
  }

  curSlots = (**(short(__thiscall***)(int*))(*item + 0x8c))(item);
  skillTier = FUN_00521eb0(character);  // ECX=character
  if ((skillTier < curSlots + 1) && (character[0x6b4 / 4] < 1)) {
    return 1;  // tinkering skill insufficient for next slot
  }

  // kit level @ kit+0xb0 vs need → 4 ok / 2 primitive  (SETGE + LEA [CL+CL+2])
  return (char)(((curSlots + 1 <= (int)*(short*)(kit + 0xb0)) * 2) + 2);
}
