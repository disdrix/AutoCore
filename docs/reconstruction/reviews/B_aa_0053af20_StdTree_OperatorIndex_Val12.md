# Review B (skeptical / adversarial): `aa_0053af20` StdTree_OperatorIndex_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053af20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-Q) |
| **Counterpart** | `reviews/A_aa_0053af20_StdTree_OperatorIndex_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is pure lower_bound (no insert) | **Falsified** — miss path calls `FUN_0053a8e0` InsertHint with `{key,0,0}` |
| 2 | This is always-insert | **Falsified** — hit path returns existing `node+0x10` without insert |
| 3 | Returns full node / iterator | **Falsified** — both paths return **mapped** @ `+0x10` (not node base, not pair start @+0x0c) |
| 4 | `ret 0x0c` like InsertHint | **Falsified** — bytes show **`ret 0x04`** (one stack arg) |
| 5 | cdecl / multi-arg thiscall mess | **Falsified** — thiscall ECX=map, one key pointer |
| 6 | isnil at +0x15 (other tree family) | **Falsified** — tests **+0x19** (Val12) |
| 7 | Unsigned key compare | **Falsified** — decompile uses **signed** `(int)node[3] < *key` and `<=` |
| 8 | Legacy CVOGCharacter name is product role | **Narrow** — 3 callers across mission counters + create-from-pack; structural role is map op[] |
| 9 | Scaffold `undefined4` plate is dual-ready | **Falsified** — ABI + Val12 + lower_bound CF required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hit vs miss CF | **High** | double-insert or miss-as-hit corruption |
| ABI ret 0x04 thiscall | **High** | stack smash |
| Val12 isnil@+0x19 / mapped@+0x10 | **High** | wrong write target |
| Signed key compare | **High** | order inversion for high keys |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
head = *(this+4); candidate = head; node = head.left
if !node.isnil:
  lower_bound walk (signed key@+0xc, isnil@+0x19)
if candidate != head && candidate.key <= *key:
  return candidate+0x10          // hit
v = {*key, 0, 0}
InsertHint(map, &outIt, candidate, &v)
return *outIt + 0x10             // miss
ret 4
```

Clean must **not** return node base, treat key as unsigned, or skip InsertHint on miss.

Decompile shows `FUN_0053a8e0(&param_2, puVar4, local_c)` without explicit `this` — thiscall ECX=map is implicit; bytes confirm map still in ECX path from prologue.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique map operator[] — return ref to mapped (two ints). Default zeros on create.
ref (int v1, int v2) MapGetOrInsert(MapShell map, int key)
{
    var (node, found) = LowerBoundEqual(map, key);
    if (found)
        return ref node.Mapped; // +0x10
    node = InsertHint(map, hint: node, value: new Val12(key, 0, 0));
    return ref node.Mapped;
}
```

Server ports that always-insert, or return the full pair including key, will diverge from mission-counter / create-from-pack write sites.

---

## 5. Open questions

1. Exact demangled map type / mapped product meaning per owner.  
2. Whether any path needs the insert-vs-hit boolean (callers only use mapped*).  
3. Thread-safety / reentrancy — not observed; not claimed.

**Verdict:** **accept-with-gaps**
