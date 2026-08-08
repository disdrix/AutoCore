// =============================================================================
// Item_GetTinkerSkillOrCap_Inferred  (FUN_00521eb0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00521eb0
// Address:   0x00521eb0–0x00521ef6 inclusive (71 B / 0x47)
//            jump table data @ 0x00521ef8 (9 dwords); pad NOP @ 0x00521ef7
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / tinker kit skill-tier map
// Generated: 2026-08-05 MEGA-106 dual seal
//            (decompile_function + analyze_function_complete + disassemble_function
//             + read_memory + callers/xrefs + caller disasm)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE: Map item byte at +0x59b to a capped tinker skill-tier value 0..5.
// Used by tinker-kit validation FUN_00513c10 and tinker float helper FUN_00521f20
// as the item-side threshold compared against character vfunc(+0x8c)+1.
//
// Partition hint Character_GetTinkerSkillOrCap corrected: call-site ECX is the
// **item** (EDI), not the character. Character skill is parent-side only.
//
// Retires scaffold: Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0
//
// Mapping:
//   0 -> 0
//   1,2 -> 1 | 3,4 -> 2 | 5,6 -> 3 | 7,8 -> 4 | 9 -> 5 | >=10 -> 5
//   i.e. v==0 ? 0 : min((v+1)/2, 5)
//
// Leaf: no callees. ABI: __thiscall ECX=item; RET; EAX=tier.

#include <cstdint>

// item+0x59b : uint8 source byte (product field English open → _Inferred)
// item+0x6b4 : int flag checked by parents (not read here)

// __thiscall: ECX = item; no stack args; EAX = tier 0..5; plain RET
extern "C" std::uint8_t __thiscall Item_GetTinkerSkillOrCap_Inferred(void *item)
{
  const auto *base = reinterpret_cast<const std::uint8_t *>(item);
  const std::uint8_t v = base[0x59b];

  if (v == 0) {
    return 0;
  }

  // Jump-table path for v in 1..9; default for v > 9 returns 5.
  switch (v) {
  case 1:
  case 2:
    return 1;
  case 3:
  case 4:
    return 2;
  case 5:
  case 6:
    return 3;
  case 7:
  case 8:
    return 4;
  case 9:
    return 5;
  default:
    // Machine: MOV CL,9; CMP CL,AL; SBB EAX,EAX; AND EAX,5
    // Only reached when v > 9 → always 5.
    return static_cast<std::uint8_t>((v > 9) ? 5 : 0);
  }
}
