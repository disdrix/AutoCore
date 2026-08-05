# Review B (skeptical / adversarial): `aa_00513de0` Item_SetBroken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513de0_Item_SetBroken.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on mask **`0x80000`** + setter role; **reject** alternate-mask / pure-OR / always-dirty claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Mask is `0x8000` / bit 15 or other flag | **Falsified** — imm `00 00 08 00` = **`0x80000`**; shifts use **`0x13`** (19) |
| 2 | Mask is `0x20000` (dirty bit) | **Falsified** — `0x20000` is **callee** `FUN_00512670` only; write path ands **`0x80000`** |
| 3 | Always calls dirty helper | **Falsified** — `je` skips call when bit already equals desired |
| 4 | Function is a Broken **reader**/predicate | **Falsified** — writes `xor [ecx+0x17c],esi`; no boolean return (void + optional tail) |
| 5 | This is stack eligibility / capacity | **Falsified** — eligibility is `0x00513e70`; capacity `0x0040abf0` |
| 6 | Virtual call always runs | **Falsified** — only if **post-write** bit19 set (`test [ecx+0x17e],8`) |
| 7 | Virtual is a normal `call` (returns here) | **Falsified** — `ff a2 90 00 00 00` is **`jmp [edx+0x90]`** tail |
| 8 | Desired value is full `uint` / multi-bit | **Partially falsified** — load is **`movzx` byte**; write keeps only bit0 via `& 0x80000` after `<<19` |
| 9 | Compare uses only bit0 of desired | **Nuance** — compare is **full low byte** vs extracted bit `{0,1}`; write uses only bit0. Non-0/1 desired always dirty, may clear Broken if even |
| 10 | `extraout_ECX` means this is destroyed | **Decompiler artifact** — bytes keep using **ECX** for stores; `FUN_00512670` is `__fastcall` same object |
| 11 | Scaffold alias “only ReverseEngineerFailure callee” | **Overstated** — other raw captures also call (`004d08c0`, `004d4440`, `0050ac80`, …) |
| 12 | Ready for bit-exact / runtime seal | **Fail** — matrix open; no live CE this pass |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Item*
// [esp+4] at entry = desired (byte used)
// ret 4

flags = *(u32*)(item + 0x17c)
desired = (u8)stack_arg

if ( ((flags >> 19) & 1) != desired )   // full-byte compare vs {0,1}
  FUN_00512670(item)                    // | 0x20000 on item and +0xac chain

// bit19 := (desired & 1)
delta = ( ((u32)desired << 19) ^ flags ) & 0x80000
*(u32*)(item + 0x17c) = flags ^ delta

if ( *(u8*)(item + 0x17e) & 0x08 )      // == flags bit19 set after write
  // [esp+4] = 0; jmp [*(item)+0x90]    // tail; never returns to this epilogue
ret 4
```

### Byte anchors (not decompiler-only)

| Addr | Bytes | Meaning |
|------|-------|---------|
| `00513de0` | `8b 81 7c 01 00 00` | `mov eax, [ecx+0x17c]` |
| `00513de7` | `0f b6 74 24 08` | `movzx esi, byte [esp+8]` |
| `00513dec` | `c1 e8 13` | `shr eax, 0x13` |
| `00513e04` | `81 e6 00 00 08 00` | `and esi, **0x80000**` |
| `00513e0a` | `31 b1 7c 01 00 00` | `xor [ecx+0x17c], esi` |
| `00513e10` | `f6 81 7e 01 00 00 08` | `test byte [ecx+0x17e], 8` |
| `00513e24` | `ff a2 90 00 00 00` | `jmp [edx+0x90]` |
| `00513e2a` | `c2 04 00` | `ret 4` |

Relative call at `00513df6`: target **`0x00512670`** (displacement check: next=`00513dfb`, rel=`0xffffe875` → `00512670`).

---

## 3. Relation attack: dirty bit vs Broken vs sibling

| Unit | Mask | Bit | Mutation |
|------|------|-----|----------|
| **This** `0x00513de0` | **`0x80000`** | **19** | XOR set-to-desired Broken |
| Dirty helper `0x00512670` | `0x20000` | 17 | OR sticky dirty on self+chain |
| Sibling `0x00513e30` | `0x100000` | 20 | Same XOR pattern; **no** vtbl |
| Reader `0x00513e70` | reads `0x80000` | 19 | eligibility only |

**Cannot** conflate Dirty (`0x20000`) with Broken (`0x80000`).

---

## 4. Semantic attacks on “Broken”

Role name is **not** proved by this body alone (no string in unit). Adversarial check uses **external sealed** peer evidence:

- Loot / UI `"Broken: "` when bit19 set
- Overlay `i_g_2d_overlay_broken.dds`
- Count/Find skip bit19 unless includeBroken
- Registry row `ItemFlag_Broken` → setter `0x00513de0`

**Accept** product label **Broken** at **High** via that chain; this dual **owns** the **write mask and CF**, not re-proving strings.

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mask `0x80000` / bit 19 | **High / Sealed** | Wrong wire/flag port |
| Setter (not reader) | **High** | Missing mutator |
| Dirty-on-change only | **High** | Extra/missing dirty storms |
| Vtbl `+0x90` only when Broken set | **High** | Spurious side effects on clear |
| Vtbl product identity | **Low** | Wrong notify/hook |
| Desired always 0/1 from callers | **Medium** | Edge non-boolean clears flag |
| Name `Item_SetBroken` | **Probable** | Original symbol unknown |

---

## 6. Verdict

### **accept-with-gaps**

Mask **`0x80000`** is **byte-sealed**. Function is the dedicated **Broken setter**. Reject alternate masks, always-dirty, and “reader” mislabels. Leave vtbl `+0x90` and full callers as residual gaps.
