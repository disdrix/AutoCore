# Function record: CVOGHBSkillBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005788d0` |
| **Canonical name** | `CVOGHBSkillBase_ctor` |
| **Prior** | `FUN_005788d0` / mistaken `CVOGHBSkillCast_ctor_Inferred` |
| **Address** | `0x005788d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Confirmed** — RTTI `".?AVCVOGHBSkillBase@@"` via COL `0x00aaede0` → type_info `0x00af8cec` on vtbl `PTR_FUN_009d3fdc` |
| **Completion status** | Named + dual residual strengthened 2026-07-29 (ValidateTarget attach sealed) |

## Purpose

Construct `CVOGHBSkillBase` heartbeat: `CVOGHBBase_ctor`, install skill-base vtbl, copy skill runtime blob, run `Skill_ValidateTargetForSkill` with **notify=1**; on accept **attach owner = target** and set period/counter. Type tag `+0x1c = 1` marks the HB for `Skill_ValidateTarget_HBSkillListener` RTTI.

## Signature (decompiler-derived + dual residual)

```c
CVOGHBSkillBase* __thiscall CVOGHBSkillBase_ctor(
    CVOGHBSkillBase* this,   // ECX
    void* pSourceObj,        // param_2 — TFID seed @ obj+0x160 (nullable)
    void* pSkillBlob,        // param_3 — skill runtime source (0x18c dwords)
    uint32_t arg4,           // param_4 → this+0x688
    void* pTarget,           // param_5 — ValidateTarget subject AND AttachOwner subject
    uint32_t* pTfid16,       // param_6 — 16-byte TFID → this+0x690..
    uint32_t arg7);          // param_7 → this+0x6a8; FUN_0058ab60 → this+0x6a0
```

**Important dual residual:** `pSourceObj` and `pTarget` are **distinct**. Source seeds TFID blocks only; attach/list-link uses **target**.

## Sealed layout (byte offsets)

| Offset | Dword | Field | Confidence |
|-------:|------:|-------|------------|
| `+0x00` | 0 | vtbl `PTR_FUN_009d3fdc` | **Confirmed** |
| `+0x08` | 2 | set from `this+0x40` on accept only | **Confirmed** |
| `+0x0C` | 3 | `nPeriodSentinel` via `SetPeriodAndCounter` | **Confirmed** |
| `+0x10` | 4 | `nPeriodCounter` (also set when flag true) | **Confirmed** |
| `+0x18` | 6 | `pOwnerObject` — AttachOwner stores **pTarget** | **Confirmed** |
| `+0x1C` | 7 | HB type tag **`1`** (skill base) | **Confirmed** |
| `+0x20` | 8 | base `cStopped` (listener requires `== 0`) | High (base + listener) |
| `+0x24` | 9 | embedded skill runtime blob start | **Confirmed** |
| `+0x24 + 0x630` | — | end of blob copy (`0x18c` dwords) | **Confirmed** |
| `+0x3C` | `0xF` | period source (from blob); `0 → 1` floor | **Confirmed** |
| `+0x40` | `0x10` | source of accept-path write to `+0x08` | **Confirmed** |
| `+0x658` | `0x196` | source TFID ×4 from `pSourceObj+0x160` or sentinel | **Confirmed** |
| `+0x668` | `0x19A` | secondary TFID ×4 (`FUN_00513b00` / sentinel) | **Confirmed** |
| `+0x678` | `0x19E` | attached-owner TFID ×4 from `pOwner+0x160` (**accept only**) | **Confirmed** |
| `+0x688` | `0x1A2` | `arg4` store | **Confirmed** (role Tentative) |
| `+0x690` | `0x1A4` | `pTfid16[0..3]` | **Confirmed** |
| `+0x6A0` | `0x1A8` | `FUN_0058ab60(arg7)` heap ptr | **Confirmed** (product name open) |
| `+0x6A4` | `0x1A9` | byte cleared to 0 | **Confirmed** |
| `+0x6A8` | `0x1AA` | `arg7` store | **Confirmed** (role Tentative) |
| `+0x6B0` | `0x1AC` | three dwords zeroed | **Confirmed** |

**Invalid TFID sentinel** `DAT_009d3f88`: `{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}` (16B) — used when `pSourceObj == null`.

## Sealed control flow

```
CVOGHBBase_ctor(this)
this.vtbl = PTR_FUN_009d3fdc          // CVOGHBSkillBase
FUN_0054f3c0()                        // skill-field zeroer on ECX=this (mostly overwritten next)
zero tail (0x1ac..0x1ae, byte 0x1a9); this[+0x1c] = 1
memcpy skill blob → this+0x24 (0x18c dwords)
seed TFID blocks from pSourceObj / FUN_00513b00 / sentinel
store arg4, pTfid16, arg7, FUN_0058ab60(arg7)
ok = Skill_ValidateTargetForSkill(this+0x24, pTarget, notify=1)
if (ok):
    CVOGHBBase_AttachOwnerObject(this, pTarget)   // owner list @ target+0xB0
    copy this[+0x18]+0x160 → this+0x678 TFID
    this[+0x08] = this[+0x40]
    period = this[+0x3C]; if period==0: period=1
    CVOGHBBase_SetPeriodAndCounter(this, period, true)
