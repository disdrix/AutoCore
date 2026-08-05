# Review B (skeptical / adversarial): `aa_00561370` WorldMgr_RebindAllObjects_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-P) |
| **Counterpart** | `reviews/A_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a single-object rebind like `FUN_00560e90` | **Falsified** — nested loops over **all** islands/bodies + extras list |
| 2 | Decompiler `__fastcall` / free function | **Falsified** — `mov esi,ecx`; bare `ret`; caller `FUN_00562530` is thiscall on same manager |
| 3 | Bind without unbind (or reverse order) | **Falsified** — always `0055fbf0` then `0055fa40` per body |
| 4 | Only one island list | **Falsified** — two isomorphic passes (`+8/+0xc` and `+0x14/+0x18`) plus extras `+0x120` |
| 5 | Host flag write is optional / branchy | **Falsified** — unconditional after every unbind+bind |
| 6 | `FUN_0055f7a0` gets flag 0 | **Falsified** — stack byte forced to **1** |
| 7 | Multiple callers / hot path spam | **Weakened** — single xref from profile swap; not per-tick island step |
| 8 | Name implies phys-pair flush | **Falsified** — sibling `0x00561320` is pair drain; this is link rebind |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unbind→bind order | **High** | spatial-query corruption |
| thiscall manager ECX | **High** | wrong object as this |
| Host +0x28 stamp | **High** | missed dirty/active mark |
| Two island + extras split | **High** | incomplete rebind after profile swap |
| Product list A vs B English | Low–Med | naming only |
| `0055f7a0` full contract | Medium | extras path mis-port |

---

## 3. Cross-check against raw + bytes

```
for island in listA:
  for body in island.bodies:
    Unbind(mgr, body); Bind(mgr, body); host(body).byte28 = 1
for island in listB:  // same
for obj in listC:
  FUN_0055f7a0(mgr, obj, 1)
ret
```

Caller `FUN_00562530`: replace `mgr+0xd0` profile / refcounts / `+0xcc+4` / `+0x144`; if `param_3` → this function. Clean must **not** invent per-tick scheduling, pair-merge, or skip unbind.

---

## 4. Surviving contract for AutoCore

```csharp
// After manager profile swap (flag):
void RebindAllObjects(Manager mgr)
{
    foreach (var island in mgr.IslandsA)
        foreach (var body in island.Bodies)
        {
            UnbindLinks(mgr, body);
            BindLinks(mgr, body);
            body.Host.Flag28 = 1;
        }
    foreach (var island in mgr.IslandsB)
        foreach (var body in island.Bodies)
        {
            UnbindLinks(mgr, body);
            BindLinks(mgr, body);
            body.Host.Flag28 = 1;
        }
    foreach (var obj in mgr.Extras120)
        RefreshObjectPath(mgr, obj, flag: 1); // FUN_0055f7a0
}
```

Do **not** call this every sim step — only when profile swap requests full rebind. Preserve unbind-before-bind (matches W26-D/E + W24-B RebindActivate pattern).

---

## 5. Open questions

1. Product English distinguishing island list A vs B.  
2. Full dual / English of `FUN_0055f7a0` and why extras skip unbind+bind.  
3. Host `+0x28` product meaning.  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
