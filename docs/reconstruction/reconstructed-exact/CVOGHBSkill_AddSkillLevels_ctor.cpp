// =============================================================================
// CVOGHBSkill_AddSkillLevels_ctor  (was FUN_006270b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006270b0
// Address:   0x006270b0–0x00627160  (autoassault.exe, image base 0x400000)
// Body size: 177 bytes (0xB1) inclusive of ret 0x18; pad CC → 0x00627170
// System:    skills-abilities
// Generated: 2026-07-23 scaffold as FUN_006270b0; R11-022 dual A/B seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Construct CVOGHBSkill_AddSkillLevels (RTTI Confirmed):
//     1. CVOGHBSkillBase_ctor — base skill HB fields, validate, attach, period
//     2. Install subclass vtbl PTR_FUN_009d1c54
//     3. Init empty RB-tree / map header at this+0x6c4 (+ size 0 @ +0x6c8)
//     4. If pTarget->vtbl+0x210(0) == 0 → AttachOwnerObject(this, null)
//
// RTTI
//   COL @ 0x00aae638 (dword before vtbl) → type_info 0x00af22b4
//   ".?AVCVOGHBSkill_AddSkillLevels@@"
//
// ABI (retail)
//   __thiscall this in ECX (object size 0x6d0 from sole caller)
//   stack: (pSource, pSkillBlob, arg4, pTarget, pTfid, arg7)  → ret 0x18
//   return: this* in EAX
//
// SOLE CALLER
//   FUN_00627750 @ 0x006277ec
//     operator_new(0x6d0) → this ctor → if pOwnerObject: Enqueue(map+0xe4ec)+Start
//                                      else: vtbl dtor(1)
//
// Dual: reviews/A|B_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md
//

#include <cstdint>

extern void* ExceptionList;

// Base ctor (RTTI CVOGHBSkillBase @ 0x005788d0)
extern "C" std::uint32_t* __thiscall CVOGHBSkillBase_ctor(
    std::uint32_t* self,
    void* pSource,
    void* pSkillBlob,
    void* arg4,
    void* pTarget,
    void* pTfid,
    void* arg7);

// Empty RB node factory (dualed aa_00439770)
extern "C" void* RbTree_AllocEmptyNode_Inferred(void); // FUN_00439770

// Base HB owner attach / clear
extern "C" void __thiscall CVOGHBBase_AttachOwnerObject(void* hb, void* owner);

// Image data
extern "C" void* PTR_FUN_009d1c54; // vtbl @ 0x009d1c54

// this = CVOGHBSkill_AddSkillLevels*  (size 0x6d0)
// Formals match CVOGHBSkillBase_ctor stack plate.
std::uint32_t* __thiscall CVOGHBSkill_AddSkillLevels_ctor(
    std::uint32_t* self,
    void* pSource,
    void* pSkillBlob,
    void* arg4,
    void* pTarget,
    void* pTfid,
    void* arg7)
{
    // SEH frame present in binary (LAB_009a8b76); omitted in spirit.
    (void)ExceptionList;

    CVOGHBSkillBase_ctor(self, pSource, pSkillBlob, arg4, pTarget, pTfid, arg7);

    *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d1c54);

    // Empty map / _Tree header at this+0x6c4 (dword index 0x1b1)
    void* node = RbTree_AllocEmptyNode_Inferred();
    self[0x1b1] = reinterpret_cast<std::uint32_t>(node); // +0x6c4 _Myhead
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(node) + 0x15) = 1;
    *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(node) + 4) = node; // parent
    *reinterpret_cast<void**>(node) = node;                                       // left
    *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(node) + 8) = node; // right
    self[0x1b2] = 0; // +0x6c8 _Mysize

    // Target host/mode gate: vtbl+0x210(0). Fail → detach owner (factory skips enqueue).
    using Vfunc0210 = int(__thiscall*)(void* obj, int arg0);
    auto** vtbl = *reinterpret_cast<void***>(pTarget);
    int gate = reinterpret_cast<Vfunc0210>(vtbl[0x210 / sizeof(void*)])(pTarget, 0);
    if (gate == 0) {
        CVOGHBBase_AttachOwnerObject(self, nullptr);
    }

    return self;
}
