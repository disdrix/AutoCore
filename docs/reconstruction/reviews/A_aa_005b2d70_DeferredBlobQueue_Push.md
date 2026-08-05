# Review A (reconstruction fidelity): `aa_005b2d70` DeferredBlobQueue_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2d70` |
| **VA** | `0x005b2d70` |
| **Canonical name** | `DeferredBlobQueue_Push` (inferred; Ghidra `FUN_005b2d70`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b2d70_DeferredBlobQueue_Push.md` |
| **System** | input-drive-control / ghost deferred events / skills HB unpack |
| **Evidence pass** | Live `batch_decompile` + grow helper `FUN_005b2c10`; callers `VehicleNet_UnpackOwnerSkillsHB`, `VehicleNet_PostCorrectionEvent` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Push one dword/pointer element** into a **ring / block-deque** container:

Container layout (this):

| Off | Field | Role |
|---|---|---|
| +0x04 | block table `T**` | array of 16-byte block pointers |
| +0x08 | block capacity (count of block slots) | grow threshold |
| +0x0C | head index | start |
| +0x10 | count | element count |

Algorithm:

1. If `(head+count) % 4 == 0` **and** `capacity <= (count+4)>>2` → `FUN_005b2c10(1)` grow block table.
2. `idx = head + count`; `slot = idx >> 2` (block index, wrap if `slot >= capacity`).
3. If `blocks[slot] == null` → `operator_new(0x10)` (4 dword cells).
4. `cell = blocks[slot] + (idx & 3)`; if non-null `*cell = *param_2` (copy one dword from arg).
5. `count++`.

So each block holds **4** elements; growth via `FUN_005b2c10` reallocates the block-pointer vector (ring-preserving memmoves).

**Callers:**

| Caller | Payload |
|---|---|
| `VehicleNet_UnpackOwnerSkillsHB` `0x005b2690` | skills/HB node record |
| `VehicleNet_PostCorrectionEvent` `0x005f7360` | deferred equip blob ptr (0x203C/0x203E) |

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b2d70_FUN_005b2d70.md` |
| Annotated | `docs/reconstruction/raw/aa_005b2d70_FUN_005b2d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b2d70.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b2d70_FUN_005b2d70.md` |
| Parent duals | `A_aa_005b2690_*`, `A_aa_005f7360_*` |

**Three-rep:** present.

---

## 3. Signature

```c
void __thiscall DeferredBlobQueue_Push(void *queue, uint32_t *elemPtr /* one dword copied */);
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| grow gate `(head+count)&3==0` && capacity tight | **Yes** | **High** |
| slot = (head+count)>>2 with wrap | **Yes** | **High** |
| lazy new 0x10 block | **Yes** | **High** |
| store *elem at cell; count++ | **Yes** | **High** |
| Clean ≡ raw | **Yes** | **High** |

### Decompiler hazards

- `FUN_005b2c10` end `operator_delete` “does not return” — **false** (grow continues after free in real CRT; residual same family as other MSVC decomp).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 4-wide block ring push of one dword | **High** | body |
| Grow via `FUN_005b2c10` | **High** | live |
| Used for skills HB nodes + deferred equip blobs | **High** | callers |
| Container product name | **Tentative** | inferred |
| Full drain/pop API | **Open** | not this VA |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Dual the pop/drain consumer that processes PostCorrection blobs.
2. Confirm whether skills path stores pointer-sized node heads vs inline records (caller builds then pushes address-shaped dword).

**Verdict:** **accept-with-gaps**
