# Review A (reconstruction fidelity): `aa_005204f0` Character_SumCommodityTierMaxCapacities (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005204f0` |
| **VA** | `0x005204f0`–`0x00520517` inclusive (**40 B** / `0x28`) |
| **Canonical name** | `Character_SumCommodityTierMaxCapacities` (**INFERRED**) |
| **Ghidra symbol** | `FUN_005204f0` |
| **Review date** | `2026-08-05` |
| **Agent** | R13-033 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_005204f0_Character_SumCommodityTierMaxCapacities_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | R13 residual dual; partition parent `0x00520340` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `search_byte_patterns` + `get_function_by_address` + `get_function_signature` + `get_function_hash`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Sum of level-scaled max commodity capacities** across the parent tier domain:

```c
// __thiscall: ECX = Character*
// ret 0 (no stack args on entry)
int Character_SumCommodityTierMaxCapacities(Character* ch) {
  int sum = 0;
  for (int tier = 0; tier < 6; ++tier)
    sum += Character_CalcCommodityTierMaxCapacity_Inferred(ch, tier);
  // tier 0 → 0 from parent default; effective Σ over tiers 1..5
  return sum;
}
```

Read-only aggregate capacity probe. No place/stamp/mutation.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ original raw scaffold CF (6-iter sum loop) |
| Live bytes | `read_memory` 40 B body; exit `C3`; CALL rel → `0x00520340` |
| Full listing | `disassemble_function` — EBX this; ESI tier; EDI sum; bound 6 |
| Parent max leaf | dualed `Character_CalcCommodityTierMaxCapacity_Inferred` `0x00520340` |
| Callers | **0** recovered (xrefs empty; LE data-ptr search empty) |
| Clean | `reconstructed-exact/Character_SumCommodityTierMaxCapacities_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile (with ABI seals)

| Stage | Match |
|---|---|
| Prolog PUSH EBX/ESI/EDI | **Yes** |
| `MOV EBX,ECX` this capture | **Yes** (decompiler omits this — **byte-sealed**) |
| EDI=sum0; ESI=tier0 | **Yes** |
| Loop: PUSH ESI; MOV ECX,EBX; CALL parent | **Yes** |
| ESI++; EDI+=EAX; CMP ESI,6; JL | **Yes** |
| EAX=EDI; POP*; **RET** (`C3`) | **Yes** |
| Align `LEA ESP,[ESP]` nop | **Yes** (`8D A4 24 00 00 00 00`) |

### Body

| Field | Value |
|---|---|
| Start | `0x005204f0` |
| End inclusive | `0x00520517` |
| Size | **40 B** (`0x28`) |
| Padding | `CC` from `0x00520518` |
| Hash | `d92f870e00782c00c40f2e7d135502a523f94ffedd62e5e56c6de5879d471343` |

### Offsets / layout

| Item | Role | Confidence |
|---|---|---|
| ECX this → EBX | Character* host | **High** |
| stack push = tier | parent arg (0..5) | **High** |
| parent +0x599 level | via dualed parent only | **High** (parent) |
| loop bound 6 | includes dead tier 0 | **High** |

---

## 4. Callers (context, not owned)

| Caller | Site | Role |
|---|---|---|
| *(none)* | — | No static CALL / data pointer recovered |

This unit is a **caller of** the partition parent, not a callee of it. Orphan status is a residual gap (possible dead code or unrecovered dynamic dispatch).

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Loop 0..5 sum of parent max | **High** |
| ABI thiscall + ret 0 | **High** |
| Tier 0 contributes 0 (parent default) | **High** (parent dual) |
| Effective Σ = tiers 1..5 max | **High** |
| Role as total Complexity budget | **High** (family) |
| Product method English | **Open** |
| Call sites / liveness | **Open** (orphan) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed thiscall sum-of-max wrapper; name Inferred; product English + caller residual.
