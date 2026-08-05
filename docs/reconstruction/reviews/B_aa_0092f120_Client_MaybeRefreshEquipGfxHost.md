# Review B (skeptical / adversarial): `aa_0092f120` Client_MaybeRefreshEquipGfxHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0092f120_Client_MaybeRefreshEquipGfxHost.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + tail call; **reject** equip/inventory mutation claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Applies equip / changes hardpoints | **Falsified** — no equip helpers; only optional `FUN_004962b0` |
| 2 | Always refreshes | **Falsified** — dual null short-circuit |
| 3 | `this` in ECX | **Falsified** — client arrives in **EAX**; ECX set only for callee |
| 4 | Nested call with stack frame | **Falsified** — `jmp` tail to `FUN_004962b0` |
| 5 | Same as CompletelyDestroyObject | **Falsified** — destroy is large; this is only the shared gfx-host tail fragment |
| 6 | Bit-exact ready | **Fail** — host type + `FUN_004367f0` open |

---

## 2. Decisive dataflow (SEALED)

```
host = client[+0xE04]
if host == 0: return
gfx  = host[+0xE898]
if gfx == 0: return
FUN_004962b0(gfx)   // if gfx[+0x53] then FUN_004367f0(0,0)
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pure optional refresh | **High** | Invented equip side effects |
| Offsets `+0xE04` / `+0xE898` | **High** | Wrong null checks |
| Tail-call linkage | **High** | Stack imbalance theory |
| Named “equip gfx host” product title | **Tentative** | Docs mislabel |
| Runtime | **Open** | Residual |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0xE04` is local player character | Compatible? | **Unproven** — may be subsystem; do not claim character |
| Always non-null after equip | Hidden? | **No** — body tests both |
| Mutates item COID | Hidden? | **No** |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `Client_RecvInventoryEquip` / UnequipNotify | Callers after hardpoint class switch / destroy previous |
| `FUN_009440e0` CompletelyDestroyObject | Shares `+0xE04/+0xE898` → `FUN_004962b0` pattern at tail |
| `FUN_004962b0` | Real work |
| `FUN_004367f0` | Leaf refresh/unload |

---

## 6. Verdict

**accept-with-gaps.** Sealed as a **2-gate optional gfx-host refresh** used after equip/unequip. Not inventory logic. Product names of intermediate objects remain open.
