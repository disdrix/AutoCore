# Review A (reconstruction fidelity): `aa_00560750` PhysHost_MergeSortedPairList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560750` |
| **VA** | `0x00560750`–`0x00560a2c` |
| **Body** | **733 bytes** (`0x2DD`) |
| **Canonical name** | `PhysHost_MergeSortedPairList_Inferred` |
| **Ghidra name** | `FUN_00560750` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-S) |
| **Counterpart** | `reviews/B_aa_00560750_PhysHost_MergeSortedPairList_Inferred.md` |
| **System** | phys host merge — sorted pair list @ host+0x68 |
| **Evidence pass** | Live Ghidra decompile + read_memory + get_function_by_address + analyze_function_complete + assembly context at sole caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

During host island merge (`PhysSim_MergeHosts`), merge **src** `host+0x68` sorted stride-16 pair list into **dest**'s list:

1. Snapshot dest via `LocalWorklist16_Init` (`0055f520`).
2. Grow dest for combined count (`005b3300` elem 0x10).
3. Dual-key ordered merge on `*(entry[0])+4`, `*(entry[1])+4`.
4. Equal keys → vcall `entry[2].vtbl+0x14` then partner `vtbl+0x10`; drop one equal.
5. Drain tails; set final count; release worklist (inline arena free).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560750_FUN_00560750.md` (+ W29-S) |
| Annotated | `docs/reconstruction/raw/aa_00560750_FUN_00560750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysHost_MergeSortedPairList_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560750.cpp` |
| Function records | `functions/aa_00560750_*.md` |
| Parent dual | W20-B `PhysSim_MergeHosts_Inferred` (callee gap closed here) |
| Worklist dual | W28-R `LocalWorklist16_Init` |

---

## 3. Signature (sealed)

```c
// EAX = dest list*; stack = src list*; void; plain ret
void PhysHost_MergeSortedPairList_Inferred(void* dest /*EAX*/, void* src /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| dest | EAX (`MOV ESI,EAX`) | **High** |
| src | Stack[0x4] | **High** |
| cleanup | plain ret; caller `ADD ESP,4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
snap = LocalWorklist16_Init(dest.count); copy dest → snap
grow dest for dest.count+src.count
merge(snap, src) by dual keys @+4
  less → emit; equal → vcall absorb, skip both
final_count = (dest_n - equals) + src.count; drain tails
release snap worklist via DAT_00b05060
```

| Stage | Match | Conf |
|---|---|---|
| EAX dest ABI | **Yes** | **High** |
| Stride 0x10 / dual key | **Yes** | **High** |
| Equal-key vcalls | **Yes** | **High** |
| Worklist init/release | **Yes** | **High** |
| Sole caller merge hosts | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry: `83 EC 28 56 8B F0` — dest from **EAX**.
- Call `0055f520` with dest count; grow `005b3300` with elem **0x10**.
- Exit: `83 C4 28 C3`.
- Sole call site `0x00560a6c`: `LEA EAX,[ESI+0x68]; PUSH EBP; PUSH EAX; LEA EAX,[EDI+0x68]; CALL`; later `ADD ESP,4`.
- Body **733 B**.

---

## 6. Gaps

- Product English for pair-record / virtual absorb methods.
- Record dword at +0x0C meaning.
- Caller `PUSH EBP` purpose (function ignores Stack[0x8]).
- Runtime / bit-exact — open.

---

## 7. Verdict

Merge CF/ABI sealed; parent W20-B gap on `00560750` closed → **accept-with-gaps**.
