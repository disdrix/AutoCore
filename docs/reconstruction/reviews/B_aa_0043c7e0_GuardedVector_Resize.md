# Review B (skeptical / adversarial): `aa_0043c7e0` GuardedVector_Resize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c7e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-D) |
| **Counterpart** | `reviews/A_aa_0043c7e0_GuardedVector_Resize.md` |
| **Scratch** | `tmp/a_0043c7e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EAX**; **ECX=new_size** |
| 2 | Stdcall with stack formals | **Falsified** — plain `RET`; only register args |
| 3 | Grow always used by sole caller | **Falsified** — `FUN_0043c660` does `XOR ECX,ECX` (clear only) |
| 4 | Decompiler 4-arg `FUN_0043cb00` list complete | **Falsified** — bytes put **count in ECX** and 4 stack packs; decompiler drops count |
| 5 | Function is swap itself | **Falsified** — only resizes; parent `0043c660` swaps headers after |
| 6 | Product name retail string | **Overstated** — inferred `GuardedVector_*` |
| 7 | Nested grow bit-exact | **Survives** — out of scope residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX container + ECX new_size | **High** | Wrong size / wrong object |
| Grow vs shrink vs equal | **High** | Silent no-op or double free path |
| Shrink → EraseRange range | **High** | Leaves tail elements |
| Nested `0043cb00` free | **Medium** | Port invents memcpy grow |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  size = [EAX+0x10]
  if size < new_size: grow via 0043cb00 with fill0
  if new_size < size: EraseRange [begin+new, begin+old)

bytes:
  MOV ESI, [EAX+0x10]
  CMP ECX, ESI / JBE skip_grow
  SUB ECX, ESI / CALL 0043cb00
  JNB skip_shrink
  CALL 0043c8c0
  plain RET after ADD ESP,8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 for trichotomy.  
Caller site `0x0043c697`: `33 C9 8B C6 … E8 …` confirms ECX=0, EAX=ESI.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector resize (unlocked body used under parent CS when flag +0x2c set):
//   EAX = container (+0x0c begin, +0x10 size)
//   ECX = new_size
//   grow: fill-default 0 via FUN_0043cb00(count=ECX, …)
//   shrink: EraseRange([begin+new, begin+old))
// Do not invent plain vector::resize without ring begin/size + EraseRange shrink.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets; nested grow + product name residual → **accept-with-gaps**.
