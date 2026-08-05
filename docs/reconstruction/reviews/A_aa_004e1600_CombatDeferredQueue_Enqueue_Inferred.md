# Review A (reconstruction fidelity): `aa_004e1600` CombatDeferredQueue_Enqueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e1600` |
| **VA** | `0x004e1600` |
| **Canonical name (Ghidra)** | `FUN_004e1600` |
| **Proposed name** | `CombatDeferredQueue_Enqueue_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e1600` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004e1600_CombatDeferredQueue_Enqueue_Inferred.md` |
| **System** | `combat` / deferred multi-hit record queue |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Thread-safe enqueue of a deferred combat payload** onto a singly-linked queue owned by `this`.

Used by `Client_Combat_ApplyMultiTargetHits_Inferred` (`0x004da2e0`) to submit the **0x28 multi-hit record** after the per-target apply loop when host flag `+0x7E` is set. Also called from `FUN_004d7e30`.

### Control flow

1. SEH frame `LAB_009a24b0`.
2. If `payload (param_2) == NULL` → return 0 (low byte clear; ExceptionList-masked artifact).
3. `operator_new(0xc)` node:
   * `node[0] = &PTR_FUN_009cc1d4` (vtable)
   * `node[1] = 0` then **overwrite with payload**
   * `node[2] = 0` (next pointer)
4. Optional outer lock: if `this+0xc < 4`, `EnterCriticalSection(this+0x28)`.
5. Always `EnterCriticalSection(this+0x10)`.
6. Link:
   * Empty (`this+8 == 0`): `this+4 = this+8 = node` (head = tail).
   * Else: `tail->next = node`; `this+8 = node`.
7. `FUN_004e16b3` epilogue: leave CS `+0x10`, optionally leave CS `+0x28`, `InterlockedIncrement(this+0xc)` (published count).

### Queue object layout (inferred)

| Offset | Field |
|---|---|
| `+0x04` | head node* |
| `+0x08` | tail node* |
| `+0x0c` | count (Interlocked) |
| `+0x10` | CRITICAL_SECTION (inner) |
| `+0x28` | CRITICAL_SECTION (outer; used when count < 4) |

### Node layout (0xC)

| Offset | Field |
|---|---|
| `+0x00` | vtbl `PTR_FUN_009cc1d4` |
| `+0x04` | payload* (e.g. 0x28 hit record) |
| `+0x08` | next* |

**Not** the hit apply itself (`004d78e0`), not the multi-target walker (`004da2e0`), not record construction (caller).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004e1600` |
| Epilogue | live `FUN_004e16b3` (leave CS + InterlockedIncrement) |
| Callers | `get_function_callers` → `004d7e30`, `004da2e0` |
| Parent dual | `A_aa_004da2e0_*` Phase 2 deferred record |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004e1600` |
| Function record | `docs/reconstruction/functions/aa_004e1600_FUN_004e1600.md` |

**This pass:** live decompile; callers; epilogue. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = deferred combat queue host
uint __thiscall CombatDeferredQueue_Enqueue_Inferred(
    void *queue,     // this
    void *payload);  // param_2 — non-null record (e.g. 0x28 multi-hit pack); null = no-op
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `operator_new(0xc)` | Allocate list node |
| `EnterCriticalSection` | Inner `+0x10`; optional outer `+0x28` |
| `FUN_004e16b3` | Unlock + InterlockedIncrement count |
| `PTR_FUN_009cc1d4` | Node vtable |

| Caller | Role |
|---|---|
| `0x004da2e0` | Multi-target deferred pack submit |
| `0x004d7e30` | Sibling combat path |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null payload early return | Yes |
| 0xC node + vtbl + payload store | Yes |
| Outer CS when count < 4 | Yes |
| Inner CS always | Yes |
| Empty vs append-tail link | Yes |
| Epilogue unlock + count++ | Yes (`004e16b3`) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thread-safe SLL enqueue of payload | **High** | body |
| Node size 0xC, vtbl `009cc1d4` | **High** | |
| Count at `+0xc`, locks at `+0x10`/`+0x28` | **High** | |
| Used for deferred multi-hit records | **High** | caller `004da2e0` |
| Outer CS only when count < 4 | **High** | explicit |
| Product queue class name | **Tentative** | `_Inferred` |
| Consumer/drain side of queue | **Open** | not this unit |

---

## 7. Gaps / open

1. Product name of queue type and node type.
2. Who drains/processes enqueued 0x28 records.
3. Why outer CS gated on `count < 4` (startup / bootstrap **Probable**).
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — enqueue CF High; drain consumer residual.
