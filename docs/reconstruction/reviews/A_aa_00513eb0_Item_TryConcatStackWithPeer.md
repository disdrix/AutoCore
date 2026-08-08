# Review A (reconstruction fidelity): `aa_00513eb0` Item_TryConcatStackWithPeer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513eb0` |
| **VA** | `0x00513eb0` |
| **Canonical name** | `Item_TryConcatStackWithPeer` |
| **Prior names** | `FUN_00513eb0`, `Named_CalleeOf_Client_RecvInventoryDropResponse_00513eb0` |
| **Review date** | `2026-08-05` (MEGA-012 dual A/B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00513eb0_Item_TryConcatStackWithPeer.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mutating try-concat:** merge peer item into destination `this` when CBIDs match.

```
if peer==null || CBID(peer)!=CBID(this): return false
optional: combine u16@+0x180 under def limit@+0x4BC (fit→early true; overflow→remainder)
this.qty = peer.qty + this.qty   // vtbl +0x25C / +0x260  (non-early path)
dirty(this); return true
```

**Calling convention:** MSVC `__thiscall` — destination in `ECX`; peer on stack; `ret 4`; bool in `AL`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | destination item receiving merge | both call sites: existing/found stack |
| stack0 | peer being absorbed | trade-return item / drag-selected item |
| AL | success | `MOV AL,1` / `XOR AL,AL` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ APPEND re-verify) | `docs/reconstruction/raw/aa_00513eb0_FUN_00513eb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513eb0_FUN_00513eb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_TryConcatStackWithPeer.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00513eb0.cpp` |
| Function records | `aa_00513eb0_FUN_00513eb0.md`, `aa_00513eb0_Item_TryConcatStackWithPeer.md` |
| Live decompile | Ghidra `decompile_function` `0x00513eb0` (2026-08-05) ≡ raw body |
| Live disasm | `disassemble_function` full body through 3× `RET 4` |
| Live bytes | `read_memory` `0x00513eb0` length 256; end `32 C0 5E C2 04 00` + `CC` pad |
| Analyze | `analyze_function_complete` (xrefs/callers/callees/vars) |
| Callers | `get_function_callers` + `get_function_xrefs` (2 sites) |
| Call-site ABI | `get_assembly_context` @ `0x00813670`, `0x00813995` |
| Parent decompiles | `Client_RecvInventoryDropResponse` `0x00813730`; `FUN_008134d0`; dirty `FUN_00512670` |
| Capacity sibling | dualed `Item_CanAcceptStackQty` `0x0040abf0` (max @ **+0x4BA**) |
| Eligibility sibling | dualed `Item_IsStackEligible` `0x00513e70` |

**Not performed:** `disassemble_bytes`, Launcher, live process memory, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `ESI=this`, `ECX=peer` from `[ESP+8]` | **Yes** — prologue bytes |
| peer null → fail | **Yes** — `TEST ECX / JZ 0x00513f5b` |
| CBID: `*(peer+0xA8)+0x34` vs `*(this+0xA8)+0x34` | **Yes** |
| `limit = *(u16*)(*(this_clone+0x3C)+0x4BC)` | **Yes** — `MOV DX,[EAX+0x4BC]` |
| skip field math if limit==0 or 0xFFFF | **Yes** — `TEST DX / JBE` + `CMP DX,0xFFFF / JZ` |
| `sum = *(u16*)(this+0x180)+*(u16*)(peer+0x180)` | **Yes** |
| sum≤limit → store, dirty, `AL=1`, `RET 4` | **Yes** — early exit **no** vfunc path |
| else `CDQ; IDIV EDI`; rem0→limit; store rem | **Yes** |
| peer GetQty vtbl+0x25C; this GetQty; SetQty sum vtbl+0x260 | **Yes** |
| dirty `FUN_00512670`; `AL=1`; `RET 4` | **Yes** |
| fail `XOR AL,AL; POP ESI; RET 4` | **Yes** |
| Body end before `CC` pad / next @ `0x00513f60` | **Yes** — size **0xAF** |

### 3.1 Early fit path skips qty merge — **SEALED as oddity**

When `+0x180` sum fits under limit, retail returns after dirty **without** calling vtbl `+0x25C`/`+0x260`. Preserve bit-exact; do not "fix" by always merging qty.

### 3.2 Limit field ≠ capacity max — **SEALED**

This body loads def **`+0x4BC`**. Sibling capacity predicate loads def **`+0x4BA`**. Different offsets; do not merge formulas.

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| item `+0xA8` | ptr | clonebase | `MOV EDX,[ECX+0xA8]` / `MOV EAX,[ESI+0xA8]` |
| clonebase `+0x34` | i32 | CBID equality | `MOV EDX,[EDX+0x34]` / `CMP EDX,[EAX+0x34]` |
| clonebase `+0x3C` | ptr | def blob | `MOV EAX,[EAX+0x3C]` |
| def `+0x4BC` | u16 | limit for `+0x180` math | `MOV DX,[EAX+0x4BC]` |
| item `+0x180` | u16 | combined field | `MOVZX …,[ESI+0x180]` |
| vtbl `+0x25C` | method | get quantity | `CALL [EDX+0x25C]` |
| vtbl `+0x260` | method | set quantity | `CALL [EDI+0x260]` |
| item `+0x17C` | u32 flags | dirty bit `0x20000` via callee | `FUN_00512670` |

---

## 5. Callers (2 UNCONDITIONAL_CALL)

| Site | Function | ECX (this) | stack peer |
|------|----------|------------|------------|
| `0x00813673` | `FUN_008134d0` TradeRemoveItem_Response | `EAX` = `FUN_005710c0(CBID)` hit | `EBP` = resolved trade item |
| `0x00813995` | `Client_RecvInventoryDropResponse` | `EBP` = existing from `FUN_00571010` | `EAX` = selected via client+0x9B8 vfunc+0x3AC |

Pattern sealed: **destination is always `this`**; **peer is always the absorbed item**. Parent drop plate labels branch **concat/split**; null-peer error string **"Dropping failed trying to concatinate"**.

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = try-concat same-CBID peer into this | **High / Sealed** |
| Canonical `Item_TryConcatStackWithPeer` | **Probable** (PDB unknown; matches partition hint + concat string) |
| Distinct from `Item_CanAcceptStackQty` | **High** — mutates; different max offset |
| Distinct from `Item_IsStackEligible` | **High** — eligibility has no merge math |
| Scaffold `Named_CalleeOf_…` retired | **Yes** |

---

## 7. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** (175 B to `RET 4`) |
| Signature (`__thiscall` + peer) | **High** |
| Control flow | **High** (live ≡ raw 2026-08-05) |
| CBID + dirty + qty vfuncs | **High / Sealed** |
| Call-site this/peer | **High / Sealed** (2/2) |
| Return = bool AL | **High / Sealed** |
| Product English `+0x180` | **Open** |
| Product English def`+0x4BC` | **Open** |
| Fit-path no-qty-merge rationale | **Open** (behavior sealed) |
| Runtime / bit-exact | **Open** |
| Overall | **accept-with-gaps** |

---

## 8. Gaps (non-blocking)

- Field names for `item+0x180` and def`+0x4BC`.
- Whether server mirrors remainder-wrap and early-exit asymmetry.
- Runtime Confirmed / differential / bit-exact image.