return this   // reject path: no attach, no period; still returns this
```

## ValidateTarget attach dual residual (sealed)

| Claim | Level | Evidence |
|---|---|---|
| Call is `(skill=this+0x24, target=pTarget, notify=1)` | **Confirmed** | live decompile call site |
| Wrapper polarity 1=accept / 0=reject | **Confirmed** | `aa_00553650` dual; ctor branches on `(char)ok != 0` |
| Accept → AttachOwner(**pTarget**) | **Confirmed** | same `param_5` |
| Accept does **not** AttachOwner(pSourceObj) | **Confirmed** | `param_2` never passed to Attach |
| Type tag `+0x1c==1` required by HBSkillListener | **Confirmed** | `0x005532e0` gate before RTTI cast |
| notify=1 enables listener `vtbl+0x18` when handler returns 2 | **High** | listener reads flag at ctx+9; ctor forces 1 |
| Reject leaves `pOwner==0`, periods 0 | **Confirmed** | no Attach/SetPeriod; base ctor zeros |
| Reject still returns live `this` | **Confirmed** | fall-through `return param_1` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005788d0_FUN_005788d0.md` (+ 2026-07-29 RTTI append)
- Annotated: `docs/reconstruction/raw/aa_005788d0_CVOGHBSkillBase_ctor.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_ctor.cpp`
- Dual: `reviews/A|B_aa_005788d0_CVOGHBSkillBase_ctor.md`

## Callers / callees

- **Callers (14 subclass ctors, Ghidra):** `0x00614c80`, `0x00614dc0`, `0x00617ad0`, `0x00617df0`, `0x00618180`, `0x0061c590`, `0x006202f0`, `0x00621350`, `0x00621700`, `0x006223c0`, `0x006226a0`, `0x00626240`, `0x006270b0`, `0x00650f50` — each installs subclass vtbl after base.
- **Sibling:** `FUN_00578830` — same vtbl; no blob/ValidateTarget; `AttachOwner(null)` + sentinel attached TFID.
- **Callees:** `CVOGHBBase_ctor`, `FUN_0054f3c0`, `FUN_00513b00`, `FUN_0058ab60`, `Skill_ValidateTargetForSkill`, `CVOGHBBase_AttachOwnerObject`, `CVOGHBBase_SetPeriodAndCounter`

## Confidence

| Claim | Level |
|---|---|
| Product class name from RTTI | **Confirmed** |
| ValidateTarget gate on construct (notify=1) | **Confirmed** |
| Attach subject = target (not source) | **Confirmed** |
| Type tag + period accept path | **Confirmed** |
| Full skill-blob field glossary | Tentative (open) |
| Product English for arg4 / arg7 / `FUN_0058ab60` | Tentative |
| Reject-path caller free contract | Mild open (static: object returned; free not in unit) |
