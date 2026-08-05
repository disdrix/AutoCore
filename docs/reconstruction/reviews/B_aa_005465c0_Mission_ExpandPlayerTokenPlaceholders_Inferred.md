# Review B (skeptical / adversarial): `aa_005465c0` Mission_ExpandPlayerTokenPlaceholders_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005465c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_005465c0_Mission_ExpandPlayerTokenPlaceholders_Inferred.md` |
| **Dual status** | WQ7R-D present |
| **Verdict** | **accept-with-gaps** on token expand CF; **reject** free-form parser / write-to-wallet / thiscall claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Free-form `[$anything]` macro engine | **Falsified** — only five literal needles; no general scanner |
| 2 | Writes / awards credits | **Falsified** — read-only delta format into string; no store to `+0x720` |
| 3 | `__thiscall` on character | **Falsified** — cdecl 2-arg; `ADD ESP,8` at both callers |
| 4 | Name is `Named_credits` only | **Partial poison** — credits is one of five tokens; rename must cover full set |
| 5 | Class/race strings computed in-body | **Falsified** — delegated to `FUN_00521900` / `FUN_00521800` |
| 6 | Always expands all tokens | **Falsified** — each block skips when find == npos |
| 7 | Safe if replacement re-introduces needle | **Risk acknowledged** — loops until npos; pathological re-insert could spin (same as image) |
| 8 | Product plate names this function | **Falsified** — no RTTI/plate; `_Inferred` required |
| 9 | Handles gender / other tags (`[$he]` etc.) | **Falsified** — not present (cf. separate gender unit reviews) |

---

## 2. Decisive dataflow (image-backed)

```
// cdecl (Character* ch, std::string* text)
// for each token in {name, class, race, credits, level}:
//   while find(token) != npos:
//     materialize replacement from ch
//     replace(pos, token_len, replacement)
```

Materializers:

| Token | Path |
|---|---|
| name | MI vcall `[vtbl+0x160]` |
| class | `FUN_00521900(ch)` |
| race | `FUN_00521800(ch)` |
| credits | `sprintf("%I64d", *(i64*)(ch+0x720) - *(i64*)(ch+0x728))` |
| level | MI vcall `[vtbl+0x27c]` → `sprintf("%i")` |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Five-token CF | **High** | Wrong dialog text pipeline |
| cdecl ABI | **High** | Stack imbalance port |
| Credits delta formula | **High** | Wrong displayed money |
| `+0x728` semantic label | **Probable/Open** | Misnamed “debt/spent” |
| Vtbl product English | **Open** | Naming only |
| Runtime | **Open** | Unobserved |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Credits is single u32 | only +0x720? | **No** — 64-bit with SBB across +0x724/+0x72c |
| Credits writeback | store after sprintf? | **No** — replace string only |
| Token lengths wrong | off-by-one replace | Image uses 7/8/7/10/8 matching C-string lens |
| thiscall ECX=string | ECX preserved? | Callers push both; ECX used only as string this for find/replace after `MOV ECX,ESI` |

---

## Verdict

**accept-with-gaps** — sealed as fixed five-token player placeholder expander; reject wallet mutation and free-form macro claims.
