# Review B (skeptical / adversarial): `aa_0059d300` StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-029) |
| **Counterpart** | `reviews/A_aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: DestroyStr14 zeros, size--, `*outIt`, `ret 8` |
| 2 | Same binary as no-dtor isnil21 erase `0x00405650` / `0x004e3e70` | **Falsified** — this unit frees `node+0x14` and zeros three dwords before node delete |
| 3 | isnil/color at +0x29/+0x28 or +0x31/+0x30 | **Falsified** — imm `0x21` / color@+0x20; rotates are isnil21 pair |
| 4 | Same as StringKey isnil2d erase `0x004094c0` | **Falsified** — different isnil offset, rotates, ABI; DestroyStr14 not `~basic_string` at +0x0C |
| 5 | Function frees whole tree / range | **Falsified** — single-node erase; range is caller `FUN_0059d620` |
| 6 | Stack-only RET 0xC (3 args, no this) | **Falsified** — **thiscall** + **ret 8**; caller `MOV ECX,EDI` |
| 7 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 8 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 9 | No value dtor (bare node delete only) | **Falsified** — DestroyStr14 free of `+0x14` heap |
| 10 | Skill/CVOG exclusive helper (product alias) | **Falsified as sole role** — shared STL erase plate; skills-abilities is partition system only |
| 11 | Same VA as Rrotate parent | **Falsified** — parent is `0x005a27f0`; this is erase that *calls* Rrotate |
| 12 | Runtime Confirmed name | **Rejected** — structural `_Inferred` only; no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI thiscall + ret 8 | **High** | stack smash |
| isnil@+0x21 layout | **High** | map corruption |
| DestroyStr14 | **High** | leak / double-free |
| size-- epilogue | **High** | size drift |
| 1 caller | **High** | missing specialization |
| Family vs no-dtor isnil21 clones | **High** | wrong dtor / merge |
| Product English | Medium | naming only |
| Two-child splice plate exactness | Med | rare path only |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
if node->isnil(+0x21) → throw "invalid map/set<T> iterator"
FUN_004e12c0(); splice; fix root/L/R extremity (min 004cb2c0 / max 00421a60)
if erased black → RB recolor/rotate (isnil21 L/R 0050e9f0/005a27f0)
if node[+0x14] != 0: operator_delete(node[+0x14])
zero +0x14/+0x18/+0x1C
operator_delete(node)
if size>0 size--; *outIt=succ; ret 8
```

Clean must **not** invent range loops, freelist recycle, isnil29/isnil2d/31 rotates, bare-delete-only merge with `00405650`/`004e3e70`, or stack-only RET0xC ABI.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil21 tree node by pointer; DestroyStr14 value teardown
void EraseAndRebalance_DestroyStr14(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor_Isnil21(node); // FUN_004e12c0
    UnlinkAndRebalance(map, node);          // isnil21 L/R rotate helpers
    if (node.StrPtr14 != null) Free(node.StrPtr14);
    node.StrPtr14 = node.StrSize18 = node.StrRes1C = 0;
    Delete(node);
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x21** / **color@+0x20** / **node 0x28** / **DestroyStr14** and call the isnil21 rotate/min/iter pair (not isnil29 / isnil2d / isnil31 families; not no-dtor isnil21 erase clones).

---

## 5. Open questions

1. Product map `value_type` English (string field layout vs generic owned buffer).
2. Whether `FUN_0059d620` is the only live range shell (1 xref sealed today).
3. Exact two-child successor-swap mid-path (decomp unreachable).

---

## 6. Verdict

Adversarial pass confirms A on ABI/CF/family/DestroyStr14/role. Product residual → **accept-with-gaps**. Never Runtime Confirmed.
