// =============================================================================
// UI_InteractionMenu_PopulateTargetButtons_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fe20
// Address:   0x0082fe20 – 0x0082ff3f exclusive (autoassault.exe, base 0x400000)
// Size:      0x11F (287 B); multiple ret (C3) epilogues; pad CC
// System:    interaction menu / social UI (parent of convoy Invite/Kick pack)
// Generated: 2026-08-04 WQ9E-D dual (live decompile ≡ raw 2026-07-23 + read_memory)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     FUN_0082fe20 scaffold
// =============================================================================
//
// PURPOSE: When the interaction menu host is active (+0x4C0), rebuild the popup
// shell and, for a resolved non-self target TFID at host+0x578, populate the
// social action button pack (Ignore, Friends, Tell, Trade, Clan, Convoy, name).
// Pack call order is reversed when host->vtbl+0x478() returns non-zero.
//
// ABI: __thiscall; ECX = menu host*; ret 0 (no stack cleanup).
// Vtbl method: sole DATA xref @ 0x00a720e0.
// Dualed child: UI_InteractionMenu_AddConvoyInviteOrKick_Inferred (FUN_0082fb30).
// =============================================================================

#include <cstdint>

struct Object;
struct MenuHost;
struct TFID_16;

extern Object* DAT_00d1b6d8; // local player

// Popup shell rebuild (blocker / list reset) — not dualed here.
extern "C" void __fastcall FUN_0082d2b0(MenuHost* menu);

// Resolve world object from TFID — dualed elsewhere as Object_ResolveFromTFID.
extern "C" Object* Object_ResolveFromTFID(TFID_16* tfid);

// Close / hide related widget path when host+0x2B0 set — not dualed here.
extern "C" void FUN_0090d400(/* ESI/EDI parent regs */);

// Button pack helpers (register-contract children; most undualed).
// Target typically in EAX/EDX/EBX; menu host in ESI/EDI per pack.
extern "C" void FUN_0082f8d0(); // Add/Remove Ignore
extern "C" void FUN_0082f9a0(); // Add/Remove Friends
extern "C" void FUN_0082f810(); // Send a Tell
extern "C" void FUN_0082fc40(); // Trade
extern "C" void FUN_0082fa60(); // Clan Invite/Kick
extern "C" void FUN_0082fb30(); // Convoy Invite/Kick (dualed)
extern "C" void FUN_0082fd50(); // nameplate / labeled button

// __thiscall
extern "C" void __thiscall UI_InteractionMenu_PopulateTargetButtons_Inferred(
    MenuHost* menu)
{
  auto* host = reinterpret_cast<std::uint8_t*>(menu);

  // Gate: host+0x4C0 (param_1[0x130]) must be non-zero.
  if (*reinterpret_cast<int*>(host + 0x4c0) == 0) {
    return;
  }

  FUN_0082d2b0(menu);

  Object* target = nullptr;
  if (DAT_00d1b6d8 == nullptr) {
    if (*reinterpret_cast<int*>(host + 0x2b0) != 0) {
      FUN_0090d400();
    }
    return;
  }

  // Resolve TFID at host+0x578 (param_1 + 0x15e as int*).
  target = Object_ResolveFromTFID(reinterpret_cast<TFID_16*>(host + 0x578));
  if (target == nullptr) {
    if (*reinterpret_cast<int*>(host + 0x2b0) != 0) {
      FUN_0090d400();
    }
    return;
  }

  // local SharedBase vtbl+0x298(target) — affinity / blocked probe.
  // Decompiler: nested offBase(local) + 0x298. Non-zero → skip pack.
  {
    auto* local = reinterpret_cast<std::uint8_t*>(DAT_00d1b6d8);
    int offBase =
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(local + 4) + 4);
    auto** vtbl = *reinterpret_cast<void***>(local + offBase + 4);
    using AffFn = char(__thiscall*)(void*, Object*);
    auto aff = reinterpret_cast<AffFn>(vtbl[0x298 / 4]);
    if (aff(reinterpret_cast<void*>(local + offBase + 4), target) != 0) {
      if (*reinterpret_cast<int*>(host + 0x2b0) != 0) {
        FUN_0090d400();
      }
      return;
    }
  }

  // target->vtbl+0x210(0) — owner/parent; skip if null or local.
  {
    auto** vtbl = *reinterpret_cast<void***>(target);
    using OwnFn = Object*(__thiscall*)(Object*, int);
    Object* ownerOrSelf =
        reinterpret_cast<OwnFn>(vtbl[0x210 / 4])(target, 0);
    if (ownerOrSelf == nullptr || ownerOrSelf == DAT_00d1b6d8) {
      if (*reinterpret_cast<int*>(host + 0x2b0) != 0) {
        FUN_0090d400();
      }
      return;
    }
  }

  // menu->vtbl+0x478() — button order flag.
  int orderFlag = 0;
  {
    auto** vtbl = *reinterpret_cast<void***>(menu);
    using FlagFn = int(__thiscall*)(MenuHost*);
    orderFlag = reinterpret_cast<FlagFn>(vtbl[0x478 / 4])(menu);
  }

  if (orderFlag == 0) {
    FUN_0082f8d0(); // Ignore
    FUN_0082f9a0(); // Friends
    FUN_0082f810(); // Tell
    FUN_0082fc40(); // Trade
    FUN_0082fa60(); // Clan
    FUN_0082fb30(); // Convoy (dualed child)
    FUN_0082fd50(); // Name
  } else {
    FUN_0082fd50();
    FUN_0082fb30();
    FUN_0082fa60();
    FUN_0082fc40();
    FUN_0082f810();
    FUN_0082f9a0();
    FUN_0082f8d0();
  }
}
