# Review B (skeptical / adversarial): `aa_004e3260` HashTable_LookupObjectByCoid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3260` |
| **VA** | `0x004e3260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create** — W16-I) |
| **Counterpart** | `reviews/A_aa_004e3260_HashTable_LookupObjectByCoid_Inferred.md` |
| **Evidence** | Adversarial re-read of raw + **image bytes** (`read_memory` body + `FUN_004e23d0`); cross-check callers / parent dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Free function of two id args only (scaffold decompile) | **Falsified** | ECX table; mask/buckets; `ret 8` |
| 2 | Always finds object | **Falsified** | Miss returns 0; empty bucket / no key match |
| 3 | Returns hash **node** pointer | **Falsified** | Returns `*(node+0xc)` object payload |
| 4 | Hashes both lo and hi into bucket | **Falsified** | Bucket uses **coidLo only** (`and` with mask); hi only in chain equality |
| 5 | Performs insert / erase | **Falsified** | Pure load/call/return |
| 6 | Owns dual-table / bGlobal select | **Falsified** | Domain select is parent `004bae70`; this is table-local |
| 7 | Decompiler is complete CF | **Falsified** | Drops thiscall + bucket math |
| 8 | `ret` without stack cleanup | **Falsified** | `c2 08 00` |
| 9 | Sole caller is ResolveObjectTarget | **Falsified** | Also `004c82b0`, `004dfcc0`, `Vehicle_applyCreatePacket` |
| 10 | Product name sealed | **Not sealed** | Keep `_Inferred` / `FUN_*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thiscall + mask/bucket + payload offset | **High** (image) | Resolve always-null or wrong object |
| Return object* not node* | **High** | Type confusion / double deref |
| coidLo-only hash | **High** | Port that mixes hi into bucket mismatches retail |
| No mutation | **High** | Fake write side effects |
| Product table type name | **Open** | Naming only if layout wired |
| Sentinel / head+4 walk detail | **Tentative** (callee) | Off-by-one on empty chains |

---

## 3. Cross-check spine (must match image)

```
// FUN_004e3260(pTable /*ECX*/, coidLo, coidHi) -> object*|null
bucket  = coidLo & *(u32*)(pTable + 0x8)
listHead = (*(void***)(pTable + 0x10))[bucket]
node = FUN_004e23d0(listHead, coidLo, coidHi, &prevOut)
if !node: return 0
return *(void**)(node + 0xc)
```

Scaffold decompile / early clean matched **hit payload** only. Strengthen pass corrects clean + duals to image.

Parent dual spine remains:

```
ResolveObjectTarget → select table (ctx+4 or +8) → THIS unit
```

---

## 4. Surviving contract for AutoCore

```
HashTable_LookupObjectByCoid(pTable, coidLo, coidHi) -> object*|null
  bucket = coidLo & table.mask          // +0x8
  walk bucket chain for (lo,hi) keys    // node +0x18/+0x1c
  return node.object                    // +0xc
  no mutation
```

Port requirement: table object with **mask + bucket array**; chain nodes with **prev/next layout compatible with `FUN_004e23d0`**; payload at **+0xc**.

---

## 5. Open questions

1. Product names for hash table class / method.
2. Relation of this table type to RemoveObject’s `ctx+0xe5c0` removal hash (sibling, not this body).
3. Runtime concurrency / rehash policy.
4. Whether `FUN_004c82b0` / `004dfcc0` use same table layout without domain flags.
5. Bit-exact / differential open.

**Verdict:** **accept-with-gaps**. Treat residual `FUN_*` names as open; **do not** trust decompiler alone for this unit — image sealed thiscall + bucket index.
