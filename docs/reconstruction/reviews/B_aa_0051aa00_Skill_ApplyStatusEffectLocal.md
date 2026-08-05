# Review B (skeptical / adversarial): `aa_0051aa00` Skill_ApplyStatusEffectLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh) |
| **Counterpart** | `reviews/A_aa_0051aa00_Skill_ApplyStatusEffectLocal.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Sends cast request / is LocalCastValidate | **Falsified** — local 0x2031 apply only |
| 2 | Always success | **Falsified** — return `2` / `0x11` paths |
| 3 | Local return `0x11` is wire status field | **Falsified** — wire status at `+0x14` read by Recv; this body never writes/reads `+0x14`; Recv wire-`0x11` never calls this unit |
| 4 | Clean `+0x130` skill placeholders are sealed | **Falsified** — residual maps to `+0x5fc` / `+0x614` via `sizeof(CVOGHBBase)==0x28` |
| 5 | `FUN_006061e0` is anonymous forever | **Falsified** — RTTI `CVOGHBWakeupSkill` |
| 6 | ApplyEffects is full authoritative combat | **Still limited** — client presentation/handler invoke; server truth elsewhere |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x2031 apply path | **High** | Missing status FX |
| Local vs wire `0x11` | **High** | Double-cancel / wrong remove |
| Skill byte map from overlay | **High** | Broken cancel/CD |
| WakeupSkill RTTI name | **Confirmed** | Wrong HB subclass port |
| ApplyEffects product name | Inferred only | Cosmetic |
| `+0x614` bit0 English | Tentative | Misnamed flag only |

---

## 3. Cross-check against raw

```
apply 0x2031: ensure skill; optional binding cancel; sim cast-again;
  build TFID heap; delay<1 ApplyEffectsOnTarget else CVOGHBWakeupSkill_ctor;
  return local status (Recv ignores).
Clean ≡ raw CF; residual closed overlay + helper names.
```

---

## 4. Surviving contract for AutoCore

```
// Recv:
if status == 0x11: remove active cast (vtbl+0x220); do NOT ApplyStatusEffectLocal
if status in {0, 'c'} and source resolved:
  ApplyStatusEffectLocal(source, packet, isLocalCaster)
  // ignore return

// ApplyStatusEffectLocal (delay often 0 on server success):
  materialize skill; maybe clear optimistic binding;
  if delay < 1: Skill_ApplyEffectsOnTarget_Inferred(...)
  else: new CVOGHBWakeupSkill(0x674) → enqueue world+0xe4ec → Start
```

---

## 5. Open questions

1. English for `skill+0x614` bit0.
2. Live status-apply capture (runtime matrix).
3. Product names for cast-counter helpers.

**Verdict:** **accept-with-gaps**
