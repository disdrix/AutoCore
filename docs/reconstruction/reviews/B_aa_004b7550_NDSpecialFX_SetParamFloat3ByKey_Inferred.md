# Review B (skeptical / adversarial): `aa_004b7550` NDSpecialFX_SetParamFloat3ByKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7550` |
| **VA** | `0x004b7550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b7550_NDSpecialFX_SetParamFloat3ByKey_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Signature is `(this, float*)` only | Decompiler 2-param display | **Falsified** — key at `Stack[0x8]`; callers pass `(&vec, key)` |
| 2 | Inserts new map node if missing | lower_bound miss path | **Falsified** — miss is silent no-op (no insert) |
| 3 | LevelUp-only helper | Scaffold alias | **Falsified** — water FX, weapon fire, drive, combat xrefs |
| 4 | Writes unscaled raw vec | Could skip scale | **Falsified** — always multiplies by entry `+8/+c/+10` |
| 5 | State `0` means “active / done” | Could be complete flag | **Countered by `004b75d0`** — modes treat `0` as not-yet-resolved / skip gate; update sets `1`/`2` |
| 6 | Free function on weapon | ECX is weapon | **Falsified** — ECX is FX host (`+0x224` map); weapons call with FX `this` after `004ec010` / embedded controller |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Keyed map write CF | **High** | FX params silent drop |
| No insert on miss | **High** | Assume auto-create keys |
| Scale contract | **High** | Wrong magnitudes |
| Global key enum | Open | Wrong field English only |
| Product name | Tentative | Cosmetic |

---

## 3. Surviving contract

```
// thiscall; no allocate
void SetParamFloat3ByKey(fx, const float *v, int key) {
  it = map_lower_bound(fx->map@0x224, key);
  if (it == fx->mapEnd@0x228) return;
  e = it->payload;                 // *(it+0x10)
  e->v = v * e->scale;             // +14..+1c *= +8/+c/+10
  e->state = 0;                    // +0x20
}
```

---

## 4. Falsifications locked in

- **Reject** LevelUp-only scaffold as role label.
- **Reject** two-arg decompiler signature without key.
- **Reject** treating miss as create/insert.
- **Reject** “state=0 means finished.”

---

## 5. Open questions

1. Authoritative key dictionary (script-side NDSpecialFX XML).
2. Who inserts map nodes (parser / `FUN_004a4fa0` family) — not this unit.

**Verdict:** **accept-with-gaps**
