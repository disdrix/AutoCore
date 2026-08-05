# Review B (skeptical / adversarial): `aa_00922270` Input_TryFirePrimaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00922270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure gun fire only (like secondary) | Body walks `+0x550` skills first | **Falsified** — skill-first |
| 2 | Same heat quantifier as secondary | Primary `FUN_004f5290` returns on first heat-OK; secondary fails on first heat-bad | **Falsified as identical** — dual quantifiers sealed |
| 3 | Heat fail logs like secondary | No string / no `FUN_007a4480` in unit | **Falsified** — silent |
| 4 | Name must be retail `Input_TryFirePrimaryWeapons` | No string xref in unit; inferred from sibling + QB slot0 + DriveControlTick | **Hold `_Inferred`** |
| 5 | Skill path also fires guns | `goto LAB_00922371` skips `FUN_004f50d0` | **Falsified** |
| 6 | Tip only after successful fire | Tip call precedes heat probe | **Falsified order claim** — tip on gate pass |
| 7 | Server-authoritative fire | Client input path; enqueue via `FUN_0056d520` HB | **Client entry only** |
| 8 | `unaff_EDI` is a real formal | Asm category push is literal **1** | **Decomp noise** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Skill-before-gun order | **High** | AutoCore casts guns when hardpoint skill ready |
| Heat quantifier ∃ vs ∀ | **High** | Primary blocked when one overheated sibling slot exists (wrong) |
| Group select vtbl +0x38 vs +0x3C | **High** CF / **Probable** product | Fire wrong hardpoint group |
| Gates shared with secondary | **High** | Ghost fire without vehicle/net |
| Product name without string | **Probable** | Registry rename premature |
| 0xD2 flag semantics | **Medium** | Blocked when should fire |
| Tip 0x12 meaning | **Medium** | Wrong first-time UX |

---

## 3. Cross-check against raw

```
TryPrimary (inferred):
  walk hardpoint skills @char+0x550 (stride 0xC)
    first ready category-1 → CastSkillFromQB; UI; return path
  else if gates (player, !0xD2, net, vehicle+0x250):
    tip(0x12)
    if any primary heat-OK: fire all primary-marked weapons; UI
Clean ≡ raw CF. FUN_004f5290/50d0 names residual. Product symbol _Inferred.
```

Sibling secondary dual still stands: no skill walk; heat fail string; `vtbl+0x3C` + universal heat OK.

---

## 4. Surviving contract for AutoCore

```
Client primary fire entry:
  1) Prefer ready hardpoint skill (category 1 CD) before guns.
  2) Skill cast does not also pull primary gun trigger in same call.
  3) Gun path requires vehicle + live sector net + clear 0xD2.
  4) Primary heat gate is existential (any primary can fire), not universal.
  5) Primary heat fail is silent (no secondary-style log).
  6) Fire applies per primary-marked hardpoint via shared FUN_0056d520 start path.
Mirror gate order in any client-sim / input harness.
```

---

## 5. Open questions

1. Live capture: overheat primary → tip shown, no fire, no log.
2. Live: skill-ready hardpoint with cold guns → skill cast only.
3. Map 0xD2 bits; tip 0x12 string table.
4. Global rename wave for `FUN_004f5290` / `004f50d0` / secondary twins — out of this unit's rename scope unless owned.

**Verdict:** **accept-with-gaps**
