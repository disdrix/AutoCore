# Review B (skeptical / adversarial): `aa_0043ce90` GuardedVector_RingCopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ce90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-B) |
| **Counterpart** | `reviews/A_aa_0043ce90_GuardedVector_RingCopyRange.md` |
| **Scratch** | `tmp/a_0043ce90.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure empty thunk / `jmp` | **Falsified** — 47 B reshape + call + clean |
| 2 | Does full assign alone | **Falsified** — parent always follows with fit (`0043c8c0`) or grow (`0043cec0`) |
| 3 | Multiple parents beyond CopyAssign | **Falsified** — only `FUN_0043c730` (2 xrefs) |
| 4 | Decompiler void means no return value | **Overstated** — bytes `MOV EAX,ESI` return out cursor |
| 5 | Named alias is retail symbol | **Overstated** — structural GuardedVector_*; Ghidra `FUN_0043ce90` |
| 6 | Full stack formal map sealed | **Gap** — reshape hex recoverable but unowned `FUN_0043d390` owns semantics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exclusive parent fit+grow | **High** | Missed assign path |
| Call 0043d390 + return ESI | **High** | Wrong cursor / corrupt list |
| Role = ring element copy entry | **High** | Invented memcpy assign |
| Exact formal order of reshape | **Medium** | Port arg mismatch |
| Product English | **Medium** | Naming only |

---

## 3. Cross-check against raw + bytes

```
// high level
FUN_0043d390(...marshalled...);
return ESI;  // as EAX
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Parent W26-G documented this unit as prep residual; boundary now sealed.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector unlocked assign non-empty paths:
//   push range args; ESI = &outCursor;
//   call GuardedVector_RingCopyRange (→ FUN_0043d390);
//   then fit residual OR grow residual helpers.
// Do not replace with flat memcpy ignoring ring begin/size.
```

---

## 5. Verdict

Adversarial pass **confirms** A boundary facts. Residual = unowned `FUN_0043d390` formal depth + product English → **accept-with-gaps**.
