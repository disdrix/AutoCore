# Review B (skeptical / adversarial): `aa_00971900` AssPreloader_IsKeyTrackedRecursive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-K) |
| **Counterpart** | `reviews/A_aa_00971900_AssPreloader_IsKeyTrackedRecursive_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra `undefined` / void-ish return | **Falsified** — **`MOV AL,1` / `XOR AL,AL`** + analyze return warning; callers `test al,al` |
| 2 | cdecl / plain RET | **Falsified** — **`RET 8`** all three exits |
| 3 | Contains uses same +0x1c pending as enqueue sibling | **Falsified** — bytes **`lea eax,[ebp+0x7c]`** (tracked set) |
| 4 | Recursive call is free-function 2-arg only | **Falsified** — **`mov ecx,ebp`** before self-call |
| 5 | Skip drain when already known | **Falsified** — **`FUN_00971480` always** before contains |
| 6 | Product English in this body | **Overstated** — no string; AssPreloader family via sibling path; method **Inferred** |
| 7 | Recurse always on in primary caller | **Falsified** — `FUN_004ed310` pushes **0** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + RET 8 + AL | **High** | Wrong object / stack smash |
| +0x7c contains after drain | **High** | False tracked / miss |
| Optional dep recurse | **High** | Infinite or missed deps |
| Product method English | **Inferred** | Naming only |
| Nested drain/dep collectors | **Open** | Side effects mis-modeled |
| Runtime | **Open** | SEH / concurrent preload |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  drain(this)
  if contains(this+0x7c, key): return 1
  if recurse: walk deps recursively; return any
  return 0

bytes:
  MOV EBP,ECX
  CALL 00971480
  LEA EAX,[EBP+0x7C] / CALL contains → AL=1 exit RET 8
  CMP recurse,0 → skip walk
  CALL 00744360; loop; MOV ECX,EBP / CALL self
  FUN_005b2ba0 cleanup; AL=0/1; RET 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full 282 B hex sealed.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader key tracked test (optional recursive deps):
//   ECX = AssPreloader* this
//   stack = (const int* key, char recurse); RET 8; AL = bool
//   Always drain via FUN_00971480 first
//   Membership: GuardedVector_ContainsFirstEqual at this+0x7c
//   If recurse: collect deps (FUN_00744360), recurse self, free temp ring
// Do not use +0x1c pending here; do not drop ECX on recurse; do not skip drain.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/+0x7c/recurse; product English + nested dual residual → **accept-with-gaps**.
