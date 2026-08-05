# Review B (skeptical / adversarial): `aa_0043d650` GuardedVector_ResizeZeroFill_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-M) |
| **Counterpart** | `reviews/A_aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is "Clear only" (always size→0) | **Falsified** — stack formal is `new_size`; callers often pass 0 but ABI accepts any N |
| 2 | cdecl / no this | **Falsified** — ECX preserved into thiscall Resize; no ECX load needed in 28 B body |
| 3 | Own grow/shrink math | **Falsified** — sole callee is sealed `0043d940`; wrapper only seeds fill |
| 4 | RET 8 like Resize | **Falsified** — body ends `C2 04 00`; callee cleans its own (n, fill) via RET 8 |
| 5 | Scaffold VOG_DEBUG_STOP name | **Rejected** — no evidence; structural GuardedVector name only |
| 6 | Product Clear English | **Overstated** — inferred structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + stack new_size + RET 4 | **High** | Stack imbalance |
| fill=0 into Resize_Thiscall | **High** | Wrong fill path / grow contents |
| Wrapper-only classification | **High** | Invent nested math |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  local_8 = 0; FUN_0043d940(param_1); return;

bytes:
  PUSH ECX; PUSH ECX
  MOV EAX,ESP; MOV [EAX],0          ; fill=0
  MOV EAX,[ESP+0xC]                 ; new_size
  MOV [ESP+4],ESP                   ; local ptr (decompiler phantom)
  PUSH EAX; CALL 0043d940           ; RET 8 inside callee
  POP ECX; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF; **bytes win** on thiscall ECX + RET 4.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector thiscall resize-to-N with zero fill:
//   ECX = container
//   stack new_size; RET 4
//   always fill=0 into GuardedVector_Resize_Thiscall
// Do NOT invent a separate Clear opcode that hardcodes N=0 in the body.
// Do NOT call as cdecl or pass fill from caller.
// Do NOT mix with W28-D EAX/ECX Resize ABI.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF and rejects Clear-only / wrong-RET / scaffold-name claims → **accept**.
