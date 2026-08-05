# Annotated low-level: `aa_0060c010` CNDHash_InsertAlways

| Field | Value |
|---|---|
| Stable ID | `aa_0060c010` |
| VA | `0x0060c010` |
| Body | `0x0060c010`–`0x0060c0a5` |
| Canonical name | `CNDHash_InsertAlways` |
| Prior / alias | `FUN_0060c010`; `Named_CalleeOf_Mission_VOGRegionMissions_0060c010` |
| System | shared CNDHash container (region-mission secondary indexes) |
| Date | 2026-07-29 (W18-K OWN-ONLY dual) |
| Tools | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (no `disassemble_bytes`) |

---

## Purpose

**Always-insert** sibling of `CNDHash_Insert` (`0x0053c560` / twin `0x0053c360`):

- Rejects null `value` → HRESULT **`0x80004003`** (`E_POINTER`).
- **No** traversal-lock check at `this+0x1d`.
- **No** `CNDHash_LookupByKey` / duplicate policy.
- Always allocates a node, head-inserts into the bucket chain, appends the global list, bumps count, returns **0**.
- Node vtbl = **`PTR_LAB_009cf024`** (same family as mission insert twin `0x0053c360`).

Sole static caller: `CVOGRegionMissions_ctor` (`0x0060b870`) — secondary index tables `this[2]` / `this[3]` keyed by `def[+0x88]` / byte `def[+0x86]`.

---

## ABI — SEALED

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: `this` in **ECX** → EDI |
| Stack args | **`uint32 key`**, **`void* value`** (`RET 8` = `C2 08 00`) |
| Return | **EAX**: `0` success, `0x80004003` null value |
| Body | `0060c010`–`0060c0a5` |

```c
int __thiscall CNDHash_InsertAlways(CNDHash *this, uint32_t key, void *value);
```

---

## Algorithm — SEALED

```
if value == NULL: return 0x80004003
node = FUN_0053ada0( freelist = this+0x20 )   // 0x1c slab node
init node:
  vtbl = PTR_LAB_009cf024
  touch(+4) = 0
  value(+8) = value
  key(+10)  = key
  listNext(+14)=listPrev(+18)=0
  bucketNext(+0c) temp 0 then set
bucketHdr = this->buckets[+0x10][ key & this->mask[+0x08] ]
node->bucketNext = bucketHdr->head(+4)
bucketHdr->head  = node
FUN_00537d30(bucketHdr)   // ECX = bucket header (chain integrity / touch-flag)
if this->listTail[+0x18] != 0:
  oldTail->listNext(+14) = node
  node->listNext = 0
  node->listPrev = oldTail
  this->listTail = node
else:
  this->listHead[+0x14] = this->listTail = node
  node list links = 0
this->count[+0x0c]++
return 0
```

### Diff vs `CNDHash_Insert` (`0x0053c560`)

| Feature | Insert | InsertAlways (this) |
|---|---|---|
| `allowDuplicate` arg | yes (soft-skip) | **no** |
| Lookup / hard-dup | yes | **no** |
| Lock log `+0x1d` | yes (non-abort) | **no** |
| Node vtbl | `009cefd4` | **`009cf024`** |
| Stack args | 3 (`RET 0xC`) | **2 (`RET 8`)** |
| Core link / count | same | same |

---

## Layouts (fields this unit touches)

**Hash:**

| Off | Role |
|---|---|
| `+0x08` | mask |
| `+0x0c` | count++ |
| `+0x10` | buckets* |
| `+0x14` | listHead (empty path) |
| `+0x18` | listTail |
| `+0x20` | freelist shell passed to `FUN_0053ada0` |

**Node (0x1c):**

| Off | Role |
|---|---|
| `+0x00` | vtbl `0x009cf024` |
| `+0x04` | touch flag byte |
| `+0x08` | value* |
| `+0x0c` | bucket next |
| `+0x10` | key |
| `+0x14` | list next |
| `+0x18` | list prev |

---

## Callees / callers

| Dir | Symbol | Notes |
|---|---|---|
| Callee | `FUN_0053ada0` | freelist node alloc; ECX=`this+0x20` |
| Callee | `FUN_00537d30` | bucket-chain touch repair (`HashListError:…`) |
| Caller | `CVOGRegionMissions_ctor` `0x0060b870` | 2 sites: index A/B |

---

## Confidence

| Claim | Level |
|---|---|
| Always-insert (no uniqueness) | **Confirmed** |
| ABI thiscall + RET 8 | **Confirmed** (bytes) |
| Offsets / vtbl | **High** |
| Freelist at `this+0x20` | **Confirmed** (`LEA ECX,[EDI+20]`) |
| Product English name | **Inferred** (behavior sealed; no RTTI string on unit) |
| Multi-key intentional vs “forgot check” | **Probable multi** — secondary indexes may collide |

---

## Pseudocode (annotated)

```c
int __thiscall CNDHash_InsertAlways(int thisHash, uint key, int value)
{
  // ECX=this → EDI; EBP=value; key from [esp+…] after frame
  if (value == 0)
    return 0x80004003;          // E_POINTER

  // ECX = this+0x20 freelist
  undefined4 *node = (undefined4 *)FUN_0053ada0();
  node[3] = 0;                  // bucketNext temp
  *node = &PTR_LAB_009cf024;    // vtbl
  node[5] = 0;                  // listNext
  node[6] = 0;                  // listPrev
  *(byte *)(node + 1) = 0;      // touch @ +4
  node[2] = value;              // +8
  node[4] = key;                // +10

  int bucketHdr = *(int *)(*(int *)(thisHash + 0x10)
                           + (*(uint *)(thisHash + 8) & key) * 4);
  node[3] = *(undefined4 *)(bucketHdr + 4);   // old head
  *(undefined4 **)(bucketHdr + 4) = node;     // prepend
  FUN_00537d30();                             // ECX still bucketHdr

  if (*(int *)(thisHash + 0x18) != 0) {
    *(undefined4 **)(*(int *)(thisHash + 0x18) + 0x14) = node;
    node[5] = 0;
    node[6] = *(undefined4 *)(thisHash + 0x18);
    *(int *)(thisHash + 0xc) = *(int *)(thisHash + 0xc) + 1;
    *(undefined4 **)(thisHash + 0x18) = node;
    return 0;
  }
  *(undefined4 **)(thisHash + 0x18) = node;
  *(undefined4 **)(thisHash + 0x14) = node;
  node[6] = 0;
  node[5] = 0;
  *(int *)(thisHash + 0xc) = *(int *)(thisHash + 0xc) + 1;
  return 0;
}
```
