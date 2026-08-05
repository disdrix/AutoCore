# Review B (skeptical / adversarial): `aa_0043e910` GuardedVector_RingFillFromPtr

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-K) |
| **Counterpart** | `reviews/A_aa_0043e910_GuardedVector_RingFillFromPtr.md` |
| **Scratch** | `tmp/a_0043e910.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `RingFillRange` (`0043cef0`) EBX fill | **Falsified** — fill is stack `param_5`; 5 args not 4 |
| 2 | `stdcall RET 0x14` | **Falsified** — epilogue is plain `C3` |
| 3 | Flat `memset` / linear vector fill | **Falsified** — page map `>>2` + capacity wrap |
| 4 | Touches begin/size | **Falsified** — only `+0x04` / `+0x08` |
| 5 | No self-check | **Falsified** — `CMP dest, fill*; JE skip` |
| 6 | Product name retail string | **Overstated** — inferred structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 5-arg plain RET + stack fill* | **High** | Caller stack-corrupt / wrong fill |
| Forward fill CF | **High** | Insert residual wrong |
| Block map `>>2` + wrap | **High** | Slot OOB |
| Self-alias skip | **High** | rare alias overwrite only |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | rare ring edge |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for (; p1!=p3 || p2!=p4; p2++): map p2 on p1; if dest!=p5: *dest=*p5

bytes:
  MOV EBX,[ESP+0x18] after PUSH EBX  ; fill*
  CMP start_c vs end_c / start_i vs end_i
  SHR idx,2; capacity wrap; LEA dest; CMP dest,EBX; store; INC idx
  POP*; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Sole caller `FUN_0043e080` (3 xrefs) matches InsertN fill residual.

Contrast sealed `0043cef0`: EBX fill, no `if (dest != fill)`, 4 stack args — do **not** unify helpers.

---

## 4. Surviving contract for AutoCore

```
// Forward ring dword fill from stack fill*:
//   5 stack args, plain RET
//   while start cursor != end: map start_i on start_c; if dest!=fill *dest=*fill; ++start_i
//   self-alias skip is address equality, not value equality
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/map/self-guard; only naming residual → **accept**.
