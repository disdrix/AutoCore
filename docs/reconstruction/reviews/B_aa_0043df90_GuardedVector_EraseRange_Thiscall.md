# Review B (skeptical / adversarial): `aa_0043df90` GuardedVector_EraseRange_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043df90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-L) |
| **Counterpart** | `reviews/A_aa_0043df90_GuardedVector_EraseRange_Thiscall.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as W27-C `GuardedVector_EraseRange` (`0043c8c0`) | **Partially true CF** — same shorter-side erase math; **ABI differs**: W27-C is **EAX** container; this is **ECX** thiscall |
| 2 | Same callees as W27-C (`0043d300` / `0043d390`) | **Falsified** — rel32 → `0043ebb0` / `0043ec50` (thiscall-family checked/forward assign) |
| 3 | cdecl / plain RET | **Falsified** — `C2 14 00` + `SUB/ADD ESP,10` |
| 4 | Destroys elements / free heap | **Falsified** — only ring reassign + begin/size; no free/dtor call in body |
| 5 | Linear vector erase | **Falsified** — ring wrap on begin via `capacity*4` |
| 6 | Product name retail string | **Overstated** — inferred `GuardedVector_EraseRange_Thiscall` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + 5 formals + RET 0x14 | **High** | Stack imbalance / wrong object |
| Shorter-side trichotomy | **High** | Wrong packing side |
| begin wrap / size shrink | **High** | Corrupted ring head |
| Callee identities | **High** (sealed W33-K/J) | Port invents flat move |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Edge wrap races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix = from_i - begin; erase_cnt = to_i - from_i
  if prefix < suffix: reverse-assign then advance begin + shrink size
  else: forward-assign then size-only shrink
  out = {this, begin+prefix}

bytes:
  MOV ESI,ECX
  CALL 0043ebb0 (prefix < suffix arm) / CALL 0043ec50 (else)
  epilogue: MOV [out],ESI; MOV [out+4], begin+prefix; ADD ESP,10; RET 14

Resize_Thiscall shrink site:
  push to_i=begin+size, to_c, from_i=begin+new, from_c, out
  CALL 0043df90  ; ECX still container
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 for CF; **bytes win** on ECX/RET 0x14.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector thiscall erase-range:
//   ECX = container (+0x08 capacity, +0x0c begin, +0x10 size)
//   stack out, from_c, from_i, to_c, to_i; RET 0x14
//   shorter prefix → reverse pack + begin advance/wrap
//   else → forward pack + size-only shrink
//   out = {container, begin+prefix}
// Do NOT reuse W27-C EAX EraseRange ABI or its older callees (d300/d390).
// Do NOT invent element dtor/free here — packing only.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/callees and rejects EAX-mix / dtor / linear-vector misreads; nested pack helpers already dual-sealed → **accept**.
