# Review B (skeptical / adversarial): `aa_004e24d0` Mem_MoveDwordRange_ToExclusiveEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e24d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-H) |
| **Counterpart** | `reviews/A_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `aa_004e2e80` Mem_MoveDwordRange_ReturnEnd | Dest math: exclusiveEnd−size vs dest=param3; bare `c3` vs `c2 0c 00`; void vs return end | **Falsified** |
| 2 | Same as `aa_00506430` (forward copy return end) | Body ends exclusive; no `add eax,size` return | **Falsified** |
| 3 | `__stdcall` / `ret 0xC` like sibling | Final opcode `c3` only | **Falsified** |
| 4 | `thiscall` / ECX object method | No ECX load as this; pure stack triple | **Falsified** |
| 5 | Element stride ≠ 4 (byte move) | `sar 2` + `*4` size; callers are dword vectors | **Falsified** |
| 6 | dest = exclusiveEnd (no subtract) | `2b c8` before push | **Falsified** |
| 7 | Product name is CVOGSectorMap_AddCharacter | Auto parent-seed only; body is generic memmove helper | **Falsified** as product name |
| 8 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exclusive-end dest formula | **High** | Wrong vector hole / overlap corruption |
| cdecl bare ret | **High** | Stack imbalance if wrapped as stdcall |
| Distinct from 004e2e80 | **High** | Wrong helper substitution |
| Product identifier spelling | **Low–Med** | Naming only |
| Empty range (count=0) no-op | **High** | memmove(0) — standard |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `8b4c2404…`, ends `…83c40cc3` |
| IAT memmove | **Yes** `@ 0x009c652c` |
| Sibling 004e2e80 dual | **Different VA / ABI / dest / return** |
| Callers are insert/grow | **Yes** (25 xrefs) |

**Attack on “this is the return-end move helper”:** **Fails** — exclusive-end dest, void, cdecl.

**Attack on “sector-map character add product API”:** **Fails** — pure reloc helper shared by many containers.

---

## 4. Surviving contract for AutoCore

```
// cdecl: void MoveDwordRangeToExclusiveEnd(srcBegin, srcEnd, destEndExcl)
// size = ((srcEnd-srcBegin)>>2)*4
// memmove(destEndExcl - size, srcBegin, size)
// bare ret; no this; not stdcall
```

**Falsified port mistakes:**

- Using `memmove(destEndExcl, …)` without subtracting size.
- Treating as stdcall / expecting returned end pointer like 004e2e80.
- Assuming non-dword stride.

---

## 5. Open questions

1. Product/PDB symbol.
2. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/dest formula; reject identity-with-004e2e80 and product-name myths.
