# Review B (skeptical / adversarial): `aa_0043ece0` Pod8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ece0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-M) |
| **Counterpart** | `reviews/A_aa_0043ece0_Pod8_CopyIfNonNull.md` |
| **Scratch** | `docs/reconstruction/tmp/a_0043ece0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack cdecl args | **Falsified** — bare `RET`; loads via EAX/ECX only |
| 2 | Always writes (no null check) | **Falsified** — `TEST EAX` / `JZ` skip |
| 3 | Copies only one dword | **Falsified** — second store at `[EAX+4]` |
| 4 | Same as `0043ecf0` | **Falsified** — twin is u32+u8 (`8A`/`88`), this is u32×2 (`8B`/`89`) |
| 5 | Same as `0043ea50` | **Falsified** — that unit has no null gate, split stack ptr, `RET 4` |
| 6 | Product name retail | **Overstated** — inferred structural name |
| 7 | Returns dest in EAX | **Overstated** — void leaf; EAX is input dest; Ghidra return-type warning is plate noise |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX dest + ECX src + bare RET | **High** | Wrong ABI in port |
| Null-safe skip | **High** | Spurious write / crash |
| Two-dword width | **High** | Truncates POD |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Unlikely for pure leaf |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (in_EAX != 0) { *in_EAX = *param_1; in_EAX[1] = param_1[1]; }

bytes:
  TEST EAX,EAX / JZ
  MOV EDX,[ECX]; MOV [EAX],EDX
  MOV ECX,[ECX+4]; MOV [EAX+4],ECX
  RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Body **15 B** sealed. Sole caller `0043e970` sets EAX=slot, ECX=value* (W31-J).

---

## 4. Surviving contract for AutoCore

```
// Pod8_CopyIfNonNull:
//   EAX = dest (nullable); ECX = const {u32,u32}*; bare RET
//   if dest: write 8 bytes; else no-op
// Do not unify with PodU32U8_StoreSplit (0043ea50) or Pod5_CopyIfNonNull (0043ecf0).
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/width/null gate; product residual only → **accept**.
