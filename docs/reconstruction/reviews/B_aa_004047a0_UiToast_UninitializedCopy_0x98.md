# Review B (skeptical / adversarial): `UiToast_UninitializedCopy_0x98` / `FUN_004047a0` @ `0x004047a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004047a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004047a0_UiToast_UninitializedCopy_0x98.md` |
| **Verdict** | **accept** on CF/stride/ABI/callee; **needs-more-evidence** only on product symbol + 4th-arg product type |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Deep-constructs toast (heap strings / ctors) | **Falsified** — only calls sealed POD `rep movsd` leaf |
| 2 | Element size is not `0x98` | **Falsified** — both cursors `add …, 0x98`; leaf is `0x26` dwords |
| 3 | `__stdcall` / `ret N` | **Falsified** — epilogue is plain **`C3`** (cdecl) |
| 4 | thiscall with ECX = dst | **Falsified** — dst is stack `[ebp+10]`; ECX only loaded from unused formal |
| 5 | Same as fill-N (N copies of one template) | **Falsified** — walks **src range**; each element is distinct source |
| 6 | Grows / reallocates toast vector | **Falsified** — no heap; pure copy loop |
| 7 | Decompiler 3-param form misses real CF | **Partial** — 4th formal exists in bytes but is **body-dead** for PodCopy; CF of loop is correct |
| 8 | Product name sealed | **Open** |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride `0x98` | **Confirmed** | Wrong element packing / overrun |
| cdecl plain ret | **Confirmed** | Stack imbalance if ported as stdcall |
| Return = dst end | **Confirmed** | Insert hole end wrong |
| Callee PodCopy | **Confirmed** | Deep-copy fantasy |
| Toast role | **High** | Mis-wire as generic range copy of other width |
| 4th arg semantics | **Low** (unused) | Docs only |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// cdecl
void* UiToast_UninitializedCopy_0x98(void* src_begin, void* src_end, void* dst, void* unused = nullptr):
  while src_begin != src_end:
    UiToast_PodCopyElement_0x98(dst, src_begin)   // 0x98 POD bytes if dst != null
    src_begin += 0x98
    dst       += 0x98
  return dst

// NOT fill-N. NOT vector grow. NOT owning ctor.
// Wrapper FUN_00404510 may pass this/result extras — ignore for behavior.
```

---

## 4. Falsification notes

### 4.1 “Owning range ctor”

Only `FUN_00404710` is called; that leaf is pure `rep movsd`. Any port that runs element constructors invents behavior.

### 4.2 Confusion with UninitializedFillN

Fill-N (`0x00404130`) stamps **N copies of one template**. This VA walks a **source range**. Ports that collapse them break insert-from-range paths.

### 4.3 stdcall trap

Epilogue is `C3`, not `C2 xx 00`. Treating as stdcall with 12/16-byte cleanup double-pops the caller.

### 4.4 Decompiler vs 4th arg

Decomp shows three formals; bytes load `[ebp+14]`. Adversarial take: treat as optional unused formal from MSVC vector helper expansion — **do not invent behavior** from it.

---

## 5. Open questions

1. Retail symbol.
2. Whether any non-toast client reuses this exact helper (xrefs show only `00404510` today).
3. Bit-exact / runtime — open.

**Verdict:** **accept** on sealed CF, stride, cdecl ABI, PodCopy linkage. Reject owning-ctor / fill-N / grow overclaims. Product name open.
