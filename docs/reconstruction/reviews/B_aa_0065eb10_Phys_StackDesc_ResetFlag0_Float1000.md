# Review B (skeptical / adversarial): `aa_0065eb10` Phys_StackDesc_ResetFlag0_Float1000

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065eb10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-O) |
| **Counterpart** | `reviews/A_aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` |
| **Scratch** | `tmp/a_0065eb10.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Frees / destroys heap wheels or chassis object | **Falsified** — only two stores into ECX buffer; callers pass stack desc / CCS desc |
| 2 | Writes torque into vehicle wheels array | **Falsified** — no wheels base; absolute float store at `desc+4` only |
| 3 | Constant is 50.0 / not 1000.0 | **Falsified** — `00 00 7a 44` = 1000.0f; next float at `+4` is 50.0 but unused |
| 4 | stdcall / stack args | **Falsified** — ECX this/desc; plain `ret` |
| 5 | Non-leaf (calls into Havok) | **Falsified** — 19 B, no `call`/`jmp` out except ret |
| 6 | Zeroes entire 8+ B struct | **Falsified as full clear** — only byte `+0` and float `+4`; bytes +1..+3 untouched |
| 7 | Product name proven | **Agree Open** — Inferred only |
| 8 | Same role as calcWheelTorque clamp site | **Falsified as same function** — shared DAT only; this unit is desc reset |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Two-store CF | **High** | Wrong teardown side effects |
| 1000.0f constant | **High** | Wrong default scalar |
| Does not free heap | **High** | Double-free / leak misports |
| Descriptor product layout beyond +0/+4 | **Open** | Incomplete type port only |

---

## 3. Cross-check against raw + bytes

```
xmm0 = *(float*)0x00a0f520   // 1000.0
*desc = 0
*(float*)(desc+4) = xmm0
ret
```

Clean must **not** invent free, zero-fill of whole object, torque application, or stack args.

---

## 4. Surviving contract for AutoCore

```c
// Port of Phys_StackDesc_ResetFlag0_Float1000
// fastcall: ECX = desc*
void Phys_StackDesc_ResetFlag0_Float1000(uint8_t* desc) {
  desc[0] = 0;
  *(float*)(desc + 4) = 1000.0f;  // image DAT_00a0f520
}
```

Do **not** treat as wheels dtor or rigid-body free. Do **not** reuse as calcWheelTorque clamp helper.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Leaf reset flag+float | **Agree Confirmed** |
| 1000.0f @ DAT_00a0f520 | **Agree Confirmed** |
| accept | **Agree** |
| Inferred name | **Agree** Open product symbol |

---

## 6. Verdict

Adversarial pass; no CF contradictions → **accept**.
