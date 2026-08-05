# Review B (skeptical / adversarial): `aa_005502d0` Skill_SetIsCastingFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_005502d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual seal; prior 2026-07-23 **accept**) |
| **Counterpart** | `reviews/A_aa_005502d0_Skill_SetIsCastingFlag.md` |
| **Scratch** | `reviews/a_005502d0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Complex cast AI / validation | Body is pure stores | **Falsified** — flag setter only |
| 2 | No tick stamp on true | `mov [ecx+0x178], g_dwClientTickMs` | **Falsified** — stamps |
| 3 | False clears tick / float | `je` skips both stores | **Falsified** — leaves stale `+0x178` |
| 4 | `+0x628` is dword / pointer | `mov byte [ecx+0x628], al` | **Falsified** — **byte** |
| 5 | `+0x170` integer zero | `movss` after `xorps` | **Falsified** — **float 0.0f** |
| 6 | Three stack args / `unaff_SI` | `ret 4`; one `push` at all sites | **Falsified** |
| 7 | Only HBOK callers | xref #3 `FUN_0052c780` | **Falsified** — bulk clear exists |
| 8 | `+0x628` means something else (e.g. rank) | LocalCastValidate busy→7; QB charge branch | **Survives as is-casting** at CF level |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x628` is-casting **byte** | **High** | LocalCastValidate / QB wrong |
| True-path tick stamp `+0x178` | **High** | Charge elapsed UI wrong |
| False leaves `+0x178` | **High** | Wrong if server assumes clear |
| ABI thiscall+char+RET4 | **High** | Hook/shim crash |
| Complete CODE caller set (3) | **High** | Missed writer of flag |

---

## 3. Cross-check against raw / asm

```
always:  skill+0x628 = (char)flag
if true: skill+0x170 = 0.f; skill+0x178 = g_dwClientTickMs
if false: skill+0x628 = 0 only
```

Clean must match; decomp plate “`pSkill` as flag” is a naming bug — **not** a second object pointer.

---

## 4. Surviving contract for AutoCore

```
// Client-local only (mirrors optimistic cast-again HB):
SetIsCastingFlag(skill, true):
  skill.IsCasting = 1          // +0x628
  skill.CastChargeElapsedBase = 0.f   // +0x170 (float; product name open)
  skill.CastStartTickMs = now  // +0x178

SetIsCastingFlag(skill, false):
  skill.IsCasting = 0
  // do NOT zero +0x178 / +0x170

// Gates:
//   LocalCastValidate: IsCasting || categoryCD → response 7
//   QuickBar CD UI: if IsCasting use (now - CastStartTickMs) vs charge/CD fields
```

Server must re-validate cast eligibility; this flag is **not** authoritative net state.

---

## 5. Open questions (non-blocking)

1. Product English / PDB for the three fields.
2. What else writes `+0x170` between casts.
3. When `FUN_0052c780` runs (teardown / map leave / death?).

**Verdict:** **accept**
