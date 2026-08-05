
# Review B (skeptical / adversarial): `aa_0043df70` GuardedVector_PopBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043df70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-C) |
| **Counterpart** | `reviews/A_aa_0043df70_GuardedVector_PopBack.md` |
| **Scratch** | `tmp/a_0043df70.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | EAX container like PushBack | **Falsified** — entry loads `[ECX+0x10]`; ECX this |
| 2 | Full pop_back with element dtor | **Falsified** — leaf; no calls; only size/begin stores |
| 3 | Pop front polarity | **Falsified** — begin never incremented; only cleared when size hits 0 |
| 4 | Decompiler void/fastcall wrong | **Survives as nuance** — void correct; ECX param correct; "fastcall" label OK for ECX this |
| 5 | Product name retail | **Overstated** — inferred `GuardedVector_PopBack`; no PDB string |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + RET | **High** | Wrong object |
| size-- / empty begin=0 | **High** | Ring desync |
| No dtor | **High** | Double-free if assumed |
| SEH-only callers | **High** (5 xrefs all Catch@) | Missed direct path only naming |
| Product English | **Inferred** | Naming only |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if size!=0: size--; if size==0: begin=0

bytes:
  MOV EAX,[ECX+0x10]; TEST/JZ
  ADD EAX,-1; MOV [ECX+0x10],EAX; JNZ
  MOV dword [ECX+0x0C],0
  RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 ≡ 23 B hex.

Polarity vs `FUN_0040d980` (pop_front): that unit advances begin with wrap; this unit only shrinks size — sealed pair of bookkeeping helpers.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector pop_back bookkeeping (SEH undo / empty shrink):
//   ECX = container (+0x0c begin, +0x10 size)
//   if size: size--; if size==0: begin=0
//   no element dtor — caller must destroy first if needed
// Do not invent vector::pop_back with destroy here.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets; product name residual is cosmetic → **accept**.

