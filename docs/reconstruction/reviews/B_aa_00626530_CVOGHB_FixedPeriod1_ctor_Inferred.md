# Review B (skeptical / adversarial): `aa_00626530` CVOGHB_FixedPeriod1_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-O dual B) |
| **Counterpart** | `reviews/A_aa_00626530_CVOGHB_FixedPeriod1_ctor_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00626530.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ctor also Enqueues / Starts HB | **Falsified** — no such callees in body |
| 2 | Allocates its own 0x50 block | **Falsified** — no `operator_new` in leaf |
| 3 | Same as activate-player ctor (`006264e0`) | **Falsified** — different vtbl, size, period source, no host/flag writes |
| 4 | `__cdecl` / bare `ret` | **Falsified** — `C2 10 00` = ret 16 |
| 5 | Period comes from arg5 | **Falsified** — period hardcoded 1; arg5 → `+0x08` only |
| 6 | arg3/arg4 must be stored | **Falsified for this leaf** — unused; may be for parent/vtbl elsewhere |
| 7 | Product class confirmed on this VA | **Overstated** — no RTTI dual on ctor |
| 8 | Multiple construction factories | **Falsified** — single code xref |
| 9 | `param_1[2]` is byte flag | **Clarify** — dword at `+0x08` (`89 4E 08`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 4 args + ret 0x10 + return this | **High** | ABI break |
| Order base→vtbl→attach→+0x08→period1 | **High** | Lifecycle wrong |
| Sole xref + size 0x50 | **High** | Wrong factory model |
| Fixed period 1 | **High** | Wrong tick rate |
| Product class English | **Medium** | Naming only |
| arg3/arg4 meaning | **Open** | Parent contract only |
| Vtbl method bodies | **Out of scope** | Separate duals |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live:
  CVOGHBBase_ctor; *this = 009e3188; AttachOwner(param_2);
  this+8 = param_5; SetPeriod(1,true); return this;

bytes (abbrev):
  56 8B F1 E8→00508200  … C7 06 88 31 9E 00 E8→005083b0
  … 89 4E 08  6A 01 6A 01 E8→005081a0  8B C6 5E C2 10 00

parent site:
  new(0x50); FUN_00626530(owner, host+0x6d0, host+0x6e0, 1000)
```

Clean **must not**:
- Enqueue / Start / free,
- treat as activate-player twin (vtbl `009e3168`),
- feed arg5 into SetPeriod,
- invent stores of arg3/arg4,
- claim multi-site construction.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_00626530 — CVOGHB_FixedPeriod1_ctor_Inferred
// thiscall: this=ECX (0x50 at sole site). Args: pOwner, a3, a4, a5. ret 0x10. Returns this.
unsafe CVOGHBBase* Ctor(CVOGHBBase* self, void* pOwner, uint a3, uint a4, uint a5)
{
    CVOGHBBase_ctor(self);
    *(void**)self = (void*)0x009E3188;
    CVOGHBBase_AttachOwnerObject(self, pOwner);
    *(uint*)((byte*)self + 0x08) = a5;
    CVOGHBBase_SetPeriodAndCounter(self, period: 1, fTrue: 1);
    return self;
    // a3/a4 unused here
}
// Parent owns: new(0x50), any Enqueue/Start, use of host+0x6d0/+0x6e0.
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/fields/sole-xref; product class + unused-arg English remain gaps → **accept-with-gaps**.
