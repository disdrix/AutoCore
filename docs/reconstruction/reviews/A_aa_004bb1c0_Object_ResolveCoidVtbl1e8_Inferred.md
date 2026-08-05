# Review A (reconstruction fidelity): `aa_004bb1c0` Object_ResolveCoidVtbl1e8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb1c0` |
| **VA** | `0x004bb1c0`–`0x004bb1e9` |
| **Canonical name (Ghidra)** | `FUN_004bb1c0` |
| **Proposed name** | `Object_ResolveCoidVtbl1e8_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Client_UpdateNpcInteractIcons_004bb1c0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W18-T) |
| **Reviewer role** | Reconstruction fidelity (thin resolve + virtual get) |
| **Counterpart** | `reviews/B_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve free `(bGlobal, coidLo, coidHi)` to an object, then return the result of `vtbl+0x1e8()`.**

Body (entire function):

1. `obj = CVOGReaction_ResolveObjectTarget(bGlobal, coidLo, coidHi)` with **ECX = resolve ctx** from caller.
2. If null → return 0.
3. Else → return `obj->vtbl[+0x1e8]()`.

### Primary use

`CVOGSectorMap_DoPlayerOnLoadTrigger` / `DoCreatorLoadTrigger`: resolve map trigger COIDs, then fire nested `vtbl+0x114` on a chain from the result. Also `Client_UpdateNpcInteractIcons` and character-remove / sector helpers.

**Not** blob+`+0x1d4` (`Object_ResolveTfIdVtbl1d4_Inferred` `0x004bb010`), **not** resolve-only (`0x004bb950`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveCoidVtbl1e8_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` |
| Live Ghidra | `decompile_function` `0x004bb1c0`; `analyze_function_complete`; callers/callees; `read_memory` body; DoPlayerOnLoad call-site bytes |
| Sibling duals | `Object_ResolveTfIdVtbl1d4_Inferred`, `Object_ResolveFromTFID` |
| Callee | `CVOGReaction_ResolveObjectTarget` `0x004bae70` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// ECX = resolve context (caller-supplied; body does not load ECX)
// stack bGlobal, coidLo, coidHi; RET 0xC
void * __thiscall Object_ResolveCoidVtbl1e8_Inferred(
    void *ctx, uint32_t bGlobal, uint32_t coidLo, uint32_t coidHi);
// returns: vtbl+0x1e8() result, or 0 if ResolveObjectTarget fails
```

| Item | Evidence |
|---|---|
| Stack arity 3 | `RET 0xC` @ `0x004bb1e2` / `0x004bb1e7` |
| ECX this/ctx | Body never writes ECX before CALL resolve; DoPlayerOnLoad `MOV ECX,[EAX+0xe4e8]` immediately before CALL |
| Sole direct callee | `CALL rel32` → `0x004bae70` |
| Virtual | `CALL [EDX+0x1e8]` after `MOV ECX,EAX` |

**Decompiler trap:** Ghidra signature omits ECX — same class of error as sibling resolve wrappers.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Free triple push order → Resolve | **Yes** |
| ResolveObjectTarget + ECX passthrough | **Yes** |
| Null → 0 | **Yes** |
| Else vtbl+0x1e8 return | **Yes** |
| No other branches / stores | **Yes** |

**Body hex:** `8b44240c8b542408508b4424085250e89cfcffff85c0740d8b108bc8ff92e8010000c20c0033c0c20c00`

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thin resolve + virtual get | **High** | 42-byte body |
| ECX passthrough ABI | **High** | bytes + DoPlayerOnLoad site |
| Slot `+0x1e8` exact | **High** | `FF 92 E8 01 00 00` |
| Free-arg (not blob) form | **High** | three stack loads |
| Product name of `+0x1e8` | **Tentative** | `_Inferred` |
| Return = “same object*” always | **Probable** | may unwrap |

---

## 6. Gaps / open

1. Retail / PDB name of `vtbl+0x1e8`.
2. Exhaustive resolve-ctx provenance per caller (DoPlayerOnLoad sealed).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF/ABI/slot High; product vtbl name open.
