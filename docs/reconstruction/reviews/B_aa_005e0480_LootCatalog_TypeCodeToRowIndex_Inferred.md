# Review B (skeptical / adversarial): `aa_005e0480` LootCatalog_TypeCodeToRowIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e0480_LootCatalog_TypeCodeToRowIndex_Inferred.md` |
| **Evidence** | Live `decompile_function` + `read_memory` + callers; consumer duals |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity map (type code used raw as row) | Body remaps sparse codes; default −1 | **Falsified identity** |
| 2 | Quality/rarity mapper | Callers pass **type** codes; quality bands mapped separately in `005e07d0`/`005e0cd0` | **Falsified quality role** |
| 3 | Monotonic ascending map | `0x32→9` vs `0x34→8`; `0x44→0xb` vs `0x46→10` | **Falsified monotonic** — swaps are real |
| 4 | Has side effects / RNG | No stores, no calls | **Falsified** |
| 5 | Product type names proven | No strings | **Survives** as `_Inferred` gap only |
| 6 | Only one caller | Four live callers | **Falsified sole-caller** |
| 7 | `cdecl` | `ret 4` | **Falsified cdecl** — stack cleanup present |

---

## 2. Live ≡ raw

Live decompile matches raw case list and default `0xffffffff`. Memory shows jump-table switch shape (`mov eax,[esp+4]`; `add eax,-6`; `cmp eax,0x40`; `ja` default; dispatch), consistent with compiler switch — not hand-rolled if-chain.

---

## 3. Surviving contract

```
// typeCode stack arg; ret 4
// return compact row 0..11 or -1
// cases: 6,8,10,0xc,0xe,0x10,0x1a,0x1c,0x32,0x34,0x44,0x46
// note swaps: 0x32→9, 0x34→8, 0x44→11, 0x46→10
// pure; no globals
```

**Gaps kept:** retail type names; swap rationale.

**Verdict:** **accept**.
