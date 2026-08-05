# Review B (skeptical / adversarial): `aa_0043ea50` PodU32U8_StoreSplit

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ea50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-M) |
| **Counterpart** | `reviews/A_aa_0043ea50_PodU32U8_StoreSplit.md` |
| **Scratch** | `docs/reconstruction/tmp/a_0043ea50.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure `__thiscall` ECX=this only | **Falsified** — dest is **EAX**; ECX is pU32; stack pU8; `RET 4` |
| 2 | Same as null-safe `0043ecf0` | **Falsified** — no `TEST EAX`; split sources vs contiguous `src*`; `RET 4` vs bare `RET` |
| 3 | Same as `0043ece0` | **Falsified** — u32+u8 vs u32×2; no null gate; stack formal |
| 4 | Contiguous `PodU32U8*` in ECX | **Falsified** — second source reloaded from stack pointer, not `src+4` from original ECX |
| 5 | Null-safe | **Falsified** — unconditional stores |
| 6 | Product name retail | **Overstated** — inferred structural name |
| 7 | Body is grow map | **Falsified** — next unit `0043ea60` is grow; this is 16 B store leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX dest + ECX pU32 + stack pU8 + RET 4 | **High** | Wrong ABI in port |
| No null gate | **High** | Missed crash path if dest null |
| 5-byte write / 3 trailing untouched | **High** | Over-clears slot |
| Split vs contiguous | **High** | Wrong helper reuse |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Adapter parents free |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  *in_EAX = *param_1;
  *(u8*)(in_EAX+1) = *param_2;

bytes:
  MOV EDX,[ECX]
  MOV ECX,[ESP+4]
  MOV [EAX],EDX
  MOV DL,[ECX]
  MOV [EAX+4],DL
  RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Body **16 B** sealed. Adapter `0043e8f0` confirms ESI→EAX dest and stack LEAs for split pointers.

Contrast matrix:

| Unit | Null? | Sources | Width | RET |
|---|---|---|---|---|
| `0043ece0` | yes | contiguous u32×2 | 8 | bare |
| `0043ecf0` | yes | contiguous u32+u8 | 5 | bare |
| `0043ea50` | **no** | **split** u32* + u8* | 5 | **4** |

---

## 4. Surviving contract for AutoCore

```
// PodU32U8_StoreSplit:
//   EAX = dest (assumed non-null); ECX = const u32*; stack = const u8*; RET 0x4
//   write 5 bytes at +0/+4; do not zero trailing 3
// Do not reuse Pod8_CopyIfNonNull / Pod5_CopyIfNonNull ABIs.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/split sources/write width; product + parent-adapter residual only → **accept**.
