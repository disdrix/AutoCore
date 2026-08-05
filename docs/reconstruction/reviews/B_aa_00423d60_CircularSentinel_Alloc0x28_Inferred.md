# Review B (skeptical / adversarial): `aa_00423d60` CircularSentinel_Alloc0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423d60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-B) |
| **Counterpart** | `reviews/A_aa_00423d60_CircularSentinel_Alloc0x28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN_00423d60(void)` is full ABI | **Falsified** — callers assign return; EAX preserved through stores; bare RET |
| 2 | Size is 0xC like std::list sentinel | **Falsified** — `push 0x28`; 26 B body with immediate 0x28 |
| 3 | ECX-thiscall / has formals | **Falsified** — no stack args; no `this` |
| 4 | Writes full 0x28 payload | **Falsified** — only +0 and +4; rest unwritten |
| 5 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 6 | Name claims PDB “HashNode” English | **Careful** — structural circular sentinel only; `_Inferred` |
| 7 | Null-new path is safe | **Noted** — second store gates on `eax+4 != 0` (true when eax=0 → addr 4); same MSVC shape as 0xC twin; not a product contract |
| 8 | Unique to AssResolver | **Partial** — only 3 xrefs, all bag-ctor twins; still shared helper shape |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size 0x28 + circular links | **High** | Wrong node size in port |
| EAX return | **High** | Dropped return in clean |
| Factory-only (no free/insert) | **High** | Mis-port as full list API |
| Product node type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Twin bag ctor shape (00423cf0 / 00469db0 / 0044a0d0):
//   head = FUN_00423d60()     // this unit
//   *(this+8) = head; *(this+0xc) = 0
//   FUN_004646e0(this+0x10, 9, &head)
//   *(this+0x20)=1; *(this+0x24)=1
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 26 B hex seals size and self-links.

Family check: identical instruction pattern to `0x004933f0` with `0x28` vs `0xC`.

---

## 4. Surviving contract for AutoCore

```
// Port as free function factory:
void* CircularSentinel_Alloc0x28(void) {
  void* n = operator_new(0x28);
  if (n) *(void**)n = n;           // next
  // prev @ +4 = n  (retail MSVC gate on (n+4)!=0)
  return n;
}
// Pair with PtrVecShell_InitFill (004646e0) and nested bag ctors.
// Do not invent product English for payload[+8..).
```

---

## 5. Verdict

Adversarial pass confirms A on size/links/ABI/return. Residual product payload + runtime → **accept-with-gaps**.
