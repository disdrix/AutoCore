# Review B (skeptical / adversarial): `aa_0040abf0` Item_CanAcceptStackQty

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040abf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040abf0_Item_CanAcceptStackQty.md` |
| **Verdict** | **accept-with-gaps** on CF (capacity formula + callers closed; type-4 product residual open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is stack **eligibility** (`Item_IsStackEligible`) | No blob+0x3f2 / Broken tests; pure qty math | **Falsified** — different unit (`0x00513e70`) |
| 2 | Type-4 max is truly unlimited **999999** in the compare | Bytes: `mov esi,0xF423F` then `movzx edx,si` | **Falsified as effective 999999** — effective **16959** |
| 3 | Default 200 always applied | Only when def u16==0 and type≠4 | **Falsified as always** |
| 4 | `this` is the **incoming** item | 5/5 sites: ECX = existing stack; push = new qty | **Falsified** |
| 5 | Return packs multi-byte status (`CONCAT31`) | `setle cl; mov al,cl` only | **Falsified** — bool AL |
| 6 | Function mutates inventory | No stores to item/grid | **Falsified** |
| 7 | Capacity field is at clonebase+0x4BA directly | Load is `*( *(clonebase+0x3C) + 0x4BA )` | **Falsified as direct** — one pointer hop |
| 8 | Hidden sixth caller / data xref | 5 UNCONDITIONAL_CALL only | **Falsified** |
| 9 | Formula unique to this VA | Identical max path inlined in `0x005710c0` | **Survives as shared formula**; this VA still owned as leaf helper |
| 10 | Server must mirror type-4 load-then-mask quirk | Client compare is masked; product intent open | **Gap** — document effective u16; do not invent product rule |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predicate shape `(qty+add) <= (max&0xFFFF)` | **High** | Wrong merge rejects |
| Type4 / def+0x4BA / default 200 | **High** | Wrong caps |
| Effective type4 = 16959 | **High** | Over-accept huge stacks |
| ECX = destination item | **High** | Capacity from wrong clonebase |
| addQty = stack ushort | **High** | Wrong headroom |
| Bool return | **High** | Misread EAX |
| Type-4 product class name | **Open** | Doc only |
| Whether server uses same mask | **Open** | Server desync on huge stacks |
| Runtime wire/process | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0040abf0  mov  eax, [ecx+0xA8]          ; clonebase
0040abf3  cmp  dword [eax+0x38], 4
0040abf7  push esi
0040abf8  jne  short non_type4
0040abfa  mov  esi, 0x000F423F          ; 999999
0040abff  jmp  short after_max
0040ac01  mov  eax, [eax+0x3C]          ; def blob*
0040ac04  mov  ax,  [eax+0x4BA]         ; max u16
0040ac0b  test ax, ax
0040ac0e  movzx esi, ax
0040ac11  ja   short after_max          ; nonzero → keep
0040ac13  mov  esi, 0xC8                ; 200
0040ac18  mov  edx, [ecx]
0040ac1a  call dword [edx+0x25C]        ; qty
0040ac20  movzx ecx, word [esp+8]       ; addQty
0040ac25  add  eax, ecx
0040ac27  movzx edx, si                 ; max & 0xFFFF
0040ac2a  xor  ecx, ecx
0040ac2c  cmp  eax, edx
0040ac2e  setle cl
0040ac31  mov  al, cl
0040ac33  pop  esi
0040ac34  ret  4
```

Decompiler body (2026-07-29) matches 2026-07-23 raw; live bytes confirm immediates **4 / 999999 / 200 / 0x4BA / 0x25C** and the **SI zero-extend** compare.

---

## 4. Surviving contract for AutoCore

```
bool Item_CanAcceptStackQty(Item* dest, uint16_t addQty):
  cb = dest->clonebase          // +0xA8
  if (cb->type == 4):           // +0x38
    max = 999999
  else:
    max = *(uint16_t*)(cb->def + 0x4BA)   // def @ +0x3C
    if (max == 0): max = 200
  qty = dest->GetQuantity()     // vtbl +0x25C
  return (qty + addQty) <= (max & 0xFFFF)
```

- Call only after same-CBID / non-Broken / eligibility as appropriate.
- Type-4 **effective** client cap for this compare is **16959**, not 999999.
- Do **not** conflate with `Item_IsStackEligible` (no capacity).
