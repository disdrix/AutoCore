# Review A (reconstruction fidelity): `aa_00520340` Character_CalcCommodityTierMaxCapacity (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520340` |
| **VA** | `0x00520340`–`0x005204cd` inclusive (**398 B** / `0x18E`) |
| **Canonical name** | `Character_CalcCommodityTierMaxCapacity` (**INFERRED**) |
| **Ghidra symbol** | `FUN_00520340` |
| **Review date** | `2026-08-05` |
| **Agent** | R12-018 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_00520340_Character_CalcCommodityTierMaxCapacity_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | R12 residual dual; partition parent `0x005244e0` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Level-scaled max commodity capacity** for one tier (product UI label: **Complexity**):

```c
// __thiscall: ECX = Character*
// ret 4: tier ∈ {1..5}
int Character_CalcCommodityTierMaxCapacity(Character* ch, uint32_t tier) {
  uint8_t level = *(uint8_t*)((char*)ch + 0x599);
  switch (tier) {
  case 1: return (int)floor(level * 3.5f);
  case 2: return (int)floor(level * 2.8f);
  case 3: return (int)floor(level * 2.1f);
  case 4: return (int)floor(level * 1.4f);
  case 5: return (int)floor(level * 0.7f);
  default: return 0;
  }
}
```

Read-only capacity probe. No place/stamp/mutation.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ original raw scaffold CF |
| Live bytes | `read_memory` body + `ret 4` on all exits; JT @ `0x005204d0`; scale floats sealed |
| Full listing | `disassemble_function` — EBP frame; ECX this; switch tier−1; per-case FILD/FMUL/floor/FISTP-chop |
| Free-score consumer | dualed `Character_CalcCommodityTierFreeScore_Inferred` `0x00522780` (`max = this(tier)`) |
| UI consumer | `FUN_008e41b0` — `"Complexity: %i/%i"` uses this as max |
| Callers | **5** recovered (see table) |
| Clean | `reconstructed-exact/Character_CalcCommodityTierMaxCapacity_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile (with ABI seals)

| Stage | Match |
|---|---|
| Frame + 8-byte align stack | **Yes** (`AND ESP, -8`) |
| Tier from `[EBP+8]`; `tier-1`; `JA` default if >4 | **Yes** |
| Jump table 5 entries @ `0x005204d0` | **Yes** (`read_memory`) |
| `MOVZX` level from `[ECX+0x599]` per case | **Yes** |
| `FILD` level; `FMUL` tier scale; CRT `floor` IAT | **Yes** |
| FISTP with RC=chop (`OR AH,0xC`) → EAX | **Yes** (decompiler ROUND = chop) |
| Default `XOR EAX,EAX` | **Yes** |
| **`ret 4`** all exits | **Yes** (`C2 04 00`) |

### Body

| Field | Value |
|---|---|
| Start | `0x00520340` |
| End inclusive | `0x005204cd` |
| Size | **398 B** (`0x18E`) |
| Align / JT | `8B FF` @ `0x005204ce`; JT @ `0x005204d0` |

### Offsets / layout

| Item | Role | Confidence |
|---|---|---|
| `this+0x599` uint8 | level (family consensus) | **High** CF / **Open** product English |
| scale 3.5/2.8/2.1/1.4/0.7 | tier capacity multipliers | **High** |
| tier domain 1..5 | product tiers | **High** |
| floor→int | capacity is integer budget | **High** |

---

## 4. Callers (context, not owned)

| Caller | Site | Role |
|---|---|---|
| `FUN_00522780` free-score | `0x00522799` | max for free = max−used |
| `FUN_005226e0` | `0x005226f6` | Σ max tiers 1..5 |
| `FUN_005204f0` | `0x00520503` | Σ max tiers 0..5 (0→0) |
| `FUN_008e41b0` | `0x008e4222` | UI Complexity max |
| `FUN_008e55e0` | `0x008e563a` | UI host |

Partition parent `0x005244e0` is a **wave host** (five-row used-cost sum), not a structural caller of this unit.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Formula + scales + switch + default 0 | **High** |
| ABI thiscall + ret 4 | **High** |
| Role as max capacity / Complexity budget | **High** |
| Product method English | **Open** |
| +0x599 English ("level") | **Open** (family duals) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed level×tier-scale max capacity leaf; name Inferred; product English residual.
