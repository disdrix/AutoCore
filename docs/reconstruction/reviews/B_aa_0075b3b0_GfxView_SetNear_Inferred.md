# Review B (skeptical / adversarial): `aa_0075b3b0` GfxView_SetNear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075b3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-O) |
| **Counterpart** | `reviews/A_aa_0075b3b0_GfxView_SetNear_Inferred.md` |
| **Scratch** | `tmp/a_0075b3b0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Integer store not float | **Falsified** — `MOVSS` load/store; callers push `0x3F000000` (0.5f) |
| 2 | Sets far plane | **Falsified** — writes `+0xF0` only; twin `FUN_0075b390` is far at `+0xF4` |
| 3 | stdcall without this | **Falsified** — ECX base on all stores; `RET 4` is thiscall cleanup |
| 4 | Dirty only +0x48 | **Falsified** — both `+0x48` and `+0xCC` set |
| 5 | Product name retail | **Overstated** — `_Inferred`; class high via path/siblings, method English open |
| 6 | Non-leaf / hidden call | **Falsified** — 28 B, no CALL, callees empty |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + RET 4 | **High** | Wrong object / stack desync |
| Near @ +0xF0 float | **High** | Projection clip wrong |
| Dirty pair | **High** | Stale projection matrix |
| Leaf | **High** | Invented callees |
| Product English | **Inferred** | Naming only |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  *(this+0xF0) = param_2;
  *(this+0x48) = 1;
  *(this+0xCC) = 1;

bytes:
  MOVSS XMM0,[ESP+4]; MOV AL,1;
  MOVSS [ECX+0xF0],XMM0;
  MOV [ECX+0x48],AL; MOV [ECX+0xCC],AL;
  RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 ≡ 28 B hex.

Polarity vs `FUN_0075b390`: identical shape with `+0xF4` — sealed pair of near/far setters.

---

## 4. Surviving contract for AutoCore

```
// GfxView SetNear (leaf):
//   ECX = view; stack float near; RET 4
//   view->near (+0xF0) = near
//   view->projDirty (+0x48) = 1
//   view->auxDirty  (+0xCC) = 1
// Do not write far here; do not skip dirty flags.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/float; product method English residual cosmetic → **accept**.
