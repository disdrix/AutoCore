# Review B (skeptical / adversarial): `aa_00574910` ConvoyRoster_Unlock_NoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574910` |
| **VA** | `0x00574910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create**) |
| **Counterpart** | `reviews/A_aa_00574910_ConvoyRoster_Unlock_NoOp_Inferred.md` |
| **Verdict** | **accept-with-gaps** — empty body + sole caller sealed; “unlock” product word open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Real LeaveCriticalSection | Invent unlock body | **Falsified** — `c3` only |
| 2 | Body includes neighbor `lea [ecx+0x1a4]` | Bad function bounds | **Falsified** — Ghidra body end = entry; pad `cc` then other code |
| 3 | Same VA as Lock / merge pair | Collapse | **Falsified** — `00574900` vs `00574910` |
| 4 | `ret 4` / stack arg | ABI confuse | **Falsified** — pure `c3` |
| 5 | Performs roster walk | Misread next function | **Falsified** — no loop in body |
| 6 | Multiple callers | Over-general API | **Falsified** — **1** xref |
| 7 | Required for XP correctness | Must implement | **Falsified for this image** — omittable |
| 8 | Product name sealed | Over-promote | **Sustained** — placement only |
| 9 | Unlock runs *before* count | Order reverse | **Falsified** — CALL after award loop |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Machine `c3` | **High** | Invented leave side effects |
| Function bounds 1 byte | **High** | Absorb neighbor code |
| Sole caller + exit position | **High** | Wrong port sequence |
| “Unlock” English | **Low / Tentative** | Bad NAMING |
| Historical CS leave | **Tentative** | Doc color |

---

## 3. Cross-check

```text
// 0x00574910: c3
void ConvoyRoster_Unlock_NoOp_Inferred(/* optional this ignored */)
{
  return;
}

// Do not treat bytes at 0x00574920 as this function.
```

---

## 4. Surviving contract for AutoCore

```
ConvoyRoster_Unlock_NoOp_Inferred():
  // retail: RET only
  // Port: omit OR empty stub after convoy award loop
  // Pair: after Lock_NoOp + CountEligible + slot awards
  // Do NOT invent LeaveCriticalSection or roster writes
```

**Port tests:** Omitting CALL does not change awards; do not merge with GetMember or Count.

---

## 5. Open questions

1. PDB name.
2. Whether enter/leave were ever non-empty in another build.
3. Runtime (policy).

**Verdict:** **accept-with-gaps** — hidden-body, bounds, and multi-caller attacks **closed**; product label inferred.
