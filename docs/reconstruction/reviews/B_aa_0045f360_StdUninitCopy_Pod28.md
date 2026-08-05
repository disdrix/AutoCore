# Review B (skeptical / adversarial): `aa_0045f360` StdUninitCopy_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045f360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-K) |
| **Counterpart** | `reviews/A_aa_0045f360_StdUninitCopy_Pod28.md` |
| **Scratch** | `tmp/a_0045f360.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `__fastcall(param_1)` is complete ABI | **Falsified** — EAX=dst, EDI=src_end live-in; parent sets all three |
| 2 | This is `basic_string` uninit-copy | **Falsified** — no string IAT/ctors; pure 7-dword stores; stride 0x1c POD |
| 3 | This is fill-n (`FUN_0045f150`) | **Falsified** — walks src range to end; copies from src, not from a value template only |
| 4 | Stride is 0x20 / 0x10 | **Falsified** — explicit `ADD *,0x1C` and 7 dword stores |
| 5 | Constructs non-trivial objects | **Falsified** — leaf mem copies only; null-dst skips writes |
| 6 | Multi-parent utility | **Weakened** — only 4 xrefs, all inside `FUN_0045cd30` |
| 7 | Void — no useful return | **Falsified** — EAX advanced to dst_end; parent mid-arm assigns `vec->end` |
| 8 | Scaffold anmTrackMaster plate | **Rejected** — structural Pod28 name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX/ECX/EDI + 0x1c | **High** | corrupt vector relocate |
| leaf / no ctor | **High** | wrong lifetime |
| parent-only Pod28 insert-n | **High** | over-generalize |
| product T English | **Low** | naming |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_0045f360 (bytes)
ESI=ECX; if ESI==EDI: ret
// loop: optional 7-dword copy; +=0x1c; until ESI==EDI
// EAX ends as dst_end

// Parent StdVector_InsertN_Pod28 (W34-P)
// grow: Ucopy [begin,where) → new; fill; Ucopy [where,end) → new+hole
// in-place arms: same helper for range shift
```

Decompiler void is under-specified; parent use of returned end seals EAX-out.

---

## 4. Surviving contract for AutoCore

```
// Port as trivial uninit-copy stride 0x1c:
// Retail register formals: EAX=dst, ECX=src_begin, EDI=src_end
Pod28* StdUninitCopy_Pod28(Pod28* dst, const Pod28* b, const Pod28* e) {
  for (; b != e; ++b, ++dst)
    if (dst) *dst = *b;   // 7-dword POD
  return dst;
}
// Do not call as single-arg fastcall.
// Do not run string/RC ctors.
// Pair only with Pod28 insert-n family (not RcElem28 / BasicString).
```

---

## 5. Verdict

Adversarial pass confirms register ABI, stride, and leaf POD semantics. Product typename open → **accept-with-gaps**.
