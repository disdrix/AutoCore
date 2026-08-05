# Review B (skeptical / adversarial): `aa_004d80b0` CVOGCombat_CalculateAndAwardKillXP

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d80b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Verdict** | **accept-with-gaps** on formula structure; **needs-more-evidence** for live client non-zero XP |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Client kill XP awards meaningful amounts | **Falsified in this image** — `g_flGlobalKillXpScalar` is 0 with no writers found (XP.md + `read_memory`) |
| 2 | Spree +5%/stack is primary kill bonus | **Partial** — applied only when raw ≥ 1; with scalar 0, stack term never runs |
| 3 | Prep-clamp “high within low+3” is bidirectional | **Overstated** — only clamps when `victim - player > 3`; does not clamp player above victim |
| 4 | Sixth param is meaningful | **Unsupported** — unused in body; treat as padding/alignment artifact |
| 5 | Floater always shows awarded XP | **Conditional** — needs `AddExperience` true **and** local `+0x7e`; with scalar 0 award is false when scaled→0 |
| 6 | Convoy blend is “divide loot fairly” | **Probable but not proven** — math matches XP.md; social design not evidenced |

---

## 2. Surviving formula skeleton

```
base = LevelDiffBase(victim', player, grey)
if count>0: base = ceil((base + trunc(count*0.1*base))/count)
raw = ceil(base * GLOBAL * mult)
xp = raw<1 ? 0 : raw + ceil(stacks * raw * 0.05)
AddExperience(char, xp, KillPath=1)
```

For AutoCore server: **do not ship GLOBAL=0**; XP.md recommends `1.0` and validate vs desired pacing.

---

## 3. Open questions

1. Is GLOBAL filled at runtime by an external injector / missing DLL writer not in this EXE?
2. Exact identity of local-player context for `+0x7e` floater gate.
3. Interaction order: AddExperience itself also mutates spree on KillPath — double-count risk vs formula stacks reading pre-increment byte?

**Note on #3:** Formula reads `+0x738` **before** `AddExperience`; AddExperience KillPath then increments spree. Stacks use **prior** spree state — consistent if intentional; document carefully.

---

## 4. Verdict

Formula reconstruction is high confidence. Live client kill XP is **structurally zero** unless GLOBAL is patched. Do not treat client-local kill path as authority for multiplayer awards.
