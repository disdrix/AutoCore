# Review B (skeptical / adversarial): `aa_006264e0` CVOGHBActivatePlayer_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006264e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-G dual B) |
| **Counterpart** | `reviews/A_aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_006264e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ctor also Enqueues / Starts HB | **Falsified** — parent does Enqueue+Start after return |
| 2 | Allocates its own 0x2c block | **Falsified** — no `operator_new` in leaf; caller owns size |
| 3 | `__cdecl` / bare `ret` | **Falsified** — `C2 0C 00` = ret 12 |
| 4 | `param_3` is host not owner | **Falsified** — AttachOwnerObject takes `param_3`; parent passes player as owner, host as `param_4` |
| 5 | Period 0 means disabled | **Falsified** — clamp forces **1** |
| 6 | Product class confirmed on this VA | **Overstated** — no RTTI dual; name from activate parent role |
| 7 | Base size 0x28 is full object | **Falsified for this subclass** — caller `new(0x2c)`; writes `+0x28` |
| 8 | Multiple construction factories | **Falsified** — single code xref |
| 9 | Ghidra empty prototype is ABI | **Noise** — trust body + stack offsets |
| 10 | `param_1[2]` / dword index confuses byte `+0x28` | **Clarify** — decomp `param_1+10` is dword* arithmetic → `+0x28`; sealed by `C6 46 28 00` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 3 args + ret 0xC + return this | **High** | ABI break |
| Order base→vtbl→attach→fields→period→host | **High** | Lifecycle / owner list wrong |
| Sole caller + size 0x2c | **High** | Wrong factory model |
| Period min 1 | **High** | Zero-period spin / stuck |
| Product class English | **Medium** | Naming only |
| periodSrc+0x1c meaning | **Medium** | Mis-seed period twin |
| Vtbl method bodies | **Out of scope** | Separate duals |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live:
  CVOGHBBase_ctor; *this = 009e3168; AttachOwner(param_3);
  *(this+0x28)=0; this+8 = *(param_2+0x1c);
  period = *(param_2+0x18) || 1; SetPeriod(period,true);
  this+0x24 = param_4; return this;

bytes (abbrev):
  56 8B F1 E8→00508200  … C7 06 68 31 9E 00 E8→005083b0
  C6 46 28 00  … period clamp … E8→005081a0
  89 56 24  8B C6  5E  C2 0C 00

parent site:
  new(0x2c); FUN_006264e0(host+0x24, player_obj, host)
```

Clean **must not**:
- Enqueue / Start / free,
- invert owner vs host args,
- allow period 0 through SetPeriod,
- claim multi-site construction,
- invent null-`this` guards (retail has none).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_006264e0 — CVOGHBActivatePlayer_ctor_Inferred
// thiscall: this=ECX (0x2c). Args: periodSrc, pOwner, pHost. ret 0xC. Returns this.
unsafe CVOGHBBase* Ctor(CVOGHBBase* self, void* periodSrc, void* pOwner, void* pHost)
{
    CVOGHBBase_ctor(self);
    *(void**)self = (void*)0x009E3168;
    CVOGHBBase_AttachOwnerObject(self, pOwner);
    *((byte*)self + 0x28) = 0;
    *(uint*)((byte*)self + 0x08) = *(uint*)((byte*)periodSrc + 0x1C);
    int period = *(int*)((byte*)periodSrc + 0x18);
    if (period == 0) period = 1;
    CVOGHBBase_SetPeriodAndCounter(self, period, true: 1);
    *(void**)((byte*)self + 0x24) = pHost;
    return self;
}
// Parent must: host+0x6c4 = action; Enqueue; Start — not this unit.
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/fields/sole-caller; product class + periodSrc+0x1c English remain gaps → **accept-with-gaps**.
