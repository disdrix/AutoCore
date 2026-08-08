# Review B (skeptical / adversarial): `aa_004094c0` StdMap_StringKey_EraseAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004094c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9J-F) |
| **Counterpart** | `reviews/A_aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `ret 0xC` |
| 2 | isnil/color at +0x31/+0x30 (isnil31 family / OWN peer head) | **Falsified** — this unit uses **+0x2D / +0x2C** |
| 3 | Same binary as isnil29 erase `0x004cb740` | **Falsified** — different rotates (`0044e010`/`0042a840` vs isnil29 pair), isnil offset, string dtor |
| 4 | Function frees whole tree / range | **Falsified** — single-node erase; range is caller `FUN_00407f90` |
| 5 | ECX-thiscall primary like many tree helpers | **Falsified** — **3 stack args**, `ret 0xC` |
| 6 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 7 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 8 | Mapped value heap free required always | **Unproven** — only `~basic_string` + delete node sealed; mapped@+0x28 may be POD dword |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI ret 0xC / 3 stack args | **High** | stack smash |
| isnil@+0x2D layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| 1 caller | **High** | missing specialization |
| String key identity | **High** | wrong dtor |
| Product English | Medium | naming only |
| Two-child splice plate exactness | Med | rare path only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil → throw "invalid map/set<T> iterator"
FUN_0042ac40(); splice; fix root/L/R extremity (min/max isnil2d)
if erased black → RB recolor/rotate (isnil2d L/R)
~basic_string(node+0xC); operator_delete(node);
if size>0 size--; *outIt=succ; ret 0xC
```

Clean must **not** invent range loops, freelist recycle, isnil29 rotates, or isnil@+0x31 offsets from the OWN head peer.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one StringKey tree node by pointer; parent owns key identity
void EraseAndRebalance(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor(node); // FUN_0042ac40
    UnlinkAndRebalance(map, node);  // isnil2d L/R rotate helpers
    DestroyString(node.KeyAt0x0C);
    Delete(node);
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x2D** / **color@+0x2C** / **string@+0x0C** and call the isnil2d rotate pair (not isnil29 / isnil31 families).

---

## 5. Open questions

1. Exact demangled map type for `FUN_00407f90` host.  
2. Whether mapped@+0x28 ever needs deep free (POD dword likely).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
