# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Kill_Eval` @ `0x00613910`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen; prior `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |
| **Verdict** | **accept** on formula + provenance for Eval; runtime open |
| **Scratch** | `tmp/a_00613910.md` |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Eval increments progress | **Falsified** — pure compare; no stores (asm) |
| 2 | Required kills at req+0x50 like UseItem | **Falsified** — Kill uses **+0x18** (CVTSI2SS) |
| 3 | param_2 is character and required | **Falsified** — unused; only stack arg2 (state) loaded |
| 4 | Strict `<` fails at exact count | **Falsified** — COMISS + JC only on progress **<** required → equality completes |
| 5 | Only 0x2071 can satisfy Eval | **Falsified as Eval rule** — any float ≥ threshold works; writers are external |
| 6 | Eval applies kill CBID/level filters | **Falsified** — zero filter code; Precheck owns match |
| 7 | Precheck bump then Eval is undefined | **Falsified** — Eval is pure read; Precheck also gates on Eval already-true |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formula + offsets + polarity | **High / Confirmed** (asm) | Never complete kill objectives |
| param_2 unused | **High / Confirmed** | Wrong thiscall framing |
| Progress writer identity | **High** for layout; writers external | HUD/server desync if server slots wrong — not Eval bug |
| Absolute vs delta *inside Eval* | N/A sealed | N/A |
| Runtime observation | Open | Policy |

---

## 3. Surviving contract for AutoCore

```
Kill_Eval(req, _, state):
  slot     = *(u8*)(req + 0x08)
  required = (float)*(i32*)(req + 0x18)
  progress = *(f32*)(state + 4 + slot * 4)
  return progress >= required ? 1u : 0u
```

Do **not** implement kill target matching in Eval.  
Do **not** increment progress in Eval.  
Port threshold only; authority of slot values is server `0x2071` + optional client Precheck optimism.

---

## 4. Open questions (after residual)

1. ~~Confirm RecvObjectiveState same slot layout~~ **Closed** — `piVar4[1..4]` absolute.
2. ~~Precheck bump interaction~~ **Closed** for Eval; Precheck early-calls Eval.
3. Runtime kill → slot capture (still open).
4. Precheck default addend float (owned by `aa_00613b50`).

**Verdict:** **accept** on formula; progress provenance **sealed as dual-writer / pure-read**. Runtime/diff remain open policy.
