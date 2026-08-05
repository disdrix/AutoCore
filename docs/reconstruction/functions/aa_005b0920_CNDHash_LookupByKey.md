# Function record: CNDHash_LookupByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0920` |
| **Canonical name** | `CNDHash_LookupByKey` |
| **Address** | `0x005b0920` |
| **Body** | `0x005b0920`–`0x005b0953` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared CNDHash container (many consumers) |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Generic CNDHash lookup by uint32 key. Returns the stored **value pointer** or **NULL**. Pure leaf (no callees); does not take the traversal lock.

## Signature (sealed)

```c
void * __thiscall CNDHash_LookupByKey(void *this, uint32_t key);
// this: CNDHash*
// return: value* or NULL; RET 4
```

## Algorithm (sealed)

```
index = (this->mask@+0x08) & key
node  = this->buckets@+0x10[index]->head@+0x04
while node:
  if node->key@+0x10 == key: return node->value@+0x08
  node = node->next@+0x0c
return NULL
```

## Layouts (fields used)

| Object | Off | Field |
|---|---|---|
| CNDHash | `+0x08` | mask |
| CNDHash | `+0x10` | buckets (array of bucket-header*) |
| BucketHdr | `+0x04` | chain head |
| Node | `+0x08` | value |
| Node | `+0x0c` | next |
| Node | `+0x10` | key |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b0920_CNDHash_LookupByKey.md`
- Annotated: `docs/reconstruction/raw/aa_005b0920_CNDHash_LookupByKey.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_LookupByKey.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005b0920_CNDHash_LookupByKey.md`
- Review B: `docs/reconstruction/reviews/B_aa_005b0920_CNDHash_LookupByKey.md`
- Dual report: `docs/agents/task-dual-ab-005b0920-cndhash-lookupbykey-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | **none** (leaf) |
| **Callers** | **200+** sites — missions (`CVOGReaction_*`, `CVOGCharacter_*`), unlock (`Client_RecvUnlockRegion`), skills, UI, `CNDHash_Insert` pre-check, etc. See Ghidra xrefs. |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / RET 4 | **High** (bytes + decompile) |
| mask / buckets / node offsets | **High** (bytes + Insert cross-check) |
| Value return (not node) | **High** |
| Full hash object size / ctor | Open (not this unit) |
| Runtime / bit-exact | Open |

## Dual A/B

| Review | Verdict |
|---|---|
| A fidelity | **accept** |
| B adversarial | **accept** |
