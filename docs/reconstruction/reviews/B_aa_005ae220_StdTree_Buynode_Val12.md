# Review B (skeptical / adversarial): `aa_005ae220` StdTree_Buynode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-I) |
| **Counterpart** | `reviews/A_aa_005ae220_StdTree_Buynode_Val12.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Category-cooldown-only node ctor | **Falsified** — 6 callers across maps |
| 2 | `void` return / no pointer | **Falsified** — EAX preserved; null branch |
| 3 | thiscall ECX=map | **Falsified** — pure stack args, `ret 0x14` |
| 4 | Value is 1 dword key only | **Falsified** — 3 dwords copied |
| 5 | isnil comes from color arg | **Falsified** — hard `mov byte [eax+0x19], 0` |
| 6 | Same as `FUN_005ae1c0` | **Falsified** — 0x1c vs 0x24 |
| 7 | Placement-new into freelist | **Falsified** — CRT `operator_new(0x1c)` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Node size / layout | **High** | map corruption |
| ABI ret 0x14 | **High** | stack smash |
| Shared helper | **High** | wrong specialization port |
| Color 0 = red | High (MSVC convention + insert passes 0) | rebalance bugs |
| Product name | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
new(0x1c) → links → val×3 → color → isnil0 → ret 0x14
```

Clean must **not** invent vtbl, freelist, or domain-only category fields beyond the 12-byte blob.

---

## 4. Surviving contract for AutoCore

```csharp
// Generic tree node buy — do not special-case only cooldowns
sealed class TreeNodeVal12 {
    public TreeNodeVal12 Left, Parent, Right;
    public int V0, V1, V2;
    public byte Color;
    public byte IsNil; // always 0 on buy
}
TreeNodeVal12 Buynode(TreeNodeVal12 L, TreeNodeVal12 P, TreeNodeVal12 R,
                      int v0, int v1, int v2, byte color)
    => new TreeNodeVal12 { Left=L, Parent=P, Right=R, V0=v0, V1=v1, V2=v2, Color=color, IsNil=0 };
```

---

## 5. Open questions

1. Demangled map types per caller.  
2. Whether any caller relies on non-zero isnil (none — forced 0).

**Verdict:** **accept**
