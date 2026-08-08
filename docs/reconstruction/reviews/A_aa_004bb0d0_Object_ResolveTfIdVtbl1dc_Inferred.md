# Review A (reconstruction fidelity): `aa_004bb0d0` Object_ResolveTfIdVtbl1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0d0` |
| **VA** | `0x004bb0d0`–`0x004bb0f9` |
| **Canonical name (Ghidra)** | `FUN_004bb0d0` |
| **Proposed name** | `Object_ResolveTfIdVtbl1dc_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_004bb0d0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A — live Ghidra WQ9R-D) |
| **Reviewer role** | Reconstruction fidelity (thin resolve + virtual get) |
| **Counterpart** | `reviews/B_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve a compact TFID/target blob to an object, then return the result of `vtbl+0x1dc()`.**

Body (entire function):

1. `obj = CVOGReaction_ResolveObjectTarget(blob[+8] byte, blob[0], blob[1])` with **ECX = resolve ctx** from caller.
2. If null → return 0.
3. Else → return `obj->vtbl[+0x1dc]()`.

### Primary uses

- `Skill_FilterTargetForResolveList_Inferred`: after related-TFID path, `FUN_004bb0d0(FUN_0040aff0(tfid))` feeds crew helper `FUN_005749d0`.
- `CVOGHBAIBase_FindTargetToAttack` and several AI/object helpers (9 CODE xrefs).

**Not** resolve-only (`Object_ResolveFromTFID` `0x004bb950`), **not** vtbl+0x1d4 (`0x004bb010`), **not** vtbl+0x1d8 identity (`0x004bb070`), **not** free-arg Lookup (`0x004bb0a0` — same slot, different ABI).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.md` (+ v2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1dc_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` |
| Live Ghidra | `batch_decompile` / `analyze_function_complete` / `get_function_xrefs` / `read_memory` body |
| Sibling duals | `Object_ResolveTfIdVtbl1d4_Inferred` (`004bb010`); `Client_LookupObjectByTfid_Inferred` (`004bb0a0`) |
| Callee | `CVOGReaction_ResolveObjectTarget` `0x004bae70` (rel32 sealed) |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// ECX = resolve context (caller-supplied; body does not load ECX)
// stack TFID-head*; RET 4
void * __thiscall Object_ResolveTfIdVtbl1dc_Inferred(void *ctx, void *pBlob);
// returns: vtbl+0x1dc() result, or 0 if ResolveObjectTarget fails
```

| Item | Evidence |
|---|---|
| Stack arity 1 | `RET 4` @ both exit paths |
| ECX this/ctx | Body never writes ECX before CALL resolve; same class as `004bb010` |
| Sole direct callee | `CALL rel32` → `0x004bae70` |
| Virtual | `CALL [EDX+0x1dc]` after `MOV ECX,EAX` |

**Decompiler trap:** Ghidra signature omits ECX — same class of error as `Object_ResolveFromTFID` / `Vtbl1d4`.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Unpack +0 / +4 / +8 only | **Yes** |
| ResolveObjectTarget three-arg + ECX passthrough | **Yes** |
| Null → 0 | **Yes** |
| Else vtbl+0x1dc return | **Yes** |
| No other branches / stores | **Yes** |

**Body hex:** `8b4424048b5004528b108a40085250e88cfdffff85c0740d8b108bc8ff92dc010000c2040033c0c20400`

Byte twin of `004bb010` with `D4 01` → `DC 01` and different resolve rel32.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thin resolve + virtual get | **High** | 42-byte body |
| ECX passthrough ABI | **High** | bytes + sibling family |
| Slot `+0x1dc` exact | **High** | `FF 92 DC 01 00 00` |
| Distinct from free-arg Lookup | **High** | `RET 4` vs `RET 0xc` / arg packing |
| Product name of `+0x1dc` | **Tentative** | `_Inferred`; role matches Lookup sibling |
| Return = identity always | **Probable** | may unwrap host/outer |

---

## 6. Gaps / open

1. Product/PDB name of `vtbl+0x1dc`.
2. Whether return is always identity-equal to resolved `obj`.
3. Exhaustive per-caller ECX provenance (not dual-owned).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**.
