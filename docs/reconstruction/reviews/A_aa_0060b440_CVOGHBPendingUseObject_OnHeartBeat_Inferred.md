# Review A (reconstruction fidelity): `aa_0060b440` CVOGHBPendingUseObject_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b440` |
| **VA** | `0x0060b440`–`0x0060b49f` |
| **Canonical name (proposed)** | `CVOGHBPendingUseObject_OnHeartBeat_Inferred` |
| **Ghidra name** | `FUN_0060b440` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-T) |
| **Counterpart** | `reviews/B_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md` |
| **System** | heartbeat / missions-progression |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` |
| **Verdict** | **accept** on CF/ABI/fields/Remove token; **accept-with-gaps** on product English |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta/xrefs/callees). **No** `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

OnHeartBeat for the pending-use-object HB (vtbl `PTR_FUN_009df668+0x0C`):

1. Gate: owner, character `+0x28`, secondary `+0x24`, not stopped.
2. If `character[+0xc9c] != secondary` → `*out = Remove (16)`.
3. Else commit `ResolveUseObjectPending(1)` then `RescheduleAfterFire`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060b440_FUN_0060b440.md` (+ W26-T append) |
| Annotated | `docs/reconstruction/raw/aa_0060b440_FUN_0060b440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBPendingUseObject_OnHeartBeat_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060b440.cpp` |
| Function | `docs/reconstruction/functions/aa_0060b440_FUN_0060b440.md` |
| Named | `docs/reconstruction/functions/aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md` |
| Live | decompile ≡ raw CF; body 96 B; `DAT_00af49ac` = 16 |
| Vtbl | `read_memory 0x009df668` → OnHB slot `0x0060b440` |
| Ctor context | `FUN_0060b380` sets `+0x24` secondary, `+0x28` character, type tag **10** |

---

## 3. Signature (sealed)

```c
std::uint32_t* __thiscall FUN_0060b440(
    CVOGHBPendingUseObject* self, std::uint32_t* pOutStatus);
// ret 4; returns pOutStatus
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX | **High** |
| pOutStatus | Stack[0x4] | **High** |
| return | EAX = pOut | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if !owner || !char(+0x28) || !sec(+0x24) || stopped:
  *out = 16; return out
if char[+0xc9c] != sec:
  *out = 16; return out
ResolveUseObjectPending(char, 1)
RescheduleAfterFire(this, out)
return out
```

| Stage | Match | Conf |
|---|---|---|
| Four-part gate | **Yes** | **High** |
| Secondary match `+0xc9c` | **Yes** | **High** |
| Commit path | **Yes** | **High** |
| Remove = 16 | **Yes** | **High** (`read_memory`) |
| Field map vs decomp pads | **Corrected** | **High** (bytes) |

---

## 5. Decompiler corrections (sealed)

| Decomp | Reality |
|---|---|
| `param_1[1].pVTable` | `*(this+0x28)` character* |
| packed `bHeatAtMaxDebounce…` | `*(this+0x24)` secondary* |
| uninit `pOutNextDelayMs` | same stack out as `param_2` |

---

## 6. Gaps / open

1. Product English for HB / first-time event period (`object+0x25c` ×1000).
2. Post-commit list fate (Reschedule vs next beat Remove) — runtime residual.
3. No direct CODE callers (virtual only) — expected for OnHeartBeat.

**Verdict:** CF spine **accept High**. Product name **accept-with-gaps** (`_Inferred`).
