# Review A (reconstruction fidelity): `aa_004b73c0` NDSpecialFX_SetHostObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b73c0` |
| **VA** | `0x004b73c0` |
| **Canonical name (Ghidra)** | `FUN_004b73c0` |
| **Proposed name** | `NDSpecialFX_SetHostObject_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004b73c0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004b73c0_NDSpecialFX_SetHostObject_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX param host |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind a **host game object** onto an NDSpecialFX-like controller:

1. Store host pointer at **`this+0x10`**.
2. Cache host **TFID / identity block** at **`this+0x18..+0x24`**:
   - If `host == NULL`: copy sentinel `DAT_009cb2a0..ac` = **`(-1,-1,0,0)`** (`read_memory` sealed).
   - Else: copy **`host+0x160..+0x16c`** (same 16-byte TFID limb layout used elsewhere).
3. If host non-null: walk intrusive list at **`this+0x204`** (node next = `*node`; end when node == list head). For each node with **`node[2] != 0`**, call **`FUN_0058e370(host)`** (reattach / notify child FX component).

Early-return on null host after sentinel copy (no list walk).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004b73c0` |
| Raw / annotated / clean | `raw/aa_004b73c0_*`, `reconstructed-exact/FUN_004b73c0.cpp` |
| Function record | `functions/aa_004b73c0_FUN_004b73c0.md` |
| Sentinel | `read_memory` `0x009cb2a0` → `ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00` |

**This pass:** live decompile; bulk xrefs; FireHelper / interact attach call sites. **No** Launcher / ledgers.

---

## 3. Signature

```c
void __thiscall NDSpecialFX_SetHostObject_Inferred(void *fx, void *hostObject /* may be NULL */);
```

---

## 4. Callers (sample; 17 xrefs)

| Caller cluster | Examples | Role |
|---|---|---|
| Weapon fire / session init | `FUN_0056d160` @ `0056d1ad` | After `FUN_004ec010(8)` session alloc — bind weapon host |
| Interact / reaction attach | `FUN_00518590` | Bind reaction target object then `FUN_004b75d0` |
| Skill / combat FX binders | `00553f50`, `00553ff0`, `00555050`, `005557a0`, `00555f10`, `00556da0` | Host rebinding when FX attached to entity |
| Vehicle / drive FX | `FUN_005a9400` | Water/drive-related FX host |
| Other | `FUN_0099c720`, `FUN_00518590` peers | Broad client FX surface |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `this+0x10 = host` | Yes |
| null → copy `DAT_009cb2a0` quartet → return | Yes |
| non-null → copy `host+0x160` quartet | Yes |
| walk `this+0x204` list; gated `FUN_0058e370(host)` | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `+0x10` = host object pointer | **High** | `004b75d0` null-checks `this+0x10` before vtbl `+0x1cc` |
| `+0x18` = TFID-like 16B cache | **High** | same limbs as entity `+0x160`; null sentinel −1/−1/0/0 |
| Null early-out skips child notify | **High** | decompile |
| List at `+0x204` is doubly/intrusive linked (next=`*node`) | **High** | standard pattern; end = head ptr |
| `node[2]` payload gate | **High** | nonzero before `FUN_0058e370` |
| `FUN_0058e370` English (reattach child) | **Probable** | not dualed this pass |
| Product name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Exact type of list elements at `+0x204` and full contract of `FUN_0058e370`.
2. Whether `host+0x160` is always TFID vs shared identity block (layout matches TFID consumers).

**Verdict:** **accept-with-gaps**
