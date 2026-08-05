// =============================================================================
// CVOGHBSkillBase_ctor  (was FUN_005788d0; mistaken scaffold CVOGHBSkillCast_ctor_Inferred)
// Address:  0x005788d0  Stable: aa_005788d0
// System:   skills-abilities
//
// RTTI Confirmed: COL@0x00aaede0 → type_info@0x00af8cec ".?AVCVOGHBSkillBase@@"
// Vtable: PTR_FUN_009d3fdc
// Calls Skill_ValidateTargetForSkill(this+0x24 /*skill blob*/, target, notify=1)
// Dual residual sealed: AttachOwner(target) not source; type tag +0x1c=1;
//   period from +0x3C (floor 0→1) only on accept.
// Dual: reviews/A|B_aa_005788d0_CVOGHBSkillBase_ctor.md
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
extern void  CVOGHBBase_ctor(void* self);
extern void  FUN_0054f3c0();
extern void* FUN_00513b00(void* out16);
extern void* FUN_0058ab60(std::uint32_t arg);
extern int   Skill_ValidateTargetForSkill(void* skillRuntime, void* target, void* notifyFlag);
extern void  CVOGHBBase_AttachOwnerObject(void* hb, void* owner);
extern void  CVOGHBBase_SetPeriodAndCounter(void* hb, int period, bool flag);
extern std::uint32_t DAT_009d3f88;
extern void* PTR_FUN_009d3fdc;

// this = CVOGHBSkillBase*
// pSourceObj — object providing seed TFID@+0x160 (may be null); NOT the attach subject
// pSkillBlob — source skill runtime (0x18c dwords copied to this+0x24)
// pTarget    — ValidateTarget target AND AttachOwner subject (notify flag forced 1)
// pTfid      — 16-byte TFID copied to this+0x690 (dword 0x1a4)
// arg7       — stored at +0x6a8; FUN_0058ab60 → this+0x6a0
std::uint32_t* __thiscall CVOGHBSkillBase_ctor(
    std::uint32_t* self,
    int pSourceObj,
    std::uint32_t* pSkillBlob,
    std::uint32_t arg4,
    void* pTarget,
    std::uint32_t* pTfid,
    std::uint32_t arg7)
{
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4 = 0xffffffff;
    std::uint8_t local_1c[16];

    // SEH frame omitted in spirit; ExceptionList bookkeeping present in binary
    (void)local_c;
    (void)puStack_8;
    (void)local_4;

    CVOGHBBase_ctor(self);
    *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d3fdc); // CVOGHBSkillBase vtbl
    FUN_0054f3c0();

    self[0x1ac] = 0;
    self[0x1ad] = 0;
    self[0x1ae] = 0;
    *reinterpret_cast<std::uint8_t*>(self + 0x1a9) = 0;
    self[7] = 1; // HB type tag: skill base

    // Copy skill runtime blob into this+0x24 (index 9), 0x18c dwords
    std::uint32_t* dst = self + 9;
    for (int n = 0x18c; n != 0; --n) {
        *dst++ = *pSkillBlob++;
    }

    // Source-object TFID seed → this+0x658.. (+0x196 dwords); sentinel if null
    std::uint32_t* pSrcTfid =
        (pSourceObj == 0) ? &DAT_009d3f88
                          : reinterpret_cast<std::uint32_t*>(pSourceObj + 0x160);
    self[0x196] = pSrcTfid[0];
    self[0x197] = pSrcTfid[1];
    self[0x198] = pSrcTfid[2];
    self[0x199] = pSrcTfid[3];

    // Secondary TFID block → this+0x668.. (+0x19a)
    std::uint32_t* pAlt =
        (pSourceObj == 0) ? &DAT_009d3f88
                          : reinterpret_cast<std::uint32_t*>(FUN_00513b00(local_1c));
    self[0x19a] = pAlt[0];
    self[0x19b] = pAlt[1];
    self[0x19c] = pAlt[2];
    self[0x19d] = pAlt[3];

    self[0x1a2] = arg4;
    self[0x1a4] = pTfid[0];
    self[0x1a5] = pTfid[1];
    self[0x1a6] = pTfid[2];
    self[0x1a7] = pTfid[3];
    self[0x1aa] = arg7;
    self[0x1a8] = reinterpret_cast<std::uint32_t>(FUN_0058ab60(arg7));

    // Validate target against embedded skill blob; notify flag = 1
    // Accept → AttachOwner(pTarget)  [NOT pSourceObj]; period from +0x3C floor 0→1
    int ok = Skill_ValidateTargetForSkill(
        reinterpret_cast<void*>(self + 9), pTarget, reinterpret_cast<void*>(1));
    if (static_cast<char>(ok) != '\0') {
        CVOGHBBase_AttachOwnerObject(self, pTarget);
        int owner = static_cast<int>(self[6]); // pOwnerObject @ +0x18 == pTarget
        self[0x19e] = *reinterpret_cast<std::uint32_t*>(owner + 0x160);
        self[0x19f] = *reinterpret_cast<std::uint32_t*>(owner + 0x164);
        self[0x1a0] = *reinterpret_cast<std::uint32_t*>(owner + 0x168);
        self[0x1a1] = *reinterpret_cast<std::uint32_t*>(owner + 0x16c);
        self[2] = self[0x10]; // +0x08 ← +0x40
        int period = static_cast<int>(self[0xf]); // +0x3C
        if (period == 0) {
            period = 1;
        }
        CVOGHBBase_SetPeriodAndCounter(self, period, true);
    }
    return self; // reject: no attach/period; still returns live this
}
