# Review B (skeptical / adversarial): `aa_00989ef0` ResourceCache_SetField10AndConfigure_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989ef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-F) |
| **Counterpart** | `reviews/A_aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md` |
| **Scratch** | `tmp/a_00989ef0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Standard MSVC `__thiscall` (ECX=this) | **Falsified** — **EDI=this**; ECX is field10 value |
| 2 | Decompiler void/thiscall is complete ABI | **Partial** — void ok; thiscall label **misleading** |
| 3 | Configure whole object | **Falsified** — `LEA EAX,[EDI+0x14]` targets subobject |
| 4 | Always locked | **Falsified** — gated by `+0x80` |
| 5 | Same as LookupByName | **Related layout only** — different CF (store+configure vs name resolve) |
| 6 | Product field10 = stack size | **Overstated** — AssManager passes 0x10000/0x40000 (size-like) but not proven product English |
| 7 | No stack formal | **Falsified** — `RET 4` + call-site PUSH |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI object + ECX field10 + RET 4 | **High** | Wrong wire |
| CS `+0x68` / flag `+0x80` | **High** | Race / deadlock |
| EAX subobject `+0x14` | **High** | Corrupt wrong object |
| ResourceCache family name | **Inferred** | Naming only |
| FUN_00996d70 semantics | **Open** | Port incomplete configure |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  SEH; optional Enter; +0x10=param_1; FUN_00996d70(param_2); optional Leave

bytes (105 B):
  SEH push -1 / LAB_009adcf3 / fs:[0]
  CMP byte [EDI+80],0
  LEA ESI,[EDI+68]; MOV EBX,ECX
  optional Enter(ESI)
  PUSH stack_arg; MOV [EDI+10],EBX; LEA EAX,[EDI+14]; CALL FUN_00996d70
  CMP [ESI+18],0; optional Leave
  unlink SEH; ADD ESP,10; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Byte corrections: EDI-this, EAX subobject, RET 4.

Call-site polarity: AssManager uses global `0x00d1eac8` + size-like ECX + flag 0; `FUN_0099c1c0` uses stack-local object + ECX `0x4000` + flag 1 — **same worker, different instances**.

---

## 4. Surviving contract for AutoCore

```
// ResourceCache-family set +0x10 then configure +0x14:
//   EDI = object (e.g. 0x00d1eac8 global or stack instance)
//   ECX = dword stored at +0x10
//   stack arg = configure flag for FUN_00996d70 (EAX=obj+0x14)
//   if *(char*)(obj+0x80): Enter/Leave CS at obj+0x68
//   RET 4; void
// Do not invent ECX-thiscall.
// Do not call configure with EAX=obj (must be obj+0x14).
// Pair lock layout with ResourceCache_LookupByName; do not merge CF.
```

---

## 5. Verdict

Adversarial pass confirms A after correcting decompiler thiscall mislabel; residuals are field semantics + configure callee → **accept-with-gaps**.
