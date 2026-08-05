# Review B (skeptical / adversarial): `aa_0060c010` CNDHash_InsertAlways

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c010` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-K OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_0060c010_CNDHash_InsertAlways.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `CNDHash_Insert` (has soft/hard dup) | Body has **zero** `CNDHash_LookupByKey` calls; no third stack arg; `RET 8` not `RET 0xC` | **Falsified** — stripped always-insert |
| 2 | Checks traversal lock `+0x1d` | No load of `+0x1d`; no `FUN_007a4480` | **Falsified** — unlocked |
| 3 | `__stdcall` / three args | Bytes: ECX=this, value via `[esp+10]` after 2 pushes, key later; **`C2 08 00`** | **Falsified** — **`__thiscall(this,key,value)`** |
| 4 | Returns node pointer | Success path `XOR EAX,EAX` only | **Falsified** — returns **HRESULT/status** |
| 5 | Freelist is global / unrelated | `LEA ECX,[EDI+0x20]` immediately before `FUN_0053ada0` | **Confirmed** freelist @ **`this+0x20`** |
| 6 | `FUN_00537d30` takes hash `this` | ECX still holds **bucketHdr** after head-insert (same as sibling analysis pattern) | **Confirmed** ECX=bucketHdr |
| 7 | Only one call site | `analyze_function_complete` → **2** xrefs, both in `FUN_0060b870` | **Falsified exclusive-one** — two sites, one function |
| 8 | Node vtbl equals continent Insert | Continent uses `009cefd4`; this writes `009cf024` | **Different vtbl** — same family as twin `0053c360` |
| 9 | Scaffold “unknown system” | Caller is region-missions ctor secondary indexes | **Partially** — system is **CNDHash / missions indexing** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + key + value + RET 8 | **High** | Wrong wrappers smash stack |
| Always-insert / multi-key | **High** | Server ports that dedupe would diverge from client secondary indexes |
| mask@+8, buckets@+10, count@+0c, list@+14/+18 | **High** | Corrupt table |
| Node value@+8 key@+10 next@+c list@+14/+18 | **High** | Lookup/walk wrong |
| Freelist @+0x20 | **High** | Wrong pool → heap corruption |
| Product English name | **Medium** | Naming only |
| Multi-key intentional | **Medium** | Could be omitted check; behavior still multi |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  if param_3==0 return 0x80004003
  node = FUN_0053ada0()
  node vtbl 009cf024; value; key
  bucket prepend; FUN_00537d30
  list append; count++; return 0

bytes @ 0060c010 (read_memory):
  53 55 8B6C2410 33DB 3BEB 57 8BF9 750B
  5F 5D B803400080 5B C20800
  56 8D4F20 E8... 8BF0 ... C70624F09C00 ...
  ... C20800 CC...

≡ same CF. No lookup, no lock strings, no third arg.
Sibling CNDHash_Insert (0053c560) has Lookup×2 + allowDuplicate + lock logs.
```

---

## 4. Surviving contract for AutoCore

```csharp
// Client always-insert (region mission secondary indexes).
// Do NOT apply soft-skip / hard-fail uniqueness of CNDHash_Insert.
int CndHashInsertAlways(CndHash table, uint key, object value)
{
    if (value == null) return unchecked((int)0x80004003);
    var node = AllocNode(table);          // freelist @ +0x20
    node.Vtbl = NodeVtbl_009cf024;
    node.Value = value;
    node.Key = key;
    var bucket = table.Buckets[table.Mask & key];
    node.BucketNext = bucket.Head;
    bucket.Head = node;
    IntegrityWalk(bucket);
    // append global list; count++
    return 0;
}
```

- Server may use multi-map / `Dictionary`+list if secondary keys collide.
- Do not share uniqueness policy with continent-unlock `CNDHash_Insert`.
- Do not require traversal lock for this path.

---

## 5. Gaps surviving review

1. Product / PDB name.
2. Whether secondary keys are unique in data (behavior still always-insert).
3. Full freelist / node RTTI names.
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — ABI, always-insert CF, layouts sealed; product name residual.
