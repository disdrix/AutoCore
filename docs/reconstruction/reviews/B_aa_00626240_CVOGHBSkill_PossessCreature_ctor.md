# Review B (skeptical / adversarial): `aa_00626240` CVOGHBSkill_PossessCreature_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R11-021 dual B) |
| **Counterpart** | `reviews/A_aa_00626240_CVOGHBSkill_PossessCreature_ctor.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00626240.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Class name is `Named_VOG_DEBUG_STOP` / product "debug stop" | **Falsified** — string is assert only; RTTI is `CVOGHBSkill_PossessCreature` |
| 2 | Ctor allocates `0x6f0` itself | **Falsified** — no `operator_new` in leaf; caller pushes `0x6f0` |
| 3 | Null creature cast aborts / does not return this | **Falsified** — falls through to `mov eax,esi` after `FUN_007a4480` |
| 4 | `__cdecl` / bare `ret` | **Falsified** — `C2 18 00` = ret 24 |
| 5 | Dyn-cast subject is `param_2` (source) not `param_5` | **Falsified** — `push edi` after `mov edi,[esp+…]` tracks `param_5` |
| 6 | Parent is generic `CVOGHBBase_ctor` only | **Falsified** — relative call seals `0x005788d0` skill base |
| 7 | Object size is base `0x6c0` | **Falsified for subclass** — type table + factory use **0x6f0** |
| 8 | Multiple full-arg construction sites | **Falsified for code xrefs** — single UNCONDITIONAL_CALL; other sites are default/vtable DATA only |
| 9 | `param_1+0x1b2` is dword at `+0x1b2` | **Clarify** — decomp dword* index → byte `+0x6c8`; sealed by `88 9E C8 06 00 00` |
| 10 | This leaf Enqueues / Starts HB | **Falsified** — no such callees |
| 11 | Ghidra surface `undefined FUN_00626240(void)` is ABI | **Noise** — trust body + `ret 0x18` + stack |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 6 args + ret 0x18 + return this | **High** | ABI break |
| Order base→vtbl→clears→cast→optional assert | **High** | Lifecycle / creature binding wrong |
| RTTI class string | **Confirmed** | Naming only if wrong (it is not) |
| Size 0x6f0 | **High** (caller/registry) | Heap OOB on port |
| `+0x6c0` creature binding | **High** | Possess target null |
| Assert non-fatal | **High** | Wrong error model |
| `+0x6c4` post-ctor meaning | **Medium** | Mis-model secondary host |
| Non-OWN vtbl English | **Out of scope** | Separate duals |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live:
  CVOGHBSkillBase_ctor(p2..p7);
  *this = 0x009d1ba4;
  *(this+0x6c8)=0; *(this+0x6c4)=0; *(this+0x6c9)=0;
  c = __RTDynamicCast(p5, 0, ClonedObjectBase, Creature, 0);
  *(this+0x6c0)=c; if (!c) FUN_007a4480(0,"VOG_DEBUG_STOP");
  return this; // ret 0x18

bytes (abbrev):
  … E8→005788d0  33 DB
  C7 06 A4 1B 9D 00
  88 9E C8 06 00 00  89 9E C4 06 00 00  88 9E C9 06 00 00
  E8→__RTDynamicCast  89 86 C0 06 00 00  75 0e
  68 44 58 A1 00  53  E8→007a4480
  8B C6 … C2 18 00
```

Clean **must not**:
- invent product name from `"VOG_DEBUG_STOP"`,
- allocate inside the leaf,
- treat cast-fail as non-returning,
- invert dyn-cast subject,
- claim multi full-ctor call sites,
- Enqueue/Start,
- dual non-OWN vtbl bodies in this unit.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_00626240 — CVOGHBSkill_PossessCreature_ctor
// thiscall: this=ECX (0x6f0). Args: src, skillBlob, arg4, target, tfid, arg7.
// ret 0x18. Returns this. Cast-fail still returns this after debug helper.
unsafe void* Ctor(void* self, void* pSource, void* pSkillBlob, uint arg4,
                  void* pTarget, void* pTfid, uint arg7)
{
    CVOGHBSkillBase_ctor(self, pSource, pSkillBlob, arg4, pTarget, pTfid, arg7);
    *(uint*)self = 0x009d1ba4u;
    *((byte*)self + 0x6c8) = 0;
    *(uint*)((byte*)self + 0x6c4) = 0;
    *((byte*)self + 0x6c9) = 0;
    var creature = RTDynamicCast_Creature(pTarget);
    *(void**)((byte*)self + 0x6c0) = creature;
    if (creature == null) VOG_DEBUG_STOP(0);
    return self;
}
```

**Port notes:** Preserve non-fatal cast assert. Do not shrink object below `0x6f0`. Do not merge with ActivatePlayer HB (`0x2c` / vtbl `0x009e3168`) or Virus skill (`0x6e0` / vtbl `0x009d14bc`).

---

## 5. Verdict

**accept-with-gaps** — adversarial checks leave CF/ABI/RTTI/size/fields intact; remaining gaps are non-OWN method English and runtime confirmation.
