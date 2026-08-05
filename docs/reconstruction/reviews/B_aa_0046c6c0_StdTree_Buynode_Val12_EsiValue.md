# Review B (skeptical / adversarial): `aa_0046c6c0` StdTree_Buynode_Val12_EsiValue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046c6c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-T) |
| **Counterpart** | `reviews/A_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same function as `FUN_005ae220` | **Falsified** — `ret 0x10` vs `ret 0x14`; ESI vs stack value* |
| 2 | Device-effect exclusive node ctor | **Falsified** — 2 callers; primary consumer is map insert `0044a8c0` |
| 3 | `void` return / no pointer | **Falsified** — EAX preserved; null branch |
| 4 | thiscall ECX=map | **Falsified** — pure stack args + ESI; no ECX use |
| 5 | Value is 1 dword key only | **Falsified** — 3 dwords from ESI |
| 6 | isnil comes from color arg | **Falsified** — hard `mov byte [eax+0x19], 0` |
| 7 | Placement-new into freelist | **Falsified** — CRT `operator_new(0x1c)` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Node size / layout | **High** | map corruption |
| ABI ret 0x10 | **High** | stack smash |
| ESI value contract | **High** | garbage node payload |
| Distinct from stack-buy twin | **High** | wrong helper substitution |
| Color 0 = red | High (MSVC + insert passes 0) | rebalance bugs |
| Product name | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
new(0x1c) → links → ESI val×3 → color → isnil0 → ret 0x10
```

Clean must **not** invent vtbl, freelist, or claim stack `value*` (that is `005ae220`).

---

## 4. Surviving contract for AutoCore

```csharp
// ESI-value Val12 buy — do NOT call like stack twin
// Caller: ESI = &value; push color; push right; push parent; push left; call
TreeNodeVal12 BuynodeEsi(TreeNodeVal12 L, TreeNodeVal12 P, TreeNodeVal12 R,
                         int v0, int v1, int v2, byte color)
    => new TreeNodeVal12 { Left=L, Parent=P, Right=R, V0=v0, V1=v1, V2=v2, Color=color, IsNil=0 };
// Port: use explicit value* form; preserve 0x1c layout.
```

---

## 5. Open questions

1. Demangled map types for `0043c2e0` / `0044a8c0` consumers.  
2. Whether any caller leaves ESI clobbered incorrectly (insert path reloads before call).

**Verdict:** **accept**
