# Review B (skeptical / adversarial): `aa_00480460` AlignedFreelist_PopSlot_0x160_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480460` |
| **VA** | `0x00480460` |
| **Canonical name** | `AlignedFreelist_PopSlot_0x160_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00480460_AlignedFreelist_PopSlot_0x160_Inferred.md` |
| **System** | client audio / `CSoundManager` queue slot pool |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | “Size query” only | Allocates, chains, pops | **Falsified** as size-only |
| 2 | Mission fail notify semantics | Callee dual = Vector_PushDword; keyword rename residue | **Falsified** mission role |
| 3 | Slot size 0x150 (play instance) | Stride `0x58` int words = **0x160** | **Falsified** 0x150 claim |
| 4 | This is `FUN_00480170` | Different VA; 00480170 only writes tail fields | **Falsified** |
| 5 | True void / no return | Parents: `iVar = FUN_00480460(); if (iVar==0)` | **Falsified** pure-void model |
| 6 | Unlimited growth each pop | Only grows when empty; then pop | **Falsified** always-malloc |
| 7 | `0x5800` is coincidence | `0x40 * 0x160 = 0x5800` exact | **Attack fails** — sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slab 0x5800 / align 0x10 | **Confirmed** | Wrong pool size |
| 0x160 freelist stride | **Confirmed** | Overlap / corruption |
| Pop advances head | **Confirmed** | Leak freelist |
| EAX return of slot | **High** | Null-slot false OOM |
| Vector_PushDword name residue | **High** | Wrong mission coupling |
| Freelist head storage site | **Open** | Hook wrong global |

---

## 3. Cross-check

```
raw ≡ live.
0x40 * 0x160 = 0x5800.
piVar2 + 0x58 (int*) = +0x160 bytes.
piVar1[0x15a8] = last next 0.
Callee 004149d0 dual: pure Vector_PushDword — historical FailMissionNotify name is residue.
Parents assign return and null-check before 00480170.
```

### Rename trap

Coverage list `Mission_Uses_CVOGReaction_FailMissionNotify_00480460` is **keyword contamination** from the callee symbol. Function is an **audio slot freelist**, not mission fail.

### Parent dual trap

`A_aa_007258a0` “00480460 size → 00480170 alloc” is **wrong**. Invert: **00480460 = pool pop**, **00480170 = field init**.

---

## 4. Surviving contract for AutoCore

```
AlignedFreelist_PopSlot(pHead /*EDI*/):
  if empty: aligned_malloc(0x5800,16); track slab; chain 0x40 nodes of 0x160
  slot = *pHead; *pHead = slot->next; return slot  // EAX

AutoCore must NOT:
  - call mission fail APIs here
  - use 0x150 play-instance size for this pool
  - treat void decompiler print as no-return-value
  - grow on every successful pop
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Freelist pop 0x160 / slab 0x5800 | **Agree Confirmed** |
| FailMissionNotify = Vector_PushDword residue | **Agree High** |
| EAX return High | **Agree** |
| Head storage open | **Agree** |
| accept-with-gaps | **Agree** |
