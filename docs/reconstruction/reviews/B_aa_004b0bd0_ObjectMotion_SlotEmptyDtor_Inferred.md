# Review B (skeptical / adversarial): `ObjectMotion_SlotEmptyDtor_Inferred` / `FUN_004b0bd0` @ `0x004b0bd0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b0bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-R) |
| **Counterpart** | `reviews/A_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function does real resource teardown | **Falsified** — body is single `c3` |
| 2 | Multi-role mass shared empty (is EmptyRet) | **Falsified** — only 2 xrefs, both from SlotRelease; different VA than `0x0056f570` |
| 3 | `ret 4` / stack cleanup | **Falsified** — bare `ret` |
| 4 | Has callees | **Falsified** — none |
| 5 | Product name retail | **Overstated** — `_Inferred` |
| 6 | Runtime verified | **Open** (vacuous) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty body | **High** | Over-porting nonexistent cleanup |
| Sole-caller role | **High** | Mis-grouping with EmptyRet |
| Bare ret ABI | **High** | Stack if callers wrongly assume ret n |
| Product English | **Medium** | Docs only |
| Runtime | **Open** | N/A practically |

---

## 3. Cross-check against raw + bytes

```
C3                  ; ret
CC CC …             ; pad, not body
```

Live decompile: `void FUN_004b0bd0(void) { return; }`. Xrefs: `0x005be2bf`, `0x005be2da` only.

---

## 4. Surviving contract for AutoCore

```
// Empty thiscall leaf — MUST NOT invent free/log/notify
// Call sites may pass ECX; body ignores it
// Distinct VA from EmptyRet (0x0056f570) and CVOGHBBase_EmptyVFunc (0x005081f0)
// Used only as pre-freelist "dtor" hook inside ObjectMotion_SlotReleaseToFreelist
```

Do not merge into mass EmptyRet without verifying all xrefs. Do not add cleanup when porting SlotRelease.

---

## 5. Verdict

Adversarial pass **confirms** A: private empty dtor stub for motion-slot freelist release → **accept**.
