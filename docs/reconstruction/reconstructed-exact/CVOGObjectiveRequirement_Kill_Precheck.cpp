// READABILITY (auto CF):
//  - Multi-branch kill precheck; three credit mutate sites.
//  - Asm seal 2026-07-29: arg2=state, arg5=addend; no decomp +0.0.
//  - RET 0x1c (7 stack args). Eval pure-read contrast sealed.

// =============================================================================
// CVOGObjectiveRequirement_Kill_Precheck
// -----------------------------------------------------------------------------
// Stable ID: aa_00613b50
// Address:   0x00613b50  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; 2026-07-29 ABI/asm residual rewrite
// Exactness: Behavior from live disassemble_function + decompile. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// Vtable: Kill requirement 0x009e19e4 +0x4 (Eval +0x8 = 0x00613910)
//
// Slot (shared with Eval):
//   slot = *(uint8_t*)(req + 0x08)
//   progress @ state + 4 + slot*4
//   required = (float)*(int32_t*)(req + 0x18)
//
// Mutate vs Eval:
//   Precheck ADDS into progress; Eval only compares progress >= required.
// =============================================================================

#include <cstdint>

// Entity vtable indices used (byte offsets into vptr table as in client):
//   +0x1d4, +0x210, +0x244, +0x27c, +0x28c — see raw/annotated for call sites.

extern "C" void __fastcall FUN_005001f0(int entity_related);
extern "C" void CVOGReaction_FailMission(/* mission* */);

/// @return 1 on accepted credit (vehicle path) or non-fail credit; 0 on reject / FailMission
std::uint32_t __thiscall CVOGObjectiveRequirement_Kill_Precheck(
    int* req,                 // ECX / this
    int* ctx_entity,          // arg1 — killer/context (faction compare)
    float* state,             // arg2 — progress blob
    int type_code,            // arg3 — must be 0
    float cbid_or_value,      // arg4 — CVTTSS2SI for direct CBID when req+0x11==0
    float addend,             // arg5 — credit delta for default/vehicle paths
    void* /*unused_arg6*/,    // arg6 — no body references
    int* victim)              // arg7 — victim entity
{
  // --- gates ---
  if (type_code != 0) {
    return 0;
  }

  // vtbl+0x8 = Kill_Eval(req, ctx_entity, state) — pure read; no credit if complete
  auto eval = *reinterpret_cast<std::uint8_t(__thiscall**)(int*, int*, float*)>(
      *reinterpret_cast<std::uintptr_t*>(req) + 8);
  if (eval(req, ctx_entity, state) != 0) {
    return 0;
  }

  const auto slot = *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(req) + 8);
  float* progress = reinterpret_cast<float*>(
      reinterpret_cast<char*>(state) + 4 + static_cast<std::uint32_t>(slot) * 4);

  // --- vehicle-style path (req+0x10) ---
  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(req) + 0x10) != 0) {
    // Filters (victim vcalls +0x1d4 / +0x210(0), faction@+0x532 inequality vs ctx,
    // optional level +0x27c vs req+0x30/+0x34, bitmasks req+0x24 / req+0x28):
    // See raw asm 0x00613b87–0x00613c5b. On any filter fail → return 0.
    //
    // On success:
    *progress = *progress + addend;
    return 1;  // early success — skips FailMission tail
  }

  // --- non-vehicle: direct (req+0x12==0) or type-0xe (req+0x12!=0) ---
  // Direct: CBID via float trunc of arg4 or victim.vcall(+0x28c) vs req+0x14;
  //         reject if (float)req+0x18 <= *progress; optional type@ victim+0xa8+0x38;
  //         optional level band.
  // Type-0xe: require type==0xe; CBID via FUN_005001f0 after +0x1d4; same cap/level.
  // Full filter CF: raw body + dual A §5. Any fail → return 0.

  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(req) + 0x13) != 0 && victim != nullptr) {
    // XP-style credit: progress += (float)victim.vcall(+0x244)
    auto v244 = *reinterpret_cast<int(__thiscall**)(int*)>(
        *reinterpret_cast<std::uintptr_t*>(victim) + 0x244);
    *progress = *progress + static_cast<float>(v244(victim));
  } else {
    *progress = *progress + addend;
  }

  // FailMission tail (non-vehicle only)
  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(req) + 0x1c) != 0) {
    // mission = **(req[1] + 0x14c); CVOGReaction_FailMission(mission) with ECX=ctx
    CVOGReaction_FailMission(nullptr /* see raw: deref req+4 → +0x14c */);
    return 0;
  }
  return 1;
}
