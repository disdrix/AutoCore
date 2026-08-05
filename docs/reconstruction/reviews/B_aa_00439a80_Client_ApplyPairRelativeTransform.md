# Review B (skeptical / adversarial): `aa_00439a80` Client_ApplyPairRelativeTransform

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439a80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-S) |
| **Counterpart** | `reviews/A_aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| **Verdict** | **accept-with-gaps** (CF sealed; naming + vtbl English open) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for caller claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | TeleportIn-only helper (parent-seed sole role) | **Falsified** — 8 distinct call sites including Respawn + attach helpers |
| 2 | Standard `__thiscall` ECX=this | **Falsified** — EDI pack; bare `ret` |
| 3 | Stack stdcall with cleaned args | **Falsified** — epilogue `c3` not `c2 xx` |
| 4 | Simple Vec3 copy / no rotation | **Falsified** — full quat inverse + Mat4 project |
| 5 | Divide-by-zero unchecked always | **Falsified** — gate on \|q\|² vs 1e-6 dual eps |
| 6 | Clean may invent hardpoint product names as sealed | **Contested** — structural name only; product English open |
| 7 | Returns meaningful EAX | **Unfounded** — decomp void; no sealed return-value contract |
| 8 | Same unit as `Math_Mat4TransformPoint3_Project` | **Falsified** — that is callee `0x0076f6e0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI ABI | **High** | wrong port register convention |
| Multi-caller ownership | **High** | wrong system tag / dead rename |
| Quat inverse CF | **High** | broken attach orientation |
| Vtbl English | **Low–Med** | misleading AutoCore method names |
| Stack object refcount bumps (`iStack_274++`) | **Med** | decomp residual; do not invent domain meaning |

---

## 3. Cross-check against raw + bytes

- Live decompile **≡** raw body (W19-S append).
- Entry loads **`[edi+0xc]` → EBX**, **`[edi+4]` → ESI** match annotated optB/optA.
- eps floats sealed at known globals used by sibling math.
- Parent-seed alias retained as **alias only**.

Any clean that:
- uses ECX thiscall without EDI, or
- drops the null-helper arms, or
- always divides without the eps gate, or
- scopes the unit as TeleportIn-only

is **wrong** for this VA.

---

## 4. Surviving contract for AutoCore

```c
// EDI = { objA*, optA*, objB*, optB* }; bare ret
void Client_ApplyPairRelativeTransform(void);

// Port notes:
// - Preserve optional helper arms (id -1 when null).
// - Preserve quat inverse only when |q|^2 not near 0 (1e-6 gate).
// - Call Math_Mat4TransformPoint3_Project for the project step.
// - Do not invent TeleportIn-only side effects here.
```

---

## 5. Open questions

1. PDB / product symbol.
2. Whether opt helpers are hardpoints, anim nodes, or another bind type.
3. Runtime capture on TeleportIn vs Respawn paths.

**Verdict:** **accept-with-gaps**
