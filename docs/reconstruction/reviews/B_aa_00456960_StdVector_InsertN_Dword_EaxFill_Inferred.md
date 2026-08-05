# Review B (skeptical / adversarial): `aa_00456960` StdVector_InsertN_Dword_EaxFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00456960` |
| **VA** | `0x00456960` |
| **Canonical name** | `StdVector_InsertN_Dword_EaxFill_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00456960_StdVector_InsertN_Dword_EaxFill_Inferred.md` |
| **System** | util / container |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body grows, memmoves, fills; never shrinks | **Falsified** erase |
| 2 | Mission/UI domain logic lives here | No packet/string/mission callees; pure triad math | **Falsified** domain |
| 3 | Same ABI as `FUN_004073a0` | Fill via `*EAX`; count in first formal; different helpers | **Falsified** merge |
| 4 | Growth is 2× | Formula is `cap + (cap>>1)` then exact floor | **Falsified** 2× |
| 5 | Element stride 8/16 | All math is `>>2` / `*4` | **Falsified** |
| 6 | Count always 1 | Wrapper uses 1; other sites pass multi-count | **Falsified** always-1 |
| 7 | Decompiler `operator_delete` “does not return” is real noreturn | Warning noise after free; triad still written on realloc path | **Agree** warning is decompiler artifact on that branch |
| 8 | Can fold into `00466da0` | Wrapper rebinds iterator; this owns grow/fill | **Falsified** merge |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-n CF + triad | **Confirmed** | Corrupt containers |
| 1.5× / exact-fit growth | **Confirmed** | OOM / wrong cap |
| EAX fill dword | **Confirmed** | Garbage elements |
| Generic multi-caller | **High** | Wrong ownership in docs |
| Product English name | **Open** | Naming only |
| Fill-helper English | **Tentative** | Port stubs incomplete |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw/clean CF.
read_memory @ 0x00456960:
  83 EC 0C        sub esp, 0xC
  53 56           push ebx, esi
  8B F1           mov esi, ecx   ; count path
  8B 08           mov ecx, [eax] ; fill = *EAX
  8B DA           mov ebx, edx   ; vec
  … triad load [ebx+4] …
```

### Merge trap

Do **not** merge with:

- `FUN_004073a0` — sibling insert-n, different ABI/helpers
- `FUN_00466da0` — insert-one + iterator rebind only
- Domain push wrappers that only *call* this

### Growth trap

Assuming power-of-two doubling will over-allocate vs retail 1.5× + exact-fit floor.

---

## 4. Surviving contract for AutoCore

```
StdVector_InsertN_Dword_EaxFill(count, vec, pos, *value@EAX):
  if count==0: return
  if size+count > max: overflow helper
  if need_grow:
    newCap = max(cap + cap/2, size+count)  // with max-elem gates
    realloc; prefix|gap|suffix; fill gap with *value; return
  else:
    in-place shift; fill [pos, pos+count)
```

**Verdict:** **accept-with-gaps** — adversarial review does not break insert-n / growth / EAX-fill contract.
