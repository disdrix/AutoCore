# Review B (skeptical / adversarial): `aa_0051a790` Skill_LocalCastValidate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 (dual residual `2026-07-29`; **gate-ladder strengthen** same day) |
| **Counterpart** | `reviews/A_aa_0051a790_Skill_LocalCastValidate.md` |
| **Residual scratch** | `reviews/a_0051a790.md` |
| **Verdict** | **accept-with-gaps** on ordered ladder + UX code map; assembly formal + runtime still open |

---

## 1. Claims under attack

| # | Claim | Attack outcome |
|---|---|---|
| 1 | Server authoritative cast allow | **Falsified** — client local precheck; server still validates |
| 2 | Plate signature `(pCaster, bSkipBusy, pSkill)` as written | **Falsified** — 2nd is skip-busy; 3rd is skill pointer (`_bSkipBusyCheck` inverted name) |
| 3 | Always returns 0 | **Falsified** — multi-code ordered ladder G0–G9 |
| 4 | Codes 10–12 are unnamed “form flags” | **Falsified as final UX** — FormatFailure: prevent / must-hidden / can't-while-hidden |
| 5 | This function returns 13/14 directly | **Falsified** — no literals; may forward LocalRangeTargetCheck |
| 6 | Code 3 means “no plant” as product English | **Partial** — body is plant/`+0x6b4` gate; toast is **wrecked** |
| 7 | Power path is `+0x6b4 >= 1` | **Falsified** — raw requires `+0x6b4 < 1` with current < cost |
| 8 | Power always checked when plant present | **Falsified** — if `plant+0x6b4 >= 1`, G5 power deny **never fires** even if `+0x12c < cost` |
| 9 | Binding occupied must fail cast | **Not shown** — NotEquals≠0 skips deep checks → `return 0` |
| 10 | Promote FUN_005169c0 / FUN_00518c20 to product names | **Blocked** — multi-caller leave-FUN (2026-07-29) |
| 11 | TFID equality is full 16-byte memcmp | **Falsified** — NotEquals compares 2×i32 + 1×char only |
| 12 | Gate order is free / reorderable for port | **Falsified** — early-exit order is load-bearing (G0 before G1 before G2…) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ordered ladder G0–G9 | **High** | Wrong deny priority / missed early reject |
| Code 0/4/6/7 family | **High** | Wrong cast fail UX |
| Code 5 status / 3 wrecked toast | **High** string; gate product open for 3 | Mislabel server parity |
| Codes 10/11/12 UX | **High** | Hide/prevent toast wrong |
| Busy gate +0x10 | **High** | Cast while busy |
| Power only when `+0x6b4 < 1` | **High CF** | Over-deny power on server port |
| Category CD ST0 residual | Tentative rep in clean | False recharge deny |
| `plant+0x6b4` field meaning | Open | Power/vehicle gate mis-port |
| Working ABI from callers (9) | **High** | Broken port signature |

---

## 3. Cross-check against raw + FormatFailureMessage

```
G0 suppress5;
G1 vehicle plant3;
G2 busy5/6;
G3 null skill → 0;
G4 free bind only:
  G5 power4; G6 cd/cast7; G7 prevent10; G8 hide12/11 | LocalRangeTargetCheck;
else 0 (incl. occupied bind).
Clean ≡ raw CF; plate names still wrong; UX table sealed from 0x0054fa20.
```

RequestCast fail path: `Skill_FormatFailureMessage(validateCode, …)` — **Confirmed** bridge.

LocalRangeTargetCheck may surface **0xf** (accuracy) or handler codes (**13/14** Probable) — **not** LocalCastValidate literals.

---

## 4. Surviving contract for AutoCore

```
LocalCastValidate(caster, skipBusy=0, pSkill, rangeExtra=0):
  evaluate G0→G9 early-exit order (do not reorder)
  0 allow; local only — server still validates
  map codes via FormatFailureMessage strings
  power deny requires plant+0x6b4 < 1 AND current < cost
  occupied active-cast binding → 0 (no deep skill gates)
  pair RequestCast / QuickBarActivate / LocalRangeTargetCheck
  do not implement Ghidra plate param names as retail ABI
  leave FUN_005169c0 / FUN_00518c20 as FUN_*
```

---

## 5. Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| Ordered gate ladder | **Sealed High** (G0–G9) |
| eSkillResponses 10–12 meanings | **Sealed High** via FormatFailureMessage |
| Codes 3/5 UX strings | **Sealed High** |
| Power dual-use of `+0x6b4` | **Sealed High CF** (G1 vs G5) |
| FUN_005169c0 identity | Role sealed; **leave FUN_*** |
| FUN_00518c20 identity | Role sealed; **leave FUN_*** |
| TFID polarity + compare width | **Sealed High** |
| Caller set completeness | **Sealed High** (9 callers) |
| Assembly prototype | Still open |
| Runtime matrix | Still open |
| Skill flag product enum | Probable only |

**Verdict:** **accept-with-gaps**
