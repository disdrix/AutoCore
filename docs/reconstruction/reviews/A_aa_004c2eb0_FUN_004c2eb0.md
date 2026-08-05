# Review A (reconstruction fidelity): `aa_004c2eb0` FUN_004c2eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2eb0` |
| **VA** | `0x004c2eb0` |
| **Body** | `0x004c2eb0`–`0x004c2ed8` |
| **Canonical name** | `FUN_004c2eb0` (leave-FUN) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c2eb0_FUN_004c2eb0.md` |
| **System** | `skills-abilities` (FormatFailure case **0x10** “until Level N”) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Inverse level-band map** for summon-cap UX: given an integer input (FormatFailure feeds a derived “next band” value), return

```
level = floor( (float)input - 2.5 ) * 14
```

with **negative results forced to 0**. Used only to choose between sprintf templates:

- `level > 0x50` → short “You can only have N summons at a time.”
- else → long “… at a time until Level L.”

Sole Ghidra caller: `Skill_FormatFailureMessage` (case 0x10). Pure math; no cast mutation.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_004c2eb0_*`, `reconstructed-exact/FUN_004c2eb0.cpp` |
| Function record | `functions/aa_004c2eb0_FUN_004c2eb0.md` |
| Live decompile | Ghidra `0x004c2eb0` ≡ raw |
| Body bytes | `read_memory` length 48 — ends `RET 4` |
| Constants | `DAT_00aaa6c4` = **2.5**; `DAT_009cb8dc` = **14.0** |
| Caller | FormatFailure case 0x10 after vtbl+0x210 setup |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Span `004c2eb0`–`004c2ed8` | **Confirmed** | function info |
| One stack formal, **`RET 4`** (stdcall-ish / thiscall-without-this) | **Confirmed** | `cvtsi2ss xmm0,[esp+4]` … `c2 04 00` |
| Formula `(input - 2.5) * 14` then trunc toward 0 | **Confirmed** | mul/sub + `cvttss2si` |
| Clamp: `result & ((result < 0) - 1)` → **0 if negative** | **Confirmed** | `test eax; setl cl; sub ecx,1; and eax,ecx` |
| Constants 2.5 / 14.0 | **Confirmed** | `read_memory` |
| Sole FormatFailure caller | **Confirmed** | xrefs |
| Input meaning = “next max band” from FormatFailure ABI mess | **Medium** | decomp loses arg wiring through vtbl+0x210 |
| Product name | **Open** | leave FUN_* |
| Exact inverse of `FUN_004c2e60` | **High layout** | 2.5 vs 2.0 base offset — **not exact algebraic inverse** |

---

## 4. Control flow

```c
/* stack arg: int x; RET 4 */
unsigned FUN_004c2eb0(int x)
{
  int t = (int)((float)x - 2.5f) * 14.0f;  /* cvttss2si after mul */
  if (t < 0) return 0;
  return (unsigned)t;
}
```

Clean ≡ raw ≡ live. No side effects.

---

## 5. Gaps / open

1. Precise intermediate FormatFailure passes as `x` (vtbl+0x210 / EAX pollution).
2. Why subtract **2.5** not **2.0** (asymmetric vs `FUN_004c2e60`).
3. Product symbol / design table for band edges.

**Verdict:** **accept-with-gaps** — formula + clamp + RET 4 sealed; arg semantics Medium.
