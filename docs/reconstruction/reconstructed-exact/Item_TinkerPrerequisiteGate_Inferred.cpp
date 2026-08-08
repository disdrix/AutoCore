// =============================================================================
// Item_TinkerPrerequisiteGate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00513bc0
// Address:   0x00513bc0  (autoassault.exe, image base 0x400000)
// Body:      0x00513bc0–0x00513c06 inclusive (71 B / 0x47)
// System:    inventory-transfer / tinker kit validation
// Generated: 2026-08-05 MEGA-104 OWN-ONLY dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + machine control flow.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Prior:     FUN_00513bc0; Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00513bc0 (retired)
// =============================================================================

// PURPOSE:
//   Boolean prerequisite gate for tinker-kit validation parent FUN_00513c10.
//   Returns true when the candidate item's type is compatible with the kit:
//     - candidate type (+0xb4) equals kit host type (+0xa8)+0x38, OR
//     - candidate type 0x44 and kit def subtype short (+0x3c)+0x3f4 == 10, OR
//     - candidate type 0x46 and kit def subtype short (+0x3c)+0x3f4 == 11.
//   Inverse of FUN_00509b10 type-6 subtype remap (10→0x44, 11→0x46).
//
// ABI (machine-sealed):
//   __thiscall  ECX = kit item
//   stack arg0  = candidate item (nullable)
//   return      = bool in AL (1 pass / 0 fail)
//   epilogue    = RET 4
//
// CALLERS:
//   FUN_00513c10 @ 0x00513c36 (sole static UNCONDITIONAL_CALL)
//
// CALLEES: none (leaf)

#include <cstdint>

// Layout fragments (offsets only; product field names open)
struct ItemDefBlob {
  // ...
  // +0x3f4: int16_t subtype;   // 10 / 11 special-cased for type-6 remap family
};

struct ItemHost {
  // +0x38: uint32_t type;
  // +0x3c: ItemDefBlob* def;
};

struct ItemObject {
  // +0xa8: ItemHost* host;     // kit side
  // +0xb4: uint32_t type;      // candidate side (instance dword)
};

// Retail: uint __thiscall FUN_00513bc0(int kit, int candidate)
// Machine returns AL only; modeled as bool for port clarity.
bool Item_TinkerPrerequisiteGate_Inferred(ItemObject* kit /*ECX*/,
                                          ItemObject* candidate /*stack*/)
{
  if (candidate == nullptr) {
    return false;
  }

  ItemHost* kitHost = *reinterpret_cast<ItemHost**>(
      reinterpret_cast<uint8_t*>(kit) + 0xa8);
  uint32_t candType = *reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(candidate) + 0xb4);
  uint32_t kitType = *reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(kitHost) + 0x38);

  if (candType == kitType) {
    return true;
  }

  if (candType == 0x44u) {
    auto* def = *reinterpret_cast<uint8_t**>(
        reinterpret_cast<uint8_t*>(kitHost) + 0x3c);
    int16_t sub = *reinterpret_cast<int16_t*>(def + 0x3f4);
    return sub == 10;
  }

  if (candType == 0x46u) {
    auto* def = *reinterpret_cast<uint8_t**>(
        reinterpret_cast<uint8_t*>(kitHost) + 0x3c);
    int16_t sub = *reinterpret_cast<int16_t*>(def + 0x3f4);
    return sub == 11;
  }

  return false;
}

// Ghidra twin name retained for search:
//   bool FUN_00513bc0(ItemObject* kit, ItemObject* candidate);
