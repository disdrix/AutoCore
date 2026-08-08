# Review B (skeptical / adversarial): `aa_005a4590` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-032) |
| **Counterpart** | `reviews/A_aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: free +0x14, zero vector fields, size--, `*outIt`, `ret 8` |
| 2 | isnil/color at +0x29/+0x28 (isnil29 family) | **Falsified** — `80 78 21 00` / color@+0x20; rotates are isnil21 pair |
| 3 | isnil@+0x31 / isnil31 erase merge | **Falsified** — different VA (`00408ed0`), different rotates |
| 4 | This is insert/rebalance (`005a4950` / `00407200`) | **Falsified** — throw string is iterator-invalid; no `"map/set too long"`; frees node |
| 5 | Function frees whole tree / is clear | **Falsified** — single-node erase; range loops via caller `005a4c30` |
| 6 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 7 | `param_2` is unused dead formal | **Falsified** — out-iterator store in epilogue bytes |
| 8 | Skill-domain exclusive helper | **Falsified** — structural std tree; only map erase-range caller |
| 9 | Same as Val16/0x28 insert family erase | **Narrow** — shared isnil@+0x21 rotates; this neighborhood node **0x24** + heap@+0x14; do not assume Val16 POD free |
| 10 | Lrotate/Rrotate identity swapped | **Falsified** — L sites call `0050e9f0`, R sites call parent `005a27f0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI ret 8 thiscall | **High** | stack smash |
| isnil@+0x21 layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| Value free @+0x14 | **High** | leak / double-free |
| 1 caller | **High** | missing specialization |
| Product English | Medium | naming only |
| Successor helper name | Low–Med | naming only |
| Both-children full MSVC path | Med | incomplete CF if unreachable blocks real |

---

## 3. Cross-check against raw + bytes

```
if node->isnil → throw "invalid map/set<T> iterator"
FUN_004e12c0(); splice; fix root/L/R extremity (min 004cb2c0 / max 00421a60)
if erased black → RB recolor/rotate (L 0050e9f0 / R 005a27f0)
if node[+0x14]: delete; zero +0x14/+0x18/+0x1c
operator_delete(node); if size>0 size--; *outIt=succ; ret 8
```

Clean must **not** invent range loops, freelist recycle, isnil29 offsets, or Val12 isnil@+0x19.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil@+0x21 tree node by pointer; parent owns key identity
void EraseAndRebalance(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor(node); // FUN_004e12c0
    UnlinkAndRebalance(map, node);  // isnil21 L/R rotate helpers
    if (node.HeapBegin != null) Delete(node.HeapBegin);
    Delete(node);
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x21** and call the isnil21 rotate pair (`0050e9f0` / `005a27f0`), not isnil29/31. Free value buffer @+0x14 before node.

---

## 5. Open questions

1. Exact demangled map type for caller `FUN_005a4c30` (key + vector-like payload).
2. Whether unreachable blocks hide a fuller both-children successor-swap (peer erase duals same posture).
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
