# Review B (skeptical / adversarial): `aa_004397f0` CircularSentinel_Alloc0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004397f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-C) |
| **Counterpart** | `reviews/A_aa_004397f0_CircularSentinel_Alloc0x10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN_004397f0(void)` is full ABI | **Falsified** — callers assign return; EAX preserved through stores; bare RET |
| 2 | Size is 0x28 like CircularSentinel_Alloc0x28 | **Falsified** — `push 0x10`; 26 B body with immediate 0x10 |
| 3 | ECX-thiscall / has formals | **Falsified** — no stack args; no `this` |
| 4 | Writes full 0x10 payload | **Falsified** — only +0 and +4; rest unwritten |
| 5 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 6 | Name claims PDB “HashNode” English | **Careful** — structural circular sentinel only; `_Inferred` |
| 7 | Null-new path is safe | **Noted** — second store gates on `eax+4 != 0` (true when eax=0 → addr 4); same MSVC shape as 0x28/0xC twins; not a product contract |
| 8 | Unique to NestedHash 0x10 bag | **Partial** — primary bag consumer is W34-E `00457ac0`; also 3 other list/FX sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size 0x10 + circular links | **High** | Wrong node size in port |
| EAX return | **High** | Dropped return in clean |
| Factory-only (no free/insert) | **High** | Mis-port as full list API |
| Product node type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// NestedHash_Ctor_Sentinel0x10 (00457ac0, W34-E):
//   head = FUN_004397f0()     // this unit
//   *(this+8) = head; *(this+0xc) = 0
//   FUN_004646e0(this+0x10, 9, &head)
//   *(this+0x20)=1; *(this+0x24)=1
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 26 B hex seals size and self-links.

Family check: identical instruction pattern to `0x00423d60` / `0x004933f0` with size **0x10**.

---

## 4. Surviving contract for AutoCore

```
// Port as free function factory:
void* CircularSentinel_Alloc0x10(void) {
  void* n = operator_new(0x10);
  if (n) *(void**)n = n;           // next
  // prev @ +4 = n  (retail MSVC gate on (n+4)!=0)
  return n;
}
// Pair with NestedHash_Ctor_Sentinel0x10 (00457ac0) and PtrVecShell_InitFill (004646e0).
// Do not invent product English for payload[+8..).
// Do not conflate with Alloc0x28 (00423d60) or Alloc0xC (004933f0).
```

---

## 5. Verdict

Adversarial pass confirms A on size/links/ABI/return. Residual product payload + runtime → **accept-with-gaps**.
