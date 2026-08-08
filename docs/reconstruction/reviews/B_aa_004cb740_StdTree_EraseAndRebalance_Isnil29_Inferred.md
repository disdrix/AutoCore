# Review B (skeptical / adversarial): `aa_004cb740` StdTree_EraseAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9E-E) |
| **Counterpart** | `reviews/A_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `ret 8` |
| 2 | isnil/color at +0x19/+0x18 (Val12) | **Falsified** — this unit uses **+0x29 / +0x28** |
| 3 | Same binary as Val12 erase `0x004e4130` | **Falsified** — different VA, rotates (`004192a0`/`004192f0` vs Val12 pair), isnil offset |
| 4 | Function frees whole tree / range | **Falsified** — single-node erase; range would loop this |
| 5 | VOG_DEBUG_STOP scaffold name is product role | **Narrow** — shared tree helper; three map callers |
| 6 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 7 | `param_2` is unused dead formal | **Falsified** — out-iterator store in epilogue bytes |
| 8 | Skill-domain exclusive helper | **Falsified** — structural std tree; callers are map erase shells |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI ret 8 thiscall | **High** | stack smash |
| isnil@+0x29 layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| 3 callers | **High** | missing specialization |
| Product English | Medium | naming only |
| Successor helper name | Low–Med | naming only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil → throw "invalid map/set<T> iterator"
FUN_004cb270(); splice; fix root/L/R extremity (min/max isnil29)
if erased black → RB recolor/rotate (isnil29 L/R)
operator_delete(node); if size>0 size--; *outIt=succ; ret 8
```

Clean must **not** invent range loops, freelist recycle, or Val12 isnil@+0x19 offsets.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil@+0x29 tree node by pointer; parent owns key identity
void EraseAndRebalance(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor(node); // FUN_004cb270
    UnlinkAndRebalance(map, node);  // isnil29 L/R rotate helpers
    Delete(node);
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x29** and call the isnil29 rotate pair (not Val12 / isnil15).

---

## 5. Open questions

1. Exact demangled map type for `FUN_004c8610` / `004c8780` / `004cbaa0`.  
2. Whether `FUN_004cb270` also writes the out-it shadow fully before epilogue store.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
