# Review B (skeptical / adversarial): `aa_00480970` Mem_Move200B_Blocks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-M) |
| **Counterpart** | `reviews/A_aa_00480970_Mem_Move200B_Blocks_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function frees / destructs elements | **Falsified** — pure `rep movsd` move; no free call |
| 2 | Variable element size | **Falsified** — hard `0xC8` / `ECX=0x32` |
| 3 | True `__thiscall` / ECX=this | **Falsified** — three stack args, bare `RET` |
| 4 | Exactly 3 stack args always pushed | **Nuanced** — body reads 3; callers often push 4th dummy |
| 5 | `memcpy` non-overlapping only | **Open risk** — erase uses overlapping left-shift (`dest < src`); works like memmove for that pattern; reverse overlap not sealed |
| 6 | Product name proven | **Sustained as gap** — structural INFERRED only |
| 7 | Sound-only helper | **Weakened** — also called from `FUN_00480560` generic erase; stride-shared, not sound-exclusive |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Block 200 B | **Confirmed** | Corrupt adjacent records |
| Range `[src,end) → dest` | **Confirmed** | Wrong erase geometry |
| cdecl cleanup | **Confirmed** | Stack imbalance if modeled stdcall |
| Safe for all overlap cases | **Medium** | If ported as `memcpy` with dest>src | 
| Product type of element | **Open** | Over-typed shared POD |

---

## 3. Cross-check against raw + bytes

```
while src != end:
  rep movsd 50 dwords   ; 200 B
  src += 200; dest += 200
```

Clean must **not** invent free, element constructors, or non-200 stride. Fourth stack arg is **caller noise**.

---

## 4. Surviving contract for AutoCore

```c
// Port only if a server/container uses 200-byte record vectors.
// Erase one: move [pos+200, end) → pos; end -= 200.
void Mem_Move200B_Blocks(void* src, void* srcEnd, void* dest);
```

Do **not** assume this is `std::vector` reallocate — it is a bare range shift.

---

## 5. Open questions

1. Product symbol.
2. Whether any non-erase caller uses non-overlapping bulk relocate.
3. Shared header layout with `FUN_00480560` (`+8` = end pointer).

**Verdict:** **accept-with-gaps**
