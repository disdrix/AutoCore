# Review B (skeptical / adversarial): `aa_009717a0` AssPreloader_EnqueueKeyAndDeps_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009717a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-J) |
| **Counterpart** | `reviews/A_aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler may imply two register params without ECX this | **Falsified** — entry **`MOV ESI,ECX`**; callers load ECX from manager+0x6c |
| 2 | Returns meaningful non-zero status | **Falsified** — **`XOR EAX,EAX`** always before RET |
| 3 | Enqueues key without eligibility gates | **Falsified** — always delegates to `FUN_00971640` three-gate path |
| 4 | Dep collector uses host directly as ECX | **Falsified** — `ECX = *(*(self+0x110)+0x64)` |
| 5 | Same as multi-key `FUN_00971820` body | **Overstated** — sibling loops ring; this is **single-key** seed |
| 6 | Product method name in body | **Overstated** — no strings; family via callee W31-K + callers; English **Inferred** |
| 7 | Stack cleanup RET 0 / cdecl | **Falsified** — **`RET 4`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + stack key + RET 4 | **High** | Wrong object / stack smash |
| Stage order push→deps→enqueue→clear | **High** | Missing deps or leak local |
| `+0x110→+0x64` | **High** | Wrong dep host |
| Return 0 | **High** | Caller status mishandle |
| Product method English | **Inferred** | Naming only |
| Nested `00744360` semantics | **Open** | Incomplete dep set |
| Runtime | **Open** | Event races via enqueue |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  zero local
  PushBack(local, key)
  FUN_00744360 via *(cache+0x64)
  FUN_00971640(host, local)
  clear local
  return 0

bytes:
  8BF1                 mov esi, ecx
  8B7C242C             mov edi, [esp+2C]   ; key
  57 8D4C240C E8…      push edi; lea ecx,local; call 0043d670
  8B8E10010000         mov ecx, [esi+110]
  8B4964               mov ecx, [ecx+64]
  50 57 E8…            push &local; push edi; call 00744360
  56 8D74240C E8…      push esi; lea esi,local; call 00971640
  33C0 C20400          xor eax,eax; ret 4
```

Caller `FUN_004ed310` @ `004ed43b`: `mov ecx,[edx+0x6c]; push ebx; call` — thiscall + one stack arg sealed.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader enqueue one key + deps:
//   ECX = AssPreloader* this
//   stack = const int* key; RET 4; returns 0
//   local ring: push key → expand deps via *(this+0x110)+0x64 →
//     EnqueueEligibleFromRing (ESI=local, stack=this) → clear local
// Do not drop ECX; do not skip dep expand; do not invent non-zero return.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/stage order/offsets; product method English + nested dep-collector dual residual → **accept-with-gaps**.
