# Review B (skeptical / adversarial): `aa_00513e30` Item_SetCustomized

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513e30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513e30_Item_SetCustomized.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on mask **`0x100000`** + setter role; **reject** Broken/dirty-mask conflation |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Mask is `0x80000` / Broken (bit 19) | **Falsified** — imm `00 00 10 00` = **`0x100000`**; shifts use **`0x14`** (20) |
| 2 | Mask is `0x20000` (dirty bit) | **Falsified** — `0x20000` is **callee** `FUN_00512670` only |
| 3 | Always calls dirty helper | **Falsified** — `je` skips call when bit already equals desired |
| 4 | Function is a Customized **reader** | **Falsified** — writes `xor [ecx+0x17c],esi`; void + `ret 4` |
| 5 | Has Broken-style vtbl `+0x90` tail | **Falsified** — epilogue is `pop esi; ret 4` only |
| 6 | Desired value is full `uint` multi-bit | **Partially falsified** — load is **`movzx` byte**; write keeps only bit0 via `& 0x100000` after `<<20` |
| 7 | Compare uses only bit0 of desired | **Nuance** — compare is **full low byte** vs `{0,1}`; write uses only bit0 |
| 8 | `extraout_ECX` means this is destroyed | **Decompiler artifact** — bytes keep using **ECX** for stores |
| 9 | Scaffold “only VehicleSwitchFailure callee” | **Overstated** — xrefs: `00810360`, `005cb520`, `005cbcb0`, `0091260e`, `009126a9` |
| 10 | Ready for bit-exact / runtime seal | **Fail** — not run this pass |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Item*
// [esp+4] at entry = desired (byte used)
// ret 4

flags = *(u32*)(item + 0x17c)
desired = (u8)stack_arg

if ( ((flags >> 20) & 1) != desired )   // full-byte compare vs {0,1}
  FUN_00512670(item)                    // | 0x20000 on item and +0xac chain

// bit20 := (desired & 1)
delta = ( ((u32)desired << 20) ^ flags ) & 0x100000
*(u32*)(item + 0x17c) = flags ^ delta
ret 4
```

### Byte anchors (not decompiler-only)

| Addr | Bytes | Meaning |
|------|-------|---------|
| `00513e30` | `8b 81 7c 01 00 00` | `mov eax, [ecx+0x17c]` |
| `00513e37` | `0f b6 74 24 08` | `movzx esi, byte [esp+8]` |
| `00513e3c` | `c1 e8 14` | `shr eax, 0x14` |
| `00513e54` | `81 e6 00 00 10 00` | `and esi, **0x100000**` |
| `00513e5a` | `31 b1 7c 01 00 00` | `xor [ecx+0x17c], esi` |
| `00513e60` | `5e c2 04 00` | `pop esi; ret 4` |

Relative call at `00513e46`: target **`0x00512670`** (`next=00513e4b`, rel=`0xffffe825`).

---

## 3. Relation attack: dirty vs Broken vs Customized

| Unit | Mask | Bit | Mutation |
|------|------|-----|----------|
| Broken `0x00513de0` | **`0x80000`** | **19** | XOR + optional vtbl |
| Dirty helper `0x00512670` | `0x20000` | 17 | OR sticky dirty |
| **This** `0x00513e30` | **`0x100000`** | **20** | XOR set-to-desired Customized |

**Cannot** conflate Dirty / Broken / Customized masks.

---

## 4. Semantic attacks on “Customized”

Body has **no string**. Adversarial check uses **external sealed** peer evidence:

- Trade: `"You cannot trade items that have been customized to you!"` when bit20 set
- Permanent-customize Yes path sets via this function (`0x0091260e`)
- Inventory drop type-5 trade gate reads bit20 of `+0x17c`

**Accept** product label **Customized** at **Probable/High** via that chain; this dual **owns write mask and CF**.

Alternate labels (soulbound / permanent-bind) not disproved — residual naming gap only.

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mask `0x100000` / bit 20 | **High / Sealed** | Wrong wire/flag port |
| Setter (not reader) | **High** | Missing mutator |
| Dirty-on-change only | **High** | Extra/missing dirty storms |
| No vtbl side effect | **High** | Spurious notify on set/clear |
| Desired always 0/1 from callers | **Medium** | Edge non-boolean clears flag |
| Name `Item_SetCustomized` | **Probable** | Original symbol unknown |

---

## 6. Verdict

### **accept-with-gaps**

Mask **`0x100000`** is **byte-sealed**. Function is the dedicated **bit-20 (Customized) setter**. Reject Broken-mask, always-dirty, reader, and vtbl-tail mislabels. Leave PDB name and full callers as residual gaps.
