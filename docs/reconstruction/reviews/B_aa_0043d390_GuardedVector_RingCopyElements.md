# Review B (skeptical / adversarial): `aa_0043d390` GuardedVector_RingCopyElements

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-A) |
| **Counterpart** | `reviews/A_aa_0043d390_GuardedVector_RingCopyElements.md` |
| **Scratch** | `tmp/a_0043d390.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Exclusive private of `FUN_0043ce90` only | **Falsified** — 7 xrefs; also `0043c8c0`, `0043cb00`, `0043cf40` |
| 2 | `memcpy` / flat buffer copy | **Falsified** — map-of-blocks + wrap math |
| 3 | Element size > 4 bytes | **Falsified** — one dword store per iteration |
| 4 | Stackless custom-reg ABI | **Falsified** — 7 cdecl stack formals |
| 5 | Callees / non-leaf | **Falsified** — 0 callees |
| 6 | Named alias is retail symbol | **Overstated** — structural Infer from GuardedVector family; Ghidra remains `FUN_0043d390` |
| 7 | Decompiler void return hides important EAX | **Low risk** — result is via outPair stores; plain RET |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 7-arg cdecl + out-pair write | **High** | Corrupt iterator / skip elements |
| Block `>>2` / `%4` + capacity wrap | **High** | wrong slot / OOB |
| Shared multi-caller leaf | **High** | Missed alternate path |
| Product English | **Medium** | Naming only |
| Every non-OWN caller's arg packing | **Medium** | Port mismatch on those paths |

---

## 3. Cross-check against raw + bytes

```
while (src != end):
  dst_map[block][slot] = src_map[block][slot]  // 1 dword
  ++srcIdx; ++dstIdx
*out = {dstCont, dstIdx}
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. W27-B/W27-C left formal depth residual; body now OWN-sealed.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector ring element walk (assign / erase-forward / related):
//   Do not replace with flat memcpy.
//   Use map@+4, capacity@+8, 4 dwords/block, capacity wrap.
//   Write out-pair {container, index} after range.
// Reverse direction is FUN_0043d300 — separate unit.
```

---

## 5. Verdict

Adversarial pass **confirms** A: ABI, ring addressing, multi-caller leaf CF sealed. Residuals English + non-OWN caller pack detail → **accept**.
