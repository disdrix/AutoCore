# Review B (skeptical / adversarial): `aa_006261e0` CVOGHBActivatePlayer_EndOrDestroy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006261e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-P dual B) |
| **Counterpart** | `reviews/A_aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_006261e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Identical to base `FUN_005083f0` | **Falsified** — pre-OnEnd when flag0==0; then **calls** base |
| 2 | Pre-calls OnEnd when flag0≠0 | **Falsified** — `jnz` skips vcall; base handles OnEnd |
| 3 | Single stack arg only | **Falsified** — `ret 8` + two pushes; base dual seals second flag |
| 4 | Decompiler one-arg base prototype means this is one-arg | **Noise** — base under-modeled; this leaf pushes two |
| 5 | Static code callers | **Falsified** — DATA vtbl only |
| 6 | Implements hard destroy itself | **Falsified** — no SEH / list remove; base tail owns |
| 7 | Product name proven | **Overstated** — structural `_Inferred` |
| 8 | OnEnd pre-call uses wrong slot | **Falsified** — `call [eax+0x14]` = sealed OnEnd slot |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 2 args + ret 8 | **High** | Stack corruption |
| Pre-OnEnd only on flag0==0 | **High** | Double OnEnd or missed host notify |
| Always chain base EndOrDestroy | **High** | Leaked HB / missed teardown |
| Product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live:
  if ((char)param_2 == 0) this->vtbl+0x14();
  FUN_005083f0(param_2, param_3);

bytes:
  53  8B 5C 24 08  84 DB  56  8B F1  75 05
  8B 06  FF 50 14
  8B 4C 24 10  51  53  8B CE  E8 → 005083f0
  5E  5B  C2 08 00
```

Clean **must not**:
- invert the flag0 pre-OnEnd test,
- drop second stack arg,
- reimplement base hard/soft TEARDOWN here,
- claim multi-site direct CALL graph.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_006261e0 — CVOGHBActivatePlayer_EndOrDestroy_Inferred
// thiscall: this=ECX. Args: flag_onEnd, flag_hard. ret 8.
unsafe void EndOrDestroy(CVOGHBBase* self, uint flagOnEnd, uint flagHard)
{
    if ((sbyte)(byte)flagOnEnd == 0) // retail tests low byte via BL
        CallVtbl14_OnEnd(self);
    CVOGHBBase_EndOrDestroy(self, flagOnEnd, flagHard);
}
// Ensure: flag0==0 still notifies host via OnEnd; flag0!=0 OnEnd once in base.
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/slot/pre-OnEnd policy; product English remains gap → **accept-with-gaps**.
