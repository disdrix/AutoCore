# Review B (skeptical / adversarial): `aa_007fbb70` FUN_007fbb70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbb70` |
| **VA** | `0x007fbb70` |
| **Canonical name** | `FUN_007fbb70` (**leave-FUN**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_007fbb70_FUN_007fbb70.md` |
| **Live tools** | Independent `force_decompile` + caller + sibling contrast |
| **Verdict** | **leave-FUN** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** Grab clear `0x007fbbb0` | **Falsified** — different body/offsets |
| 2 | Always destroys selected | **Falsified** — only when EDX matches selected+0x518 or null cases |
| 3 | Nulls `host+0x309c` | **Falsified** — flags only + vtbl+4(0); pointer clear not in body |
| 4 | True MSVC `__fastcall` with ECX meaningful | **Overstated** — ECX unused; EAX/EDX sealed |
| 5 | Removes hash entry | **Falsified** — caller `FUN_00413a60` does remove |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Match predicate | **High** | Sticky selection after delete |
| Flag pair +0x30b4=1 / +0x30b5=0 | **High** | UI mode stuck |
| Does not free hash node | **High** | Double ownership claims |
| English of +0x518 field | **Probable** | Wrong compare width |
| Whether vtbl+4(0) frees object | **Tentative** | Lifetime bug if assumed |

---

## 3. Caller challenge

| Caller | Must not claim |
|---|---|
| `FUN_0085fcc0` | That this clears the widget — widget detach is `host.vtbl+0xbc(widget)` after |
| `FUN_0088f410` | InventorySheet-only |

---

## 4. CF challenge of Review A

- Dual identity: **agree**
- leave-FUN: **agree**
- Residual: EAX provenance at `FUN_0085fcc0` call (what object is host) — **open**, CF of this body still sealed

---

## 5. Surviving contract

```
FUN_007fbb70(host /*EAX*/, id /*EDX*/):
  sel = host.selected(+0x309c)
  if id==0 || sel==0 || id == sel.field(+0x518):
    host.flag(+0x30b4) = 1
    host.flag(+0x30b5) = 0
    if sel: sel.vtbl+4(0)
```

**Verdict:** **leave-FUN.** Accept A.
