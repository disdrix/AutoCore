# Review B (skeptical / adversarial): `aa_00513eb0` Item_TryConcatStackWithPeer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513eb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00513eb0_Item_TryConcatStackWithPeer.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role (field English residual open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is only a **capacity predicate** (`Item_CanAcceptStackQty`) | Body stores `+0x180`, calls SetQty, dirty | **Falsified** — mutates; different VA `0x0040abf0` |
| 2 | This is **eligibility** (`Item_IsStackEligible`) | No blob+0x3f2 / Broken tests; has merge math | **Falsified** — different unit `0x00513e70` |
| 3 | Max/limit is def **`+0x4BA`** (capacity field) | Bytes: `MOV DX,[EAX+0x4BC]` | **Falsified** — body uses **`+0x4BC`** |
| 4 | `+0x180` is the same as vfunc qty | Early fit path updates only `+0x180`; qty path is separate vfuncs | **Survives as distinct fields** — do not equate |
| 5 | `this` is the **incoming/peer** item | Sites: ECX = existing/found; push = absorbed | **Falsified** |
| 6 | Fastcall / no stack cleanup | Three exits `RET 4` (`C2 04 00`) | **Falsified** — thiscall + callee-cleanup 4 |
| 7 | Always merges vfunc qty on success | Fit path returns before vfunc calls | **Falsified as always** — early exit sealed |
| 8 | Remainder 0 leaves field 0 | `TEST EDX / JNZ; MOV EDX,EDI` before store | **Falsified** — rem0 → full limit |
| 9 | More than 2 callers / data xrefs | `get_function_xrefs` → 2 UNCONDITIONAL_CALL only | **Falsified** |
| 10 | Function is pure / no side effects | Stores + dirty OR `0x20000` + SetQty | **Falsified** |
| 11 | Product symbol is proven PDB name | No PDB; name from role + concat string | **Gap** — Probable not Confirmed |
| 12 | Unlimited path (limit 0/FFFF) still touches `+0x180` | `JBE` / `JZ` skip to vfunc block | **Falsified** — skips field math |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Same-CBID gate before mutate | **High** | Cross-type merge |
| ABI thiscall RET 4 / bool AL | **High** | Stack corruption / wrong return |
| `+0x180` sum / remainder math | **High** | Wrong field updates |
| Early fit skips SetQty | **High** | Over-merge qty in port |
| vfunc Get/Set qty on non-early | **High** | Lost stack qty |
| Dirty `FUN_00512670` | **High** | UI/state stale |
| this=dest, peer=absorbed | **High** | Inverted merge |
| Role = concat | **High** | Mis-name only |
| English for `+0x180` / `+0x4BC` | **Open** | Doc only |
| Server parity of remainder rule | **Open** | Desync on overflow stacks |
| Runtime wire/process | **Open** | Unverified live |

---

## 3. Cross-check raw + live disasm

