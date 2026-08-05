# Review B (skeptical / adversarial): `aa_004363b0` BitVec_EnsureOneAndLocateRef_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004363b0` |
| **VA** | `0x004363b0` |
| **Canonical name** | `BitVec_EnsureOneAndLocateRef_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004363b0_BitVec_EnsureOneAndLocateRef_Inferred.md` |
| **System** | packed bit-vector |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure stack thiscall ECX=this | Bytes: host in **EAX**, no `mov ecx` at entry; EDI out | **Falsified** plain thiscall |
| 2 | Void / no return | `mov eax,edi` before ret | **Falsified** |
| 3 | Locate only / no growth | Always `call FUN_004364b0` with EAX=1 | **Falsified** locate-only |
| 4 | Uses stale begin after ensure | Re-reads `[ebx+8]` after call | **Falsified** stale model |
| 5 | Element width 1 byte / bit-addressable array | Math is dword words ×32 bits | **Falsified** byte model |
| 6 | Same as sibling `00436410` | Different body; sibling calls more helpers | **Falsified** merge |
| 7 | Domain gfxBody mesh logic | Pure bit storage math; plate is **caller** file | **Falsified** domain claim |
| 8 | cdecl plain ret | `C2 0C 00` | **Falsified** |
| 9 | Count is variable | Imm `mov eax,1` | **Falsified** variable count |
| 10 | Product name required | No symbol | **Agree** `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0xC / 3 stack formals | **Confirmed** | Stack imbalance |
| EAX host / EDI out | **Confirmed** | Wrong ABI in port |
| Ensure count=1 | **Confirmed** | Wrong growth |
| Rebase after ensure | **Confirmed** | UAF on realloc |
| param3 meaning | **Open** | Mis-pass flag |
| Sole caller completeness | **Probable** | Miss dynamic calls |
| Runtime | **Open** | |

---

## 3. Cross-check against raw / live / bytes

```
raw decompile CF ≡ live (register formals explicit in bytes);
body 95 B ends C2 0C 00;
caller 00765c31: lea edi,[out]; mov eax,host; push×3; call.
```

### ABI trap

Do **not** invent `__thiscall void f(host, a,b,c)`. Port must preserve **EAX/EDI** custom formals or wrap at the sole call site.

### Realloc trap

`bitIndex` is computed from **pre-ensure** dwordPos relative to **old** begin, then applied to **new** begin. Saving a raw `dwordPos` pointer across `004364b0` is wrong if ensure reallocates — index form is load-bearing.

### Domain trap

`Named_CalleeOf_Named_gfxBody_*` is inventory residue from the only static caller living under `gfxBody.cpp`. This VA is a shared bit-storage helper.

---

## 4. Surviving contract for AutoCore

```
BitVec_EnsureOneAndLocateRef(host=EAX, bitAdd, dwordPos*, param3, out=EDI):
  old = host->begin            // +8
  EnsureInsertBits(host, bitAdd, dwordPos, param3, count=1)  // FUN_004364b0
  begin' = host->begin
  idx = ((dwordPos - old)/4)*32 + bitAdd
  out->{bit=idx&31, word=begin'+(idx>>5)}
  return out
  ret 0xC
```

---

## 5. Open questions

1. Retail type name.  
2. `FUN_004364b0` / fill policy dual.  
3. param3.  
4. Runtime.

**Verdict:** **accept-with-gaps**. Reject thiscall-void / locate-only / gfxBody-domain overclaims.
