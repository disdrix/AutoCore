# Review B (skeptical / adversarial): `aa_004111d0` Character_GetXpRemainingToMaxLevelSoftCap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004111d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_004111d0_Character_GetXpRemainingToMaxLevelSoftCap_Inferred.md` |
| **Dual status** | MEGA-124 present |
| **Verdict** | **accept-with-gaps** on formula/ABI; **reject** authority-grant / current-level / thiscall claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **grants** mission XP / mutates total XP | **Falsified** — leaf read + return only; no store to `+0x730` |
| 2 | Uses **current level** (`+0x6c8`) not max | **Falsified** — bytes load **`[ESI+0xc50]`** only |
| 3 | Decompiler `void` / no params is ABI | **Falsified** — `unaff_ESI` is real; bare `RET` + ESI call-site reload |
| 4 | ECX thiscall | **Falsified** — no `MOV …,ECX`; body uses **ESI** exclusively for object |
| 5 | Multi-caller generic util | **Falsified as multi-caller** — **2** xrefs, both in `Client_ShowMissionRewardChatToast` only |
| 6 | Named_CalleeOf scaffold is product name | **Reject scaffold** — retire; formula name is structural `_Inferred` |
| 7 | Remaining is always ≥ 0 | **Unfounded** — no `MAX(0,…)` in body |
| 8 | Same as full AddExperience soft-clamp path | **Partial** — shares `threshold−1` policy but AddExperience clamps **current** level threshold when already max; this unit keys **maxLevel** always |
| 9 | Thread-safe / pure without globals | **Callee** may lazy-init XP table via globals — body itself is pure given ESI |

---

## 2. Decisive dataflow (image-backed)

```text
// ESI = character*
AX  = *(ushort*)(ESI + 0xc50)          // maxLevel
EAX = Experience_GetCumulativeThreshold(AX)  // cdecl
EAX = EAX - *(int*)(ESI + 0x730)       // − totalXp
EAX = EAX - 1                          // soft-cap room
RET                                    // bare
```

Call-site only consumer: toast award clamp when `[char+0x6b4] < 1` and `award >= remaining`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formula threshold(max)−xp−1 | **High** | Wrong toast clamp |
| ESI character ABI | **High** | Port uses ECX/stack |
| Sole toast consumer (today) | **High** (2 xrefs) | Miss other sites if image changes |
| maxLevel @ +0xc50 | **High** | Wrong table key |
| totalXp @ +0x730 | **High** | Wrong subtractand |
| Product name | **Open** | Naming only |
| Runtime | **Open** | Unobserved |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Key is current level +0x6c8 | bytes use +0xc50? | **Yes +0xc50** — attack fails |
| Soft-cap is threshold (no −1) | `SUB EAX,1` present? | **Yes** — −1 sealed |
| Stack arg character | `RET 4`? | **No** — bare `C3` |
| Writes soft-cap into total | store to +0x730? | **No stores** |
| Toast clamp always on | gate +0x6b4? | **Caller** skips when ≥1 |

---

## 5. Name attack

| Candidate | Keep? |
|-----------|-------|
| `Named_CalleeOf_Client_ShowMissionRewardChatToast_004111d0` | **Retire** — scaffold only |
| `Mission_GetRewardXp` | **Reject** — does not compute reward |
| `Experience_GetCumulativeThreshold` wrapper identity | **Reject** — post-processes with −xp−1 |
| `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` | **Keep** — formula + soft-cap −1 + maxLevel key |

---

## Verdict

**accept-with-gaps** — pure remaining-to-soft-cap leaf sealed; reject grant/thiscall/current-level/scaffold-name claims. Gaps: product English, negative remaining behavior, runtime.
