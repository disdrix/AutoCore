# Review B (skeptical / adversarial): `aa_0043c8c0` GuardedVector_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c8c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-C) |
| **Counterpart** | `reviews/A_aa_0043c8c0_GuardedVector_EraseRange.md` |
| **Scratch** | `tmp/a_0043c8c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this only | **Falsified** — container is **EAX**; ECX used as scratch |
| 2 | Cdecl / plain RET | **Falsified** — `RET 0x14` stdcall 5 args |
| 3 | Always advances begin | **Falsified** — forward path only shrinks size |
| 4 | Wrap at raw capacity | **Falsified** — wrap test is `begin >= capacity*4` |
| 5 | Decompiler invents range math | **Survives as naming only** — bytes compute prefix/suffix compare |
| 6 | Product name retail string | **Overstated** — inferred from `GuardedVector_*` family |
| 7 | Nested move bit-exact | **Survives** — out of scope residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX + RET 0x14 ABI | **High** | Callers stack-corrupt |
| Shorter-side CF | **High** | Wrong residual elements |
| +0x08/+0x0c/+0x10 | **High** | Ring desync |
| Nested move free | **Medium** | Element slots wrong |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix = erase_from - begin
  if prefix < (size+begin - erase_to): reverse move + begin++
  else: forward move + size--
  out = {container, begin+prefix}

bytes:
  MOV ESI, EAX
  SUB (param_3 - [ESI+0xc]) → prefix
  LEA end=[size+begin]; SUB end - param_5 → suffix
  CMP prefix, suffix / JNB else
  CALL 0043d300 / CALL 0043d390
  RET 0x14
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Xrefs from `0043c550`, `0043c730`, `0043c7e0` only.

Caller shapes confirm erase semantics:

- shrink: erase `[begin+new_n, begin+old_n)`
- erase-one: erase `[idx, idx+1)`
- assign-fit: trim dest after prep

---

## 4. Surviving contract for AutoCore

```
// Ring erase used by assign-fit / shrink / erase-match:
//   EAX = container (+0x04 slots, +0x08 cap, +0x0c begin, +0x10 size)
//   stdcall (out, seed2, from, seed4, to) ; RET 0x14
// Port must preserve shorter-side policy + capacity*4 wrap
// or replace with equivalent container erase under same CS parent rules.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets; nested move + product name residual → **accept-with-gaps**.
