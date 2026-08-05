# Review B (skeptical / adversarial): `aa_00799940` NDXmlWrapper_CtorCoCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00799940_NDXmlWrapper_CtorCoCreate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Soft-fail returns null on CoCreate fail | `_CxxThrowException` after log | **Falsified** — **throws** |
| 2 | Skill-only API | NDUI / SpecialFX / skill load callers | **Falsified** — shared |
| 3 | Creates both COM slots +4 and +8 | Only CoCreate into `this+4` (`ppv=param_1+1`); +8 stays 0 | **Only +4 filled here** |
| 4 | `CLSCTX_ALL` / remote | `push 1` = INPROC_SERVER only | **Falsified** if claimed broader |
| 5 | Method at +0xFC is Release | Arg `0` + large offset — not IUnknown slot | **Not Release** |
| 6 | Returns HRESULT in EAX on success | Returns **this** pointer | **Object* return** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Throw on failure | **High** | Ports that ignore exceptions hang half-init |
| CoCreate into +4 only | **High** | Wrong field for iface |
| Shared NDXml infra | **High** | Over-scope skill ownership |
| IID product identity | **Low** | Wrong COM dependency |

---

## 3. Surviving contract for AutoCore

```csharp
NDXmlWrapper* NDXmlWrapper_CtorCoCreate(NDXmlWrapper* self)
{
    self->vtbl = NDXmlWrapper_vftable;
    self->ComA = self->ComB = null;
    self->Field3 = self->Buffer = null;
    var hr = CoCreateInstance(clsid_a0f0e0, null, CLSCTX_INPROC_SERVER, iid_a0f0f0, out self.ComA);
    if (hr >= 0) {
        self.ComA.Method_0xFC(0);
        return self;
    }
    Log("VOG_DEBUG_STOP");
    throw; // match retail — do not return null quietly
}
```

**Port traps:**

- Returning null instead of throwing on CoCreate fail.
- Putting COM pointer at +8.
- Assuming MSXML free-threaded / out-of-proc.

---

## 4. Residual gaps

1. CLSID/IID name resolution via `read_memory` 16 B each (follow-up).
2. Method `+0xFC` product name.

**Verdict:** **accept-with-gaps**
