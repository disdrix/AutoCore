# Function record: CVOGHBSkill_OnHit_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617ad0` |
| **Canonical name** | `CVOGHBSkill_OnHit_ctor` |
| **Prior** | `FUN_00617ad0` / retired `Named_CalleeOf_Named_VOG_DEBUG_STOP_00617ad0` |
| **Address** | `0x00617ad0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Confirmed** — RTTI `".?AVCVOGHBSkill_OnHit@@"` via COL `0x00aadbc4` → type_info `0x00af1d60` on vtbl `PTR_FUN_009d0f1c` |
| **Completion status** | Named + dual R11-012 sealed 2026-08-05 (**accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

OnHit skill-HB constructor over `CVOGHBSkillBase`: install product vtbl, copy optional truncated float seed from skill blob `+0x4c` into HB tail `+0x6c0` with enable `+0x6c4`.

## Signature

```c
CVOGHBSkill_OnHit* __thiscall CVOGHBSkill_OnHit_ctor(
    CVOGHBSkill_OnHit* this,
    void* pSourceObj,
    void* pSkillBlob,
    uint32_t arg4,
    void* pTarget,
    uint32_t* pTfid,
    uint32_t arg7);
```

## Sealed layout (OnHit tail)

| Offset | Field | Confidence |
|-------:|-------|------------|
| `+0x00` | vtbl `PTR_FUN_009d0f1c` | **Confirmed** |
| `+0x6c0` | int seed from `skillBlob+0x4c` (if ≠0) | **Confirmed** store |
| `+0x6c4` | enable byte | **Confirmed** |
| size | `0x6d0` | **High** |

## Control flow

```
CVOGHBSkillBase_ctor(this, source, blob, arg4, target, tfid, arg7)
this.vtbl = PTR_FUN_009d0f1c
if (*(float*)(blob+0x4c) != 0.0f):
    this[+0x6c4] = 1
    this[+0x6c0] = CVTTSS2SI(blob+0x4c)
else:
    this[+0x6c4] = 0
return this   // ret 0x18
```

## Dual

| Path | File | Verdict |
|------|------|---------|
| A | `reviews/A_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` | accept-with-gaps |
| B | `reviews/B_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` | accept-with-gaps |

## Gaps

- Product English for `skillBlob+0x4c` / `+0x6c0`
- Flag=0 leaves `+0x6c0` unwritten
- Caller/subclass duals out of OWN scope
- Runtime / bit-exact open
