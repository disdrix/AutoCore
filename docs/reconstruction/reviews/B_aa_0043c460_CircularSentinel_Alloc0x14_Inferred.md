# Review B (skeptical / adversarial): `aa_0043c460` CircularSentinel_Alloc0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-B) |
| **Counterpart** | `reviews/A_aa_0043c460_CircularSentinel_Alloc0x14_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN_0043c460(void)` is full ABI | **Falsified** — callers assign return; EAX preserved through stores; bare RET |
| 2 | Size is 0xC or 0x28 | **Falsified** — `push 0x14`; 26 B body with immediate 0x14 |
| 3 | ECX-thiscall / has formals | **Falsified** — no stack args; no `this` |
| 4 | Writes full 0x14 payload | **Falsified** — only +0 and +4; rest unwritten |
| 5 | Scaffold `Named_CalleeOf_*VOG*` is product | **Rejected** — parent-seed alias only |
| 6 | Name claims PDB “HashNode” English | **Careful** — structural circular sentinel only; `_Inferred` |
| 7 | Null-new path is safe | **Noted** — second store gates on `eax+4 != 0` (true when eax=0 → addr 4); same MSVC shape as family; not a product contract |
| 8 | Exclusive NestedHash-only | **Falsified** — 4 callers incl. HeadBag + UI/loot list temps |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size 0x14 + circular links | **High** | Wrong node size in port |
| EAX return | **High** | Dropped return in clean |
| Factory-only (no free/insert) | **High** | Mis-port as full list API |
| Product node type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// NestedHash / HeadBag bag ctors:
//   head = FUN_0043c460()     // this unit
//   *(this+8) = head; *(this+0xc) = 0
//   FUN_004646e0(this+0x10, 9, &head)

// Ad-hoc:
//   FUN_005e2670 / FUN_007c77b0 allocate head, walk/rebuild circular chain, delete
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 26 B hex seals size and self-links.

Family check: identical instruction pattern to `0x00423d60` / `0x004933f0` with `0x14` vs `0x28` / `0xC`.

---

## 4. Surviving contract for AutoCore

```
// Port as free function factory:
void* CircularSentinel_Alloc0x14(void) {
  void* n = operator_new(0x14);
  if (n) *(void**)n = n;           // next
  // prev @ +4 = n  (retail MSVC gate on (n+4)!=0)
  return n;
}
// Pair with NestedHash_Ctor_Sentinel0x14 / HeadBag_Ctor_Sentinel0x14 / PtrVecShell_InitFill.
// Do not invent product English for payload[+8..).
// Do not unify with 0xC or 0x28 factories.
```

---

## 5. Verdict

Adversarial pass confirms A on size/links/ABI/return/multi-caller factory role. Residual product payload + runtime → **accept-with-gaps**.
