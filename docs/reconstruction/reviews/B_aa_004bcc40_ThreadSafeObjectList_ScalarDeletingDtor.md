# Review B (skeptical / adversarial): `aa_004bcc40` ThreadSafeObjectList_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-I) |
| **Counterpart** | `reviews/A_aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md` |
| **Scratch** | `tmp/a_004bcc40.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as complete dtor `0x004bcbf0` | **Falsified** — this adds `(flags&1)` + `operator_delete` + `ret 4` |
| 2 | Bare `ret` / no stack arg | **Falsified** — `ret 4`; flags at `[esp+8]` after push esi |
| 3 | Always frees | **Falsified** — free only when bit0 set |
| 4 | Array-delete (`flags&2`) supported | **Falsified** — only bit0 tested; no cookie/loop |
| 5 | Has direct call-graph callers | **Falsified** — analyze_function_complete callers empty; virtual via vtbl only |
| 6 | Product mangled name sealed | **Open** — family structural name only |
| 7 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / CF | **High** | Wrong teardown / double free |
| Body dtor target `0x004bcbf0` | **High** | Wrong drain path |
| Scalar free gate | **High** | Leak or free of stack list |
| Class family ThreadSafeObjectList | **High** | Mis-wire to unrelated scalar dtor |
| Product mangled | **Open** | Docs only |

---

## 3. Cross-check against raw + bytes

```
PUSH ESI; MOV ESI,ECX
CALL FUN_004bcbf0
TEST [ESP+8],1 / JZ
  PUSH ESI; CALL operator_delete; ADD ESP,4
MOV EAX,ESI; POP ESI; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Vtbl `0x009cb368` first dword = `0x004bcc40`.

---

## 4. Surviving contract for AutoCore

```
// Virtual delete path for ThreadSafeObjectList:
//   (*list->vtbl)(list, 1)  → this VA → dtor body + free
// Stack / member destroy without free:
//   ThreadSafeObjectList_Dtor(list)  // 0x004bcbf0 only
// Do NOT free inside complete dtor body.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/free-gate/vtbl sealed; product mangled residual only → **accept**.
