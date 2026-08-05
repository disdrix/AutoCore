# Review B (skeptical / adversarial): `aa_00788db0` MemZero_DestSize_ReturnOne_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00788db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-O) |
| **Counterpart** | `reviews/A_aa_00788db0_MemZero_DestSize_ReturnOne_Inferred.md` |
| **Scratch** | `tmp/a_00788db0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is CRT `memset` | **Falsified** — returns **1**, not dest; no fill-value arg (hard zero only) |
| 2 | thiscall / ECX dest | **Falsified** — both formals stack; EBX/ESI from `[ESP+…]`; bare `RET` |
| 3 | stdcall cleans own args | **Falsified** — `C3`; callers `ADD ESP,8` / co-clean |
| 4 | Has callees | **Falsified** — leaf; `REP STOS*` only |
| 5 | Scaffold NDRiver name is product | **Falsified** — chain `Named_CalleeOf_*` not structural; reject |
| 6 | Only ListTrackedCtx uses it | **Falsified** — also `FUN_00498380` zeros 0x52000 heap |
| 7 | size is unsigned-only | **Falsified** — signed `JLE`/`TEST`; size≤0 no-op still returns 1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero-fill semantics | **High** | Wrong buffer init |
| cdecl + return 1 | **High** | Wrong port / wrong success check |
| Body bounds 76 B | **High** | Overlap next unit |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Callers (CODE ×3):
//   FUN_00497920 @ 0049796b  — (this+0x14, 0xA0)
//   FUN_00497c80 @ 00497cbf  — (this+0x14, 0xA0); ADD ESP,8 after
//   FUN_00498380 @ 004985c4  — (new 0x52000, 0x52000)
// No DATA xrefs.
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF. Full hex seals `REP STOS*` + `MOV EAX,1`.

---

## 4. Surviving contract for AutoCore

```
// Port as cdecl zero-fill that always reports success:
uint32_t MemZero_DestSize_ReturnOne(void* dest, int size) {
  if (size > 0) memset(dest, 0, (size_t)size);  // or bit-exact bulk/tail path
  return 1;
}
// Do not invent fill-value param or return-dest CRT shape.
// Do not use Named_CalleeOf_* alias.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/zero/return-1/leaf/callers. No residual blocking seal → **accept**.
