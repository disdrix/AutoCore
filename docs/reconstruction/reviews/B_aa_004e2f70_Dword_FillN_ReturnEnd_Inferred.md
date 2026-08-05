# Review B (skeptical / adversarial): `aa_004e2f70` Dword_FillN_ReturnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2f70` |
| **VA** | `0x004e2f70` |
| **Canonical name** | `Dword_FillN_ReturnEnd_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md` |
| **System** | util / container |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | memcpy / uninitialized_copy_n (distinct sources) | Confuse with copy helpers | **Falsified** — `pValue` never advanced; same dword repeated |
| 2 | Element stride 12 / 0x38 / domain POD | Confuse with Vec12 / floater fills | **Falsified** — stride **4** only (`add 4` / `*4` lea) |
| 3 | Returns count | Return-value confusion | **Falsified** — returns **end pointer** |
| 4 | thiscall / object method | Ghidra habit | **Falsified** — ECX unused; free `ret 0x0C` |
| 5 | Grows capacity / allocates | Vector insert parent projection | **Falsified** — leaf stores only |
| 6 | Sector-map exclusive | Scaffold alias name | **Falsified** — multi-caller generic fill |
| 7 | Product name required for seal | Symbol inflation | **Agree leave structural INFERRED** |
| 8 | Signed count with negative fill | Hostile count | **Open residual** — loop is `!=0` decrement; negative → long/UB; not sealed as validated API |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fill-n same dword / end return | **Confirmed** | Port as memcpy → wrong hole contents |
| Stride 4 / ret 0x0C | **Confirmed** | Misaligned end / stack imbalance |
| Leaf no alloc | **Confirmed** | False dependency on heap |
| Multi-caller util | **High** | Overfit domain name |
| Product STL symbol | **Open** | Doc only |
| Negative count behavior | **Open** | Hostile inputs |

---

## 3. Cross-check against raw / live / bytes

```text
raw aa_004e2f70 ≡ live decompile 2026-07-29 (W16-B)
read_memory @ 0x004e2f70:
  mov esi, count; mov edi, dst; mov edx, pValue
  loop: mov ebx,[edx]; mov [eax],ebx; add eax,4; dec ecx; jnz
  lea eax,[edi+esi*4]
  ret 0x0C
callees: none
```

### memcpy trap

Parents may *look* like they “copy a range.” This helper **replicates one dword**. Porting as `memcpy(dst, pValue, count*4)` only works when `count==1` or when the source is intentionally a single value address.

### Return trap

End is `dst + count*4` **bytes**. Do not return `count` or `dst` alone when parents use the return to set vector `end`.

### Alias trap

`Named_CalleeOf_…_CVOGSectorMap_AddCharacter_004e2f70` is a **seed path name**, not a product method and not an exclusivity claim.

---

## 4. Surviving contract for AutoCore

```
Dword_FillN_ReturnEnd(dst, count, pValue) → end:
  for i in 0..count-1:
    dst[i] = *pValue          // pValue fixed
  return dst + count          // element pointer / byte end = +count*4

AutoCore must NOT:
  - treat as memcpy of count distinct dwords from a moving source
  - use stride other than 4
  - invent grow/alloc inside this VA
  - bind a sector-map product name without evidence
  - model thiscall / missing ret 0x0C
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Fill-n CF / end return | **Agree Confirmed** |
| ret 0x0C / three formals / free | **Agree Confirmed** |
| Not memcpy | **Agree Confirmed** |
| Multi-caller util | **Agree High** |
| Structural INFERRED name OK | **Agree** |
| accept-with-gaps | **Agree** |
| Negative count defined | **Leave Open** — not a documented precondition here |

---

## 6. Open questions

1. Demangled / CRT helper identity (optional).
2. Full caller census for domain map.
3. Whether any parent relies on reading `*pValue` each iteration for a **mutating** source (unusual; would be caller abuse).
4. Bit-exact vs retail image.

**Verdict:** **accept-with-gaps** — agree with A; block memcpy/stride conflation and domain-exclusive naming.
