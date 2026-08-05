# Review A (reconstruction fidelity): `aa_00480460` AlignedFreelist_PopSlot_0x160_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480460` |
| **VA** | `0x00480460` |
| **Canonical name** | `AlignedFreelist_PopSlot_0x160_Inferred` |
| **Ghidra symbol** | `FUN_00480460` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00480460_AlignedFreelist_PopSlot_0x160_Inferred.md` |
| **System** | client audio / `CSoundManager` queue slot pool |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Lazy freelist pop** for fixed-size **sound queue slots** (`0x160` bytes each).

Authoritative stages (live ≡ raw):

1. **`EDI` points at freelist head pointer** (decompiler `unaff_EDI` = `&head`).
2. If head is null **or** `*head == 0` (empty / exhausted chain):
   - `slab = _aligned_malloc(0x5800, 0x10)` — **0x40 × 0x160 = 0x5800**
   - Call historical symbol **`CVOGReaction_FailMissionNotify(&slab)`** — dual of `0x004149d0` seals this as **generic `Vector_PushDword`** (register slab into a tracking vector; name is call-graph residue, **not** mission fail).
   - `*head = slab`
   - Chain **0x3F** freelist links: each slot’s first dword → next slot (`int*` stride `+0x58` dwords = **+0x160** bytes)
   - Last slot next: `slab[0x15a8] = 0` (`0x3F * 0x58 = 0x15A8` dword index)
3. **Pop:** advance head (`*head = **head`). Decompiler prints **void**; parents use **return as slot pointer** → classic **EAX = previous head** under-recovered by Ghidra.
4. Parents: null check → treat as OOM; else hand slot to `FUN_00480170` + field fill.

**Not** a “size query.” Parent dual wording that paired this with “alloc at 00480170” is inverted: **this VA is the pool/alloc side**.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_00480460_*` | CF ≡ live |
| Live decompile | Ghidra `0x00480460` | sealed |
| Complete analysis | 4 xrefs; callees `_aligned_malloc`, `CVOGReaction_FailMissionNotify` | |
| FailMissionNotify dual | `A_aa_004149d0` → **Vector_PushDword** | name residue |
| Parent | `FUN_007258a0` / siblings | freelist pop before init |

### Arithmetic seal

| Quantity | Value |
|---|---|
| Slot size | `0x58 * sizeof(int) = 0x160` |
| Slots per slab | `0x40` (0x3F links + first) |
| Slab bytes | `0x40 * 0x160 = 0x5800` |
| Last next index | `0x3F * 0x58 = 0x15A8` dwords |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `_aligned_malloc(0x5800, 0x10)` | **Confirmed** | body |
| Freelist link stride **0x160** | **Confirmed** | `piVar2 + 0x58` on `int*` |
| 0x40 slots / last next 0 | **Confirmed** | loop + `piVar1[0x15a8]=0` |
| EDI = `&freelist_head` | **High** | unaff_EDI pattern + pop |
| Returns popped slot (EAX) despite void print | **High** | all parents assign return |
| `CVOGReaction_FailMissionNotify` is **not** mission logic here | **High** | dual = Vector_PushDword; tracks slab |
| Exact tracking vector `this` (ECX into push) | **Medium** | reg-lost in decompile |
| Empty test `*head==0` vs null-head dual meaning | **Medium** | both arms trigger grow |
| Product pool name | **Open** | structural |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Empty check | Yes |
| Aligned slab alloc | Yes |
| Register slab (vector push residue name) | Yes |
| Chain freelist | Yes |
| Pop head | Yes |

```c
// Slot* AlignedFreelist_PopSlot(Slot **pHead)  // pHead in EDI; return in EAX
void FUN_00480460(void)
{
  if (*pHead == 0 || *(int *)*pHead == 0) {
    Slot *slab = _aligned_malloc(0x5800, 0x10);
    Vector_PushDword(/*track*/, &slab);   // misnamed CVOGReaction_FailMissionNotify
    *pHead = slab;
    for (int i = 0x3F; i != 0; --i) {
      *(Slot **)slab = (Slot *)((char *)slab + 0x160);
      slab = (Slot *)((char *)slab + 0x160);
    }
    /* last */ next = 0;
  }
  // EAX = old *pHead; *pHead = (*pHead)->next;  // return under-recovered
  *pHead = *(Slot **)*pHead;
}
```

---

## 5. Callers / callees

**Callees:** `_aligned_malloc`, `CVOGReaction_FailMissionNotify` (`0x004149d0` / Vector_PushDword).

**Callers (4):** `FUN_007252d0`, `FUN_007258a0`, `FUN_00725a70`, `FUN_00725bd0`.

---

## 6. Gaps / open

1. Where freelist head lives on `CSoundManager` (static vs manager field) — EDI source residual.
2. Slab free / process teardown.
3. Decompiler void vs EAX return (port must return slot).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — freelist math and role sealed; head location residual.
