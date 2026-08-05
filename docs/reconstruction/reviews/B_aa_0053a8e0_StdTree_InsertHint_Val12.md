# Review B (skeptical / adversarial): `aa_0053a8e0` StdTree_InsertHint_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a8e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-Q) |
| **Counterpart** | `reviews/A_aa_0053a8e0_StdTree_InsertHint_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is always-insert like `FUN_00539210` alone | **Falsified** — empty/hint/neighbor gates; may call InsertOrFind |
| 2 | `ret 0x10` (4 stack args) | **Falsified** — bytes show **`ret 0x0c`** (3 stack args) |
| 3 | Multi-caller shared like insert rebalance | **Falsified** — **1** caller (`FUN_0053af20`) |
| 4 | Legacy CVOGCharacter name is product role | **Narrow** — scaffold callee chain; structural role is tree hint insert |
| 5 | isnil at +0x15 (other tree family) | **Falsified** — tests **+0x19** (Val12) |
| 6 | Decomp `FUN_005ae050()` has no args so it is a global | **Falsified** — `__fastcall` ECX=`&local_nodeptr` (bytes `lea ecx,[esp+..]`) |
| 7 | Fallthrough always inserts | **Weakened** — `FUN_0053a1a0` is insert-**or**-find; may return existing |
| 8 | Scaffold `undefined4` plate is dual-ready | **Falsified** — ABI + Val12 + hint CF required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hint CF (empty/leftmost/end/neighbor) | **High** | wrong map insert path |
| ABI ret 0x0c thiscall | **High** | stack smash |
| Val12 isnil@+0x19 | **High** | corruption |
| Neighbor insert targets (MSVC) | **High** | decomp aliases local as param_3; MSVC pattern + bytes |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
if size==0 → InsertAndRebalance(1, head)
else if hint==leftmost && key < hint.key → Insert(1, hint)
else if hint==head && rightmost.key < key → Insert(0, rightmost)
else if key < hint.key:
    pred = Prevnode(hint)
    if pred.key < key:
        Insert(pred.right.isnil ? right_of_pred : left_of_hint)
else if hint.key < key:
    succ = Nextnode(hint)
    if usable: Insert(hint.right.isnil ? right_of_hint : left_of_succ)
else InsertOrFind → *outIt
ret 0x0c
```

Clean must **not** drop the InsertOrFind fallthrough or treat this as pure always-insert.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique map insert with hint (Val12). Parent supplies hint; may no-op-insert existing key via InsertOrFind.
Node InsertHint(MapShell map, Node hint, in Val12 value)
{
    if (map.Size == 0) return InsertAndRebalance(map, addLeft: true, map.Head, value);
    // leftmost / end / neighbor fast paths…
    // else:
    var (node, _) = InsertOrFind(map, value);
    return node;
}
```

Server ports that always-insert without uniqueness will diverge from `FUN_0053af20` operator[]-style use.

---

## 5. Open questions

1. Exact demangled map type for create-from-pack owner.  
2. Whether InsertOrFind pair.inserted is ever consumed (this unit only copies node).  
3. Product names of Prevnode/Nextnode (structural seal only).

**Verdict:** **accept-with-gaps**