```
00513eb0  PUSH ESI
00513eb1  MOV  ESI, ECX                 ; this
00513eb3  MOV  ECX, [ESP+8]             ; peer
00513eb7  TEST ECX, ECX
00513eb9  JZ   fail                     ; → XOR AL,AL; RET 4
00513ebf  MOV  EDX, [ECX+0xA8]
00513ec5  MOV  EAX, [ESI+0xA8]
00513ecb  MOV  EDX, [EDX+0x34]
00513ece  CMP  EDX, [EAX+0x34]          ; CBID
00513ed1  JNZ  fail
00513ed7  MOV  EAX, [EAX+0x3C]
00513eda  MOV  DX,  [EAX+0x4BC]         ; limit (NOT +0x4BA)
00513ee1  TEST DX, DX
00513ee4  PUSH EDI
00513ee5  JBE  qty_merge                ; limit==0 → skip field
00513ee7  CMP  DX, 0xFFFF
00513eec  JZ   qty_merge
00513eee  MOVZX EDI, word [ESI+0x180]
00513ef5  MOVZX EAX, word [ECX+0x180]
00513efc  ADD  EAX, EDI
00513efe  MOVZX EDI, DX                 ; limit
00513f01  CMP  EAX, EDI
00513f03  JG   overflow
00513f05  MOV  ECX, ESI
00513f07  MOV  [ESI+0x180], AX          ; fit store
00513f0e  CALL FUN_00512670
00513f13  POP  EDI
00513f14  MOV  AL, 1
00513f16  POP  ESI
00513f17  RET  4                        ; EARLY — no SetQty
00513f1a  CDQ
00513f1b  IDIV EDI                      ; rem in EDX
00513f1d  TEST EDX, EDX
00513f1f  JNZ  store_rem
00513f21  MOV  EDX, EDI                 ; rem0 → limit
00513f23  MOV  [ESI+0x180], DX
00513f2a  MOV  EDX, [ECX]               ; peer vtbl (ECX still peer unless fit path)
00513f2c  MOV  EDI, [ESI]               ; this vtbl
00513f2e  PUSH EBX
00513f2f  CALL [EDX+0x25C]              ; peer GetQty
00513f35  MOV  EBX, EAX
00513f37  MOV  EAX, [ESI]
00513f39  MOV  ECX, ESI
00513f3b  CALL [EAX+0x25C]              ; this GetQty
00513f41  ADD  EBX, EAX
00513f43  PUSH EBX
00513f44  MOV  ECX, ESI
00513f46  CALL [EDI+0x260]              ; this SetQty(sum)
00513f4c  POP  EBX
00513f4d  MOV  ECX, ESI
00513f4f  CALL FUN_00512670
00513f54  POP  EDI
00513f55  MOV  AL, 1
00513f57  POP  ESI
00513f58  RET  4
00513f5b  XOR  AL, AL
00513f5d  POP  ESI
00513f5e  RET  4
```

Decompiler body (2026-08-05) matches 2026-07-23 raw; live disasm confirms immediates **0xA8 / 0x34 / 0x3C / 0x4BC / 0x180 / 0x25C / 0x260** and three **`RET 4`** exits.

**Note on `00513f2a`:** after overflow path, `ECX` is still the **peer** (never overwritten on that path). Fit path returns earlier. Skip-limit path jumps here with `ECX=peer` as well. Decompiler correctly calls peer GetQty first.

---

## 4. Surviving contract for AutoCore

```
bool Item_TryConcatStackWithPeer(Item* dest, Item* peer):
  if peer == null: return false
  if CBID(peer) != CBID(dest): return false          // clonebase+0x34 via +0xA8
  limit = *(u16*)(dest.def + 0x4BC)                  // def via clonebase+0x3C
  if limit != 0 && limit != 0xFFFF:
    sum = dest.field180 + peer.field180              // item+0x180
    if sum <= limit:
      dest.field180 = sum
      MarkDirty(dest)                                // FUN_00512670
      return true                                    // NO SetQty
    rem = sum % limit
    if rem == 0: rem = limit
    dest.field180 = rem
  dest.SetQty(peer.GetQty() + dest.GetQty())         // vtbl +0x25C / +0x260
  MarkDirty(dest)
  return true
```

- Call only when product path intends **concat** (drop concat flag / trade add-to-existing).
- Do **not** substitute capacity max at def **`+0x4BA`**.
- Do **not** invent always-merge-qty on the fit path.
- Pair with eligibility / capacity leaves only as **callers** decide; this unit does not invoke them.

---

## 5. Falsified mis-names (do not reintroduce)

| Bad name | Why false |
|----------|-----------|
| `Item_CanAcceptStackQty` | Different VA; predicate; `+0x4BA` |
| `Item_IsStackEligible` | Different VA; flags only |
| `Named_CalleeOf_Client_RecvInventoryDropResponse_*` only | Also called from trade remove; role is concat not "drop response helper" |
| `Item_AddQuantity` alone | Misses CBID gate + `+0x180` math + early exit |

---

## 6. Residual gaps (accept-with-gaps)

- Product English for `+0x180` and def`+0x4BC`.
- Product rationale for fit-path skipping SetQty.
- Runtime / bit-exact / server parity.
