# Review B (skeptical / adversarial): `aa_006380a0` Mem_CopyBytes

| Field | Value |
|---|---|
| **Stable ID** | `aa_006380a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-K) |
| **Counterpart** | `reviews/A_aa_006380a0_Mem_CopyBytes.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is `memmove` (handles overlap) | **Falsified** — only forward `rep movs*`; no direction test |
| 2 | Args are src,dst,n (reversed) | **Falsified** — EDI loaded from first arg slot, ESI from second |
| 3 | Element-count not byte-count | **Falsified** — parents pass `count * stride` / `len+1`; body treats `n` as bytes (`>>2` / `&3`) |
| 4 | `__stdcall` / `ret n` | **Falsified** — bare `C3` |
| 5 | Zero-fills destination | **Falsified** — pure load/store copy; no store of 0 |
| 6 | Returns dest pointer (memcpy return) | **Falsified** — void; no `mov eax,edi` |
| 7 | Non-leaf / CRT memcpy IAT | **Falsified** — inline string ops only |
| 8 | Decompiler for-loops mean different algorithm than `rep movs` | **Falsified as semantics** — same dword-then-byte CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-count memcpy CF | **High** | Truncated/overlong grow copies |
| dst/src order | **High** | Overwriting source buffer |
| cdecl | **High** | Stack imbalance in ports |
| Not memmove | **High** | Silent corruption if overlapping ports use it |

---

## 3. Cross-check against raw + bytes

```
// retail shape
memcpy(dst, src, n);  // dword then byte residual; void
```

Clean must **not** invent reverse-direction handling, alignment asserts, or a non-void return. Sibling `Mem_MoveDwordRange_ReturnEnd` (`0x004e2e80`) is a different unit (range size from end-begin + IAT memmove + returns end).

---

## 4. Surviving contract for AutoCore

```c
// Port of Mem_CopyBytes (client util leaf)
void Mem_CopyBytes(void* dst, const void* src, unsigned n) {
  // Equivalent: std::memcpy(dst, src, n);
  // Do NOT use when dst/src overlap (use memmove).
  // Grow parents: always new heap dest + old heap src — safe.
}
```

---

## 5. Open questions

1. Product symbol name (none in body).
2. Whether any rare caller passes overlapping ranges (not observed in sealed grow parents).

**Verdict:** **accept**
