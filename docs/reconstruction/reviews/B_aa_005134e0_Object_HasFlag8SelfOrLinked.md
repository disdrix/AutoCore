# Review B (skeptical / adversarial): `aa_005134e0` Object_HasFlag8SelfOrLinked

| Field | Value |
|---|---|
| **Stable ID** | `aa_005134e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005134e0_Object_HasFlag8SelfOrLinked.md` |
| **System** | targeting / object-flags |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on mask **`0x08`** + link-aware CF; **reject** Broken / bit-index-8 / pure-self-only claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Flag is **bit index 8** of `+0x184` | **Falsified** — mask is **`0x08`** = bit **3**; peers saying “bit 8” mean the **imm 8** |
| 2 | This tests **ItemFlag_Broken** (`0x80000` / bit 19 @ `+0x17c`) | **Falsified** — no `+0x17c` load; mask is **8** at **`+0x184`** |
| 3 | Pure self-only check | **Falsified** — non-null `+0xac` walks related/parent |
| 4 | Always calls virtual `+0x19c` | **Falsified** — skipped when `+0xac == 0` |
| 5 | Related path uses same absolute `+0x184` | **Falsified** — MI path tests **`+0x188`** after vbtable adjust |
| 6 | Returns host status code (equip-style) | **Falsified** — pure bool / `c3`; no `ret N` |
| 7 | Scaffold alias “only ContactCountdownTick callee” | **Overstated** — many callers (AI, skill, targeting, UI) |
| 8 | Ready for bit-exact / runtime seal | **Fail** — matrix open; no live CE this pass |
| 9 | Product name of flag is sealed | **Fail** — CF sealed only; English open |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Object*
// ret (no stack cleanup)

parent = *(obj + 0xac)
if (parent == 0)
  return ( *(obj + 0x184) & 0x08 ) != 0

related = parent->vtbl[+0x19c]()     // thiscall parent
self    = ( *(obj + 0x184) & 0x08 ) != 0
if (related != 0)
  adj = *(*(related + 4) + 4)
  return self || ( *(related + adj + 0x188) & 0x08 ) != 0
return self || ( *(parent + 0x184) & 0x08 ) != 0
```

### Byte anchors (not decompiler-only)

| Addr | Bytes | Meaning |
|------|-------|---------|
| `005134e0` | `56 8b f1` | `push esi; mov esi,ecx` |
| `005134e3` | `8b 8e ac 00 00 00` | `mov ecx,[esi+0xac]` |
| `005134ef` | `ff 90 9c 01 00 00` | `call [eax+0x19c]` |
| `005134f5` | `b2 08` | mask **8** |
| `005134f7` | `84 96 84 01 00 00` | `test [esi+0x184],dl` |
| `0051350b` | `84 94 06 88 01 00 00` | `test [esi+eax+0x188],dl` |
| `0051352f` | `24 08` | leaf `and al,8` |
| `0051353f` | `c3` | `ret` |

---

## 3. Relation attack: flag8 vs Broken vs dirty

| Unit | Offset | Mask | Role |
|------|--------|------|------|
| **This** `0x005134e0` | `+0x184` (rel `+0x188`) | **`0x08`** | read-only exclude predicate |
| Broken setter `0x00513de0` | `+0x17c` | **`0x80000`** | write ItemFlag_Broken |
| Dirty helper `0x00512670` | `+0x17c` | **`0x20000`** | write dirty |

**Cannot** conflate this flag with Broken or dirty. Shared only: parent link field **`+0xac`**.

---

## 4. Semantic attacks on name

- Body has **no** strings; product English for mask `0x08` is **not** sealed here.
- “HasFlag8SelfOrLinked” is a **mechanical** name from CF (mask + link). Accept as proposed dual label; do not claim PDB truth.
- Caller consensus (reject when true) supports **exclude-gate** role at **High**, not a specific game-design noun.

---

## 5. Confidence table (adversarial)

| Claim | Level |
|-------|-------|
| CF + mask + offsets | **High / Sealed** |
| Exclude-when-true role | **High** (caller CF) |
| Flag product English | **Open** |
| vtbl `+0x19c` product name | **Open** |
| MI `+0x188` ≡ same logical flag as `+0x184` | **High** CF intent; layout detail residual |
| Bit-exact / runtime | **Open** |

---

## 6. Verdict

**Accept-with-gaps** on sealed machine contract. Reject any mapping to Broken/`+0x17c`/bit-index-8. Residual: product flag name, related virtual name, runtime verification.
