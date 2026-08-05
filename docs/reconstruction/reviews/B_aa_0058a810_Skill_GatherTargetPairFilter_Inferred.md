# Review B (skeptical / adversarial): `aa_0058a810` Skill_GatherTargetPairFilter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058a810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058a810_Skill_GatherTargetPairFilter_Inferred.md` |
| **Verdict** | **accept-with-gaps** on product name; **accept** on pair-filter role + mode CF |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is ValidateTarget | **Falsified** — no HB list / skill def walk; gather-only caller |
| 2 | This is GetObjectsInArea | **Falsified** — no spatial query; filters one candidate |
| 3 | Mode 10 = alive only | **Falsified** — only mode that **allows** `vtbl+0x198 != 0` (dead-like) |
| 4 | Mode 1 == mode 2 | **Falsified** — opposite `vtbl+0x298` polarity |
| 5 | Dedupe scans full out list | **Overstated** — `TFID_EqualsObjectId` vs **outList base** only (primary/first slot) |
| 6 | filterA always restricts Vehicle/Creature/Character | **Falsified** — living types take remap paths and **bypass** exact filterA match |
| 7 | Multiple callers | **Falsified** — sole `Skill_GatherTargetsInArea` |
| 8 | Product name known | **Holds as false** — `_Inferred` required |
| 9 | Unlisted modes reject | **Falsified** — after commons, default `return 1` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sole-caller pair filter role | **Confirmed** | Wrong skill pipeline stage |
| Mode branch CF | **High** | Wrong multi-target class |
| Mode English labels | **INFERRED** | Doc only |
| Primary TFID dedupe scope | **High** | Over-filter if assumed full-list |
| Living-type filterA bypass | **High** | Character-only gather assumptions fail |
| Product symbol | Unknown | Cosmetic |

---

## 3. Surviving contract

```
accept = GatherTargetPairFilter(cand, caster, outListBase, mode, filterA, filterB, filterC, &frame)
if accept: Gather appends TFID stride 0x10 using frame
mode drives relationship class; not spatial query; not cast power check
```

Ownership: **this unit** owns pair accept CF. Gather owns query flags / pass-1 / list packing. Range/distance is `FindDistanceToTarget`. Broadphase is `GetObjectsInArea`.

---

## 4. Residual uncertainty

| # | Item | Blocks role seal? |
|---|---|---|
| R1 | Mode English / PDB | No |
| R2 | Vtbl product names | No |
| R3 | filterB helper English | Mild |
| R4 | Indirect calls not in callers graph | Low (none found) |

---

## 5. Concrete checks

1. Re-decompile ≡ raw. **Pass**
2. Callers = only GatherTargetsInArea. **Pass**
3. Mode 8 early accept. **Pass**
4. Cross-check residual table in `a_0058d330.md`. **Pass**
5. Hostile vs ally polarity. **Pass**

---

## 6. Verdict

**accept** on gather pair-filter role + mode CF; **accept-with-gaps** for product name (`_Inferred`) and filter helper English.
