# Review A (reconstruction fidelity): `aa_00522780` Character_CalcCommodityTierFreeScore (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522780` |
| **VA** | `0x00522780` |
| **Canonical name** | `Character_CalcCommodityTierFreeScore` (**INFERRED**) |
| **Ghidra symbol** | `FUN_00522780` |
| **Review date** | `2026-08-05` |
| **Agent** | R10-036 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | R10 residual dual; parent `0x00522710` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Compute a float free-capacity score** for one commodity TFID tier row on Character:

```c
// __thiscall: ECX = Character*
// ret 8: tier (1..5), tfidRow[5]{lo,hi}
float Character_CalcCommodityTierFreeScore(Character* ch, uint32_t tier, const uint32_t* row) {
  int used = Character_SumCommodityTfidRowCost(ch, tier, row); // FUN_00522710
  int max  = FUN_00520340(ch, tier);
  int free = max - used;
  if (free < 0) return 0.0f;
  // base/scale by tier 1..5; else 0
  // return (level * scale + (base + free*2)) * 0.01f
  // level = *(uint8_t*)(ch + 0x599)
}
```

Read-only score worker (no inventory mutation).

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` ≡ raw scaffold CF |
| Live bytes | `read_memory` body `0x00522780`–`0x0052283d` (**189 B**); dual `ret 8`; jump table `@0x00522840` |
| Float globals | `read_memory` on scale/0.01/zero VAs (2.5, 2.0, 1.5, 1.0, 0.5, ≈0.01, 0.0) |
| Parent callee | `Character_SumCommodityTfidRowCost_Inferred` dual sealed 2026-08-04 |
| Max callee | `FUN_00520340` — level×scale floor (context only) |
| Caller | `FUN_00522860` @ `0x005228c0` sole xref |
| Clean | `reconstructed-exact/Character_CalcCommodityTierFreeScore_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile

| Stage | Match |
|---|---|
| ECX → ESI this | **Yes** (`mov esi, ecx`) |
| Call `FUN_00522710(tier, row)` with this | **Yes** (pushes + ECX=this) |
| Call `FUN_00520340(tier)` with this | **Yes** |
| `free = max - used`; `js` → zero | **Yes** |
| `tier-1` bounds check `>4` → zero | **Yes** |
| Jump table cases 1..5 set base + scale | **Yes** (imm + `movss` loads) |
| `movzx` level `@this+0x599` | **Yes** |
| `fild` level; `fmul` scale; `fiadd` `(base+free*2)`; `fmul` 0.01; `ret 8` | **Yes** |
| Zero path: `fld g_flZero`; pop; `ret 8` | **Yes** |

### Body

| Field | Value |
|---|---|
| Start | `0x00522780` |
| End exclusive | `0x0052283d` |
| Size | **189 B** (`0xBD`) |
| Data after | Jump table 5× rel32 `@0x00522840` |

### Tier table (sealed)

| Tier | base | scale VA | scale |
|----:|-----:|---|---:|
| 1 | 50 | `0x00aaa6c4` | 2.5 |
| 2 | 40 | `0x00a10e74` | 2.0 |
| 3 | 30 | `0x00aaa68c` | 1.5 |
| 4 | 20 | `0x00a0f2a0` | 1.0 |
| 5 | 10 | `0x00a0f298` | 0.5 |

---

## 4. Callers (context, not owned)

| Caller | Role |
|---|---|
| `FUN_00522860` | For tiers 0..4 (`i+1`): if head TFID non-null, multiply running product by this score; else require remaining pairs null |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Formula + early-outs | **High** |
| ABI thiscall + ret 8 | **High** |
| Tier base/scale table | **High** |
| Parent used-cost callee | **High** |
| Product method English | **Open** |
| Semantic label of score (UI/craft) | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed free-capacity score worker; name Inferred; product English open.
