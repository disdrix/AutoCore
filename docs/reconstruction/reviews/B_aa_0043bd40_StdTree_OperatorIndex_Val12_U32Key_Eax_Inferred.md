# Review B (skeptical / adversarial): `aa_0043bd40` StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bd40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-Q) |
| **Counterpart** | `reviews/A_aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is pure lower_bound (no insert) | **Falsified** — miss path calls `FUN_0043be60` with `{key,0,0}` |
| 2 | This is always-insert | **Falsified** — hit returns existing `node+0x10` |
| 3 | Same ABI as `0x0053af20` (thiscall + `ret 4`) | **Falsified** — **EAX key***, plain **`ret`**, no stack key |
| 4 | Signed key compare | **Falsified** — body uses **unsigned** `jnb` path; decompile casts `uint` |
| 5 | Returns full node / iterator / key@+0x0c | **Falsified** — both paths return **mapped** @ `+0x10` |
| 6 | isnil at +0x15 (other tree family) | **Falsified** — tests **+0x19** (Val12) |
| 7 | Ghidra `in_EAX` phantom → ignore | **Falsified** — `mov esi,eax` at entry; call sites `lea eax,[&key]` |
| 8 | Value size not Val12 | **Falsified** — miss zeros two mapped dwords + key = 12 B payload |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hit vs miss CF | **High** | double-insert or miss-as-hit |
| EAX key + plain ret | **High** | wrong call convention / stack trash |
| Unsigned order | **High** | inversion for keys with high bit |
| Mapped @ +0x10 | **High** | write key slot / wrong field |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
head = *(this+4); candidate = head; node = root
if !node.isnil:
  unsigned lower_bound walk (key@+0xc, isnil@+0x19)
if candidate != head && candidate.key <= *key:
  return candidate+0x10          // hit
v = {*key, 0, 0}
InsertHint(map, &outIt, candidate, &v)  // FUN_0043be60
return *outIt + 0x10             // miss
plain ret
```

Clean must **not** use signed compare, stack key + `ret 4`, return node base, or skip insert on miss.

Call-site pattern (effect manager / NestedHash):
```
lea eax, [&staticKey]
lea ecx, [map]
call FUN_0043bd40
mov [eax], fnOrPtr
mov [eax+4], 0
```

---

## 4. Surviving contract for AutoCore

```csharp
// Unique map operator[] — return ref to mapped (two ints). Default zeros on create.
// Key is uint32; key pointer passed in register (not stack).
ref (int v1, int v2) MapGetOrInsertU32(MapShell map, uint key)
{
    var (node, found) = LowerBoundEqualUnsigned(map, key);
    if (found)
        return ref node.Mapped; // +0x10
    node = InsertHint(map, hint: node, value: new Val12(key, 0, 0));
    return ref node.Mapped;
}
```

Ports that reuse the **signed thiscall** twin (`0x0053af20`) ABI here will corrupt stack and mis-order keys with the high bit set.
