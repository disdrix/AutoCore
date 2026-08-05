# Review B (skeptical / adversarial): `aa_004507a0` StdVector_Dword_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004507a0` |
| **VA** | `0x004507a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004507a0_StdVector_Dword_InsertN_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` + 22 xrefs + resize dual |
| **Agent** | W18-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / resize-down | No shrink; only insert/grow paths | **Falsified erase** |
| 2 | Element width 8 / 0x38 (other vectors) | `>>2`, `new(cap*4)`, fill one dword | **Falsified other stride** |
| 3 | `ret 8` (two stack args only) | Three formals; **`C2 0C 00`** | **Falsified** |
| 4 | fillSrc is count of values range | Single `mov ecx,[eax]` load of one dword | **Falsified range-fill** |
| 5 | Silent overflow | Calls `FUN_004540b0` when `size+count > 0x3FFFFFFF` | **Falsified silent** |
| 6 | Same as map insert (`005d20b0` family) | Linear buffer + new/delete; no RB | **Falsified map** |
| 7 | Always reallocates | In-capacity hybrid and backward paths exist | **Falsified always-realloc** |
| 8 | Growth is exact `size+count` only | Prefers `cap + cap/2` first | **Falsified exact-only** |
| 9 | Identical product symbol to `004073a0` | Possible clone; not proven this dual | **Open / not sealed** |
| 10 | Safe without valid insertPos | Mid paths assume pos in [begin,end] | **Falsified misuse** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-N dword role | **Confirmed** | Container corruption |
| ABI / stride / shell layout | **Confirmed** | Wrong ports |
| Growth + max size | **Confirmed** | OOM / wrap |
| Three CF arms | **Confirmed** | Miss path bugs |
| Product mangled name | **Open** | Doc-only |
| Twin `004073a0` relation | **Open** | Duplicate docs |
| Runtime | **Open** | — |

---

## 3. Cross-check vs resize front

`FUN_004367f0` owns **size compare / shrink erase** and only **delegates grow** here with insert-at-end. This unit must not be documented as the full resize API. Shrink stays on `FUN_00410490` (owned by resize dual, not this VA).

---

## 4. Byte anchors

```text
0x004507a0: 8B 44 24 0C  53 56 8B F1   ; fillSrc*; push; this→esi
            8B 56 04                   ; begin
            8B 08  89 4C 24 14         ; fill = *fillSrc
            … BF FF FF FF 3F           ; 0x3FFFFFFF
            … D1 E9 / 03 C1            ; cap + (cap>>1)
            … operator_new(cap*4)
            … 89 7E 04 / 89 46 0C / 89 4E 08  ; rebind
            … C2 0C 00                 ; all exits
```

---

## 5. What would reverse the seal?

- Evidence of non-4-byte element in this exact body (contradicts `>>2` / `*4`).
- A fourth path (e.g. move-only without fill) not covered by decompile.
- Proof `param_4` is iterator range rather than single value (contradicts entry load).

None observed.
