# Review B (skeptical / adversarial): `aa_00515520` CVOGObject_ComputeOutcomeRolls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00515520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-M) |
| **Counterpart** | `reviews/A_aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md` |
| **Verdict** | **accept** on ABI/virtual/6-channel spine; **needs-more-evidence** on product English + full arg map |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Direct CODE callers | **Falsified** — 0 CODE; 26 DATA only |
| 2 | g_flMultiKillCountBlend proves multi-kill | **Falsified** — shared 0.1f pool |
| 3 | ret 4 / few stack args | **Falsified** — C2 28 00 = 10 dwords |
| 4 | Same as CalculateAndAwardKillXP | **Falsified** — different VA 004d80b0 |
| 5 | unaff_* are real inputs | **Overstated** — decompiler artifacts |
| 6 | Product name retail | **Overstated** — _Inferred only |
| 7 | Always positive return | **Falsified** — early return 0; final clamp |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ret 0x28 / thiscall | **High** | Stack smash |
| Virtual dispatch only | **High** | Wrong call graph |
| 6-channel roll + RNG | **High** | Wrong math |
| Full formal names | **Medium** | Arg shuffle |
| Product English | **Tentative** | Docs only |

---

## 3. Surviving contract

```
// Virtual outcome rolls (many CVOGObject vtables):
// ret 0x28 thiscall; 6 short channels + RNG/seed table;
// optional reaction flags; return max(0, int)
```

Do not merge with CVOGCombat_CalculateAndAwardKillXP (0x004d80b0). Do not treat shared float pool names as product multi-kill.

---

## 4. Residual

- Product method name / award type.
- Complete 10-arg stack layout.
- Predicate labs + full temp recovery.
- Runtime / differential.

**Verdict:** **accept** (ABI/virtual/spine sealed; gaps documented).
