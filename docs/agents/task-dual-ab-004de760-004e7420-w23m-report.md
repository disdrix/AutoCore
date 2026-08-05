# Dual A/B report — W23-M OWN `aa_004de760` + `aa_004e7420`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-M  
**Scope:** VAs `0x004de760`, `0x004e7420` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004de760` CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred | **accept-with-gaps** — CF/ABI/Deliver gate/modes 5·8 sealed; host `+0xfc` / mode English residual |
| `aa_004e7420` RbTree_InitEmptyHeader_Node1c | **accept** — 43 B empty tree header: alloc 0x1c node, `+0x19=1`, self-link L/P/R, size 0, return this |

---

## VA `0x004de760` — sealed facts

1. **Body:** `0x004de760`–`0x004de9e6` (647 B / `0x287`).
2. **ABI:** **`__thiscall`** (ECX = host*); stack `character*`, `optionalObject*`; **`ret 8`**.
3. **Lock:** `character+0x55c` pending-objectives CNDHash; TraversalLock byte `hash+0x1d` (strings `HashError:TraversalLock…` / `TraverseToNext…` / `VOG_DEBUG_STOP`).
4. **Walk:** hash head `+0x14`, next `node+0x14`, entry `node+0x8`; objective evaluators vector `+0x158/+0x15c`.
5. **Deliver gate:** vcall `+0x50 == 3` then `__RTDynamicCast` → `CVOGObjectiveRequirement_Deliver`.
6. **Filters:** `deliver[7]` (`+0x1c`) == `host+0xfc`; object MI `+0x34` == `deliver[6]` (`+0x18`).
7. **Register:** `FUN_004dbef0` modes **5** (predicate `+0xc` false) / **8** (true); links `-1,-1`; objective id from entry.
8. **optObject==0:** scan host list via char MI `+0xa8` → `+0xe4e8` vector + vcall `+0x1d8`.
9. **Callers:** Patrol_InitActive, `FUN_00610e60`, `FUN_004dea70`, `FUN_0080af70`, `FUN_0092a440`.
10. **Name:** `CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred` (Ghidra `FUN_004de760`). **Reject** coverage alias RTTI Type Descriptor.
11. **Decompile ≡ entry/exit bytes** for ABI + lock/unlock; CF sealed from decompile.

### Gaps

- Product English for host `+0xfc` and register modes 5/8.  
- Deliver predicate vcall `+0xc` product name.  
- Nested list/`+0xe4e8` dual residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004de760_FUN_004de760.md` |
| Annotated | `docs/reconstruction/raw/aa_004de760_FUN_004de760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004de760.cpp` |
| Function | `docs/reconstruction/functions/aa_004de760_FUN_004de760.md` |
| Function named | `docs/reconstruction/functions/aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004de760.md` |

---

## VA `0x004e7420` — sealed facts

1. **Body:** `0x004e7420`–`0x004e744a` (43 B / `0x2b`).
2. **ABI:** **`__thiscall`** on header (ECX); no stack formals; plain **`ret`**; returns **this** in EAX.
3. **Alloc:** `call FUN_005ae2b0` → `operator_new(0x1c)` empty node (zeros L/P/R; `+0x18=1`; `+0x19=0`). Rel32 **Confirmed**.
4. **Header:** `+4 = node*`; `+8 = size = 0`.
5. **Node:** `+0x19 = 1` (head/nil); left/parent/right **self-linked** (`+0`, `+4`, `+8`).
6. **Role:** empty MSVC-style `_Tree` / RB-tree header init for **0x1c-node** flavor.
7. **Callers:** `FUN_004d8a10` ×2 (`0x004d8d92`, `0x004d8d9d`).
8. **Sibling (not owned; W22-R sealed):** `FUN_004e7450` / `RbTree_InitEmptyHeader` — 0x18 factory + flag **`+0x15`**.
9. **Name:** `RbTree_InitEmptyHeader_Node1c` (Ghidra `FUN_004e7420`).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product C++ typedef for this 0x1c-node map flavor.  
- Whether `header+0` is a live adjacent field (untouched here).  
- OOM null-head path (retail stores without null check).  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e7420_FUN_004e7420.md` |
| Annotated | `docs/reconstruction/raw/aa_004e7420_FUN_004e7420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RbTree_InitEmptyHeader_Node1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e7420.cpp` |
| Function | `docs/reconstruction/functions/aa_004e7420_FUN_004e7420.md` |
| Function named | `docs/reconstruction/functions/aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` |
| Scratch | `docs/reconstruction/tmp/a_004e7420.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004de760` | After give-item / patrol init / deliver host paths: rescan **pending Deliver** only; preserve TraversalLock; register object links with modes **5/8**; do not treat as Collect or as RTTI data. |
| `004e7420` | Empty maps of the **0x1c** flavor: factory + this header init (self-link + size 0 + head flag **`+0x19`**). Do **not** reuse 0x18 / `+0x15` offsets from sibling `004e7450`. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004e7450` | `RbTree_InitEmptyHeader` — 0x18 / `+0x15` (W22-R sealed) |
| `0x005ae2b0` | 0x1c node factory for this header unit |
| `0x00439770` | 0x18 node factory for sibling header |
| `0x004dbef0` | `CVOGReaction_RegisterObjectHashEntry_Inferred` (callee of `004de760`) |
| `0x004d8a10` | large ctor calling both header flavors |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
