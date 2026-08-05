# Review B (skeptical / adversarial): `aa_00406840` LogicUiEventQueue_Resize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-E) |
| **Counterpart** | `reviews/A_aa_00406840_LogicUiEventQueue_Resize.md` |
| **Scratch** | `tmp/a_00406840.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a clear/reset helper (always n=0) | **Overstated** — body is general resize; callers happen to pass 0 |
| 2 | Element size is 4 / pointer vector | **Falsified** — `/0x138` + `RET 0x138` + InsertN dual |
| 3 | Grows by assigning end pointer only | **Falsified** — grow calls full InsertN |
| 4 | Shrink is `end = begin + n*stride` only | **Falsified** — calls erase helper that moves tail (POD copy loop 0x4e dwords) |
| 5 | newCount is a stack formal | **Falsified** — bytes use EAX; callers `xor eax,eax` |
| 6 | Decomp void / missing value arg means no stack value | **Falsified** — `RET 0x138` proves by-value POD |
| 7 | InsertN call omits this (decomp) | **Decomp artifact** — thiscall ECX=queue from image |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resize CF 3-way | **High** | Wrong queue length |
| EAX=newCount + RET 0x138 | **High** | Stack smash / wrong n |
| Stride 0x138 | **High** | OOB |
| Callers (2) | **High** | Missed edge |
| Product English | **Medium** | Naming only |
| Erase helper internals | **Medium** | Shrink POD detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
size = (end-begin)/0x138
newCount(EAX) <= size ? maybe erase : InsertN(end, n-size, &value)
RET 0x138
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Call-site bytes at `0x00801e8b` / `0x009470a0` both `33 C0` before call.

---

## 4. Surviving contract for AutoCore

```
// Logic-UI event queue resize (value by-value 0x138)
LogicUiEventQueue_Resize(queue, newCount /*EAX*/, value[0x138])
// element size MUST remain 0x138
// after grow, iterators may be invalidated (InsertN realloc path)
// clear: Resize(q, 0, dummyValue)
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/stride; residual event layout is family-wide → **accept**.
