# Review B (skeptical / adversarial): `aa_007b5dd0` NDUIWindow_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5dd0` |
| **VA** | `0x007b5dd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b5dd0_NDUIWindow_BaseCtor_Inferred.md` |
| **Evidence** | Live decompile ≡ raw; callers CreateChildWidgets + subclass ctors |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Loads XML skins | **Falsified** | No string refs; no vtbl+0x28; pure field init |
| 2 | Attaches child to parent | **Falsified** | Parent attach is caller `vtbl+0xa8` after return |
| 3 | Stub / empty | **Falsified** | 292 insn; CS; QPC helper; large zero/fill |
| 4 | Server-side | **Falsified** | Client UI ctor fan-in only |
| 5 | Subclass-specific button logic | **Falsified** | Subclasses call this then overwrite vtbl |
| 6 | Clean invents CS/timer | **Falsified** | In live decompile |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base ctor role | **High** | Wrong factory taxonomy |
| Vtbl `00a960ac` | **High** | Wrong type hierarchy |
| Field English | **Tentative** | Layout port |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
widget = NDUIWindow_BaseCtor(mem, cookie):
  super FUN_00759860
  vtbl = base NDUI
  default colors / flags / dims / CS / timer
  store cookie
  return widget
```

Callers allocate `0x488` (or subclass larger) then load XML after attach.

**Verdict:** **accept-with-gaps**
