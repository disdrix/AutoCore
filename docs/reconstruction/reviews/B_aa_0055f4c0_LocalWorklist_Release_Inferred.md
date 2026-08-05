# Review B (skeptical / adversarial): `aa_0055f4c0` LocalWorklist_Release_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f4c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-N) |
| **Counterpart** | `reviews/A_aa_0055f4c0_LocalWorklist_Release_Inferred.md` |
| **Scratch** | `tmp/a_0055f4c0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the bind/unbind outer itself | **Falsified** — those are `0055fa40` / `0055fbf0`; this is nested teardown |
| 2 | Stack formals / `ret 4` | **Falsified** — `MOV ESI,ECX`; plain `C3` ret |
| 3 | Always heap free via vcall | **Falsified** — bump path when size==0 or slab≠current |
| 4 | Always runs tag free | **Falsified** — skipped when `desc[+8] < 0` (`JS`) |
| 5 | Decompiler `*8` is complete for tag size | **Overstated** — machine `AND 0x7fffffff` first; clean corrected |
| 6 | Product allocator name is retail | **Overstated** — `DAT_00b05060` only; `_Inferred` role name |
| 7 | Optional / skippable in bind/unbind port | **Falsified** — both bind and unbind always call it (incl. dual free-path sites) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Teardown role | **High** | Leak / double-free |
| ECX desc / ret 0 | **High** | ABI break |
| Slab branch | **High** | Arena corruption |
| Tag free + mask + 0x12 | **High** | Heap bookkeeping |
| Allocator product type | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH ESI; MOV ESI,ECX
size = align16(desc[4]*8)
branch bump vs vtbl+0x28
if desc[2]>=0: vtbl+0x14(*desc, (desc[2]&0x7fffffff)*8, 0x12)
POP EDI; POP ESI; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Mask residual documented and fixed in clean. Caller duals require always-call.

---

## 4. Surviving contract for AutoCore

```
// After bind/unbind worklist use:
LocalWorklist_Release_Inferred(&stack_worklist_desc);
// Must preserve: aligned size, bump-vs-free, tag 0x12 free with 0x7fffffff mask.
// Do not omit on early free-path returns inside complex branch.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; decompiler mask elision corrected in clean → **accept**.
