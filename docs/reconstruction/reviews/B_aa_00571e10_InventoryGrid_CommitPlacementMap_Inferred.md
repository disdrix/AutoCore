# Review B (skeptical / adversarial): `aa_00571e10` InventoryGrid_CommitPlacementMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571e10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-C OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` |
| **System** | inventory-transfer |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI + inventory-family roles; **reject** "non-returning operator_delete" and "void thiscall with 0 stack args" |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `operator_delete` does not return / whole clear is one delete | **Falsified** — bytes loop on isnil until sentinel; multiple deletes |
| 2 | No stack args / cdecl ret 0 | **Falsified** — `ret 8`; two stack formals |
| 3 | RemoveItem always runs | **Falsified** — requires related≠0 **and** flag≠0; SortAndRepack fail passes `(0,0)` |
| 4 | RemoveItem uses **this** grid | **Falsified** — `mov ecx,ebp` = related |
| 5 | Primary role is only "fail restore" | **Weakened** — also success-with-flag path in RePlaceItems |
| 6 | Product name proven | **Fail** — `_Inferred`; does not block accept-with-gaps |
| 7 | Needs `disassemble_bytes` | **Falsified** — decompile + `read_memory` seal ABI/CF |

---

## 2. Decisive evidence

### Epilogue ret 8

```text
… 5b 83 c4 10 c2 08 00
```

at `0x00571fac`.

### RemoveItem ECX = related

```text
85 ed                 ; test related
…
8b cd                 ; mov ecx, ebp  ; related
e8 …                  ; call InventoryGrid_RemoveItem
```

### SortAndRepack fail site

Parent dual + decompile: `FUN_00571e10(0,0)` — restamp/clear without remove.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ret 8 / related+flag | **High** | Broken inventory ports |
| RemoveItem target = related | **High** | Wrong grid mutation |
| Restamp type≠4 | **High** | Cell occupancy bugs |
| Map shell `this+0x5c` | **High** | Allocator/map corruption |
| Product name | **Tentative** | Naming only |
| Iterator begin = *head vs head->left | **High** (bytes `mov esi,[eax]`) | Off-by-structure if misread |

---

## 4. What would falsify accept-with-gaps

1. Additional callers with different arity (not ret 8).
2. Proof restamp uses different pitch formula than Place/Remove family.
3. Image bytes differing on RemoveItem ECX source.

None observed.

---

## 5. Verdict

**accept-with-gaps.** Prefer `InventoryGrid_CommitPlacementMap_Inferred` over pure "restore-only" naming. Residuals: product symbol, related typedef, runtime golden.
