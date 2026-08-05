# Review B (skeptical / adversarial): `aa_00536920` CVOGCharacter_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536920` |
| **VA** | `0x00536920` |
| **Canonical name** | `FUN_00536920` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00536920_CVOGCharacter_ctor.md` |
| **System** | missions-progression / character runtime |
| **Verdict** | **accept-with-gaps** on structure; **reject** full field seal, exclusive “player only”, and GiveItem-as-character-logic claims |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Only player character spawn ctor” | **Falsified** — GiveItem type `0x14` heap path; UI embeds at `parent+0x510` |
| “Creates inventory item payload alone” | **Partial** — factory *calls* it for type `0x14`, but body is full character field/hash init |
| “Applies CreateCharacter packet” | **Falsified** — no packet walk; that is `0x00534bd0` |
| “Grants missions / GiveMission” | **Falsified** — only constructs empty tables + staging clear |
| “All nine hashes product-named” | **Falsified** — only system-map subset sealed English |
| “Clean has full semantic plate” | **Falsified** — scaffold still FUN_* / offsets |
| “param_2 is hash bits” | **Falsified** — most-derived ctor flag; bits live on each hash object |

---

## 2. Decompiler hazards

| Hazard | Reality |
|---|---|
| Scaffold listed self-call `FUN_00536920` as callee | **False** — no recursion |
| `FUN_00538270()` no-arg map head | Returns new sentinel node; isnil `+0x49` set by this unit |
| Inline hash inits look like free functions without this | Each `operator_new` block builds a **separate** hash; ECX set to new object before AllocBuckets |
| Dual-base math easy to mis-offset | Adjust `-0xd9c` matches ApplyCreate secondary-this usage family |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is object always `0xF30`? | Heap path type `0x14` yes; embedded path size unknown (member at `+0x510`) | **High** heap / **Open** embed sizeof |
| Is `+0x508` staging map? | Cross-duals + `FUN_0052d8b0` call | **High** |
| Active at `+0x540` vs completed `+0x538`? | System map + ctor bits (completed 8 / active 4) | **High** roles; bits **High** |
| `+0x534` skill hash? | ApplyCreate inserts skill triples after Recreate — role **Probable**, not sealed English | **Probable** |

---

## 4. Surviving contract (minimal)

```
// thiscall
CVOGCharacter* Ctor(CVOGCharacter* this, int mostDerivedFlag);
// if mostDerivedFlag: dual-base cookies + FUN_00518940
// FUN_004c9aa0(0); install vtbls; dual-base adjust -0xd9c
// init fields; empty maps; new nine CNDHash* at known offsets
// ClearMissionStagingTree(this, destroy=0, missionId=-1)
// fill TFID arrays -1; post-inits; return this
//
// Heap factory (item type 0x14): operator_new(0xF30) + Ctor(this, 1)
// Do NOT treat body as packet apply or GiveMission.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| mostDerived + return this | **Agree** |
| Hash offset/bits/AllocBuckets table | **Agree** High |
| Staging `+0x508` + clear call | **Agree** |
| Type `0x14` size `0xF30` | **Agree** |
| Product class name CVOGCharacter | **Accept as working name** — RTTI/string open |
| Full field dictionary sealed | **Reject** — Open residual |

---

## 6. Residual (honest)

1. RTTI / product class string.
2. Complete field map (thousands of bytes of defaults).
3. Embedded-subobject parent type at `FUN_008fa9f0`.
4. Whether type `0x14` items are true characters or share layout only.
5. Runtime construct + vtbl dump.
6. Bit-exact vs retail.

---

## 7. Verdict

### **accept-with-gaps**

Ctor structure, factory size, dual-base, staging shell, and CNDHash pointer/bits matrix are **sealed**. Reject packet-apply / GiveMission claims and any assertion that every zeroed offset is product-named. Dual A table is acceptable with listed Opens.
