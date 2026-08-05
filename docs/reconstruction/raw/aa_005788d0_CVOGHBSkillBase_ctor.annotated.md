# Annotated low-level: CVOGHBSkillBase_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_005788d0` |
| VA | `0x005788d0` |
| Canonical name | `CVOGHBSkillBase_ctor` |
| Prior | `FUN_005788d0` |
| System | skills-abilities |
| Date | 2026-07-29 (dual residual strengthen) |

## Machine-level notes

- **RTTI sealed:** COL before vtable `PTR_FUN_009d3fdc` at `0x00aaede0` → type descriptor `0x00af8cec` → `".?AVCVOGHBSkillBase@@"` (live re-read).
- Sibling default-ish ctor `FUN_00578830` and dtor/related share the same vtable DATA xrefs; sibling does **not** ValidateTarget (AttachOwner null + sentinel TFID).
- Derived skill HBs (14 callers, e.g. `FUN_00614dc0`) call this then replace vtbl with subclass PTR.
- `param_1+9` / `this+0x24` is the embedded skill-runtime blob start (`0x18c` dwords = `0x630` bytes).
- `Skill_ValidateTargetForSkill(this+0x24, target, 1)` — notify flag **1** so listener may call HB `vtbl+0x18` on handler code 2.
- **Attach subject = target (`param_5`)**, not source (`param_2`). Source only seeds TFID blocks.
- Type tag `this+0x1c = 1` required by `Skill_ValidateTarget_HBSkillListener` before RTTI to `CVOGHBSkillBase`.
- Accept period: `this+0x3C` (blob-relative `+0x18`), floor `0→1`; `SetPeriodAndCounter(..., true)` writes `+0x0C` and `+0x10`.
- Invalid TFID sentinel `DAT_009d3f88` = `{0xFFFFFFFF,0xFFFFFFFF,0,0}`.

## Pseudocode (annotated)

```c
// CVOGHBSkillBase *this,
//   pSourceObj  — TFID seed @ +0x160 (nullable),
//   skillBlob*,
//   arg4,
//   pTarget     — ValidateTarget + AttachOwner subject,
//   tfid16*,
//   arg7
undefined4 * __thiscall
CVOGHBSkillBase_ctor(undefined4 *this, int pSourceObj, undefined4 *skillBlob,
                     undefined4 arg4, void *pTarget, undefined4 *pTfid, undefined4 arg7)
{
  CVOGHBBase_ctor(this);
  *this = &PTR_FUN_009d3fdc;          // CVOGHBSkillBase vtbl (RTTI)
  FUN_0054f3c0();                      // skill-field zeroer (largely overwritten by memcpy)
  // zero trailing fields; type tag this[+0x1c] = 1 (skill HB type)
  // memcpy skillBlob → this+0x24 (0x18c dwords)
  // store source TFID @ this+0x658.. from pSourceObj+0x160 (or DAT_009d3f88)
  // store second TFID block @ this+0x668.. (FUN_00513b00 / sentinel)
  // arg4 @ +0x688; pTfid @ +0x690; arg7 @ +0x6a8; FUN_0058ab60(arg7) @ +0x6a0
  // ValidateTarget(skill_runtime=this+0x24, pTarget, notify=1)
  // on accept:
  //   AttachOwner(pTarget)            // NOT pSourceObj
  //   copy owner TFID → this+0x678
  //   this+0x08 = this+0x40
  //   period = this+0x3C or 1; SetPeriodAndCounter(this, period, true)
  // reject: return this with no attach/period
  return this;
}
```

## Sealed dual residual (ValidateTarget attach)

| Claim | Level |
|---|---|
| notify=1 call site | **Confirmed** |
| AttachOwner(target) | **Confirmed** |
| Type tag +0x1c=1 ↔ listener gate | **Confirmed** |
| Period only on accept | **Confirmed** |
| Reject returns live this | **Confirmed** |

## Open questions

- Full layout of the 0x18c-dword skill blob overlay inside CVOGHBSkillBase (field glossary shared with other skill units).
- Product English of `arg4` / `arg7` / `FUN_0058ab60` heap payload (behavior: 0x4b0 alloc, 300-dword seeded table).
- Product meaning of accept-path `this+0x08 = this+0x40`.
- Whether reject path leaves a half-scheduled HB that callers must free (static: returned; free not in unit).
