# Review B (skeptical / adversarial): `aa_0043ecf0` PodU32U8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ecf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-N) |
| **Counterpart** | `reviews/A_aa_0043ecf0_PodU32U8_CopyIfNonNull.md` |
| **Scratch** | `tmp/a_0043ecf0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `0043ece0` (8-byte store) | **Falsified** — second field is **byte** (`8A`/`88`), not dword |
| 2 | thiscall / ECX=this dest | **Falsified** — EAX=dest, ECX=src (register dual) |
| 3 | Null-checks source | **Falsified** — only `TEST EAX,EAX` (dest) |
| 4 | Writes full 8-byte slot | **Falsified** — 5 bytes only |
| 5 | Multi-caller helper | **Falsified** — **1** xref (`0043ea3f`) |
| 6 | Product name retail | **Overstated** — inferred structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX dest / ECX src / RET | **High** | Wrong store ABI |
| Write width 5 vs 8 | **High** | Truncate / over-write |
| Null dest skip | **High** | Crash vs silent skip |
| Sole caller push path | **High** | Wrong ownership |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Slot padding residual |

---

## 3. Cross-check against raw + bytes

```
live decompile 2026-07-29 ≡ raw 2026-07-23:
  if (in_EAX) { *in_EAX = *param_1; *(u8*)(in_EAX+1) = *(u8*)(param_1+1); }

bytes (15 B):
  85 C0 74 0A 8B 11 89 10 8A 49 04 88 48 04 C3

twin 0043ece0:
  85 C0 74 0A 8B 11 89 10 8B 49 04 89 48 04 C3
  ^^^^^^^^^^^^^^^^^^^^ identical ^^^^ delta second width
```

W31-J already sealed caller store site `E8 AC 02 00 00` → this unit; not re-owned here.

---

## 4. Surviving contract for AutoCore

```
// PodU32U8 null-safe store:
//   EAX = dest slot (nullable); ECX = const {u32,u8}*
//   if dest: write u32 + u8; no src null check; plain RET
// Do not swap with 0043ece0 (u32×2). Do not invent thiscall.
// Push caller still size++ when dest null (page base null path).
```

---

## 5. Verdict

Adversarial pass **confirms** A; only product residual → **accept**.
