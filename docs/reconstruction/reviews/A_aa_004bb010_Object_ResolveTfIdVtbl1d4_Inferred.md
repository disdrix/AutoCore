# Review A (reconstruction fidelity): `aa_004bb010` Object_ResolveTfIdVtbl1d4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb010` |
| **VA** | `0x004bb010`–`0x004bb039` |
| **Canonical name (Ghidra)** | `FUN_004bb010` |
| **Proposed name** | `Object_ResolveTfIdVtbl1d4_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Client_CreateVehicleObjectApply_004bb010` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W17-T) |
| **Reviewer role** | Reconstruction fidelity (thin resolve + virtual get) |
| **Counterpart** | `reviews/B_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve a compact TFID/target blob to an object, then return the result of `vtbl+0x1d4()`.**

Body (entire function):

1. `obj = CVOGReaction_ResolveObjectTarget(blob[+8] byte, blob[0], blob[1])` with **ECX = resolve ctx** from caller.
2. If null → return 0.
3. Else → return `obj->vtbl[+0x1d4]()`.

### Primary use

`Client_CreateVehicleObjectApply` (`0x00812630`): `FUN_004bb010(pkt+0x90)` — if 0, allocate via GiveItemByCbid and apply create; if non-0, existing-object path. Same virtual (`+0x1d4`) is also invoked on freshly created objects in that parent, so return is “primary/host-like pointer,” not a pure boolean.

Also: `ClientSpecialEvent_Respawn_Update` / `_dtor`, `FUN_00979290`, `FUN_00979310`.

**Not** resolve-only (`Object_ResolveFromTFID` `0x004bb950`), **not** vtbl+0x1d8 identity (`0x004bb070`), **not** vtbl+0x1dc (`0x004bb0a0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bb010_FUN_004bb010.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004bb010_FUN_004bb010.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1d4_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` |
| Live Ghidra | `decompile_function` `0x004bb010`; `analyze_function_complete`; `get_function_callers` / callees; `read_memory` body; CreateVehicle call-site bytes |
| Sibling duals | `Object_ResolveFromTFID`, `Object_ResolveTfIdGetIdentity_Inferred`, `Client_LookupObjectByTfid_Inferred` |
| Callee | `CVOGReaction_ResolveObjectTarget` `0x004bae70` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// ECX = resolve context (caller-supplied; body does not load ECX)
// stack TFID-head*; RET 4
void * __thiscall Object_ResolveTfIdVtbl1d4_Inferred(void *ctx, void *pBlob);
// returns: vtbl+0x1d4() result, or 0 if ResolveObjectTarget fails
```

| Item | Evidence |
|---|---|
| Stack arity 1 | `RET 4` @ `0x004bb032` / `0x004bb037` |
| ECX this/ctx | Body never writes ECX before CALL resolve; CreateVehicle `MOV ECX,[EAX+0xe4e8]` immediately before CALL |
| Sole direct callee | `CALL rel32` → `0x004bae70` |
| Virtual | `CALL [EDX+0x1d4]` after `MOV ECX,EAX` |

**Decompiler trap:** Ghidra signature omits ECX — same class of error as `Object_ResolveFromTFID`.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Unpack +0 / +4 / +8 only | **Yes** |
| ResolveObjectTarget three-arg + ECX passthrough | **Yes** |
| Null → 0 | **Yes** |
| Else vtbl+0x1d4 return | **Yes** |
| No other branches / stores | **Yes** |

**Body hex:** `8b4424048b5004528b108a40085250e84cfeffff85c0740d8b108bc8ff92d4010000c2040033c0c20400`

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thin resolve + virtual get | **High** | 42-byte body |
| ECX passthrough ABI | **High** | bytes + CreateVehicle site |
| Slot `+0x1d4` exact | **High** | `FF 92 D4 01 00 00` |
| CreateVehicle existing-object gate | **High** | parent clean + OWNER_WHEEL_RACE_RE |
| Product name of `+0x1d4` | **Tentative** | `_Inferred` |
| Return = “same object*” always | **Probable** | may be host/outer unwrap |

---

## 6. Gaps / open

1. Retail / PDB name of `vtbl+0x1d4`.
2. Exhaustive resolve-ctx provenance per caller (only CreateVehicle site bytes sealed here).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF/ABI/slot High; product vtbl name open.
