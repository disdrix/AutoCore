# Review B (skeptical / adversarial): `aa_0043cef0` GuardedVector_RingFillRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-D) |
| **Counterpart** | `reviews/A_aa_0043cef0_GuardedVector_RingFillRange.md` |
| **Scratch** | `tmp/a_0043cef0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stdcall `RET 0x10` | **Falsified** — plain `RET`; caller cleans |
| 2 | Fill value on stack | **Falsified** — value via **`[EBX]`** |
| 3 | Linear buffer `base+idx*4` | **Falsified** — page map `slots[page][sub]` with wrap |
| 4 | Multiple unrelated parents | **Falsified** — only `FUN_0043cb00` (3 xrefs) |
| 5 | Mutates begin/size | **Falsified** — reads only `+0x04/+0x08`; no size commit |
| 6 | Product name retail string | **Overstated** — inferred structural |
| 7 | Body has nested free | **Falsified** — **leaf** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf + full body hex | **High** | Missed callee side effects |
| EBX fill + 4 stack args | **High** | Wrong stores / stack corrupt |
| Page wrap `capacity` | **High** | OOB page index |
| Dual-iterator half-open | **High** | Infinite loop / underfill |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Parent packing races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for (; c1!=c2 || i1!=i2; ++i1)
    store *EBX at map[page][sub] with page wrap

bytes:
  CMP EDI, [ESP+18] / CMP EDX, EBP exit
  SHR page; LEA page*4; SUB → sub
  CMP page, [EDI+8] / JA skip; SUB page, cap
  MOV page_ptr, [[EDI+4]+page*4]
  MOV [page_ptr+sub*4], [EBX]
  plain RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Xrefs only from `FUN_0043cb00`.

---

## 4. Surviving contract for AutoCore

```
// Ring fill used by grow/insert residual:
//   EBX = &fill_dword
//   stack (container, idx_from, container, idx_to)  // typically same container
//   pages of 4 dwords; wrap page when page >= capacity (+0x08)
// Do not replace with flat memset/memcpy ignoring page map.
```

---

## 5. Verdict

Adversarial pass **confirms** A on full leaf CF/ABI/map math. Product name residual only → **accept**.
