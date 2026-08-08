# Review A (reconstruction fidelity): `aa_005226e0` Character_SumCommodityTierMaxCapacities (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005226e0` |
| **VA** | `0x005226e0`–`0x00522709` inclusive (**42 B** / `0x2A`) |
| **Canonical name** | `Character_SumCommodityTierMaxCapacities` (**INFERRED**) |
| **Ghidra symbol** | `FUN_005226e0` |
| **Review date** | `2026-08-05` |
| **Agent** | R13-034 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | R13 residual dual; partition parent `0x00520340` |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Sum level-scaled max commodity capacity** across product tiers 1..5:

```c
// __thiscall: ECX = Character*
// RET (no stack args)
int Character_SumCommodityTierMaxCapacities(Character* ch) {
  int sum = 0;
  for (int tier = 1; tier <= 5; ++tier)
    sum += Character_CalcCommodityTierMaxCapacity(ch, tier); // FUN_00520340
  return sum;
}
```

Read-only capacity aggregate. No place/stamp/mutation.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ original raw scaffold CF (loop 1..5 sum max) |
| Live bytes | `read_memory` body `0x005226e0`–`0x00522709` (**42 B**); `C3` RET; CALL rel → `0x00520340` |
| Full listing | `disassemble_function` — EBX=this; ESI=tier; EDI=sum; push tier; CALL max |
| Parent callee | dualed `Character_CalcCommodityTierMaxCapacity_Inferred` `0x00520340` (R12-018) |
| Callers | **0** recovered (`xref_count=0`; no data ptr) |
| Clean | `reconstructed-exact/Character_SumCommodityTierMaxCapacities_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile (with ABI seals)

| Stage | Match |
|---|---|
| Save EBX/ESI/EDI | **Yes** |
| `MOV EBX,ECX` this | **Yes** (decompiler omits — **bytes win**) |
| Seed sum=0, i=0 | **Yes** (`XOR EDI` / `XOR EAX`) |
| `LEA ESI,[EAX+1]` tier | **Yes** |
| `PUSH ESI`; `MOV ECX,EBX`; `CALL FUN_00520340` | **Yes** |
| `ADD EDI,EAX` accumulate | **Yes** |
| `CMP EAX,5` / `JL` loop while tier < 5 | **Yes** → tiers **1..5** |
| `MOV EAX,EDI`; POP*; **`RET`** | **Yes** (`C3`) |

### Body

| Field | Value |
|---|---|
| Start | `0x005226e0` |
| End inclusive | `0x00522709` |
| Size | **42 B** (`0x2A`) |
| Pad | `CC` after RET |

### Offsets / layout

| Item | Role | Confidence |
|---|---|---|
| ECX this | Character* for max leaf | **High** |
| tier domain 1..5 | five product tiers | **High** |
| sum int EAX | total max capacity | **High** |
| leaf scales | owned by parent dual | **High** (context) |

---

## 4. Callers (context, not owned)

| Caller | Site | Role |
|---|---|---|
| *(none recovered)* | — | Ghidra xref_count=0; no `E0 26 52 00` data refs |

Structural consumers of the **leaf** (not this wrapper): free-score `00522780`, UI Complexity, sibling sum `005204f0`.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Loop 1..5 + sum + sole callee | **High** |
| ABI thiscall + RET | **High** |
| Role Σ max capacity over tiers | **High** |
| Product method English | **Open** |
| Call graph / live use | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed Σ max tiers 1..5 thiscall wrapper; name Inferred; callers residual.
