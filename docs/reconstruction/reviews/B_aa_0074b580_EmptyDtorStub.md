# Review B (skeptical / adversarial): `EmptyDtorStub` / `FUN_0074b580` @ `0x0074b580`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074b580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-B) |
| **Counterpart** | `reviews/A_aa_0074b580_EmptyDtorStub.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function does real resource teardown | **Falsified** — body is single `c3` |
| 2 | Is the mass-shared EmptyRet @ `0x0056f570` | **Falsified** — different VA; different xref set (20 vs hundreds) |
| 3 | Mission/CVOGReaction-specific logic (scaffold plate) | **Falsified** — empty body; multi-role callers |
| 4 | `ret 4` / stack cleanup | **Falsified** — bare `ret` |
| 5 | Has callees | **Falsified** — none |
| 6 | ListTrackedObj-only private stub | **Overstated** — also EH Unwind + other FUN_* |
| 7 | Runtime verified | **Open** (vacuous) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty body | **High** | Over-porting nonexistent cleanup |
| Bare ret ABI | **High** | Stack if callers wrongly assume ret n |
| Multi-role shared | **High** | Mis-merging with EmptyRet without xref audit |
| Product English | **Low** | Docs only — descriptive name |
| Runtime | **Open** | N/A practically |

---

## 3. Cross-check against raw + bytes

```
C3                  ; ret
CC CC …             ; pad, not body
```

Live decompile: `void FUN_0074b580(void) { return; }`.  
Xrefs include `004be3ce/de/ee` (ListTrackedObj) + Unwind@009a… + FUN_00492*/496*.

---

## 4. Surviving contract for AutoCore

```
// Empty leaf — MUST NOT invent free/log/notify
// Call sites may pass ECX; body ignores it
// Distinct VA from EmptyRet (0x0056f570), ObjectMotion_SlotEmptyDtor (0x004b0bd0),
//   CVOGHBBase_EmptyVFunc (0x005081f0)
// Used as trivial member dtor + EH unwind target
// Reject Mission_Uses_CVOGReaction scaffold alias
```

Do not merge into mass EmptyRet without verifying all xrefs. When porting ListTrackedObj complete dtor, the three member dtor calls are intentional no-ops (empty types or stripped bodies).

---

## 5. Verdict

Adversarial pass **confirms** A: multi-role empty dtor stub fully sealed → **accept**.
