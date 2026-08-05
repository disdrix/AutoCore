# Review B (skeptical / adversarial): `aa_004e7420` RbTree_InitEmptyHeader_Node1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7420` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-M) |
| **Counterpart** | `reviews/A_aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This alone is a full node factory | **Falsified** — only calls `FUN_005ae2b0`; no `operator_new` here |
| 2 | Same as sealed `FUN_004e7450` / `RbTree_InitEmptyHeader` | **Falsified** — sibling uses `FUN_00439770` + flag `+0x15` / node 0x18 |
| 3 | Factory already self-links and sets size | **Falsified** — factory zeros links, leaves `+0x19=0`, no header size |
| 4 | Head flag is at `+0x15` like the 0x18 flavor | **Falsified** — bytes `C6 40 19 01` → **`+0x19`** |
| 5 | Size field is at `header+4` | **Falsified** — `+4` is head pointer; size at `+8` |
| 6 | Returns the node pointer | **Falsified** — `mov eax,esi` returns header this |
| 7 | Needs stack args / RET N | **Falsified** — plain `ret`, ECX-only |
| 8 | Coverage rename / InitInstance scaffold defines product type | **Falsified as type name** — role is generic empty-tree header for 0x1c nodes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Head @ +4 / size @ +8 | **High** | Corrupt map layout on port |
| Node self-links + `+0x19=1` | **High** | Iteration / empty checks break |
| Factory identity `005ae2b0` / size 0x1c | **High** | Wrong node size vs 0x18 sibling |
| OOM null head | Medium | Retail faults; port may want assert |
| Product map key type | Low/Medium | Naming only for this unit |

---

## 3. Cross-check against raw + bytes

```
this (ESI) → node = FUN_005ae2b0()  // 0x1c
header+4 = node
node+0x19 = 1
node.left = node.parent = node.right = node
header+8 = 0
return this
```

Clean must **not** invent insert/erase, rebalance, or key compare — empty header only.

Do **not** fold `FUN_005ae2b0` body into this unit (separate VA; not owned).

Do **not** reuse `+0x15` / 0x18 offsets from W22-R sibling.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — 0x1c node flavor only
unsafe RbTreeHeader* RbTree_InitEmptyHeader_Node1c(RbTreeHeader* header)
{
    var node = AllocEmptyNode_0x1c(); // FUN_005ae2b0
    header->Head = node;
    node->IsNil = 1;           // +0x19  (NOT +0x15)
    node->Left = node->Parent = node->Right = node;
    header->Size = 0;          // +0x08
    return header;
}
```

---

## 5. Open questions

1. Whether server AutoCore maps use this exact 0x1c head layout or only the 0x18 sibling.
2. Why `FUN_004d8a10` owns **two** of these headers vs four of the 0x18 flavor.

**Verdict:** **accept**
