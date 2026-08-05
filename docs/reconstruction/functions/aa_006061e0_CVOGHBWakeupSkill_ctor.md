# Function record: CVOGHBWakeupSkill_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006061e0` |
| **Canonical name** | `CVOGHBWakeupSkill_ctor` |
| **Ghidra name** | `FUN_006061e0` |
| **Address** | `0x006061e0`–`0x00606353` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / heartbeat |
| **Completion status** | **Dual A/B sealed 2026-07-29 W19-G** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Class** | `CVOGHBWakeupSkill` — RTTI **Confirmed** `".?AVCVOGHBWakeupSkill@@"` @ `0x00af48f0` |
| **Vtbl** | `PTR_FUN_009de7b4` |
| **Object size** | `0x674` (`operator_new` at callers) |

## Alias

- Ghidra / scaffold: `FUN_006061e0`
- Prior auto-name noise: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006061e0` (**reject**)

## Purpose

Construct delayed skill-apply heartbeat: base ctor → install CVOGHBWakeupSkill vtbl → embed skill blob at `+0x24` → seed world/flag/pos/seed/TFID vector → AttachOwner → append TFID list + invalid sentinel. Used when ApplyStatusEffectLocal delay ≥ 1 (and ApplyLocalById sibling path).

## Signature

```c
void* /*CVOGHBWakeupSkill**/ __thiscall CVOGHBWakeupSkill_ctor(
    void* thisHb /* ECX */,
    uint32_t skillTypeOrPeriodSeed,
    void* hostObject,
    uint32_t* skillBlobSrc,  // 0x630 B / 0x18c dwords
    void* world,
    int* tfidList,           // 16 B elems, invalid-terminated
    void* pos,
    uint32_t seed,
    uint32_t flagWord);      // low byte → +0x658
// ret 0x20
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006061e0_FUN_006061e0.md`
- Annotated: `docs/reconstruction/raw/aa_006061e0_FUN_006061e0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBWakeupSkill_ctor.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_006061e0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_006061e0_CVOGHBWakeupSkill_ctor.md`
- Review B: `docs/reconstruction/reviews/B_aa_006061e0_CVOGHBWakeupSkill_ctor.md`
- Function alias record: `docs/reconstruction/functions/aa_006061e0_FUN_006061e0.md`

## Callers / callees

| Direction | VA / name |
|---|---|
| Caller | `Skill_ApplyStatusEffectLocal` @ `0x0051ae04` |
| Caller | `Skill_ApplyLocalById_Inferred` / `FUN_00514e70` @ `0x00514f7d` |
| Callee | `CVOGHBBase_ctor` |
| Callee | `CVOGHBBase_AttachOwnerObject` |
| Callee | `FUN_004cbfc0` (vector grow/insert) |
| Callee | `FUN_00608720` (16-byte TFID fill) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** (≡ raw ≡ bytes) |
| Class RTTI name | **Confirmed** |
| Ctor role | **Confirmed** |
| Field seed map for Fire dual offsets | **High** |
| `param_2` / `param_9` product English | **Inferred** / open |
| Types on TFID vector helper | **High** layout; helper names leave-FUN |

## Gaps

1. Product English for type/period seed and flag byte.
2. Full dual of `FUN_004cbfc0` / `FUN_00608720` (not owned here).
3. Runtime / bit-exact image diff.
